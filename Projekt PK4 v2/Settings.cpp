#include "Settings.h"



Settings::Settings(int resx,int resy)
{
	resolutionx = resx;
	resolutiony = resy;
	scale = resx / 1920.0;
	xgravity *=scale;
	ygravity *= scale;
	playerSpeed *= scale;
}

int Settings::getResolutionX()
{
	return resolutionx;
}
int Settings::getResolutionY()
{
	return resolutiony;
}

float Settings::getXgravity()
{
	return xgravity;
}

float Settings::getYgravity()
{
	return ygravity;
}

float Settings::getPlayerSpeed()
{
	return playerSpeed;
}

double Settings::getScale()
{
	return scale;
}
