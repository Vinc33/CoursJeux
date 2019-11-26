#include "Utils.h"
#include <iostream>
#include <fstream>
#include <SFML/System/FileInputStream.hpp>


vector<string> Utils::split(string s, char delim) 
{
	vector<string> elems;
	string current = "";
	for (char& c : s)
	{
		if (c != delim)
		{
			current += c;
		}
		else
		{
			elems.push_back(current);
			current = "";
		}
	}
	elems.push_back(current);
	return elems;
}
string Utils::readFromFile(const string& fileName)
{
	string inputFile = "";
	string line = "";
	ifstream fileStream;
	try
	{
		fileStream.open(fileName);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
	if (fileStream.is_open())
	{
		while (getline(fileStream, line))
		{
			inputFile.append(line);
		}
		fileStream.close();
	}
	return inputFile;
}
