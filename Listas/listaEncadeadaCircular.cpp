#include <iostream>


using namespace std;


struct node
{
    int valor;
    node* prox;
};

class listaEncadeadaCircular
{
public:
    node *sentinela;

    listaEncadeadaCircular(){
        sentinela = nullptr; 
    }

    void avancar() {
        if (sentinela != nullptr) {
            sentinela = sentinela->prox;
        }
    }



    void inserir(int x){
        node* aux = new node();
        aux->valor = x;
        if (sentinela == nullptr){
           aux->prox = aux;
           sentinela = aux;
        } else {
            aux->prox = sentinela->prox;
            sentinela->prox = aux;
        }
        avancar();
    }

    int inicioLista(){
        node* inicio = sentinela->prox;
        return inicio->valor;
    }

    int fimLista(){
        return sentinela->valor;
    }


   ~listaEncadeadaCircular() {
    if (sentinela != nullptr) {
        node* current = sentinela->prox;
        node* head = current;
        do {
            node* next = current->prox;
            delete current;
            current = next;
        } while (current != head);
        sentinela = nullptr;
    }
}


};

int main(){
    listaEncadeadaCircular L;

    L.inserir(1);
    L.inserir(2);
    L.inserir(3);

    L.inicioLista();
    L.fimLista();

    cout << "Início da Lista: " << L.inicioLista() << endl;
    cout << "Fim da Lista: " << L.fimLista() << endl;
}


