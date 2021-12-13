#include "Player.h"
#include <iostream>

Player::Player(const std::string& name, const int lives) :
	m_Name{ name },
	m_Score{},
	m_Lives{lives}
{

}

Player::~Player()
{
	std::cout << "I am being deleted!" << std::endl;
}

void Player::AddPoints(const int newPoints)
{
	m_Score += newPoints;
}

void Player::PrintInfo()
{
	std::cout << GetInfo() << std::endl;
}

std::string Player::GetInfo()
{
	return std::string("Hi, my name is " + m_Name + " , I have " + std::to_string(m_Lives) + " lives and i have " + std::to_string(m_Score) + " points.");
}