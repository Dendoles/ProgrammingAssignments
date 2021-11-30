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
	ClearBackground(0, 0, 0.298f);
	Color4f purplishColor{ 0.8f, 0.6f, 1, 1 };
	Color4f redishColor{1, 0.4f, 0.4f, 1};

	OneDiceTracking();
	TwoDiceTracking();

	DrawRedDiceGraphs(redishColor);
	DrawPurpleDiceGraphs(purplishColor);

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

void OneDiceTracking()
{
	int roll{ rand() % 6 + 1 };

	switch (roll)
	{
		case 1:
			++g_DiceValue1;
			break;
		case 2:
			++g_DiceValue2;
			break;
		case 3:
			++g_DiceValue3;
			break;
		case 4:
			++g_DiceValue4;
			break;
		case 5:
			++g_DiceValue5;
			break;
		case 6:
			++g_DiceValue6;
			break;
		default:
			std::cout << roll << std::endl;
			break;
	}
}
void DrawRedDiceGraphs(Color4f colorOfStatistics)
{
	SetColor(colorOfStatistics);
	FillRect(g_Border, g_Border, g_DiceValue1, g_RectHeight);
	FillRect(g_Border, (2 * g_Border) + g_RectHeight, g_DiceValue2, g_RectHeight);
	FillRect(g_Border, (3 * g_Border) + (2 * g_RectHeight), g_DiceValue3, g_RectHeight);
	FillRect(g_Border, (4 * g_Border) + (3 * g_RectHeight), g_DiceValue4, g_RectHeight);
	FillRect(g_Border, (5 * g_Border) + (4 * g_RectHeight), g_DiceValue5, g_RectHeight);
	FillRect(g_Border, (6 * g_Border) + (5 * g_RectHeight), g_DiceValue6, g_RectHeight);
}

void TwoDiceTracking()
{
	int firstDiceRoll{ rand() % 6 + 1};
	int secondDiceRoll{ rand() % 6 + 1 };
	int resultingValue{ firstDiceRoll + secondDiceRoll };

	switch (resultingValue)
	{
		case 2:
			++g_TwoDiceValue2;
			break;
		case 3:
			++g_TwoDiceValue3;
			break;
		case 4:
			++g_TwoDiceValue4;
			break;
		case 5:
			++g_TwoDiceValue5;
			break;
		case 6:
			++g_TwoDiceValue6;
			break;
		case 7:
			++g_TwoDiceValue7;
			break;
		case 8:
			++g_TwoDiceValue8;
			break;
		case 9:
			++g_TwoDiceValue9;
			break;
		case 10:
			++g_TwoDiceValue10;
			break;
		case 11:
			++g_TwoDiceValue11;
			break;
		case 12:
			++g_TwoDiceValue12;
			break;
		default:
			std::cout << resultingValue << std::endl;
			break;
	}
}

void DrawPurpleDiceGraphs(Color4f colorOfStatistics)
{
	SetColor(colorOfStatistics);
	FillRect(g_Border, (7 * g_Border) + (6 * g_RectHeight), g_TwoDiceValue12, g_RectHeight);
	FillRect(g_Border, (8 * g_Border) + (7 * g_RectHeight), g_TwoDiceValue11, g_RectHeight);
	FillRect(g_Border, (9 * g_Border) + (8 * g_RectHeight), g_TwoDiceValue10, g_RectHeight);
	FillRect(g_Border, (10 * g_Border) + (9 * g_RectHeight), g_TwoDiceValue9, g_RectHeight);
	FillRect(g_Border, (11 * g_Border) + (10 * g_RectHeight), g_TwoDiceValue8, g_RectHeight);
	FillRect(g_Border, (12 * g_Border) + (11 * g_RectHeight), g_TwoDiceValue7, g_RectHeight);
	FillRect(g_Border, (13 * g_Border) + (12 * g_RectHeight), g_TwoDiceValue6, g_RectHeight);
	FillRect(g_Border, (14 * g_Border) + (13 * g_RectHeight), g_TwoDiceValue5, g_RectHeight);
	FillRect(g_Border, (15 * g_Border) + (14 * g_RectHeight), g_TwoDiceValue4, g_RectHeight);
	FillRect(g_Border, (16 * g_Border) + (15 * g_RectHeight), g_TwoDiceValue3, g_RectHeight);
	FillRect(g_Border, (17 * g_Border) + (16 * g_RectHeight), g_TwoDiceValue2, g_RectHeight);

}

#pragma endregion ownDefinitions