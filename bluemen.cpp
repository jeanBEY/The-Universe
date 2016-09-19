/***********************************************************
 **CLASS:            BLUEMEN
 **
 **DESCRIPTION:      CPP FILE
 **
 **A derived class of the Creature class.  BlueMen
 **is actualy a a swarm of individuals, therefore has
 **the ability to use 3, 2 or 1 die to generate the attack
 **roll value.
 **BlueMen has armor of 3 and starting Strength Points of
 **12.
 ***********************************************************/

#include "bluemen.hpp"

/*************************************************************
 **Function:        BlueMen(int, int, string)
 **Description:     Constructor uses parameters, sends them
 **to set methods.  Also initializes chance to zero.
 **Parameters:      int(armor), int (strength points),
 **string (creature type), & string (name)
 **Pre-Conditions:      N/A
 **Post-Conditions:     BlueMen object's armor, sPoints,
 **creature type & name is assigned a value.
 *************************************************************/
BlueMen::BlueMen(int arm, int sp, string type, string name): Creature(arm, sp, type, name)
{
    //SETS INHERITED MEMBERS :)
}

/*************************************************************
 **Function:        attack()
 **Description:     Uses two 10-sided die rolls to assign to
 **damage variable, returns local damage variable
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     damage is assigned a value
 *************************************************************/
int BlueMen::attack() {
    int damage = 0;
    damage += rand()%10 + 1;
    damage += rand()%10 + 1;
    return damage;
}

/*************************************************************
 **Function:        defense(int)
 **
 **Description:     Accepts an int(damage roll value from
 **opponent) as parameter.  Then depending on BlueMen's
 **sPoints, the mob() method is called to determine how many
 **dice will be used(3,2, or 1) for the defense roll.  Local
 **variable defense is assigned the value of the roll from
 **mob().  Then local damageINF(damage inflicted) variable is
 **assigned the value from operation: damage - defense - armor.
 **If defense roll is higher than attacker's damage, then no
 **change is made to Strength Points(per TA Chris Snyder).
 **
 **Parameters:          int(damage roll value)
 **Pre-Conditions:      N/A
 **Post-Conditions:     sPoints is adjusted(possibly)
 *************************************************************/
void BlueMen::defense(int damage)
{
    int damageINF = 0;
    int defense = 0;
    defense = mob(sPoints);                     //mob method
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
 **Function:        mob(int)
 **Description:     Nested inside defense(), this method accepts
 **the sPoints of BlueMen.  Based on sPoints, 3, 2, or 1 die
 **is/are used for the defense roll.
 **
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     Opponent's attack roll is assigned 0
 *************************************************************/
int BlueMen::mob(int strength)
{
    int def;
    
    if(strength > 0 && strength < 5)
    {
        if(BBB)
        {
        cout << endl << "***Only 1 mob, using 1 die***" <<endl <<endl;
        }
        
        def = rand()%6 + 1;         //use 1 die
        return def;
    }
    else if(strength > 4 && strength < 9)
    {
        if(BBB)
        {
        cout << endl << "***Only 2 mobs, using 2 dice***" <<endl <<endl;
        }
        
        def = rand()%6 + 1;         //use 2 die
        def += rand()%6 + 1;
        return def;
    }
    else
    {
        if(BBB)
        {
        cout << endl << "***Mobs at full force!  Using 3 dice***" <<endl <<endl;
        }
        
        def = rand()%6 + 1;         //use 3 die
        def += rand()%6 + 1;
        def += rand()%6 + 1;
        return def;
    }
}
