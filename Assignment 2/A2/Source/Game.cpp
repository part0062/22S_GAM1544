#include "Game.h"

const int Game::NUM_ASTEROIDS = 20;

using namespace GameDev2D;

Game::Game() :
	m_Bullet(nullptr)
{
	// Create a player.
	m_pPlayer = new Player();
	m_pPlayer->SetPosition( Vector2( GameDev2D::GetScreenWidth()/2.0f, GameDev2D::GetScreenHeight()/2.0f ) );

	// Fill a vector with asteroids.
	for( int i=0; i<NUM_ASTEROIDS; i++ )
	{
		Asteroid* pAsteroid = new Asteroid();
		m_Asteroids.push_back( pAsteroid );
	}
}

Game::~Game()
{
	// Delete all objects.
	delete m_pPlayer;
	for( Asteroid* pAsteroid : m_Asteroids )
	{
		delete pAsteroid;
	}

	if (m_Bullet != nullptr)
	{
		delete m_Bullet;
	}
}

void Game::OnUpdate(float delta)
{
	// Update the player and asteroids.
	m_pPlayer->OnUpdate( delta );
	for( Asteroid* pAsteroid : m_Asteroids )
	{
		pAsteroid->OnUpdate( delta );
		if (m_Bullet != nullptr){
			if (CollisionCheck(pAsteroid->GetPosition(), m_Bullet->GetPosition(), pAsteroid->GetRadius(), m_Bullet->GetRadius())) {
				delete pAsteroid;
				delete m_Bullet;
			}
		}
	}

	if (m_Bullet != nullptr)
	{
		m_Bullet->OnUpdate(delta);
	}
}

void Game::OnRender(BatchRenderer& batchRenderer)
{
	batchRenderer.BeginScene();

	// Render the player and asteroids.
	m_pPlayer->OnRender( batchRenderer );
	for( Asteroid* pAsteroid : m_Asteroids )
	{
		pAsteroid->OnRender( batchRenderer );
	}

	if (m_Bullet != nullptr)
	{
		m_Bullet->OnRender(batchRenderer);
	}

	batchRenderer.EndScene();
}

void Game::OnKeyEvent(KeyCode keyCode, KeyState keyState)
{
	if( keyCode == KeyCode::Escape )
	{
		Application::Get().Quit();
	}

	if (keyCode == KeyCode::Space && keyState == KeyState::Down)
	{
		m_Bullet = new Bullet(m_pPlayer->GetPosition());
		m_Bullet->SetAngle(m_pPlayer->GetAngle());
		m_Bullet->SetVelocity(m_pPlayer->GetVelocity());
	}

	// Send key events to the player.
	m_pPlayer->OnKeyEvent( keyCode, keyState );
}

void Game::OnMouseButtonEvent(MouseButton button, MouseButtonState state, float mouseX, float mouseY)
{		
}

void Game::OnMouseMovedEvent(float mouseX, float mouseY)
{
}


bool Game::CollisionCheck(Vector2 asteroidPos, Vector2 bulletPos, float asteroidR, float bulletR)
{
	float distance = sqrtf((bulletPos.x - asteroidPos.x) * (bulletPos.x - asteroidPos.x) + (bulletPos.y - asteroidPos.y) * (bulletPos.y - asteroidPos.y));

	return (distance <= asteroidR + bulletR);
}
