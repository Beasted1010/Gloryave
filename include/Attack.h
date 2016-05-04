#ifndef ATTACK_H
#define ATTACK_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

class Attack
{
    public:
        Attack();
        void Display_Attacks(vector<string> attacks);
        virtual ~Attack();
    protected:
    private:
};

#endif // ATTACK_H
