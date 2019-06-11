// projekt pk4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Assets.h"
#include "Player.h"
#include "World.h"
#include "WorldManager.h"
#include "Pause.h"
#include "GameCreator.h"
#include "Settings.h"
#include <Windows.h>
#include <vld.h> 
#define resolution_x 1920
#define resolution_y 1080



int main()
{
	GameCreator game(resolution_x, resolution_y);
	game.RunGameLoop();
	return 0;
}

