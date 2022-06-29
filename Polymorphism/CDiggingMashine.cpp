#include "CDiggingMashine.h"

void CDiggingMashine::SetHolesNeed()
{
	cout << "Enter number of holes you need:" << endl;
	cin >> holesNeed;
}

void CDiggingMashine::IsWorking()
{
	if (!power)
	{
		while (!power)
		{
			string choose;
			cout << "The digging mashine is OFF. Turn it ON?\n";
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
	}
}

int CDiggingMashine::Dig()
{
	int i = 0;
	while (holesMade < holesNeed)
	{
		trunk[i] = true;
		holesMade++;
		
		if (trunk[trunkSize - 1] == true)
		{
			string choose;
			cout << "The " << brand <<"'s digging mashine has made " << holesMade << " holes. The dirt-trunk is full, set it empty?:\n";
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

CDiggingMashine::CDiggingMashine()
{
	holesNeed = 0;
	holesMade = 0;
	for (int i = 0; i < trunkSize; i++)
		trunk[i] = false;
}
