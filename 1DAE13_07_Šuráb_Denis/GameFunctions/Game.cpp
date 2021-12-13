#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	InitializeSounds();
	g_Circle.center.x = float(rand() % int(g_WindowWidth - (g_Circle.radius * 2) + 1) + int(g_Circle.radius));
	g_Circle.center.y = float(rand() % int(g_WindowHeight - (g_Circle.radius * 2) + 1) + int(g_Circle.radius));
	g_Rectangle.left = float(rand() % int(g_WindowWidth - (g_Rectangle.width) + 1) + 0);
	g_Rectangle.bottom = float(rand() % int(g_WindowHeight - (g_Rectangle.height) + 1) + 0);

	// initialize game resources here
}

void Draw()
{
	ClearBackground();
	
	DrawRectAndCircle();
	DrawRandomRectangle();
	DrawRandomCircle();
	// Put your own draw statements here

}

void Update(float elapsedSec)
{
	//std::cout << "Mouse pos [" << g_MousePos.x << ", " << g_MousePos.y << "] \n";

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
	g_MousePos.x = float(e.x);
	g_MousePos.y = float(g_WindowHeight - e.y);
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

void DrawRandomCircle()
{
	SetColor(1, 1, 1);

	FillEllipse(g_Circle.center, g_Circle.radius, g_Circle.radius);


	if (IsPointInCircle(g_MousePos, g_Circle) == true)
	{
		SetColor(1, 0, 0);
		DrawEllipse(g_Circle.center, g_Circle.radius, g_Circle.radius, 20.f);
	}
}

void DrawRandomRectangle()
{
	SetColor(1, 1, 1);


	FillRect(g_Rectangle);

	if (IsPointInRect(g_MousePos, g_Rectangle) == true)
	{
		SetColor(1, 0, 0);
		DrawRect(g_Rectangle, 10);
	}
}

void DrawRectAndCircle()
{
	float rectWidth{ 100 };
	float circleRad{ 50 };
	Circlef mouseCircle{g_MousePos.x + circleRad, g_MousePos.y, circleRad};
	Rectf mouseRect{ g_MousePos.x - rectWidth, g_MousePos.y, rectWidth , rectWidth / 2.f };


	if (isOverlapping(g_Circle, mouseCircle))
	{
		SetColor(1, 0, 0, 0.3f);
	}
	else
	{
		SetColor(0, 1, 0, 0.3f);
	}
	FillEllipse(mouseCircle.center, mouseCircle.radius, mouseCircle.radius);
	
	if (isOverlapping(mouseRect, g_Rectangle))
	{
		SetColor(1, 0, 0, 0.3f);
	}
	else
	{
		SetColor(0, 1, 0, 0.3f);
	}
	FillRect(mouseRect);
}

void InitializeSounds()
{
	//Sounds/Shoot.wav
	const char* path{"Sounds/bc_music.mp3"};
	const char* path2{ "Sounds/bc_music.mp3" };
	const char* path3{"Sounds/ihopeyoushatyourself.wav"};
	SDL_Init(SDL_INIT_AUDIO);
	
	int audioHertz{22050}; //default is 22050
	Uint16 audioFormat{AUDIO_S16SYS};
	int audioChannel{2};
	int audioBuffer{4096};

	if (Mix_OpenAudio(audioHertz, audioFormat, audioChannel, audioBuffer) != 0)
	{
		std::cout << "Rip audio\n";
	}
	g_pTmpChunk = Mix_LoadWAV(path3);

	if (g_pTmpChunk == nullptr)
	{
		std::cout << "pTmpChunk was a nullprt\n";
	}

	Mix_Volume(-1,MIX_MAX_VOLUME/10);
	Mix_PlayChannel(-1, g_pTmpChunk, 0);
	//Mix_PlayMusic()
	std::cout << "Played sound\n";
	//TODO: add SDL_Quit(); at the end function
}


#pragma endregion ownDefinitions