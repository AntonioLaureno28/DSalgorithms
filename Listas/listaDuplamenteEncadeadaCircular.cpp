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

    void inserirNoInicio (int x){
        node* aux = new node();
        aux->valor = x;
        if (sentinela == nullptr){ //se estiver vazio;
            aux->prox = aux;
            aux->ant = aux;
            sentinela = aux;
        } else {
            aux->prox = sentinela->prox;
            aux->ant = sentinela;
            sentinela->prox->ant = aux;
            sentinela->prox = aux;
        }

        cout << "Elemento inserido com sucesso!";
    }

    void inserirNoFim(int x){
        node* aux = new node();
        aux->valor = x;
        if (sentinela == nullptr){
            aux->prox = aux;
            aux->ant = aux;
            sentinela = aux;
        } else {
            aux->ant = sentinela->ant;
            aux->prox = sentinela;
            sentinela->ant->prox = aux;
            sentinela->ant = aux;
        }

    }






    ~listaDuplamenteEncadeadaCircular();
};


