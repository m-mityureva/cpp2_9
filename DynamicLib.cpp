#include "stdafx.h"
#include "DynamicLib.h"
#include <iostream>

DynamicLib::DynamicLib(string name) :OSObject(name) {
	_linkCount = 0;
	_memory = 8;
}

DynamicLib::~DynamicLib() {

}

void DynamicLib::Print() {
	cout << "      " << _name << " (memory:" << _memory << ", links: " << _linkCount << ")\n";
	//OSObject::Print();
}

void DynamicLib::IncreaseLinkCount() {
	_linkCount++;
}

void DynamicLib::ReduceLinkCount() {
	_linkCount--;
}

int DynamicLib::GetLinkCount() {
	return _linkCount;
}