#pragma once
#include "CMashine.h"
class CDiggingMashine : public virtual CMashine
{
protected:
	int holesMade;
	int holesNeed;

	void SetHolesNeed();

	virtual int Dig();

	void IsWorking() override;

	CDiggingMashine();
};