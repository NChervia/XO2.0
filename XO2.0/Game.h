#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include "XO.h"
#include "SocketServer.h"
#include "SocketClient.h"

enum gameType { Null = 0, Alone = 1, Server = 2, Client = 3, Ready = 4 };

class Game
{
private:



	XO xoGame;
	SocketClient ClientS;
	SocketServer ServerS;

	sf::RenderWindow* window;//Window
	sf::Event sfmlEvent; //Event


	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;


	sf::Texture textureDesktopClean;
	sf::Texture textureButtonAlone;
	sf::Texture textureButtonServer;
	sf::Texture textureButtonClient;
	sf::Texture texturePulpit;

	sf::Texture test;
	sf::Texture textureX;
	sf::Texture textureO;
	sf::Texture textureIF;
	sf::Texture textureZero;

	sf::Font inkFree;
	sf::Text guiText;

	sf::Sprite ButtonAlone;
	sf::Sprite ButtonServer;
	sf::Sprite ButtonClient;
	sf::Sprite Won;
	sf::Sprite Pulpit;
	sf::Sprite XorO;
	std::vector <sf::Sprite> GameMap;

	gameType GameType;
	bool startBool;
	int mouseBuff;
	int mouseBuffTwo;
	int gamesStepInt;
	int gameStepIntBuff[11] = { 12,12,12,12,12,12,12,12,12,12,12 };;
	
	//Private functions
	void initWindow();
	void initVariables();
	void initSprite();
	void initTexture();
	void initFonts();
	void initText();
	void initGameMap();
	void updateGameMap();
		

public:
	//Constructor\Destructor
	Game();
	virtual ~Game();

	//Functions

	void updateMousePositions();
	void pollEvents();
	void eventVictory();


	void start();
	void updateMouseStart();
	void updateStart();
	void renderButtons(sf::RenderTarget* target);
	void renderStart();

	void buttonAlone();
	void buttonServer();
	void buttonClient();

	void textRun();
	
	void run();

	void gamesSteps(gameType num);


	int mousePress();
	
	void renderSprite(sf::RenderTarget* target);
	void renderText(sf::RenderTarget* target);
	void renderGameMap(sf::RenderTarget* target);
	void renderGameWon(sf::RenderTarget* target);
	void update();
	void render();
};

