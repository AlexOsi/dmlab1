#include "SetOfChars.h"

void SetOfChars::print() const {
    std::cout << m_chars;
}

SetOfChars SetOfChars::operator* (const SetOfChars& other) const {
    return this->intersectionWith(other);
}

SetOfChars SetOfChars::operator+ (const SetOfChars& other) const {
    return this->unionWith(other);
}

SetOfChars SetOfChars::operator- (const SetOfChars& other) const {
    return this->differenceWith(other);
}

SetOfChars SetOfChars::operator! () const {
    return this->negation();
}

SetOfChars SetOfChars::negation() const {
    std::string englishAlphabet;
    for (char ch = 'A'; ch <= 'z'; ch++) {
        if (isalpha(ch)) {
            englishAlphabet.push_back(ch);
        }
    }
    SetOfChars all{englishAlphabet};
    return all.differenceWith(*this);
}

SetOfChars SetOfChars::intersectionWith(const SetOfChars& other) const {
    std::string charsIntersection;
    std::set_intersection(this->m_chars.begin(), this->m_chars.end(),
                          other.m_chars.begin(), other.m_chars.end(),
                          std::back_inserter(charsIntersection));
    return SetOfChars{charsIntersection};
}

SetOfChars SetOfChars::differenceWith(const SetOfChars &other) const {
    std::string charsDifference;
    std::set_difference(this->m_chars.begin(), this->m_chars.end(),
                          other.m_chars.begin(), other.m_chars.end(),
                          std::back_inserter(charsDifference));
    return SetOfChars{charsDifference};
}

SetOfChars SetOfChars::unionWith(const SetOfChars &other) const {
    std::string charsUnion;
    std::set_union(this->m_chars.begin(), this->m_chars.end(),
                   other.m_chars.begin(), other.m_chars.end(),
                   std::back_inserter(charsUnion));
    return SetOfChars{charsUnion};
}

bool SetOfChars::isEqualTo(const SetOfChars& other) const {
    return this->m_chars == other.m_chars;
}

bool operator ==(const SetOfChars& one, const SetOfChars& other) {
    return one.isEqualTo(other);
}