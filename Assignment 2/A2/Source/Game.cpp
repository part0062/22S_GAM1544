#include "Game.h"

const int Game::NUM_ASTEROIDS = 20;

using namespace GameDev2D;

Game::Game() :
	m_Bullets{},
	m_Elapsed(0.0f)
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

	// Fill array with bullets
	for (int i = 0; i < NUM_BULLETS; i++)
	{
		m_Bullets[i] = new Bullet();
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

	for (int i = 0; i < NUM_BULLETS; i++)
	{
		if (m_Bullets[i] != nullptr)
		{
			delete m_Bullets[i];
		}
	}
}

void Game::OnUpdate(float delta)
{
	// Update the player and asteroids.
	m_pPlayer->OnUpdate( delta );

	for( Asteroid* pAsteroid : m_Asteroids )
	{
		pAsteroid->OnUpdate(delta);
		
		if (m_pPlayer != nullptr)
		{
			if (CollisionCheck(pAsteroid, m_pPlayer))
			{
				m_pPlayer->SetPosition(Vector2(Math::RandomFloat(0.0f, GetScreenWidth()), Math::RandomFloat(0.0f, GetScreenHeight())));
			}
		}

		for (int i = 0; i < NUM_BULLETS; i++)
		{
			if (CollisionCheck(pAsteroid, m_Bullets[i]))
			{
				delete pAsteroid;
				pAsteroid = nullptr;

				m_Bullets[i]->SetActive(false);
			}
		}
	}

	for (int i = 0; i < NUM_BULLETS; i++)
	{
		m_Bullets[i]->OnUpdate(delta);
	}
}

void Game::OnRender(BatchRenderer& batchRenderer)
{
	batchRenderer.BeginScene();

	// Render the player and asteroids.
	m_pPlayer->OnRender( batchRenderer );

	for( Asteroid* pAsteroid : m_Asteroids )
	{
		if (pAsteroid != nullptr)
		{
			pAsteroid->OnRender(batchRenderer);
		}
	}

	for (int i = 0; i < NUM_BULLETS; i++)
	{
		m_Bullets[i]->OnRender(batchRenderer);
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
		SpawnBullet(m_pPlayer->GetPosition(), m_pPlayer->GetVelocity(), m_pPlayer->GetAngle());
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

//Collision Checking

bool Game::CollisionCheck(Asteroid* a, Bullet* b)
{
	if (a != nullptr && b != nullptr)
	{
		Vector2 bPos = b->GetPosition();
		Vector2 aPos = a->GetPosition();

		float distance = sqrtf((bPos.x - aPos.x) * (bPos.x - aPos.x) + (bPos.y - aPos.y) * (bPos.y - aPos.y));

		return (distance <= a->GetRadius() + b->GetRadius());
	}
	
	return false;
}

bool Game::CollisionCheck(Asteroid* a, Player* p)
{
	if (a != nullptr && p != nullptr)
	{
		Vector2 pPos = p->GetPosition();
		Vector2 aPos = a->GetPosition();

		float distance = sqrtf((pPos.x - aPos.x) * (pPos.x - aPos.x) + (pPos.y - aPos.y) * (pPos.y - aPos.y));

		return (distance <= a->GetRadius() + p->GetRadius());
	}
	
	return false;
}

Bullet* Game::GetBullet()
{
	for (int i = 0; i < NUM_BULLETS; i++)
	{
		if (m_Bullets[i]->IsActive() == false)
		{
			return m_Bullets[i];
		}
	}

	return nullptr;
}

void Game::SpawnBullet(const Vector2& pos, const Vector2& velocity, float angle)
{
	Bullet* bullet = GetBullet();

	if (bullet != nullptr)
	{
		bullet->Activate(pos, velocity, angle);
	}
}