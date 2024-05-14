#include <iostream>
#include<string>
#include"RewardProgram.h"

using namespace std;

RewardProgram :: RewardProgram()
{
		points=0;
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
void RewardProgram:: increment_points() {
	points++;
}
void RewardProgram:: redeem_reward()
	{
		points = 0;
		cout << "You completed 5 rides!" << endl;
		cout << "Your next ride is free!" << endl;
	}
void RewardProgram:: increment_points()
{
	points++;

}