#ifndef WEAPONS_H
#define WEAPONS_H
#include <string>
using namespace std;

class Weapons
{
    string weapon_name;
    int weapon_power;

    public:
        Weapons();
        virtual ~Weapons();
    protected:
    private:
};

#endif // WEAPONS_H
