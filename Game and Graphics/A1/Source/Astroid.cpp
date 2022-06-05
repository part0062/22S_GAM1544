#include "Astroid.h"

Astroid::Astroid() :
	m_Points{},
	m_Position{}
{
	m_Position.x = GameDev2D::Math::RandomFloat(0.0f, GetScreenWidth());
	m_Position.y = GameDev2D::Math::RandomFloat(0.0f, GetScreenHeight());

	const float NUM_POINTS = 8.0f;
	float radiansPerSide = 2.0f * (float)M_PI / (float)NUM_POINTS;

	const float RADIUS_MIN = 10.0f;
	const float RADIUS_MAX = 50.0f;

	for (int i = 0; i < NUM_POINTS; i++)
	{
		float angle = i * radiansPerSide;
		float radius = GameDev2D::Math::RandomFloat(RADIUS_MIN, RADIUS_MAX);
		Vector2 point = Vector2(cos(angle), sin(angle)) * radius;

		m_Points.push_back(point);
	}
	m_Points.push_back(m_Points[0]);
}



void Astroid::OnRender(BatchRenderer& batchRenderer)
{
	batchRenderer.RenderLineStrip(m_Points, ColorList::White, 1.0f, m_Position, 0.0f);
}



void Astroid::OnUpdate(float delta)
{

}