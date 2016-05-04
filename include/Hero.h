#ifndef HERO_H
#define HERO_H
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


class Hero
{
    int HP;
    int XP;

    public:
        Hero();
        Hero(int difficulty);
        virtual ~Hero();
        void lose_HP(int loss);
        int get_HP();
        int get_XP();
        int set_XP(int xp);
        int set_HP(int hp);
    protected:
    private:
};

#endif // HERO_H
