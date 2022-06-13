#include "Interpreter.h"

Interpreter::Interpreter() {}
Interpreter::~Interpreter() {}

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

void Interpreter::StartLoop(int Pointer) 
{
	loopStart.push(Pointer);
}

void Interpreter::EndLoop(int& Pointer) 
{
	if (mem[Pointer] == 0) 
	{
		loopStart.pop();
	}
	else 
	{
		Pointer = loopStart.top();
	}
}

void Interpreter::Print() 
{
	//printf((const char*)mem[Pointer]);
	//std::cout << mem[Pointer];
	std::cout << (int)mem[Pointer];
}