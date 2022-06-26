#include "Asteroid.h"

using namespace GameDev2D;

const float Asteroid::MIN_VELOCITY = 20.0f; // Pixels per second. 
const float Asteroid::MAX_VELOCITY = 70.0f; // Pixels per second. 
const float Asteroid::MIN_ANGULAR_VELOCITY = 30.0f;  // Degrees per second.
const float Asteroid::MAX_ANGULAR_VELOCITY = 180.0f; // Degrees per second.
const int Asteroid::MIN_SIDES = 10;
const int Asteroid::MAX_SIDES = 20;
const float Asteroid::MIN_RADIUS = 10.0f;
const float Asteroid::MAX_RADIUS = 30.0f;
const Color Asteroid::COLOR = ColorList::SlateGray;

Asteroid::Asteroid()
{
	m_Angle = 0;
	m_Radius = 0.0f;

	// Create the asteroid shape.
	{
		int numSides = Math::RandomInt( MIN_SIDES, MAX_SIDES );

		float radiansPerSide = 2 * (float)M_PI / numSides;

		for( int i=0; i<numSides; i++ )
		{
			m_Radius = Math::RandomFloat( MIN_RADIUS, MAX_RADIUS );
			float angle = i*radiansPerSide;

			m_Shape.push_back( Vector2( cos(angle), sin(angle) ) * m_Radius );
		}

		m_Shape.push_back( m_Shape[0] );
	}

	// Initialize Position, along one of the 4 edges.
	// More or less 2 edges due to wrapping.
	if( Math::RandomInt( 0, 1 ) == 0 )
	{
		// Along top or bottom.
		m_Position.x = Math::RandomFloat( 0, (float)GameDev2D::GetScreenWidth() );
		m_Position.y = (float)Math::RandomInt( 0, 1 ) * GameDev2D::GetScreenHeight();
	}
	else
	{
		// Along left or right.
		m_Position.x = (float)Math::RandomInt( 0, 1 ) * GameDev2D::GetScreenWidth();
		m_Position.y = Math::RandomFloat( 0, (float)GameDev2D::GetScreenHeight() );
	}

	// Initialize velocity and angular velocity.
	float angleRadians = Math::RandomFloat( 0, (float)M_PI*2 );
	Vector2 dir = Vector2( cos(angleRadians), sin(angleRadians) );
	m_Velocity = dir * Math::RandomFloat( MIN_VELOCITY, MAX_VELOCITY );
	m_AngularVelocity = Math::RandomFloat( MIN_ANGULAR_VELOCITY, MAX_ANGULAR_VELOCITY );
}

Asteroid::~Asteroid()
{
}

void Asteroid::OnUpdate(float delta)
{
	// Turn.
	m_Angle += m_AngularVelocity * delta;

	// Move.
	m_Position += m_Velocity * delta;

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

void Asteroid::OnRender(BatchRenderer& batchRenderer)
{
	// Render the asteroid.
	float angleRadians = (float)(m_Angle * M_PI / 180.0f);
	batchRenderer.RenderLineStrip( m_Shape, COLOR, 2, m_Position, angleRadians );
}

void Asteroid::SetPosition(Vector2 pos)
{
	m_Position = pos;
}

Vector2 Asteroid::GetPosition()
{
	return m_Position;
}

float Asteroid::GetRadius()
{
	return m_Radius;
}
