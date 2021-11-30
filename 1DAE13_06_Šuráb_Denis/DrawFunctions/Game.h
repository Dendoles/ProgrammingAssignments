#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Draw Functions - Šuráb, Denis - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 600 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

// Declare your own functions here

void DrawFancyTriangles();
void DrawConcetricTriangles();
void DrawWeirdlyShapedAndCoolTriangles();
//

void DrawSquares(float size, float xPos, float yPos, int numberOfSquares = 1);
void DrawSquares(float size, const Point2f& pos, int numberOfSquares = 1);
void DrawEquilateralTriangle(const Point2f& pos, float sizeOfOneSide, bool isFilled = true);
void DrawEquilateralTriangle(float posX, float posY, float sizeOfOneSide, bool isFilled = true);
void DrawPentagram(const Point2f& pos, float size, const Color4f& color);
void DrawPentagram(float xPos, float yPos, float size, float r, float g, float b, float a = 1);
void DrawLinearGradient(const Rectf& rectangle, const Color4f& firstColor, const Color4f& secondColor);
void DrawDotGrid(const Point2f& pos, float radius, int rows, int columns, float spaceBetween = 0);

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
