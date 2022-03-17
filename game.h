#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include "Player.h"
#include "Tile.h"
#include "TileMap.h"
// Class, that acts like game engine???
class Game
{
public:
	//variables:
	float screenHeight;
	float screenWidth;
	int level = 1;
private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	//World
	//TileMap* world;
	//Player
	Player* player;
	Tile* tile;
	TileMap* tileMap;
	int canJump;
	//Game objects
	sf::Sprite star;
	sf::Texture texture;
	float velocity = 0.f;
	float velocityY=0.f;
	sf::Vector2f vel;
	sf::Sprite deathCom;
	sf::Texture deathComTexture;
	sf::Sprite winCom;
	sf::Texture winComTexture;
	//private functions
	void initVariables();
	void initWindow();
	void initPlayer();
	void initStar();
	void renderWorld();
	void initWorld(int level);
	



public:	
	//constuctor & destructor
		Game();
		~Game();
		bool alive = 1;
		bool win = 0;
		//Accessors
		void whileDead();
		void whileWin();
		const bool running() const;

		//functions
		void pollEvents();
		void updateInput();
		void updateCollisions();
		void update();
		void render();
		void initDeathCom();
		void initWinCom();
		void starCollision();
		void loadNextLevel();
};

