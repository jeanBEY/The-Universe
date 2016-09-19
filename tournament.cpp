/***********************************************************
 **CLASS:            TOURNAMENT
 **
 **DESCRIPTION:      CPP FILE
 **
 **Holds the contents of the universe game:  Player 1,
 **Player 2, the menu, and the functions to start the combat.
 ***********************************************************/

#include "tournament.hpp"

/*************************************************************
 **Function:        Tournament()
 **Description:     Instantiates Tournament object
 **Parameters:
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
Tournament::Tournament()
{
    
}

/*************************************************************
 **Function:        menu()
 **Description:     Asks user whether they want to quit or play
 **(displays blow by blow)
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void Tournament::menu()
{
    int choice;
    
    cout << "Welcome to the Tournament! " <<endl <<endl;
    cout << "Would you like to play or quit? " <<endl;
    cout << "Enter 1 to play OR 2 to quit. " <<endl;
    cin >> choice;
    cin.ignore();
    
    if(choice == 1)
    {
        cout << "Would you like the blow by blow to display?";
        cout << "Enter 1 for YES or 0 for NO" <<endl;
        cin >> blowBYBlow;
        cin.ignore();
        
        setTEAM1();             //Set Team #1
        setTEAM2();             //Set Team #2
        
        if(blowBYBlow)
        {
            cout << "STARTING LINEUP 1:" <<endl <<endl;
            lineup1.displayList();
            cout << endl << "STARTING LINEUP 2:" <<endl <<endl;
            lineup2.displayList();
        }
        
        int count = 1;
        
        /*
         **While there is a node at the top of each lineup,
         **representing the next Creature in line to fight,
         **then match() is called.  If it is a tie, then the
         **do while loop iterates again, until there is no
         **tie.  Then endMatch() is called to handle winner/loser.
         */
        while((lineup1.getTop() != NULL) && (lineup2.getTop() != NULL))
        {
            cout << endl << "*******MATCH: " <<count << " **********" <<endl;
            do
            {
                match();
                
            }while((lineup1.getTop()->ptrCreature->getsPoints()) ==
                   (lineup2.getTop()->ptrCreature->getsPoints()));

            endMatch();
            count++;
        }
        
        if(blowBYBlow)
        {
            cout << endl << "ENDING LINEUP 1: " <<endl <<endl;
            lineup1.displayList();
        
            cout << endl << "ENDING LINEUP 2: " <<endl <<endl;
            lineup2.displayList();
        
            cout << endl << "ENDING LOSERS: " <<endl <<endl;
            losers.displayList();
        }
        
        //Display 1st, 2nd, 3rd, their teams, and which side scored more points
        displayWinners();
        
        //Display Loser Pile
        cout << "LOSER PILE: " <<endl <<endl;
        losers.displayList();
        
        //DELETE LINEUPS AND LOSERS LIST
        while((lineup1.getTop()) != NULL)
        {
            lineup1.remove();
        }
        
        while((lineup2.getTop()) != NULL)
        {
            lineup2.remove();
        }
        
        while((losers.getTop()) != NULL)
        {
            losers.remove();
        }
        
        cout << endl << "THANKS FOR PLAYING!" <<endl <<endl;
        
        menu();
        
    }
    else if(choice ==2)
    {
        quit();
    }
    else
    {
        cout << "Please enter valid input, try again..." <<endl <<endl;
        menu();
    }
}

