#pragma once
#include <iostream>
#include <string>
using namespace std;

class CMashine
{
protected:
	string brand;
	bool power;
	int trunkSize = 20;
	bool* trunk = new bool[trunkSize];

	virtual void IsWorking() = 0;

	void PowerOn();

	string GetPower();

	CMashine();

	virtual ~CMashine();
};

