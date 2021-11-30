//Šuráb, Denis - 1DAE13
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
	float thickness{ 1.5f }; //added a bit more thickness cause the example seemd thicker than my project
	float rectangleSize{ 4.f };
	float adjustingValue{0.25f}; //dont know if this is screen problem or something is offseted used only with the green border
	float halfOfTheWindowWidth{ g_WindowWidth / 2 };
	float halfOfTheWindowHeight(g_WindowHeight / 2);
	ClearBackground(0.725f,0.827f,0.933f);

	//Crossing red lines
	utils::SetColor(0.945f, 0.6f, 0.615f);
	utils::DrawLine(0.0f, 0.0f, g_WindowWidth, g_WindowHeight, thickness);
	utils::SetColor(0.945f, 0.6f, 0.615f);
	utils::DrawLine(g_WindowWidth, 0.f, 0.f, g_WindowHeight, thickness);

	//Green border
	utils::SetColor(0.149f, 0.415f, 0.203f);
	utils::DrawRect(adjustingValue, adjustingValue, g_WindowWidth - adjustingValue, g_WindowHeight - adjustingValue,thickness); //used the adjustingValue here cause if i only used 0 it was not visible on the screen from 2 sides (looked like it was offseted)

	//Grid
	utils::SetColor(1.f, 1.f, 1.f);
	utils::DrawLine(g_WindowWidth / 3, 0.f, g_WindowWidth / 3, g_WindowHeight, thickness);

	utils::SetColor(1.f, 1.f, 1.f);
	utils::DrawLine(g_WindowWidth* 2 / 3, 0.f, g_WindowWidth * 2 / 3, g_WindowHeight, thickness);

	utils::SetColor(1.f, 1.f, 1.f);
	utils::DrawLine(0.f, g_WindowHeight  / 3, g_WindowWidth, g_WindowHeight / 3, thickness);

	utils::SetColor(1.f, 1.f, 1.f);
	utils::DrawLine(0.f, g_WindowHeight * 2 / 3, g_WindowWidth, g_WindowHeight * 2 / 3, thickness);

	//Blue center point
	utils::SetColor(0.0784f, 0.0784f, 0.9412f);
	utils::FillRect(halfOfTheWindowWidth - (rectangleSize / 2), halfOfTheWindowHeight -(rectangleSize / 2), rectangleSize, rectangleSize); //I think you need to substract half of the rectangleSize for width and height so the center of rectangle is in middle of the screen otherwise the starting point(bottom-left would be in the middle)

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