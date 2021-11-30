//Šuráb Denis 1DAE13
#include "pch.h"
#include <iostream>

void DoubleTheArrayValues(int* pInteger, const int sizeOfArray);
void ChangeVariable(int* pInteger);

int main()
{
    std::cout << "Hello World!\n";
    //int numbers[]{};
    //int numbers[10]{};

    int number1{2};
    std::cout << sizeof(number1) << '\n';
    const int size{6};
    int numbers[size]{1,2,3};

    std::cout << "Sizeof arry is " << sizeof(numbers) / sizeof(int) << "\n";


    for(int i{}; i < size; i++)
    {
        std::cout << numbers[i] << "\n";
    }
    DoubleTheArrayValues(numbers, size);
    //std::cout << numbers << '\n';

    //std::cout << number1 << " The address of number1 is " << &number1 << '\n';

    //ChangeVariable(&number1);

    //std::cout << number1 << " The address of number1 is " << &number1 << '\n';
}

void ChangeVariable(int* pInteger)
{
    *pInteger *= 2;
}

void DoubleTheArrayValues(int* pInteger, const int sizeOfArray)
{
    std::cout << pInteger << '\n';
    for (int i{}; i < sizeOfArray; i++) 
    {
        //std::cout << *(pInteger + i) << '\n'; // *pInteger is dereferencing the pointer so we get the value int this case it is 1
        std::cout << pInteger[0] << '\n'; // reason why arrays start with 0, we get the first element
    }
}