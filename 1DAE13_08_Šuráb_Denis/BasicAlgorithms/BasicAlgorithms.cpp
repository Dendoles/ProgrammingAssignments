//Šuráb, Denis 1DAE13
#include "pch.h"
#include <iostream>
#include <time.h>

////////////////////////////////////////////////////////////////////////
////////////////////////Predeclaration
////////////////////////////////////////////////////////////////////////

int Count(int* pArray, const int arraySize, int desiredNumber);
int MinElement(int* pArray, const int arraySize);
int MaxElement(int* pArray, const int arraySize);
void Swap(int index1, int index2, int* pArray);
void Shuffle(int* pArray, const int arraySize, int numberOfSwaps);
void BubbleSort(int* pArray, int arraySize, bool isAscending = true);


void TestBubbleSort();
void TestShuffle();
void TestSwap();
void TestMinMax();
void TestCount();
void PrintElements(int* pArray, const int arraySize);

int main()
{
    srand(unsigned int(time(NULL)));

    //PrintCount();
    //TestMinMax();
    //TestSwap();
    //TestShuffle();
    TestBubbleSort();
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

void TestCount()
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
        if (pArray[i] >= highest)
        {
            highest = pArray[i];
        }
    }
    return highest;
}

void TestMinMax()
{
    const int arr1Size{10};
    const int arr2Size{14};
    int array1[arr1Size]{ 10, 1, -4, 5, 3, 10, -2, -1, 3, 10 };
    int array2[arr2Size]{ -2,0,0,3,0,0,-5,-5,1,-3,-5,-4,3,3 };
    std::cout << "- - Test of MinElement and MaxElement functions - -\n";
    PrintElements(array1, arr1Size);
    std::cout << MinElement(array1, arr1Size) << " is the smallest value in this array\n";
    std::cout << MaxElement(array1, arr1Size) << " is the largest value in this array\n \n";

    PrintElements(array2, arr2Size);
    std::cout << MinElement(array2, arr2Size) << " is the smallest value in this array\n";
    std::cout << MaxElement(array2, arr2Size) << " is the largest value in this array\n";
}

void Swap(int index1, int index2, int* pArray)
{
    // swapping 2 variables withou using 3rd variable B-)
    pArray[index1] = pArray[index1] + pArray[index2];
    pArray[index2] = pArray[index1] - pArray[index2];
    pArray[index1] = pArray[index1] - pArray[index2];
}

void TestSwap()
{
    const int arr1Size{ 10 };
    const int arr2Size{ 14 };
    int array1[arr1Size]{ 0, 1, -4, 5, 3, 10, -2, -1, 3, 10 };
    int array2[arr2Size]{ -2,0,0,3,0,0,-5,-5,1,-3,-5,-4,3,3 };

    std::cout << "- - Test of Swap function - -\n";
    std::cout << "Before swapping\n";
    PrintElements(array1, arr1Size);
    std::cout << "After swapping the first and the last element\n";
    Swap(0, arr1Size - 1, array1);
    PrintElements(array1, arr1Size);

    std::cout << "\n\nBefore swapping\n";
    PrintElements(array2, arr2Size);
    std::cout << "After swapping the second and the second last element\n";
    Swap(1, arr2Size - 2, array2);
    PrintElements(array2, arr2Size);
}

void Shuffle(int* pArray, const int arraySize, int numberOfSwaps)
{
    int index1{}, index2{};
    for (int i{}; i < numberOfSwaps; i++)
    {
        index1 = rand() % (arraySize - 1) + 0;
        do
        {
            index2 = rand() % (arraySize - 1) + 0;
        } while (index2 == index1);

        Swap(index1, index2, pArray);
    }
}

void TestShuffle()
{
    int numberOfShuffles{10};
    const int arr1Size{ 10 };
    const int arr2Size{ 14 };
    int array1[arr1Size]{ 0, 1, -4, 5, 3, 10, -2, -1, 3, 10 };
    int array2[arr2Size]{ -2,0,0,3,0,0,-5,-5,1,-3,-5,-4,3,3 };

    std::cout << "- - Test of Shuffle function - -\n";
    std::cout << "Before shuffling\n";
    PrintElements(array1, arr1Size);
    std::cout << "After shuffling " << numberOfShuffles << " times\n";
    Shuffle(array1, arr1Size, numberOfShuffles);
    PrintElements(array1, arr1Size);

    numberOfShuffles = 50;

    std::cout << "\n\nBefore shuffling\n";
    PrintElements(array2, arr2Size);
    std::cout << "After shuffling " << numberOfShuffles << " times\n";
    Shuffle(array2, arr2Size, numberOfShuffles);
    PrintElements(array2, arr2Size);
}

void BubbleSort(int* pArray, int arraySize, bool isAscending)
{
    if (arraySize == 1)
    {
        return;
    }
    for (int i = 0; i < arraySize; i++)
    {
        if (isAscending)
        {
            if (pArray[i] > pArray[i + 1])
            {
                if (i + 1 >= arraySize)
                {

                }
                else
                {
                    Swap(i, i + 1, pArray);
                }
            }
        }
        else
        {
            if (pArray[i] < pArray[i + 1])
            {
                Swap(i, i + 1, pArray);
            }
        }

    }
    BubbleSort(pArray, arraySize - 1, isAscending);
}

void TestBubbleSort()
{
    int numberOfShuffles{ 10 };
    const int arr1Size{ 10 };
    const int arr2Size{ 14 };
    int array1[arr1Size]{ 0, 1, -4, 5, 3, 10, -2, -1, 3, 10 };
    int array2[arr2Size]{ -2,0,0,3,0,0,-5,-5,1,-3,-5,-4,3,3 };

    std::cout << "- - Test of BubbleSort function - -\n";
    std::cout << "Before sort\n";
    PrintElements(array1, arr1Size);
    std::cout << "After ascending sort\n";
    BubbleSort(array1, arr1Size);
    PrintElements(array1, arr1Size);

    std::cout << "\n\nBefore sort\n";
    PrintElements(array2, arr2Size);
    std::cout << "After descending sort\n";
    BubbleSort(array2, arr2Size, false);
    PrintElements(array2, arr2Size);
}