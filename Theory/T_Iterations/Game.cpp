#include "pch.h"
#include "Game.h"
#include <iostream>
#include <cmath>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	const int maxValue{ 1800 };
	int value{ 1 }, count{ };
	while (value < maxValue)
	{
		value += value;
		++count;
	}
	std::cout << count << std::endl; 

	int toGuess{};
	int randomNumber{};
	count = 0;

	//std::cin >> toGuess;
	do 
	{
		randomNumber = rand();
		++count;
	} while (toGuess != randomNumber);
	std::cout << "Number of guesses " << count;

	count = 0;
	toGuess = 0;
	randomNumber = 0;

	while (toGuess != randomNumber)
	{
		randomNumber = rand();
		++count;
	}
	std::cout << "Number of guesses " << count;

	for (float angle{}; angle < g_Pi * 2; angle += g_Pi * 2 / 15)
	{
		std::cout << angle << ' ' << sin(angle) << std::endl;
	}

}

void Draw()
{
	ClearBackground(0.1f,0.1f,0.1f);

	const float scaling{ 100 };
	const Point2f translation{ 50, g_WindowHeight / 2 };
	float posX1{ translation.x };
	float posX2{ translation.x + 1 };
	const float step{ g_Pi * 2 / 360 };

	for (float angle{}; angle < g_Pi * 2; angle += step)
	{
		float posY1{ sin(angle) * scaling + translation.y};
		float posY2{ sin(angle + step) * scaling + translation.y };
		++posX2;

		DrawLine(posX1, posY1, posX2, posY2);
		++posX1;
	}

	for (float angle{}; angle < g_Pi * 2; angle += step)
	{
		float posY2{ sin(angle + step) * scaling + translation.y };
		float posY1{ sin(angle) * scaling + translation.y };
		float posX1{ cos(angle) * scaling + translation.x };
		float posX2{ cos(angle + step) * scaling + translation.x };
		DrawLine(posX1, posY1, posX2, posY2);
	}

	FillRect(10.f, translation.y + sin(g_Angle) * 50.f, 50.f, 10.f);

}

void Update(float elapsedSec)
{

	g_Angle += 0.01f;
	// process input, do physics 

	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
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
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
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
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

#pragma endregion ownDefinitions