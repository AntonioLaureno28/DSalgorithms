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

    int remover(int x){
        if (sentinela == nullptr){
            throw out_of_range("A lista está vazia.");
        }

        node* aux = sentinela; // 
        node* aux2 = sentinela->prox; // Começa no início da lista.
        
        do
        {
            if (aux2->valor == x){
                if (aux2 == sentinela){
                    if (aux2 = aux2->prox){ // Único nó da lista.
                        delete aux2;
                        sentinela = nullptr;
                    } else { //Mais de um nó na lista.
                        sentinela = aux;
                        aux->prox = aux2->prox;
                        delete aux2;
                    }
                } else {
                    aux->prox = aux2->prox;
                    delete aux2;
                }
                cout << "Nó removido";
            }
            aux = aux2;
            aux2 = aux2->prox;

        } while (aux2 != sentinela->prox); // Esse loop permite que cada nó da lista seja verificado apenas umas vez. Até retornar ao início da lista.
        
        cout << "Nó não encontrado.";

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

    L.remover(3);

    L.inicioLista();
    L.fimLista();

    cout << "Início da Lista: " << L.inicioLista() << endl;
    cout << "Fim da Lista: " << L.fimLista() << endl;
}


