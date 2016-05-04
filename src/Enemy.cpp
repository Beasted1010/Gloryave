#include "Enemy.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

Enemy::Enemy()
{
    srand(time(NULL));
    level = rand() % 5 + 1;
    switch(level)
    {
    case 1:
        level = 1;
        type = "Really Weak Opponent";
        cout << type << endl;
        hp = rand() % 10 + 20;
        xp = rand() % 20 + 50;
        break;
    case 2:
        level = 2;
        type = "Weak Opponent";
        cout << type << endl;
        hp = rand() % 10 + 25;
        xp = rand() % 20 + 80;
        break;
    case 3:
        level = 3;
        type = "Challenging Opponent";
        cout << type << endl;
        hp = rand() % 10 + 35;
        xp = rand() % 20 + 150;
        break;
    case 4:
        level = 4;
        type = "Strong Opponent";
        cout << type << endl;
        hp = rand() % 10 + 50;
        xp = rand() % 20 + 200;
        break;
    case 5:
        level = 5;
        type = "Really Strong Opponent";
        cout << type << endl;
        hp = rand() % 10 + 70;
        xp = rand() % 20 + 300;
        break;
    }
}

void Enemy::Got_hit(int attack_power)
{
    hp -= attack_power;
}

void Enemy::Result(bool killed)
{
    if(killed == true)
    {
        cout << "You killed a " << type << "!" << endl;
    }
    else
    {
        cout << "The enemy fled!" << endl;
    }
}

int Enemy::Attack()
{
    srand(time(NULL));
    switch(level)
    {
    case 1:
        attack = rand() % 10 + 5;
        break;
    case 2:
        attack = rand() % 10 + 10;
        break;
    case 3:
        attack = rand()% 10 + 17;
        break;
    case 4:
        attack = rand() % 10 + 24;
        break;
    case 5:
        attack = rand() % 10 + 32;
        break;
    }
    return attack;

}

int Enemy::get_xp()
{
    return xp;
}

int Enemy::get_hp()
{
    return hp;
}

int Enemy::addTo_hp(int newHP)
{
    hp += newHP;
}

Enemy::~Enemy()
{
    //dcot
}
