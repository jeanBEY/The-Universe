/***********************************************************
 **CLASS:            CREATURE
 **
 **DESCRIPTION:      CPP FILE
 **
 **The base/parent (abstract) class.  Contains data members
 **and functions, including 2 virtual functions.
 ***********************************************************/

#include "creature.hpp"

/*************************************************************
 **Function:        Creature()
 **Description:     Constructor(EMPTY)
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
Creature::Creature() {
    
}

/*************************************************************
 **Function:        Creature(int, int, string)
 **Description:     Constructor uses parameters, sends them
 **to set methods.
 **Parameters:      int(armor), int (strength points),
 **string (creature type), string (name)
 **Pre-Conditions:      N/A
 **Post-Conditions:     Creature object's armor, sPoints,
 **creature type & name is assigned a value.
 *************************************************************/
Creature::Creature(int armor, int sPoints, string cType, string name) {
    setArmor(armor);
    setsPoints(sPoints);
    setCreatureType(cType);
    setName(name);
    
    goldPoints = 0;             //goldPoints are used to determine who gets 1st, 2nd and 3rd place
}

/*************************************************************
 **Function:        getArmor()
 **Description:     Returns armor
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
int Creature::getArmor() {
    return armor;
}

/*************************************************************
 **Function:        getsPoints()
 **Description:     Returns sPoints
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
int Creature::getsPoints() {
    return sPoints;
}

/*************************************************************
 **Function:        getGoldPoints()
 **Description:     Returns goldPoints
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
int Creature::getGoldPoints()
{
    return goldPoints;
}

/*************************************************************
 **Function:        getCreatureType()
 **Description:     Returns creatureType
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
string Creature::getCreatureType()
{
    return creatureType;
}

/*************************************************************
 **Function:        getName()
 **Description:     Returns name
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
string Creature::getName()
{
    return name;
}

/*************************************************************
 **Function:        getType()
 **Description:     Returns type
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
int Creature::getType()
{
    return type;
}

/*************************************************************
 **Function:        getBBB()
 **Description:     Returns BBB (integer to hold blow by blow
 **feature display)
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
bool Creature::getBBB()
{
    return BBB;
}

/*************************************************************
 **Function:        getTEAM()
 **Description:     Returns TEAM
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
int Creature::getTEAM()
{
    return TEAM;
}

/*************************************************************
 **Function:        setArmor(int)
 **Description:     Sets armor value passed into it
 **Parameters:      int(armor value)
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void Creature::setArmor(int a){
    armor = a;
}

/*************************************************************
 **Function:        setsPoints(int)
 **Description:     Sets sPoints value passed into it
 **Parameters:      int(strength points value)
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void Creature::setsPoints(int s) {
    sPoints = s;
}

/*************************************************************
 **Function:        setGoldPoints(int)
 **Description:     Adds to goldPoints
 **Parameters:      int(goldPoints to add to current goldPoints)
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void Creature::setGoldPoints(int gp)
{
    goldPoints += gp;
}

/*************************************************************
 **Function:        setCreatureType(string)
 **Description:     Sets creature type(i.e. Barbarian, Medusa)
 **Parameters:      string(creature type)
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void Creature::setCreatureType(string ct)
{
    creatureType = ct;
}

/*************************************************************
 **Function:        setName(string)
 **Description:     Sets name value passed into it
 **Parameters:      string(name of Creature)
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void Creature::setName(string cName) {
    name = cName;
}

/*************************************************************
 **Function:        setType(int)
 **Description:     Sets type of creature(i.e. 1 for Barbarian,
 **2 for Medusa, etc.)
 **Parameters:      int (# assigned to type of creature)
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void Creature::setType(int t)
{
    type = t;
}

/*************************************************************
 **Function:        setBBB(int)
 **Description:     Sets feature to turn blow by blow display
 **on or off, using a bool as parameter
 **Parameters:      bool(true or false)
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void Creature::setBBB(bool b)
{
    BBB = b;
}

/*************************************************************
 **Function:        setTEAM(int)
 **Description:     Sets the team for Creature
 **Parameters:      int(team #1 or #2)
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void Creature::setTEAM(int t)
{
    TEAM = t;
}

/*************************************************************
 **Function:        rollGold()
 **Description:     Uses 5 sided die to gain goldPoints.  
 **When a creature wins a match, they get to roll a die to 
 **gain goldPoints(which in the end determines the winners)
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void Creature::rollGold()
{
    int gold;
    gold = rand()%5 + 1;
    setGoldPoints(gold);
}

/*************************************************************
 **Function:        restorePoints()
 **Description:     Uses a 5 sided die to determine percentage
 **of current strength points to restore.  This function is
 **called for Creatures that have won a match.
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void Creature::restorePoints()
{
    int pointsRestored;
    pointsRestored = getsPoints() + (((rand()%5 + 1)/10)*getsPoints());
    if(pointsRestored < 0)
    {
        pointsRestored = pointsRestored * -1;       //Make sure that points restored is positive
    }
    setsPoints(pointsRestored);                     //Uses 5 sided die roll to determine percentage of current sPoints
                                                    //to ADD to current sPoints.
}