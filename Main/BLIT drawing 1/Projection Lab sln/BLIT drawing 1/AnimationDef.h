#pragma once
#include "ImageDef.h"
#include "BLITVars.h"
#include "ScreenBounds.h"
class AnimationDef : ImageDef
{
public:
	ScreenBounds frameSize;
	ScreenBounds srcSize;
	const unsigned int* src = nullptr;
	int itteration = 0;
	unsigned int NumOfFrames = 0;
	float frameRate;

	Vector2Int GetFramePosition(unsigned int frameNum)
	{
		if (frameNum > NumOfFrames) {
			std::cout << "out of frame bounds";

			return Vector2Int::Zero();
		}
		int framesWidth = (int)floor(srcSize.Width / frameSize.Width);
		Vector2Int pos = IndexToPos(frameNum, framesWidth);
		if (pos.y > floor(srcSize.Height / frameSize.Height))
		{
			return Vector2Int::Zero();
		}
		return Vector2Int(frameSize.Width * pos.x, frameSize.Height * pos.y);

	}
	AnimationDef(const unsigned int* _src, ScreenBounds _srcBound, ScreenBounds _frameBounds, float _frameRate, Vector2Int _min, Vector2Int _max, std::string _name);
private:

};

AnimationDef::AnimationDef(const unsigned int* _src, ScreenBounds _srcBound, ScreenBounds _frameBounds, float _frameRate, Vector2Int _min, Vector2Int _max, std::string _name)
{
	min = _min;
	max = _max;
	imageName = _name;
	src = _src;
	frameRate = _frameRate;
	srcSize = _srcBound;
	frameSize = _frameBounds;
	NumOfFrames = (int)floor(_srcBound.Width / _frameBounds.Width) * (int)floor(_srcBound.Height / _frameBounds.Height);
	itteration = 0;
}