#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp> 
class Tile
{
private:
	
	
	sf::Texture texture;
	sf::Vector2f pos;
public:
	void initSprite(std::string TextureName,float x,float y);
	void render(sf::RenderTarget& target);
	sf::Sprite sprite;
	int tileType;
	//Constructor & Destructor
	Tile(std::string textureName,float x,float y,int isPassable);
	~Tile();

	const sf::Sprite& getshape();

};

