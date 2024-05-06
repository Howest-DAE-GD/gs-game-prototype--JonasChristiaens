#include "pch.h"
#include "Player.h"
#include <iostream>


Player::Player(float xPos, float yPos):
	m_Color{ 1.0f, 0.0f, 0.0f, 1.0f }, m_Position { xPos, yPos }, m_Size{ 100.0f }, m_Score{ 5000 }, m_Speed{ 100.f }, m_ShrinkingFactor{ 5 }
{

}

void Player::Draw() const
{
	utils::SetColor(m_Color);
	utils::FillEllipse( m_Position, m_Size, m_Size);
}

void Player::Update(float elapsedSec) 
{
	//change difficulty dependant on ball size
	if (m_Score >= 1000)
	{
		m_ShrinkingFactor = 10;

		if (m_IsMoving) {
			m_Speed = 150.f;
		}

	}
	if (m_Score >= 5000)
	{
		m_ShrinkingFactor = 15;

		if (m_IsMoving) {
			m_Speed = 200.f;
		}
	}

	//let the ball shrink
	if (m_Size >= 1.0f)
	{
		m_Size -= m_ShrinkingFactor * elapsedSec;
	}
	
	//check which keys are pressed
	CheckKeys();

	//update position
	m_Position.x += m_DirectionVector.x * m_Speed * elapsedSec;
	m_Position.y += m_DirectionVector.y * m_Speed * elapsedSec;

	std::cout << "X: " << m_Position.x << ", Y:" << m_Position.y << std::endl;
	std::cout << "m_Size: " << m_Size << std::endl;
	std::cout << "m_Score: " << m_Score << std::endl;
	std::cout << "m_Speed: " << m_Speed << std::endl;
	std::cout << "m_ShrinkingFactor: " << m_ShrinkingFactor << std::endl;
	std::cout << " " << std::endl;
}

void Player::CheckKeys()
{
	m_DirectionVector = Vector2f{};
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	const bool isLeft{ bool(pStates[SDL_SCANCODE_A]) };
	const bool isRight{ bool(pStates[SDL_SCANCODE_D]) };
	const bool isUp{ bool(pStates[SDL_SCANCODE_W]) };
	const bool isDown{ bool(pStates[SDL_SCANCODE_S]) };

	if (isUp)
	{
		m_DirectionVector.y += 1;
	}
	if (isDown)
	{
		m_DirectionVector.y -= 1;
	}
	if (isLeft)
	{
		m_DirectionVector.x -= 1;
	}
	if (isRight)
	{
		m_DirectionVector.x += 1;
	}

	m_IsMoving = isUp || isLeft || isDown || isRight;
	m_DirectionVector = m_DirectionVector.Normalized();
}