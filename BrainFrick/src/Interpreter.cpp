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