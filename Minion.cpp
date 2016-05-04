


#include "Minion.h"

Minion::Minion()
{
    cout << "This opponent is a MINION!" << endl;
    cout << "Minions are tough opponents with +50 hp!" << endl;
    addTo_hp(50);
    cout << "Your opponent now has " << get_hp() << " HP!" << endl;
    set_attack(35);
    cout << "Minion's attack is set at " << get_attack() << "!" << endl;
    cout << Attack() << endl;
}
