/***********************************************************
 **CLASS:            BARBARIAN
 **
 **DESCRIPTION:      CPP FILE
 **
 **A derived class of the Creature class.  Barbarian has
 **armor of 0 and starting Strength Points of 12.
 ***********************************************************/

#include "barbarian.hpp"

/*************************************************************
 **Function:        Barbarian(int, int, string, string)
 **Description:     Constructor uses parameters, sends them
 **to set methods.
 **Parameters:      int(armor), int (strength points),
 **string (creature type), string (name)
 **Pre-Conditions:      N/A
 **Post-Conditions:     Barbarian object's armor, sPoints, 
 **creature type & name is assigned a value.
 *************************************************************/
Barbarian::Barbarian(int arm, int sp, string type, string name): Creature(arm, sp, type, name)
{
    //SETS INHERITED MEMBERS :)
}

/*************************************************************
 **Function:        attack()
 **Description:     Uses two 6-sided die rolls to assign to
 **damage variable, returns local damage variable
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     damage is assigned a value
 *************************************************************/
int Barbarian::attack() {
    int damage = 0;
    damage += rand()%6 + 1;
    damage += rand()%6 + 1;
    return damage;
}

/*************************************************************
 **Function:        defense(int)
 **
 **Description:     Accepts an int(damage roll value from
 **opponent) as parameter.  Then defense() uses two 6-sided
 **die rolls to assign value to local defense variable.  Local
 **damageINF(damage inflicted) variable is assigned the value
 **from operation: damage - defense - armor.  If defense roll
 **is higher than attacker's damage, then no change is made to
 **Strength Points(per TA Chris Snyder).
 **
 **Parameters:          int(damage roll value)
 **Pre-Conditions:      N/A
 **Post-Conditions:     sPoints is adjusted(possibly)
 *************************************************************/
void Barbarian::defense(int damage)
{
    int damageINF = 0;
    int defense = 0;
    defense += rand()%6 + 1;
    defense += rand()%6 + 1;
    damageINF = damage - defense - armor;
    
    if(BBB)
    {
        cout << "Defense roll: " << defense <<endl;
        cout << "Armor: " << armor <<endl;
        cout << "Total damageINF: " << damageINF <<endl;
    }
        
    if(damageINF > 0)
    {
        sPoints -= damageINF;
    }
    else if(damageINF < 0)
    {
        //EMPTY ON PURPOSE
    }
}
