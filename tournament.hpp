/***********************************************************
 **CLASS:            TOURNAMENT
 **
 **DESCRIPTION:      HPP FILE
 **
 **Holds the contents of the universe game:  Player 1,
 **Player 2, the menu, and the functions to start the combat.
 ***********************************************************/

#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP
#include <iostream>
#include <string>
#include <cstdlib>
#include "creature.hpp"
#include "barbarian.hpp"
#include "medusa.hpp"
#include "vampire.hpp"
#include "harrypotter.hpp"
#include "bluemen.hpp"
#include "lineupList.hpp"
#include "loserList.hpp"
using namespace std;

class Tournament
{
private:

    bool blowBYBlow;                                    //Holds bool to show blow by blow
    
    int team1POINTS;
    int team2POINTS;
    
    int choiceC1;
    int choiceC2;
    int choiceC3;
    int choiceC4;
    int choiceC5;
    int choiceC6;
    
    Creature *pCreature1;
    Creature *pCreature2;
    Creature *pCreature3;
    Creature *pCreature4;
    Creature *pCreature5;
    Creature *pCreature6;
    
    LineupList lineup1;
    LineupList lineup2;
    
    LoserList losers;
    
public:
    Tournament();
    
    void menu();
    
    int quit();
    
    void play();                                        //If play, then lineup 1 and lineup 2 setup called
    
    void setTEAM1();                                    //Set lineup 1
    void setTEAM2();                                    //Set lineup 2
    
    void round(Creature * &, int, Creature * &, int);   //One round in a battle
    
    void match();                                       //Battle
    void endMatch();                                    //Adjust lineup/losers list

    void createBarbarian(Creature * &);
    void createHarryPotter(Creature * &);
    void createMedusa(Creature * &);
    void createVampire(Creature * &);
    void createBlueMen(Creature * &);
    
    void displayWinners();
    
    
};
#endif
