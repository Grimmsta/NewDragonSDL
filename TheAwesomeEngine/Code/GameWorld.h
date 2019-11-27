#pragma once
#include "UI/UIManager.h"
#define MAX_GAME_OBJECTS 250

class GameObject;

class GameWorld
{
public:
	GameWorld();
	~GameWorld();
	
	GameObject* Objects[MAX_GAME_OBJECTS];
	UIManager uiManager;

	void Update();
	void Render();
	UIManager* GetUIManager() { return &uiManager; }
	void SpawnGameObject(GameObject * go);
	void DestroyGameObjetc(GameObject* go);

private:

};

