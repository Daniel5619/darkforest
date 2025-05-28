#include <iostream>
#include <vector>
#include <cstdlib> // Needed for rand() and srand()
#include "Weapon.h"
#include "SuperWeapon.h"  //this is the coolest game ever
#include "WimpyWeapon.h"
#include "Player.h"
#include <functional>
using namespace std;
   
Weapon* search(std::function<int()> random_generator){
 
    int rand = random_generator();
    Weapon* weapon;

    if(rand == 1){
       weapon = new Weapon("sword",10);
       
    }
    else if(rand == 2){
       weapon = new SuperWeapon("Supersword",1);
    }
    else{
        weapon = new WimpyWeapon("WimpySword");
    }
    cout << "You found a "  << weapon->getDescription() << "!\n";
    return weapon;
}

void goIntoTheForest(Weapon* weapon, Player& player1){

    cout << "You encounter a goblin in the forest!\n";
    int goblinHealth = 120;

    if (weapon == nullptr){
        cout << "The goblin attacks you\n";
        
         player1 -= player1.getHealth();
         
    }
    else {

       string selection = "";

       while (selection != "2" && goblinHealth >0){

            cout << "[1] attack\n";
            cout << "[2] run away\n";

            cin >> selection;

            if ("1" == selection){
                goblinHealth = goblinHealth - (weapon->attack());
                cout << "you attack the goblin. The goblin is at " <<  goblinHealth <<  " health.\n";
            }

       }
    }

}


int main() {

    vector <Weapon*> inventory;
    string selection;
    Player player1(120);

    // Define the range for random number generation
    const int weapon_range = 3;

    // Define the lambda for random number generation, capturing weapon_range
    auto random_in_range = [weapon_range]() {
        srand(static_cast<unsigned int>(time(0)));
        return rand() % weapon_range + 1;
    };

    while ("x" != selection){

        cout << "Select an action!\n";
        cout << "[1] to search around you\n";
        cout << "[2] to view inventory\n";
        cout << "[3] go into the forest\n";
        cout << "[x] to exit\n";

        cin >> selection;

        if ("1" == selection){
            inventory.push_back(search(random_in_range));
        }
        else if("2" == selection){
            cout << "Your inventory contains:\n";
            for(int i=0; i < inventory.size() ; i++){
                cout << inventory[i]->getDescription() << "\n";
            }
        }
        else if("3" == selection){
            int chosenNum=0;
            if (inventory.size() > 0) {

                for(int i=0;i<inventory.size();i++){
                    cout << "Please choose a weapon!\n" << "choose " << i << " for the " << inventory[i]->getName() << " weapon\n" ;
                }
                cin >> chosenNum;

                for(int x=0;x<inventory.size();x++){

                    if(chosenNum==x){

                        cout << "you have chosen the " << inventory[chosenNum]->getName() << " weapon!\n";
                        break;
                    }
                }

            }
            Weapon *weapon = nullptr;

            if (inventory.size() > 0){
                weapon = inventory[chosenNum];
            }
                
            goIntoTheForest(weapon, player1);
        }
       
        if(player1.getHealth() <= 0){
            cout << "you died!\n";
            break;
        }
        
    }

    cout << "last attack was: " << lastATK << "\n";
    cout << "goodbye\n";
    return 0;
}

