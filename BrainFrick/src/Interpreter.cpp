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