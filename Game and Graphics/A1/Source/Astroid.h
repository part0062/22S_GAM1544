#pragma once
#include "GameDev2D.h"

using namespace GameDev2D;

class Astroid
{
public:
	Astroid();
	~Astroid();

	void OnUpdate(float delta);
	void OnRender(BatchRenderer& batchRenderer);

private:
	std::vector<Vector2> m_Points;
	Vector2 m_Position;
};