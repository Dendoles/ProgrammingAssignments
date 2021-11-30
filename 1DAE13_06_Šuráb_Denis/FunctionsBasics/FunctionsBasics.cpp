// Šuráb, Denis 1DAE13
#include <iostream>
#include <chrono>
#include <time.h>

// STRUCT AND CONSTRUCTOR
//--------------------------------------------------------------------
struct Point2f
{
    Point2f();
    explicit Point2f(float x, float y);

    float x;
    float y;
};

Point2f::Point2f()
    :Point2f{ 0.0f, 0.0f }
{
}
Point2f::Point2f(float x, float y)
    : x{ x }, y{ y }
{
}
//--------------------------------------------------------------------

void Print(int value, char delimiter);
void Print(char value, char delimiter);
void Print(float value, char delimiter);
int TestSum(int a, int b);
int Multiply(int num1, int num2);
int Modulo(int number, int divisor);
void PrintNumbers(int startingNumber, int endingNumber);
void CalcElapsedTime(int startingNumber, int endingNumber);
void PrintMessage(int numberOfSpaces = 0);
std::string IsEven(int number);
int IsLeapYear(int year);
int GetRand(int startingNumber, int endingNumber);
float GetRand(float startingNumber, float endingNumber);
float GetDistance(float firstPointX, float firstPointY, float secondPointX, float secondPointY);
float GetDistance(const Point2f& coordinatesOfFirstPoint,const Point2f& coordinatesOfSecondPoint);



void TestPrint();
void TestMultiply();
void TestPrintNumbers();
void TestCalcElapsedTime();
void TestPrintMessage();
void TestIsEven();
void TestIsLeapYear();
void TestGetIntRand();
void TestGetFloatRand();
void TestGetDistance();

int main()
{
    srand(unsigned int(time(NULL)));
    int num1{3}, num2{8}, result{};

    //result = TestSum(num1, num2);
    //TestMultiply();
    //TestPrint();
    //std::cout << Modulo(num1, num2) << ", " << num1 % num2;
    //TestPrintNumbers();
    //TestCalcElapsedTime();
    //TestPrintMessage();
    //TestIsEven();
    //TestIsLeapYear();
    //TestGetIntRand();
    //TestGetFloatRand();
    //TestGetDistance();

}

int TestSum(int a, int b)
{
    int result{};
    result = a + b;
    return result;
}
void TestPrint()
{
    Print('a', ',');
    Print(20, ',');
    Print(20.0f, ',');
}

void Print(int value, char delimiter)
{
    std::cout << value << delimiter;
}

void Print(char value, char delimiter)
{
    std::cout << value << delimiter;
}

void Print(float value, char delimiter)
{
    std::cout << value << delimiter;
}

void TestMultiply()
{
    int number1{}, number2{};
    int num1{}, num2{}, num3{}, num4{};

    std::cout << "- - Function that calculates the product of 2 integers - -" << "\n";
    std::cout << "2 numbers to multiply? ";
    std::cin >> number1 >> number2;
    std::cout << number1 << " * " << number2 << " = " << Multiply(number1, number2) << "\n";

    std::cout << "4 numbers to multiply? ";
    std::cin >> num1 >> num2 >> num3 >> num4;
    std::cout << num1 << " * " << num2 << " * " << num3 << " * " << num4 << " = " << Multiply(Multiply(num1, num2), Multiply(num3, num4));
}

int Multiply(int num1, int num2) 
{
    return num1 * num2;
}

int Modulo(int number, int divisor)
{
    int num1{ number / divisor };
    return number - (num1 * divisor);
}
void TestPrintNumbers()
{
    int arg1{ 10 }, arg2{ 20 }, arg3{ 90 }, arg4{ 115 };
    std::cout << "- - Function that prints the integers in a given interval - -" << "\n";
    std::cout << "Interval [" << arg1 << ", " << arg2 << "]" << "\n";
    PrintNumbers(arg1, arg2);
    std::cout << "\n" << "Interval [" << arg2 << ", " << arg3 << "]" << "\n";
    PrintNumbers(arg3, arg4);
}

void PrintNumbers(int startingNumber, int endingNumber)
{
    while (startingNumber <= endingNumber)
    {
        std::cout << startingNumber << " ";
        startingNumber++;
    }
}
void CalcElapsedTime(int startingNumber, int endingNumber)
{
    std::chrono::steady_clock::time_point startTime{ std::chrono::steady_clock::now() };
    PrintNumbers(startingNumber, endingNumber);
    std::chrono::steady_clock::time_point endTime{ std::chrono::steady_clock::now() };
    std::chrono::duration<float, std::milli> elapsedTime{endTime - startTime};
    std::cout << "\n" << "This print task took " << elapsedTime.count() << " milliseconds";
}
void TestCalcElapsedTime()
{
    int num1{0}, num2{30}, num3{400};
    std::cout << "- - Function that counts the time of a printing task - -" << "\n";
    std::cout << "Interval [" << num1 << ", " << num2 << "]" << "\n";
    CalcElapsedTime(num1, num2);

    std::cout << "Interval [" << num1 << ", " << num3 << "]" << "\n";
    CalcElapsedTime(num1, num3);
}

