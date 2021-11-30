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
	int numberOfRectangles{100};
	while (numberOfRectangles >= 0)
	{
		RandomPositionAndSizeGenerator();
		RandomColorGenerator();
		DrawRandomRect();
		Sleep(1);
		--numberOfRectangles;
	}
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
void DrawRandomRect()
{
	const Color4f outlineColor{0,0,0,1};
	const float lineSize{1};


	SetColor(g_RectColor);
	FillRect(g_RectPos, g_RectWidth, g_RectHeight);

	SetColor(outlineColor);
	DrawRect(g_RectPos, g_RectWidth, g_RectHeight, lineSize);
}
void RandomPositionAndSizeGenerator()
{
	const float border{ 10 };
	const float minHeight{ 10 };
	const float minWidth{ 10 };

	g_RectPos.x = float(rand() % int(g_WindowWidth - 2 * border - minWidth + 1) + border);
	g_RectPos.y = float(rand() % int(g_WindowHeight - 2 * border - minHeight + 1) + border);

	g_RectWidth = float(rand() % int(g_WindowWidth - g_RectPos.x - border - minWidth + 1) + int(minWidth));
	g_RectHeight = float(rand() % int(g_WindowHeight - g_RectPos.y - border - minHeight + 1) + int(minHeight));
}
void RandomColorGenerator()
{
	g_RectColor.r =  (rand() % 256) / 255.f;
	g_RectColor.g = (rand() % 256) / 255.f;
	g_RectColor.b = (rand() % 256) / 255.f;
}
#pragma endregion ownDefinitions