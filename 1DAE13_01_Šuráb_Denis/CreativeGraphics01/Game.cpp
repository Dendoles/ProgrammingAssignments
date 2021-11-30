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
	ClearBackground(1.f, 1.f, 1.f);
	

	//Variables
	float halfOfWindowWidth(g_WindowWidth / 2.f);
	float halfOfWindowHeight(g_WindowHeight / 2.f);
	float lineThickness{ 3.f };
	float signSize{ g_WindowHeight / 5 };
	float widthOfRectangle{ 1.8f * signSize }; 
	float heightOfRectangle{ 0.25f * signSize };
	float arcSize{ 0.7f * signSize };
	float offsetForArcs{ signSize * 0.06f };

	//no entry sign
	SetColor(1.f, 0.f, 0.f);
	FillEllipse(halfOfWindowWidth / 2, halfOfWindowHeight / 2, signSize, signSize); // / 2 to place it at the bottom left 
	SetColor(1.f, 1.f, 1.f);
	FillEllipse(halfOfWindowWidth / 2, halfOfWindowHeight / 2, signSize * 0.8f, signSize * 0.8f); //dividing by 0.8 to get 80% of the diameter

	//do not enter sign
	SetColor(1.f, 0.f, 0.f);
	FillEllipse(halfOfWindowWidth * 1.5f, halfOfWindowHeight / 2, signSize, signSize); // *1.5 and / 2 to placee it bottom right
	SetColor(1.f, 1.f, 1.f);
	FillRect(halfOfWindowWidth * 1.5f - (widthOfRectangle / 2.f), halfOfWindowHeight / 2 - (heightOfRectangle / 2.f), widthOfRectangle, heightOfRectangle);

	//no waiting sign
	SetColor(1.f, 0.f, 0.f);
	FillEllipse(halfOfWindowWidth / 2, halfOfWindowHeight * 1.5f, signSize, signSize); // / 2 * 1.5 to place it top left 
	SetColor(0.212f, 0.176f, 0.506f);
	FillArc(halfOfWindowWidth / 2.f + offsetForArcs, halfOfWindowHeight * 1.5f + offsetForArcs, arcSize, arcSize, -g_Pi / 4, g_Pi * 3 / 4);
	FillArc(halfOfWindowWidth / 2.f - offsetForArcs, halfOfWindowHeight * 1.5f - offsetForArcs, arcSize, arcSize, g_Pi * 3 / 4, g_Pi * 7 /4);

	//no stopping sign
	SetColor(1.f, 0.f, 0.f);
	FillEllipse(halfOfWindowWidth * 1.5f, halfOfWindowHeight * 1.5f, signSize, signSize); // * 1.5 and * 1.5 to place it top right 
	SetColor(0.212f, 0.176f, 0.506f);
	FillArc(halfOfWindowWidth * 1.5f + offsetForArcs * 2, halfOfWindowHeight * 1.5f, arcSize, arcSize, -g_Pi / 4, g_Pi / 4);
	FillArc(halfOfWindowWidth * 1.5f, halfOfWindowHeight * 1.5f + offsetForArcs * 2, arcSize, arcSize, g_Pi / 4, g_Pi * 3 / 4);
	FillArc(halfOfWindowWidth * 1.5f - offsetForArcs * 2, halfOfWindowHeight * 1.5f, arcSize, arcSize, g_Pi * 3 / 4, g_Pi * 5 /4);
	FillArc(halfOfWindowWidth * 1.5f, halfOfWindowHeight * 1.5f - offsetForArcs * 2, arcSize, arcSize, g_Pi * 5 / 4, g_Pi * 7 /4);

	//GRID
	SetColor(0.f, 0.f, 0.f);
	DrawLine(halfOfWindowWidth, 0.f, halfOfWindowWidth, g_WindowHeight, lineThickness);
	DrawLine(0.f, halfOfWindowHeight, g_WindowWidth, halfOfWindowHeight, lineThickness);
	DrawRect(0.f, 0.f, g_WindowWidth, g_WindowHeight, lineThickness * 2); //  * 2 because one half of the lineThickness is outside
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