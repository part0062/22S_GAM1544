#pragma once

#include <GameDev2D.h>

using namespace GameDev2D;

class Player
{
private:
	static const float TURN_SPEED; // Degrees per second.
	static const float ACCELERATION_RATE; // Pixels per second per second.
	static const float MAX_VELOCITY; // Pixels per second.
	static const Color COLOR;

public:
	Player();
	~Player();

	// Write game logic in the Update method.
	void OnUpdate(float delta);

	// Render game objects in the Draw method.
	void OnRender(BatchRenderer& batchRenderer);

	// Input event methods.
	void OnKeyEvent(KeyCode keyCode, KeyState keyState);
	void OnMouseButtonEvent(MouseButton button, MouseButtonState state, float mouseX, float mouseY);
	void OnMouseMovedEvent(float mouseX, float mouseY);

	void SetPosition(Vector2 pos);
	Vector2 GetPosition();

	float GetAngle();
	Vector2 GetVelocity();

	float GetRadius();

private:
	Vector2 m_Velocity;
	Vector2 m_Position;
	float m_Angle;

	Vector2 m_Controls;

	std::vector<Vector2> m_Shape;
};
