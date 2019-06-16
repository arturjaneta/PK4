#pragma once

#include <SFML/Graphics.hpp>

#include "IRenderable.h"
#include "SpriteInfo.h"
#include "Settings.h"

class SpriteObject : public IRenderable
{
public:
	SpriteObject(SpriteInfo& info, sf::Vector2f pos,Settings _set);
	virtual ~SpriteObject() {}

	virtual void update();
	virtual void draw(sf::RenderTarget& target);
	// Setters
	virtual void setPosition(sf::Vector2f pos) { RenderPosition = pos; }
	void setFrameLoop(int start, int stop, bool loop = true);
	// Getters
	SpriteInfo getSpriteInfo() { return _SpriteInfo; }
	sf::Sprite& getSprite() { return Sprite; }
	sf::Vector2f getRenderPosition() { return RenderPosition; }

protected:
	SpriteInfo& _SpriteInfo;
	sf::Sprite Sprite;
	sf::Vector2f RenderPosition;

	int CurrentFrame;
	sf::Clock Clock;
	float FrameDelay;
	bool mLoopAnim;
	int mStartFrame;
	int mEndFrame;
	int mFrameDir;
	Settings set;
};
