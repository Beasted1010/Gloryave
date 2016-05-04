#include "Attack.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

Attack::Attack()
{
    //ctor
}

Attack::Attack(vector<string> attacks)
{
    cout << attacks.front() << endl;
    cout << attacks.back() << endl;
}

Attack::~Attack()
{
    //dtor
}
