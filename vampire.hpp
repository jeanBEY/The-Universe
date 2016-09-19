/***********************************************************
 **CLASS:            VAMPIRE
 **
 **DESCRIPTION:      HPP FILE
 **
 **A derived class of the Creature class.  Vampire
 **has a specialized power called Charm, where he can charm
 **his opponent into not attacking(there's a 50/50 chance for
 **this)
 **Vampire has armor of 1 and starting Strength Points of
 **18.
 ***********************************************************/

#ifndef VAMPIRE_hpp
#define VAMPIRE_hpp
#include <iostream>
#include <string>
#include <cstdlib>
#include "tournament.hpp"
using namespace std;

class Vampire:public Creature
{
private:
    
    
public:
    Vampire(int, int, string, string);
    
    virtual int attack();
    
    virtual void defense(int);
    
    int charm(int);             //Uses 50/50 chance to set opponent's attack roll to zero
    
};
#endif
