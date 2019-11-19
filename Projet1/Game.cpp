#include "Game.h"

//for tests
#include "Hunter.h"
#include "Monk.h"
#include "Rogue.h"
#include <iostream>

using namespace std;

namespace GameView
{
	Game::Game(int width, int height, string titleScreen)
	{
		data->window.setVerticalSyncEnabled(true);
		data->window.create(VideoMode(width, height), titleScreen, Style::Close | Style::Titlebar);
		InputManager inputManager;
		inputManager.Initiate();
		myTexture.loadFromFile("Image/image.png");

		//myEntity = new MyEntity(&myTexture, sf::Vector2u(3, 2), 0.001f, 0.01f);
		//Tileset entityTileset = {};
		//entity = new Entity();
		//entities.push_back(new Hunter());
		//entities.push_back(new Monk());
		entities.push_back(new Rogue());
		entities[0]->setPosition(data->window.getSize().x / 2 - entities[0]->animator.GetSprite()->getLocalBounds().width / 2, data->window.getSize().y / 2 - entities[0]->animator.GetSprite()->getLocalBounds().height / 2);

		test = new Platform(&myTexture, Vector2f(10.0f, 10.0f), Vector2f(20.0f, 20.0f));
		//myEntity = new MyEntity(&myTexture,sf::Vector2f(20.0f,45.0f), sf::Vector2u(3, 2), 0.001f, 0.1f);
	}

	Game::~Game()
	{
		for (Entity* e : entities)
			delete e;
	}

	void Game::init()
	{
		data->window.setFramerateLimit(FPS);
		data->assetManager.init();
		level.init(data->assetManager);
	}

	void Game::updateEvent()
	{
		Event event;
		// passe tous les events avant de continuer 
		while (data->window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				data->window.close();

			//data->inputManager.update(event);
			//myEntity->updateInput((float)FPS,true);
		}
	}

	void Game::updateLogic()
	{
	}
	void Game::update()
	{
		//float currentTime = 0, frameTime = 0.0, interpolation =0.0f;
		while (data->window.isOpen())
		{
			timeManager.Update();

			updateInput();
			updateEvent();
			updateLogic();

			render();
		}
	}

	void Game::updateInput()
	{
		for (Entity* e : entities)
		{
			e->Update();
		}
	}

	void Game::startGame()
	{
		update();
	}

	void Game::render()
	{
		data->window.clear(Color::Black);
		
		level.drawPlayGround(data->window);
		
		for (Entity* e : entities)
		{
			e->Draw(data->window);
		}

		/*myEntity->draw(data->window);
		test->Draw(data->window);*/

		data->window.display();
	}
}