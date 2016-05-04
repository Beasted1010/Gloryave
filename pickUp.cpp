#include "pickUp.h"
#include "Hero.h"
#include "Survival.h"

//TODO:... implement this, maybe try with inheritance? maybe not lol
pickUp::pickUp(int chance)
{
    if(chance < 6)
    {
        incr_heroHP();
    }
    else if(chance < 50)
    {

    }
    else if(chance < 80)
    {

    }
    else if( chance < 90)
    {

    }
    else
    {

    }
}

int pickUp::incr_heroHP()
{
    cout << "Extra HP!" << endl;
    return 25;
}

pickUp::~pickUp()
{
    //dtor
}
