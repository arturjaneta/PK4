
#include "SpriteObject.h"


SpriteObject::SpriteObject(SpriteInfo& info, sf::Vector2f pos,Settings _set) : IRenderable(),
_SpriteInfo(info),
CurrentFrame(0),FrameDelay(100.f), mLoopAnim(true), mStartFrame(0), mEndFrame(0), mFrameDir(1)
{
	set = _set;
	Sprite = sf::Sprite(info.mTexture);
	Sprite.setScale(set.getScale(), set.getScale());
	RenderPosition = pos;
}


void SpriteObject::update()
{
	Sprite.setPosition(RenderPosition);
}

void SpriteObject::draw(sf::RenderTarget& target)
{
	if (Clock.getElapsedTime().asMilliseconds() >= FrameDelay &&
		(mLoopAnim || (mFrameDir == 1 && CurrentFrame != mEndFrame) || (mFrameDir == -1 && CurrentFrame != mStartFrame)))
	{
		Clock.restart();
		CurrentFrame += mFrameDir;

		if (CurrentFrame > mEndFrame && mFrameDir == 1 && mLoopAnim)
			CurrentFrame = mStartFrame;
		else if (CurrentFrame < mStartFrame && mFrameDir == -1 && mLoopAnim)
			CurrentFrame = mEndFrame;
	}

	// pozycja klatki
	int frameX = (CurrentFrame%_SpriteInfo.mFramesPerRow)*_SpriteInfo.mFrameDim.x;
	int frameY = (CurrentFrame / _SpriteInfo.mFramesPerRow)*_SpriteInfo.mFrameDim.y;

	Sprite.setTextureRect(sf::IntRect(frameX, frameY, _SpriteInfo.mFrameDim.x, _SpriteInfo.mFrameDim.y));

	target.draw(Sprite); 
}

void SpriteObject::setFrameLoop(int start, int stop, bool loop)
{
	mLoopAnim = loop;

	if (start == mStartFrame && stop == mEndFrame)
		return;

	if (start <= stop)
	{
		mStartFrame = start;
		mEndFrame = stop;
		CurrentFrame = start;
		mFrameDir = 1;
	}
	else
	{
		mStartFrame = stop;
		mEndFrame = start;
		CurrentFrame = start;
		mFrameDir = -1;
	}
}