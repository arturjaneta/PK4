// projekt pk4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//
#include "GameCreator.h"
#include <string>
#include <vld.h> 


int main(int argc, char ** argv)
{
	GameCreator game(std::stoi(argv[1]), std::stoi(argv[2]));
	game.RunGameLoop();
	return 0;
}

