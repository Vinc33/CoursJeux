#pragma once
#include <string>
#include "./Manager/StateManager.h"
#include "./Manager/AssetManager.h"
#include "InputManager.h"
#include "Level.h"
#include "EntityBase.h"
#include "Platform.h"
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

		void init();
		void startGame();

		static void AddEntity(EntityBase* e);

	private:
		void update();
		void updateInput();
		void updateLogic();
		void updateEvent();
		void render();

		TimeManager timeManager;

		const unsigned int FPS = 60;
		
		GameDataRef data = std::make_shared<GameData>();
		Platform* test;

		vector<EntityBase*> entities;
		static vector<EntityBase*> newEntities;
		Level level;

	};
}
