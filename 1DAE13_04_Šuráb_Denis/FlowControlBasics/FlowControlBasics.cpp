// Šuráb, Denis 1DAE13

#include "pch.h"
#include <iostream>
#include <time.h>
#include "structs.h"

void PrintTruthTable();
void CompareTwoNumbers();
void CalculatePrice();
void ConvertDayNumber();
void CheckLeapYear();
void ConvertSeconds();
void UseActorState();
void UsePoint2f();

int main()
{
	std::srand(unsigned int (time(NULL)));
	//PrintTruthTable();
	//CompareTwoNumbers();
	//CalculatePrice();
	//ConvertDayNumber();
	//CheckLeapYear();
	//ConvertSeconds();
	//UseActorState();
	//UsePoint2f();

}

void PrintTruthTable()
{
	const bool valueTrue{ true };
	const bool valueFalse{ false };

	std::cout << "- - Print truth table - -" << std::endl;
	std::cout << "Logical binary AND-operator (&&)" << std::endl;
	std::cout << std::boolalpha << valueTrue << " && " << valueTrue << " is " << (valueTrue && valueTrue) << std::endl;
	std::cout << std::boolalpha << valueTrue << " && " << valueFalse << " is " << (valueTrue && valueFalse) << std::endl;
	std::cout << std::boolalpha << valueFalse << " && " << valueTrue << " is " << (valueFalse && valueTrue) << std::endl;
	std::cout << std::boolalpha << valueFalse << " && " << valueFalse << " is " << (valueFalse && valueFalse) << std::endl;

	std::cout << "Logical binary OR-operator (&&)" << std::endl;
	std::cout << std::boolalpha << valueTrue << " || " << valueTrue << " is " << (valueTrue || valueTrue) << std::endl;
	std::cout << std::boolalpha << valueTrue << " || " << valueFalse << " is " << (valueTrue || valueFalse) << std::endl;
	std::cout << std::boolalpha << valueFalse << " || " << valueTrue << " is " << (valueFalse || valueTrue) << std::endl;
	std::cout << std::boolalpha << valueFalse << " || " << valueFalse << " is " << (valueFalse || valueFalse) << std::endl;

	std::cout << "Logical unary NOT-operator (!)" << std::endl;
	std::cout << std::boolalpha << "!" << valueTrue << " is " << (!valueTrue) << std::endl;
	std::cout << std::boolalpha << "!" << valueFalse << " is " << (!valueFalse) << std::endl;

}

void CompareTwoNumbers()
{
	int firstNumber{ std::rand() % 11 };
	int secondNumber{ std::rand() % 11 };

	std::cout << "- - Compare 2 numbers - -" << std::endl;
	std::cout << "First number is " << firstNumber << std::endl;
	std::cout << "Second number is " << secondNumber << std::endl;
	std::cout << "Second number is " << ((secondNumber > firstNumber) ? "larger" : "smaller") << " than first one" << std::endl;

}

void CalculatePrice()
{
	int numberOfBallpoints{};
	float priceForPiece{};
	const int number1{ 20 };
	const int number2{ 49 };
	const int number3{ 100 };
	const float moneyValue1{ 4.00f };
	const float moneyValue2{ 3.5f };
	const float moneyValue3{ 3.25f };
	const float moneyValue4{ 3.10f };
	float totalPrice{};

	std::cout << "- - Calculate price - -" << std::endl;
	std::cout << "Nr of ballpoints? ";
	std::cin >> numberOfBallpoints;

	//priceForPiece = ((numberOfBallpoints < number1) ? 4.f : (((numberOfBallpoints < number2) ? 3.5f : ((numberOfBallpoints <= number3) ? 3.25f : 3.10f))));
	if (numberOfBallpoints < number1)
	{
		totalPrice = moneyValue1 * numberOfBallpoints;
	}
	else if (numberOfBallpoints < number2)
	{
		totalPrice = moneyValue2 * numberOfBallpoints;
	}
	else if (numberOfBallpoints <= number3)
	{
		totalPrice = moneyValue3 * numberOfBallpoints;
	}
	else 
	{
		totalPrice = moneyValue4 * numberOfBallpoints;
	}

	std::cout << "Total price is " << totalPrice;
}

