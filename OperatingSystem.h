#pragma once
#include "stdafx.h"
#include "OSObject.h"
#include "Process.h"
#include "DynamicLib.h"
#include <list>
#include <string>

using namespace std;

class OperatingSystem {
private :
	list<Process*> _processes;
	list<DynamicLib*> _dynamicLibs;
	Process* FindProcess(string name);
	DynamicLib* FindDynamicLib(string name);

public:
	OperatingSystem();
	~OperatingSystem();
	void PrintTree();
	void PrintLibs();
	void CreateProcess(string name, int memory);
	void CreateThread(string processName, string threadName, int memory);
	void AddLibRef(string processName, string threadName, string libName);
	void RemoveProcess(string name);
	void RemoveThread(string processName, string threadName);
	void RemoveLibRef(string processName, string threadName, string libName);
	int GetProcessMemory(string name);
	int GetThreadMemory(string name);
};