/*************************************************************
 **Function:        quit()
 **Description:     Quits program, by returning 0
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
int Tournament::quit()
{
    return 0;
}

/*************************************************************
 **Function:        displayWinners()
 **Description:     Assigns Pointer to Creatures to elements of
 **array.  Sort the array by the data member goldPoints.  
 **Display each creature by decrementing backwards in the array
 **showing the Creatures that scored the highest amount of points
 **as the winners. 
 **
 **Show team that scored most points.
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void Tournament::displayWinners()
{
    Creature **array;
    array = new Creature * [6];
    array[0] = pCreature1;
    array[1] = pCreature2;
    array[2] = pCreature3;
    array[3] = pCreature4;
    array[4] = pCreature5;
    array[5] = pCreature6;
    
    Creature **temp;
    temp = new Creature * [6];
    for(int i = 0; i < 6; i++)
    {
        temp[i] = array[i];
    }
    
    //SORT ALGORITHM
    Creature *pCtemp;
    bool change;
    
    do
    {
        change = false;
        for(int i = 0; i < (6-1); i++)
        {
            if(temp[i]->getGoldPoints() > temp[i +1]->getGoldPoints())
            {
                pCtemp = temp[i];
                temp[i] = temp[i + 1];
                temp[i + 1] = pCtemp;
                change = true;
            }
        }
    } while(change); //if there was a change in the last do loop, then there's a chance it still needs to be sorted.
                     //if there was NO change, then the list has been completely sorted
    
    //PRESENT WINNERS TO SCREEN (ONLY DISPLAY THE FIRST THREE CREATURES IN THE TEMP ARRAY
    cout << "THE WINNERS ARE..." <<endl <<endl;
    int place = 1;
    for(int k = 5; k > 2; k--)
    {
        cout << "#" << place << " PLACE: " <<endl <<endl;
        cout << "Team: " << temp[k]->getTEAM() << " " <<endl;
        cout << "Type: " << temp[k]->getCreatureType() << " " <<endl;
        cout << "Name: " << temp[k]->getName() << " " <<endl;
        cout << "Gold Points: " << temp[k]->getGoldPoints() << " " <<endl <<endl;
        
        place++;
    }
    
    //SHOW TEAM THAT SCORED MOST POINTS
    cout << endl << "The team that scored the most points are: " <<endl <<endl;
    if(team1POINTS > team2POINTS)
    {
        cout << "****TEAM 1!****" <<endl << endl;
    }
    else
    {
        cout << "****TEAM 2!****" <<endl <<endl;
    }
    
}

/*************************************************************
 **Function:        match()
 **Description:     If both players at the top of the list
 **have strength points above zero, then the fighting continues
 **until one of them dies.
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void Tournament::match()
{
    //while strength points of head Creatures are ABOVE zero, fight via rounds
    //once one of them dies, or gets BELOW zero strength points, the fighting stops
    //if there is a tie meaning both their sPoints are equal, both get to roll a dice for gold points
    
    while((lineup1.getTop()->ptrCreature->getsPoints()) > 0 && (lineup2.getTop()->ptrCreature->getsPoints() > 0))
    {
        round(lineup1.getTop()->ptrCreature, lineup1.getTop()->ptrCreature->getType(),
            lineup2.getTop()->ptrCreature, lineup2.getTop()->ptrCreature->getType());
    }
}

/*************************************************************
 **Function:        endMatch()
 **Description:     Compares the strength points of Creatures
 **at the top of each list and displays which one is the winner.
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void Tournament::endMatch()
{
    cout <<endl << "The fighting is done!" <<endl;
    cout <<endl << "The winner of this MATCH is: " <<endl <<endl;
    
    if((lineup1.getTop()->ptrCreature->getsPoints()) > (lineup2.getTop()->ptrCreature->getsPoints()))
    {
        cout << "Player from Lineup #1 wins!  Congrats " ;
        cout << lineup1.getTop()->ptrCreature->getName() << " the " << lineup1.getTop()->ptrCreature->getCreatureType() << " ! " <<endl <<endl;
        
        lineup1.getTop()->ptrCreature->restorePoints();     //winner gets strength points restored
        lineup1.getTop()->ptrCreature->rollGold();          //winner earns gold points
        team1POINTS += 1;                                   //TEAM 1 earns one point
        
        lineup1.addLast(lineup1.getTop()->ptrCreature);     //add the winner to back of list
        lineup1.remove();                                   //remove winner from front of list
        
        losers.add(lineup2.getTop()->ptrCreature);          //add loser to loser list
        lineup2.remove();                                   //remove loser from lineup
        
    }
    else if((lineup2.getTop()->ptrCreature->getsPoints()) > (lineup1.getTop()->ptrCreature->getsPoints()))
    {
        cout << "Player from Lineup #2 wins!  Congrats " ;
        cout << lineup2.getTop()->ptrCreature->getName() << " the " << lineup2.getTop()->ptrCreature->getCreatureType() << " ! " <<endl <<endl;
        
        lineup2.getTop()->ptrCreature->restorePoints();     //winner gets strength points restored
        lineup2.getTop()->ptrCreature->rollGold();          //winner earns gold points
        team2POINTS += 1;                                   //TEAM 2 earns 1 point
        
        lineup2.addLast(lineup2.getTop()->ptrCreature);     //add the winner to back of list
        lineup2.remove();                                   //remove winner from front of list
        
        lineup2.addLast(lineup2.getTop()->ptrCreature);     //add the winner to back of list
        lineup2.remove();                                   //remove winner from front of list
        
        losers.add(lineup1.getTop()->ptrCreature);          //add loser to loser list
        lineup1.remove();                                   //remove loser from lineup

    }

}


/*************************************************************
 **Function:        round()
 **Description:     Calls attack()/defense() methods to allow
 **2 Creatures to fight one round.
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void Tournament::round(Creature * & ptrC1, int type1, Creature * & ptrC2, int type2)
{
    if(blowBYBlow)
    {
        cout << endl << "Player 1 Creature sPoints before fight:  " << ptrC1->getsPoints() <<endl;
        cout << "Player 2 Creature sPoints before fight:  " << ptrC2->getsPoints() <<endl;
    }
    
    int damageO1 = 0;
    int damageO2 = 0;
    
    //***************PLAYER 1 AGAINST PLAYER 2
    //Call Player 1's attack() and store value in damage01
    switch(type1)
    {
        case 1:  damageO1 = ptrC1->attack();
            break;
        case 2:  damageO1 = ptrC1->attack();
            if(damageO1 == 12)
            {
                static_cast<Medusa *>(ptrC1)->glare(ptrC2);
                if(blowBYBlow)
                {
                    cout << endl << "*****Player 1:  Medusa has just used her GLARE attack*****" <<endl <<endl;
                }
            }
            break;
        case 3: damageO1 = ptrC1->attack();
            break;
        case 4: damageO1 = ptrC1->attack();
            break;
        case 5:  damageO1 = ptrC1->attack();
            break;
        default: ;
    }
    
    if(blowBYBlow)
    {
        cout << "Player 1 attack roll:  " << damageO1 <<endl;
        cout << "Player 2 DEFENSE " <<endl;
    }
    
    switch(type2)
    {
        case 1:  ptrC2->defense(damageO1);
            break;
        case 2: ptrC2->defense(damageO1);
            break;
        case 3: ptrC2->defense(damageO1);
            break;
        case 4: ptrC2->defense(damageO1);
            break;
        case 5:  ptrC2->defense(damageO1);
            break;
        default: ;
    }
    
    //***************PLAYER 2 AGAINST PLAYER 1
    switch(type1)
    {
        case 1:  damageO2 = ptrC2->attack();
            break;
        case 2: damageO2 = ptrC2->attack();
            if(damageO2 == 12)
            {
                static_cast<Medusa *>(ptrC2)->glare(ptrC1);
                if(blowBYBlow)
                {
                    cout << endl << "*****Player 2:  Medusa has just used her GLARE attack*****" <<endl <<endl;
                }
            }
            break;
        case 3: damageO2 = ptrC2->attack();
            break;
        case 4: damageO2 = ptrC2->attack();
            break;
        case 5:  damageO2 = ptrC2->attack();
            break;
        default: ;
    }
    
    if(blowBYBlow)
    {
        cout << "Player 2 attack roll:  " << damageO2 <<endl;
        cout << "Player 1 DEFENSE " <<endl;
    }
        
    switch(type2)
    {
        case 1:  ptrC1->defense(damageO2);
            break;
        case 2: ptrC1->defense(damageO2);
            break;
        case 3: ptrC1->defense(damageO2);
            break;
        case 4: ptrC1->defense(damageO2);
            break;
        case 5:  ptrC1->defense(damageO2);
            break;
        default: ;
    }
    
    if(blowBYBlow)
    {
        cout << "Player 1 sPoints AFTER fight:  " << ptrC1->getsPoints() <<endl;
        cout << "Player 2 sPoints AFTER fight:  " << ptrC2->getsPoints() <<endl <<endl;
    }
    
}


//*********************************************************************************************************
//
//                                        CREATING THE LINEUPS
//
//*********************************************************************************************************

/*************************************************************
 **Function:        setTEAM1()
 **Description:     Prompts user to enter creature type, 
 **& name to create Creatures.  Then adds pointer to those 
 **Creatures to the node list.
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void Tournament::setTEAM1()
{
    cout << "PLAYER 1, let's choose your 3 Creatures!" <<endl <<endl;
    cout << "1. Barbarian " <<endl;
    cout << "2. Medusa" <<endl;
    cout << "3. Vampire" <<endl;
    cout << "4. Blue Men" <<endl;
    cout << "5. Harry Potter" <<endl <<endl;
    cout << "Enter your choice for Creature #1, then press enter: " <<endl;
    cin >> choiceC1;
    cin.ignore();
    
    cout << "Enter your choice for Creature #2, then press enter: " <<endl;
    cin >> choiceC2;
    cin.ignore();
    
    cout << "Enter your choice for Creature #3, then press enter: " <<endl;
    cin >> choiceC3;
    cin.ignore();
    
    /**********************
     CREATURE #1
     **********************/
    switch(choiceC1)
    {
        case 1: createBarbarian(pCreature1);
            pCreature1->setTEAM(1);
            pCreature1->setType(choiceC1);
            break;
        case 2: createMedusa(pCreature1);
            pCreature1->setTEAM(1);
            pCreature1->setType(choiceC1);
            break;
        case 3: createVampire(pCreature1);
            pCreature1->setTEAM(1);
            pCreature1->setType(choiceC1);
            break;
        case 4: createBlueMen(pCreature1);
            pCreature1->setTEAM(1);
            pCreature1->setType(choiceC1);
            break;
        case 5: createHarryPotter(pCreature1);
            pCreature1->setTEAM(1);
            pCreature1->setType(choiceC1);
            break;
        default: cout << "Invalid input, please start over..." <<endl;
            setTEAM1();
    }
    
    /**********************
     CREATURE #2
     **********************/
    switch(choiceC2)
    {
        case 1: createBarbarian(pCreature2);
            pCreature2->setTEAM(1);
            pCreature2->setType(choiceC2);
            break;
        case 2: createMedusa(pCreature2);
            pCreature2->setTEAM(1);
            pCreature2->setType(choiceC2);
            break;
        case 3: createVampire(pCreature2);
            pCreature2->setTEAM(1);
            pCreature2->setType(choiceC2);
            break;
        case 4: createBlueMen(pCreature2);
            pCreature2->setTEAM(1);
            pCreature2->setType(choiceC2);
            break;
        case 5: createHarryPotter(pCreature2);
            pCreature2->setTEAM(1);
            pCreature2->setType(choiceC2);
            break;
        default: cout << "Invalid input, please start over..." <<endl;
            setTEAM1();
    }
    
    /**********************
     CREATURE #3
     **********************/
    switch(choiceC3)
    {
        case 1: createBarbarian(pCreature3);
            pCreature3->setTEAM(1);
            pCreature3->setType(choiceC3);
            break;
        case 2: createMedusa(pCreature3);
            pCreature3->setTEAM(1);
            pCreature3->setType(choiceC3);
            break;
        case 3: createVampire(pCreature3);
            pCreature3->setTEAM(1);
            pCreature3->setType(choiceC3);
            break;
        case 4: createBlueMen(pCreature3);
            pCreature3->setTEAM(1);
            pCreature3->setType(choiceC3);
            break;
        case 5: createHarryPotter(pCreature3);
            pCreature3->setTEAM(1);
            pCreature3->setType(choiceC3);
            break;
        default: cout << "Invalid input, please start over..." <<endl;
            setTEAM1();
    }
    
    //ADDING CREATURES TO LINEUP #1
    lineup1.add(pCreature1);
    lineup1.add(pCreature2);
    lineup1.addLast(pCreature3);
    cout << "Great job PLAYER 1!  You've created your lineup!" <<endl <<endl;
}

