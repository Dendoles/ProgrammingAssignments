#include "pch.h"
#include "Game.h"
#include  <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground(0.3f,0.3f,0.3f);

	float size{ 10.f };
	// Put your own draw statements here
	SetColor(0, 1, 0);
	FillRect(g_MousePos.x - size / 2.f, g_MousePos.y - size / 2.f, size, size);
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
		std::cout << "Left arrow key released\n";
		break;
	case SDLK_RIGHT:
		std::cout << "Right arrow key released\n";
		break;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	g_MousePos.x = float(e.x);
	g_MousePos.y = float(g_WindowHeight - e.y);
	std::cout << "Position X: " << g_MousePos.x << ' ' << "Position Y: " << g_MousePos.y << std::endl;
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		std::cout << "Clicked the left mouse button\n" << e.x <<  ' ' << e.y;
		break;
	case SDL_BUTTON_RIGHT:
		std::cout << "Clicked the right mouse button\n" << e.x << ' ' << e.y;
		break;
	case SDL_BUTTON_MIDDLE:
		std::cout << "Clicked the middle mouse button\n" << e.x << ' ' << e.y;
		break;
	case SDL_BUTTON_X1:
		std::cout << "Clicked the mouse button 4\n" << e.x << ' ' << e.y;
		break;
	case SDL_BUTTON_X2:
		std::cout << "Clicked the mouse button 5\n" << e.x << ' ' << e.y;
		break;
	}
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