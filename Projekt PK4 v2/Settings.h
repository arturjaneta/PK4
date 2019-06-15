#pragma once

class Settings
{
	int resolutionx;
	int resolutiony;
	float xgravity= 0.f;
	float ygravity= 5.5;
	float playerSpeed = 2.5;
	double scale;
public:
	Settings(int resx=1920,int resy=1080);
	int getResolutionX();
	int getResolutionY();
	float getXgravity();
	float getYgravity();
	float getPlayerSpeed();
	double getScale();
};