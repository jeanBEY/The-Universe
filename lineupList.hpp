/***********************************************************
 **CLASS:            LINEUPLIST
 **
 **DESCRIPTION:      HPP FILE
 **
 **This queue node list holds the lineup for player #1 &
 **player #2's pointer to Creatures.  It demonstrates
 **FIFO, which is First In First Out.  If the node at the 
 **top of the list, has the winner pointer to Creature, then 
 **they are removed from the front of the list, and then
 **reinserted into the back of the list.
 ***********************************************************/

#ifndef LINEUPLIST_HPP
#define LINEUPLIST_HPP
#include <iostream>
#include <string>
#include "creature.hpp"
using namespace std;

class LineupList
{
protected:
    struct LineupNode
    {
        Creature * ptrCreature;
        LineupNode *next;
        LineupNode *previous;
        LineupNode();
    };
    
    LineupNode *head;    //head pointer
    LineupNode *tail;    //tail pointer
    
    int listSIZE;
    
public:
    

    
    LineupList();
    ~LineupList();
    
    int getListSIZE();
    LineupNode * getTop();
    
    void add(Creature *);
    Creature * remove();
    
    void addLast(Creature *);
    
    void displayList();
};
#endif