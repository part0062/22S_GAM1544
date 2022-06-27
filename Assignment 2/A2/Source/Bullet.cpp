#include "Bullet.h"

using namespace GameDev2D;

const float Bullet::M_SPEED = 800.0f;

Bullet::Bullet(Vector2 pos) :
	m_Position(pos),
	m_Velocity(Vector2::Zero),
	m_Angle(0.0f),
	m_Radius(3.0f)
{
	m_Points.push_back(Vector2(0.0f, 3.0f));
	m_Points.push_back(Vector2(3.0f, 0.0f));
	m_Points.push_back(Vector2(0.0f, -3.0f));
	m_Points.push_back(Vector2(-3.0f, 0.0f));
	m_Points.push_back(Vector2(0.0f, 3.0f));
}

Bullet::~Bullet()
{
}

void Bullet::OnUpdate(float delta)
{

	float angleRadians = Math::DegreesToRadians(m_Angle);
	Vector2 direction = Vector2(cos(angleRadians), sin(angleRadians));
	m_Velocity += direction * M_SPEED * delta;
	m_Position +=  m_Velocity * delta;
}

void Bullet::OnRender(BatchRenderer& batchRenderer)
{
	float angleRadians = (float)(m_Angle * M_PI / 180.0f);
	batchRenderer.RenderLineStrip(m_Points, ColorList::White, 1.0f, m_Position, angleRadians);
}

void Bullet::SetPosition(Vector2 pos)
{
	m_Position = pos;
}

Vector2 Bullet::GetPosition()
{
	return m_Position;
}

void Bullet::SetAngle(float angle)
{
	m_Angle = angle;
}

void Bullet::SetVelocity(Vector2 velocity)
{
	m_Velocity = velocity;
}

float Bullet::GetRadius()
{
	return m_Radius;
}