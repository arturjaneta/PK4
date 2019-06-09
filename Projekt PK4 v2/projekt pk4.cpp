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
#include <Windows.h>
#include <vld.h> 

int main()
{
	GameCreator game;
	game.RunGameLoop();
	return 0;
}

