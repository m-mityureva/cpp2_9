#pragma once
#include "stdafx.h"
#include <string>
#include "OSObject.h"

class DynamicLib : public OSObject {
private:
	int _linkCount;
public:
	DynamicLib(string name);
	~DynamicLib();
	int GetLinkCount();
	void IncreaseLinkCount();
	void ReduceLinkCount();
	void Print();
};