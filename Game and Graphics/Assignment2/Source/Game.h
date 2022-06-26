#pragma once

#include <GameDev2D.h>
#include "Player.h"
#include "Asteroid.h"
#include "Bullet.h"

using namespace GameDev2D;

class Game
{
private:
	static const int NUM_ASTEROIDS;

public:
	Game();
	~Game();

	//Write game logic in the Update method
	void OnUpdate(float delta);

	//Render game objects in the Draw method
	void OnRender(BatchRenderer& batchRenderer);

	//Input event methods
	void OnKeyEvent(KeyCode keyCode, KeyState keyState);
	void OnMouseButtonEvent(MouseButton button, MouseButtonState state, float mouseX, float mouseY);
	void OnMouseMovedEvent(float mouseX, float mouseY);

	bool CollisionCheck(Vector2 asteroidPos, Vector2 bulletPos, float asteroidR, float bulletR);

private:
	Player* m_pPlayer;
	std::vector<Asteroid*> m_Asteroids;
	Bullet* m_Bullet;
};
