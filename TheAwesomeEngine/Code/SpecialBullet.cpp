//#include "SpecialBullet.h"
//#include "Engine.h"
//
//
//std::vector<std::vector<Vector2>> SpecialBullet::sPaths;
//
//void SpecialBullet::CreatePath()
//{
//	int currentPath = 0;
//	BezierPath* path = new BezierPath();
//
//	path->AddCurve({ Vector2(500.f, 10.f),Vector2(500.f, 0.f), Vector2(500.f, 310.f), Vector2(500.f, 300.f) }, 1);
//
//	sPaths.push_back(std::vector<Vector2>());
//	path->Sample(&sPaths[currentPath]);
//
//	delete path;
//}
//
//SpecialBullet::SpecialBullet(float xPos, float yPos, int bezierPath, const char* path) : GameObject(xPos, yPos), _bezierPath(bezierPath), _path(path)
//{
//	mCurrentPath = bezierPath;
//	
//	currentWayoint = 0;
//
//	mCurrentPath = xPos;
//	currentWayoint = yPos;
//
//}
//
//void SpecialBullet::Update()
//{
//
//}
//
//void SpecialBullet::Render()
//{
//	if (_path)
//	{
//		EngineRenderTexture(_posX, _posY, 30, 30, _path);
//	}
//	else
//	{
//		EngineRenderSquare(_posX, _posY, 20, 20);
//	}
//}
//
//
