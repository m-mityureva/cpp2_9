#pragma once
#include "stdafx.h"
#include <string>

using namespace std;

class OSObject {
protected:
	int _memory;
	string _name;

public:
	OSObject();
	OSObject(string name);
	OSObject(string name, int memory);
	virtual int GetMemory();
	void SetMemory(int memory);
	string GetName();
	virtual void Print();
};