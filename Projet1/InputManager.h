#pragma once
#include "InputMap.h"
#include "EnumInput.h"
#include <vector>

using namespace std;

class InputManager
{
public:
	InputManager();
	~InputManager();

	static void init();

	static void update();

	static bool getKeyState(int playerID, INPUT key);

private:
	static vector<InputMap*> players;
};

