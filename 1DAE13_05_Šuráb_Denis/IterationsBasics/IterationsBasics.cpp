// 1DAE13 Šuráb, Denis

#include "pch.h"
#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>
#include <math.h>

void EvenNumbers();
void ExamScores();
void GuessNumber();
void Trigonometry();
void AsciiTable();

float g_Pi{ 3.14159265359f };

int main()
{
	std::srand(unsigned int(time(NULL)));
	//EvenNumbers();
	//ExamScores();
	//GuessNumber();
	//Trigonometry();
	AsciiTable();
}

void EvenNumbers()
{
	std::cout << "- - Even numbers - -" << std::endl;
	int i{};
	int upperBoundaryNumber{ 24 };

	do {
		i += 2;
		std::cout << i <<" ";

	} while (i < upperBoundaryNumber);

	std::cout << std::endl;
	i = 0;

	while (i < upperBoundaryNumber)
	{
		i += 2;
		std::cout << i << " ";
	}

	std::cout << std::endl;

	for (i = 2; i <= upperBoundaryNumber; i += 2)
	{
		std::cout << i << " ";
	}
}
void ExamScores()
{
	std::cout << "- - Exam scores - -" << std::endl;
	int i{};
	const int escapeNumber{ -1};
	int totalScore{}, value{};
	int a1{}, a{}, b{}, c{}, d{}, e{}, fx{}, f{};
	const int maxScore{ 20 };
	std::string enteredScores{};

	do {
		std::cout << "Score [ 0, 20 ] ?";
		std::cin >> value;
		if (value > maxScore || value < escapeNumber)
		{
			std::cout << "Wrong score!" << std::endl;
		}
		else
		{
			if (value != escapeNumber)
			{
				if (value > 17)
				{
					a1++;
				}
				else if (value > 15)
				{
					a++;
				}
				else if (value == 15)
				{
					b++;
				}
				else if (value > 12)
				{
					c++;
				}
				else if (value > 10)
				{
					d++;
				}
				else if (value == 10)
				{
					e++;
				}
				else if (value > 7)
				{
					fx++;
				}
				else
				{
					f++;
				}
				totalScore += value;
				enteredScores += std::to_string(value);
				enteredScores += ", ";
			}
		}

	} while (value != escapeNumber);


	std::cout << "A+: " << a1 << std::endl;
	std::cout << "A: " << a << std::endl;
	std::cout << "B: " << b << std::endl;
	std::cout << "C: " << c << std::endl;
	std::cout << "D: " << d << std::endl;
	std::cout << "E: " << e << std::endl;
	std::cout << "FX: " << fx << std::endl;
	std::cout << "F: " << f << std::endl;

	std::cout << "Total score: " << totalScore << std::endl;
	std::cout << "Entered scores: " << enteredScores;
}
void GuessNumber()
{
	int number{};
	int i{};
	int guess{};
	std::cout << "- - Guess number - -" << std::endl;
	do {
		std::cout << "Number to guess ? ";
		std::cin >> number;
		if (number < 0)
		{
			std::cout << "This is a wrong number, " << std::endl;
		}
	} while (number < 0);

	do {
		guess =  std::rand();
		i++;
	} while (guess != number);

	std::cout << "Number found after " << i << " guesses";
}
void Trigonometry()
{
	float degrees{};
	const float maxDegrees{ 180 };
	const float increment{ 10 };
	const float rowOffset{ 10 };

	std::cout << "- - Trigonometry - -" << std::endl;
	std::cout << std::setw(rowOffset) << "Degrees" << std::setw(rowOffset) << "Radians" << std::setw(rowOffset) << "Cos" << std::setw(rowOffset) << "Sin"<< std::endl;

	for (degrees; degrees <= maxDegrees; degrees += increment)
	{
		float radians{(degrees * g_Pi) / 180.f};
		float cosine{cosf(radians)};
		float sine{sinf(radians)};

		std::cout << std::fixed;
		std::cout << std::setw(rowOffset) << std::setprecision(0) << degrees;
		std::cout << std::setw(rowOffset) << std::setprecision(2) << radians; 
		std::cout << std::setw(rowOffset) << std::setprecision(2) << cosine;
		std::cout << std::setw(rowOffset) << std::setprecision(2) << sine << std::endl;
	}
}
void AsciiTable()
{
	std::cout << "- - ASCII table - -" << std::endl;
	const char lastChar{ 'z' };
	char originaFirstChar{'a'};
	char firstChar{ originaFirstChar };
	int iterations{};
	int rowOffset{ 5 };
	int valueOffset{ 10 };

	for (firstChar; firstChar <= lastChar; firstChar++)
	{
		iterations++;
	}
	int amount{ iterations / 2 };
	int amountOfIterations{ amount };

	while (amountOfIterations != 0)
	{
		std::cout << originaFirstChar << std::setw(valueOffset) << int(originaFirstChar) << std::setw(rowOffset);
		std::cout << char(originaFirstChar + amount) << std::setw(valueOffset) << int(originaFirstChar + amount);
		std::cout << std::endl;

		--amountOfIterations;
		++originaFirstChar;	
	}
}