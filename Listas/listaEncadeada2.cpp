#include <iostream>


using namespace std;


struct node
{
    int valor;
    node* prox;
};


class linkedList
{
public:
    node* head;

    linkedList(){
        head = nullptr;
    }

    bool existe(){
        return head == nullptr;
    }

    void inserir(int x){
        node* aux = new node;
        aux->valor = x;
        if (head == nullptr || aux->valor < head->valor){
            aux->prox = head;
            aux = head;
            cout << "Elemento inserido com sucesso.";
        } else {
            node* aux2 = head;
            while (aux2->prox != nullptr && aux2->prox->valor < aux->valor){
                aux2 = aux2->prox;
            }
            aux->prox = aux2->prox;
            aux2->prox = aux;
            cout << "Elemento inserido com sucesso.";
        }
        
    }

    void inserirNoFim(int x){
        node* aux = new node;
        aux->valor = x;

        if (head == nullptr) {
            aux->prox = head;
            aux = head;
        } else {
            node* aux2 = head;
            while (aux2->prox != nullptr){
                aux2 = aux2->prox;
            }
            aux2->prox = aux;
        }
    }

    void remover(int x){
        node* aux = head;
        if(existe()){
            throw out_of_range("A lista está vazia! Adicione algum elemento!");
        } else if (aux->valor == x){
            head = head->prox;
            delete aux;
            cout << "O elemento" << x << "foi removido com sucesso!";
            return;
        } else {
            node* aux2 = head;
            while (aux2->prox != nullptr && aux2->valor != x)
            {
                aux2 = aux2->prox;
            }
            aux2 = aux;
            head = aux;
            head = head->prox;
            delete aux;
            delete aux2;
            cout << "O elemento" << x << "foi removido com sucesso!";
            return;
        }

    }


    void contagemElementos(){
        node* aux = head;
        int count;
        while (aux->prox != nullptr){
            aux = aux->prox;
            count++;
        }
        cout << "Número de Elementos: " << count;
    }



    void print(){
        node* aux = head;
        while (aux->prox != nullptr)
        {
            cout << aux->valor << " ";
            aux = aux->prox;
        }
        
    }
};


int main(){
    linkedList L;
    int valor, op;

    
    while (op != 6)
    {
        cout << "Escolha uma Opção: Inserir (1); Inserir no Fim (2); Consultar (3); Remover (4); Mostrar Lista (5); Encerrar (6)/n";
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Insira um valor na lista: ";
            cin >> valor;
            L.inserir(valor);
            break;
        case 2:
            cout << "Insira um valor no fim da lista: ";
            cin >> valor;
            L.inserirNoFim(valor);
            break;
        case 3:
            L.contagemElementos();
            break;
        case 4:
            cout << "Insira o valor que deseja remover da lista: ";
            cin >> valor;
            L.remover(valor);
            break;
        case 5: 
            L.print();
            break;
        default:
            break;
        }
    }
    
    
}
