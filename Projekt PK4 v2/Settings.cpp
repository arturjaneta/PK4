#include "Settings.h"



Settings::Settings(int resx,int resy)
{
	ResolutionX = resx;
	ResolutionY = resy;
	Scale = resx / 1920.0;
	XGravity *=Scale;
	YGravity *= Scale;
	PlayerSpeed *= Scale;
}

int Settings::getResolutionX()
{
	return ResolutionX;
}
int Settings::getResolutionY()
{
	return ResolutionY;
}

float Settings::getXgravity()
{
	return XGravity;
}

float Settings::getYgravity()
{
	return YGravity;
}

float Settings::getPlayerSpeed()
{
	return PlayerSpeed;
}

double Settings::getScale()
{
	return Scale;
}

int Settings::getFrameRate()
{
	return FrameRate;
}
