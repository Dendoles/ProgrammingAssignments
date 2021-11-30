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

	DrawLines();
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
	switch (key)
	{
		case SDLK_RIGHT:
			SwitchColor();
		break;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	g_MousePos.x = float(e.x);
	g_MousePos.y = float(g_WindowHeight - e.y);
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

void SwitchColor()
{
	if (g_Color == Color::blue)
	{
		g_Color = Color::green;
	}
	else if (g_Color == Color::green)
	{
		g_Color = Color::red;
	}
	else if (g_Color == Color::red)
	{
		g_Color = Color::blue;
	}
	else
	{
		g_Color = Color::blue;
	}
}

void DrawLines()
{
	float border{ 9 };

	SetColor(DrawColor());
	for (float i = 0; i < g_WindowHeight; i += border)
	{
		DrawLine(0, i, g_MousePos.x, g_MousePos.y);
		DrawLine(g_WindowWidth, i, g_MousePos.x, g_MousePos.y);
	}
	for (float i = 0; i < g_WindowWidth; i += border)
	{
		DrawLine(i, 0, g_MousePos.x, g_MousePos.y);
		DrawLine(i, g_WindowHeight, g_MousePos.x, g_MousePos.y);
	}
}

Color4f DrawColor()
{
	Color4f color{};

	if (g_Color == Color::blue)
	{
		color = Color4f(0, 0, 1, 1);
	}
	else if (g_Color == Color::green)
	{
		color = Color4f(0, 1, 0, 1);
	}
	else if (g_Color == Color::red)
	{
		color = Color4f(1, 0, 0, 1);
	}
	return color;
}

#pragma endregion ownDefinitions