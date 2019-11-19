#pragma once
#include <string>
#include "./Manager/StateManager.h"
#include "./Manager/AssetManager.h"
#include "InputManager.h"
#include "Level.h"
#include "Entity.h"
#include "Platform.h"
#include "TimeManager.h"
#include "ViewManager.h"

using namespace sf;

namespace GameView
{
	struct GameData
	{
		StateManager stateManager;
		sf::RenderWindow window;
		AssetManager assetManager;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
	public:
		Game(int width, int height, string titleScreen);
		~Game();

		void init();
		void startGame();

	private:
		void update();
		void updateInput();
		void updateLogic();
		void render();
		void updateEvent();

		TimeManager timeManager;

		const unsigned int FPS = 60;
		
		GameDataRef data = std::make_shared<GameData>();
		Platform* test;

		vector<Entity*> entities;
		ViewManager* viewCharacter;
	};
}
