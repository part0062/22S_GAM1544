#include "Astroid.h"

Astroid::Astroid() :
	m_Points{},
	m_Position(GetHalfScreenWidth(), GetHalfScreenHeight())
{
	const float RADIUS = 40.0f;
	const float NUM_POINTS = 8.0f;

	float radiansPerSide = 2.0f * (float)M_PI / (float)NUM_POINTS;

	for (int i = 0; i < NUM_POINTS; i++)
	{
		float angle = i * radiansPerSide;
		Vector2 point = Vector2(cos(angle), sin(angle)) * RADIUS;

		m_Points.push_back(point);
	}
	m_Points.push_back(m_Points[0]);
}

void Astroid::OnRender(BatchRenderer& batchRenderer)
{
	batchRenderer.RenderLineStrip(m_Points, ColorList::White, 1.0f, m_Position, 0.0f);
}