#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	PrintLetters();
	// initialize game resources here
}

void Draw()
{
	ClearBackground();
	SetColor(g_RandomColor);
	FillEllipse(g_MousePos.x, g_MousePos.y, g_GrowingSize, g_GrowingSize);
}

void Update(float elapsedSec)
{
	if (g_CurrentState == StateOfCircle::growing)
	{
		HandlingGrowing();
		CollisionCheck();
	}
	if (g_CurrentState == StateOfCircle::shrinking)
	{
		HandlingShrinking();
	}
	if (!g_WasPrinted)
	{
		PrintCurrentState();
	}
}

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_UP:
		IncreaseSpeed();
		PrintSpeedValue();
		break;
	case SDLK_DOWN:
		DecreaseSpeed();
		PrintSpeedValue();
		break;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		if (g_CurrentState == StateOfCircle::waiting)
		{
			//std::cout << "Left mouse button released\n";
			g_MousePos.x = float(e.x);
			g_MousePos.y = float( g_WindowHeight - e.y );
			g_CurrentState = StateOfCircle::growing;
			PrintCurrentState();
			RandomiseValues();
			PrintRandomisedValue();
		}
		break;
	}
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

void PrintLetters()
{
	int numberOfCharacters{};
	char startingCharacter{'a'};
	const char endingCharacter{'z'};

	std::cout << "How many characters per line ?" << std::endl;
	std::cin >> numberOfCharacters;

	while (startingCharacter < endingCharacter)
	{
		for (int iterations = 0; iterations < numberOfCharacters; iterations++)
		{
			if (startingCharacter <= endingCharacter)
			{
				std::cout << startingCharacter;
			}
			startingCharacter++;
		}
		std::cout << std::endl;
	}
}

void RandomiseValues()
{
	const float minGrow{ 50 };
	const float maxGrow{ 150 };
	float r{ (rand() % 256 + 0) / 255.f };
	float g{ (rand() % 256 + 0) / 255.f };
	float b{ (rand() % 256 + 0) / 255.f };

	g_RandomColor = Color4f{r, g, b, 1};
	g_MaxValue = float(rand() % int(maxGrow + 1) + int(minGrow));
}

void PrintRandomisedValue()
{
	std::cout << "The maximum radius is " << g_MaxValue << std::endl;
}

void PrintCurrentState()
{
	if (g_CurrentState == StateOfCircle::growing)
	{
		std::cout << "Growing state." << std::endl;
	}
	else if (g_CurrentState == StateOfCircle::shrinking)
	{
		std::cout << "Shrinking state." << std::endl;
	}
	else
	{
		std::cout << "Waiting state." << std::endl << std::endl;
	}
	g_WasPrinted = true;
}

void IncreaseSpeed()
{
	const float incrementingValue{0.4f};
	const float maxValue{ 5 };

	if ((g_Speed + incrementingValue) > maxValue)
	{
		g_Speed = maxValue;
	}
	else
	{
		g_Speed += incrementingValue;
	}
}

void DecreaseSpeed()
{
	const float decrementingValue{ 0.4f };
	const float minValue{ 0.2f };
	if ((g_Speed - decrementingValue) < minValue ) 
	{
		g_Speed = minValue;
	}
	else
	{
		g_Speed -= decrementingValue;
	}
}

void PrintSpeedValue()
{
	std::cout << "g_Speed = " << g_Speed << std::endl;
}

void CollisionCheck()
{
		bool isCollided{ false };

		if (g_MousePos.x + g_MaxValue > g_WindowWidth)
		{
			g_MaxValue = g_WindowWidth - g_MousePos.x;
			isCollided = true;
		}
		if (g_MousePos.x - g_MaxValue < 0)
		{
			g_MaxValue = g_MousePos.x;
			isCollided = true;
		}
		if (g_MousePos.y + g_MaxValue > g_WindowHeight)
		{
			g_MaxValue = g_WindowHeight - g_MousePos.y;
			isCollided = true;
		}
		if (g_MousePos.y - g_MaxValue < 0)
		{
			g_MaxValue = g_MousePos.y;
			isCollided = true;
		}
		if (isCollided)
		{
			std::cout << "Ouch!" << std::endl;
		}
}

void HandlingGrowing()
{
	if (g_GrowingSize < g_MaxValue)
	{
		g_GrowingSize += g_Speed;
	}
	else
	{
		g_CurrentState = StateOfCircle::shrinking;
		g_WasPrinted = false;
	}
}

void HandlingShrinking() 
{
	if ((g_GrowingSize > 0))
	{
		if ((g_GrowingSize - g_Speed) > 0)
		{
			g_GrowingSize -= g_Speed;
		}
		else
		{
			g_GrowingSize = 0;
		}
	}
	else
	{
		g_CurrentState = StateOfCircle::waiting;
		g_WasPrinted = false;
	}
}

#pragma endregion ownDefinitions