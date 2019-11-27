#pragma once
#include <vector>
#include <memory>

//#include "../GameObject.h"

class Bullet;

class UIManager
{
public:
	UIManager();
	~UIManager();
	//std::vector<std::unique_ptr<GameObject>> mUIElements;

	const int MAX_LIVES = 5;
	const int MIN_LIVES = 0;

	int numLives = 5;
	int xMargin = 8;
	int lifeItemSize = 34;
	int mScore = 0;

	Bullet* bullet;

	void UpdateLife();
	void UpdateScore();

	void Update();
	void Render();
};