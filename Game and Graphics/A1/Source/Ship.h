#pragma once
#include "GameDev2D.h"

class Ship
{
public:
	Ship();
	void OnRender(GameDev2D::BatchRenderer& batchRenderer);
	void OnUpdate(float delta);
	void OnKeyEvent(GameDev2D::KeyCode keyCode, GameDev2D::KeyState keyState);

private:
	std::vector<GameDev2D::Vector2> m_Points;
	GameDev2D::Vector2 m_Position;

	float m_Angle;
	float m_PosX;
	float m_PosY;
};