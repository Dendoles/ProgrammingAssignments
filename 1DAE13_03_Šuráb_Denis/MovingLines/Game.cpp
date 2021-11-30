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
	ClearBackground(0.392f, 0.392f, 0.667f);
	float xPosOfLine{0};
	float xPosOfLine2{g_WindowWidth};
	float yPosOfLine{ g_WindowHeight };
	float yPosOfLine2{ 0 };

	// Put your own draw statements here
	SetColor(1, 1, 1);

	DrawLine(xPosOfLine, yPosOfLine - g_NrFrameRate, xPosOfLine2, yPosOfLine - g_NrFrameRate);
	DrawLine(xPosOfLine, yPosOfLine2 + g_NrFrameRate, xPosOfLine2, yPosOfLine2 + g_NrFrameRate);

	DrawLine(xPosOfLine + g_NrFrameRate, yPosOfLine2, xPosOfLine + g_NrFrameRate, yPosOfLine);
	DrawLine(xPosOfLine2 - g_NrFrameRate, yPosOfLine2, xPosOfLine2 - g_NrFrameRate, yPosOfLine);

	SetColor(1,1,0);
	DrawLine(xPosOfLine2 - g_NrFrameRate, yPosOfLine, xPosOfLine, yPosOfLine - g_NrFrameRate);
	DrawLine(xPosOfLine, yPosOfLine - g_NrFrameRate, xPosOfLine + g_NrFrameRate, yPosOfLine2);
	DrawLine(xPosOfLine + g_NrFrameRate, yPosOfLine2, xPosOfLine2, yPosOfLine2 + g_NrFrameRate);
	DrawLine(xPosOfLine2, yPosOfLine2 + g_NrFrameRate, xPosOfLine2 - g_NrFrameRate, yPosOfLine);
}

void Update(float elapsedSec)
{
	++g_NrFrameRate;
	g_NrFrameRate = float(int(g_NrFrameRate) % int(g_WindowHeight));
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