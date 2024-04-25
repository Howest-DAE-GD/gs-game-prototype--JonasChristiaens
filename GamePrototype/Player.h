#pragma once
#include "utils.h"

class Player
{
public:
	Player(float xPos, float yPos);

	void Draw() const;
	void Update(float elapsedSec);
	void CheckKeys();

private:
	Vector2f	m_DirectionVector;
	Color4f		m_Color;
	Point2f		m_Position;
	float		m_Size;
	int			m_Score, m_Speed, m_ShrinkingFactor;
	bool		m_IsMoving{};
};

