#pragma once

class Settings
{
	int ResolutionX;
	int ResolutionY;
	float XGravity= 0.f;
	float YGravity= 5.5;
	float PlayerSpeed = 2.5;
	double Scale;
public:
	Settings(int resx=1920,int resy=1080);
	int getResolutionX();
	int getResolutionY();
	float getXgravity();
	float getYgravity();
	float getPlayerSpeed();
	double getScale();
};