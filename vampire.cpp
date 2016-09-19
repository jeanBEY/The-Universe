/***********************************************************
 **CLASS:            VAMPIRE
 **
 **DESCRIPTION:      CPP FILE
 **
 **A derived class of the Creature class.  Vampire
 **has a specialized power called Charm, where he can charm
 **his opponent into not attacking(there's a 50/50 chance for
 **this)
 **Vampire has armor of 1 and starting Strength Points of
 **18.
 ***********************************************************/

#include "vampire.hpp"

/*************************************************************
 **Function:        Vampire(int, int, string)
 **Description:     Constructor uses parameters, sends them
 **to set methods.  Also initializes chance to zero.
 **Parameters:      int(armor), int (strength points),
 **string (creature type), string (name)
 **Pre-Conditions:      N/A
 **Post-Conditions:     Vampire object's armor, sPoints,
 **creature type, & name is assigned a value.
 *************************************************************/
Vampire::Vampire(int arm, int sp, string type, string name): Creature(arm, sp, type, name)
{
    //SETS INHERITED MEMBERS :)
}

/*************************************************************
 **Function:        attack()
 **Description:     Uses one 12-sided die roll to assign to
 **damage variable, returns local damage variable
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     damage is assigned a value
 *************************************************************/
int Vampire::attack() {
    int damage = 0;
    damage += rand()%12 + 1;
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
void Vampire::defense(int damage)
{
    int damageINF = 0;
    int defense = 0;
    damage = charm(damage);         //Charm method
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
 **Function:        charm(int)
 **Description:     Nested inside defense(), this method accepts
 **the attack roll value from opponent.  Using a random
 **number generator to use 50/50 chance of activating Vampire's
 **Charm power, if it activates, then the opponent's attack roll
 **is assigned the value 0 (hence, Charm was used to charm the
 **opponent into NOT attacking).
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     Opponent's attack roll is assigned 0
 *************************************************************/
int Vampire::charm(int opponentAttack)
{
    int charmed;
    charmed = rand()%2;
    if(charmed ==0 )
    {
        opponentAttack = 0;
        
        if(BBB)
        {
            cout << endl << "*******Vampire has just used his CHARM on you, ";
            cout << "you've lost your chance to attack!*******" <<endl <<endl;
        }
            
        return opponentAttack;
    }
    else
    {
        return opponentAttack;
    }
}
