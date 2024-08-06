#include <iostream>


using namespace std;


struct node
{
    int valor;
    node* prox;
};

class listaEncadeadaCircular
{
private:
    
public:
    node *sentinela;

    listaEncadeadaCircular(){
        sentinela = nullptr; 
    }

    void inserir(node* x){
        if (sentinela == nullptr){
           x->prox = x;
           sentinela = x;
        }
    }
    ~listaEncadeadaCircular();
};


