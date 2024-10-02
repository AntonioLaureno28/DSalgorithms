#include <iostream>
using namespace std;

struct node {
    int valor;
    node* esq;
    node* dir;

    node(int x) : valor(x), esq(nullptr), dir(nullptr) {}
};

class novaArvore
{
private:

    node* raiz;

    node** search(int x){
        node** atual = &raiz;

        while (*atual != nullptr)
        {
            if (x < (*atual)->valor)
            {
                atual = &((*atual)->esq);

            } else if (x > (*atual)->valor){
                atual = &((*atual)->dir);
            } else {
                return;
            }
        }
        return atual;
    }
    
public:
    novaArvore(){
        raiz = nullptr;
    }

    void inserir(int x){
        node** localizado = search(x); // encontra a posição onde o X deve ser inserido
        if (*localizado == nullptr){
            *localizado = new node(x);
            return;
        } else {
            cout << "Elemento já se encontra na arvore" << endl;
        }
    }

    ~novaArvore();
};


