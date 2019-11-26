#pragma once
#include<vector>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Manager/AssetManager.h"


using namespace sf;
using namespace std;

namespace GameView
{
	class Level
	{

	public:
		Level();
		~Level();

		// charge les sprites pour le backGround et le playGround
		void init();

		void drawBackGround(sf::RenderTarget& target);
		void drawPlayGround(sf::RenderTarget& target);

	private:

		vector<sf::Sprite> backGround;
		vector<vector<vector<sf::Sprite>>> playGround;

		Vector2i currentPos;
		int layerSize;

	};
}

