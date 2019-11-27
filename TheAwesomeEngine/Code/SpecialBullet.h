//#pragma once
//#include "GameObject.h"
//#include "BezierPath.h"
//
//
//class SpecialBullet : public GameObject{
//public:
//	static void CreatePath();
//
//	SpecialBullet(float xPos, float yPos, int bezierPath, const char* path);
//
//	virtual ~SpecialBullet();
//
//	const char* _path;
//
//	int _bezierPath;
//
//	void Update();
//
//	void Render();
//
//
//private:
//
//	float lifetime = 2.f;
//
//	static std::vector<std::vector<Vector2>> sPaths;
//
//	int mCurrentPath;
//
//	int currentWayoint;
//
//	const float epsilon = 5.f;
//};