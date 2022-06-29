#include "CDibblingMashine.h"

void CDibblingMashine::SetSeedType()
{
	cout << "What exactly you wanna plant?" << endl;
	cin >> seedType;
}

void CDibblingMashine::SetNeedPlant()
{
	cout << "Enter number of seeds you have to plant:" << endl;
	cin >> needPlant;
}

void CDibblingMashine::IsWorking()
{
	if (!power)
	{
		while (!power)
		{
			string choose;
			cout << "The dibbling mashine is OFF. Turn it ON?\n";
			cin >> choose;
			if (choose != "yes")
				break;
			else
			{
				PowerOn();
				IsWorking();
			}
		}
	}
	else
	{
		SetNeedPlant();
		SetSeedType();
		Dibble();
	}
}

int CDibblingMashine::Dibble()
{
	int i = 0;
	while (seedsPlanted < needPlant)
	{
		trunk[i] = false;
		seedsPlanted++;

		if (trunk[trunkSize - 1] == false)
		{
			string choose;
			cout << "The " << brand <<"'s dibbling mashine has planted " << seedsPlanted << " " << seedType << " seeds. The seed-trunk is empty, fill it up again?:\n";
			cin >> choose;
			if (choose != "yes")
			{
				cout << "You've got no " << seedType << " seeds to plant\n";
				break;
			}
			else
			{
				for (int j = 0; j < trunkSize; j++)
					trunk[j] = true;
				i = NULL;
			}
		}
		else
			i++;
	}
	cout << "The " << brand << "'s dibbling mashine has planted " << seedsPlanted << " " << seedType << " seeds." << endl;
	plantedAtAll += seedsPlanted;
	seedsPlanted = NULL;
	return plantedAtAll;
}

CDibblingMashine::CDibblingMashine()
{
	needPlant = 0;
	seedsPlanted = 0;
	plantedAtAll = 0;
	for (int i = 0; i < trunkSize; i++)
		trunk[i] = true;
}
