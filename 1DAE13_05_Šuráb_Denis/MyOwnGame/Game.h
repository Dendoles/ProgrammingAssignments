#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Šuráb, Denis - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 600 };
float g_WindowHeight{ 800 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_Size{ 10 };
Point2f g_Power{1,1};
float g_Acceleration{ 0.2f };
//float g_Speed{};
Point2f g_Length{};
Point2f g_Pos{ g_WindowWidth / 2.f, g_WindowHeight / 4.f };
Point2f g_HolePos{g_WindowWidth / 2.f, g_WindowHeight * 3.f / 4.f };
float g_HoleSize{g_Size * 2.f};
Point2f g_MousePos{};
bool g_IsHovering{ false };
bool g_IsClicked{ false };
bool g_IsMoving{false};

// Declare your own functions here

void CalculateLength();
void CheckHovering();
void CheckBorderCollision();
void CalculatePower();

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