/*************************************************************
 **Function:        setTEAM2()
 **Description:     Prompts user to enter creature type,
 **& name to create Creatures.  Then adds pointer to those
 **Creatures to the node list.
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void Tournament::setTEAM2()
{
    cout << "PLAYER 2, let's choose your 3 Creatures!" <<endl <<endl;
    cout << "1. Barbarian " <<endl;
    cout << "2. Medusa" <<endl;
    cout << "3. Vampire" <<endl;
    cout << "4. Blue Men" <<endl;
    cout << "5. Harry Potter" <<endl <<endl;
    cout << "Enter your choice for Creature #1, then press enter: " <<endl;
    cin >> choiceC4;
    cin.ignore();
    
    cout << "Enter your choice for Creature #2, then press enter: " <<endl;
    cin >> choiceC5;
    cin.ignore();
    
    cout << "Enter your choice for Creature #3, then press enter: " <<endl;
    cin >> choiceC6;
    cin.ignore();
    
    /**********************
     CREATURE #1
     **********************/
    switch(choiceC4)
    {
        case 1: createBarbarian(pCreature4);
            pCreature4->setTEAM(2);
            pCreature4->setType(choiceC4);
            break;
        case 2: createMedusa(pCreature4);
            pCreature4->setTEAM(2);
            pCreature4->setType(choiceC4);
            break;
        case 3: createVampire(pCreature4);
            pCreature4->setTEAM(2);
            pCreature4->setType(choiceC4);
            break;
        case 4: createBlueMen(pCreature4);
            pCreature4->setTEAM(2);
            pCreature4->setType(choiceC4);
            break;
        case 5: createHarryPotter(pCreature4);
            pCreature4->setTEAM(2);
            pCreature4->setType(choiceC4);
            break;
        default: cout << "Invalid input, please start over..." <<endl;
            setTEAM2();
    }
    
    /**********************
     CREATURE #2
     **********************/
    switch(choiceC5)
    {
        case 1: createBarbarian(pCreature5);
            pCreature5->setTEAM(2);
            pCreature5->setType(choiceC5);
            break;
        case 2: createMedusa(pCreature5);
            pCreature5->setTEAM(2);
            pCreature5->setType(choiceC5);
            break;
        case 3: createVampire(pCreature5);
            pCreature5->setTEAM(2);
            pCreature5->setType(choiceC5);
            break;
        case 4: createBlueMen(pCreature5);
            pCreature5->setTEAM(2);
            pCreature5->setType(choiceC5);
            break;
        case 5: createHarryPotter(pCreature5);
            pCreature5->setTEAM(2);
            pCreature5->setType(choiceC5);
            break;
        default: cout << "Invalid input, please start over..." <<endl;
            setTEAM2();
    }
    
    /**********************
     CREATURE #3
     **********************/
    switch(choiceC6)
    {
        case 1: createBarbarian(pCreature6);
            pCreature6->setTEAM(2);
            pCreature6->setType(choiceC6);
            break;
        case 2: createMedusa(pCreature6);
            pCreature6->setTEAM(2);
            pCreature6->setType(choiceC6);
            break;
        case 3: createVampire(pCreature6);
            pCreature6->setTEAM(2);
            pCreature6->setType(choiceC6);
            break;
        case 4: createBlueMen(pCreature6);
            pCreature6->setTEAM(2);
            pCreature6->setType(choiceC6);
            break;
        case 5: createHarryPotter(pCreature6);
            pCreature6->setTEAM(2);
            pCreature6->setType(choiceC6);
            break;
        default: cout << "Invalid input, please start over..." <<endl;
            setTEAM2();
    }
    
    //ADDING CREATURES TO LINEUP #2
    lineup2.add(pCreature4);
    lineup2.add(pCreature5);
    lineup2.addLast(pCreature6);
    cout << "Great job PLAYER 2!  You've created your lineup!" <<endl <<endl;
}


