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
	ClearBackground();
	Point2f left{ 0, 1 };
	Point2f top{ g_WindowWidth/ 2.f, g_WindowHeight };
	Point2f right{ g_WindowWidth, 1};

	SetColor(1, 1, 1);
	DrawSierpinskiTriangle(left, top, right);


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

void DrawSierpinskiTriangle(const Point2f& left, const Point2f& top, const Point2f& right)
{
	if (DistanceBetweenPoints(left, right) < g_MinimalSize)
	{
		return;
	}
	DrawTriangle(left, top, right);

	SetColor(1, 0, 0);
	DrawSierpinskiTriangle(left, MidOfPoint(left, top), MidOfPoint(left, right));
	SetColor(0, 1, 0);
	DrawSierpinskiTriangle(MidOfPoint(left, top), top, MidOfPoint(top, right));
	SetColor(0, 0, 1);
	DrawSierpinskiTriangle(MidOfPoint(left, right), MidOfPoint(top, right), right);

}

float DistanceBetweenPoints(const Point2f& point1, const Point2f& point2)
{
	float vecX{ abs(point1.x - point2.x)};
	float vecY{ abs (point1.y - point2.y)};
	return sqrtf(powf(vecX, 2) + powf(vecY, 2));
}

Point2f MidOfPoint(const Point2f& point1, const Point2f& point2)
{
	Point2f point{ (point1.x + point2.x) / 2.f, (point1.y + point2.y) / 2.f};
	return point;
}
#pragma endregion ownDefinitions