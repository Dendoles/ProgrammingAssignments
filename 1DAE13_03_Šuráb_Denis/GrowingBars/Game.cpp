#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{

}

void Draw()
{
	ClearBackground(0.3f,0.3f,0.3f);
	DrawRectangles();
	// Put your own draw statements here

}

void Update(float elapsedSec)
{
	++g_NrFrames;
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
void DrawRectangles()
{
	const float border{ 20.f };
	const float widthOfBorderRect{g_WindowWidth - border * 2.f };
	const int framesForRed{ 30 };
	const float pixels{ 15.f };
	const float heightOfBorderRect{ 150.f };
	const float lineSize{ 2.5f };
	const float startingRedColor{ 0.4705f };
	float growingNumberForYellowRect{ float(g_NrFrames % int(widthOfBorderRect)) };
	float rangeFrom0to1{ float((g_NrFrames % framesForRed) + 1) / framesForRed };
	float growingNumberForRedRect{ int(rangeFrom0to1) * pixels };
	float offset{0.3f};

	g_RedRectWidth += growingNumberForRedRect;
	g_RedRectWidth = float(int(g_RedRectWidth) % int(widthOfBorderRect));

	float colorChange{ (((int(g_RedRectWidth) % int(widthOfBorderRect) + 1)) / widthOfBorderRect) + offset };
	//colorChange = float(int(startingRedColor + colorChange) % int());

	//float colorChange{ float((int(g_RedRectWidth) % int(widthOfBorderRect) + 1)) };
	//colorChange = colorChange % 

	std::cout << colorChange << std::endl;

	SetColor(0.784f, 0.784f, 0); //yellowish
	FillRect(border, g_WindowHeight - border - heightOfBorderRect, growingNumberForYellowRect, heightOfBorderRect);
	SetColor(colorChange,0.09f,0.f ); // redish
	FillRect(border, border, g_RedRectWidth, heightOfBorderRect);


	//border Rects
	SetColor(1, 1, 1);
	DrawRect(border, border, widthOfBorderRect, heightOfBorderRect, lineSize);
	DrawRect(border, g_WindowHeight - border - heightOfBorderRect, widthOfBorderRect, heightOfBorderRect, lineSize);
}


#pragma endregion ownDefinitions