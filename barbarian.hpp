/***********************************************************
 **CLASS:            BARBARIAN
 **
 **DESCRIPTION:      HPP FILE
 **
 **A derived class of the Creature class.  Barbarian has
 **armor of 0 and starting Strength Points of 12.
 ***********************************************************/

#ifndef BARBARIAN_hpp
#define BARBARIAN_hpp
#include <iostream>
#include <string>
#include <cstdlib>
#include "tournament.hpp"
using namespace std;

class Barbarian:public Creature
{
private:
    
public:
    Barbarian(int, int, string, string);
    
    virtual int attack();
    
    virtual void defense(int);
    
};
#endif
