#include "Game.h"

//for tests
#include "Hunter.h"
#include "Monk.h"
#include "Pingouin.h"
#include "Rogue.h"
#include "Hero.h"

std::vector<EntityBase*> GameView::Game::newEntities = std::vector<EntityBase*>();
std::vector<EntityBase*> GameView::Game::entitiesForCollision = std::vector<EntityBase*>();
namespace GameView
{

	Game::Game(int width, int height, string titleScreen)
	{
		data->window.setVerticalSyncEnabled(true);
		data->window.create(VideoMode(width, height), titleScreen, Style::Close | Style::Titlebar);
		InputManager inputManager;
		inputManager.Initiate();

		//myEntity = new MyEntity(&myTexture, sf::Vector2u(3, 2), 0.001f, 0.01f);
		//Tileset entityTileset = {};
		//entity = new Entity();
		//entities.push_back(new Hunter());
		//entities.push_back(new Monk());
		//entities.push_back(new Rogue());
		
		
		AddEntity(new Hunter());
		AddEntity(new Monk());
		AddEntity(new Rogue());

		sf::Texture* texture = new sf::Texture();
		texture->loadFromFile("Assets/ToolAndMagic/ThrownAxe.png");
		test = new Platform(texture, Vector2f(100.0f, 50.0f), Vector2f(200.0f, 300.0f));
	}

	Game::~Game()
	{
		for(auto ent : entities)
		{
			delete ent;
		}
	}

	void Game::init()
	{
		data->window.setFramerateLimit(FPS);
		AssetManager::init();
		level.init();
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
		for (EntityBase* e : entitiesForCollision) {
			if (test->hitbox->checkCollision((dynamic_cast<EntityCollision*>(e))->GetCollider(), 1.0f))
				cout << "collision" << endl;

			cout << "pas de collision" << endl;
		}
		entitiesForCollision = vector<EntityBase*>();
	}

	void Game::update()
	{
		while (data->window.isOpen())
		{
			timeManager.update();

			updateInput();
			updateEvent();
			updateLogic();

			render();
		}
	}

	void Game::updateInput()
	{
		for (EntityBase* e : entities)
			e->update();

		entities.insert(entities.end(), newEntities.begin(), newEntities.end());
		newEntities = std::vector<EntityBase*>();
	}

	void Game::startGame()
	{
		update();
	}

	void Game::AddEntity(EntityBase * e)
	{
		e->init();
		newEntities.push_back(e);
	}
	void Game::AddForCheckCollision(EntityBase * e)
	{
		entitiesForCollision.push_back(e);
	}

	void Game::render()
	{
		data->window.clear(Color::Black);

		level.drawPlayGround(data->window);

		for (EntityBase* e : entities)
			e->draw(data->window);

		test->draw(data->window);
		data->window.display();
	}
}