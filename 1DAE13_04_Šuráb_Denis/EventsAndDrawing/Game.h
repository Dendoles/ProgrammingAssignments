#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "EventsAndDrawing - Šuráb, Denis - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_RectWidth{};
float g_RectHeight{};
Point2f g_RectPos{};
Point2f g_MousePos{};
float g_Border{ 50 };
bool isGreen{ false };
float g_Speed{};
float g_Offset{};
enum class Behaviour {
	running, stopped
};
Behaviour g_Behaviour{Behaviour::stopped};
// Declare your own functions here
void GenerateRandomTransformationX(float arg_Border);
void GenerateRandomTransformationY(float arg_Border);
void GenerateRandomPositionX(float arg_Border);
void GenerateRandomPositionY(float arg_Border);

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
