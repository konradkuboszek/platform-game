#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp> 
class Player
{
private:

	sf::Texture texture;

	float movementSpeed;

	//private functions
	void initTexture();
	void initSprite();
	
public:
	Player();
	virtual ~Player();
	sf::Sprite sprite;
	//Functions
	const sf::Sprite& getshape();
	float getPositionX();
	float getPositionY();
	void move(const float dirX, const float dirY);
	void updateWindowBoundsCollison(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget& target);
};

