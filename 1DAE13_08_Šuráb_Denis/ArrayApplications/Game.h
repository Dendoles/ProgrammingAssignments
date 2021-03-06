#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "ArrayApplications - ?ur?b, Denis - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Color4f g_ColorForRand{1,0,1,1};
const int g_RandSize{6};
int g_RandValues[g_RandSize]{};
Texture g_RandNumbers[g_RandSize]{};


const int g_PointsSize{5};
int g_Assigner{g_PointsSize};
Point2f g_Points[g_PointsSize]{};

const int g_AngleSpeedSize{100};
AngleSpeed g_AngleSpeed[g_AngleSpeedSize]{};

const int g_BubblePointsSize{10};
Point2f g_BubblePoints[g_BubblePointsSize]{};
Point2f g_MousePos{};


Point2f g_ClickPos{};
const int g_Rows{3};
const int g_Columns{4};
const int g_CellClickedSize{g_Rows * g_Columns};
bool g_IsCellClicked[g_CellClickedSize]{};
const Point2f g_PosOfGrid{ 20, g_WindowHeight / 2.f };
const float g_OneGridSize{ 80 };


// Declare your own functions here

int UpdateAssigner();
void DrawClickedPoints();
void ShovePoints();
void DrawPentagram();
void UpdatePentagram(float elapsedTime);
void InitPentagramSpeed();
void LoadAndCheckTextures();
void UpdateRandStats();
void DrawRandStats();
void UpdateBubbles();
void DrawFollowingBubbles();
void UpdateGrids();
void DrawGrid();
void CheckCollision();

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
