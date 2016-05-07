/***************************************************************************************************
PROGRAM     : let's_make_a_deal_pseudo_percentage.cpp
PURPOSE        : This program will compute the pseudo result of the game "Let's Make a Deal" for 10000  times.
                             In fact, the program is made to answer  the famous question in the game,
                             "is it to the player's advantage to switch doors?"  After running the program,
                             it will show the total number of wins and loses along with the overall percentage
                             of winning in different situations. It won't take any input. The user just need to run
                             the program and analyze the result to understand the answer of this question.
Coder                : Mosfiqur Rahman (mr986@drexel.edu)
Last Modified : 1st March, 2016.
***************************************************************************************************/

#include <iostream>  // for  having input and output
#include <ctime>      //  for seeding the random number generator using the system's clock
#include <cstdlib>  // for generating random numbers

using namespace std; //for using standard library namespace

void setupDoors (  char &door1,  char &door2,  char &door3);
// Prototyping  function setupDoors, which will setup the position of
// the Car and the two Goats randomly behind the three doors

void pickDoorChoices(char door1, char door2, char door3, int  &doorPlayer, int &doorMonty);
// Prototyping the function pickDoorChoices, which will make the right choice randomly
// for the door that will be picked by Monty according to the choice of the Player

void chance_of_win ( char door1, char door2, char door3, int  doorPlayer, int doorMonty);
// Prototyping the chance_of_win function, which will compute  the pseudo result of the
// game "Let's Make a Deal" for 10000  times along with the overall percentage
//of winning in different situations


// The following function is the main function
int main()
  {
    char door1, door2, door3;
    // Declaring three character variable named door1, door2, and door3 respectively for storing
    // the value of the object behind the door

    int doorPlayer, doorMonty;
    // Declaring two integer variables  named doorPlayer, and doorMonty to store the  position
    // of the door they pick up

    int seed = static_cast<int>(time(0));
    // Declaring and initializing an integer variable seed, using the system's clock
    srand(seed);
     // seeding the random number generator using the system's clock

        cout << "Hi, welcome to the my winning-percentage calculator! " << endl;
        // Optional, introductory texts
        cout << "I'll calculate a pseudo wining percentage in the famous game \"Let's Make a Deal\", and give you an idea how to beat Monty. "  << endl  << endl;
        // Optional, introductory texts
        cout  << "So, let's analyze the following data: " << endl << endl;
        // Optional, introductory texts

        for (int k = 0; k<6 ; k++)
        // Running a for loop to compute the result produced by the function chance_of_win for 6 times

        {
        chance_of_win (  door1,  door2, door3,  doorPlayer, doorMonty);
        // Calling the function chance_of_win
       cout << endl << endl; // Optional, irtoductory output
       cout << "////////////////////////////////////////////////////////////////////////////////";  // Optional, irtoductory output
       cout << endl << endl;  // Optional, irtoductory output
        }

    return 0;
  }

        /***
                                           The following function will setup the position of the Car and the two Goats randomly
                                           behind the three doors.

        @param  &door1  -  value of object behind the Door -  1
        @param  &door2  -  value of object behind the Door -  2
        @param  &door3  -  value of object behind the Door -  3

        ***/

