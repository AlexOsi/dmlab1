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

void printAnswer(const std::string& nameOfStatement, bool isStatementRight) {
    if (isStatementRight) {
        std::cout << nameOfStatement << " statement is right" << std::endl;
    }
    else {
        std::cout << nameOfStatement << " statement is wrong" << std::endl;
    }
}

int main() {

    SetOfChars A{"abc"}, B{"cde"}, C{"ecv"}, X{"tba"};

    bool isFirstStatement = (A*B*C*!X)+(!A*C)+(!B*C)+(C*X) == C;
    printAnswer("First", isFirstStatement);

    bool isSecondStatement = A-(A-B) == B-(B-A);
    printAnswer("Second", isSecondStatement);

    bool isThirdStatement = (A-B)-C == (A-C)-(B-C);
    printAnswer("Third", isThirdStatement);

    bool isFourthStatement = A-B == A*!B;
    printAnswer("Fourth", isFourthStatement);

    bool isFifthStatement = A-(A-B) == A*B;
    printAnswer("Fifth", isFifthStatement);
//    SetOfChars A{getInputString("Enter elements of set A in one line:\n")};
//    A.print();
//    SetOfChars B{getInputString("Enter elements of set B in one line:\n")};
//    SetOfChars C{getInputString("Enter elements of set C in one line:\n")};
    return 0;
}

