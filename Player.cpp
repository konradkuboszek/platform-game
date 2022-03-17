#include "Player.h"


void Player::initTexture()
{
	if(!this->texture.loadFromFile("Textures/player.png"))
	{
		std::cout << "Error Player INITTEXTURE."<<std::endl;

	}
}
void Player::initSprite()
{
	this->sprite.setPosition(sf::Vector2f(0.f, 700.f));
	this->sprite.setTexture(this->texture);

}
//Constructor and destructor
Player::Player()
{	
	this->movementSpeed = 2.f;
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{
}
//Functions
const sf::Sprite& Player::getshape()
{
	return this->sprite;
}
float Player::getPositionX()
{
	return sprite.getPosition().x;
}
float Player::getPositionY()
{
	return sprite.getPosition().y;
}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
	//screen collision
	if (sprite.getPosition().x < 0)
		sprite.setPosition(0, sprite.getPosition().y);
	if (sprite.getPosition().y < 0)
		sprite.setPosition(sprite.getPosition().x,0);
//	if(this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width >= target->getSize().x)
}

void Player::updateWindowBoundsCollison(const sf::RenderTarget* target)
{

}

void Player::update(const sf::RenderTarget* target)
{
	this->updateWindowBoundsCollison(target);
}

void Player::render(sf::RenderTarget& target)
{	
	target.draw(this->sprite);
}
