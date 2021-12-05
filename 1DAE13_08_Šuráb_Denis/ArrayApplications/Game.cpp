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
	ClearBackground();
	DrawClickedPoints();
	// Put your own draw statements here

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
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
			
			g_Points[UpdateAssigner()] = Point2f(float(e.x), float(g_WindowHeight - e.y));
			//for (int i = 0; i < g_PointsSize; i++)
			//{
			//	std::cout << i << ":   " << g_Points[i].x << '\t' << g_Points[i].y;
			//	std::cout << '\n';
			//}
			//std::cout << '\n';
		break;
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

int UpdateAssigner()
{
	if (g_Points[0].x != 0 &&
		g_Points[0].y != 0)
	{
		ShovePoints();
		//g_Assigner = g_PointsSize - 1;
		g_Assigner = 0;
	}
	else
	{
		g_Assigner--;
	}
	return g_Assigner;
}

void ShovePoints()
{
	for (int i{ 0 }; i < g_PointsSize - 1; i++)
	{
		g_Points[(g_PointsSize - 1) - i] = g_Points[((g_PointsSize - 1) - i - 1)];
	}
	//4 -> 3 -> 2 -> 1 -> 0

	//for (int i{ g_PointsSize - 1 }; i > 0; i--)
	//{
	//	if (i != 1)
	//	{
	//		g_Points[i - 1] = g_Points[i - 2];
	//	}
	//}
}

void DrawClickedPoints()
{
	const float radius{ 10 };
	for (int i{}; i < g_PointsSize; i++)
	{
		if (g_Points[i].x != 0 &&
			g_Points[i].y != 0)
		{
			SetColor(1, 1, 0);
			FillEllipse(g_Points[i], radius, radius);
			if (i != g_PointsSize - 1 &&
				g_Points[i + 1].x != 0 &&
				g_Points[i + 1].y != 0)
			{
				SetColor(1, 1, 1);
				DrawLine(g_Points[i], g_Points[i + 1]);
			}
		}
	}
}

#pragma endregion ownDefinitions