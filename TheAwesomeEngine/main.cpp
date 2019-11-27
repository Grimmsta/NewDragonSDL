#include <SDL.h>
#include "Code/Engine.h"
#include "Code/GameObject.h"
#include "Code/Player.h"
#include "Code/Enemy.h"
#include "Code/Enemy01.h"
#include "Code/UI/UIManager.h"

bool isOpen = false;
int main(int argc, char* argv[]) {

	int FPS = 60;
	int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;


	EngineInitialize();

	SDL_Event keyEvent;
	while (EngineIsOpen()) {

		GameWorld Game;
		SetUIManager(Game.GetUIManager());

		Game.SpawnGameObject(new Player(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, "Res/Ma_Man.png", Player::Normal, Player::CircleBomb));
		
		Game.SpawnGameObject(new Enemy01(500, 300, 10, Enemy01::Circle));
		Game.SpawnGameObject(new Enemy01(500, 400, 10, Enemy::Circle));
		Game.SpawnGameObject(new Enemy01(700, 400, 10, Enemy01::Vertical));

		while (EngineIsOpen())
		{
			frameStart = SDL_GetTicks();
			EngineClear();

			Game.Update();
			Game.Render();

			//EngineRenderSquare(10.f, 10.f, 64, 64);
			
			if (EngineGetKeyDown(Key::Escape))
			{
				EngineClose();
			}

			frameTime = SDL_GetTicks() - frameStart;
			if (frameDelay > frameTime)
			{
				SDL_Delay(frameDelay - frameTime);
			}
			EngineUpdate();
		}
	}
	EngineDestroy();

	return 0;
}