void TestPrintMessage()
{
    int num1{ 2 }, num2{ 4 };
    std::cout << "- - Function that prints an indented message - -" << "\n";
    PrintMessage();
    std::cout << "No indentation specified" << "\n";
    PrintMessage(num1);
    std::cout << num1 << " spaces indentation specified" << "\n";
    PrintMessage(num2);
    std::cout << num2 << " spaces indentation specified";
}

void PrintMessage(int numberOfSpaces)
{
    char space{ ' ' };
    for (int i = 0; i < numberOfSpaces; i++)
    {
        std::cout << space;
    }
}

void TestIsEven()
{
    int n1{41}, n2{18467}, n3{6334}, n4{26500}, n5{19169};
    std::cout << "- - Function that checks whether a number is even - -" << "\n";
    std::cout << n1 << " is " << IsEven(n1) << "\n";
    std::cout << n2 << " is " << IsEven(n2) << "\n";
    std::cout << n3 << " is " << IsEven(n3) << "\n";
    std::cout << n4 << " is " << IsEven(n4) << "\n";
    std::cout << n5 << " is " << IsEven(n5) << "\n";
}

std::string IsEven(int number)
{
    if (number % 2 == 0)
    {
        return "even";
    }
    else
    {
        return "odd";
    }
}

void TestIsLeapYear()
{
    int year{};
    std::cout << "- - Function that check whether year is leap - -" << "\n";
    do
    {
        std::cout << "Year ? ";
        std::cin >> year;
        if (year != -1)
        {
            std::cout << year << " has " << IsLeapYear(year) << " days in February" << "\n";
        }
    } while (year != -1);
}

int IsLeapYear(int year)
{
    if (year % 4 != 0)
    {
        return 28;
    }
    else if (year % 100 != 0)
    {
        return 29;
    }
    else if (year % 400 != 0)
    {
        return 28;
    }
    else
    {
        return 29;
    }
}

int GetRand(int startingNumber, int endingNumber)
{ 
    return (rand() % (endingNumber - startingNumber + 1) + startingNumber);
}

void TestGetIntRand()
{
    int num1{1}, num2{6}, num3{10}, num4{20}, num5{-5}, num6{0};
    std::cout << "- - Functon that generates a random number in a given integer interval - -" << "\n";
    std::cout << "In [" << num1 << ", " << num2 << "] " << GetRand(num1, num2) << "\n";
    std::cout << "In [" << num3 << ", " << num4 << "] " << GetRand(num3, num4) << "\n";
    std::cout << "In [" << num5 << ", " << num6 << "] " << GetRand(num5, num6) << "\n";
}
float GetRand(float startingNumber, float endingNumber)
{
    int number = rand() % (int(endingNumber - startingNumber * 100.f) + 1) + int(startingNumber * 100.f);
    return number / 100.f;
}

void TestGetFloatRand()
{
    float num1{ 0 }, num2{ 3.14159f }, num3{ -2 }, num4{ 3 };
    std::cout << "- - Functon that generates a random number in a given float interval - -" << "\n";    
    std::cout << "In [" << num1 << ", " << num2 << "] " << GetRand(num1, num2) << "\n";
    std::cout << "In [" << num3 << ", " << num4 << "] " << GetRand(num3, num4) << "\n";
}

float GetDistance(float firstPointX, float firstPointY, float secondPointX, float secondPointY)
{
    float x = firstPointX - secondPointX;
    float y = firstPointY - secondPointY;
    return sqrtf(powf(x, 2) + powf(y, 2));
}

float GetDistance(const Point2f& coordinatesOfFirstPoint, const Point2f& coordinatesOfSecondPoint)
{
    Point2f coordinates{coordinatesOfFirstPoint.x - coordinatesOfSecondPoint.x, coordinatesOfFirstPoint.y - coordinatesOfSecondPoint.y};

    return sqrtf(powf(coordinates.x, 2) + powf(coordinates.y, 2));
}

void TestGetDistance()
{
    float x1{0.41f}, y1{184.67f}, x2{63.34f}, y2{265.00f};
    Point2f firstCoordinate{x1,y1}, secondCoordinate{x2,y2};

    std::cout << "- - Function that calculates distance between 2 points - -" << "\n";
    std::cout << "Distance between [" << x1 << ", " << y1 << "] and [" << x2 << ", " << y2 << "]" << "\n";
    std::cout << "Calling one version: " << GetDistance(x1, y1, x2, y2) << "\n";
    std::cout << "Calling one version: " << GetDistance(firstCoordinate, secondCoordinate) << "\n";

    x1 = 191.69f;
    y1 = 157.24f;
    x2 = 114.78f;
    y2 = 293.58f;
   
    firstCoordinate =  Point2f(x1,y1);
    secondCoordinate = Point2f(x2, y2);

    std::cout << "Distance between [" << x1 << ", " << y1 << "] and [" << x2 << ", " << y2 << "]" << "\n";
    std::cout << "Calling one version: " << GetDistance(x1, y1, x2, y2) << "\n";
    std::cout << "Calling one version: " << GetDistance(firstCoordinate, secondCoordinate) << "\n";
}