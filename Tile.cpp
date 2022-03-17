#include "Tile.h"



void Tile::initSprite(std::string TextureName,float x,float y)
{	
	//init Texture
	if (!texture.loadFromFile(TextureName))
		std::cout << "Error loading Tile File." << std::endl;
	//init Sprite
	pos = sf::Vector2f(x, y);
	sprite.setTexture(texture);
	sprite.setPosition(pos);
}
//Rendering tiles
void Tile::render(sf::RenderTarget& target)
{	
	target.draw(this->sprite);
}


Tile::Tile(std::string textureName, float x, float y, int isPassable)
{
	initSprite(textureName,x,y);
	tileType = isPassable;
}

Tile::~Tile()
{
}
const sf::Sprite& Tile::getshape()
{
	return this->sprite;
}