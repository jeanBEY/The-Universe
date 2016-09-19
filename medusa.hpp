/***********************************************************
 **CLASS:            MEDUSA
 **
 **DESCRIPTION:      HPP FILE
 **
 **A derived class of the Creature class.  Medusa
 **has a specialized power called Glare, where is the
 **opponent has looked her straight in the eye, she
 **automatically wins.
 **Medusa has armor of 3 and starting Strength Points of
 **8.
 ***********************************************************/

#ifndef MEDUSA_hpp
#define MEDUSA_hpp
#include <iostream>
#include <string>
#include <cstdlib>
#include "tournament.hpp"
using namespace std;

class Medusa:public Creature
{
private:
    
public:
    Medusa(int, int, string, string);
    
    virtual int attack();
    
    virtual void defense(int);
    
    void glare(Creature * &);
    
};
#endif
