#include <iostream>
#include <vector>
#include <string>
#include "../Utils.h"
#include "AssetManager.h"



map<string, Texture> AssetManager::textureInfo = map<string, Texture>();
map<string, Font> AssetManager::fontInfo = map<string, Font>();

AssetManager::AssetManager() {}
AssetManager::~AssetManager(){}

void AssetManager::init()
{
	preLoadSprite("../MetroidVania/MetroidVaniaSprite.txt");
}
void AssetManager::loadFromLevel(LevelInfo levelInfo)
{
	string fileName = getNameFile(levelInfo);
}

void AssetManager::loadTexture(string name, string fileName)
{
	Texture texture;

	if (texture.loadFromFile(fileName))
	{
		textureInfo[name] = texture;
	}	
}

Texture &AssetManager::getTexture(string name)
{
	return textureInfo.at(name);
}

void AssetManager::loadFont(string name, string fileName)
{
	Font font;

	if (font.loadFromFile(fileName))
	{
		fontInfo[name] = font;
	}
}

Font &AssetManager::getFont(string name)
{
	return fontInfo.at(name);
}

string AssetManager::getNameFile(LevelInfo levelInfo)
{
	string fileName = "";

	switch (levelInfo)
	{
		case LevelInfo::levelIntro: fileName = "levelIntro.txt"; break;
	}
	return fileName;
}

void AssetManager::preLoadSprite(const string& fileName)
{
	string fileInfo = Utils::readFromFile(fileName);
	vector<string> info = Utils::split(fileInfo, '|');
	for each (string infoMap in info)
	{
		int spaceNo = infoMap.find(' ');
		string fileName = infoMap.substr(0, spaceNo);
		string mapName = infoMap.substr(spaceNo+1, infoMap.size());

		Texture texture; 
		texture.loadFromFile(fileName);
		textureInfo.insert( {mapName,texture} );
	}
}

