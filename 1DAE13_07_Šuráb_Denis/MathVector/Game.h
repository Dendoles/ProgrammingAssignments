#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "MathVector - Šuráb, Denis - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

Vector2f g_Vector{ 100 , 30 };
float g_LengthOfVector{200};
Point2f g_Center{ g_WindowWidth / 2.f, g_WindowHeight / 2.f };
float g_Angle{ };

// Declare your own functions here

void DrawTriangle(float posX, float posY, float sizeOfOneSide);
void PrintDotProduct();
void PrintCrossProduct();
void PrintLength();
void PrintScale();
void PrintNormalize();
void PrintAngleBetween();
void DrawVectorAnimation();
void RotationOfAnimation(float elapsedTime);

void DrawVector(const Vector2f& vector, const Point2f& startingPos = Point2f(0, 0));
std::string ToString(const Vector2f& vector);
Vector2f Add(const Vector2f& vector1, const Vector2f& vector2);
Vector2f Subtract(const Vector2f& vector1, const Vector2f& vector2);
float DotProduct(const Vector2f& vector1, const Vector2f& vector2);
float CrossProduct(const Vector2f& vector1, const Vector2f& vector2);
float Length(const Vector2f& vector);
Vector2f Scale(const Vector2f& vector, float scale);
Vector2f Normalize(const Vector2f& vector);
float AngleBetween(const Vector2f& vector1, const Vector2f& vector2);
bool AreEqual(const Vector2f& vector1, const Vector2f& vector2);

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
