#pragma once
#include "GameWorld.h"
#include "Borders.h"
#include <SDL.h>
class GameObject
{
public:
	GameObject() {}
	GameObject(float x, float y);
	
	virtual void Update() = 0;
	virtual void Render();

	int _posX, _posY;

	
	SDL_Rect _collisionBox;

	Bounds entityBoxCollider;

	GameWorld* _gameWorld;
};
