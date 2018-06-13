#pragma once
#include "stdafx.h"
#include "OSObject.h"
#include "DynamicLib.h"
#include <list>

using namespace std;

class Thread : public OSObject {
private:
	list<DynamicLib*> _dynamicLibs;
public:
	Thread(string name, int memory);
	~Thread();
	void Print();
	void AddLibRef(DynamicLib* pdl);
	void RemoveLibRef(DynamicLib* pdl);
	int GetMemory();
};