void setupDoors (  char &door1,  char &door2,  char &door3)
// Defining the setupDoors function, which will will setup the position of
// the Car and the two Goats randomly behind the three doors

  {
        int door;
        //Declaring an integer variable door to store the number of the door

        door  =  1 + rand() % 3 ;
        //Initializing the variable door  by random numbers from 1 to 3 using rand() function

        if ( door  ==  1)
       // Checking whether the value of door is equal to 1 or not
        //If it's so then continues, or moves to other conditional statement.
        {
                door1  = 'C';
                // Initializing the value of the variable door1 to C
                door2  = 'G';
                // Initializing the value of the variable door2 to G
                door3  = 'G';
                // Initializing the value of the variable door3 to G
        }
        else  if ( door == 2)
        // Checking whether the value of door is equal to 2 or not
        //If it's so then continues, or moves to other conditional statement.
        {
                door1  = 'G';
                // Initializing the value of the variable door1 to G
                door2  = 'C';
                // Initializing the value of the variable door2 to C
                door3  = 'G';
                // Initializing the value of the variable door3 to G
        }
        else
        // If the previous 'if' and 'else if' statements fail, then the program run through this statement.
        {
                door1  = 'G';
                // Initializing the value of the variable door1 to G
                door2  = 'G';
                // Initializing the value of the variable door2 to G
                door3  = 'C';
                // Initializing the value of the variable door3 to C
        }
  }

        /***
                                        The following function will make the right choice randomly
                                        for the door that will be picked by Monty according to the choice of the Player
        @param  door1  -  value of object behind the Door -  1
        @param  door2  -  value of object behind the Door -  2
        @param  door3  -  value of object behind the Door -  3
        @param  &doorPlayer  -  the number of the door, picked by the Player
        @param  &doorMonty  -  the number of the door, picked by the Monty

        ***/

void pickDoorChoices(char door1, char door2, char door3, int  &doorPlayer, int &doorMonty)
// Defining the pickDoorChoices function, which will will make the right choice randomly
// for the door that will be picked by Monty acccording to the choice of the Player

  {
        int r1  =  1 + rand()  %  3;
        //Declaring and initializing the integer variable r1  by random numbers from 1 to 3 using rand() function
        doorPlayer  =  r1 ;
        // Initializing the value of  the variable doorPlayer by r1

       while ( true )
       //Running a while loop to find the right choice randomly
     // for the door that will be picked by Monty according to the choice of the Player
       {
                int r2 = 1 + rand()  %  3;
                 //Declaring and initializing the integer variable r2  by random numbers from 1 to 3 using rand() function
                doorMonty  =  r2;
                // Initializing the value of  the variable doorMonty by r2

                if ( doorMonty  ==  doorPlayer )
                // Checking whether the value of doorMonty is equal to doorPlayer or not
              //If it's so then continues, or moves to other conditional statement.
                    {
                        continue; // going directly to the test condition and then will continue the looping process
                    }
                else if ( doorMonty == 1 && door1 == 'C' )
                // Checking whether the value of doorMonty is equal to 1 or not, and the value of door1 is equal to C or not
              //If it's so then continues, or moves to other conditional statement.
                     {
                        continue; // going directly to the test condition and then will continue the looping process
                    }
                else if (doorMonty == 2 && door2 == 'C' )
                // Checking whether the value of doorMonty is equal to 2 or not, and the value of door2 is equal to C or not
              //If it's so then continues, or moves to other conditional statement.
                     {
                        continue; // going directly to the test condition and then will continue the looping process
                    }
                else if ( doorMonty == 3 && door3 == 'C' )
                // Checking whether the value of doorMonty is equal to 3 or not, and the value of door3 is equal to C or not
              //If it's so then continues, or moves to other conditional statement.
                     {
                        continue; // going directly to the test condition and then will continue the looping process
                    }
                else
                // If the previous 'if' and 'else if' statements fail, then the program run through this statement.
                     {
                        break; //  exiting the loop from this point
                    }
        }
  }

        /***
                        The following function will compute  the pseudo result of the game
                        "Let's Make a Deal" for 10000  times along with the overall percentage
                        of winning in different situations
        @param  door1  -  value of object behind the Door -  1
        @param  door2  -  value of object behind the Door -  2
        @param  door3  -  value of object behind the Door -  3
        @param  doorPlayer  -  the number of the door, picked by the Player
        @param  doorMonty  -  the number of the door, picked by the Monty

        ***/

