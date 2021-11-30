//Šuráb, Denis - 1DAE 13GDE

#include "pch.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>
void CatMeowing(); //forward declaration for the function

int g_GlobalVar{ }; // naming convention 'g_'

int main()
{
    std::cout << "Hello cat!\n";
    float fPi{ float(M_PI) };
    float result{ };
    result = sinf(1.2f); //sinf (for float)
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();
    CatMeowing();


    int number{ };
    std::cin >> number;
    std::cin.ignore();
    std::cin.get();

    std::string text;
    text = "Hello cat!";
    text += " meoow ";
    text += std::to_string(number);
    std::cout << text << std::endl;
}

void CatMeowing()
{
    float randomNumber{ };
    //randomNumber = (rand() %  (255 + 0)) / 255.0f;
    randomNumber = rand() % (10 + 2);
    //randomNumber = (rand() % (1001 + 200)) / 100.0f;
    //randomNumber = (rand() % 11 + 2) / 1.0f;
    std::cout << randomNumber << '\n';
}
