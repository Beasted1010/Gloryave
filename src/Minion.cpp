


#include "Minion.h"

Minion::Minion()
{
    cout << "This opponent is a MINION!" << endl;
    cout << "Minions are tough opponents with +50 hp!" << endl;
    cout << "OLD HP:" << get_hp() << endl;
    addTo_hp(50);
    cout << "Your opponent now has " << get_hp() << " HP!" << endl;
}
