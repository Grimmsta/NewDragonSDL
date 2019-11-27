#include "GameObject.h"
#include "Engine.h"

GameObject::GameObject(float x, float y):_posX(x), _posY(y)
{
	/*
	_posX = posX;
	_posY = posY;
	*/
}

void GameObject::Render()
{
	EngineRenderSquare(_posX, _posY, 64, 64);
}



