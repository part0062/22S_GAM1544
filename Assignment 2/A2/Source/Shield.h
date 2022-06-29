#pragma once
#include "GameDev2D.h"

using namespace GameDev2D;

class Shield
{
public:
	Shield();
	~Shield();

	void OnUpdate(float delta);
	void OnRender(BatchRenderer& batchRenderer);

private:
	Vector2 m_Position;
	std::vector<Vector2> m_Shape; 
};