void ConvertDayNumber()
{
	int day{};

	std::cout << "Day number [1, 7] ? ";
	std::cin >> day;

	if (day == 1)
	{
		std::cout << "Start of the week";
	}
	else if (day == 2 || day == 3 || day == 4)
	{
		std::cout << "Middle of the week";
	}
	else if (day == 5)
	{
		std::cout << "Nearly weekend";
	}
	else if (day == 6 || day == 7)
	{
		std::cout << "Weekend";
	}
	else
	{
		std::cout << "Wrong day number";
	}
	switch (day)
	{
	case 1:
		std::cout << "\n" << "Monday";
		break;
	case 2:
		std::cout << "\n" << "Thusday";
		break;
	case 3:
		std::cout << "\n" << "Wednesday";
		break;
	case 4:
		std::cout << "\n" << "Thursday";
		break;
	case 5:
		std::cout << "\n" << "Friday";
		break;
	case 6:
		std::cout << "\n" << "Saturday";
		break;
	case 7:
		std::cout << "\n" << "Sunday";
		break;
	default:
		std::cout << "\n" << "Wrong day number";
		break;
	}
}

void CheckLeapYear()
{
	int year{};
	int leapYear{ 29 };
	int commonYear{ 28 };

	std::cout << "- - Check leap year - -" << std::endl;
	std::cout << "Year ? ";
	std::cin >> year;

	if ((year % 4) != 0)
	{
		std::cout << year << ": " << commonYear;
	}
	else if ((year % 100) != 0)
	{
		std::cout << year << ": " << leapYear;
	}
	else if ((year % 400) != 0)
	{
		std::cout << year << ": " << commonYear;
	}
	else
	{
		std::cout << year << ": " << leapYear;
	}

}

void ConvertSeconds()
{
	int inputSeconds{};
	int reminder{};
	std::cout << "- - Convert seconds - -" << std::endl;
	std::cout << "Number of seconds ?";
	std::cin >> inputSeconds;

	int days{ inputSeconds / (60 * 60 * 24) };
	reminder = inputSeconds % (60 * 60 * 24);
	int hours{ reminder / (60 * 60)};
	reminder = reminder  % (60 * 60);
	int minutes{ reminder / 60};
	reminder = reminder % 60;
	int seconds{ reminder };

	std::cout << days << " days" << std::endl << hours << " hours" << std::endl << minutes << " minutes" << std::endl << seconds << " seconds";
}

void UseActorState()
{
	enum class ActorState 
	{
		running, flying, falling
	};

	int randomNumber{ rand() % 3 };

	ActorState state{ ActorState(randomNumber) };
	
	std::cout << "- - Define and use ActorState - -" << std::endl;
	switch (state)
	{
	case ActorState::falling:
		std::cout << "falling";
		break;
	case ActorState::flying:
		std::cout << "flying";
		break;
	case ActorState::running:
		std::cout << "running";
		break;
	}
}
void UsePoint2f() 
{
	Point2f p1;
	Point2f p2{};
	Point2f p3{ 26, 25 };

	std::cout << "- - Define and use Point2f - -" << std::endl;
	//std::cout << "p1: [" << p1.x << ", " << p1.y << "]" << std::endl;
	std::cout << "p2: [" << p2.x << ", " << p2.y << "]" << std::endl;
	std::cout << "p3: [" << p3.x << ", " << p3.y << "]" << std::endl;

	p1.x = 20;
	p1.y = 3;
	p2 = Point2f{ 30, 40 };
	++p3.x;
	--p3.y;

	std::cout << "Values after changing the members" << std::endl;
	std::cout << "p1: [" << p1.x << ", " << p1.y << "]" << std::endl;
	std::cout << "p2: [" << p2.x << ", " << p2.y << "]" << std::endl;
	std::cout << "p3: [" << p3.x << ", " << p3.y << "]" << std::endl;
}