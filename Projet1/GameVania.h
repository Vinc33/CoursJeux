#pragma once
#include "Game.h"

namespace GameView
{
	class GameVania :
		public Game
	{
	public:
		GameVania(int width, int height, string titleScreen);
		~GameVania();

		void init();
	};
}
