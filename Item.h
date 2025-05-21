#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>


class Item{

    public:

    Item (std::string name) {
        name_ = name
    }

    virtual void useItem() {
        std::cout << "you have used the " << name_ << "\n";
    }
    

    private:
    std::string name_;



}

#endif //ITEM