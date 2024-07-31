#include <iostream>


using namespace std;

struct pilhaEncadeada
{
    struct node{
        int value;
        node* proximo;
    };

    node *topo;

    pilhaEncadeada(){
        topo = nullptr;
    }

    void push(int x){
        node *novo = new node;
        novo->value = x;
        novo->proximo = topo;
        topo = novo;
    }

    int consultar_topo(){
        return topo->value;
    }

    void pull(){
        node *primeiro = topo;
        topo = topo->proximo;
        delete primeiro;
    }

    bool vazia(){
        return (topo == nullptr);
    }

    ~pilhaEncadeada(){
        while (not vazia()) pull();
    }
};

int main(){
    
}
