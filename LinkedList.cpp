#include <iostream>

class Node {
public:
    int value;
    Node* next;

    Node(int value) : value(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr){}

    void append(int newValue){
        Node* newNode = new Node(newValue);
        if(head == nullptr){
            head = newNode; 
        }else{
            Node* current = head;
            while (current->next != nullptr){
                current = current->next;
            }
            current->next = newNode;
        }
        
    }

    int Get(int nodeIndexNum){
        Node* current = head;
        int finalIndex = 1;
        
        while (current->next != nullptr){
            finalIndex++;
            current = current->next;
        }
        current = head;
        if (nodeIndexNum <= finalIndex && nodeIndexNum > 0) {
            for (int i = 1; i != nodeIndexNum; i++){
                current = current->next;
            }
            return current->value;
        } else {
            return 0;
        }
    }

    void Delete() {
        Node* newNodePtr = head->next;
        delete head;
        head = newNodePtr;
    }

    void Print() {
        Node* current = head;
        while (current != nullptr){
            std::cout << current->value << "\n";
            current = current->next;
        }
    }

    ~LinkedList(){
        Node* current = head;
        while (current != nullptr){
            Node* next = current->next;
            delete current;
            current = next;
        }

        head = nullptr;
        std::cout << "LinkedList Destructor" << std::endl;

    }
};

int main(){

    LinkedList list;
    list.append(1);
    list.append(5);
    list.append(7);

    list.Print();

    list.Delete();

    list.Print();

    std::cout << std::endl;

    std::cout << list.Get(0) << std::endl;
    return 0;
}