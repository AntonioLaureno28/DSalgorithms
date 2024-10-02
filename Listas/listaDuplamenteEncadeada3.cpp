#include <iostream>

struct Noh {
    int elem;
    Noh *ant;  // Ponteiro para o nó anterior
    Noh *prox; // Ponteiro para o nó seguinte
};

struct Lista {
    Noh *inicio; // Início da lista
};


void separar (Lista &L, Lista &I, Lista &P){
    Noh* atual = L.inicio;

    I.inicio = nullptr;         // Inicializando as listas I e P 
    P.inicio = nullptr;


    while (atual != nullptr)
    {
        Noh* proximo = atual->prox;     //
        atual->ant = nullptr;           // Isola o elemento da lista 
        atual->prox = nullptr;          //

        if (atual->elem % 2 == 0){ // Verifica se é par ou impar 
            if (P.inicio == nullptr){
                P.inicio = atual;
            } else {
                atual->prox = P.inicio; // Coloca o nó no início da lista P
                P.inicio->ant = atual;
                P.inicio = atual;
            }
        } else {
            if (I.inicio == nullptr){
                I.inicio = atual;
            } else {
                atual->prox = I.inicio;
                I.inicio->ant = atual;
                I.inicio = atual;
            }
        }

        atual = proximo;
    }
    
    L.inicio = nullptr;
}