#include "CDiggingDibblingMashine.h"

void CDiggingDibblingMashine::IsWorking()
{
	if (!power)
	{
		while (!power)
		{
			string choose;
			cout << "The " << brand <<"'s dibbling-digging mashine is OFF. Turn it ON?\n";
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
		SetHolesNeed();
		Dig();
		for (int i = 0; i < trunkSize; i++)
			trunk[i] = true;
		while (plantedAtAll < holesMade)
		{
			SetNeedPlant();
			if (plantedAtAll + needPlant > holesMade || needPlant > holesMade)
			{
				cout << "There is not enough holes to plant so many seeds" << endl;
				continue;
			}
			SetSeedType();
			this->Dibble();
		}
	}	
}

int CDiggingDibblingMashine::Dig()
{
	string choose;
	int i = 0;
	while (holesMade < holesNeed)
	{
		trunk[i] = true;
		holesMade++;
		fuel--;

		if (fuel == 0)
		{
			cout << "The fuel has run of. Tank the mashine up?\n";
			cin >> choose;
			if (choose != "yes")
			{
				cout << "The mashine can't work anymore\n";
				break;
			}
			else
			{
				fuel = 100;
			}
		}

		if (trunk[trunkSize - 1] == true)
		{
			cout << "The " << brand << "'s digging mashine has made " << holesMade << " holes. The dirt-trunk is full, set it empty?:\n";
			cin >> choose;
			if (choose != "yes")
			{
				cout << "You can't dig anymore\n";
				break;
			}
			else
			{
				for (int j = 0; j < trunkSize; j++)
					trunk[j] = false;
				i = NULL;
			}
		}
		else
			i++;
	}
	cout << "The " << brand << "'s digging mashine has made " << holesMade << " holes." << endl;
	return holesMade;
}

void CDiggingDibblingMashine::Dibble()
{
	int i = 0;
	while (seedsPlanted < needPlant)
	{
		string choose;
		trunk[i] = false;
		seedsPlanted++;
		fuel--;

		if (fuel == 0)
		{
			cout << "The fuel has run of. Tank the mashine up?\n";
			cin >> choose;
			if (choose != "yes")
			{
				cout << "The mashine can't work anymore\n";
				break;
			}
			else
			{
				fuel = 100;
			}
		}

		if (trunk[trunkSize - 1] == false)
		{
			cout << "The " << brand << "'s dibbling mashine has planted " << seedsPlanted << " " << seedType << " seeds. The seed-trunk is empty, fill it up again?:\n";
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
}

CDiggingDibblingMashine::CDiggingDibblingMashine()
{
	fuel = 100;
	for (int i = 0; i < trunkSize; i++)
		trunk[i] = false;
}
