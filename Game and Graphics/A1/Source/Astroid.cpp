#include "Astroid.h"

//TODO Add randomizing to starting position

Astroid::Astroid() :
	m_Points{},
	m_Position{},
	m_Speed(300.0f)
{
	m_Angle = GameDev2D::Math::RandomFloat(0.0f, (2.0f * (float)M_PI));
	const float NUM_POINTS = 8.0f;

	m_Radians = (2.0f * (float)M_PI / NUM_POINTS);

	const float RADIUS_MIN = 10.0f;
	const float RADIUS_MAX = 50.0f;

	for (int i = 0; i < NUM_POINTS; i++)
	{
		float angle = i * m_Radians;
		float radius = GameDev2D::Math::RandomFloat(RADIUS_MIN, RADIUS_MAX);
		Vector2 point = Vector2(cos(angle), sin(angle)) * radius;

		m_Points.push_back(point);
	}
	m_Points.push_back(m_Points[0]);
}



void Astroid::OnRender(BatchRenderer& batchRenderer)
{
	batchRenderer.RenderLineStrip(m_Points, ColorList::White, 1.0f, m_Position, m_Angle);
}



void Astroid::OnUpdate(float delta)
{
	m_Velocity = Vector2(cos(m_Radians), sin(m_Radians)) * m_Speed;

	Vector2 displacement = m_Velocity * delta;

	m_Position += displacement;
}