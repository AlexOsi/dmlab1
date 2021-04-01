#include "SetOfChars.h"

std::string getInputString(const std::string& inputMessage) {
    std::string inputString;
    std::cout << inputMessage;
    std::getline(std::cin, inputString);
    auto endWithoutExtraChars = std::remove_if(inputString.begin(),
                                               inputString.end(),
                                               [] (char ch) {return !isalpha(ch);});
    inputString.erase(endWithoutExtraChars, inputString.end());
    return inputString;
}

int main() {

    SetOfChars A{"abc"};
    SetOfChars B{"cde"};
    SetOfChars C{"ecv"};
    auto D = unionSets(A, B);
    D.print();
//    SetOfChars A{getInputString("Enter elements of set A in one line:\n")};
//    A.print();
//    SetOfChars B{getInputString("Enter elements of set B in one line:\n")};
//    SetOfChars C{getInputString("Enter elements of set C in one line:\n")};
    return 0;
}

