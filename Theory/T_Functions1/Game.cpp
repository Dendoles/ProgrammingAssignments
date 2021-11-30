#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	int result{}, number1{ 14 }, number2{ 2 };
	result = CalculateSum(number1,number2);
}

void Draw()
{
	ClearBackground(0.3f,0.3f,0.3f);
	// Put your own draw statements here
	SetColor(0, 0, 1);
	FillRect(g_PosX, 10, 50, 10);
	SetColor(1, 0, 0);
	FillRect(g_PosXFramerateIndependent, 200, 50, 10);

}

void Update(float elapsedSec)
{
	// process input, do physics 

	g_PosX += g_SpeedX;
	g_PosXFramerateIndependent += g_SpeedX * elapsedSec;
	if (g_PosX > g_WindowWidth)
	{
		g_PosX -= g_WindowWidth;
	}
	if (g_PosXFramerateIndependent > g_WindowWidth)
	{
		g_PosXFramerateIndependent -= g_WindowWidth;
	}

	std::cout << elapsedSec << std::endl;

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
int CalculateSum(int a, int b) 
{
	int result{};
	result = a + b;
	return result;
}

#pragma endregion ownDefinitions