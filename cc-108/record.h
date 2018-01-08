//
// Created by Shaun Baker on 08.01.18.
//

#ifndef CODE_CRITIQUE_RECORD_H
#define CODE_CRITIQUE_RECORD_H

namespace util
{
    class Record {
    public:
        Record(uint64_t id, std::string value = {});
        std::string to_string() const;
        //other methods elided
    private:
        uint64_t const id;
        std::string value;
    };
    inline
    std::string to_string(Record const &r)
    {
        return r.to_string();
    }
}

#endif //CODE_CRITIQUE_RECORD_H
