#pragma once

class Settings
{
	int resolutionx;
	int resolutiony;
public:
	Settings(int resx=1920,int resy=1080);
	int getResolutionX();
	int getResolutionY();
};