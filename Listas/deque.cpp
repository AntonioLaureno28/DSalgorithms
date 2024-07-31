#include <iostream>


using namespace std;

class deque
{
    struct node
    {
        node *ant;
        int elem;
        node *prox;
    };
    
    node *left, *right;

public:
    deque(){
        left = right = nullptr;
    }

    bool isEmpty(){
        return left == nullptr;
    }

    void addLeft(int x){
        node* newNode = new node;
        newNode->elem = x;
        if (isEmpty()){
            left = right = newNode;
        } else {
            newNode->prox = left;
            left->ant = newNode;
            left = newNode;
        }
    }

    void addRight(int y){
        node* newNode = new node;
        newNode->elem = y;
        if (right == nullptr){
            left = right = newNode;
        } else {
            newNode->ant = right;
            right->prox = newNode;
            right = newNode;
        }
    }

    void removeLeft(){
        if (isEmpty()){
            throw std::out_of_range("Deque is empty");
        }
        node* aux = left;
        left = left->prox;
        if (left == nullptr){
            right = nullptr;
        } else {
            left->ant = nullptr;
        }

        delete aux;
    }

    void removeRight(){
        if (isEmpty()){
            throw std::out_of_range("Deque is empty");
        }
        node* aux = right;
        right = right->ant;
        if (right == nullptr){
            left == nullptr;
        } else {
            right->prox = nullptr;
        }

        delete aux;

    }

    int peekLeft() {
        if (isEmpty()){
            throw std::out_of_range("Deque is empty");
        }
        return left->elem;
    }

    int peekRight() {
        if (isEmpty()){
            throw std::out_of_range("Deque is empty");
        }
        return right->elem;
    }


    ~deque(){
        while(!isEmpty()){
            removeRight();
        }
    }
};

int main(){
    deque d;

    d.addLeft(1);
    d.addRight(2);
    d.addLeft(0);

    cout << "Left element: " << d.peekLeft() << endl; 
    cout << "Right element: " << d.peekRight() << endl;   

    d.removeLeft();

    cout << "Left element: " << d.peekLeft() << endl; 
    cout << "Right element: " << d.peekRight() << endl; 

    
}