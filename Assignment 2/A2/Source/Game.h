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
	static const int NUM_BULLETS = 3;

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

	bool CollisionCheck(Asteroid* a, Bullet* b);
	bool CollisionCheck(Asteroid* a, Player* p);

	Bullet* GetBullet();
	void SpawnBullet(const Vector2& pos, const Vector2& velocity, float angle);

private:
	Player* m_pPlayer;
	std::vector<Asteroid*> m_Asteroids;
	Bullet* m_Bullets[NUM_BULLETS];

	float m_Elapsed;
};
