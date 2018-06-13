#pragma once
#include "stdafx.h"
#include <list>
#include "OSObject.h"
#include "Thread.h"

using namespace std;

class Process : public OSObject {
private:
	list<Thread*> _threads;
public:
	Process(string name, int memory);
	void CreateThread(string name, int memory);
	void RemoveThread(string name);
	Thread* FindThread(string name);
	int GetMemory();
	void Print();
};