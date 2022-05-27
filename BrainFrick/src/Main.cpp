#include <iostream>
#include <fstream>

int main(int argc, char** argv) 
{
	bool quit = false;
	std::string fileName;
	std::ifstream file;
	while (!quit) 
	{
		std::cout << "Input file location: ";
		std::cin >> fileName;
		file.open(fileName);
		if (file.is_open()) 
		{
			std::cout << "File opened" << std::endl;
		}
		file.close();
	}
	return 0;
}