#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "user.h"
using namespace std;

class Station;

class Train
{

public:
    int currentPosition;
    int trainID;
    int capacity;
    int breakdownDelay = 10;

    vector<Station*> route;

    Train(int id, int cap, vector<Station*> route);
    bool isBreakdown = false;
    void setBreakdown(bool isBroken);
};