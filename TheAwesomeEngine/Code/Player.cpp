#include "Player.h"
#include "Engine.h"
#include "Key.h"
#include "Bullet.h"
#include "MathHelper.h"
#include "UI/UIManager.h"
#include <math.h>
#include <iostream>

Player::Player(float x, float y, ShootingTypes st, SpecialAttacks sa) : GameObject(x, y), _st(st), _sa(sa) {}

Player::Player(float x, float y, const char* path, ShootingTypes st, SpecialAttacks sa) : GameObject(x, y), _path(path), _st(st), _sa(sa)
{
}

Vector2 math;

void Player::Update()
{
	Bounds screenBounds = Bounds(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	timer += EngineGetDeltaTime();

	float radius = 10.f;

	float radiusX = radius * sin(0);
	float radiusY = radius * cos(0);

#pragma region BoxCollider

	entityBoxCollider.x = _posX;
	entityBoxCollider.y = _posY;
	entityBoxCollider.width = 32;
	entityBoxCollider.height = 64;

#pragma endregion

	float _directionX = 0.0f;
	float _directionY = 0.0f;

	if (_directionX == 0.f && _directionY == 0.f)
	{
		_directionX++;
	}

#pragma region Input

#pragma region Movement
	Vector2 deltaMovement;
	if (EngineGetKey(Key::W))
	{
		_posY -= 10.f;
		_directionY--;
	}
	if (EngineGetKey(Key::S))
	{
		_posY += 10.f;
		_directionY++;
	}
	if (EngineGetKey(Key::D))
	{
		_posX += 10.f;
		_directionX++;
	}
	if (EngineGetKey(Key::A))
	{
		_posX -= 10.f;
		_directionX--;
	}
#pragma endregion

#pragma region BoundsChecking

	if (_posX <= screenBounds.x)
	{
		_posX = screenBounds.x;
	}
	else if (_posX + 32 >= screenBounds.width)
	{
		_posX = screenBounds.width - 32;
	}

	if (_posY <= screenBounds.y)
	{
		_posY = screenBounds.y;
	}
	else if (_posY + 64 >= screenBounds.height)
	{
		_posY = screenBounds.height - 64;
	}
#pragma endregion

#pragma region Weaponry

#pragma region ChangeWapons
	if (EngineGetKey(Key::NUM1))
	{
		_st = Normal;
	}

	if (EngineGetKey(Key::NUM2))
	{
		_st = Shotgun;
	}

	if (EngineGetKey(Key::NUM3))
	{
		_st = Flamethrower;
	}
#pragma endregion

#pragma region Firing
	if (_st != Flamethrower && EngineGetKeyDown(Key::Space))
	{
		if (_st == Normal)
		{
			_gameWorld->SpawnGameObject(new Bullet(_posX + 16, _posY + 32 * _directionY, 0, -1, "Res/FireBall (1).png", "Player"));
		}
		if (_st == Shotgun)
		{
			_gameWorld->SpawnGameObject(new Bullet(_posX + 16, _posY + 32 * _directionY, 1, -1, "Res/Bullet.png", "Player")); //To the right
			_gameWorld->SpawnGameObject(new Bullet(_posX + 16, _posY + 32 * _directionY, 0, -1, "Res/Bullet.png", "Player")); //Straight
			_gameWorld->SpawnGameObject(new Bullet(_posX + 16, _posY + 32 * _directionY, -1, -1, "Res/Bullet.png", "Player")); //To the left 

		}
	}
	else if (_st == Flamethrower && EngineGetKey(Key::Space))
	{
		_gameWorld->SpawnGameObject(new Bullet(_posX + 16, _posY + 32 * _directionY, 0, -1, "Res/FireBall (1).png", "Player"));
	}

	if (_sa == CircleBomb && EngineGetKeyDown(Key::Space))
	{
		for (int i = 1; i <= (bulletCount - 1) * 0.5; i++)
		{
			_gameWorld->SpawnGameObject(new Bullet(_posX, _posY, cos(i * angle), sin(i * angle), "Res/Bullet.png", "Player"));
			_gameWorld->SpawnGameObject(new Bullet(_posX, _posY, cos(-i * angle), sin(-i * angle), "Res/Bullet.png", "Player"));

		}
	}
#pragma endregion
#pragma endregion

#pragma endregion Input

	entityBoxCollider.x = _posX;
	entityBoxCollider.y = _posY;
}

void Player::Render()
{
	if (_path) {
		EngineRenderTexture(_posX, _posY, 64, 64, _path);
	}
	else {
		EngineRenderSquare(_posX, _posY, 64, 64);
	}
}

