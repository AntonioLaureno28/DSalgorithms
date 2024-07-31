#include <iostream>


using namespace std;

struct filaEncadeada
{
    struct node
    {
        int value;
        node *prox;
    };

    node *head;
    node *tail;

    filaEncadeada(){
        head = nullptr;
    }

    bool isEmpty(){
        return head == nullptr;
    }

    void enqueue(int x){
       node *novo = new node();
       novo->value = x;
       if (tail != nullptr) {
        tail->prox = novo;
       }
       tail = novo;
       if (isEmpty()){
        head = novo;
       }
    }

    int dequeue(){
        node *clock = head;
        int x = head->value;
        head = head->prox;
        delete clock;
        return x;
    }
    
};
