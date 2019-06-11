#include "Settings.h"



Settings::Settings(int resx,int resy)
{
	resolutionx = resx;
	resolutiony = resy;
}

int Settings::getResolutionX()
{
	return resolutionx;
}
int Settings::getResolutionY()
{
	return resolutiony;
}