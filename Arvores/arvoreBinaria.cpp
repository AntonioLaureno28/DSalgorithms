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
        //Nó com 1 ou nenhum filho
        if (aux->dir == nullptr){
            *cima = aux->esq; //se o nó a ser removido (aux) não tem filho à direita, é só substituir o ponteiro do nó pai (*cima) pelo filho esquerda de aux.
        } else if (aux->esq == nullptr){
            *cima = aux->dir; //Mesma situação de cima.
        } else { //nó tem 2 filhos a direita
            // Precisamos achar o sucessor in-order (o menor sucessor a direita do nó a ser removido)
            node* sucessor = aux->dir; //sucessor é inicialmente definido como o filho à direita de aux (aux->dir).
            node* *cimaSucessor = &aux->dir; //cimaSucessor é um ponteiro para ponteiro que aponta para o ponteiro do filho à direita de aux.

            while (sucessor->esq != nullptr){
                cimaSucessor = &sucessor->esq;
                sucessor = sucessor->esq;
                //A cada iteração, cimaSucessor é atualizado para apontar para o ponteiro do filho à esquerda do sucessor atual.
            }

            *cimaSucessor = sucessor->dir;
            //Remove o sucessor da sua posição original, substituindo-o por seu filho à direita (se houver).
            sucessor->esq = aux->esq;
            //Conecta a subárvore esquerda de aux à esquerda do sucessor.
            sucessor->dir = aux->dir;
            //Conecta a subárvore direita de aux à direita do sucessor.
            *cima = sucessor; //Substitui aux pelo sucessor na árvore principal.
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

