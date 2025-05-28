
#include <iostream>
#include <vector>


class Node{
    public:
    int value;
    Node* left;
    Node* right;

    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

class BinaryTree{

    public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    void insert(int value){
        if(root == nullptr){
            root = new Node(value);
        }else{
            Node* current = root;
            while(true){
                if(value < current->value){
                    if(current->left == nullptr){
                        current->left = new Node(value);
                        break;
                    }else{
                        current = current->left;
                    }
                }else{
                    if(current->right == nullptr){
                        current->right = new Node(value);
                        break;
                    }else{
                        current = current->right;
                    }
                }
            }
        }
    }

    Node* search(int value){
        Node* current = root;
        while(current != nullptr){
            if(value == current->value){
                return current;
            }else if(value < current->value){
                current = current->left;
            }else{
                current = current->right;
            }
        }
        return nullptr;
    }

    void printInOrder(Node* node){
        if(node == nullptr){
            return;
        }
        printInOrder(node->left);
        std::cout << node->value << " ";
        printInOrder(node->right);
    }
};

int main(){
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    
    std::cout << "In-order traversal: ";
    tree.printInOrder(tree.root);
    std::cout << std::endl;

    int searchValue = 4;
    Node* result = tree.search(searchValue);
    if(result != nullptr){
        std::cout << "Found " << searchValue << " in the tree." << std::endl;
    }else{
        std::cout << searchValue << " not found in the tree." << std::endl;
    }

    return 0;
}