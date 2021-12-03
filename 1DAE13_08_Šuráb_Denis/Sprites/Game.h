#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Sprites - Šuráb, Denis - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

Sprite g_KnightSprite{};
Point2f g_KnightPosition{};
const float g_Scale{ 5.0f };
float g_KnightSpeed{100};

// Declare your own functions here

void initKnight();
void UpdateKnight(float elapsedTime);
void DrawKnight();
void MovementOfKnight(float elapsedTime);

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
