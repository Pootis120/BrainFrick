#include <iostream>
#include <fstream>

#include "Interpreter.h"

int main(int argc, char** argv) 
{
	bool quit = false;
	std::string fileName;
	std::ifstream file;
	while (!quit) 
	{
		std::cout << "Input file location: ";
		//std::cin >> fileName;
		fileName = "C:\\Dev\\Cpp\\Test.txt";
		file.open(fileName);
		if (file.is_open()) 
		{
			Interpreter prog;
			std::cout << "File opened" << std::endl;
			char ch;
			while (file >> std::noskipws >> ch) {
				std::cout << ch;
			}
		}
		else 
		{
			std::cout << "Could not open file" << std::endl;
		}
		file.close();
	}
	return 0;
}