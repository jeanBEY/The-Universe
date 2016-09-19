/***********************************************************
 **Program Filename:       MAIN(Tournament)
 **
 **Author:                 JEANVALLY G.BEATO
 **
 **Date:                   2/29/16
 **
 **Description:  The Universe program allows user to choose
 **between 5 different characters(Barbarian, Medusa, Vampire
 **BlueMen, HarryPotter) to do battle.  Two players will
 **choose 3 Creatures to use in their lineup.  The Creatures
 **at the top of each lineup fight until one dies.  The one
 **that dies goes into a Loser pile.  The one that wins gets
 **put at the back of the line(and given another chance to
 **fight once they reach the front of the line again).  The
 **game ends when one of the lineups loses all of it's
 **Creatures to the Loser pile.  
 **Input:       User choices(ints & names)
 **Output:      Results of battle
 ***********************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include "tournament.hpp"
using namespace std;

int main()
{
    
    //TO USE RANDOM # GENERATOR
    unsigned seed;
    seed = time(0);
    srand(seed);
    
    Tournament test;
    test.menu();
    
    return 0;
}

