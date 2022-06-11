#pragma once
#include <stack>

class Interpreter
{
private:
	unsigned short Pc = 1000;
	char mem[2000];
	std::stack<int> loopStart;
public:
	Interpreter();
	~Interpreter();

	void MovePcLeft();
	void MovePcRight();
	void Add();
	void Sub();
	void StartLoop(int pc);
	void EndLoop(int& pc);
	void Print();
	void GetChar();
};

