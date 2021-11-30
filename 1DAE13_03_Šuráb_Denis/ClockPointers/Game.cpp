#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground(0.1f,0.1f,0.1f);
	float startingPosX{g_WindowWidth / 2.f};
	float startingPosY{ g_WindowHeight / 2.f };
	float radiusForBiggerOne{ 200.f};
	float radiusForSmallerOne{ 180.f };

	float x1{ radiusForBiggerOne * cosf(1.f) + startingPosX };
	float y1{ radiusForBiggerOne * sinf(0.f) + startingPosY };

	float x2{ radiusForSmallerOne * cosf(1.f) + startingPosX };
	float y2{ radiusForSmallerOne * sinf(0.f) + startingPosY };

	SetColor(1, 1, 1);
	DrawLine(startingPosX, startingPosY, x1, y1);
	DrawLine(startingPosX, startingPosY, x2, y2);
}

void Update(float elapsedSec)
{
	++g_AngleForBigPointer;
	++g_AngleForSmallPointeer;

	/*g_AngleForBigPointer = float(int(g_AngleForBigPointer) % int(2 * g_Pi));
	g_AngleForSmallPointeer = float(int(g_AngleForSmallPointeer) % int(2 * g_Pi));*/

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