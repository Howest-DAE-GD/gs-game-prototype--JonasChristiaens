#pragma once
#include "utils.h"

class Player
{
public:
	Player(float xPos, float yPos);

	void Draw() const;
	void Update(float elapsedSec);
	void CheckKeys();
	void GainSize();
	void IncreaseScore();
	Point2f GetPosition();
	float GetSize();
	int GetScore();

private:
	Vector2f	m_DirectionVector;
	Color4f		m_Color;
	Point2f		m_Position;
	float		m_Size, m_Speed;
	int			m_Score, m_ShrinkingFactor;
	bool		m_IsMoving{};
};

