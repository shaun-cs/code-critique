//
// Created by Shaun Baker on 12.01.18.
//

#ifndef CODE_CRITIQUE_ZIPIT_H
#define CODE_CRITIQUE_ZIPIT_H

// Class to 'zip' together a pair of iterators
template <typename T>
class zipit : public std::pair<T, T>
{
    zipit &operator+=(std::pair<int,int> const &rhs)
    {
        this->first += rhs.first;
        this->second += rhs.second;
        return *this;
    }
public:
    using std::pair<T, T>::pair;
    zipit &operator+=(int n)
    {
        return *this += std::make_pair(n, n);
    }
    zipit &operator-=(int n)
    {
        return *this += std::make_pair(-n, -n);
    }
    zipit &operator++()
    {
        return *this += 1;
    }
    zipit &operator--()
    {
        return *this += -1;
    }
    auto operator*()
    {
        return std::make_pair(
                *this->first, *this->second);
    }
    auto operator*() const
    {
        return std::make_pair(
                *this->first, *this->second);
    }
    // Hmm, operator-> ??
};
template <typename T>
auto begin(T one, T two)
-> zipit<typename T::iterator>
{
    return {one.begin(), two.begin()};
}
template <typename T>
auto end(T one, T two)
-> zipit<typename T::iterator>
{
    return {one.end(), two.end()};
}

#endif //CODE_CRITIQUE_ZIPIT_H
