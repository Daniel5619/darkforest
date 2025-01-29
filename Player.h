#include <iostream>

class Player {
private:
    int health;

    public:
    Player(int initHealth) : health(initHealth) {}

    void operator+=(int value) {
        health += value;
    }

    void operator-=(int value) {
        health -= value;
        if (health < 0) health = 0;
    }

    int getHealth() const {
        return health;
    }
};