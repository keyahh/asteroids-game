#include "Animation.h"


Animation::Animation(sf::Sprite& target, sf::IntRect& rect, const std::vector<Frame>& frames, bool loop)
	: length(0), progress(0), target(target), rect(rect), loop(loop)
{
	for (auto& i : frames)
	{
		addFrame(i);
	}
}

void Animation::addFrame(const Frame& frame)
{
	frameVec.push_back(frame);
	length += frame.frameLength;
}


void Animation::playAnimation(const float& dt)
{
	progress += dt;
	float p = progress;
	for (int i = 0; i < frameVec.size(); i++)
	{
		p -= frameVec[i].frameLength;
		if (p <= 0 || &(frameVec[i]) == &frameVec.back()) //if enough time has passed for next frame or animation has reached last frame
		{
			//target.setIntRectPos(frameVec[i].rectPos);
			rect.left = frameVec[i].rectPos.x;
			rect.top = frameVec[i].rectPos.y;
			target.setTextureRect(rect);
			if (&(frameVec[i]) == &frameVec.back() && loop && p > 0)//if looping is available and last frame has been reached, reset loop
			{
				i = 0;
				continue;
			}
			break;
		}
	}

}
