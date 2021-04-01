#include "SetOfChars.h"

void SetOfChars::print() {
    std::cout << m_chars;
}

SetOfChars SetOfChars::negationSet() {
    std::string englishAlphabet;
    for (char ch = 'A'; ch <= 'z'; ch++) {
        if (isalpha(ch)) {
            englishAlphabet.push_back(ch);
        }
    }
    SetOfChars all{englishAlphabet};

}

SetOfChars intersectionSets(const SetOfChars& one, const SetOfChars& other) {
    std::string charsIntersection;
    std::set_intersection(one.m_chars.begin(), one.m_chars.end(),
                          other.m_chars.begin(), other.m_chars.end(),
                          std::back_inserter(charsIntersection));
    return SetOfChars{charsIntersection};
}

SetOfChars differenceSets(const SetOfChars& one, const SetOfChars& other) {
    std::string charsDifference;
    std::set_difference(one.m_chars.begin(), one.m_chars.end(),
                        other.m_chars.begin(), other.m_chars.end(),
                        std::back_inserter(charsDifference));
    return SetOfChars{charsDifference};
}

SetOfChars unionSets(const SetOfChars& one, const SetOfChars& other) {
    std::string charsUnion;
    std::set_union(one.m_chars.begin(), one.m_chars.end(),
                   other.m_chars.begin(), other.m_chars.end(),
                   std::back_inserter(charsUnion));
    return SetOfChars{charsUnion};
}
