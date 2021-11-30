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

	float outerRadius{ 200.f };
	float middleRadius{2 * outerRadius / 3 };
	float innerRadius{ outerRadius / 3 };
	float xPos{g_WindowWidth / 2.f};
	float yPos{g_WindowHeight / 2.f};

	//outer points 0 90 180 270 deg
	float radianPortionForOuterPoints{ g_Pi / 2.f};

	float outerX1{ outerRadius * cosf(0.f) + xPos };
	float outerY1{ outerRadius * sinf(0.f) + yPos };

	float outerX2{ outerRadius * cosf(radianPortionForOuterPoints) + xPos };
	float outerY2{ outerRadius * sinf(radianPortionForOuterPoints) + yPos };

	float outerX3{ outerRadius * cosf(2 * radianPortionForOuterPoints) + xPos };
	float outerY3{ outerRadius * sinf(2 * radianPortionForOuterPoints) + yPos };

	float outerX4{ outerRadius * cosf(3 * radianPortionForOuterPoints) + xPos };
	float outerY4{ outerRadius * sinf(3 * radianPortionForOuterPoints) + yPos };

	//middle points 45 135 225 315 deg
	float startingPointForMiddlePoints{ g_Pi / 4.f };

	float middleX1{ middleRadius * cosf(startingPointForMiddlePoints) + xPos };
	float middleY1{ middleRadius * sinf(startingPointForMiddlePoints) + yPos };

	float middleX2{ middleRadius * cosf(startingPointForMiddlePoints + radianPortionForOuterPoints) + xPos };
	float middleY2{ middleRadius * sinf(startingPointForMiddlePoints + radianPortionForOuterPoints) + yPos };

	float middleX3{ middleRadius * cosf(startingPointForMiddlePoints + (radianPortionForOuterPoints * 2)) + xPos };
	float middleY3{ middleRadius * sinf(startingPointForMiddlePoints + (radianPortionForOuterPoints * 2)) + yPos };

	float middleX4{ middleRadius * cosf(startingPointForMiddlePoints + (radianPortionForOuterPoints * 3)) + xPos };
	float middleY4{ middleRadius * sinf(startingPointForMiddlePoints + (radianPortionForOuterPoints * 3)) + yPos };

	//inner points1 30 120 210 300 deg
	float startingPointForInnerPoints1{ g_Pi / 6.f };

	float innerPoint1X1{ innerRadius * cosf(startingPointForInnerPoints1) + xPos };
	float innerPoint1Y1{ innerRadius * sinf(startingPointForInnerPoints1) + yPos };

	float innerPoint1X2{ innerRadius * cosf(startingPointForInnerPoints1 + radianPortionForOuterPoints) + xPos };
	float innerPoint1Y2{ innerRadius * sinf(startingPointForInnerPoints1 + radianPortionForOuterPoints) + yPos };

	float innerPoint1X3{ innerRadius * cosf(startingPointForInnerPoints1 + (radianPortionForOuterPoints * 2)) + xPos };
	float innerPoint1Y3{ innerRadius * sinf(startingPointForInnerPoints1 + (radianPortionForOuterPoints * 2)) + yPos };

	float innerPoint1X4{ innerRadius * cosf(startingPointForInnerPoints1 + (radianPortionForOuterPoints * 3)) + xPos };
	float innerPoint1Y4{ innerRadius * sinf(startingPointForInnerPoints1 + (radianPortionForOuterPoints * 3)) + yPos };

	//inner points2 60 150 240 330
	float startingPointForInnerPoints2{ g_Pi / 3.f };

	float innerPoint2X1{ innerRadius * cosf(startingPointForInnerPoints2) + xPos };
	float innerPoint2Y1{ innerRadius * sinf(startingPointForInnerPoints2) + yPos };

	float innerPoint2X2{ innerRadius * cosf(startingPointForInnerPoints2 + radianPortionForOuterPoints) + xPos };
	float innerPoint2Y2{ innerRadius * sinf(startingPointForInnerPoints2 + radianPortionForOuterPoints) + yPos };

	float innerPoint2X3{ innerRadius * cosf(startingPointForInnerPoints2 + (radianPortionForOuterPoints * 2)) + xPos };
	float innerPoint2Y3{ innerRadius * sinf(startingPointForInnerPoints2 + (radianPortionForOuterPoints * 2)) + yPos };

	float innerPoint2X4{ innerRadius * cosf(startingPointForInnerPoints2 + (radianPortionForOuterPoints * 3)) + xPos };
	float innerPoint2Y4{ innerRadius * sinf(startingPointForInnerPoints2 + (radianPortionForOuterPoints * 3)) + yPos };

	/*SetColor(1, 1, 1);
	DrawEllipse(xPos, yPos, outerRadius, outerRadius, 2.f);
	DrawEllipse(xPos, yPos, outerRadius * 2 / 3, outerRadius * 2 / 3, 2.f);
	DrawEllipse(xPos, yPos, outerRadius / 3, outerRadius / 3, 2.f);*/

	SetColor(1, 0, 0);
	DrawLine(outerX1, outerY1, innerPoint1X1, innerPoint1Y1);
	DrawLine(innerPoint1X1, innerPoint1Y1, middleX1, middleY1);
	DrawLine(middleX1, middleY1, innerPoint2X1, innerPoint2Y1);
	DrawLine(innerPoint2X1, innerPoint2Y1, outerX2, outerY2);
	DrawLine(outerX2, outerY2, innerPoint1X2, innerPoint1Y2);
	DrawLine(innerPoint1X2, innerPoint1Y2, middleX2, middleY2);
	DrawLine(middleX2, middleY2, innerPoint2X2, innerPoint2Y2);
	DrawLine(innerPoint2X2, innerPoint2Y2, outerX3, outerY3);
	DrawLine(outerX3, outerY3, innerPoint1X3, innerPoint1Y3);
	DrawLine(innerPoint1X3, innerPoint1Y3, middleX3, middleY3);
	DrawLine(middleX3, middleY3, innerPoint2X3, innerPoint2Y3);
	DrawLine(innerPoint2X3, innerPoint2Y3, outerX4, outerY4);
	DrawLine(outerX4, outerY4, innerPoint1X4, innerPoint1Y4);
	DrawLine(innerPoint1X4, innerPoint1Y4, middleX4, middleY4);
	DrawLine(middleX4, middleY4, innerPoint2X4, innerPoint2Y4);
	DrawLine(innerPoint2X4, innerPoint2Y4, outerX1, outerY1);

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