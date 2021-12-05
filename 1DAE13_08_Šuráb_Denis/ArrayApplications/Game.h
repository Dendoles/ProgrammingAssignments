#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "ArrayApplications - Šuráb, Denis - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const int g_PointsSize{5};
int g_Assigner{g_PointsSize};
Point2f g_Points[g_PointsSize]{};
const int g_AngleSpeedSize{100};
AngleSpeed g_AngleSpeed[g_AngleSpeedSize]{};

// Declare your own functions here

int UpdateAssigner();
void DrawClickedPoints();
void ShovePoints();
void DrawPentagram();
void UpdatePentagram(float elapsedTime);
void InitPentagramSpeed();

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
