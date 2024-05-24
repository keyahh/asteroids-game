#ifndef FRAMEH
#define FRAMEH

//#include "AnimatedSpriteSheet.h"
#include "Frame.h"
#include <vector>

class Animation
{
private:
	std::vector<Frame> frameVec;
	sf::Sprite &target;
	sf::IntRect& rect;
	float length;
	float progress;
	bool loop;

	//sf::Clock clock;

public:

	Animation(sf::Sprite& target, sf::IntRect& rect, const std::vector<Frame>& frames, bool loop = false);
	void addFrame(const Frame& frame);
	void playAnimation(const float& dt);
};

#endif