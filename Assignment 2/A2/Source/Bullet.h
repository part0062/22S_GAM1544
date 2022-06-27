#pragma once

#include <GameDev2D.h>

using namespace GameDev2D;

class Bullet
{
public:
	Bullet(Vector2 pos);
	~Bullet();

	void OnUpdate(float delta);
	void OnRender(BatchRenderer& batchRenderer);

	void SetPosition(Vector2 pos);
	Vector2 GetPosition();

	void SetAngle(float angle);
	void SetVelocity(Vector2 velocity);

	float GetRadius();

	//Shooting methods
	void Activate(const Vector2& position, const Vector2& velocity);
	bool IsActive();

private:
	static const Vector2 M_VELOCITY;
	static const float M_SPEED;
	static const float M_TIMER;

	Vector2 m_Position;
	Vector2 m_Velocity;
	std::vector<Vector2> m_Points;
	float m_Angle;
	float m_Radius;
};
