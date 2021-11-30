//Šuráb, Denis 1DAE13

#include "pch.h"
#include <iostream>
#include <time.h>
#include <string>
/////////////////////////////////////////////////////////////////////////////////
void EvenOrOdd();
void RandomInteger();
void RandomFloat();
void AsciiCalculator();
void RandomAscii();
void CastVsRound();
void FullHdCalculation();
void PrefixPostfix();
void ExploreStrings();
void StringConcatenation();
void NumberToString();
void StringToNumber();
/////////////////////////////////////////////////////////////////////////////////
int main()
{
    srand(int(time(nullptr))); // little bit of randomising
    //EvenOrOdd();
    //RandomInteger();
    //RandomFloat();
    //AsciiCalculator();
    RandomAscii();
    //CastVsRound();
    //FullHdCalculation();
    //PrefixPostfix();
    //ExploreStrings();
    //StringConcatenation();
   //NumberToString();
   // StringToNumber();
}

void EvenOrOdd() // Tells you a reminder so you can know if the num is even or odd
{
    int number{ };
    int remainder{ };
    std::cout << "Hello my dear USER!" << std::endl << "Please insert whole number: ";
    std::cin >> number;
    remainder = number % 2;
    std::cout << "The reminder is: " << remainder;
}

void RandomInteger() //creating random integers from set intervals
{
    int number1{ std::rand() % 51 };
    int number2{ std::rand() % 71 + 10 };
    int number3{ std::rand() % 41 - 20 };
    int number4{ std::rand() % 5 - 2};


    std::cout << number1 << std::endl << number2 << std::endl << number3 << std::endl << number4 << std::endl;
}

void RandomFloat() //creating random floats from set intervals
{
    float number1{ (std::rand() % 1001 + 500) / 100.0f };
    float number2{ (std::rand() % 1001 - 500) / 100.0f };

    std::cout << number1 << std::endl << number2 << std::endl;
}

void AsciiCalculator() //asks for letter and then shows its ascii value
{
    char letter{ };
    std::cout << "Letter? ";
    std::cin >> letter;
    std::cout << "Letter " << letter << ", ASCII value " << int(letter);
}

void RandomAscii() // creates a random ascii char
{
    char randomLetter{ std::rand() % ('z' - 'a' + 1) + 'a'};
    std::cout << "Random letter " << randomLetter << ", ASCII value " << int(randomLetter);
}

void CastVsRound() //noticing the difference between 
{
    float num1{ 5.44f };
    float num2{ 5.45f };
    float num3{ 5.51f };

    std::cout << num1 << ", rounded: " << round(num1) << ", int cast: " << int(num1) << std::endl;
    std::cout << num2 << ", rounded: " << round(num2) << ", int cast: " << int(num2) << std::endl;
    std::cout << num3 << ", rounded: " << round(num3) << ", int cast: " << int(num3) << std::endl;
}

void FullHdCalculation() //calculates the ratio of fhd
{
    int width{ 1920 };
    int height{ 1080 };

    std::cout << "The aspect ratio of full HD (1920 x 1080) is: " << (float(width) / height);
}

void PrefixPostfix()//seeing the difference between postfix and prefix
{
    int i{ 10 };
    int j{ ++i };
    std::cout << "i: " << i << ", j: " << j << std::endl;

    int k{ 10 };
    int l{ k++ };
    std::cout << "k: " << k << ", l: " << l << std::endl;
}

void ExploreStrings()
{
    std::string string1;
    std::cout << string1;
    std::string welcomemingString{ "Welcome!" };
    std::cout << welcomemingString;

    welcomemingString = "Hello!";
    std::cout << welcomemingString;

    std::string name{ };
    std::cout << "Hey user! give me your first name! ";
    std::cin >> name;
}

void StringConcatenation()
{
    std::string fWord{  };
    std::string sWord{ };

    std::cout << "First word? ";
    std::cin >> fWord;
    std::cout << "Second word? ";
    std::cin >> sWord;

    std::cout << fWord + ' ' + sWord;

}

void NumberToString()
{
    std::string numbersLog{ };
    int enteredNr{ };

    std::cout << "Enter an integer value: ";
    std::cin >> enteredNr;
    numbersLog = std::to_string(enteredNr);

    std::cout << "Enter an integer value: ";
    std::cin >> enteredNr;
    numbersLog += " ";
    numbersLog += std::to_string(enteredNr);
    
    std::cout << "Enter an integer value: ";
    std::cin >> enteredNr;
    numbersLog += " ";
    numbersLog += std::to_string(enteredNr);

    std::cout << "Log of entered numbers: " << numbersLog;
}

void StringToNumber()
{
    std::string numberInt{ "3"};
    std::string numberFloat{ "3.55" };
    float result{ std::stoi(numberInt) + std::stof(numberFloat) };

    std::cout << "One string contains " << numberInt << std::endl;
    std::cout << "Other string contains " << numberFloat << std::endl;
    std::cout << "Adding strings " << numberInt + numberFloat << std::endl;
    std::cout << "Adding numbers " << result;

}