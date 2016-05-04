#ifndef Attack_H
#define Attack_H
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
        Attack(vector<string> attacks);
        virtual ~Attack();
    protected:
    private:
};

#endif // Attack_H
