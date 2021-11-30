// Šuráb, Denis - 1DAE13
#include <iostream>

int main()
{
    int integerVar{ 2 };
    char characterVar{ 'D' };
    bool booleanVar{ true };
    float floatVar{ 3.14f };
    double doubleVar{ 3.2838892382 };

    std::cout << std::boolalpha << '(' << integerVar << ')' << std::endl << '(' << characterVar << ')' << std::endl << '(' << booleanVar << ')' << std::endl << '(' << floatVar << ')' << std::endl << '(' << doubleVar << ')' << std::endl;
    std::cout << std::endl;

    integerVar = 3;
    characterVar = 'S';
    booleanVar = false;
    floatVar = 4.13f;
    doubleVar = 11.1111111;

    std::cout << std::boolalpha << '(' << integerVar << ')' << std::endl << '(' << characterVar << ')' << std::endl << '(' << booleanVar << ')' << std::endl << '(' << floatVar << ')' << std::endl << '(' << doubleVar << ')' << std::endl;

    std::cout << "Hello user! , may you input 1integer, 1 character, 1 decimal number for float, 1 decimal number for type double and lastly input 1 or 0 (true or false for boolean)\n";
    std::cin >> integerVar >> characterVar >> floatVar >> doubleVar >> booleanVar;
    std::cout << std::boolalpha << '(' << integerVar << ')' << std::endl << '(' << characterVar << ')' << std::endl << '(' << booleanVar << ')' << std::endl << '(' << floatVar << ')' << std::endl << '(' << doubleVar << ')' << std::endl;

    float anotherFloat{ 23.11f };
    char variableForMixing;
    float floatForMixing;
    int anotherInt = 3;

    //binary operators +,-
    integerVar += 2;
    floatVar = anotherFloat + 222222.33f;
    ++characterVar;
    variableForMixing = characterVar + integerVar - 2;

    //binary operators *, /
    integerVar /= 2;
    floatVar = anotherFloat / 2;
    floatForMixing = floatVar * 2.33 / integerVar;
    
    integerVar /= 2;
    //compound exercises
    integerVar = 5 * (2 - 3) - anotherInt;
    anotherInt = 234 / 4 * (3 - integerVar);

}


