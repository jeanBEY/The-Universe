/***********************************************************
 **CLASS:            BLUEMEN
 **
 **DESCRIPTION:      HPP FILE
 **
 **A derived class of the Creature class.  BlueMen
 **is actualy a a swarm of individuals, therefore has
 **the ability to use 3, 2 or 1 die to generate the attack
 **roll value.
 **BlueMen has armor of 3 and starting Strength Points of
 **12.
 ***********************************************************/

#ifndef BLUEMEN_hpp
#define BLUEMEN_hpp
#include <iostream>
#include <string>
#include <cstdlib>
#include "tournament.hpp"
using namespace std;

class BlueMen:public Creature
{
private:
    
    
public:
    BlueMen(int, int, string, string);
    
    virtual int attack();
    
    virtual void defense(int);
    
    int mob(int);
    
};
#endif
