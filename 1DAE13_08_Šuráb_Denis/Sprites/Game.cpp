#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	initKnight();
	// initialize game resources here
}

void Draw()
{
	ClearBackground();

	DrawKnight();
	// Put your own draw statements here

}

void Update(float elapsedSec)
{
	UpdateKnight(elapsedSec);
	MovementOfKnight(elapsedSec);
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
	DeleteTexture(g_KnightSprite.texture);
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

void initKnight()
{
	bool isCreationOk{};
	isCreationOk = TextureFromFile("Resources/RunningKnight.png", g_KnightSprite.texture);
	if (!isCreationOk)
	{
		std::cout << "Failed to load image RunningKnight.png\n";
	}
	g_KnightSprite.cols = 8;
	g_KnightSprite.frames = 8;
	g_KnightSprite.currentFrame = 0;
	g_KnightSprite.accumulatedTime = 0.0f;
	g_KnightSprite.frameTime = 1 / 10.0f;

}

void UpdateKnight(float elapsedTime)
{
	g_KnightSprite.accumulatedTime += elapsedTime;
	if (g_KnightSprite.accumulatedTime > g_KnightSprite.frameTime)
	{
		g_KnightSprite.currentFrame++;
		++g_KnightSprite.currentFrame %= g_KnightSprite.frames;
		g_KnightSprite.accumulatedTime -= g_KnightSprite.frameTime;
	}

}

void DrawKnight()
{
	Rectf srcRect{};
	srcRect.width = g_KnightSprite.texture.width / g_KnightSprite.cols;
	srcRect.height = g_KnightSprite.texture.height;
	srcRect.left = g_KnightSprite.currentFrame * srcRect.width;
	srcRect.bottom = srcRect.height;

	const float border{ 10.0f };

	Rectf destRect{};
	destRect.left = g_KnightPosition.x;
	destRect.bottom = g_WindowHeight - border - (g_KnightSprite.texture.height * g_Scale);
	destRect.width = srcRect.width * g_Scale;
	destRect.height = srcRect.height * g_Scale;

	DrawTexture(g_KnightSprite.texture, destRect,srcRect);
}

void MovementOfKnight(float elapsedTime)
{
	g_KnightPosition.x += g_KnightSpeed * elapsedTime;
	float width{ g_KnightSprite.texture.width / g_KnightSprite.cols * g_Scale };

	if (g_KnightPosition.x > g_WindowWidth)
	{
		g_KnightPosition.x = -width;
	}
}

#pragma endregion ownDefinitions