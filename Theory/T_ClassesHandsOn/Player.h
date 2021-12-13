#pragma once
#include <string>

class Player
{
public:
	Player(const std::string& name, const int lives);
	~Player();

	void AddPoints(const int newPoints);
	void PrintInfo();
	

private:
	std::string GetInfo();

	std::string m_Name;
	int m_Score;
	int m_Lives;

};

