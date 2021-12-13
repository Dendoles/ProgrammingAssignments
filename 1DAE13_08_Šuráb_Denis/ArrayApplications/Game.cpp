#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	InitPentagramSpeed();
	LoadAndCheckTextures();
	// initialize game resources here
}

void Draw()
{
	ClearBackground();
	DrawPentagram();
	DrawRandStats();
	DrawFollowingBubbles();
	DrawGrid();
	DrawClickedPoints();
	// Put your own draw statements here

}

void Update(float elapsedSec)
{
	UpdatePentagram(elapsedSec);
	UpdateRandStats();
	UpdateBubbles();
	UpdateGrids();
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
	for (int i{}; i < g_RandSize; i++)
	{
		DeleteTexture(g_RandNumbers[i]);
	}
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
	g_MousePos = Point2f(float( e.x ), float( g_WindowHeight - e.y ));
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
		g_ClickPos = Point2f(float(e.x), float(g_WindowHeight - e.y));
		break;

	case SDL_BUTTON_RIGHT:
		CheckCollision();
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
	const float size{ 100 };
	Color4f green{ 0,1,0,1 };
	Point2f pos{ g_WindowWidth * 3.f / 4.f, g_WindowHeight / 2.f };
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

void UpdateRandStats()
{
	int randomNumber{rand() % g_RandSize};
	g_RandValues[randomNumber]++;
}

void LoadAndCheckTextures()
{
	bool wasLoaded{true};
	for (int i{}; i < g_RandSize; i++)
	{
		wasLoaded = TextureFromString(std::to_string(i), "Resources/DIN-Light.otf", 20, g_ColorForRand, g_RandNumbers[i]);
		if (!wasLoaded)
		{
			std::cout << "Hey i think something wrong happend while loading the Resources/DIN-Light.otf \t index: " << i << '\n';
		}
	}
}

void DrawRandStats()
{
	const float radius{10.f};
	for (int i{}; i < g_RandSize; i++)
	{
		Point2f posOfTextures{ radius, g_RandNumbers[i].height + (g_RandNumbers[i].height * i) + (i * radius)};
		Point2f posOfRects{ g_RandNumbers[i].width + radius * 2.f, g_RandNumbers[i].height + (g_RandNumbers[i].height * i) + (i * radius) };
		SetColor(g_ColorForRand);
		DrawTexture(g_RandNumbers[i], posOfTextures);
		FillRect(posOfRects, float(g_RandValues[i]), g_RandNumbers[i].height);
	}
}

void UpdateBubbles()
{
	if (g_BubblePoints[g_BubblePointsSize - 1].x == 0 &&
		g_BubblePoints[g_BubblePointsSize - 1].y == 0)
	{
		for (int i{}; i < g_BubblePointsSize; i++)
		{
			g_BubblePoints[i] = g_MousePos;
		}
	}
	else
	{
		for (int i{ 0 }; i < g_BubblePointsSize - 1; i++)
		{
			g_BubblePoints[(g_BubblePointsSize - 1) - i] = g_BubblePoints[((g_BubblePointsSize - 1) - i - 1)];
			Sleep(5);
		}
		g_BubblePoints[0] = g_MousePos;
	}
}

void DrawFollowingBubbles()
{
	const float sizeOfBiggestBubble{ 10.f };
	const float onePartTransparency{ 1 / g_BubblePointsSize };
	const float onePartSize{ sizeOfBiggestBubble / g_BubblePointsSize };

	for (int i{}; i < g_BubblePointsSize; i++)
	{
		SetColor(0, 1, 0.5f, 1 - (i * onePartTransparency));
		FillEllipse(g_BubblePoints[i], sizeOfBiggestBubble - (i * onePartSize), sizeOfBiggestBubble - (i * onePartSize));
	}
}

void UpdateGrids()
{

}

void DrawGrid()
{
	const Color4f unclickedColor{0,1,0,1},
		clickedColor{.5f,0,.5f,1},
		borderColor{1,1,1,1};

	const float lineSize{1.5f};
	const int rows{3};
	const int columns{4};

	for (int i{}; i < g_Rows; i++)
	{
		for (int u{}; u < g_Columns; u++)
		{
			if (g_IsCellClicked[(i * g_Columns) + u])
			{
				SetColor(clickedColor);
			}
			else
			{
				SetColor(unclickedColor);
			}
			//std::cout << i * columns + u << std::endl;
			FillRect(g_PosOfGrid.x + (g_OneGridSize * u), g_PosOfGrid.y + (g_OneGridSize * i), g_OneGridSize, g_OneGridSize);

			SetColor(borderColor);
			DrawRect(g_PosOfGrid.x + (g_OneGridSize * u), g_PosOfGrid.y + (g_OneGridSize * i), g_OneGridSize, g_OneGridSize, lineSize);
		}
	}
}

void CheckCollision()
{
	for (int i{}; i < g_Rows; i++)
	{
		for (int u{}; u < g_Columns; u++)
		{
			Rectf cell{g_PosOfGrid.x + (g_OneGridSize * u), g_PosOfGrid.y + (g_OneGridSize * i), g_OneGridSize, g_OneGridSize};
			if (IsPointInRect(g_MousePos, cell))
			{
				g_IsCellClicked[i * g_Columns + u] = !g_IsCellClicked[i * g_Columns + u];
			}
		}
	}
}
#pragma endregion ownDefinitions