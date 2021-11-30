//Šuráb, Denis 1DAE13 

#include "pch.h"
#include <iostream>
#include <iomanip>

float g_Pi = 3.14159265359f;

void Print(int value, char delimiter = ' ');
int GetRand(int startingNumber, int endingNumber);
float GetRand(float startingNumber, float endingNumber);
void CalcCosSin(float angle, float& cos, float& sin);
void TestCalcCosSin();

int main()
{
    std::srand(unsigned int(time(NULL)));
    //Print(10);
    //Print(30);
    TestCalcCosSin();
}

void Print(int value, char delimiter)
{
    std::cout << value << delimiter;
}

void CalcCosSin(float angle, float& cos, float & sin)
{
    cos = cosf(angle);
    sin = sinf(angle);
}

int GetRand(int startingNumber, int endingNumber)
{
    return (rand() % (endingNumber - startingNumber + 1) + startingNumber);
}

float GetRand(float startingNumber, float endingNumber)
{
    int number = rand() % (int(endingNumber - startingNumber * 10.f) + 1) + int(startingNumber * 10.f);
    return number / 10.f;
}

void TestCalcCosSin()
{
    const int rowOffset{ 10 };
    const int numberOfRows{ 10 };

    std::cout << "- - Function that calculates cosine and sine - -" << "\n";
    std::cout << std::setw(rowOffset) << "Radians" << std::setw(rowOffset) << "Cos" << std::setw(rowOffset) << "Sin" << "\n";

    for (int i = 0; i < numberOfRows; i++)
    {
        float radians = GetRand(0.f, 2.f * g_Pi);
        float cos{}, sin{};

        CalcCosSin(radians, cos, sin);

        std::cout << std::setw(rowOffset) << std::setprecision(2) << radians;
        std::cout << std::setw(rowOffset) << std::setprecision(2) << cos;
        std::cout << std::setw(rowOffset) << std::setprecision(2) << sin << "\n";
    }
}