/***********************************************************
 **CLASS:            LOSERLIST
 **
 **DESCRIPTION:      HPP FILE
 **
 **This stack node list demonstrates FILO, or First In
 **Last Out.  It holds the losers of the game.
 ***********************************************************/

#ifndef loserList_hpp
#define loserList_hpp
#include <iostream>
#include <string>
#include "creature.hpp"
using namespace std;

class LoserList
{
protected:
    struct LoserNode
    {
        Creature * ptrCreature;
        LoserNode *next;
        LoserNode();
    };
    
    LoserNode *head;    //head pointer
    
    int listSIZE;
    
public:
    LoserList();
    ~LoserList();
    
    int getListSIZE();
    LoserNode * getTop();
    
    void add(Creature *);
    Creature * remove();
    
    void displayList();
};
#endif
