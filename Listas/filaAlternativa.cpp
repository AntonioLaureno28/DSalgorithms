#include <iostream>


using namespace std;


struct node
{
    int valor;
    node* prox;
};

class filaAlternativa
{

public:
    node* inicio;
    node* fim;

    filaAlternativa(){
        inicio = fim = nullptr;
    }

    void enfilarNoInicio(int x){
        node* aux = new node();
        aux->valor = x;
        if (inicio == nullptr){
            inicio = fim = aux;
        } else {
            aux->prox = inicio;
            inicio = aux;
        }
    }

    void enfilar(int x){
        node* aux = new node();
        aux->valor = x;
        if (inicio == nullptr){
            inicio = fim = nullptr;
        } else {
            aux->prox = fim;
            fim = aux;
        }
    }

    void desenfilar(){
        node* aux = new node();
        if (inicio == nullptr){
            throw out_of_range("Fila vazia.");
        } else {
            aux = inicio;
            inicio = inicio->prox;
            delete aux;
        }
    }

    ~filaAlternativa();
};


