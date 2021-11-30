#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "MatchesGame - Šuráb, Denis - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 600 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

float g_Border{ 20 };
int g_NumberOfMatches{ 21 };
int g_PlayerMatches{};
int g_ComputerMatches{};
std::string g_PlayerMoves{};
std::string g_PcMoves{};
int g_DrawnNumber{};
bool g_IsPlayerTurn{ true };

// Declare your own functions here
void DrawPlayerMatches();
void DrawMainMatches();
void PlayerHandling();
void DrawPCMatches();
void PcHandling();
void GameEnd();

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
