#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();
	Point2f pos{ g_WindowWidth / 2.f, g_WindowHeight / 2.f };
	Color4f red{ 1, 0, 0, 1 };
	Color4f blue{0,0,1,1};

	Color4f green{ 0, 1, 0, 0 };
	Color4f purple{ 1,0,1,1 };
	Rectf rectangle{ 10, 10, g_WindowWidth - 20, 20 };

	/*SetColor(red);
	FillRect(rectangle);*/
	//DrawDotGrid(pos, 20, 3, 5, 5);
	//DrawPentagram(pos, 100, red);
	//DrawLinearGradient(rectangle, green, purple);
	//DrawPentagram(pos.x, pos.y, 100, 1, 0, 0);

	//DrawFancyTriangles();
	//DrawConcetricTriangles();
	//DrawSquares(100, g_WindowWidth / 2.f, g_WindowHeight / 2.f, 10);
		


}

void Update(float elapsedSec)
{
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

void DrawSquares(float size, float xPos, float yPos, int numberOfSquares)
{
	const float spaceBetweenSquares{size / numberOfSquares / 2.f};
	for (int i = 0; i < numberOfSquares; i++)
	{
		DrawRect(xPos + (spaceBetweenSquares * i), yPos + (spaceBetweenSquares * i), size - 2 * (spaceBetweenSquares * i), size - 2 * (spaceBetweenSquares * i));
	}
}

void DrawSquares(float size, const Point2f& pos, int numberOfSquares)
{
	const float spaceBetweenSquares{ size / numberOfSquares / 2.f };
	for (int i = 0; i < numberOfSquares; i++)
	{
		DrawRect(pos.x + (spaceBetweenSquares * i), pos.y + (spaceBetweenSquares * i), size - 2 * (spaceBetweenSquares * i), size - 2 * (spaceBetweenSquares * i));
	}
}

void DrawEquilateralTriangle(const Point2f& pos, float sizeOfOneSide, bool isFilled)
{
	Point2f pos2{ pos.x + sizeOfOneSide, pos.y };
	Point2f pos3{ (sizeOfOneSide * cosf(g_Pi / 3.f) + pos.x), (sizeOfOneSide * sinf(g_Pi / 3.f) + pos.y) };

	if (isFilled == true)
	{
		FillTriangle(pos, pos2, pos3);
	}
	else
	{
		DrawTriangle(pos, pos2, pos3);
	}
}
void DrawEquilateralTriangle(float posX, float posY, float sizeOfOneSide, bool isFilled)
{
	Point2f pos{ posX, posY };
	Point2f pos2{ pos.x + sizeOfOneSide, pos.y };
	Point2f pos3{ (sizeOfOneSide * cosf(g_Pi / 3.f) + pos.x), (sizeOfOneSide * sinf(g_Pi / 3.f) + pos.y) };

	if (isFilled == true)
	{
		FillTriangle(pos, pos2, pos3);
	}
	else
	{
		DrawTriangle(pos, pos2, pos3);
	}
}

void DrawFancyTriangles()
{
	Point2f pos{ g_WindowWidth / 2.f, g_WindowHeight / 2.f };
	const float sizeOfOneSide{ 50.f };
	Point2f pos2{ (sizeOfOneSide * cosf(g_Pi / 3.f) + pos.x), (sizeOfOneSide * sinf(g_Pi / 3.f) + pos.y) };
	Point2f pos3{ pos.x + sizeOfOneSide, pos.y };
	SetColor(0, 1, 1);
	DrawEquilateralTriangle(pos, sizeOfOneSide, true);
	SetColor(1, 0, 1);
	DrawEquilateralTriangle(pos2, sizeOfOneSide, true);
	SetColor(1, 1, 0);
	DrawEquilateralTriangle(pos3, sizeOfOneSide, true);
	SetColor(0, 0, 0);
	DrawEquilateralTriangle(pos, sizeOfOneSide * 2.f, false);
}

void DrawConcetricTriangles()
{
	Point2f pos{ g_WindowWidth / 2.f, g_WindowHeight / 2.f };
	const int numberOfTriangles{ 3 };
	const float sizeOfOneSide{ 100.f };
	const float onePartition{sizeOfOneSide / numberOfTriangles};

	Point2f posNext{ (onePartition * cosf(g_Pi / 6.f)) / 2.f, (onePartition * sinf(g_Pi / 6.f)) / 2.f };
	//Point2f posNext{ 15, 10 };
	for (int i = 0; i < numberOfTriangles; i++)
	{
		switch (i)
		{
		case 0:
			SetColor(1, 0, 0);
			break;
		case 1:
			SetColor(0, 1, 0);
			break;
		case 2:
			SetColor(0, 0, 1);
			break;
		default:
			SetColor(1, 1, 1);
		}

		DrawEquilateralTriangle(pos.x + (posNext.x * i), pos.y + (posNext.y * i), sizeOfOneSide - (onePartition * i), true);
	}
}

void DrawWeirdlyShapedAndCoolTriangles()
{
		Point2f pos{ g_WindowWidth / 2.f, g_WindowHeight / 2.f };
		const int numberOfTriangles{ 3 };
		const float sizeOfOneSide{ 100.f };
		const float onePartition{ sizeOfOneSide / numberOfTriangles };

		Point2f posNext{ (onePartition * cosf(g_Pi / 3.f)), (onePartition * sinf(g_Pi / 3.f)) };
		//Point2f posNext{ 15, 10 };
		for (int i = 0; i < numberOfTriangles; i++)
		{
			switch (i)
			{
			case 0:
				SetColor(1, 0, 0);
				break;
			case 1:
				SetColor(0, 1, 0);
				break;
			case 2:
				SetColor(0, 0, 1);
				break;
			default:
				SetColor(1, 1, 1);
			}

			DrawEquilateralTriangle(pos.x + (posNext.x * i), pos.y + (posNext.y * i), sizeOfOneSide - (onePartition * i), true);
		}
	}
void DrawPentagram(const Point2f& pos, float size, const Color4f& color)
{
	const float offset{ (2.f * g_Pi) / 5.f };
	Point2f p1{ size * cosf(0.f) + pos.x, size * sinf(0.f) + pos.y };
	Point2f p2{ size * cosf(offset) + pos.x,  size * sinf(offset) + pos.y };
	Point2f p3{ size * cosf(offset * 2.f) + pos.x, size * sinf(offset * 2.f) + pos.y };
	Point2f p4{ size * cosf(offset * 3.f) + pos.x,   size * sinf(offset * 3.f) + pos.y };
	Point2f p5{ size * cosf(offset * 4.f) + pos.x,   size * sinf(offset * 4.f) + pos.y };

	SetColor(color);
	DrawLine(p1.x, p1.y, p3.x, p3.y);
	DrawLine(p1.x, p1.y, p4.x, p4.y);
	DrawLine(p2.x, p2.y, p4.x, p4.y);
	DrawLine(p2.x, p2.y, p5.x, p5.y);
	DrawLine(p3.x, p3.y, p5.x, p5.y);

}
void DrawPentagram(float xPos, float yPos, float size, float r, float g, float b, float a)
{
	const float offset{ (2.f * g_Pi) / 5.f };
	Point2f p1{ size * cosf(0.f) + xPos, size * sinf(0.f) + yPos };
	Point2f p2{ size * cosf(offset) + xPos,  size * sinf(offset) + yPos };
	Point2f p3{ size * cosf(offset * 2.f) + xPos, size * sinf(offset * 2.f) + yPos };
	Point2f p4{ size * cosf(offset * 3.f) + xPos,   size * sinf(offset * 3.f) + yPos };
	Point2f p5{ size * cosf(offset * 4.f) + xPos,   size * sinf(offset * 4.f) + yPos };

	SetColor(r, g, b, a);
	DrawLine(p1.x, p1.y, p3.x, p3.y);
	DrawLine(p1.x, p1.y, p4.x, p4.y);
	DrawLine(p2.x, p2.y, p4.x, p4.y);
	DrawLine(p2.x, p2.y, p5.x, p5.y);
	DrawLine(p3.x, p3.y, p5.x, p5.y);
	/*glLineWidth(1.f);
	SetColor(r, g, b, a);
	glBegin(GL_LINE_LOOP);
	{
		glVertex2f(p1.x, p3.y);
		glVertex2f(p2.x, p4.y);
		glVertex2f(p2.x, p4.y);
		glVertex2f(p2.x, p5.y);
		glVertex2f(p3.x, p5.y);
	}
	glEnd();*/
}

void DrawLinearGradient(const Rectf& rectangle, const Color4f& firstColor, const Color4f& secondColor)
{
	const float rc = -(firstColor.r - secondColor.r) / rectangle.width;
	const float gc = -(firstColor.g - secondColor.g) / rectangle.width;
	const float bc = -(firstColor.b - secondColor.b) / rectangle.width;
	const float ac = -(firstColor.a - secondColor.a) / rectangle.width;

	float r{}, g{}, b{}, a{};

	for (int i = 1; i <= rectangle.width; i++)
	{
		r = firstColor.r + (rc * i);
		g = firstColor.g + (gc * i);
		b = firstColor.b + (bc * i);
		a = firstColor.a + (ac * i);

		SetColor(r, g, b, a);
		DrawLine(rectangle.left + ((i - 1) * 1) , rectangle.bottom, rectangle.left + ((i - 1) * 1), rectangle.bottom + rectangle.height);
	}
}

void DrawDotGrid(const Point2f& pos, float radius, int rows, int columns , float spaceBetween)
{
	const Point2f pos1{pos.x + radius, pos.y + radius};
	const float offset{ radius * 2.f + spaceBetween };

	for (int j = 0; j < rows; j++)
	{
		for (int i = 0; i < columns; i++)
		{
			FillEllipse(pos1.x + (offset * i), pos1.y + (j * offset), radius, radius);
		}
	}

	/*SetColor(1, 1, 1);
	DrawRect(pos.x, pos.y, (columns * radius * 2.f + (columns - 1) * spaceBetween), (rows * radius * 2.f + (rows - 1) * spaceBetween));*/
}

#pragma endregion ownDefinitions