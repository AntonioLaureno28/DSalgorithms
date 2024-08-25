#include <iostream>;

using namespace std;

class arvoreBinaria
{
private:
    struct node
    {
        int valor;
        node* dir;
        node* esq;
    };

    node* raiz;
    
public:
    arvoreBinaria(){
        raiz = nullptr;
    }

    bool vazia(){
        return (raiz == nullptr);
    }

    void inserir(int x){
        node* novo = new node {x, nullptr, nullptr};

        if (vazia()){
            raiz = novo;
            return;
        }

        node* aux = raiz;
        while (true){
            if (x < aux->valor) {
                if (aux->esq == nullptr){
                    aux->esq = novo;
                    return;
                }

                aux = aux->esq;
            } else {
                if (aux->dir == nullptr){
                    aux->dir = novo;
                    return;
                }

                aux = aux->dir;
            }
        }
    }

    bool pertence(int x){
        node* aux = raiz;

        while (aux != nullptr)
        {
            if (x < aux->valor)         aux = aux->esq;
            else if (x > aux->valor)    aux = aux->dir;
            else                        return true;
        }

        return false;
        
    }

    void inserirSeNovo(int x){
        if (pertence(x)){
            cout << "O elemento já está inserido na arvore!";
            return;
        } else {
            inserir(x);
            cout << "elemento inserido com sucesso";
        }
    }

    void remover(int x){
        node* aux = raiz;
        node* *cima = &raiz;

        while (aux != nullptr){
            if (x < aux->valor){
                cima = &aux->esq;
                aux = aux->esq;
            } else if(x > aux->valor){
                cima = &aux->dir;
                aux = aux->dir;
            } else {
                break;
            }
        }

        if (aux == nullptr){
            cout << "elemento não encontrado!!";
            return;
        }

        if (aux->dir == nullptr){
            *cima = aux->esq;
        } else if (aux->esq == nullptr){
            *cima = aux->dir;
        } else {
            node* sucessor = aux->dir;
            node* *cimaSucessor = &aux->dir;

            while (sucessor->esq != nullptr){
                cimaSucessor = &sucessor->esq;
                sucessor = sucessor->esq;
            }

            *cimaSucessor = sucessor->dir;
            sucessor->esq = aux->esq;
            sucessor->dir = aux->dir;
            *cima = sucessor;
        }
    }

    void imprimir(node* n){
        if (n != nullptr){
            imprimir(n->esq);
            cout << n->valor << endl;
            imprimir(n->dir);
        }
    }

    void deletarArvore(node* n){
        if (n != nullptr){
            deletarArvore(n->esq);
            deletarArvore(n->dir);
            delete n;
        }
    }
    ~arvoreBinaria(){
        deletarArvore(raiz);
    }
};