void chance_of_win ( char door1, char door2, char door3, int  doorPlayer, int doorMonty)
// Defining the function chance_of_win, which will compute  the pseudo result of the
// game "Let's Make a Deal" for 10000  times along with the overall percentage
//of winning in different situations

  {
        int win_in_change = 0;
        //Declaring and initializing the integer variable win_in_change  with 0
        int lose_in_change = 0;
        //Declaring and initializing the integer variable lose_in_change  with 0
        int changingWon_percent = 0;
        //Declaring and initializing the integer variable changingWon_percent  with 0

        int win_without_change = 0;
        //Declaring and initializing the integer variable win_without_change  with 0
        int lose_without_change = 0;
        //Declaring and initializing the integer variable lose_without_change  with 0
        int stayingWon_percent = 0;
        //Declaring and initializing the integer variable stayingWon_percent  with 0

        for( int i = 0 ; i < 10000 ; i++)
        // Running a for loop to  compute total number of wins and loses along with the overall percentage
        // of winning  while the player changes his choice
        {

                setupDoors(door1, door2, door3);
                //Calling the function setupDoors
               pickDoorChoices(door1, door2,  door3,  doorPlayer,  doorMonty);
               //Calling the function pickDoorChoices

                if( doorPlayer == 1 && doorMonty == 2)
                // Checking whether the value of doorPlayer is equal to 1 or not, and the value of doorMonty is equal to 2 or not
              //If it's so then continues, or moves to other conditional statement.
                {
                        doorPlayer  = 3;
                        // Initializing the value of the variable doorPlayer to 3

                        if( door3 == 'C')
                         // Checking whether the value of door3 is equal to C or not
                         //If it's so then continues, or moves to other conditional statement.
                        {
                                win_in_change++;
                                //  Incrementing the value of the variable win_in_change
                        }
                        else
                        // If the previous 'if' statement fails, then the program run through this statement.
                        {
                                lose_in_change++;
                                //  Incrementing the value of the variable lose_in_change
                        }
                }
                else if( doorPlayer == 1 && doorMonty == 3)
                // Checking whether the value of doorPlayer is equal to 1 or not, and the value of doorMonty is equal to 3 or not
              //If it's so then continues, or moves to other conditional statement.
                {
                        doorPlayer  = 2;
                        // Initializing the value of the variable doorPlayer to 2

                         if( door2 == 'C')
                         // Checking whether the value of door2 is equal to C or not
                         //If it's so then continues, or moves to other conditional statement.
                        {
                                win_in_change++;
                                //  Incrementing the value of the variable win_in_change
                        }
                        else
                         // If the previous 'if' statement fails, then the program run through this statement.
                        {
                                lose_in_change++;
                                //  Incrementing the value of the variable lose_in_change
                        }
                }
                else if( doorPlayer == 2 && doorMonty == 3)
                // Checking whether the value of doorPlayer is equal to 2 or not, and the value of doorMonty is equal to 3 or not
              //If it's so then continues, or moves to other conditional statement.
                {
                        doorPlayer  = 1;
                        // Initializing the value of the variable doorPlayer to 1

                         if( door1 == 'C')
                         // Checking whether the value of door1 is equal to C or not
                         //If it's so then continues, or moves to other conditional statement.
                        {
                                win_in_change++;
                                //  Incrementing the value of the variable win_in_change
                        }
                        else
                         // If the previous 'if' statement fails, then the program run through this statement.
                        {
                                lose_in_change++;
                                //  Incrementing the value of the variable lose_in_change
                        }
                }
                else if( doorPlayer == 2 && doorMonty == 1)
                // Checking whether the value of doorPlayer is equal to 2 or not, and the value of doorMonty is equal to 1 or not
              //If it's so then continues, or moves to other conditional statement.
                {
                        doorPlayer  = 3;
                        // Initializing the value of the variable doorPlayer to 3

                         if( door3 == 'C')
                         // Checking whether the value of door3 is equal to C or not
                         //If it's so then continues, or moves to other conditional statement.
                        {
                                win_in_change++;
                                //  Incrementing the value of the variable win_in_change
                        }
                        else
                         // If the previous 'if' statement fails, then the program run through this statement.
                        {
                                lose_in_change++;
                                //  Incrementing the value of the variable lose_in_change
                        }
                }
                else if( doorPlayer == 3 && doorMonty == 2)
                // Checking whether the value of doorPlayer is equal to 3 or not, and the value of doorMonty is equal to 2 or not
              //If it's so then continues, or moves to other conditional statement.
                {
                        doorPlayer  = 1;
                        // Initializing the value of the variable doorPlayer to 1

                         if( door1 == 'C')
                         // Checking whether the value of door1 is equal to C or not
                         //If it's so then continues, or moves to other conditional statement.
                        {
                                win_in_change++;
                                //  Incrementing the value of the variable win_in_change
                        }
                        else
                         // If the previous 'if' statement fails, then the program run through this statement.
                        {
                                lose_in_change++;
                                //  Incrementing the value of the variable lose_in_change
                        }
                }
                else if( doorPlayer == 3 && doorMonty == 1)
                // Checking whether the value of doorPlayer is equal to 3 or not, and the value of doorMonty is equal to 1 or not
              //If it's so then continues, or moves to other conditional statement.
                {
                        doorPlayer  = 2;
                        // Initializing the value of the variable doorPlayer to 2

                         if( door2 == 'C')
                         // Checking whether the value of door2 is equal to C or not
                         //If it's so then continues, or moves to other conditional statement.
                        {
                                win_in_change++;
                                //  Incrementing the value of the variable win_in_change
                        }
                        else
                         // If the previous 'if' statement fails, then the program run through this statement.
                        {
                                lose_in_change++;
                                //  Incrementing the value of the variable lose_in_change
                        }
                }

        }
                cout << "Total win when changed: " << win_in_change << " times." << endl;
                // Showing the total number of wins when the Player changes his/her choice

                cout << "Total lose when changed:  " << lose_in_change << " times." <<endl;
                // Showing the total number of loses when the Player changes his/her choice

                changingWon_percent = (win_in_change * 100) / 10000;
                //Calculating the overall percentage of  winning when the Player changes his/her choice

                cout <<  endl << "Changing won " << changingWon_percent << " % of the time." << endl  << endl;
                //Showing  the overall percentage of  winning when the Player changes his/her choice

                for ( int j = 0; j<10000 ; j++)
                // Running a for loop to  compute total number of wins and loses along with the overall percentage
              // of winning  while the player doesn't change his choice
                {
                        setupDoors(door1, door2, door3);
                         //Calling the function setupDoors
                        pickDoorChoices(door1, door2,  door3,  doorPlayer,  doorMonty);
                        //Calling the function pickDoorChoices

                        if( doorPlayer == 1 && door1== 'C')
                         // Checking whether the value of doorPlayer is equal to 1 or not, and the value of door1 is equal to C or not
                       //If it's so then continues, or moves to other conditional statement.
                        {
                                win_without_change++;
                                //  Incrementing the value of the variable win_without_change
                        }

                        else if( doorPlayer == 2 && door2 == 'C')
                        // Checking whether the value of doorPlayer is equal to 2 or not, and the value of door2 is equal to C or not
                       //If it's so then continues, or moves to other conditional statement.
                        {
                                win_without_change++;
                                //  Incrementing the value of the variable win_without_change
                        }

                        else if( doorPlayer == 3 && door3 == 'C')
                        // Checking whether the value of doorPlayer is equal to 3 or not, and the value of door3 is equal to C or not
                       //If it's so then continues, or moves to other conditional statement.
                        {
                                win_without_change++;
                                //  Incrementing the value of the variable win_without_change
                        }
                        else
                        // If the previous 'if' and 'else if' statements fail, then the program run through this statement.
                        {
                               lose_without_change++;
                               //  Incrementing the value of the variable lose_without_change
                        }
                }
                cout << "Total win without changing:  " << win_without_change << " times." << endl;
                // Showing the total number of wins when the Player doesn't change his/her choice

                cout << "Total lose  without changing: " << lose_without_change << " times." << endl;
                // Showing the total number of loses when the Player doesn't change his/her choice

               stayingWon_percent = (win_without_change * 100) / 10000;
               //Calculating the overall percentage of  winning when the Player doesn't change his/her choice

                cout << endl << "Staying won " << stayingWon_percent << " % of the time." << endl;
                //Showing  the overall percentage of  winning when the Player doesn't change his/her choice
        }


                                                                                                                                                                /*** NOTE:  I couldn't make the program simpler than this. ***/


















