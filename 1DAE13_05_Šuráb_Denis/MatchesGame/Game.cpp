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

	DrawMainMatches();
	DrawPlayerMatches();
	DrawPCMatches();
	// Put your own draw statements here

}

void Update(float elapsedSec)
{
	if (g_IsPlayerTurn == false)
	{
		PcHandling();
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
	case SDLK_2:
	case SDLK_KP_2:
		g_DrawnNumber = 2;
		if (g_IsPlayerTurn)
		{
			PlayerHandling();
		}
		break;
	case SDLK_1:
	case SDLK_KP_1:
		g_DrawnNumber = 1;
		if (g_IsPlayerTurn)
		{
			PlayerHandling();
		}
		break;
	case SDLK_3:
	case SDLK_KP_3:
		g_DrawnNumber = 3;
		if (g_IsPlayerTurn)
		{
			PlayerHandling();
		}
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

void DrawMainMatches()
{
	float matchHeight{ 50 };
	float matchWidth{ 7 };
	float spacing{ matchWidth * 2 + 5};
	float yPos{ g_WindowHeight - g_Border - matchHeight };

	float woodHeight{ matchHeight * 3.f / 4.f };
	float sulfurSideHeight{ matchHeight / 4.f };

	for (int i = 0; i < g_NumberOfMatches; i++)
	{
		SetColor(0, 1, 1);
		FillRect(g_Border + (i * spacing), yPos, matchWidth, woodHeight);
		SetColor(1, 0, 0);
		FillRect(g_Border + (i * spacing), yPos + woodHeight, matchWidth, sulfurSideHeight);
	}
}

void DrawPlayerMatches()
{
	float matchHeight{ 50 };
	float matchWidth{ 7 };
	float spacing{ matchWidth * 2 + 5 };
	float yPos{ g_Border };

	float woodHeight{ matchHeight * 3.f / 4.f };
	float sulfurSideHeight{ matchHeight / 4.f };

	for (int i = 0; i < g_PlayerMatches; i++)
	{
		SetColor(0, 1, 1);
		FillRect(g_Border + (i * spacing), yPos, matchWidth, woodHeight);
		SetColor(1, 0, 0);
		FillRect(g_Border + (i * spacing), yPos + woodHeight, matchWidth, sulfurSideHeight);
	}
}
void DrawPCMatches()
{
	float matchHeight{ 50 };
	float matchWidth{ 7 };
	float spacing{ matchWidth * 2 + 5 };
	float yPos{ g_Border };
	float xPos{ g_Border + (g_WindowWidth / 2.f) };

	float woodHeight{ matchHeight * 3.f / 4.f };
	float sulfurSideHeight{ matchHeight / 4.f };

	for (int i = 0; i < g_ComputerMatches; i++)
	{
		SetColor(0, 1, 1);
		FillRect(xPos + (i * spacing), yPos, matchWidth, woodHeight);
		SetColor(1, 0, 0);
		FillRect(xPos + (i * spacing), yPos + woodHeight, matchWidth, sulfurSideHeight);
	}
}

void PlayerHandling()
{
	g_NumberOfMatches -= g_DrawnNumber;
	g_PlayerMatches += g_DrawnNumber;
	g_PlayerMoves += std::to_string(g_DrawnNumber);
	g_PlayerMoves += "  ";
	if (g_NumberOfMatches == 0)
	{
		GameEnd();
	}
	g_IsPlayerTurn = false;
}

void PcHandling()
{
	int number{};
	do
	{
		number = rand() % 3 + 1;
	} while (number > g_NumberOfMatches);

	g_NumberOfMatches -= number;
	g_ComputerMatches += number;
	g_PcMoves += std::to_string(number);
	g_PcMoves += "  ";
	if (g_NumberOfMatches == 0)
	{
		GameEnd();
	}
	g_IsPlayerTurn = true;
}

void GameEnd()
{
	std::cout << "PC moves: " << g_PcMoves << std::endl;
	std::cout << "Your moves: " << g_PlayerMoves << std::endl;

	if (g_IsPlayerTurn)
	{
		std::cout << "Congrats you LOST!";
	}
	else 
	{
		std::cout << "Congrats you WON!";
	}
}

#pragma endregion ownDefinitions