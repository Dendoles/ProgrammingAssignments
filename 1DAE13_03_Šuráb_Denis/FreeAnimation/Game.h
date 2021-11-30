#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "FreeAnimation - Šuráb, Denis - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 800 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_NrFrameRate{ 0 };
float g_speed1{ 0 };
float g_speed2{ 0 };
float g_speed3{ 0 };
float g_speed4{ 0 };
float g_speed5{ 0 };
float g_speed6{ 0 };
float g_speed7{ 0 };
float g_speed8{ 0 };
float g_speed9{ 0 };
float g_speed10{ 0 };
// Declare your own functions here

#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
