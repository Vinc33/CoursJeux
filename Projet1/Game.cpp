#include "Game.h"
#include <cstdlib>
#include <vector>
#include <iostream>

//initialize static variables
std::vector<vector<EntityBase*>> GameView::Game::newEntities = std::vector<vector<EntityBase*>>();

namespace GameView
{
	Game::Game(int width, int height, string titleScreen)
	{
		data->window.setVerticalSyncEnabled(true);
		data->window.create(VideoMode(width, height), titleScreen, Style::Close | Style::Titlebar);
		camera = new ViewManager({ 0, 0 });
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
					if (SATCollision(e1, e2))
					{
						cout << "Contact";
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
			//cout << endl;
			timeManager.update();

			updateInput();
			updateEvent();
			updateLogic();

			render();
		}
	}

	void Game::updateInput()
	{
		InputManager::update();
		//Update each "Entity"
		for (auto a : entities)
			for (EntityBase* e : a)
				e->update();

		//Add "newEntities" to "entities"
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

	//static, allow new "Entity" to be spawned from anywhere.  GameView::Game::AddEntity(myEntity);
	void Game::AddEntity(EntityBase* e, unsigned int layer)
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

	EntityBase* Game::getEntity(unsigned layer, unsigned index)
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

	bool Game::SATCollision(EntityBase* eb1, EntityBase* eb2)
	{
		vector<Vector2f> points1;
		vector<Vector2f> points2;

		FloatRect* hitbox1 = eb1->getHitBox();
		FloatRect* hitbox2 = eb2->getHitBox();

		//get the minimal amount of coordinate needed to calculate the first two axes
		Transform* t = &eb1->getTransform();
		points1.push_back(t->transformPoint({ 0, 0 }));
		points1.push_back(t->transformPoint({ hitbox1->width, 0 }));
		points1.push_back(t->transformPoint({ 0, hitbox1->height }));

		vector<Vector2f> normals;
		normals.push_back({ points1[1].x - points1[0].x, points1[1].y - points1[0].y });
		normals.push_back({ points1[2].x - points1[0].x, points1[2].y - points1[0].y });

		if (eb1->getRotation() != eb2->getRotation())
		{
			//need to check all corner when the rotation is different
			points1.push_back(t->transformPoint({ hitbox1->width, hitbox1->height }));

			t = &eb2->getTransform();
			points2.push_back(t->transformPoint({ 0, 0 }));
			points2.push_back(t->transformPoint({ hitbox2->width, 0 }));
			points2.push_back(t->transformPoint({ 0, hitbox2->height }));
			points2.push_back(t->transformPoint({ hitbox2->width, hitbox2->height }));

			//on two more axes
			normals.push_back({ points2[1].x - points2[0].x, points2[1].y - points2[0].y });
			normals.push_back({ points2[2].x - points2[0].x, points2[2].y - points2[0].y });
		}
		else
		{
			//only need to check 2 opposed corner when the rotation is the same on both entities
			points1.erase(points1.begin());

			t = &eb2->getTransform();
			points2.push_back(t->transformPoint({ hitbox2->width, 0 }));
			points2.push_back(t->transformPoint({ 0, hitbox2->height }));
		}

		//projecting each points on each axis
		for (Vector2f axis : normals)
		{
			float minProj1 = DotProduct(points1[0], axis);
			float maxProj1 = DotProduct(points1[0], axis);

			float minProj2 = DotProduct(points2[0], axis);;
			float maxProj2 = DotProduct(points2[0], axis);;

			int pointsLength = size(points1);
			for (int i = 1; i < pointsLength; i++)
			{
				float currentProjection = DotProduct(points1[i], axis);

				if (minProj1 > currentProjection)
					minProj1 = currentProjection;
				else if (currentProjection > maxProj1)
					maxProj1 = currentProjection;

				currentProjection = DotProduct(points2[i], axis);

				if (minProj2 > currentProjection)
					minProj2 = currentProjection;
				else if (currentProjection > maxProj2)
					maxProj2 = currentProjection;
			}

			//break and return false if non-collision is proven (if there's a gap in the projection)
			if (maxProj2 < minProj1 || maxProj1 < minProj2)
				return false;
		}
		return true;
	}

	float Game::DotProduct(Vector2f v1, Vector2f v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}
}