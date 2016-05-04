#include "Hero.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

Hero::Hero()
{
    /*
    srand(time(NULL));
    HP = rand() % 80 + 20;
    XP = rand() % 100 + 20;
    */
}

Hero::Hero(int difficulty)
{
    srand(time(NULL));
    switch(difficulty)
    {
    case 1:
        HP = rand() % 80 + 200;
        XP = rand() % 100 + 20;
        break;
    case 2:
        HP = rand() % 80 + 150;
        XP = rand() % 100 + 100;
        break;
    case 3:
        HP = rand() % 80 + 90;
        XP = rand() % 100 + 200;
        break;
    case 4:
        HP = rand() % 80 + 40;
        XP = rand() % 100 + 350;
        break;
    }
}

int Hero::get_HP()
{
    return HP;
}

int Hero::set_HP(int hp)
{
    HP += hp;
}

void Hero::lose_HP(int loss)
{
    HP -= loss;
}

int Hero::get_XP()
{
    return XP;
}

int Hero::set_XP(int xp)
{
    XP += xp;
}

Hero::~Hero()
{
    //dtor
}
