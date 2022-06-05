#include "Game.h"

using namespace GameDev2D;

Game::Game():m_Ship(Ship()), m_Astroid(Astroid())
{
}

Game::~Game()
{
}

void Game::OnUpdate(float delta)
{
	m_Ship.OnUpdate(delta);
	m_Astroid.OnUpdate(delta);
}

void Game::OnRender(BatchRenderer& batchRenderer)
{
	batchRenderer.BeginScene();

	m_Ship.OnRender(batchRenderer);
	m_Astroid.OnRender(batchRenderer);

	batchRenderer.EndScene();
}

void Game::OnKeyEvent(KeyCode keyCode, KeyState keyState)
{
	m_Ship.OnKeyEvent(keyCode, keyState);

	if( keyCode == KeyCode::Escape && keyState == KeyState::Down )
	{
		Application::Get().Quit();
	}
}

void Game::OnMouseButtonEvent(MouseButton button, MouseButtonState state, float mouseX, float mouseY)
{		
}

void Game::OnMouseMovedEvent(float mouseX, float mouseY)
{
}
