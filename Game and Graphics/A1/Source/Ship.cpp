#include "Ship.h"
#include <iostream>

//TODO Add a max speed

using namespace GameDev2D;

Ship::Ship() :
	m_Points{{5.0f, 0.0f}, {0.0f, 25.0f}, {45.0f, 0.0f}, {0.0f, -25.0f}, {5.0f, 0.0f}},
	m_Position{GetHalfScreenWidth(), GetHalfScreenHeight()},
	m_Angle(0.0f),
	m_IsRotating(false),
	m_IsCounterClockwise(false),
	m_Forward(false),
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
}



//--------------------------------------------------------------------------------------------------

void Ship::OnUpdate(float delta)
{
	const float SHIP_SPEED = 10.0f;

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

	float angleToRadians = Math::DegreesToRadians(m_Angle);

	Vector2 shipDir(cos(m_Angle), sin(m_Angle));

	if (m_Forward)
	{
		m_Speed += (shipDir * SHIP_SPEED);
	}

	m_Position +=  m_Speed * delta;

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