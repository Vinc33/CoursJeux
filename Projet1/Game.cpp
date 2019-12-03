#include "Game.h"

//for tests
#include "Hunter.h"
#include "Monk.h"
#include "Rogue.h"
#include "MagicBullet.h"

std::vector<EntityBase*> GameView::Game::newEntities = std::vector<EntityBase*>();
namespace GameView
{

	Game::Game(int width, int height, string titleScreen)
	{
		data->window.setVerticalSyncEnabled(true);
		data->window.create(VideoMode(width, height), titleScreen, Style::Close | Style::Titlebar);
		InputManager inputManager;
		inputManager.Initiate();

		//AddEntity(new Hunter());
		AddEntity(new Monk());
		AddEntity(new Rogue());
		AddEntity(new MagicBullet());

		//test = new Platform(&myTexture, Vector2f(100.0f, 30.0f), Vector2f(200.0f, 150.0f));
	}

	Game::~Game()
	{
		std::vector<EntityBase*>::iterator it;
		for (it = entities.begin(); it != entities.end();it++)
		{
			delete *it;
		}
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
		}
	}

	void Game::updateLogic()
	{
		/*if (test->hitbox->checkCollision(myEntity->GetCollider(), 1.0f))
			myEntity->moveOnHitBox();*/
	}

	void Game::update()
	{
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
		for (EntityBase* e : entities)
			e->Update();

		entities.insert(entities.end(), newEntities.begin(), newEntities.end());
		newEntities = std::vector<EntityBase*>();
	}

	void Game::startGame()
	{
		update();
	}

	void Game::AddEntity(EntityBase * e)
	{
		newEntities.push_back(e);
	}

	void Game::render()
	{
		data->window.clear(Color::Black);

		level.drawPlayGround(data->window);

		for (EntityBase* e : entities)
			e->Draw(data->window);

		data->window.display();
	}
}