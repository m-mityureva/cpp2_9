#include "stdafx.h"
#include "Process.h"
#include <iostream>

Process::Process(string name, int memory) :OSObject(name, memory) {
}

void Process::CreateThread(string name, int memory) {
	_threads.push_back(new Thread(name, memory));
}

void Process::RemoveThread(string name) {
	_threads.remove(FindThread(name));
}

Thread* Process::FindThread(string name) {
	for (Thread* pt : _threads)
		if (!name.compare(pt->GetName()))
			return pt;
	throw "Thread not found";
}

void Process::Print() {
	OSObject::Print();
	for (Thread* thread : _threads)
		thread->Print();
}

int Process::GetMemory() {
	int memory = OSObject::GetMemory();
	for (Thread* pt : _threads)
		memory += pt->GetMemory();
	return memory;
}