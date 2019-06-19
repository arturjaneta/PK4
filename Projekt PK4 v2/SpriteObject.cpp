
#include "SpriteObject.h"


SpriteObject::SpriteObject(SpriteInfo& info, sf::Vector2f pos,Settings set) : IRenderable(),
SpriteInf(info),
CurrentFrame(0),FrameDelay(100.f), LoopAnim(true), StartFrame(0), EndFrame(0), FrameDir(1)
{
	Set = set;
	Sprite = sf::Sprite(info.Texture);
	Sprite.setScale(Set.getScale(), Set.getScale());
	RenderPosition = pos;
}


void SpriteObject::Update()
{
	Sprite.setPosition(RenderPosition);
}

void SpriteObject::Draw(sf::RenderTarget& target)
{
	if (Clock.getElapsedTime().asMilliseconds() >= FrameDelay &&
		(LoopAnim || (FrameDir == 1 && CurrentFrame != EndFrame) || (FrameDir == -1 && CurrentFrame != StartFrame)))
	{
		Clock.restart();
		CurrentFrame += FrameDir;

		if (CurrentFrame > EndFrame && FrameDir == 1 && LoopAnim)
			CurrentFrame = StartFrame;
		else if (CurrentFrame < StartFrame && FrameDir == -1 && LoopAnim)
			CurrentFrame = EndFrame;
	}

	// pozycja klatki
	int frameX = (CurrentFrame%SpriteInf.FramesPerRow)*SpriteInf.FrameDim.x;
	int frameY = (CurrentFrame / SpriteInf.FramesPerRow)*SpriteInf.FrameDim.y;

	Sprite.setTextureRect(sf::IntRect(frameX, frameY, SpriteInf.FrameDim.x, SpriteInf.FrameDim.y));

	target.draw(Sprite); 
}

void SpriteObject::setFrameLoop(int start, int stop, bool loop)
{
	LoopAnim = loop;

	if (start == StartFrame && stop == EndFrame)
		return;

	if (start <= stop)
	{
		StartFrame = start;
		EndFrame = stop;
		CurrentFrame = start;
		FrameDir = 1;
	}
	else
	{
		StartFrame = stop;
		EndFrame = start;
		CurrentFrame = start;
		FrameDir = -1;
	}
}