//
// Created by Shaun Baker on 12.01.18.
//

#include <algorithm>
#include <iostream>
#include <random>
#include "zipit.h"

class randomize
{
    std::mt19937 mt;
public:
    int operator()() { return mt() % 6 + 1; }
};
void play(int turns, randomize &generator)
{
    std::vector<int> player1(turns);
    std::vector<int> player2(turns);

    std::generate(player1.begin(),
                  player1.end(), generator);
    std::generate(player2.begin(),
                  player2.end(), generator);

    int total{};

    for (auto it = begin(player1, player2);
         it != end(player1, player2); ++it)
    {
        if ((*it).first != (*it).second)
        {
            auto diff = *it.first - *it.second;
            total += copysign(1.0, diff);
        }
    }
    if (total > 0)
    {
        std::cout << "Player 1 wins\n";
    }
    else if (total < 0)
    {
        std::cout << "Player2 wins\n";
    }
    else
    {
        std::cout << "Drawn!\n";
    }
}
int main()
{
    randomize generator;

    int turns;
    std::cout << "Let's play dice\n";
    while (std::cout << "How many turns? ",
            std::cin >> turns)
    {
        play(turns, generator);
    }
}
