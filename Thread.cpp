#include "stdafx.h"
#include "Thread.h"
#include <iostream>

Thread::Thread(string name, int memory) : OSObject(name, memory) {
}

Thread::~Thread() {
	for (DynamicLib* pdl : _dynamicLibs)
		delete pdl;
}

void Thread::Print() {
	cout << "   ";
	OSObject::Print();
	for (DynamicLib* pdl : _dynamicLibs)
		pdl->Print();
}

void Thread::AddLibRef(DynamicLib* pdl) {
	_dynamicLibs.push_back(pdl);
	pdl->IncreaseLinkCount();
}

void Thread::RemoveLibRef(DynamicLib* pdl) {
	_dynamicLibs.remove(pdl);
	pdl->ReduceLinkCount();
}

int Thread::GetMemory() {
	int memory = OSObject::GetMemory();
	for (DynamicLib* pdl : _dynamicLibs)
		memory += pdl->GetMemory();
	return memory;
}