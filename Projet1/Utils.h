#pragma once
#include <vector>
#include <string>

using namespace std;

class Utils {
public :
	static vector<string> Split(string s, char delim);
	static string readFromFile(const string& fileName);
};
