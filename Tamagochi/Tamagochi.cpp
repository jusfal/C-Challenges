#include "Tamagochi.h"
#include <iostream>

using namespace std;

Tamagochi::Tamagochi()
{
}


Tamagochi::~Tamagochi()
{
}

void Tamagochi::Play()
{
	cout << "The tamagochi is playing" << endl;
}

void Tamagochi::Eat()
{

	hunger + 10;

	if (hunger < 30)
	{
		cout << "Yummy! MORE!" << endl;
	}
	if (hunger > 30 && hunger < 100)
	{
		cout << "YUMMY! IM full now" << endl;
	}
	if (hunger == 100)
	{
		cout << "Stop feeding me! I feel like im going to explode" << endl;
		if (hunger > 100 && hunger < 120)
		{
			cout << "I dont feel well" << endl;
		}
		else if (hunger > 120)
		{
			cout << "Your Tamagochi has exploded. RIP" << endl;
		}

	}
}

void Tamagochi::Talk()
{
	cout << "Hey its me mochi" << endl;
}
