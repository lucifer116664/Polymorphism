#include "CMashine.h"

void CMashine::PowerOn()
{
	power = true;
}

string CMashine::GetPower()
{
	if (power)
		return "ON";
	else
		return "OFF";
}

CMashine::CMashine()
{
	brand = "SajoKop incorporated";
	power = false;
}

CMashine::~CMashine()
{
	delete[] trunk;
}
