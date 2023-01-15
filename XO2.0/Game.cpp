#include "Game.h"


void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(675, 675), "Game Life", sf::Style::Close | sf::Style::Titlebar);
}

void Game::initVariables()
{
	this->startBool = true;
	this->mouseBuff = 10;
	this->mouseBuffTwo = 10;
	this->gamesStepInt = 0;
	
}

void Game::initSprite()
{
	this->Pulpit.setTexture(this->texturePulpit);
	this->Pulpit.setPosition(0.f, 0.f);
	this->Pulpit.scale(0.9f, 0.9f);
	
	this->Won.setTexture(this->textureZero);
	this->Won.scale(4.5f, 3.5f);
	
	this->ButtonAlone.setTexture(this->textureButtonAlone);
	this->ButtonAlone.setPosition(130.f, 140.f);
	
	this->ButtonServer.setTexture(this->textureButtonServer);
	this->ButtonServer.setPosition(130.f, 270.f);
	
	this->ButtonClient.setTexture(this->textureButtonClient);
	this->ButtonClient.setPosition(130.f, 400.f);
}

void Game::initTexture()
{
	if (!this->textureDesktopClean.loadFromFile("Texture/Desktop Clean.png"))
	{
		std::cout << "Error Texture Desktop Clean.png\n";
	}
	if (!this->textureButtonAlone.loadFromFile("Texture/Alone.png"))
	{
		std::cout << "Error Texture Alone.png\n";
	}
	if (!this->textureButtonServer.loadFromFile("Texture/Server.png"))
	{
		std::cout << "Error Texture Server.png\n";
	}
	if (!this->textureButtonClient.loadFromFile("Texture/Client.png"))
	{
		std::cout << "Error Texture Client.png\n";
	}
	if (!this->texturePulpit.loadFromFile("Texture/Pulpit.png"))
	{
		std::cout << "Error Texture Pulpit.png\n";
	}
	if (!this->test.loadFromFile("Texture/Test.png"))
	{
		std::cout << "Error Texture Test.png\n";
	}
	if (!this->textureX.loadFromFile("Texture/X.png"))
	{
		std::cout << "Error Texture X.png\n";
	}
	if (!this->textureO.loadFromFile("Texture/O.png"))
	{
		std::cout << "Error Texture O.png\n";
	}
	if (!this->textureZero.loadFromFile("Texture/Zero.png"))
	{
		std::cout << "Error Texture Zero.png\n";
	}
}

void Game::initFonts()
{
	if (!this->inkFree.loadFromFile("Fonts/inkfree.ttf"))
	{
		std::cout << "Error Font inkfree.ttf\n";
	}
}

void Game::initText()
{
	this->guiText.setFont(this->inkFree);
	this->guiText.setFillColor(sf::Color::White);
	this->guiText.setCharacterSize(100);
	this->guiText.setPosition(90.f, 250.f);
	this->guiText.setOutlineThickness(1.f);
	this->guiText.setOutlineColor(sf::Color::White);
	this->guiText.setString("Connection...");
}

void Game::initGameMap()
{
	this->XorO.setTexture(this->textureZero);
	this->XorO.scale(0.8f, 0.8f);
	
	this->XorO.setPosition(110.f, 90.f);  //110 - 235   90 - 235
	this->GameMap.push_back(this->XorO);
	this->XorO.setPosition(285.f, 90.f);  //285 - 410   90 - 235
	this->GameMap.push_back(this->XorO);
	this->XorO.setPosition(450.f, 90.f);  //450 - 575   90 - 235
	this->GameMap.push_back(this->XorO);
	this->XorO.setPosition(110.f, 270.f); //110 - 235   270 - 415
	this->GameMap.push_back(this->XorO);
	this->XorO.setPosition(285.f, 270.f); //285 - 410   270 - 415
	this->GameMap.push_back(this->XorO);
	this->XorO.setPosition(450.f, 270.f); //450 - 575   270 - 415
	this->GameMap.push_back(this->XorO);
	this->XorO.setPosition(110.f, 445.f); //110 - 235   445 - 590
	this->GameMap.push_back(this->XorO);
	this->XorO.setPosition(285.f, 445.f); //285 - 410   445 - 590
	this->GameMap.push_back(this->XorO);
	this->XorO.setPosition(450.f, 445.f); //450 - 575   445 - 590
	this->GameMap.push_back(this->XorO);
	
	this->updateGameMap();
}

