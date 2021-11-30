#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "FrameTime - Šuráb, Denis - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_Framerate{};
int g_Frames{};
float g_AccumulatedTime{};
Ellipsef g_Ball{ g_WindowWidth / 2.f, g_WindowHeight / 2.f, 20,20};
float g_VerticalSpeedForBall{80.f};
float g_HorizontalSpeedForBall{100.f};
float g_GravityAcceleration{ -9.81f };
float g_VerticalVelocityForObject{};
Rectf g_Rectangle{g_WindowWidth / 2.f ,g_WindowHeight - 50, 50, 50};
bool g_IsFalling{false};

// Declare your own functions here

void DrawFreeFall();
void DrawBall();
void UpdateInfo(float elapsedTime);
void UpdateBall(float elapsedSec);
void UpdateFreeFall(float elapsedTime);

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
