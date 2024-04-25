#include "pch.h"
#include "Player.h"

Player::Player(float xPos, float yPos):
	m_Color{ 1.0f, 0.0f, 0.0f, 1.0f }, m_Position { xPos, yPos }, m_Size{ 100.0f }, m_Score{ 5000 }, m_Speed{ 0 }, m_ShrinkingFactor{ 5 }
{

}

void Player::Draw() const
{
	utils::SetColor(m_Color);
	utils::FillEllipse( m_Position,m_Size, m_Size);
}

void Player::Update(float elapsedSec) 
{
	if (m_Score >= 1000)
	{
		m_ShrinkingFactor = 10;
	}
	if (m_Score >= 5000)
	{
		m_ShrinkingFactor = 15;
	}

	if (m_Size >= 1.0f)
	{
		m_Size -= m_ShrinkingFactor * elapsedSec;
	}
	
	CheckKeys();
	m_Speed = m_IsMoving ? 200.f : 20.f;

	m_Position.x += m_DirectionVector.x * m_Speed * elapsedSec;
	m_Position.y += m_DirectionVector.y * m_Speed * elapsedSec;
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