void Game::updateGameMap()
{
	for (int i = 0; i < 9; i++)
	{ 
		if (this->xoGame.getMap(i) == ' ')this->GameMap[i].setTexture(this->textureZero);
		else if (this->xoGame.getMap(i) == 'X')this->GameMap[i].setTexture(this->textureX);
		else if (this->xoGame.getMap(i) == 'O')this->GameMap[i].setTexture(this->textureO);
		else this->GameMap[i].setTexture(this->test);
	}

}




Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initTexture();
	this->initFonts();
	this->initText();
	this->initSprite();
	this->initGameMap();
	
}

Game::~Game()
{
	delete this->window;
}

void Game::updateMousePositions()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent))
	{
		switch (this->sfmlEvent.type)
		{

		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
			}
			break;
		}
	}
}

void Game::eventVictory()
{
	if (this->xoGame.finish() == ' ')return;
	else if (this->xoGame.finish() == 'X')this->guiText.setString("In this\n game,\n\"X\" won!");
	else if (this->xoGame.finish() == 'O')this->guiText.setString("In this\n game,\n\"O\" won!");
	else if (this->xoGame.finish() == 'H')this->guiText.setString("In this\n game,\n nobody \n  won!");
	else return;
	this->guiText.setPosition(150.f, 80.f);
	this->Pulpit.setTexture(textureDesktopClean);
	while (true)
	{
		this->textRun();
	}
}

void Game::start()
{
	this->Pulpit.setTexture(textureDesktopClean);

	while ((this->window->isOpen()) && (this->startBool == true))
	{
		this->updateStart();
		this->renderStart();
	}
}

void Game::updateMouseStart()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		int pozition = 10;

		if ((this->mousePosWindow.x > 130) && (this->mousePosWindow.x < 538))      pozition = 0;
		else pozition = 10;

		if ((pozition != 10) && (this->mousePosWindow.y > 140) && (this->mousePosWindow.y < 256))        pozition += 1;
		else if ((pozition != 10) && (this->mousePosWindow.y > 270) && (this->mousePosWindow.y < 386))  pozition += 2;
		else if ((pozition != 10) && (this->mousePosWindow.y > 400) && (this->mousePosWindow.y < 516))  pozition += 3;
		else pozition = 10;

		if (pozition != 10)
		{
			if (pozition == 1)this->buttonAlone();
			if (pozition == 2)this->buttonServer();
			if (pozition == 3)this->buttonClient();
		}

	}
}

void Game::updateStart()
{
	this->pollEvents();
	this->updateMousePositions();
	this->updateMouseStart();
}

void Game::renderButtons(sf::RenderTarget* target)
{
	target->draw(this->ButtonAlone);
	target->draw(this->ButtonServer);
	target->draw(this->ButtonClient);

}

void Game::renderStart()
{
	this->window->clear();
	
	this->renderSprite(this->window);
	this->renderButtons(this->window);
	this->window->display();
}

void Game::buttonAlone()
{
	Sleep(200);
	this->GameType = Alone;
	this->startBool = false;
	this->Pulpit.setTexture(this->texturePulpit);
	this->run();
}

void Game::buttonServer()
{
	this->ServerS.ServerStart();
	this->GameType = Ready;
	std::thread addCl([&]() 
		{
		this->ServerS.addClient();
		this->GameType = Server;
		});
	addCl.detach();
	while (this->GameType == Ready)
	{
		this->textRun();
	}
	std::thread SendSer([&]() 
		{
		ServerS.readClient(this->gameStepIntBuff);
		});
	SendSer.detach();
	this->GameType = Server;
	this->startBool = false;
	this->Pulpit.setTexture(this->texturePulpit);
	this->run();
}

void Game::buttonClient()
{
	this->ClientS.clientStart();
	std::thread SendCli([&]() {

		ClientS.readServer(this->gameStepIntBuff);
		});
	SendCli.detach();
	this->GameType = Client;
	this->startBool = false;
	this->Pulpit.setTexture(this->texturePulpit);
	this->run();
}

void Game::textRun()
{
	this->pollEvents();
	this->window->clear();
	this->renderSprite(this->window);
	this->renderText(this->window);
	this->window->display();
}


void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

