#include "Ship.h"


Ship::Ship() :
	m_Points{{5.0f, 0.0f}, {0.0f, 25.0f}, {45.0f, 0.0f}, {0.0f, -25.0f}, {5.0f, 0.0f}},
	m_PosX(1280.0f / 2.0f),
	m_PosY(720.0f / 2.0f),
	m_Angle(GameDev2D::Math::DegreesToRadians(0.0f))
{
	m_Position.x = m_PosX;
	m_Position.y = m_PosY;
}


void Ship::OnRender(GameDev2D::BatchRenderer& batchRenderer)
{
	batchRenderer.RenderLineStrip(m_Points, GameDev2D::ColorList::White, 1.0f, m_Position, m_Angle);
}