#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	int number{ rand() % 11 };
	if (number < 5)
	{
		std::cout << "Number is smaller than 5";
	}
	else
	{
		std::cout << "number is larger or equals 5";
	}
	std::cout << "number is " <<((number < 5) ? "smaller than 5 \n" : "larger or equals 5\n");

	g_Position.x = g_WindowWidth / 2;
	g_Position.y = g_WindowHeight / 2;
}

void Draw()
{
	ClearBackground(0.1f, 0.1f, 0.1f);
	float radius{ 10 };

	SetColor(0.f,0.3f, 0.7f);
	FillEllipse(g_Position, radius, radius);

}

void Update(float elapsedSec)
{
	float speed{ 2 };

	switch (g_DirectionState)
	{
	case DirectionState::right:
		g_Position.x += speed;
		break;
	case DirectionState::left:
		g_Position.x -= speed;
		break;
	case DirectionState::down:
		g_Position.y -= speed;
		break;
	case DirectionState::up:
		g_Position.y += speed;
		break;
	}

	if (g_Position.x > g_WindowWidth)
	{
		g_DirectionState = DirectionState::left;
	}

	if (g_Position.x < g_WindowWidth)
	{
		g_DirectionState = DirectionState::right;
	}

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
	switch (key)
	{
	case SDLK_LEFT:
		g_DirectionState = DirectionState::left;
		break;
	case SDLK_RIGHT:
		g_DirectionState = DirectionState::right;
		break;
	case SDLK_UP:
		g_DirectionState = DirectionState::up;
		break;
	case SDLK_DOWN:
		g_DirectionState = DirectionState::down;
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