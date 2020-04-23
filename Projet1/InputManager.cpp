#include "InputManager.h"

vector<Keyboard::Key> InputManager::keysUP = vector<Keyboard::Key>();
vector<Keyboard::Key> InputManager::keysDOWN = vector<Keyboard::Key>();
vector<Keyboard::Key> InputManager::keysLEFT = vector<Keyboard::Key>();
vector<Keyboard::Key> InputManager::keysRIGHT = vector<Keyboard::Key>();
vector<int> InputManager::buttonsUP = vector<int>();
vector<int> InputManager::buttonsDOWN = vector<int>();
vector<int> InputManager::buttonsLEFT = vector<int>();
vector<int> InputManager::buttonsRIGHT = vector<int>();

vector<Keyboard::Key> InputManager::keysA = vector<Keyboard::Key>();
vector<Keyboard::Key> InputManager::keysB = vector<Keyboard::Key>();
vector<Keyboard::Key> InputManager::keysX = vector<Keyboard::Key>();
vector<Keyboard::Key> InputManager::keysY = vector<Keyboard::Key>();
vector<int> InputManager::buttonsA = vector<int>();
vector<int> InputManager::buttonsB = vector<int>();
vector<int> InputManager::buttonsX = vector<int>();
vector<int> InputManager::buttonsY = vector<int>();

vector<Keyboard::Key> InputManager::keysL1 = vector<Keyboard::Key>();
vector<Keyboard::Key> InputManager::keysL2 = vector<Keyboard::Key>();
vector<Keyboard::Key> InputManager::keysL3 = vector<Keyboard::Key>();
vector<Keyboard::Key> InputManager::keysR1 = vector<Keyboard::Key>();
vector<Keyboard::Key> InputManager::keysR2 = vector<Keyboard::Key>();
vector<Keyboard::Key> InputManager::keysR3 = vector<Keyboard::Key>();
vector<int> InputManager::buttonsL1 = vector<int>();
vector<int> InputManager::buttonsL2 = vector<int>();
vector<int> InputManager::buttonsL3 = vector<int>();
vector<int> InputManager::buttonsR1 = vector<int>();
vector<int> InputManager::buttonsR2 = vector<int>();
vector<int> InputManager::buttonsR3 = vector<int>();

vector<Keyboard::Key> InputManager::keysStart = vector<Keyboard::Key>();
vector<Keyboard::Key> InputManager::keysSelect = vector<Keyboard::Key>();
vector<int> InputManager::buttonsStart = vector<int>();
vector<int> InputManager::buttonsSelect = vector<int>();

InputManager::InputManager()
{

}

InputManager::~InputManager()
{

}

void InputManager::init()
{
	keysUP.push_back(Keyboard::Up);
	keysDOWN.push_back(Keyboard::Down);
	keysLEFT.push_back(Keyboard::Left);
	keysRIGHT.push_back(Keyboard::Right);

	keysA.push_back(Keyboard::Space);
	keysB.push_back(Keyboard::Z);
	keysX.push_back(Keyboard::X);
	buttonsX.push_back(1);
	keysY.push_back(Keyboard::C);

	keysL1.push_back(Keyboard::A);
	keysL2.push_back(Keyboard::Q);
	keysL3.push_back(Keyboard::Num1);
	keysR1.push_back(Keyboard::D);
	keysR2.push_back(Keyboard::E);
	keysR3.push_back(Keyboard::Num3);

	keysStart.push_back(Keyboard::Enter);
	keysStart.push_back(Keyboard::Escape);
	keysSelect.push_back(Keyboard::BackSpace);
}

float InputManager::GetAxis(Keys K)
{
	//TODO
	/*switch (K) 
	{

	}*/
	return 0.0f;
}

bool InputManager::GetKeyState(Keys K)
{
	//TODO implement Joystick

	vector<Keyboard::Key> validKeys;
	vector<int> validButtons;
	switch (K)
	{
	case UP:
		validKeys = keysUP;
		break;
	case DOWN:
		validKeys = keysDOWN;
		break;
	case LEFT:
		validKeys = keysLEFT;
		break;
	case RIGHT:
		validKeys = keysRIGHT;
		break;

	case A:
		validKeys = keysA;
		break;
	case B:
		validKeys = keysB;
		break;
	case X:
		validKeys = keysX;
		validButtons = buttonsX;
		break;
	case Y:
		validKeys = keysY;
		break;

	case L1:
		validKeys = keysL1;
		break;
	case L2:
		validKeys = keysL2;
		break;
	case L3:
		validKeys = keysL3;
		break;
	case R1:
		validKeys = keysR1;
		break;
	case R2:
		validKeys = keysR2;
		break;
	case R3:
		validKeys = keysR3;
		break;

	case START:
		validKeys = keysStart;
		break;
	case SELECT:
		validKeys = keysR1;
		validKeys = keysSelect;
		break;
	}
	bool toReturn = false;
	for (Keyboard::Key k2 : validKeys)
		if (Keyboard::isKeyPressed(k2))
			toReturn = true;

	for (int i : validButtons)
		if (Joystick::isButtonPressed(0, i))
			toReturn = true;
	return toReturn;
}
