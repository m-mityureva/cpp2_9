#include "stdafx.h"
#include "OSObject.h"
#include <iostream>

OSObject::OSObject() {
}

OSObject::OSObject(string name) {
	_name = name;
	_memory = 0;
}

OSObject::OSObject(string name, int memory) {
	_name = name;
	_memory = memory;
}

void OSObject::Print() {
	cout << _name << " (memory:" << GetMemory() << ")" << "\n";
}

void OSObject::SetMemory(int memory) {
	_memory = memory;
}

int OSObject::GetMemory() {
	return _memory;
}

string OSObject::GetName() {
	return _name;
}