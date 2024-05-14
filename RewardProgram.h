#pragma once
class RewardProgram {
public:
	int points=0;
	RewardProgram();
	RewardProgram(int point);
	bool check_reward();
	void redeem_reward();
	void increment_points();
	int getPoints();
};