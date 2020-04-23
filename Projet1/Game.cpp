#include "Game.h"

//assignation de variables statiques
std::vector<vector<EntityBase*>> GameView::Game::newEntities = std::vector<vector<EntityBase*>>();

namespace GameView
{
	Game::Game(int width, int height, string titleScreen)
	{
		data->window.setVerticalSyncEnabled(true);
		data->window.create(VideoMode(width, height), titleScreen, Style::Close | Style::Titlebar);
	}

	Game::~Game()
	{
		for (auto a : entities)
			for (auto e : a)
				delete e;
		delete camera;
	}

	void Game::init()
	{
		data->window.setFramerateLimit(FPS);
		AssetManager::init();
		InputManager::init();
		level.init();

		for (unsigned int i = 0; i < NBOFCOLLISIONLAYER; i++)
		{
			entities.push_back({});
			newEntities.push_back({});
		}

		camera = new ViewManager({ (float)data->window.getSize().x,(float)data->window.getSize().y });
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

		//Collision Logic
		for (CollisionRule cr : collisionRules)
		{
			for (EntityBase* e1 : entities[cr.layer1])
			{
				for (EntityBase* e2 : entities[cr.layer2])
				{
					if (e1->getHitBox()->intersects(*(e2->getHitBox())))
					{
						e1->onCollision(e2);
						e2->onCollision(e1);
					}
				}
			}
		}
	}

	void Game::update()
	{
		while (data->window.isOpen())
		{
			cout << endl;
			timeManager.update();

			updateInput();
			updateEvent();
			updateLogic();

			render();
		}
	}

	void Game::updateInput()
	{
		//Update chaque "Entity"
		for (auto a : entities)
			for (EntityBase* e : a)
				e->update();

		//Rajoute a "entities" celles spawner pendant l'Update
		int i = 0;
		for (auto a : entities)
		{
			entities[i].insert(entities[i].end(), newEntities[i].begin(), newEntities[i].end());
			newEntities[i] = vector<EntityBase*>();
			i++;
		}
	}

	void Game::startGame()
	{
		update();
	}

	//statique, permet d'ajouter de nouvelles "Entity" à partir de n'importe quelle classe.  GameView::Game::AddEntity(myEntity);
	void Game::AddEntity(EntityBase * e, unsigned int layer)
	{
		newEntities[layer].push_back(e);
	}

	void Game::ResetCollision()
	{
		collisionRules = vector<CollisionRule>();
	}

	void Game::AddCollisionBetweenLayers(unsigned int layer1, unsigned int layer2)
	{
		collisionRules.push_back({ layer1, layer2 });
	}

	EntityBase * Game::getEntity(unsigned layer, unsigned index)
	{
		return entities[layer][index];
	}

	void Game::render()
	{
		data->window.clear(Color::Black);

		data->window.setView(*camera->getView());
		camera->update();

		level.drawPlayGround(data->window);

		for (auto a : entities)
			for (EntityBase* e : a)
			{
				e->draw(data->window);
				//e->drawHitBox(data->window);
			}

		data->window.display();
	}

	void Game::SATCollision(EntityBase * eb1, EntityBase * eb2)
	{

	}
}