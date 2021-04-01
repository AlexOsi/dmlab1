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
    SetOfChars operator* (const SetOfChars& other) const;
    SetOfChars operator- (const SetOfChars& other) const;
    SetOfChars operator+ (const SetOfChars& other) const;
    SetOfChars operator! () const;
    SetOfChars negation() const;
    SetOfChars intersectionWith(const SetOfChars& other) const;
    SetOfChars differenceWith(const SetOfChars& other) const;
    SetOfChars unionWith(const SetOfChars& other) const;
    bool isEqualTo(const SetOfChars& other) const;
    SetOfChars() = default;
    void print() const;

private:
    std::string m_chars;
};

bool operator== (const SetOfChars& one, const SetOfChars& other);


#endif //DM1_SETOFCHARS_H
