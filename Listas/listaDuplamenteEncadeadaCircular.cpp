#include <iostream>


using namespace std;


struct node
{
    int valor;
    node* prox;
    node* ant;
};

class listaDuplamenteEncadeadaCircular
{

public:
    node* sentinela;

    listaDuplamenteEncadeadaCircular(){
        sentinela = nullptr;
    }

    void inserir(int x){
        
    }




    ~listaDuplamenteEncadeadaCircular();
};