//*********************************************************************************************************
//
//                                        CREATING THE CREATURES
//
//*********************************************************************************************************

/*************************************************************
 **Function:        createBarbarian(Creature *&)
 **Description:     After user chooses to use Barbarian, this
 **creates a new Barbarian object dynamically and assigns it
 **to the pointer to Creature passed by reference.
 **
 **Parameters:          Creature *&(player 1 or player 2)
 **Pre-Conditions:      N/A
 **Post-Conditions:     pointer to Creature is assigned new
 **Barbarian object
 *************************************************************/
void Tournament::createBarbarian(Creature * & pCreat)
{
    int armor = 0;
    int sPoints = 12;
    string type = "Barbarian";
    string cName;
    cout << "What is the name of this Barbarian?" <<endl;
    cin >> cName;
    cin.ignore();
    
    pCreat = new Barbarian(armor, sPoints, type, cName);
    pCreat->setBBB(blowBYBlow);
}

/*************************************************************
 **Function:        createMedusa(Creature *&)
 **Description:     After user chooses to use Medusa, this
 **creates a new Medusa object dynamically and assigns it to
 **the pointer to Creature passed by reference.
 **
 **Parameters:          Creature *&(player 1 or player 2)
 **Pre-Conditions:      N/A
 **Post-Conditions:     pointer to Creature is assigned new
 **Medusa object
 *************************************************************/
