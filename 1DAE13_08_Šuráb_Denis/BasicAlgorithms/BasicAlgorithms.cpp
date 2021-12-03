//Šuráb, Denis 1DAE13
#include "pch.h"
#include <iostream>

////////////////////////////////////////////////////////////////////////
////////////////////////Predeclaration
////////////////////////////////////////////////////////////////////////

int Count(int* pArray, const int arraySize, int desiredNumber);
int MinElement(int* pArray, const int arraySize);
int MaxElement(int* pArray, const int arraySize);


void PrintCount();
void PrintElements(int* pArray, const int arraySize);

int main()
{
    //{ 10, 1, -4, 5, 3, 10, -2, -1, 3, 10 };
    //{ 4, 3, -2, 7, 9, 0, -5, -4, 2, 1 };
    //{ 1, 1, 1, 3, -15, 8, -3, -1, 10, 24 };
    PrintCount();
}

int Count(int* pArray, const int arraySize, int desiredNumber)
{
    int count{};
    for (int i = 0; i < arraySize; i++)
    {
        if (pArray[i] == desiredNumber)
        {
            count++;
        }
    }
    return count;
}

void PrintCount()
{
    int numberForFinding{10};
    const int arraySize{10};
    int arrayOfNumbersA[arraySize]{ 10, 1, -4, 5, 3, 10, -2, -1, 3, 10 };
    int arrayOfNumbersB[arraySize]{ 4, 3, -2, 7, 9, 0, -5, -4, 2, 1 };
    
    std::cout << "- - Test Of Count Function - -" << '\n';
    PrintElements(arrayOfNumbersA, arraySize);
    std::cout << numberForFinding << " occurs " << Count(arrayOfNumbersA, arraySize, numberForFinding) << " times in this array";
    std::cout << "\n \n";

    numberForFinding = 0;
    PrintElements(arrayOfNumbersB, arraySize);
    std::cout << numberForFinding << " occurs " << Count(arrayOfNumbersB, arraySize, numberForFinding) << " times in this array";
}

void PrintElements(int* pArray, const int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        std::cout << pArray[i] << ' ';
    }
    std::cout << '\n';
}

int MinElement(int* pArray, const int arraySize)
{
    int lowest{pArray[0]};
    for (int i = 0; i < arraySize; i++)
    {
        if (pArray[i] <= lowest)
        {
            lowest = pArray[i];
        }
    }
    return lowest;
}
int MaxElement(int* pArray, const int arraySize)
{
     int highest{pArray[0]};
    for (int i = 0; i < arraySize; i++)
    {
        if (pArray[i] <= highest)
        {
            highest = pArray[i];
        }
    }
    return highest;
}