void Game::gamesSteps(gameType num)
{

	if ((this->gamesStepInt % 2) == 0)
	{
		if ((num == 1) && (this->mouseBuff != 10))
		{

			if (this->xoGame.stepX(this->mouseBuff))
			{
				
				this->gamesStepInt++;
				this->updateGameMap();
				if (this->xoGame.finish() != ' ')std::cout << "Finish " << this->xoGame.finish() << "\n";
				return;
			}

		}
		else if ((num == 2) && (this->mouseBuff != 10))
		{
			if (this->xoGame.stepX(this->mouseBuff))
			{
				/// <summary>
				char aChar[512];
				ZeroMemory(aChar, 512);
				aChar[0] = '/';
				aChar[1] = '/';
				aChar[2] = (gamesStepInt % 10) + '0';
				aChar[3] = '-';
				aChar[4] = (mouseBuff % 10) + '0';
				this->ServerS.sendToClient(aChar);
				/// </summary>

				
				this->gamesStepInt++;
				this->updateGameMap();
				if (this->xoGame.finish() != ' ')
					std::cout << "Finish " << this->xoGame.finish() << "\n";
				return;
			}
		}
		else if ((num == 3)&&(this->gameStepIntBuff[this->gamesStepInt] != 12))
		{
			if (this->xoGame.stepX(gameStepIntBuff[this->gamesStepInt]))
			{
				
				this->gamesStepInt++;
				this->mouseBuff = 10;
				this->updateGameMap();
				if (this->xoGame.finish() != ' ')std::cout << "Finish " << this->xoGame.finish() << "\n";
				return;
			}
		}
	return;
	}
	else if ((this->gamesStepInt % 2) == 1)
	{
		if ((num == 1) && (this->mouseBuff != 10))
		{
			if (this->xoGame.stepO(this->mouseBuff))
			{
				
				this->gamesStepInt++;
				this->updateGameMap();
				if (this->xoGame.finish() != ' ')std::cout << "Finish " << this->xoGame.finish() << "\n";
				return;
			}

		}
		else if ((num == 2) && (this->gameStepIntBuff[this->gamesStepInt] != 12))
		{
			/// <summary>
			if (this->xoGame.stepO(gameStepIntBuff[this->gamesStepInt]))
			{
				
				this->gamesStepInt++;
				this->mouseBuff = 10;
				this->updateGameMap();
				if (this->xoGame.finish() != ' ')std::cout << "Finish " << this->xoGame.finish() << "\n";
				return;
			}

		}
		else if ((num == 3) && (this->mouseBuff != 10))
		{
			if (this->xoGame.stepO(this->mouseBuff))
			{
				/// <summary>
				char aChar[5];
				aChar[0] = '/';
				aChar[1] = '/';
				aChar[2] = (gamesStepInt % 10) + '0';
				aChar[3] = '-';
				aChar[4] = (mouseBuff % 10) + '0';
				this->ClientS.sendToServer(aChar);
				/// </summary>

				this->gamesStepInt++;
				this->updateGameMap();
				if (this->xoGame.finish() != ' ')std::cout << "Finish " << this->xoGame.finish() << "\n";
				return;
			}
		}
	}
	else
	{
		std::cout << "Error " << "\n";
	}
	return;

	
}

int Game::mousePress()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		int pozition = 10;

		if ((this->mousePosWindow.x > 110) && (this->mousePosWindow.x < 235))      pozition = 0;
		else if ((this->mousePosWindow.x > 285) && (this->mousePosWindow.x < 410)) pozition = 1;  //Y
		else if ((this->mousePosWindow.x > 450) && (this->mousePosWindow.x < 575)) pozition = 2;
		else return 10;

		if ((this->mousePosWindow.y > 90) && (this->mousePosWindow.y < 235))        pozition += 0;
		else if ((this->mousePosWindow.y > 270) && (this->mousePosWindow.y < 415))  pozition += 3; //X
		else if ((this->mousePosWindow.y > 445) && (this->mousePosWindow.y < 590))  pozition += 6;
		else return 10;


		if ((pozition < 10) && (this->mouseBuff != pozition))
		{
			
			    
				
				this->mouseBuff = pozition;
				return pozition;
		}


	}
	return 10;
}

void Game::renderSprite(sf::RenderTarget* target)
{
	target->draw(this->Pulpit);
}

void Game::renderText(sf::RenderTarget* target)
{
	target->draw(this->guiText);
}

void Game::renderGameMap(sf::RenderTarget* target)
{
	for (auto i : this->GameMap)
	{
		target->draw(i);
	}
}

void Game::renderGameWon(sf::RenderTarget* target)
{
	if (this->xoGame.finish() == ' ')return;
	else if (this->xoGame.finish() == 'X')this->Won.setTexture(this->textureX);
	else if (this->xoGame.finish() == 'O')this->Won.setTexture(this->textureO);
	else if (this->xoGame.finish() == 'H')this->Won.setTexture(this->textureZero);
	else return;
	target->draw(this->Won);
}



void Game::update()
{
	this->pollEvents();
	this->updateMousePositions();
	this->mousePress();
	this->gamesSteps(this->GameType);
	this->eventVictory();

}

void Game::render()
{

	this->window->clear();
	this->renderSprite(this->window);
	this->renderGameMap(this->window);
	this->renderGameWon(this->window);
	this->window->display();
}