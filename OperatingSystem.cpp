#include "stdafx.h"
#include "OperatingSystem.h"
#include <string>
#include <iostream>
#include <algorithm>

OperatingSystem::OperatingSystem() {
}

OperatingSystem::~OperatingSystem() {
	for (Process* pp : _processes)
		delete pp;
	for (DynamicLib* pd : _dynamicLibs)
		delete pd;
}

void OperatingSystem::CreateProcess(string name, int memory) {
	if (FindProcess(name))
		throw "Process with this name already exists";
	_processes.push_back(new Process(name, memory));
}

void OperatingSystem::RemoveProcess(string name) {
	Process* pp = FindProcess(name);
	if (!pp)
		throw "Process not found";
	_processes.remove(pp);
}

void OperatingSystem::CreateThread(string processName, string threadName, int memory) {
	Process* pp = FindProcess(processName);
	if (!pp)
		throw "Process not found";
	pp->CreateThread(threadName, memory);
}

void OperatingSystem::RemoveThread(string processName, string threadName) {
	Process* pp = FindProcess(processName);
	if (!pp)
		throw "Process not found";
	pp->RemoveThread(threadName);
}

void OperatingSystem::AddLibRef(string processName, string threadName, string libName) {
	Thread* pt = FindProcess(processName)->FindThread(threadName);
	DynamicLib* pdl = FindDynamicLib(libName);
	if (pdl == NULL) {
		pdl = new DynamicLib(libName);
		_dynamicLibs.push_back(pdl);
	}
	pt->AddLibRef(pdl);
}

void OperatingSystem::RemoveLibRef(string processName, string threadName, string libName) {
	Thread* pt = FindProcess(processName)->FindThread(threadName);
	DynamicLib* pdl = FindDynamicLib(libName);
	if (pdl != NULL) {
		pt->RemoveLibRef(pdl);
	}
	if (pdl->GetLinkCount() == 0)
		_dynamicLibs.remove(pdl);
}

int OperatingSystem::GetProcessMemory(string name) {
	Process* pp = FindProcess(name);
	return pp->GetMemory();
}

int OperatingSystem::GetThreadMemory(string name) {
	Process* pt = FindProcess(name);
	return pt->GetMemory();
}

Process* OperatingSystem::FindProcess(string name) {
	for (Process* pp : _processes)
		if (!name.compare(pp->GetName()))
			return pp;
	return NULL;
}

DynamicLib* OperatingSystem::FindDynamicLib(string name) {
	for (DynamicLib* pdl : _dynamicLibs)
		if (!name.compare(pdl->GetName()))
			return pdl;
	return NULL;
}

void OperatingSystem::PrintTree() {
	for (Process* pp : _processes)
		pp->Print();
	cout << "\n";
}

void OperatingSystem::PrintLibs() {
	for (DynamicLib* pd : _dynamicLibs)
		pd->Print();
	cout << "\n";
}
