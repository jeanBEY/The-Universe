/***********************************************************
 **CLASS:            MEDUSA
 **
 **DESCRIPTION:      CPP FILE
 **
 **A derived class of the Creature class.  Medusa
 **has a specialized power called Glare, where is the
 **opponent has looked her straight in the eye, she
 **automatically wins.
 **Medusa has armor of 3 and starting Strength Points of
 **8.
 ***********************************************************/

#include "medusa.hpp"

/*************************************************************
 **Function:        Medusa(int, int, string)
 **Description:     Constructor uses parameters, sends them
 **to set methods.  Also initializes chance to zero.
 **Parameters:      int(armor), int (strength points),
 **string (creature type), string (name)
 **Pre-Conditions:      N/A
 **Post-Conditions:     Medusa object's armor, sPoints,
 **creature type & name is assigned a value.
 *************************************************************/
Medusa::Medusa(int arm, int sp, string type, string name): Creature(arm, sp, type, name)
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
int Medusa::attack()
{
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
void Medusa::defense(int damage)
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

/*************************************************************
 **Function:        glare(Creature *&)
 **Description:     Accepts a pointer to Creature by reference
 **as a parameter(opponent).  Then sets the opponent's sPoints
 **to zero, hence Medusa wins and has used her Glare power.
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     Opponent's sPoints is assigned 0
 *************************************************************/
void Medusa::glare(Creature * & opponent)
{
    opponent->setsPoints(0);       
}
