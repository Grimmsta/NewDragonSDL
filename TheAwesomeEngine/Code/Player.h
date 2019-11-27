#pragma once
#include "GameObject.h"
#include "Engine.h"
#include "Borders.h"
#include "Bullet.h"

class UIManager;

class Player :public GameObject {
public:
	enum ShootingTypes {
		Normal,
		Flamethrower, 
		Shotgun
	};

	enum SpecialAttacks {
		None, 
		Grenade,
		Missiles, 
		CircleBomb //Emmits bullets around the player
	};

	ShootingTypes _st;
	SpecialAttacks _sa;


	Player(float x, float y, ShootingTypes st, SpecialAttacks sa);
	Player(float x, float y, const char* path, ShootingTypes st, SpecialAttacks sa);

	const char* _path;

	void Update() override;
	void Render() override;

	int bulletCount = 25;

	float angle = 2*M_PI / 25.f;
	UIManager* UImanager;

	float timer = 0.f;



private:

};