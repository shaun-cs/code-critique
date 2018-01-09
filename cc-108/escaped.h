//
// Created by Shaun Baker on 08.01.18.
//

#ifndef CODE_CRITIQUE_ESCAPED_H
#define CODE_CRITIQUE_ESCAPED_H

#pragma once
#include <string>

//namespace util
//{
    //provide escaped textual representation of value
    //- any double quotes need escaping with \
    //- wrap in double quotes if has any spaces
    template <typename T>
    std::string escaped_text(T t)
    {
        using namespace std;

        auto ret = to_string(t);
        for(std::size_t idx = 0;
            (idx = ret.find(idx, '"')) != std::string::npos;
                idx += 2)
        {
            ret.insert(idx, "\\", 1);
        }
        if(ret.find(' ') != std::string::npos)
        {
            ret = '"' + ret + '"';
        }
        return ret;
    }
//}

#endif //CODE_CRITIQUE_ESCAPED_H
