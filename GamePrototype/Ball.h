#pragma once
#include "utils.h"

class Ball
{
public:
	Ball(float xPos, float yPos);

	void Draw() const;
	void Update(float elapsedSec);

private:
	Color4f		m_Color;
	Point2f		m_Position{};
	float		m_Size{ 20 };
	int			m_Score;
};