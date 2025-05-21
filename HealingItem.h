#ifndef HEALING_ITEM_H
#define HEALING_ITEM_H

#include <iostream>
#include <string>
#include "Item.h"

class HealingItem : public Item{
    public:
    HealingItem(int healthRecovered) : Item(name) {
        healthRecovered_ += healthRecovered;
    }

    int useItem(int* health) {
        Item::useItem();

        return health += healthRecovered_;


    } 


    private:
    int healthRecovered_ = 0;
}