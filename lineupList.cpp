/***********************************************************
 **CLASS:            LINEUPLIST
 **
 **DESCRIPTION:      CPP FILE
 **
 **This queue node list holds the lineup for player #1 &
 **player #2's pointer to Creatures.  It demonstrates
 **FIFO, which is First In First Out.  If the node at the
 **top of the list, has the winner pointer to Creature, then
 **they are removed from the front of the list, and then
 **reinserted into the back of the list.
 ***********************************************************/

#include "lineupList.hpp"

/*************************************************************
 **Function:        LineupList()
 **Description:     Constructor(EMPTY)
 **Sets head & tail pointers to NULL, sets listSIZE to zero
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     head/tail initialized to NULL and 
 **listSIZE initialized to zero
 *************************************************************/
LineupList::LineupList()
{
    head = NULL;
    tail = NULL;
    listSIZE = 0;
}

/*************************************************************
 **Function:        ~LineupList()
 **Description:     Destructor(EMPTY)
 **Starts at head of list and traverses through, deallocating 
 **each next pointer through the temp variable trash.
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
LineupList::~LineupList()
{
    LineupNode *temp = head;        //Begin at head of list, and traverse through deallocating
    while(temp != NULL)
    {
        LineupNode *trash = temp;   //Assign first node to trash
        temp = temp->next;          //Assign second node to temp
        delete trash;               //Delete first node
        if(temp == NULL)            //So we don't access NULL pointers
        {
            break;
        }
    }
}

/*************************************************************
 **Function:        getListSIZE()
 **Description:     Returns listSIZE
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
int LineupList::getListSIZE()
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
LineupList::LineupNode* LineupList::getTop()
{
    return head;
}

/*************************************************************
 **Function:        LineupNode()
 **Description:     Constructor(EMPTY) to create nodes
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
LineupList::LineupNode::LineupNode()
{
    //EMPTY IN ORDER TO CREATE NODES
}

/*************************************************************
 **Function:        add(Creature *)
 **Description:     If list is empty, it creates the first node.
 **It will assign the pointer to Creature passed by value, to 
 **the local pointer to Creature variable ptrCreature.  Sets
 **the first node's previous pointer to point to NULL(as the 
 **first node in a doubly linked list must point to NULL).
 **Assigns head to point to this new node and this new node 
 **remains at the top. 
 **
 **If the list is not empty, it creates a new node after 
 **the node tail points to.  We make this new node's previous
 **pointer to point to the same node tail is pointing to.  The
 **same node tail point's to's next pointer will now point to
 **this new node.  Then change tail to point to this new node.
 **
 **Both cases increment listSIZE by 1.
 **Parameters:          Pointer to Creature
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void LineupList::add(Creature * pC)
{
    if(!head)                               //If list is empty, create first node
    {
        LineupNode *newNode = new LineupNode;
        
        newNode->ptrCreature = pC;          //Assigns pointer to Creature to ptrCreature
        newNode->previous = NULL;           //First node in a doubly linked list must point to NULL
        head = newNode;                     //Head now points to this new node.  This node remains at the "top".
        tail = newNode;
        
        listSIZE += 1;                      //Increment list size
    }
    else
    {
        LineupNode *newNode = new LineupNode;
        
        newNode->ptrCreature = pC;          //Assigns pointer to Creature to ptrCreature
        newNode->previous = tail;           //Tail points to the node before this newNode.  We want this newNode's previous pointer to also                     point to the node before.
        tail->next = newNode;               //Node before this' next pointer, now points to this newNode.
        
        tail = newNode;                     //Tail now points to new "last" node
        
        listSIZE += 1;                      //Increment list size
    }
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
Creature * LineupList::remove()
{
    LineupNode *current;
    
    if(!head)
    {
        cout << "There are no nodes to remove." <<endl;
        return 0;
    }
    else
    {
        Creature *topCreature;
        current = head;                     //Now current points to the same "top" node as head
        topCreature = current->ptrCreature; //Assigning the ptr to Creature in that first node to topCreature
        head = head->next;                  //Head points to first node, accesses the pointer to next node and assigns it to head.
                                            //Head now is pointing to the node in position 2.
        delete current;                     //Deleting the current value, which is pointing at the first node
        
        listSIZE -= 1;                      //Decrement list size
        return topCreature;
        
    }
}

/*************************************************************
 **Function:        addLast(Creature *)
 **Description:     Assign the pointer to Creature passed by 
 **value, to the local pointer to Creature variable ptrCreature.  
 **We create a new node after tail, and make it's previous
 **pointer point to tail's node.  We want tail's next node to 
 **point to this new node.  Then we make tail point to this new
 **node.  Assign new node's next pointer to NULL since it is the
 **last node in the list.  
 **
 **Increment listSIZE by 1.
 **Parameters:          Pointer to Creature
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void LineupList::addLast(Creature * pC)
{
    LineupNode *newNode = new LineupNode;
    
    newNode->ptrCreature = pC;              //Assigns pointer to Creature to ptrCreature
    newNode->previous = tail;               //Tail points to the node before this newNode.  We want this newNode's previous pointer to also point to the node before.
    tail->next = newNode;                   //Node before this' next pointer, now points to this newNode.
    
    tail = newNode;                         //Tail now points to new "last" node
    tail->next = NULL;                      //Last node's next pointer points to NULL
    
    listSIZE += 1;                          //Increment list size
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
void LineupList::displayList()
{
    LineupNode *show = head;
    
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