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
        int get_hp();
        int get_xp();
        int addTo_hp(int newHP);
    protected:
};

#endif // ENEMY_H
