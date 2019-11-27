#pragma once
#include <SDL.h>
#include "Key.h"
#include "UI/UIManager.h"
//#include <SDL_ttf.h>

/*CORE ENGINE METHODS*/

typedef unsigned char uint8;

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

static UIManager* _UIManager = nullptr;
static Bullet* _bullet = nullptr;

void EngineInitialize();

void EngineUpdate();

void EngineClear();

void EngineClose();

void EngineDestroy();

bool EngineIsOpen();

void EngineRenderSquare(float posX, float posY, int width, int height);

float EngineGetDeltaTime();

bool EngineGetKey(Key key);

bool EngineGetKeyDown(Key key);

void EngineRenderTexture(float posX, float posY, int height, int width, const char* path);

UIManager* GetUIManager();

void SetUIManager(UIManager* uim);

//Additional

void EngineSetColor(uint8 Red, uint8 Green, uint8 Blue);

void EngineSetColor(unsigned int Color);

void EngineDrawRect(int X, int Y, int Width, int Height);

void EngineDrawString(int X, int Y, const char* String);

void EngineDrawStringFormat(int X, int Y, const char* String, ...);

