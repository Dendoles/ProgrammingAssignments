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
	ClearBackground(0.3f,0.3f,0.3f);

	Ellipse();
	Crosier();

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

void Ellipse()
{
	const float numberOfPoints{ 10 };
	const float angle{ (2.f * g_Pi) / numberOfPoints };
	const float translationX{g_WindowWidth / 4.f};
	const float translationY{g_WindowHeight / 2.f};
	const float scaling{ 100.f };
	const float lineSize{ 1.5f };

	for (int i = 1; i <= numberOfPoints; i++)
	{
		float posX = translationX + scaling * cosf(angle * i);
		float posY = translationY + scaling * sinf(angle * i);
		float posX2 = translationX + scaling * cosf(angle * (i + 1)); // the one is there so i can already count next position so i can pass it for the DrawLine() function
		float posY2 = translationY + scaling * sinf(angle * (i + 1));

		SetColor(1, 0, 0);
		DrawLine(posX, posY, posX2, posY2, lineSize);
	}
}

void Crosier() 
{
	SetColor(0, 0, 1);
	const float numberOfWindings{ 8 };
	const float a{ g_WindowWidth / 4 };
	const float angleSteps{ 0.01f };
	const float translationX{ g_WindowWidth * 3.f / 4.f };
	const float translationY{ g_WindowHeight / 2.f };
	const float max{ numberOfWindings * 2.f * g_Pi + g_Pi / 2.f};

	for (float angle = (g_Pi / 2.f); angle < max; angle += angleSteps)
	{
		float scaling{ a / sqrtf(angle) };
		float posX1{ translationX + scaling * cosf(angle) };
		float posY1{ translationY + scaling * sinf(angle) };

		float posX2{ translationX + scaling * cosf(angle + angleSteps) };
		float posY2{ translationY + scaling * sinf(angle + angleSteps) };

		DrawLine(posX1, posY1, posX2, posY2);
	}
}

#pragma endregion ownDefinitions