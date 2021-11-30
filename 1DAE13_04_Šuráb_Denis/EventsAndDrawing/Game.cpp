#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	GenerateRandomTransformationX(g_Border);
	GenerateRandomTransformationY(g_Border);
	GenerateRandomPositionX(g_Border);
	GenerateRandomPositionY(g_Border);
}

void Draw()
{
	ClearBackground();
	Color4f color{ 0.3f, 0.3f, 0.3f, 1 };

	if ((g_MousePos.x <= g_RectPos.x + g_RectWidth) && (g_MousePos.y <= g_RectPos.y + g_RectHeight) && (g_MousePos.x > g_RectPos.x) && (g_MousePos.y > g_RectPos.y) && (!isGreen))
	{
		color = Color4f{ 0, 1, 0, 1};
		isGreen = true;
	}
	else if ((g_MousePos.x <= g_RectPos.x + g_RectWidth) && (g_MousePos.y <= g_RectPos.y + g_RectHeight) && (g_MousePos.x > g_RectPos.x) && (g_MousePos.y > g_RectPos.y) && isGreen)
	{
		color = Color4f{ 0.3f, 0.3f, 0.3f, 1 };
		GenerateRandomTransformationX(g_Border);
		GenerateRandomTransformationY(g_Border);
		GenerateRandomPositionX(g_Border);
		GenerateRandomPositionY(g_Border);
		isGreen = false;
	}


	SetColor(color);
	if ((g_RectPos.x + g_RectWidth + g_Speed) > g_WindowWidth)
	{
		FillRect(g_RectPos.x + g_Speed, g_RectPos.y, g_RectWidth, g_RectHeight);
		FillRect(0, g_RectPos.y, g_RectWidth, g_RectHeight);
	}
	else 
	{
		FillRect(g_RectPos.x + g_Speed, g_RectPos.y, g_RectWidth, g_RectHeight);
	}

}

void Update(float elapsedSec)
{
	if (g_Behaviour == Behaviour::running)
	{
		++g_Speed;
		g_Speed = float(int(g_Speed) % int(g_WindowWidth));
	}
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
	switch (key)
	{
	case SDLK_r:
		if (g_Behaviour == Behaviour::stopped)
		{
			g_Behaviour = Behaviour::running;
		}
		else
		{
			g_Behaviour = Behaviour::stopped;
		}
		break;
	case SDLK_RIGHT:
		//std::cout << "Right arrow key released\n";
		break;
	case SDLK_1:
	case SDLK_KP_1:
		//std::cout << "Key 1 released\n";
		break;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		//std::cout << "Left mouse button released\n";
		g_MousePos.x = float(e.x);
		g_MousePos.y = float(g_WindowHeight - e.y);
		break;
	}
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void GenerateRandomTransformationX(float arg_Border)
{
	const float minRectWidth{60};
	g_RectWidth = float(rand() % int(g_WindowWidth - minRectWidth - (arg_Border * 2)) + minRectWidth);
}
void GenerateRandomTransformationY(float arg_Border)
{
	const float minRectHeight{ 40 };
	g_RectHeight = float(rand() % int(g_WindowHeight - minRectHeight - (arg_Border * 2)) + minRectHeight);
}
void GenerateRandomPositionX(float arg_Border)
{
	g_RectPos.x = float(rand() % int(g_WindowWidth - g_RectWidth - arg_Border) + arg_Border);
}
void GenerateRandomPositionY(float arg_Border)
{
	g_RectPos.y = float(rand() % int(g_WindowHeight - g_RectHeight - arg_Border) + arg_Border);
}


#pragma endregion ownDefinitions