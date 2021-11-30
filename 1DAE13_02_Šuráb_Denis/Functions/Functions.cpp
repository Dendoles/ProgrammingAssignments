//Šuráb, Denis - 1DAE13
#include "pch.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

void TestOneParFunctions(float arg_angle);
void TestTwoParFunctions(int arg_num1, int arg_num2);

int main()
{
	float angle{ 0.f };
	float pi{ 3.1415926535f };
	double result{ };
	int number1{ 3 };
	int number2{ 4 };

	std::cout << cos(35) << std::endl;
	std::cout << cos(angle) << std::endl;

	result = int(pow(number1, number2));
	std::cout << result << std::endl;

	TestOneParFunctions(angle);
	TestTwoParFunctions(number1, number2);



	// 1. Show my data
	std::cout << "My name is Šuráb, Denis" << std::endl;
	std::cout << "I am in group 1DAE13" << std::endl << std::endl;
	
	// 2. Show my student history
	std::cout << "Name of my high school: Howest: Digital arts and entertainment" << std::endl;
	std::cout << "In the last year I had 4 hours of math a week" << std::endl << std::endl;

	// Wait
	std::cout << "Push ENTER to quit\n";
	std::cin.get();

	return 0;
}

void TestOneParFunctions(float arg_angle = 0.f) //function for angle and the cos value of the angle
{
	float pi{ 3.1415926535f };
	float piDividedByFour{ pi / 4.0f };

	std::cout << "Angle: " << arg_angle * piDividedByFour << std::endl;
	std::cout << "cos: " << cosf(arg_angle++ * piDividedByFour) << std::endl;

	std::cout << "Angle: " << arg_angle * piDividedByFour << std::endl;
	std::cout << "cos: " << cosf(arg_angle++ * piDividedByFour) << std::endl;

	std::cout << "Angle: " << arg_angle * piDividedByFour << std::endl;
	std::cout << "cos: " << cosf(arg_angle++ * piDividedByFour) << std::endl;

	std::cout << "Angle: " << arg_angle * piDividedByFour << std::endl;
	std::cout << "cos: " << cosf(arg_angle++ * piDividedByFour) << std::endl;

	std::cout << "Angle: " << arg_angle * piDividedByFour << std::endl;
	std::cout << "cos: " << cosf(arg_angle++ * piDividedByFour) << std::endl;
}
void TestTwoParFunctions(int arg_num1, int arg_num2) //function to calculate hypotenuse requires 2 arguments
{
	int hypotenuse{ };
	int two{ 2 };
	hypotenuse = sqrt(pow(arg_num1, two) + pow(arg_num2, two));
	std::cout << hypotenuse << std::endl;
}

