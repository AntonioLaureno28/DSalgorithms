#include <iostream>


using namespace std;


struct node
{
    int valor;
    node* prox;
};

class endedQueue
{
private:
    
public:
    node* head;
    node* tail;

    endedQueue(){
        head = tail = nullptr; //inicializei a fila encadeada.
    }

    void enfilar(int x){
        node* aux = new node{x,nullptr};
        if (head == nullptr){
            aux = head = tail;
        } else {
            tail->prox = aux;  //Apontei o último nó atual para o novo nó
            tail = aux; //Atualizei o tail para o novo nó
        }
    }

    void desenfilar(){
        node* aux = new node;
        if (head == nullptr){
            throw out_of_range("Fila vazia.");
        } else {
            aux = head; //aux recebe head
            head = head->prox; // head aponta para seu próximo elemento
            std::cout << "Elemento" << aux->valor << "removido" << endl;
            delete aux; // head deletado
        }
    }
    ~endedQueue();
};

