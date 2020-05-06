#include "Level.h"
#include "LevelLoader.h"


namespace GameView
{

	Level::Level():layerSize(3)
	{
		currentPos = Vector2i(0, 0);
	}


	Level::~Level()
	{
	}
	
	void Level::init()
	{
		LevelLoader loader;
		//TODO: Receive the level in param
		vector<vector<vector<TileIdentity>>> levelInfo = loader.LoadFromFile("Level/Church_for_test.lvl");
		int tileSize = 16;
		int scale = 1;
		for(int i = 0; i < levelInfo.size(); i++)
		{	
			playGround.push_back(vector<vector<Sprite>>());
			for (int j = 0; j < levelInfo[i].size(); j++ )
			{
				playGround[i].push_back(vector<Sprite>());
				for(int k = 0; k < levelInfo[i][j].size(); k++)
				{
					if (levelInfo[i][j][k].Tileset != "")
					{
						Texture& text = AssetManager::getTexture(levelInfo[i][j][k].Tileset);
						Sprite sp;
						sp.setTexture(text);
						int left = levelInfo[i][j][k].IndexesX[0]* tileSize;
						int top = levelInfo[i][j][k].IndexesY[0]* tileSize;
						
						sp.setTextureRect(IntRect(left,top , tileSize, tileSize));
						sp.scale(Vector2f((float)scale, (float)scale));
						sp.setPosition(Vector2f(j*(tileSize *scale),k*(tileSize* scale)));
						playGround[i][j].push_back(sp);;
					}
				}
			}
		}
	}

	void Level::drawBackGround(sf::RenderTarget& target)
	{
		vector<sf::Sprite>::iterator it;
		for (it = backGround.begin(); it != backGround.end(); it++)
		{
			target.draw((*it));
		}
	}

	void Level::drawPlayGround(sf::RenderTarget& target)
	{
		for (int i = 0; i < playGround.size(); i++)
		{
			for (int j = 0; j < playGround[i].size(); j++)
			{
				for (int k = 0; k < playGround[i][j].size(); k++)
				{
					target.draw(playGround[i][j][k]);
				}
			}
		}
	}
}