void Tournament::createMedusa(Creature * & pCreat)
{
    int armor = 3;
    int sPoints = 8;
    string type = "Medusa";
    string cName;
    cout << "What is the name of this Medusa?" <<endl;
    cin >> cName;
    cin.ignore();
    
    pCreat = new Medusa(armor, sPoints, type, cName);
    pCreat->setBBB(blowBYBlow);
}

/*************************************************************
 **Function:        createVampire(Creature *&)
 **Description:     After user chooses to use Vampire, this
 **creates a new Vampire object dynamically and assigns it to
 **the pointer to Creature passed by reference.
 **
 **Parameters:          Creature *&(player 1 or player 2)
 **Pre-Conditions:      N/A
 **Post-Conditions:     pointer to Creature is assigned new
 **Vampire object
 *************************************************************/
void Tournament::createVampire(Creature * & pCreat)
{
    int armor = 1;
    int sPoints = 18;
    string type = "Vampire";
    string cName;
    cout << "What is the name of this Vampire?" <<endl;
    cin >> cName;
    cin.ignore();
    
    pCreat = new Vampire(armor, sPoints, type, cName);
    pCreat->setBBB(blowBYBlow);
}

/*************************************************************
 **Function:        createHarryPotter(Creature *&)
 **Description:     After user chooses to use HarryPotter, this
 **creates a new HarryPotter object dynamically and assigns it
 **to the pointer to Creature passed by reference.
 **
 **Parameters:          Creature *&(player 1 or player 2)
 **Pre-Conditions:      N/A
 **Post-Conditions:     pointer to Creature is assigned new
 **HarryPotter object
 *************************************************************/
void Tournament::createHarryPotter(Creature * & pCreat)
{
    int armor = 0;
    int sPoints = 10;
    string type = "Harry Potter";
    string cName;
    cout << "What is the name of this Harry Potter?" <<endl;
    cin >> cName;
    cin.ignore();
    
    pCreat = new HarryPotter(armor, sPoints, type, cName);
    pCreat->setBBB(blowBYBlow);
}

/*************************************************************
 **Function:        createBlueMen(Creature *&)
 **Description:     After user chooses to use BlueMen, this
 **creates a new BlueMen object dynamically and assigns it to
 **the pointer to Creature passed by reference.
 **
 **Parameters:          Creature *&(player 1 or player 2)
 **Pre-Conditions:      N/A
 **Post-Conditions:     pointer to Creature is assigned new
 **BlueMen object
 *************************************************************/
void Tournament::createBlueMen(Creature * & pCreat)
{
    int armor = 3;
    int sPoints = 12;
    string type = "Blue Men";
    string cName;
    cout << "What is the name of this Blue Men?" <<endl;
    cin >> cName;
    cin.ignore();
    
    pCreat = new BlueMen(armor, sPoints, type, cName);
    pCreat->setBBB(blowBYBlow);

}
