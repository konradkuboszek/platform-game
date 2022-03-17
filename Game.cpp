#include "Game.h"



//private functions
void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{

	screenHeight = 800;
	screenWidth = 1300;
	this->videoMode.height =screenHeight;
	this->videoMode.width = screenWidth;
	this->window = new sf::RenderWindow(this->videoMode, "Moja gra!", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initStar()
{
	texture.loadFromFile("Textures/star.png");
	star.setTexture(texture);
	this->star.setPosition(20.f, 20.f);
}
	
void Game::initWorld(int level) {
		tileMap = new TileMap(screenHeight, screenWidth,level);
	}

void Game::renderWorld() {
	for (int y = 0; y <=32; y++) {
		for (int x = 0; x <= (screenWidth/25); x++) {
			this->window->draw(tileMap->map[y][x]->sprite);
		}


	}

};
void Game::initPlayer()
{	
	this->player = new Player();
	
}
//Initing death and win comunicate  
void Game::initDeathCom()
{
	deathComTexture.loadFromFile("Textures/Gameover.png");
	deathCom.setPosition(sf::Vector2f(200.f, 300.f));
	deathCom.setTexture(deathComTexture);
	deathCom.setScale(1.5, 1.5);
}

void Game::initWinCom()
{
	winComTexture.loadFromFile("Textures/win.png");
	winCom.setPosition(sf::Vector2f(100.f, 200.f));
	winCom.setTexture(winComTexture);



}



//constructor & destructor
Game::Game() {
	this->initVariables();
	this->initWindow();
	this->initWorld(level);
	this->initDeathCom();
	this->initPlayer();
	this->initStar();
	this->initWinCom();
	

}
Game::~Game() {
	delete this->window;
	delete this->player;
	delete this->tileMap;
	
}
//Accessors
const bool Game::running() const
{	
	return this->window->isOpen();
}

//functions
void Game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close(); 
		}
	}
}
//Moving player
void Game::updateInput()
{
	
	const float gravity =0.55;
	
	int TileXleft = player->getPositionX()/25;
	int TileYup = player->getPositionY()/25;
	int TileXright = (player->getPositionX()+30)/25;
	int TileXmiddle = (player->getPositionX()+12.5)/25;
	int TileYdown = (player->getPositionY()+35)/25;
	int TileYdownDir = (player->getPositionY()+33)/25;
	int TileRightJump= (player->getPositionX() + 32)/25;
	int Tiledown= (player->getPositionY() + 39) / 25;

	float jumpHeight = -12.f;
		if (tileMap->map[Tiledown][TileRightJump]->tileType == 0)
			canJump = 2;
		if (tileMap->map[TileYdown][TileXleft]->tileType == 0)
			canJump = 2;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (tileMap->map[TileYup][TileXleft]->tileType == 1)
		if (tileMap->map[TileYdownDir][TileXleft]->tileType == 1)
			vel.x = -1.f;
	
		}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		if (tileMap->map[TileYup][TileXright]->tileType == 1)
			if (tileMap->map[TileYdownDir][TileXright]->tileType == 1)
				vel.x = 1.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		if (canJump > 0) {
			velocity += jumpHeight;
			canJump -=1;
		}
	
	if (tileMap->map[TileYdown][TileXleft]->tileType == 1)
		if (tileMap->map[TileYdown][TileXright]->tileType == 1)
			velocity += gravity;
		else velocity = 0;
	if (tileMap->map[TileYup][TileXleft]->tileType == 0)
		if(velocity<0)
			velocity = 0;
	
	this->player->move(vel.x,velocity);
	if(velocity>0)velocity =0;
	velocity *= 0.5;
	vel.x *= 0.3;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		if(level==1)
		this->player->sprite.setPosition(sf::Vector2f(0.f, 700.f));
		else if(level==2)
		this->player->sprite.setPosition(sf::Vector2f(1270.f, 100.f));
}
//Function, which checks if player have collided with spikes
void Game::updateCollisions()
{
	float tileYup = player->getPositionY();
	float tileYdown = player->getPositionY() + 35;
	float tileXleft = player->getPositionX();
	float tileXright = player->getPositionX() + 30;
	if (tileMap->map[tileYup / 25][tileXleft / 25]->tileType == 2)
		alive = 0;
	if (tileMap->map[tileYup / 25][tileXright / 25]->tileType == 2)
		alive = 0;
	if (tileMap->map[tileYdown / 25][tileXleft / 25]->tileType == 2)
		alive = 0;
	if (tileMap->map[tileYdown / 25][tileXright / 25]->tileType == 2)
		alive = 0;
}
//Function, which checks if player have collided whith star
void Game::starCollision()
{
	if (this->player->sprite.getGlobalBounds().intersects(star.getGlobalBounds()) && level == 1) {
		loadNextLevel();
	}
	if (this->player->sprite.getGlobalBounds().intersects(star.getGlobalBounds()) && level == 2)
		win = 1;
}

void Game::loadNextLevel()
{
	level += 1;
	this->initWorld(level);
	this->player->sprite.setPosition(sf::Vector2f(1270.f, 100.f));
	star.setPosition(sf::Vector2f(0.f, 625.f));


}
//State, when player is dead
void Game::whileDead()
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		if (level == 1) {
			this->player->sprite.setPosition(sf::Vector2f(0.f, 700.f));
		}
		else if (level == 2)
			this->player->sprite.setPosition(sf::Vector2f(1270.f, 100.f));
		alive = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		this->window->close();



}
//State, when game is won
void Game::whileWin()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		this->window->close();
}

//Updating game objects
void Game::update()
{	
	this->pollEvents();
	this->starCollision();
	this->updateInput();
	this->updateCollisions();
	
	
}


//Drawing elements on screen 
void Game::render()
{	
	/*	
		* -clear old fram
		* -render objects
		* -diplat frame in window
		Renderes the game objects
	*/
	this->window->clear(sf::Color(0, 255, 0, 255));
	this->renderWorld();
	if(alive==0)this->window->draw(this->deathCom);
	if(win==1)this->window->draw(this->winCom);
	this->window->draw(this->star);
	this->player->render(*this->window);
	this->window->display();
}


