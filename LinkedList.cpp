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

    void RemoveAt(int nodeIndexNum){
        if (nodeIndexNum == 0) {
            Delete();
            return;
        } else if (nodeIndexNum < 0) {
            return;
        }

        Node* current = head;
        Node* oldNode = head;
        int count = 0;

            while (count < nodeIndexNum && current->next != nullptr){
                oldNode = current;
                current = current->next;
                count++;
            }

            if (current != nullptr) {
                oldNode->next = current->next;
                delete current;
            }

            return;
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
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);


    list.Print();

    list.Delete();

    list.Print();

    for (int i = 0; i <= 2; i++) list.RemoveAt(0);

    list.Print();
    
    std::cout << std::endl;
    return 0;
}