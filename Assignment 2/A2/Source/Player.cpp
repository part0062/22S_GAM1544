#include "Player.h"

using namespace GameDev2D;

const float Player::TURN_SPEED = 180.0f; // Degrees per second.
const float Player::ACCELERATION_RATE = 200.0f; // Pixels per second per second.
const float Player::MAX_VELOCITY = 200.0f; // Pixels per second. 
const Color Player::COLOR = ColorList::White;

Player::Player()
{
	// Define the player shape.
	m_Shape.push_back( Vector2(  10,   0 ) );
	m_Shape.push_back( Vector2( -10,  10 ) );
	m_Shape.push_back( Vector2(  -5,   0 ) );
	m_Shape.push_back( Vector2( -10, -10 ) );
	m_Shape.push_back( Vector2(  10,   0 ) );

	m_Angle = 0;
}

Player::~Player()
{
}

void Player::OnUpdate(float delta)
{
	// Turn.
	m_Angle += -m_Controls.x * TURN_SPEED * delta;
		
	// Move.
	float acceleration = m_Controls.y * ACCELERATION_RATE;
	float angleRadians = Math::DegreesToRadians( m_Angle );
	Vector2 dir = Vector2( cos(angleRadians), sin(angleRadians) );
	m_Velocity += dir * acceleration * delta;
	m_Position += m_Velocity * delta;

	// Cap velocity.
	if( m_Velocity.Length() > MAX_VELOCITY )
	{
		m_Velocity = m_Velocity.Normalized() * MAX_VELOCITY;
	}

	// Teleport.
	if( m_Position.x < 0 )
		m_Position.x += GameDev2D::GetScreenWidth();
	if( m_Position.x >= GameDev2D::GetScreenWidth() )
		m_Position.x -= GameDev2D::GetScreenWidth();
	if( m_Position.y < 0 )
		m_Position.y += GameDev2D::GetScreenHeight();
	if( m_Position.y >= GameDev2D::GetScreenHeight() )
		m_Position.y -= GameDev2D::GetScreenHeight();
}

void Player::OnRender(BatchRenderer& batchRenderer)
{
	// Render a line strip.
	float angleRadians = (float)(m_Angle * M_PI / 180.0f);
	batchRenderer.RenderLineStrip( m_Shape, COLOR, 2, m_Position, angleRadians );
}

void Player::OnKeyEvent(KeyCode keyCode, KeyState keyState)
{
	if( keyState == KeyState::Down )
	{
		if( keyCode == KeyCode::Up || keyCode == KeyCode::W )
			m_Controls.y = 1;
		if( keyCode == KeyCode::Down || keyCode == KeyCode::S )
			m_Controls.y = -1;
		if( keyCode == KeyCode::Left || keyCode == KeyCode::A )
			m_Controls.x = -1;
		if( keyCode == KeyCode::Right || keyCode == KeyCode::D )
			m_Controls.x = 1;
	}

	if( keyState == KeyState::Up )
	{
		if( keyCode == KeyCode::Up || keyCode == KeyCode::W )
			m_Controls.y = 0;
		if( keyCode == KeyCode::Down || keyCode == KeyCode::S )
			m_Controls.y = 0;
		if( keyCode == KeyCode::Left || keyCode == KeyCode::A )
			m_Controls.x = 0;
		if( keyCode == KeyCode::Right || keyCode == KeyCode::D )
			m_Controls.x = 0;
	}
}

void Player::OnMouseButtonEvent(MouseButton button, MouseButtonState state, float mouseX, float mouseY)
{
}

void Player::OnMouseMovedEvent(float mouseX, float mouseY)
{
}

void Player::SetPosition(Vector2 pos)
{
	m_Position = pos;
}

Vector2 Player::GetPosition()
{
	return m_Position;
}

float Player::GetAngle()
{
	return m_Angle;
}

Vector2 Player::GetVelocity()
{
	return m_Velocity;
}

float Player::GetRadius()
{
	return 3.0f;
}

