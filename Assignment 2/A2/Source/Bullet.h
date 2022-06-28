#pragma once

#include <GameDev2D.h>

using namespace GameDev2D;

class Bullet
{
public:
	Bullet();
	~Bullet();

	void OnUpdate(float delta);
	void OnRender(BatchRenderer& batchRenderer);

	void SetPosition(Vector2 pos);
	Vector2 GetPosition();

	void SetAngle(float angle);
	void SetVelocity(Vector2 velocity);

	float GetRadius();

	//Shooting methods
	void Activate(const Vector2& pos, const Vector2& velocity, float angle);
	bool IsActive();
	void SetActive(bool a);

private:
	static const Vector2 M_VELOCITY;
	static const float M_SPEED;

	Vector2 m_Position;
	Vector2 m_Velocity;
	std::vector<Vector2> m_Points;

	float m_Angle;
	float m_Radius;

	bool m_IsActive;
};
