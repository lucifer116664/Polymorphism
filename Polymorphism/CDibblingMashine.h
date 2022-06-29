#pragma once
#include "CMashine.h"
class CDibblingMashine :public virtual CMashine
{
protected:
	int seedsPlanted;
	int plantedAtAll;
	int needPlant;
	string seedType;

	void SetSeedType();

	void SetNeedPlant();

	int Dibble();

	void IsWorking() override;

	CDibblingMashine();
};