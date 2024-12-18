#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

using namespace std;

int lastATK = 0;

class Weapon{

public:
    Weapon(string name, int damage){
        name_ = name;
        damage_ = damage;
        durability_ = 10;
    }
    
    Weapon(string name, int damage, int durability){
        name_ = name;
        damage_ = damage;
        durability_ = durability;
    }

    virtual int attack(){
        cout << "j'attack!\n";
        
        if (durability_ >0 ) durability_ --;
        if (durability_ == 0){
             damage_ = 0;
             cout << "your weapon is broken\n";

        }
        
        lastATK = damage_;

        return damage_;
    }

    string getName(){
        return name_;
    }

    virtual string getDescription(){
        return name_ + "," + to_string(damage_);
    }

    bool isBroken(){
        if (durability_ <=0 ) return true;
        return false;
    }

protected:
    string name_;
    int damage_;
    int durability_;
};

#endif //WEAPON