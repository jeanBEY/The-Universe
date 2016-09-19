/***********************************************************
 **CLASS:            HARRYPOTTER
 **
 **DESCRIPTION:      HPP FILE
 **
 **A derived class of the Creature class.  HarryPotter
 **has a specialized power called Hogwarts, in which he
 **gets revived back to life after dying once.
 **HarryPotter has armor of 0 and starting Strength Points of
 **10.
 ***********************************************************/

#ifndef HARRYPOTTER_hpp
#define HARRYPOTTER_hpp
#include <iostream>
#include <string>
#include <cstdlib>
#include "tournament.hpp"
using namespace std;

class HarryPotter:public Creature
{
private:
    int chance;             //harry has 1 chance to die, it's init. to 1 in constructor,
    //in which he can recover with 20 strength points
    
public:
    HarryPotter(int, int, string, string);
    
    virtual int attack();
    
    virtual void defense(int);
    
};
#endif
