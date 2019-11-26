#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System/FileInputStream.hpp>


using namespace std;
using namespace sf;

enum LevelInfo
{
	levelIntro = 0
};


struct TextureInfo
{
	string path;
	string name;
	Vector2i size;
	Vector2i pos;
};

class AssetManager
{
public:
	AssetManager();
	~AssetManager();

	static void init();
	static void loadFromLevel(LevelInfo levelInfo);

	void loadTexture(string name, string fileName);
	void loadTexture(string name, string fileName, Vector2i size, Vector2i pos);
	static Texture &getTexture(string name);

	void loadFont(string name, string fileName);
	Font &getFont(string name);

private:
	static void preLoadSprite(const string& fileName);

	vector<string> tabFileToLoad;

	static string getNameFile(LevelInfo levelInfo);
	

	static map<string,Texture> textureInfo;
	static map<string,Font> fontInfo;
};
