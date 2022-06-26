#pragma once

#include <GameDev2D.h>

using namespace GameDev2D;

class Asteroid
{
private:
	static const float MIN_VELOCITY; // Pixels per second. 
	static const float MAX_VELOCITY; // Pixels per second. 
	static const float MIN_ANGULAR_VELOCITY; // Degrees per second.
	static const float MAX_ANGULAR_VELOCITY; // Degrees per second.
	static const int MIN_SIDES;
	static const int MAX_SIDES;
	static const float MIN_RADIUS;
	static const float MAX_RADIUS;
	static const Color COLOR;

public:
	Asteroid();
	~Asteroid();

	// Write game logic in the Update method.
	void OnUpdate(float delta);

	// Render game objects in the Draw method.
	void OnRender(BatchRenderer& batchRenderer);

	void SetPosition(Vector2 pos);
	Vector2 GetPosition();

	float GetRadius();

private:
	Vector2 m_Velocity;
	Vector2 m_Position;
	float m_AngularVelocity;
	float m_Angle;
	float m_Radius;

	std::vector<Vector2> m_Shape;
};
