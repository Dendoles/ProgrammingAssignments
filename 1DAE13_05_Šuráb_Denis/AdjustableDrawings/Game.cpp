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

	ConcentricSquares();
	Stairs();
	EpicShape();
	Spiral();
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
	case SDLK_UP:
		AddingLoops();
		break;
	case SDLK_DOWN:
		SubtractingLoops();
		break;
	}
	std::cout << g_NumberOfLoops << std::endl;
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

void ConcentricSquares()
{
	const float centerX{ g_WindowWidth / 4.f };
	const float centerY{ g_WindowHeight / 4.f };
	const float numberOfSquares{ g_NumberOfLoops };
	const float boundary{ centerX - (2.f * g_Border) };
	const float spaceBetweenSquares{ boundary / numberOfSquares };
	int i{ 1 };

	SetColor(0, 1, 0);
	for (float m = 0; m < boundary; m += spaceBetweenSquares)
	{
		DrawRect(centerX - (spaceBetweenSquares * i), centerY - (spaceBetweenSquares * i), spaceBetweenSquares * (2 * i), spaceBetweenSquares * (2 * i));
		i++;
	}

}
void Spiral()
{
	const float numberOfLines{ g_NumberOfLoops };
	const float center{ g_WindowWidth * 3.f / 4.f };
	const float posX{ g_WindowWidth / 2.f + g_Border };
	const float posY{ g_Border };
	const float boundary{ center - g_WindowWidth / 2.f - g_Border };
	const float spaceBetweenLoops{ boundary / numberOfLines };
	const float sizeOfBoundary{ g_WindowWidth / 2.f - (2.f * g_Border) };
	int i{ 0 };


	SetColor(0, 0, 1);
	for (float m = spaceBetweenLoops; m <= boundary; m += spaceBetweenLoops)
	{
		DrawLine(posX + (i * spaceBetweenLoops), posY + (i * spaceBetweenLoops), posX + sizeOfBoundary - (i * spaceBetweenLoops), posY + (i * spaceBetweenLoops));
		DrawLine(posX + sizeOfBoundary - (i * spaceBetweenLoops), posY + (i * spaceBetweenLoops), posX + sizeOfBoundary - (i * spaceBetweenLoops), posY + sizeOfBoundary - (i * spaceBetweenLoops));
		DrawLine(posX + sizeOfBoundary - (i * spaceBetweenLoops), posY + sizeOfBoundary - (i * spaceBetweenLoops), posX + spaceBetweenLoops + (i * spaceBetweenLoops), posY + sizeOfBoundary - (i * spaceBetweenLoops));
		if (m != boundary)
		{
			DrawLine(posX + spaceBetweenLoops + (i * spaceBetweenLoops), posY + sizeOfBoundary - (i * spaceBetweenLoops), posX + spaceBetweenLoops + (i * spaceBetweenLoops), posY + spaceBetweenLoops + (i * spaceBetweenLoops));
		}
		i++;
	}
}

void Stairs()
{
	int checker{ 0 };
	const float numberOfSteps{ g_NumberOfLoops };
	const float centerY{ g_WindowHeight / 2.f + g_Border };
	const float boundary{ g_WindowWidth / 4.f - (2.f * g_Border) };
	const float sizeOfOneStep{ boundary / numberOfSteps };
	const float lengthOfOneStep{ sizeOfOneStep * 2.f }; // this is for the actual size of 1 line couse i devide boundary by 5 but there are 10 lines so need to be *2

	Color4f firstColor{ 1,0,0,1 };
	Color4f secondColor{ 0,0,1,1 };

	for (float m = 0; m < boundary; m += sizeOfOneStep)
	{
		if ((checker + 1) % 2 != 0)
		{
			SetColor(firstColor);
		}
		else
		{
			SetColor(secondColor);
		}
		int iterations{ checker + 1 };

		DrawLine(g_Border + (checker * lengthOfOneStep), centerY + (lengthOfOneStep * checker), g_Border + (iterations * lengthOfOneStep), centerY + (lengthOfOneStep * checker));
		DrawLine(g_Border + (iterations * lengthOfOneStep), centerY + (lengthOfOneStep * checker), g_Border + iterations * lengthOfOneStep, centerY + (lengthOfOneStep * iterations));

		checker++;
	}
}


void EpicShape()
{
	const float numberOfLines{ g_NumberOfLoops };
	const float centerX{ g_WindowWidth / 2.f + g_Border };
	const float centerY{ g_WindowHeight / 2.f + g_Border };
	const float sizeOfOneSide{ g_WindowWidth / 2.f - (2.f * g_Border) };
	const float onePartition{ sizeOfOneSide / numberOfLines };
	const float lengthY{ sizeOfOneSide + centerY - g_Border };
	const float lengthX{ sizeOfOneSide + centerX - g_Border };
	Color4f firstColor{ 1,0,0,1 }; //red
	Color4f secondColor{ 0,0,1,1 }; //blue
	Color4f thirdColor{ 0,1,0,1 }; //green
	Color4f fourthColor{ 1,1,0,1 }; // yellow
	int iterations{ 0 };

	for (float m = 0; m < sizeOfOneSide; m += onePartition)
	{
		SetColor(fourthColor);
		DrawLine(centerX + (iterations * onePartition), centerY, centerX, lengthY - (iterations * onePartition));
		SetColor(secondColor);
		DrawLine(centerX, lengthY - (iterations * onePartition), lengthX - (iterations * onePartition), lengthY);
		SetColor(firstColor);
		DrawLine(centerX + (iterations * onePartition), centerY, lengthX, centerY + (iterations * onePartition));
		SetColor(thirdColor);
		DrawLine(lengthX, centerY + (iterations * onePartition), lengthX - (iterations * onePartition), lengthY);

		iterations++;
	}
}

void AddingLoops()
{
	float maxAmount{20};

	if (g_NumberOfLoops != maxAmount)
	{
		g_NumberOfLoops++;
	}
}

void SubtractingLoops()
{
	float minAmount{ 5 };

	if (g_NumberOfLoops != minAmount)
	{
		g_NumberOfLoops--;
	}
}

#pragma endregion ownDefinitions