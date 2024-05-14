#pragma once
class RewardProgram {
public:
	int points=0;
	RewardProgram();
	bool check_reward();
	void redeem_reward();
	void increment_points();
};