#pragma once
#include "GameDev2D.h"

using namespace GameDev2D;

class Astroid
{
public:
	Astroid();

	void OnUpdate(float delta);
	void OnRender(BatchRenderer& batchRenderer);

private:
	std::vector<Vector2> m_Points;
	Vector2 m_Position;
	Vector2 m_Velocity;
	float m_Angle;
	float m_Speed;
	float m_Radians;
};