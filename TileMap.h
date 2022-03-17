#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp> 
#include "Tile.h"
class TileMap
{
public:
	TileMap(float screenHeight,float screenWidth,int level);
	~TileMap();
	std::vector<std::vector<Tile*>> map;
private:
	void initMap(float screenHeight, float screenWidth,int level);
};

