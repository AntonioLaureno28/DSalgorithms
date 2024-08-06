#include <iostream>


using namespace std;

struct node
{
    int valor;
    node* prox;
    node* ant;
};

class listaDuplamenteEncadeada
{
public:
    node* inicio;
    node* fim;

    listaDuplamenteEncadeada(){
        inicio = nullptr;
        fim = nullptr;
    }

    bool isEmpty(){
        return inicio == nullptr;
    }

    void inserirNoInicio(int x){
        node* aux = new node();
        aux->valor = x;
        if (inicio == nullptr){
            inicio = fim = aux;
        } else {
            aux->prox = inicio;
            inicio->ant = aux;
            inicio = aux;
        }
    }

    void inserirNoFim(int x){
        node* aux = new node();
        aux->valor = x;
        if (fim == nullptr){
            inicio = fim = aux;
        } else {
            aux->ant = fim;
            fim->prox = aux;
            fim = aux;
        }
    }

    void removerInicio(){
        if(isEmpty()){
            throw out_of_range("A lista está vazia!");
        }
        node* aux = inicio;
        inicio = inicio->prox;
        if (isEmpty()){
            fim = nullptr;
        } else {
            inicio->ant = nullptr;
        }
        delete aux;
    }

    void removerFim(){
        if(isEmpty()){
            throw out_of_range("A lista está vazia!");
        }
        node* aux = fim;
        fim = fim->ant;
        if (fim == nullptr){
            inicio == nullptr;
        } else {
            fim->prox = nullptr;
        }
        delete aux;
    }
    ~listaDuplamenteEncadeada();
};



