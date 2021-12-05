#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	InitPentagramSpeed();
	// initialize game resources here
}

void Draw()
{
	ClearBackground();
	DrawClickedPoints();
	DrawPentagram();
	// Put your own draw statements here

}

void Update(float elapsedSec)
{
	UpdatePentagram(elapsedSec);
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

void DrawPentagram()
{
	const float size{ 300 };
	Color4f green{ 0,1,0,1 };
	Point2f pos{ g_WindowWidth / 2.f, g_WindowHeight / 2.f };
	SetColor(green);
	for (int i{}; i < g_AngleSpeedSize; i++)
	{
		const float offset{ (2.f * g_Pi) / 5.f };
		Point2f p1{ size * cosf(0.f + g_AngleSpeed[i].angle) + pos.x, size * sinf(0.f + g_AngleSpeed[i].angle) + pos.y };
		Point2f p2{ size * cosf(offset + g_AngleSpeed[i].angle) + pos.x,  size * sinf(offset + g_AngleSpeed[i].angle) + pos.y };
		Point2f p3{ size * cosf(offset * 2.f + g_AngleSpeed[i].angle) + pos.x, size * sinf(offset * 2.f + g_AngleSpeed[i].angle) + pos.y };
		Point2f p4{ size * cosf(offset * 3.f + g_AngleSpeed[i].angle) + pos.x,   size * sinf(offset * 3.f + g_AngleSpeed[i].angle) + pos.y };
		Point2f p5{ size * cosf(offset * 4.f + g_AngleSpeed[i].angle) + pos.x,   size * sinf(offset * 4.f + g_AngleSpeed[i].angle) + pos.y };

		DrawLine(p1.x, p1.y, p3.x, p3.y);
		DrawLine(p1.x, p1.y, p4.x, p4.y);
		DrawLine(p2.x, p2.y, p4.x, p4.y);
		DrawLine(p2.x, p2.y, p5.x, p5.y);
		DrawLine(p3.x, p3.y, p5.x, p5.y);
	}
}

void UpdatePentagram(float elapsedTime)
{
	for (int i{}; i < g_AngleSpeedSize; i++)
	{
		g_AngleSpeed[i].angle += (g_AngleSpeed[i].speed * elapsedTime);
	}
}

void InitPentagramSpeed()
{
	float startingNumber{0.2f};
	float endingNumber{1.1f};
	for (int i{}; i < g_AngleSpeedSize; i++)
	{
		g_AngleSpeed[i].speed = (rand() % (int(endingNumber - startingNumber * 100.f) + 1) + int(startingNumber * 100.f)) / 100.f;
	}
}

#pragma endregion ownDefinitions