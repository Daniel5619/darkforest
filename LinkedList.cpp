#include <iostream>


template <typename T>
class Node {
public:
    T value;
    Node* next;

    Node(T value) : value(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
public:
    Node<T>* head;

    LinkedList() : head(nullptr){}

    void append(int newValue){
        Node<T>* newNode = new Node<T>(newValue);
        if(head == nullptr){
            head = newNode; 
        }else{
            Node<T>* current = head;
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

        Node<T>* current = head;
        Node<T>* oldNode = head;
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
        Node<T>* newNodePtr = head->next;
        delete head;
        head = newNodePtr;
    }

    void Print() {
        Node<T>* current = head;
        while (current != nullptr){
            std::cout << current->value << "\n";
            current = current->next;
        }
    }

    ~LinkedList(){
        Node<T>* current = head;
        while (current != nullptr){
            Node<T>* next = current->next;
            delete current;
            current = next;
        }

        head = nullptr;
        std::cout << "LinkedList Destructor" << std::endl;

    }
};

int main(){

    LinkedList<int> list;
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