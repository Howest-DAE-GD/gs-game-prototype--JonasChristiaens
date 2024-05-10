#include "pch.h"
#include "Ball.h"
#include <time.h>

Ball::Ball(float xPos, float yPos):
	m_Color{ 0.0f, 1.0f, 0.0f, 1.0f }, m_Position{xPos, yPos}
{

}

void Ball::Draw() const
{
	utils::SetColor(m_Color);
	utils::FillEllipse(m_Position, m_Size, m_Size);
}

Point2f Ball::GetPosition()
{
	return m_Position;
}
