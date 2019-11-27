#include "Engine.h"
#include <chrono>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

struct InputState {	
	bool keyIsPressed;	
	int _frameNumber;
};

static SDL_Window* _window;
static SDL_Renderer * _renderer;
static TTF_Font* StandardFont = nullptr;

static SDL_Color _currentColor = { 255,255,255,255 };

static bool bIsOpen = true;

std::chrono::high_resolution_clock::time_point _lastFrameTime;
static float _frameDelta = 0.f;

static InputState  keyStates[(unsigned int)Key::MAX];

bool fullscreen = true;
bool windowed = false;

static float _currentFrameNumber = 1;
void EngineInitialize()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	_window = SDL_CreateWindow("THe Awesomest Engine Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, windowed);
	_renderer = SDL_CreateRenderer(_window, -1, 0);

	bIsOpen = true;

	// Load standard font
	StandardFont = TTF_OpenFont("Roboto.ttf", 24);
}

void EngineUpdate()
{
	_currentFrameNumber++;
	
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			EngineClose();
		}

		if (event.type == SDL_KEYDOWN){
			if (event.key.repeat == 0)
			{
				InputState& state = keyStates[event.key.keysym.scancode];
				state.keyIsPressed = true;
				state._frameNumber = _currentFrameNumber;
			}
		}
		if (event.type == SDL_KEYUP)
		{
			InputState& state = keyStates[event.key.keysym.scancode];
			state.keyIsPressed = false;
			state._frameNumber = _currentFrameNumber;
		}
	}
	std::chrono::high_resolution_clock::time_point currentTime = std::chrono::high_resolution_clock::now();
	_frameDelta = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - _lastFrameTime).count() * 1e-6f;//10 up the 6th  microsends in a second

	_lastFrameTime = currentTime;

	SDL_RenderPresent(_renderer);
	EngineClear();

	SDL_Delay(5);
}

void EngineClear()
{
	SDL_SetRenderDrawColor(_renderer, 136, 0, 255, 255);
	SDL_RenderClear(_renderer);
}

void EngineClose()
{
	bIsOpen = false;
}


void EngineDestroy()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();
}

bool EngineIsOpen()
{
	return bIsOpen;
}

void EngineRenderSquare(float posX, float posY, int width, int height)
{
	SDL_SetRenderDrawColor(_renderer, _currentColor.r, _currentColor.g, _currentColor.b, _currentColor.a);
	SDL_FRect Square = { posX, posY, width, height };
	SDL_RenderFillRectF(_renderer, &Square);
}

float EngineGetDeltaTime()
{
	return _frameDelta;
}

bool EngineGetKey(Key key)
{
	return keyStates[(int)key].keyIsPressed;
}

bool EngineGetKeyDown(Key key)
{
	InputState& state = keyStates[(int)key];
	return state.keyIsPressed && state._frameNumber == _currentFrameNumber;
}

void EngineRenderTexture(float posX, float posY, int height, int width, const char* path)
{
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* tempSurface = IMG_Load(path);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, tempSurface);

	if (path == nullptr) {
		puts("failed to find path!");
	}

	SDL_Rect dest = { posX, posY, width, height };
	SDL_Rect src = { 0,0, tempSurface->w, tempSurface->h };

	SDL_RenderCopy(_renderer, texture, &src, &dest);

	SDL_FreeSurface(tempSurface);
	SDL_DestroyTexture(texture);
}

UIManager* GetUIManager()
{
	return _UIManager;
}

void SetUIManager(UIManager* uim)
{
	_UIManager = uim;
}

//Additional

// Text stuff


void EngineSetColor(uint8 Red, uint8 Green, uint8 Blue)
{
	_currentColor.r = Red;
	_currentColor.g = Green;
	_currentColor.b = Blue;
	_currentColor.a = 255;
}

void EngineSetColor(unsigned int Color)
{
	_currentColor.r = (Color >> 24) & 0xFF;
	_currentColor.g = (Color >> 16) & 0xFF;
	_currentColor.b = (Color >> 8) & 0xFF;
	_currentColor.a = Color & 0xFF;
}

void EngineDrawRect(int X, int Y, int Width, int Height)
{
	SDL_SetRenderDrawColor(_renderer, _currentColor.r, _currentColor.g, _currentColor.b, _currentColor.a);

	SDL_Rect rect = { X, Y, Width, Height };
	SDL_RenderFillRect(_renderer, &rect);
}

void EngineDrawString(int X, int Y, const char* String)
{
	// Render text onto surface
	SDL_Surface* MsgSurface = TTF_RenderText_Solid(StandardFont, String, _currentColor);
	SDL_Texture* MsgTexture = SDL_CreateTextureFromSurface(_renderer, MsgSurface);

	// Find out dimensions
	int MsgW = 0, MsgH = 0;
	TTF_SizeText(StandardFont, String, &MsgW, &MsgH);

	// Copy that bad boy
	SDL_Rect MessageRect = { X, Y, MsgW, MsgH };
	SDL_RenderCopy(_renderer, MsgTexture, NULL, &MessageRect);

	// Remember to clean up
	SDL_FreeSurface(MsgSurface);
	SDL_DestroyTexture(MsgTexture);
}

void EngineDrawStringFormat(int X, int Y, const char* String, ...)
{
	static char Buffer[1024];

	// Vararg lists, scary stuff
	va_list vl;
	va_start(vl, String);
	vsprintf_s<1024>(Buffer, String, vl);
	va_end(vl);

	EngineDrawString(X, Y, Buffer);
}

