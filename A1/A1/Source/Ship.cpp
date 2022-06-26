#include "Ship.h"
#include <iostream>

using namespace GameDev2D;

Ship::Ship() :
	m_Points{{5.0f, 0.0f}, {-5.0f, 15.0f}, {30.0f, 0.0f}, {-5.0f, -15.0f}, {5.0f, 0.0f}},
	m_Position{GetHalfScreenWidth(), GetHalfScreenHeight()},
	m_Angle(0.0f),
	m_IsRotating(false),
	m_IsCounterClockwise(false),
	m_Forward(false),
	m_Backwards(false),
	m_Speed{0.0f, 0.0f} {} 



//--------------------------------------------------------------------------------------------------

void Ship::OnRender(BatchRenderer& batchRenderer)
{
	batchRenderer.RenderLineStrip(m_Points, GameDev2D::ColorList::White, 1.0f, m_Position, m_Angle);
}



//--------------------------------------------------------------------------------------------------

void Ship::OnKeyEvent(KeyCode keyCode, KeyState keyState)
{
//direction/rotation bool switches
	if (keyCode == KeyCode::Left && keyState == KeyState::Down)
	{
		m_IsCounterClockwise = true;
		m_IsRotating = true;
	}
	else if (keyCode == KeyCode::Right && keyState == KeyState::Down)
	{
		m_IsCounterClockwise = false;
		m_IsRotating = true;
	}

//direction bools switched off on release
	if (keyCode == KeyCode::Left && keyState == KeyState::Up)
	{
		m_IsRotating = false;
	}
	else if (keyCode == KeyCode::Right && keyState == KeyState::Up)
	{
		m_IsRotating = false;
	}

//moving the ship forward
	if (keyCode == KeyCode::Up && keyState == KeyState::Down)
	{
		m_Forward = true;
	}
	else if (keyCode == KeyCode::Up && keyState == KeyState::Up)
	{
		m_Forward = false;
	}

//breaking the ship
	if (keyCode == KeyCode::Down && keyState == KeyState::Down)
	{
		m_Backwards = true;
	}
	else if (keyCode == KeyCode::Down && keyState == KeyState::Up)
	{
		m_Backwards = false;
	}
}



//--------------------------------------------------------------------------------------------------

void Ship::OnUpdate(float delta)
{
	const float SHIP_SPEED = 10.0f;
	const float MAX_SPEED = 500.0f;

	if (m_IsRotating)
	{
		if (m_IsCounterClockwise)
		{
			m_Angle = m_Angle + (SHIP_SPEED * delta);
		}
		else if (!m_IsCounterClockwise)
		{
			m_Angle = m_Angle - (SHIP_SPEED * delta);
		}
	}

//Move the ship forward

	Vector2 shipDir(cos(m_Angle), sin(m_Angle));

	if (m_Backwards)
	{
		m_Speed = m_Speed * (0.95f);
		if (m_Speed < Vector2::Unit) {
			m_Speed = Vector2::Zero;
		}
	}
	else if (m_Forward)
	{
		m_Speed += (shipDir * SHIP_SPEED);
	}

	m_Position +=  m_Speed * delta;

	if (m_Speed.Length() > MAX_SPEED)
	{
		m_Speed = m_Speed.Normalized() * MAX_SPEED;
	}

//Make the ship loop around the screen

	if (m_Position.x < 0.0f)
	{
		m_Position.x = GetScreenWidth();
	}
	else if (m_Position.x > GetScreenWidth())
	{
		m_Position.x = 0.0f;
	}

	if (m_Position.y < 0.0f)
	{
		m_Position.y = GetScreenHeight();
	}
	else if (m_Position.y > GetScreenHeight())
	{
		m_Position.y = 0.0f;
	}
}