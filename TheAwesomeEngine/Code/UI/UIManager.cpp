#include "UIManager.h"
#include <iostream>
#include "../Engine.h"
#include <algorithm>
#include "../Code/Bullet.h"

#define MIN(v, m) ( v > m ? m : v )
#define MAX(v, M) ( v < M ? M : v )
#define CLAMP(v, min, max) MIN( MAX(v, min), max )



UIManager::UIManager()
{
	//mUIElements.push_back( std::make_unique<Entity>() );
}

UIManager::~UIManager()
{
}


void UIManager::UpdateLife()
{
	int updatedLives = numLives - 1;
	numLives = CLAMP(updatedLives, MIN_LIVES, MAX_LIVES);

	std::cout << numLives << std::endl;

}

void UIManager::UpdateScore()
{
	mScore += 100;
}

void UIManager::Update()
{
	std::cout << mScore << std::endl;
	//std::cout << numLives << std::endl;

	if (EngineGetKeyDown(Key::Up))
	{
		int updatedLives = numLives + 1;
		numLives = CLAMP(updatedLives, MIN_LIVES, MAX_LIVES);
	}

	if (EngineGetKeyDown(Key::Down))
	{
		int updatedLives = numLives - 1;
		numLives = CLAMP(updatedLives, MIN_LIVES, MAX_LIVES);
	}

	//if (bullet->EnemyHit == true)
	//{
	//	mScore += 100;
	//	bullet->EnemyHit = false;
	//}

	if (EngineGetKey(Key::Left))
	{
		mScore -= (int)(EngineGetDeltaTime() * 1000000);;
	}
}

void UIManager::Render()
{ 
	EngineSetColor(240, 20, 20);

	// Draw hearts to match numLives
	/*for (size_t i = 0; i < MAX_LIVES; i++)
	{
		int x = SCREEN_WIDTH - lifeItemSize - xMargin;
		int y = i * lifeItemSize + i * xMargin;

		if (i < numLives)
		{
			EngineRenderTexture(x, y, lifeItemSize, lifeItemSize, "RES/heart.png");
		}

		EngineRenderTexture(x, y, lifeItemSize, lifeItemSize, "Res/border.png");
	}*/



	/*for (size_t i = 0; i < MAX_LIVES; i++)
	{
		int x = 0;
		int y = 100 + i * lifeItemSize + i * xMargin;

		if (i < numLives)
		{
			EngineRenderTexture(x, y, lifeItemSize, lifeItemSize, "RES/heart.png");
		}

		EngineRenderTexture(x, y, lifeItemSize, lifeItemSize, "Res/border.png");
	}*/



	for (size_t i = 0; i < MAX_LIVES; i++)
	{
		int x = 0 + i * lifeItemSize + i * xMargin;;
		int y = 0;

		if (i < numLives)
		{
			EngineRenderTexture(x, y, lifeItemSize, lifeItemSize, "RES/heart.png");
		}

		EngineRenderTexture(x, y, lifeItemSize, lifeItemSize, "Res/border.png");
	}





	//for (size_t i = 0; i < numLives; i++)
	//{
	//	//EngineDrawRect(SCREEN_WIDTH - lifeItemSize - xMargin, i * lifeItemSize + i * xMargin, lifeItemSize, lifeItemSize);
	//	//EngineDrawRect(0, i * lifeItemSize + i * xMargin, lifeItemSize, lifeItemSize);
	//	EngineDrawRect(i * lifeItemSize + i * xMargin, 250, lifeItemSize, lifeItemSize);
	//}

	EngineSetColor(255, 255, 255);
	//EngineDrawStringFormat(0, 0, "Score: %i", mScore);
	//EngineDrawStringFormat(0, 250, "Score: %i", mScore);

	EngineDrawStringFormat(xMargin, 50, "Score: %i", mScore);
}