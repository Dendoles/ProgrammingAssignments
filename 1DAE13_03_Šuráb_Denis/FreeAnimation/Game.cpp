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
	ClearBackground(0.1f,0.1f,0.1f);

	const float widthOfOneTab{ g_WindowWidth / 10.f };
	const float heightOfOneTab{ g_WindowHeight / 10.f };
	const float framesFor1{ 10.f };
	const float framesFor2{ 9.f };
	const float framesFor3{ 8.f };
	const float framesFor4{ 7.f };
	const float framesFor5{ 6.f };
	const float framesFor6{ 6.f };
	const float framesFor7{ 7.f };
	const float framesFor8{ 8.f };
	const float framesFor9{ 9.f };
	const float framesFor10{ 10.f };
	float f1{ float(int(g_NrFrameRate) % int(framesFor1)+ 1) / framesFor1};
	float f2{ float(int(g_NrFrameRate) % int(framesFor2) + 1) / framesFor2 };
	float f3{ float(int(g_NrFrameRate) % int(framesFor3) + 1) / framesFor3 };
	float f4{ float(int(g_NrFrameRate) % int(framesFor4) + 1) / framesFor4 };
	float f5{ float(int(g_NrFrameRate) % int(framesFor5) + 1) / framesFor5 };
	float f6{ float(int(g_NrFrameRate) % int(framesFor6) + 1) / framesFor6 };
	float f7{ float(int(g_NrFrameRate) % int(framesFor7) + 1) / framesFor7 };
	float f8{ float(int(g_NrFrameRate) % int(framesFor8) + 1) / framesFor8 };
	float f9{ float(int(g_NrFrameRate) % int(framesFor9) + 1) / framesFor9 };
	float f10{ float(int(g_NrFrameRate) % int(framesFor10) + 1) / framesFor10 };

	Color4f randomColor{ rand() % (256) / 255.f, rand() % (256) / 255.f, rand() % (256) / 255.f, 1.f };

	g_speed1 += f1;
	g_speed2 += f2;
	g_speed3 += f3;
	g_speed4 += f4;
	g_speed5 += f5;
	g_speed6 += f6;
	g_speed7 += f7;
	g_speed8 += f8;
	g_speed9 += f9;
	g_speed10 += f10;

	SetColor(randomColor);
	FillRect(0, g_speed1, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(widthOfOneTab, g_speed2, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(widthOfOneTab * 2.f, g_speed3, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(widthOfOneTab * 3.f, g_speed4, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(widthOfOneTab * 4.f, g_speed5, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(widthOfOneTab * 5.f, g_speed6, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(widthOfOneTab * 6.f, g_speed7, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(widthOfOneTab * 7.f, g_speed8, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(widthOfOneTab * 8.f, g_speed9, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(widthOfOneTab * 9.f, g_speed10, widthOfOneTab, heightOfOneTab);

	SetColor(randomColor);
	FillRect(0, (g_WindowHeight - widthOfOneTab) - g_speed1, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(widthOfOneTab, (g_WindowHeight - widthOfOneTab) - g_speed2, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(widthOfOneTab * 2.f, (g_WindowHeight - widthOfOneTab) - g_speed3, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(widthOfOneTab * 3.f, (g_WindowHeight - widthOfOneTab) - g_speed4, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(widthOfOneTab * 4.f, (g_WindowHeight - widthOfOneTab) - g_speed5, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(widthOfOneTab * 5.f, (g_WindowHeight - widthOfOneTab) - g_speed6, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(widthOfOneTab * 6.f, (g_WindowHeight - widthOfOneTab) - g_speed7, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(widthOfOneTab * 7.f, (g_WindowHeight - widthOfOneTab) - g_speed8, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(widthOfOneTab * 8.f, (g_WindowHeight - widthOfOneTab) - g_speed9, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(widthOfOneTab * 9.f, (g_WindowHeight - widthOfOneTab) - g_speed10, widthOfOneTab, heightOfOneTab);

	SetColor(randomColor);
	FillRect((g_WindowWidth - widthOfOneTab) - g_speed1, 0, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect((g_WindowWidth - widthOfOneTab) - g_speed2, heightOfOneTab, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect((g_WindowWidth - widthOfOneTab) - g_speed3, heightOfOneTab * 2.f, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect((g_WindowWidth - widthOfOneTab) - g_speed4, heightOfOneTab * 3.f, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect((g_WindowWidth - widthOfOneTab) - g_speed5, heightOfOneTab * 4.f, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect((g_WindowWidth - widthOfOneTab) - g_speed6, heightOfOneTab * 5.f, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect((g_WindowWidth - widthOfOneTab) - g_speed7, heightOfOneTab * 6.f, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect((g_WindowWidth - widthOfOneTab) - g_speed8, heightOfOneTab * 7.f, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect((g_WindowWidth - widthOfOneTab) - g_speed9, heightOfOneTab * 8.f, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect((g_WindowWidth - widthOfOneTab) - g_speed10, heightOfOneTab * 9.f, widthOfOneTab, heightOfOneTab);

	SetColor(randomColor);
	FillRect(g_speed1, 0, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(g_speed2, heightOfOneTab, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(g_speed3, heightOfOneTab * 2.f, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(g_speed4, heightOfOneTab * 3.f, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(g_speed5, heightOfOneTab * 4.f, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(g_speed6, heightOfOneTab * 5.f, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(g_speed7, heightOfOneTab * 6.f, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(g_speed8, heightOfOneTab * 7.f, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(g_speed9, heightOfOneTab * 8.f, widthOfOneTab, heightOfOneTab);
	SetColor(randomColor);
	FillRect(g_speed10, heightOfOneTab * 9.f, widthOfOneTab, heightOfOneTab);
	
}

void Update(float elapsedSec)
{
	++g_NrFrameRate;




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

#pragma endregion ownDefinitions