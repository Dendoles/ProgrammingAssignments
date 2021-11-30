#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "DiceStats - Šuráb, Denis - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_DiceValue1{};
float g_DiceValue2{};
float g_DiceValue3{};
float g_DiceValue4{};
float g_DiceValue5{};
float g_DiceValue6{};

float g_TwoDiceValue2{};
float g_TwoDiceValue3{};
float g_TwoDiceValue4{};
float g_TwoDiceValue5{};
float g_TwoDiceValue6{};
float g_TwoDiceValue7{};
float g_TwoDiceValue8{};
float g_TwoDiceValue9{};
float g_TwoDiceValue10{};
float g_TwoDiceValue11{};
float g_TwoDiceValue12{};

const float g_Border{10}; //18
float g_RectHeight{(g_WindowHeight - (18 * g_Border)) / 17};

// Declare your own functions here
void OneDiceTracking();
void DrawRedDiceGraphs(Color4f colorOfStatistics);

void TwoDiceTracking();
void DrawPurpleDiceGraphs(Color4f colorOfStatistics);

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
