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

	SetColor(0.5f,0.3f, 0.8f);
	DrawBall();
	DrawFreeFall();
	// Put your own draw statements here

}

void Update(float elapsedSec)
{
	UpdateInfo(elapsedSec);
	UpdateBall(elapsedSec);
	UpdateFreeFall(elapsedSec);
	//int time = (int(g_AccumulatedTime) % int(g_Frames / g_Framerate));

	//std::cout << time << "\n";

	/*if (time == 1)
	{
		UpdateBall(elapsedSec);
	}*/
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
	case SDLK_s:
		g_IsFalling = true;
		std::cout << "s\n";
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

void DrawBall()
{
	SetColor(1, 0.5f, 0);
	FillEllipse(g_Ball);
}

void UpdateBall(float elapsedSec)
{
		g_Ball.center.x += g_HorizontalSpeedForBall * elapsedSec;
		g_Ball.center.y += g_VerticalSpeedForBall * elapsedSec;
		//std::cout << g_HVelocity << "         " << g_VVelocity << std::endl;
		float ballHorizontalLineR{g_Ball.center.x + g_Ball.radiusX};
		float ballHorizontalLineL{ g_Ball.center.x - g_Ball.radiusX };

		float ballVerticalLineU{ g_Ball.center.y + g_Ball.radiusY };
		float ballVerticalLineD{ g_Ball.center.y - g_Ball.radiusY };


		if (ballHorizontalLineR >= g_WindowWidth || ballHorizontalLineL <= 0)
		{
			g_HorizontalSpeedForBall = -g_HorizontalSpeedForBall;
		}
		if (ballVerticalLineU >= g_WindowHeight || ballVerticalLineD <= 0)
		{
			g_VerticalSpeedForBall = -g_VerticalSpeedForBall;
		}
}

void UpdateInfo(float elapsedTime)
{
	int amountOfFrames{ 100 };
	g_Frames++;
	g_AccumulatedTime += elapsedTime;
	g_Framerate = g_Frames / g_AccumulatedTime;

	if (g_Frames % amountOfFrames == 0)
	{
		std::cout << "Number of Frames: " << g_Frames;
		std::cout << "		AccumulatedTime: " << g_AccumulatedTime;
		std::cout << "		 Framerate: " << g_Framerate << "\n";
	}
}

void UpdateFreeFall(float elapsedTime)
{
	if (g_IsFalling)
	{
		g_VerticalVelocityForObject += elapsedTime * g_GravityAcceleration;
		g_Rectangle.bottom += g_VerticalVelocityForObject * elapsedTime;

		if (g_Rectangle.bottom + g_Rectangle.height < 0)
		{
			g_VerticalVelocityForObject = 0;
			g_Rectangle.bottom = g_WindowHeight - g_Rectangle.height;
			g_IsFalling = false;
		}
	}
}

void DrawFreeFall()
{
	SetColor(1, 1, 0);
	FillRect(g_Rectangle);
}
#pragma endregion ownDefinitions