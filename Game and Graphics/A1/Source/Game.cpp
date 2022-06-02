#include "Game.h"

using namespace GameDev2D;

Game::Game()
{
	m_Ship = Ship();
}

Game::~Game()
{
}

void Game::OnUpdate(float delta)
{
}

void Game::OnRender(BatchRenderer& batchRenderer)
{
	batchRenderer.BeginScene();

	m_Ship.OnRender(batchRenderer);

	batchRenderer.EndScene();
}

void Game::OnKeyEvent(KeyCode keyCode, KeyState keyState)
{
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
