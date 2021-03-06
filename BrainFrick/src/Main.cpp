#include <iostream>
#include <fstream>

#include "Interpreter.h"

int main(int argc, char** argv) 
{
	bool quit = false;
	std::string fileName;
	Interpreter machine;
	while (!quit) 
	{
		//Load file
		std::cout << "Input file location: ";
		//std::cin >> fileName;
		fileName = "C:\\Dev\\Cpp\\Test.txt";
		std::ifstream file(fileName);
		std::string contents((std::istreambuf_iterator<char>(file)),
			std::istreambuf_iterator<char>());
		std::cout << contents << std::endl;

		std::cout << "Program start: " << std::endl;
		machine.RunInput(contents);
		std::cout << std::endl << "Program end" << std::endl;
		std::cin.get();
	}
	return 0;
}