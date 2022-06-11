#include "Interpreter.h"

Interpreter::Interpreter() {}
Interpreter::~Interpreter() {}

void Interpreter::MovePcLeft() 
{
	Pc--;
}

void Interpreter::MovePcRight()
{
	Pc++;
}

void Interpreter::Add()
{
	mem[Pc]++;
}

void Interpreter::Sub()
{
	mem[Pc]--;
}

void Interpreter::StartLoop(int pc) 
{
	loopStart.push(pc);
}

void Interpreter::EndLoop(int& pc) 
{
	if (mem[Pc] == 0) 
	{
		loopStart.pop();
	}
	else 
	{
		pc = loopStart.top();
	}
}