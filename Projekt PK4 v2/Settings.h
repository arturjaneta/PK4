#pragma once

class Settings
{
	int ResolutionX;
	int ResolutionY;
	float XGravity= 0.f;
	float YGravity= 5.5* 0.0166f;
	float PlayerSpeed = 2.5;
	int FrameRate=60;
	double Scale;
public:
	Settings(int resx=1920,int resy=1080);
	int getResolutionX();
	int getResolutionY();
	float getXgravity();
	float getYgravity();
	float getPlayerSpeed();
	double getScale();
	int getFrameRate();
};