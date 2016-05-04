#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

class Enemy
{
    int level;
    int attack;
    bool killed;
    string type;
    int hp;
    int xp;


    public:
        void Result(bool killed);
        void Got_hit(int attack_power);
        int Attack();
        Enemy();

        virtual ~Enemy();
        int get_hp(){return hp;}
        int get_xp(){return xp;}
        void addTo_hp(int newHP){hp += newHP;}
        int get_attack(){return attack;}
        void set_attack(int newAttack){attack = newAttack;}
    protected:
};

#endif // ENEMY_H
