#include <iostream>


using namespace std;

class dicionario
{

struct node
{
    int key;
    string value;
    node *prox;
};

node *start;

    
public:
    dicionario(){
        start = nullptr;
    }

    bool isEmpty(){
        return start == nullptr;
    }

    void add(int k, string v){
        start = new node{k, v, start};
    }

    int find(string val){
        node *aux = start;
        while (aux != nullptr){
            if (aux->value == val){
                return aux->key;
            }
            aux = aux->prox;
        }
        throw out_of_range("Value not found");
    }

    void remove(int k){
        node *aux = start;
        if (isEmpty()){
            throw out_of_range("Dictonary is empty");
        }

        if (aux->key == k){
            start = start->prox;
            delete aux;
            return;
        }

        while (aux->prox != nullptr){
            if (aux->prox->key == k){
                node *p = aux->prox;
                aux->prox = p->prox;
                delete p;
                return;
            }
        aux = aux->prox;
        }
    }


    ~dicionario(){
        node* aux = start;
        while(aux != nullptr){
            node* next = aux->prox;
            delete aux;
            aux = next;
        }
    }
};


