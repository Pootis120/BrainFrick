#pragma once
#include <stack>
#include <iostream>

class Interpreter
{
private:
	unsigned short Pointer = 1000;
	char mem[2000];
	std::stack<int> loopStart;
public:
	Interpreter();
	~Interpreter();

	void MovePtrLeft();
	void MovePtrRight();
	void Add();
	void Sub();
	void StartLoop(int pc);
	void EndLoop(int& pc);
	void Print();
	void GetChar();
};

