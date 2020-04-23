#include <SFML/Graphics.hpp>
#include "GameVania.h"
#include "Manager/AssetManager.h"
#include "LevelLoader.h"

using namespace sf;
using namespace GameView;

int main()
{
	string gameName = "UNNAMED VANIA GAME";
	GameVania game(800,600, gameName);

	game.init();
	game.startGame();

	return EXIT_SUCCESS;
}
