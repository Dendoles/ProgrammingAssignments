//Šuráb, Denis 1DAE13

#include "pch.h"
#include <iostream>

void BinarySize();
void NumberRepresentation();
void RangeOfSignedAndUnsignedTypes();
void BinaryOperators();
void BitChecking();
void SetThirdFlag();
void RightShift();
void LeftShift();
void BitwiseExercise();

int main()
{
    //BinarySize();
    //NumberRepresentation();
    //RangeOfSignedAndUnsignedTypes();
    //BinaryOperators();
    //BitChecking();
    //SetThirdFlag();
    //RightShift();
   // LeftShift();
    BitwiseExercise();
}

void BinarySize()
{
    bool isOkay{ true };
    int number{ 15 };
    float numberFloat{ 3.14f };
    double bigNumber{ 1 };

    std::cout << sizeof(isOkay) << std::endl << sizeof(number) << std::endl << sizeof(numberFloat) << std::endl << sizeof(bigNumber);

}

void NumberRepresentation()
{
    int number{};

    number = 15;
    std::cout << number << std::endl;
    number = 0x0F;
    std::cout << number << std::endl;
    number = 0b1111;
    std::cout << number << std::endl;

}

void RangeOfSignedAndUnsignedTypes()
{
    unsigned int numberPlusMax{ UINT32_MAX };
    unsigned int numberPlusMin{ 0 };
    signed int numberMinusMax{ INT32_MAX };
    signed int numberMinusMin{ INT32_MIN };

    std::cout << numberPlusMax << std::endl << numberPlusMin << std::endl << numberMinusMax << std::endl << numberMinusMin << std::endl;

    ++numberPlusMax;
    --numberPlusMin;
    ++numberMinusMax;
    --numberMinusMin;

    std::cout << std::endl << numberPlusMax << std::endl << numberPlusMin << std::endl << numberMinusMax << std::endl << numberMinusMin;
}

void BinaryOperators()
{
    unsigned int number1{ 3 };
    unsigned int number2{ 5 };
    unsigned int result{number1 & number2};

    std::cout << result << std::endl;
    result = number1 | number2;
    std::cout << result;
}

void BitChecking()
{
    int number{};
    int checker8{ 8 };
    int checker4{ 4 };
    int checker2{ 2 };
    int checker1{ 1 };
    std::cout << "Number to check which bits are set? ";
    std::cin >> number;

    std::cout << "1st bit " << (number & checker1) << std::endl;
    std::cout << "2nd bit " << (number & checker2) << std::endl;
    std::cout << "3rd bit " << (number & checker4) << std::endl;
    std::cout << "4th bit " << (number & checker8) << std::endl;

}

void SetThirdFlag()
{
    int number{};
    int numberForThirdFlag{ 4 };

    std::cout << "Number to set 3rd bit in? ";
    std::cin >> number;
    std::cout << "This number with 3rd bit set " << (number | numberForThirdFlag);

}

void RightShift()
{
    unsigned int number{ 2048 };
    std::cout << number << std::endl;
    std::cout << (number >> 2) << std::endl;

    int number2{ 4448 };
    int numberOfFlag{ 256 };
    int numberOfMoves{ 8 };

    std::cout << ((number2 & numberOfFlag) >> numberOfMoves);

}

void LeftShift()
{
    int number{ 2048 };
    int numberOfMoves{ 4 };

    std::cout << number << std::endl;
    std::cout << (number << numberOfMoves);
}

void BitwiseExercise()
{
    int number{ 0 };
    //prepare yourself for the messiest line of code you will ever see
    std::cout << (((number | 1) << 21) | ((number | 1) << 19) | ((number | 1) << 17) | ((number | 1) << 16) | ((number | 1) << 14) | ((number | 1) << 13) | ((number | 1) << 11) | ((number | 1) << 9) | ((number | 1) << 8) | ((number | 1) << 7) | ((number | 1) << 5) | ((number | 1) << 4) | ((number | 1) << 3) | ((number | 1) << 2) | ((number | 1) << 1) | (number | 1));
    // our 1 (number | 1) 
}