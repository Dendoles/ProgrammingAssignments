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
	SetColor(1, 1, 1);
	FillEllipse(g_Pos.x * g_Power.x, g_Pos.y * g_Power.y, g_Size, g_Size); // Player

	//TODO: change color according to "power"
	SetColor(1, 0, 0);
	if (g_IsClicked)
	{
		DrawLine(g_Pos.x * g_Power.x, g_Pos.y * g_Power.y, g_MousePos.x, g_MousePos.y, 5.f);
	}



	SetColor(0.11f, 0.12f, 0.17f);
	FillEllipse(g_HolePos.x, g_HolePos.y, g_HoleSize, g_HoleSize);
	SetColor(0, 0, 0);
	DrawEllipse(g_HolePos.x, g_HolePos.y, g_HoleSize, g_HoleSize, 2.f);

}

void Update(float elapsedSec)
{
	CheckHovering();

	g_Pos.x += g_Length.x;
	g_Pos.y += g_Length.y;

	if (g_Length.x != 0 ||
		g_Length.y != 0)
	{
		g_IsMoving = true;
	}

	if (g_IsMoving)
	{
		CheckBorderCollision();
		if (g_Power.x > 1)
		{
			g_Power.x -= g_Acceleration;
		}
		else
		{
			g_Power.x = 1;
		}
		if (g_Power.y > 1)
		{
			g_Power.y -= g_Acceleration;
		}
		else
		{
			g_Power.y = 1;
		}
	}

	if (!g_IsMoving)
	{
		CalculatePower();
	}
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
	//TODO add r for restaring the level

	switch (key)
	{
	case SDLK_r:
		g_Pos = Point2f(g_WindowWidth / 2.f, g_WindowHeight / 4.f);
		g_Length = Point2f(0,0);
		g_Power = Point2f(0, 0);
		break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	g_MousePos.x = float( e.x );
	g_MousePos.y = float(g_WindowHeight - e.y);
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	if (g_IsClicked)
	{
		g_IsClicked = false;
		CalculateLength();
	}
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		if (g_IsHovering)
		{
			g_IsClicked = true;
		}
		break;
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

void CalculateLength()
{
	float x = g_Pos.x - g_MousePos.x;
	float y = g_Pos.y - g_MousePos.y;
	float distance = { sqrtf(powf(x,2) + powf(y, 2)) };

	 g_Length.x = distance * x;
	 g_Length.y = distance * y;

	//std::cout << x << ", " << y << std::endl;
	//std::cout << g_Length.x << ", " << g_Length.y << std::endl;
}

void CheckHovering()
{
	float halfSize{ g_Size / 2.f };

	if ((g_MousePos.x >= g_Pos.x - halfSize &&
		g_MousePos.y >= g_Pos.y - halfSize) &&
		(g_MousePos.x <= g_Pos.x + halfSize &&
			g_MousePos.y <= g_Pos.y + halfSize))
	{
		g_IsHovering = true;
	}
	else
	{
		g_IsHovering = false;
	}
}

void CheckBorderCollision()
{
	float halfSize{ g_Size / 2.f };
	if ((g_Pos.x + halfSize) >= g_WindowWidth ||
		(g_Pos.x - halfSize) <= 0)
	{
		g_Length.x = -g_Length.x;
	}

	if((g_Pos.y + halfSize) >= g_WindowHeight ||
		(g_Pos.y - halfSize) <= 0)
	{
		g_Length.y = -g_Length.y;
	}
}

void CalculatePower()
{
	float smallStrength{ g_WindowWidth / 10.f };
	float mediumStrength{ g_WindowWidth / 5.f };
	//float highStrength{ g_WindowWidth / 3.f};
	float lowSpeed{ 0.2f };
	float mediumSpeed{ 0.5f };
	float highSpeed{ 1 };

	if (g_Length.x > 0 && g_Length.x <= smallStrength)
	{
		g_Power.x = lowSpeed * g_Length.x;
	}
	else if (g_Length.x > smallStrength && g_Length.x <= mediumStrength)
	{
		g_Power.x = mediumSpeed * g_Length.x;
	}
	else if (g_Length.x > mediumStrength)
	{
		g_Power.x = highSpeed * g_Length.x;
	}


	if (g_Length.y > 0 && g_Length.y <= smallStrength)
	{
		g_Power.y = lowSpeed * g_Length.y;
	}
	else if (g_Length.y > smallStrength && g_Length.y <= mediumStrength)
	{
		g_Power.y = mediumSpeed * g_Length.y;
	}
	else if (g_Length.y > mediumStrength)
	{
		g_Power.y = highSpeed * g_Length.y;
	}
}

#pragma endregion ownDefinitions