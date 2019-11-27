#pragma once
#include "GameObject.h"
#include "Vector.h"

class Enemy :public GameObject {
public:
	enum MovementTypes
	{
		Circle, Horizontal, Vertical,
	};

	MovementTypes mt;

	Enemy(float x, float y, float movementSpeed, MovementTypes mt);

	void Update() override;
	void Render() override;

	float movementSpeed = 0.f;
	//moving the enemy forward in a circler pattern
	void CircleMove();

	//moving the enemy forward on the x axis
	void HorizontalMove();

	//moving the enemy forward on the y axis
	void VerticalMove();

	float Pytha(int a, int b);

	Vector Direction;
	Vector centerPosition = Vector(_posX / 2.f, _posY);
	float angle = 6.28f;
	float radius = 100.f;

	float _directionX;
	float _directionY;
	int count = 0;
	bool enemyShoot = false;
};