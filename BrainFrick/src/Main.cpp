#include <iostream>
#include <fstream>

#include "Interpreter.h"

int main(int argc, char** argv) 
{
	bool quit = false;
	std::string fileName;
	while (!quit) 
	{
		std::cout << "Input file location: ";
		//std::cin >> fileName;
		fileName = "C:\\Dev\\Cpp\\Test.txt";
		std::ifstream file(fileName);
		std::string contents((std::istreambuf_iterator<char>(file)),
			std::istreambuf_iterator<char>());
		std::cout << contents << std::endl;
		std::cin.get();
	}
	return 0;
}