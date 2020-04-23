#pragma once
#include <iostream>
//#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>

using namespace sf;
using namespace std;

enum Keys{UP, DOWN, LEFT, RIGHT, A, B, X, Y, L1, L2, L3, R1, R2, R3, START, SELECT, LEFTAXISX, LEFTAXISY, RIGHTAXISX, RIGHTAXISY};

class InputManager
{
public:
	InputManager();
	~InputManager();

	static void init();

	static float GetAxis(Keys K);
	static bool GetKeyState(Keys K);

private:
	static vector<Keyboard::Key> keysUP;
	static vector<Keyboard::Key> keysDOWN;
	static vector<Keyboard::Key> keysLEFT;
	static vector<Keyboard::Key> keysRIGHT;
	static vector<int> buttonsUP;
	static vector<int> buttonsDOWN;
	static vector<int> buttonsLEFT;
	static vector<int> buttonsRIGHT;

	static vector<Keyboard::Key> keysA;
	static vector<Keyboard::Key> keysB;
	static vector<Keyboard::Key> keysX;
	static vector<Keyboard::Key> keysY;
	static vector<int> buttonsA;
	static vector<int> buttonsB;
	static vector<int> buttonsX;
	static vector<int> buttonsY;

	static vector<Keyboard::Key> keysL1;
	static vector<Keyboard::Key> keysL2;
	static vector<Keyboard::Key> keysL3;
	static vector<Keyboard::Key> keysR1;
	static vector<Keyboard::Key> keysR2;
	static vector<Keyboard::Key> keysR3;
	static vector<int> buttonsL1;
	static vector<int> buttonsL2;
	static vector<int> buttonsL3;
	static vector<int> buttonsR1;
	static vector<int> buttonsR2;
	static vector<int> buttonsR3;

	static vector<Keyboard::Key> keysStart;
	static vector<Keyboard::Key> keysSelect;
	static vector<int> buttonsStart;
	static vector<int> buttonsSelect;
};

