#include <iostream>
#include<string>
#include"RewardProgram.h"

using namespace std;

RewardProgram :: RewardProgram()
{
		points++;
}

bool RewardProgram:: check_reward()
	{
		if (points >= 5)
		{
			return true;
			redeem_reward();
		}
		else
			return false;
	}

void RewardProgram:: redeem_reward()
	{
		points = 0;
		cout << "You completed 5 rides!" << endl;
		cout << "Your next ride is free!" << endl;
	}