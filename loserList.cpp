/***********************************************************
 **CLASS:            LOSERLIST
 **
 **DESCRIPTION:      CPP FILE
 **
 **This stack node list demonstrates FILO, or First In
 **Last Out.  It holds the losers of the game.
 ***********************************************************/

#include "loserList.hpp"

/*************************************************************
 **Function:        LoserList()
 **Description:     Constructor(EMPTY)
 **Sets head to NULL, sets listSIZE to zero
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     head initialized to NULL and
 **listSIZE initialized to zero
 *************************************************************/
LoserList::LoserList()
{
    head = NULL;
    listSIZE = 0;
}

/*************************************************************
 **Function:        ~LoserList()
 **Description:     Destructor(EMPTY)
 **Starts at head of list and traverses through, deallocating
 **each next pointer through the temp variable trash.
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
LoserList::~LoserList()
{
    LoserNode *temp = head;         //Begin at head of list, and traverse through deallocating
    while(temp != NULL)
    {
        LoserNode *trash = temp;    //Assign first node to trash
        temp = temp->next;          //Assign second node to temp
        delete trash;               //Delete first node
    }
}

/*************************************************************
 **Function:        getListSIZE()
 **Description:     Returns listSIZE
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
int LoserList::getListSIZE()
{
    return listSIZE;
}

/*************************************************************
 **Function:        getTop()
 **Description:     Returns head
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
LoserList::LoserNode* LoserList::getTop()
{
    return head;
}

/*************************************************************
 **Function:        LoserNode()
 **Description:     Constructor(EMPTY) to create nodes
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
LoserList::LoserNode::LoserNode()
{
    //EMPTY IN ORDER TO CREATE NODES
}

/*************************************************************
 **Function:        add(Creature *)
 **Description:     Assign the pointer to Creature passed by 
 **value, to the local pointer to Creature variable ptrCreature.
 **The node that head was previously pointing to, is now
 **in position 2. Imagine the new node is placed on the left
 **hand side of the node head was pointing to.  We access this
 **new node's next pointer, and assign the node(that was already
 **there) to it.  Head now points to this new node (on the left)
 **which is also considered the "top" node.  
 **
 **Increment listSIZE by 1.
 **Parameters:          Pointer to Creature
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void LoserList::add(Creature * pC)
{
    LoserNode *newNode = new LoserNode;
    
    newNode->ptrCreature = pC;          //Assigns pointer to Creature to ptrCreature
    newNode->next = head;               //Node head was previously pointing to is now in position 2.  newNode now points to node in position 2.
    head = newNode;                     //Head now points to this new node.  This new node is now at the "top".
    
    listSIZE += 1;                      //Increment list size
    
}

/*************************************************************
 **Function:        remove()
 **Description:     If head points to NULL, then show
 **error message.  Else, assign head to local temp pointer
 **to LineupNode, current.  Current now points to same "top"
 **node as head.  Assign the pointer to Creature in that "top"
 **node to locatl pointer to Creature, topCreature.  Assign head's
 **next pointer to head, so head now points to the 'second' node.
 **Then delete the temp variable, current(which was pointing at
 **first node).
 **
 **Decrement listSIZE by 1.
 **
 **Return topCreature.
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
Creature * LoserList::remove()
{
    LoserNode *current;
    
    if(!head)
    {
        cout << "There are no nodes to remove." <<endl;
        return 0;
    }
    else
    {
        Creature *topCreature;
        current = head;                     //Now current points to the same "top" node as head
        topCreature = current->ptrCreature; //Assigning the pointer to Creature in that first node to topCreature
        head = head->next;                  //Head points to first node, accesses the pointer to next node and assigns it to head.
                                            //Head now is pointing to the node in position 2.
        delete current;                     //Deleting the current value, which is pointing at the first node
        
        listSIZE -= 1;                      //Decrement list size
        return topCreature;
        
    }
}

/*************************************************************
 **Function:        displayList()
 **Description:     Assign head to local temp pointer to
 **LineupNode.  While head does not equal NULL, access the
 **pointer to Creature in that node and display: team, type,
 **name, gold points, strength points.  The access the next
 **pointer, if it points to NULL, then terminate, otherwise,
 **iterate the while loop again.
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void LoserList::displayList()
{
    LoserNode *show = head;
    
    while(head != NULL)
    {
        cout << "Team: " << show->ptrCreature->getTEAM() << " " <<endl;
        cout << "Type: " << show->ptrCreature->getCreatureType() << " " <<endl;
        cout << "Name: " << show->ptrCreature->getName() << " " <<endl;
        cout << "Gold Points: " << show->ptrCreature->getGoldPoints() << " " <<endl;
        cout << "Strength Points: " << show->ptrCreature->getsPoints() << " " <<endl <<endl;
        show = show->next;
        if(show == NULL)
        {
            break;
        }
    }
}