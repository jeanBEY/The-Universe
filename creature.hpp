/***********************************************************
 **CLASS:            CREATURE
 **
 **DESCRIPTION:      HPP FILE
 **
 **The base/parent (abstract) class.  Contains data members
 **and functions, including 2 virtual functions.
 ***********************************************************/

#ifndef CREATURE_hpp
#define CREATURE_hpp
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Creature
{
protected:
    int armor;
    int sPoints;
    int goldPoints;
    string creatureType;
    string name;
    int type;
    
    bool BBB;               //blow by blow display
    
    int TEAM;               //holds the team/lineup they are in
    
public:
    Creature();
    Creature(int, int, string, string);
    
    int getArmor();
    int getsPoints();
    int getGoldPoints();
    string getCreatureType();
    string getName();
    int getType();
    bool getBBB();
    int getTEAM();
    
    void setArmor(int);
    void setsPoints(int);
    void setGoldPoints(int);
    void setCreatureType(string);
    void setName(string);
    void setType(int);
    void setBBB(bool);
    void setTEAM(int);
    void rollGold();
    
    void restorePoints();
    
    virtual int attack() = 0;
    virtual void defense(int) = 0;
    
    
};
#endif
