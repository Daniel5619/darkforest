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

    Node* current = list.head;
    while (current != nullptr){
        std::cout << current->value << "\n";
        current = current->next;
    }
    std::cout << std::endl;

    return 0;
}