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
	ClearBackground(0.3f,0.3f,0.3f);
	DrawExplosion();

	// Put your own draw statements here

}

void Update(float elapsedSec)
{
	ControllingExplosionFlow();
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
	//	isClicked = true;
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
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		ProcessMouseClick(float(e.x), float(e.y));
		break;
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void ProcessMouseClick(float arg_X, float arg_Y)
{
	if ((arg_X >= ((g_WindowWidth / 2) - (g_RectSize / 2))) &&
		(arg_X < ((g_WindowWidth / 2) + (g_RectSize / 2))) &&
		(arg_Y >= ((g_WindowWidth / 2) - (g_RectSize / 2))) &&
		(arg_Y < ((g_WindowWidth / 2) + (g_RectSize / 2))))
	{
		isClicked = true;
	}
	else
	{
		//isClicked = false;
	}
}
void DrawExplosion()
{
	float rectPos{ g_WindowWidth / 2 };
	float halfOfRectSize{ g_RectSize / 2 };
	float transparencyOfBomb{ 1 };
	float transparencyOfRed{ 0 };

	if (isClicked)
	{
		transparencyOfBomb = 0.5f;
		transparencyOfRed = 1;
	}
	if (!isClicked)
	{
		transparencyOfBomb = 1;
		transparencyOfRed = 0;
	}

	SetColor(0, 0, 0, transparencyOfBomb);
	FillRect(rectPos - halfOfRectSize, rectPos - halfOfRectSize, g_RectSize, g_RectSize);


	SetColor(1, 0, 0, transparencyOfRed);
	FillRect(rectPos - halfOfRectSize + g_Movement, rectPos - halfOfRectSize + g_Movement, g_RectSize, g_RectSize);
	FillRect(rectPos - halfOfRectSize + g_Movement, rectPos - halfOfRectSize - g_Movement, g_RectSize, g_RectSize);
	FillRect(rectPos - halfOfRectSize - g_Movement, rectPos - halfOfRectSize - g_Movement, g_RectSize, g_RectSize);
	FillRect(rectPos - halfOfRectSize - g_Movement, rectPos - halfOfRectSize + g_Movement, g_RectSize, g_RectSize);
}
void ControllingExplosionFlow()
{
	if (isClicked)
	{
		if (g_Movement < (g_WindowHeight / 2))
		{
			++g_Movement;
			g_Movement = float(int(g_Movement) % int(g_WindowHeight / 2)) + 1;
		}
		else if (g_Movement >= (g_WindowHeight / 2))
		{
			isClicked = false;
		}
	}
	else
	{
		g_Movement = 0;
	}
}

#pragma endregion ownDefinitions