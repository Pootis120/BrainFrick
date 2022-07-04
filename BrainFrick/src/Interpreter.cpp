#include "Interpreter.h"

Interpreter::Interpreter() {}
Interpreter::~Interpreter() {}

void Interpreter::RunInput(std::string contents)
{
	for (int i = 0; i < contents.size(); i++)
	{
		switch (contents[i])
		{
		case '<':
			MovePtrLeft();
			break;
		case '>':
			MovePtrRight();
			break;
		case '+':
			Add();
			break;
		case '-':
			Sub();
			break;
		case '[':
			StartLoop(i);
			break;
		case ']':
			EndLoop(i);
			break;
		case '.':
			Print();
			break;
		case ',':
			GetChar();
			break;
		}
	}
}

void Interpreter::MovePtrLeft() 
{
	Pointer--;
}

void Interpreter::MovePtrRight()
{
	Pointer++;
}

void Interpreter::Add()
{
	mem[Pointer]++;
}

void Interpreter::Sub()
{
	mem[Pointer]--;
}

void Interpreter::StartLoop(int pc) 
{
	loopStart.push(pc);
}

void Interpreter::EndLoop(int& pc) 
{
	if (mem[Pointer] == 0) 
	{
		loopStart.pop();
	}
	else 
	{
		pc = loopStart.top();
	}
}

void Interpreter::Print() 
{
	//printf((const char*)mem[Pointer]);
	std::cout << mem[Pointer];
}

void Interpreter::GetChar() 
{
	char character = 10; //In ASCII 10 is a newline character
	std::string input;
	std::cin >> input;
	if (!input.empty()) 
	{
		//Probably won't get to here because cin doesn't allow empty input
		character = input[0];
	}
	mem[Pointer] = character;
}