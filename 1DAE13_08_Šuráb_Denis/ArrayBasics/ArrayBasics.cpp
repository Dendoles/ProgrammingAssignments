// Šuráb, Denis - 1DAE13

#include "pch.h"
#include <iostream>
#include "structs.h"
#include <string>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////// Predeclaration
///////////////////////////////////////////////////////////////////////////////////////////////////////

void PrintElementsInArrays();
void PrintSizeOfArrays();
void PrintAddressOfArray();
void TestPrintElements();
void Print2DArray();



void PrintElements(int* pNumbers, const int size);
void PrintElements(int* pNumbers, int startIdx, int endIdx);
int GetIndex( int rowIdx, int colIdx, int nrCols );

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////// Globals
///////////////////////////////////////////////////////////////////////////////////////////////////////

const int g_Size1{ 5 }, g_Size2{ 5 };

int g_FirstArray[g_Size1]{};
int g_SecondArray[]{ 10,20,30,40,50 };
int g_ThirdArray[g_Size2]{ 5,10,15 };

int main()
{
    //PrintElementsInArrays();
    //PrintSizeOfArrays();
    //PrintAddressOfArray();
    //TestPrintElements();
    Print2DArray();
}

void PrintElementsInArrays()
{

    std::cout << "- - Accessing elements - -" << '\n';
    std::cout << "First element: " << g_ThirdArray[0] << '\n';
    std::cout << "Last element: " << g_ThirdArray[4] << '\n';

    std::cout << "Iterating over the elements" << '\n';
    for (int i = 0; i < g_Size2; i++)
    {
        std::cout << g_ThirdArray[i] << ' ';
    }
}
void PrintSizeOfArrays()
{
    int arraySize{ sizeof(g_SecondArray) / sizeof(g_SecondArray[0]) };
    std::cout << "- - Size of arrays - -" << '\n';
    std::cout << "2nd array" << '\n';
    std::cout << "  nr of bytes: " << sizeof(g_SecondArray) << '\n';
    std::cout << "  size of one element: " << sizeof(g_SecondArray[0]) << '\n';
    std::cout << "  nr of elements: " << arraySize << '\n';

    for (int i = 0; i < arraySize; i++)
    {
        std::cout << g_SecondArray[i] << ' ';
    }
}

void PrintAddressOfArray()
{
    Point2f point2fArray[g_Size2]{ Point2f(0,10), Point2f(17,24), Point2f(0,0) };

    std::cout << "- - The elements occupy consecutive memory locations - -" << "\n";
    std::cout << "Array of int types" << '\n';

    for (int i = 0; i < g_Size2; i++)
    {
        std::cout << "Address of element with index " << i << " is " << &g_ThirdArray[i] << '\n';
    }
    std::cout << '\n';
    
    std::cout << "Array of Point2f types" << '\n';
    for (int i = 0; i < g_Size2; i++)
    {
        std::cout << "Address of element with index " << i << " is " << &point2fArray[i] << '\n';
    }
}

void PrintElements(int* pNumbers, const int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << *(pNumbers + i) << ' ';
    }
    std::cout << '\n';
}

void PrintElements(int* pNumbers, int startIdx, int endIdx)
{
    for (int i = startIdx; i <= endIdx; i++)
    {
        std::cout << *(pNumbers + i) << ' ';
    }
    std::cout << '\n';
}
void TestPrintElements()
{
    const int size{5};
    const int startIndex{1}, endIndex{3};
    int firstArray[size]{};
    int secondArray[]{ 10,20,30,40,50 };
    int thirdArray[size]{ 5,10,15 };

    int arraySize{ sizeof(g_SecondArray) / sizeof(g_SecondArray[0]) };
    std::cout << "- - Passing an array to a function, PrintElements" << "\n";
    std::cout << "Print all elements" << '\n';
    PrintElements(firstArray, size);
    PrintElements(secondArray, sizeof(secondArray) / sizeof(secondArray[0]));
    PrintElements(thirdArray, size);

    std::cout << '\n';
    std::cout << "Print a range of elements" << '\n';

    PrintElements(secondArray, startIndex,endIndex);
}

int GetIndex(int rowIdx, int colIdx, int nrCols)
{
    return rowIdx * nrCols + colIdx;
}

void Print2DArray()
{
    const int arraySize{ 20 };
    const int rows{ 4 };
    const int columns{ 5 };
    int Array[arraySize]{};

    for (int i{}; i < rows; i++)
    {
        for (int u{}; u < columns; u++)
        {
            //std::cout << "columns: " << u << '\t' << "rows:" << i << '\n';
            int value{ (i + 1) * 10 + u + 1 };
            Array[GetIndex(i, u, columns)] = value;
        }
    }

    std::cout << "- - 2D arrays - -" << '\n';

    for (int j = 0; j < arraySize; j++)
    {
        std::cout << Array[j] << "  ";
        if ((j + 1) % columns == 0)
        {
            std::cout << '\n';
        }
    }
    
}