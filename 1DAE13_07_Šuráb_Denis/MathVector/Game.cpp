#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	//PrintDotProduct();
	//PrintCrossProduct();
	//PrintLength();
	//PrintScale();
	//PrintNormalize();
	//PrintAngleBetween();
}

void Draw()
{
	ClearBackground();

	DrawVectorAnimation();

	// Put your own draw statements here
	//Point2f startingPos{100, 100};
	//Vector2f vector{180,200};

	//SetColor(1, 0, 0);
	//DrawVector(g_Vector, startingPos);
	//DrawVector(vector, startingPos); //

	//Point2f secondPos{vector.x + startingPos.x, vector.y + startingPos.y};

	//SetColor(0, 0, 1);
	//DrawVector(Subtract(g_Vector, vector), secondPos);

}

void Update(float elapsedSec)
{
	RotationOfAnimation(elapsedSec);
	// process input, do physics 

	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

void DrawTriangle(float posX, float posY, float sizeOfOneSide)
{
	Point2f pos{ posX, posY };
	Point2f pos2{ pos.x + sizeOfOneSide, pos.y };
	Point2f pos3{ (sizeOfOneSide * cosf(g_Pi / 3.f) + pos.x), (sizeOfOneSide * sinf(g_Pi / 3.f) + pos.y) };

	FillTriangle(pos, pos2, pos3);
}

void DrawVector(const Vector2f& vector, const Point2f& startingPos)
{
	float size{5};
	//const float rad = g_Pi / 180;
	//const float atan2 = (90 * rad) - atan2f(vector.x, vector.y);

	Point2f endOfTheVectorPos{ vector.x + startingPos.x, vector.y + startingPos.y };

	DrawLine(startingPos.x, startingPos.y, endOfTheVectorPos.x, endOfTheVectorPos.y);

	FillEllipse(endOfTheVectorPos,size, size);
	//DrawTriangle(endOfTheVectorPos.x * atan2, endOfTheVectorPos.y * atan2, size);
}

std::string ToString(const Vector2f& vector)
{
	std::string vectorS = "[" + std::to_string(vector.x) + ", " + std::to_string(vector.y) + "]";
	return vectorS;
}

Vector2f Add(const Vector2f& vector1, const Vector2f& vector2)
{
	Vector2f vector{vector1.x + vector2.x, vector1.y + vector2.y};
	return vector;
}

Vector2f Subtract(const Vector2f& vector1, const Vector2f& vector2)
{
	Vector2f vector{vector1.x - vector2.x, vector1.y - vector2.y};
	return vector;
}

float DotProduct(const Vector2f& vector1, const Vector2f& vector2)
{
	return vector1.x * vector2.x + vector1.y * vector2.y;
}

float CrossProduct(const Vector2f& vector1, const Vector2f& vector2)
{
	return (vector1.x * vector2.y) - (vector1.y * vector2.x);
}

void PrintDotProduct()
{
	Vector2f hor{ 80, 0 };
	Vector2f ver{ 0, 50 };
	Vector2f para{ 0, 25 };

	std::cout << "Dot product: " << '\n';
	std::cout << "hor = " << ToString(hor) << "		ver = " << ToString(ver) << "		Dot product: " << DotProduct(hor, ver) << '\n';
	std::cout << "ver = " << ToString(ver) << "		para = " << ToString(para) << "		Dot product: " << DotProduct(ver, para) << '\n';
}

void PrintCrossProduct()
{
	Vector2f hor{ 80, 0 };
	Vector2f ver{ 0, 50 };

	std::cout << "Cross product: " << '\n';
	std::cout << "hor = " << ToString(hor) << "		ver = " << ToString(ver) << "		Cross product: " << CrossProduct(hor, ver) << '\n';
	std::cout << "ver = " << ToString(ver) << "		hor = " << ToString(hor) << "		Cross product: " << CrossProduct(ver, hor) << '\n';
}

void PrintLength()
{
	Vector2f vactor{ 100, 30 };
	std::cout << "Length of " << ToString(vactor) << " is " << Length(vactor);
}

float Length(const Vector2f& vector)
{
	return sqrtf(powf(vector.x, 2) + powf(vector.y, 2));
}

Vector2f Scale(const Vector2f& vector, float scale)
{
	return Vector2f(vector.x * scale, vector.y * scale);
}

void PrintScale()
{
	float scale{0.1f};
	Vector2f vector{ 100, 30 };
	std::cout << "Scaled  " << ToString(vector) << " is " << ToString(Scale(vector, scale));
}

void PrintNormalize()
{
	Vector2f vector{ 100, 30 };
	Vector2f vectorN{ Normalize(vector) };
	std::cout << "Normalized  " << ToString(vector) << " is " << ToString(vectorN) << " its length is: " << Length(vectorN);
}

Vector2f Normalize(const Vector2f& vector)
{
	float length{Length(vector)};
	return Vector2f(vector.x / length, vector.y / length);
}

void PrintAngleBetween()
{
	Vector2f vectorA{ 10 , 0 };
	Vector2f vectorB{ 10 , 10 };
	float angleInRadians{ AngleBetween(vectorA, vectorB) };
	float angleInDegrees{ angleInRadians * 180 / g_Pi };
	std::cout << "Angle between  " << ToString(vectorA) << " and " << ToString(vectorB) << " is: " << angleInRadians << " radians, or " << angleInDegrees << " degrees.";
}

float AngleBetween(const Vector2f& vector1, const Vector2f& vector2)
{
	return atan2(CrossProduct(vector1, vector2), DotProduct(vector1, vector2));
}

bool AreEqual(const Vector2f& vector1, const Vector2f& vector2)
{
	float difference{0.001f};
	Vector2f vector{abs(vector1.x - vector2.x), abs(vector1.y - vector2.y)};


	if (vector.x <= difference &&
		vector.y <= difference)
	{
		return true;
	}
	return false;
}

void DrawVectorAnimation()
{
	Vector2f vectorA{ g_LengthOfVector * cosf(g_Angle), g_LengthOfVector * sinf(g_Angle) };
	Vector2f vectorB{ 30.0f, -80.0f };
	Vector2f vectorBNorm{ Normalize(vectorB) };
	Vector2f vectorProjection{ Scale(vectorBNorm, DotProduct(vectorA, vectorBNorm)) };

	//SetColor(0, 0, 1);
	//DrawVector(vectorB, g_Center);
	SetColor(1, 1, 1);
	DrawVector(vectorA, g_Center);
	SetColor(1, 0, 0);
	DrawVector(vectorProjection, g_Center);
}

void RotationOfAnimation(float elapsedTime)
{
	const float amount{ 0.8f };
	g_Angle += amount * elapsedTime;
}

#pragma endregion ownDefinitions