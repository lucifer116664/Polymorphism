#pragma once
#include "CDiggingMashine.h"
#include "CDibblingMashine.h"

class CDiggingDibblingMashine : public CDiggingMashine, public CDibblingMashine
{
private:
	int fuel;

	int Dig() override;

	void Dibble();

	void operator =(const CMashine &other);

public:
	void IsWorking() override;

	CDiggingDibblingMashine();
};

