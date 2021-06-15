#include "SetOfChars.h"

std::string getInputString(const std::string& nameOfInputSet) {
    std::string inputString;
    std::cout << "Enter elements of set " << nameOfInputSet << " in one line" << std::endl;
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
    /*
     * Создан класс множества символов.
     * Для него перегружены операторы с реализацией операций
     * Вводим множества A, B, C, X
     * Затем проверяем верность утверждений
     * */

    SetOfChars A{getInputString("A")},
    B{getInputString("B")},
    C{getInputString("C")},
    X{getInputString("X")};

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
    return 0;
}

