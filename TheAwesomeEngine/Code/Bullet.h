#pragma once
#include "GameObject.h"
#include "UI/UIManager.h"

#define BULLET_SPEED 20.F
#define BULLET_HEIGHT 20
#define BULLET_WIDTH 20

class Bullet :public GameObject {
public:

	UIManager* _UImanager;

	Bullet(float x, float y, float dirX, float dirY, const char* path, const char* tag): GameObject(x, y), _dirX(dirX), _dirY(dirY), _path(path), _tag(tag)
	{
		_UImanager = GetUIManager();
	}

	const char* _path;

	const char* _tag;

	void Update() override;
	void Render() override;

	bool CheckCollision(SDL_Rect a, SDL_Rect b);

	bool enemyHit = false;
private:
	float _dirX;
	float _dirY;

	float lifetime = 2.f;
};