#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	char cString[]{ "MeowMeow" };
	//std::cout << sizeof(cString) << '\t' << cString << '\n';
	//cString[8] = 'A';
	//std::cout << sizeof(cString) << '\t' << cString << '\n';  WE ARE OVERWRITING THE 0 BAAD => undefined behaviour

	std::string carBrand{"BMW"};
	const char* pChar{ carBrand.c_str() };
	//std::cout << sizeof(pChar) << '\t' << pChar; // size is 4 cause it is a pointer

	//int numbers[1000000]{}; Stackoverflow

	g_NumberOfElements = 100;
	g_pNumbers = new int[g_NumberOfElements]{};
	
	for (int i{}; i < g_NumberOfElements; i++)
	{
		g_pNumbers[i] = i;
		std::cout << g_pNumbers[i] << '\n';
	}

	g_pPoints = new Point2f[g_NumberOfElements];

	for (int i{}; i < g_NumberOfElements; i++)
	{
		g_pPoints[i] = Point2f( float(rand() % int(g_WindowWidth)), float(rand() % int(g_WindowHeight)));
	}
}

void Draw()
{
	ClearBackground();
	for (int i{}; i < g_NumberOfElements - 1; i++)
	{
		g_pPoints[i] = Point2f(float(rand() % int(g_WindowWidth)), float(rand() % int(g_WindowHeight)));
		DrawLine(g_pPoints[i], g_pPoints[i + 1]);
	}
	// Put your own draw statements here

}

void Update(float elapsedSec)
{
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
	delete[] g_pPoints;
	delete[] g_pNumbers;
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