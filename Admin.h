#pragma once
#include "Metro.h"
#include "Station.h"
#include "user.h"
#include<stack>
#include <queue>

#include "Train.h"
#include "Ride.h"

class Admin
{
public:

    Subscription subscription;
    SubscriptionType type;
    Metro* metro;
    vector<Train*> trainss;
    user User;
    Ride ride;
    queue<pair<string, string>> SupportRespones;
    void write(ofstream* f);
    void read(ifstream* f);
    void  MetroManagement();
    void UserManagement();
    void FareManagement(Ride& ride);
    void StationManagement();
    void CustomerServiceMenu(stack<string>Questions);
    void GetQuestion(stack<string>Questions); // Questions stack recieved from the user 
    queue<pair<string, string>> SendReplies();
    stack<string>UserQuestions;
	void TrainManagement(Metro* metro1);
	void addTrainToLine();
	void editTrain();
	void handleBreakDowns();
	void ETA();
};
