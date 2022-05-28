#pragma once
class Interpreter
{
private:
	unsigned short Pc = 1000;
	int mem[2000];
public:
	Interpreter();
	~Interpreter();

	void MovePcLeft();
	void MovePcRight();
	void Add();
	void Sub();
	void StartLoop();
	void EndLoop();
	void Print();
	void GetChar();
};

