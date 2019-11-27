#include "Enemy.h"
#include "Engine.h"
#include "Bullet.h"
#include <iostream>

Enemy::Enemy(float x, float y, float movementSpeed, MovementTypes mt) : GameObject(x, y), movementSpeed(movementSpeed), mt(mt)
{
	entityBoxCollider.x = x;
	entityBoxCollider.y = y;
	entityBoxCollider.width = 32;
	entityBoxCollider.height = 32;
}

void Enemy::Update()
{
	entityBoxCollider.x = _posX;
	entityBoxCollider.y = _posY;
	entityBoxCollider.width = 32;
	entityBoxCollider.height = 32;

	_directionX = 0.0f;
	_directionY = 0.0f;

	if (mt == Circle)
	{
		CircleMove();
	}
	if (mt == Horizontal)
	{
		HorizontalMove();
	}
	if (mt == Vertical)
	{
		VerticalMove();
	}
}

void Enemy::Render()
{
	EngineRenderSquare(_posX, _posY, 32, 32);
}

void Enemy::CircleMove()
{
	count++;
	angle += 0.1f;

	float x = centerPosition.x + cos(angle) * radius;
	float y = centerPosition.y + sin(angle) * radius;

	//std::cout << centerPosition.x << ", " << centerPosition.y << std::endl;

	_posX = x;
	_posY = y;

	centerPosition.y -= .8f;

	_directionY--;

	if (centerPosition.y < -100)
	{
		centerPosition.y = 650.f;
	}

	if (count > 10)
	{
		_gameWorld->SpawnGameObject(new Bullet(_posX , _posY + 10 * _directionY, -1, _directionY,"Res/Bullet.png", "Enemy"));
		_gameWorld->SpawnGameObject(new Bullet(_posX, _posY + 10 * _directionY, 0, _directionY, "Res/Bullet.png", "Enemy"));
		_gameWorld->SpawnGameObject(new Bullet(_posX , _posY + 10 * _directionY, 1, _directionY, "Res/Bullet.png", "Enemy"));

		count -= count;
	}

}


void Enemy::HorizontalMove()
{
	count++;

	if (_posX > -100.f)
	{
		_posX -= 5.f;
	}
	else
	{
		_posX = 850.f;
	}

	if (count > 30)
	{
		_directionX--;
		_gameWorld->SpawnGameObject(new Bullet(_posX + 1 * _directionX, _posY + 1 * _directionY, _directionX, _directionY, "Res/Bullet.png", "Enemy"));
		count -= count;
	}
}

void Enemy::VerticalMove()
{
	count++;

	if (_posY > -100.f)
	{
		_posY -= 5.f;
	}
	else
	{
		_posY = 650.f;
	}

	if (count > 10) //Change the 10 to a attackSpeed variable
	{
		_directionY--;
		_gameWorld->SpawnGameObject(new Bullet(_posX + 1 * _directionX, _posY + 1 * _directionY, _directionX, _directionY, "Res/Bullet.png", "Enemy"));
		count -= count;
	}
}

float Enemy::Pytha(int a, int b)
{
	float c = sqrt((a * a) + (b * b));
	return c;
}
