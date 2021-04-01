#ifndef DM1_SETOFCHARS_H
#define DM1_SETOFCHARS_H

#include <string>
#include <algorithm>
#include <iostream>

class SetOfChars {
public:
    explicit SetOfChars(std::string chars)
            : m_chars(std::move(chars)) {
        std::sort(m_chars.begin(), m_chars.end());
    }
    SetOfChars negationSet();
    SetOfChars() = default;
    void print();

private:
    friend SetOfChars intersectionSets(const SetOfChars& one, const SetOfChars& other);
    friend SetOfChars differenceSets(const SetOfChars& one, const SetOfChars& other);
    friend SetOfChars unionSets(const SetOfChars& one, const SetOfChars& other);
    std::string m_chars;
};


#endif //DM1_SETOFCHARS_H
