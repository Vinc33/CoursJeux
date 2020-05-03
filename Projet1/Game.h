#pragma once
#include <string>
#include "./Manager/StateManager.h"
#include "./Manager/AssetManager.h"
#include "./Manager/ViewManager.h"
#include "InputManager.h"
#include "Level.h"
#include "EntityBase.h"
#include "TimeManager.h"

using namespace sf;

namespace GameView
{
	struct GameData
	{
		StateManager stateManager;
		sf::RenderWindow window;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
	public:
		Game(int width, int height, string titleScreen);
		~Game();

		virtual void init();
		void startGame();

		static void AddEntity(EntityBase* e, unsigned int layer = 0);
		
		void ResetCollision();
		void AddCollisionBetweenLayers(unsigned int layer1, unsigned int layer2);

		EntityBase* getEntity(unsigned layer, unsigned index);

	private:
		void update();
		void updateInput();
		void updateLogic();
		void updateEvent();
		void render();
		bool SATCollision(EntityBase * eb1, EntityBase * eb2);

		float DotProduct(Vector2f v1, Vector2f v2);

		TimeManager timeManager;

		const unsigned int FPS = 60;
		const unsigned int NBOFCOLLISIONLAYER = 3;
		
		GameDataRef data = std::make_shared<GameData>();
		vector<vector<EntityBase*>> entities;
		static vector<vector<EntityBase*>> newEntities;

		struct CollisionRule
		{
			unsigned int layer1;
			unsigned int layer2;
		};
		vector<CollisionRule> collisionRules;

		Level level;

	protected:
		ViewManager* camera;
	};
}
