#include "Attack.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

void Attack::Display_Attacks(vector<string> attacks)
{
    for(int i = 1; !attacks.empty(); i++)
    {
        cout << i << ". " << attacks.back() << endl;
        attacks.pop_back();
    }

}

Attack::Attack()
{

}

Attack::~Attack()
{
    //dtor
}
