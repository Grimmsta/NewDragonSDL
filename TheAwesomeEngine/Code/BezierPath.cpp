//#include "BezierPath.h"
//
//BezierPath::BezierPath() {
//
//}
//
//BezierPath::~BezierPath() {
//
//}
//
//void BezierPath::AddCurve(BezierCurve curve, int samples) {
//	maxCurves.push_back(curve);
//	maxSamples.push_back(samples);
//}
//
//void BezierPath::Sample(std::vector<Vector2>* sampledPath)
//{
//	for (int i = 0; i < maxCurves.size(); i++)
//	{
//		for (float t = 0; t <= 1.f; t+= (1.f/maxSamples[i]))
//		{
//			sampledPath->push_back(maxCurves[i].CalculateCurvePoint(t));
//		}
//	}
//
//}
