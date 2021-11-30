#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground(0.196f, 0.078f, 0.196f);
	DrawHouse();
	DrawFlag();
	DrawCheckerPattern();
	DrawColorBand();
	DrawPentagram();
	DrawColumnChart();
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
void DrawHouse()
{
	float xPosOfHouse{ 20.f };
	float yPosOfHouse{ g_WindowHeight * 2.f / 3.f };
	float lineSize{ 1.5f };
	float houseWidth{ 400.f };
	float baseHeight{ 70.f };
	float heightOfTheRoof{ baseHeight * 1.2f }; // roof is 120% of the base height

	Point2f p1{ xPosOfHouse, yPosOfHouse + baseHeight };
	Point2f p2{ xPosOfHouse + houseWidth, yPosOfHouse + baseHeight };
	Point2f p3{ xPosOfHouse + (houseWidth / 2.f), yPosOfHouse + baseHeight + heightOfTheRoof};


	SetColor(1, 0, 0);
	FillRect(xPosOfHouse, yPosOfHouse, houseWidth, baseHeight);
	FillTriangle(p1, p2, p3);

	SetColor(1.f, 1.f, 1.f);
	DrawRect(xPosOfHouse, yPosOfHouse, houseWidth, baseHeight, lineSize);
	DrawTriangle(p1, p2, p3, lineSize);
}
void DrawFlag() 
{
	float xPosOfRect{ 20.f };
	float yPosOfRect{ g_WindowHeight / 3.f };
	float oneProportion{ 80.f };
	float lineSize{ 1.5f };
	float thirdOfLineSize{ lineSize / 3.f };

	SetColor(1, 1, 1);
	DrawRect(xPosOfRect, yPosOfRect, oneProportion * 3.f, oneProportion * 2.f , lineSize);  // times 2 and 3 to make an accurate proportion of flags
	SetColor(0, 0, 0);
	FillRect(xPosOfRect + thirdOfLineSize, yPosOfRect + thirdOfLineSize, oneProportion - thirdOfLineSize, oneProportion * 2.f - thirdOfLineSize);
	SetColor(1, 1, 0);
	FillRect(xPosOfRect + oneProportion + thirdOfLineSize, yPosOfRect + thirdOfLineSize, oneProportion - thirdOfLineSize, oneProportion * 2.f - thirdOfLineSize);
	SetColor(1, 0, 0);
	FillRect(xPosOfRect + 2 * oneProportion + thirdOfLineSize, yPosOfRect + thirdOfLineSize, oneProportion - thirdOfLineSize, oneProportion * 2.f - thirdOfLineSize);
}
void DrawCheckerPattern() 
{
	float xPosOfRect{ 20.f };
	float yPosOfRect{ 20.f };
	float lineSize{ 1.5f };
	float rectSize{ 100.f };
	float smallRectSize{ rectSize / 3.f };
	Color4f colorOfBorder(1.f, 1.f, 1.f, 1.f);
	Color4f colorOfFiveBoxes(0.f, 0.f, 0.f, 1.f);
	Color4f colorOfFourBoxes(1.f, 1.f, 1.f, 1.f);

	SetColor(colorOfBorder);
	DrawRect(xPosOfRect, yPosOfRect, rectSize, rectSize, lineSize);

	SetColor(colorOfFiveBoxes);
	FillRect(xPosOfRect, yPosOfRect, smallRectSize, smallRectSize);
	FillRect(xPosOfRect + (2.f * smallRectSize), yPosOfRect, smallRectSize, smallRectSize);
	FillRect(xPosOfRect, yPosOfRect + (2.f * smallRectSize), smallRectSize, smallRectSize);
	FillRect(xPosOfRect + (2.f * smallRectSize), yPosOfRect + (2.f * smallRectSize), smallRectSize, smallRectSize);
	FillRect(xPosOfRect + smallRectSize, yPosOfRect + smallRectSize, smallRectSize, smallRectSize);

	SetColor(colorOfFourBoxes);
	FillRect(xPosOfRect + smallRectSize, yPosOfRect, smallRectSize, smallRectSize);
	FillRect(xPosOfRect, yPosOfRect + smallRectSize, smallRectSize, smallRectSize);
	FillRect(xPosOfRect + smallRectSize, yPosOfRect + (2.f * smallRectSize), smallRectSize, smallRectSize);
	FillRect(xPosOfRect + (2.f * smallRectSize), yPosOfRect + smallRectSize, smallRectSize, smallRectSize);
}
void DrawColorBand() 
{
	float xPosOfColorBand{ g_WindowWidth / 2 + 20.f };
	float yPosOfColorBand{ g_WindowHeight * 2.f / 3.f };
	float lineSize{ 6.f };
	float borderWidth{ 250.f };
	float borderHeight{ 100.f };
	float widthOfOneRect{ borderWidth / 9.f };

	Color4f colorOfBorder(1.f, 1.f, 0.f, 1.f);

	SetColor(colorOfBorder);
	DrawRect(xPosOfColorBand, yPosOfColorBand, borderWidth, borderHeight, lineSize);

	SetColor(0.196f, 0.196f, 0.196f);
	FillRect(xPosOfColorBand, yPosOfColorBand, widthOfOneRect, borderHeight);
	SetColor(1.f, 0.f, 0.f);
	FillRect(xPosOfColorBand + widthOfOneRect, yPosOfColorBand, widthOfOneRect, borderHeight);
	SetColor(0.f,1.f,0.f);
	FillRect(xPosOfColorBand + (widthOfOneRect * 2.f), yPosOfColorBand, widthOfOneRect, borderHeight);
	SetColor(0.f,0.f,1.f);
	FillRect(xPosOfColorBand + (widthOfOneRect * 3.f), yPosOfColorBand, widthOfOneRect, borderHeight);
	SetColor(1.f,0.f,1.f);
	FillRect(xPosOfColorBand + (widthOfOneRect * 4.f), yPosOfColorBand, widthOfOneRect, borderHeight);
	SetColor(1.f,1.f,0.f);
	FillRect(xPosOfColorBand + (widthOfOneRect * 5.f), yPosOfColorBand, widthOfOneRect, borderHeight);
	SetColor(0.f,1.f,0.f);
	FillRect(xPosOfColorBand + (widthOfOneRect * 6.f), yPosOfColorBand, widthOfOneRect, borderHeight);
	SetColor(0.f,1.f,1.f);
	FillRect(xPosOfColorBand + (widthOfOneRect * 7.f), yPosOfColorBand, widthOfOneRect, borderHeight);
	SetColor(1.f,1.f,1.f);
	FillRect(xPosOfColorBand + (widthOfOneRect * 8.f), yPosOfColorBand, widthOfOneRect, borderHeight);

	SetColor(0.f, 0.f, 0.f, 0.5f);
	FillRect(xPosOfColorBand, yPosOfColorBand, borderWidth, borderHeight / 2.f);
}
void DrawPentagram() 
{
	float xPosOfPenta{ g_WindowWidth / 2 + 120.f };
	float yPosOfPenta{ g_WindowHeight / 3.f + 50.f};
	float lineSize{ 3.f };
	float offset{ (2.f * g_Pi) / 5.f };
	float radius{ 100.f };

	float x1{ radius * cosf(0.f) + xPosOfPenta};
	float y1{ radius * sinf(0.f) + yPosOfPenta };
	float x2{ radius * cosf(offset) + xPosOfPenta };
	float y2{ radius * sinf(offset) + yPosOfPenta };
	float x3{ radius * cosf(offset * 2.f) + xPosOfPenta };
	float y3{ radius * sinf(offset * 2.f) + yPosOfPenta };
	float x4{ radius * cosf(offset * 3.f) + xPosOfPenta };
	float y4{ radius * sinf(offset * 3.f) + yPosOfPenta };
	float x5{ radius * cosf(offset * 4.f) + xPosOfPenta };
	float y5{ radius * sinf(offset * 4.f) + yPosOfPenta };

	SetColor(1.f, 0.f, 0.5f);
	DrawLine(x1, y1, x3, y3, lineSize);
	DrawLine(x1, y1, x4, y4, lineSize);
	DrawLine(x2, y2, x4, y4, lineSize);
	DrawLine(x2, y2, x5, y5, lineSize);
	DrawLine(x3, y3, x5, y5, lineSize);
}
void DrawColumnChart()
{
	float xPosOfChart{ g_WindowWidth / 2 + 20.f };
	float yPosOfChart{ 20.f };
	float widthOfChart{ 160.f };
	float heightOfChart{ 100.f };
	float widthOfOneColumn{ widthOfChart / 4.f };

	float firstPercentage{ 20.f }; //in range of [0, 20]
	float secondPercentage{ 35.f }; //in range of [21, 40]
	float thirdPercentage{ 12.f }; //in range of [41, 60]
	float fourthPercentage{ 90.f }; //more than 60

	 //i keep it commented cause i dont know how to stop the looping after inputing the numbers
	std::cout << "% people playing games" << std::endl;
	std::cout << "In the range [0, 20]? ";
	std::cin >> firstPercentage;
	std::cout << "In the range [21, 40]? ";
	std::cin >> secondPercentage;
	std::cout << "In the range [41, 60]? ";
	std::cin >> thirdPercentage;
	std::cout << "Older than 60? ";
	std::cin >> fourthPercentage;

	firstPercentage /= 100.f;
	secondPercentage /= 100.f;
	thirdPercentage /= 100.f;
	fourthPercentage /= 100.f;

	SetColor(0.f, 0.545f, 0.545f);
	FillRect(xPosOfChart, yPosOfChart, widthOfOneColumn, heightOfChart * firstPercentage);
	SetColor(0.f, 0.604f, 0.804f);
	FillRect(xPosOfChart + widthOfOneColumn, yPosOfChart, widthOfOneColumn, heightOfChart * secondPercentage);
	SetColor(0.f, 0.749f, 1.f);
	FillRect(xPosOfChart + (widthOfOneColumn * 2.f), yPosOfChart, widthOfOneColumn, heightOfChart * thirdPercentage);
	SetColor(0.f, 0.545f, 0.804f);
	FillRect(xPosOfChart + (widthOfOneColumn * 3.f), yPosOfChart, widthOfOneColumn, heightOfChart * fourthPercentage);

}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

#pragma endregion ownDefinitions