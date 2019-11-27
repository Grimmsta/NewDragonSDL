#include "Bullet.h"
#include "Engine.h"
#include "Type.h"
#include "Enemy.h"
#include "Player.h"
#include "Enemy01.h"
#include "Borders.h"
#include "Collision.h"
#include <SDL.h>
#include <iostream>

void Bullet::Update()
{

	Bounds screenBounds = Bounds( 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	_posX += BULLET_SPEED * _dirX;
	_posY += BULLET_SPEED * _dirY;

	entityBoxCollider.x = _posX;
	entityBoxCollider.y = _posY;
	entityBoxCollider.width = BULLET_WIDTH;
	entityBoxCollider.height = BULLET_HEIGHT;

	lifetime -= 0.1f;
	for (int i = 0; i < MAX_GAME_OBJECTS; i++)
	{
		GameObject* goPtr = _gameWorld->Objects[i];
		if (goPtr == nullptr || goPtr == this)
		{
			continue;
		}

		if (IsA<Enemy01>(goPtr) && _tag != "Enemy") {
		
			if (entityBoxCollider.CollidesWith(goPtr->entityBoxCollider)) {
				_gameWorld->DestroyGameObjetc(goPtr);
					_UImanager->UpdateScore();
		
				_gameWorld->DestroyGameObjetc(this);

				return;
			}
		}
	

		if (IsA<Player>(goPtr) && _tag != "Player" )
		{
			if (entityBoxCollider.CollidesWith(goPtr->entityBoxCollider))
			{
				_UImanager->UpdateLife();
				if (_UImanager->numLives <=0)
				{
					_gameWorld->DestroyGameObjetc(goPtr);
				}
				_gameWorld->DestroyGameObjetc(this);
				return;
			}
		}

	}


	//if (lifetime <= 0)
	//{
	//	_gameWorld->DestroyGameObjetc(this);
	//	return;
	//}
	if (_posX <= screenBounds.x)
	{
		_gameWorld->DestroyGameObjetc(this);
		return;
	}
	else if (_posX + 32 >= screenBounds.width)
	{
		_gameWorld->DestroyGameObjetc(this);
		return;
	}

	if (_posY <= screenBounds.y)
	{
		_gameWorld->DestroyGameObjetc(this);
		return;
	}
	else if (_posY + 64 >= screenBounds.height)
	{
		_gameWorld->DestroyGameObjetc(this);
		return;
	}
}

void Bullet::Render()
{
	if (_path)
	{
		EngineRenderTexture(_posX, _posY, 30, 30, _path);
	}
	else
	{
		EngineRenderSquare(_posX, _posY, 20, 20);
	}

}

bool Bullet::CheckCollision(SDL_Rect a, SDL_Rect b)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	/*calculate a*/
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	/*B*/
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	if (bottomA  <= topB)
	{
		return false;
	}
	if (topA >= bottomB)
	{
		return false;
	}
	if (rightA <= leftB)
	{
		return false;
	}
	if (leftA >= rightB)
	{
		return false;
	}

	return true;
}
