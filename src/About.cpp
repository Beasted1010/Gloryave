#include "About.h"
#include <iostream>
using namespace std;

About::About()
{
    int choice;
    char repeat;

    cout << "_____________________________________________________________________________________________________" << endl;
    cout << "-------------------------------------------------About-----------------------------------------------" << endl;
    cout << "Glorave v.  .30" << endl;

    cout << "ChangeLog" << endl;
    cout << "v. 0.10 Initial Creation with basic classes" << endl;
    cout << "v. 0.20 Created attack system and randomized events" << endl;
    cout << "v. 0.21 Organized classes and added optimizations, fixed slight bugs" << endl;
    cout << "v. 0.30 Added a GUI menu and updated game mechanics" << endl << endl;

    cout << "This is the first game created by the solo developer FuzzYdicE" << endl;
    cout << "This game was made after only a few months of exposure to coding" << endl;
    cout << "This game's intent is to serve as a learning opportunity to FuzzYdicE" << endl;
    cout << "Perhaps one day this game will take off in full development, having made large changes over its life" << endl << endl;

    do
    {
    cout << endl << endl << "Select from the following to read more about the 'mode' (1,2)" << endl;
    cout << "-----------------------------------------------------------------------------------------------------" << endl; //%20 = 3
    cout << "1. Adventure" << endl;
    cout << "2. Survival" << endl;
    cin >> choice;
    switch(choice)
    {
    case 1:
        cout << endl << "-----------------------------------------------Adventure---------------------------------------------" << endl;
        cout << "Adventure is the main story mode, which will be the largest part of the game." << endl;
        cout << "This mode is still under development" << endl;
        cout << "It is imagined to be based in a medieval realm" << endl;
        cout << "-----------------------------------------------------------------------------------------------------" << endl << endl; //%20 = 3
        break;
    case 2:
        cout << "------------------------------------------------Survival---------------------------------------------" << endl;
        cout << "This mode was the first to be developed and is expected to be largely adjusted and optimized" << endl;
        cout << "This is a 'play till you die' mode, challenging the user to test and develop their skills" << endl;
        cout << "It is imagined to be more of a 'mini game' where the player may build stats up and compete against past users" << endl;
        cout << "The stats earned here is also imagined to carry with the user outside the mode into adventure mode" << endl;
        cout << "This mode will develop with FuzzYdicE's knowledge of coding" << endl;
        cout << "-----------------------------------------------------------------------------------------------------" << endl << endl; //%20 = 3
        break;
    }
    cout << endl << endl <<"Choose again? (Y/N)" << endl;
    cin >> repeat;
    repeat = toupper(repeat);



    }while(repeat == 'Y');

}

/*
____________________
20
*/

About::~About()
{
    //dtor
}
