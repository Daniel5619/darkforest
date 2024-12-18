#ifndef SUPER_WEAPON_H
#define SUPER_WEAPON_H

#include <string>
#include "Weapon.h"

using namespace std;

const int MAX_ATK = 256;

class SuperWeapon : public Weapon{

    private:
        int doubler_;
        int superDamage_;

    public: 
        SuperWeapon(string name, int damage) : Weapon(name, damage) {
            doubler_=1;
            superDamage_=1;
        }

        int attack() {
            Weapon::attack();

            superDamage_ = doubler_ * damage_;
            
            if (doubler_ < MAX_ATK){
                doubler_ = doubler_ * 2;
            }

            cout << "super j'attack damange!" << superDamage_ << "\n";
            lastATK = superDamage_;

            return superDamage_;
        }

        string getDescription(){
            return name_ + "," + to_string(superDamage_);
        }

};

#endif //SUPER_WEAPON_H