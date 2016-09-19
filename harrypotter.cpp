/***********************************************************
 **CLASS:            HARRYPOTTER
 **
 **DESCRIPTION:      CPP FILE
 **
 **A derived class of the Creature class.  HarryPotter
 **has a specialized power called Hogwarts, in which he
 **gets revived back to life after dying once.
 **HarryPotter has armor of 0 and starting Strength Points of
 **10.
 ***********************************************************/

#include "harrypotter.hpp"

/*************************************************************
 **Function:        HarryPotter(int, int, string)
 **Description:     Constructor uses parameters, sends them
 **to set methods.  Also initializes chance to zero.
 **Parameters:      int(armor), int (strength points),
 **string(creature type), string (name)
 **Pre-Conditions:      N/A
 **Post-Conditions:     chance is assigned the value 1.
 **Harry Potter object's armor, sPoints, creature type &
 **name is assigned a value.
 *************************************************************/
HarryPotter::HarryPotter(int arm, int sp, string type, string name): Creature(arm, sp, type, name)
{
    //SETS INHERITED MEMBERS :)
    chance = 1;
}

/*************************************************************
 **Function:        attack()
 **Description:     Uses two 6-sided die rolls to assign to
 **damage variable, returns local damage variable
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     damage is assigned a value
 *************************************************************/
int HarryPotter::attack() {
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
 **Harry's Hogwarts power is activated if he die's once.
 **Parameters:          int(damage roll value)
 **Pre-Conditions:      N/A
 **Post-Conditions:     sPoints is adjusted(possibly)
 *************************************************************/
void HarryPotter::defense(int damage)
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
    
    if(sPoints <= 0 && chance ==1)          //if harry dies, by having 0 strength
                                            ////after the defense roll, his strength points becomes 20
    {
        sPoints = 20;
        chance -= 1;                        //chance is decremented, harry has now used up is only extra life
        if(BBB)
        {
            cout << endl << "*******Harry Potter has died and come back to life by using Hogwarts!*******" <<endl <<endl;
        }
    }
}
