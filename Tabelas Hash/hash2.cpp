#include <iostream>

class Dicionario{
    struct Node{
        int chave;
        std::string info;
        Node *prox;
    };

    int tamanho;
    int qtd_elem;
    Node **hashtable;


    Dicionario(int n){
        tamanho = n;
        qtd_elem = 0;
        //Hash table eh um vetor de tamanho n com ponteiros para nohs, ou seja,
        //estou alocando n ponteiros para nohs
        hashtable = new Node*[n];
        //Atribuir nullptr a cada posicao
        for(int i=0;i<n;i++) hashtable[i] = nullptr;
    }

    //funcao de hash (dispercao)
    int hash(int n){
        return n % tamanho;
    }

    //Ver se uma determinada chave ja esta presente
    bool pertence(int n){
        //descobrir o indice
        int i = hash(n);
        Node *temp = hashtable[i];
        //Loop pra procurar se tem
        while(temp->chave != n && temp != nullptr){
            temp = temp->prox;        
        }
        return temp !=nullptr;
    }

    std::string consulta(int n){
        if(!pertence(n)) return "";
        int i = hash(n);
        //Calculo o indice e faco um ponteiro apontar para aquele indice
        //que eh um ponteiro para nohs e percorro ate achar
        Node *temp = hashtable[i];
        while(temp->chave!=n){
            temp = temp->prox;
        }
        return temp->info;
    }

    void redimensionar(int n){
        //Criar uma tabela com o tamanho n
        Node **newhashtable = new Node*[n];
        int tamanhoatual = tamanho;
        tamanho = n;

        for(int i=0;i<n;i++) newhashtable[i] = nullptr;

        //Mudar os elementos para a nova tabela
        for(int i=0;i<tamanhoatual;i++){
            Node *temp = hashtable[i];
            //Aponto para o primeiro indice e vou mudar todos
            //os elementos desse indice, recalculando a funcao
            //para cada noh
            while(temp!=nullptr){
                //indice na tabela nova
                int j = hash(temp->chave);
                Node *atualprox = temp->prox;
                //Na nova tabela vai apontar para o que esta nela, ou seja, nullptr
                temp->prox = newhashtable[j];
                //Posicao j na nova tabela vai apontar para ele
                newhashtable[j] = temp;
                //Passa para o proximo
                temp = atualprox;
            }
        }
        delete[] hashtable;
        hashtable = newhashtable;
    }

    bool inserir(int n, std::string s){
        if(pertence(n)) return false;
        //Se a quantidade de elementos for igual ao tamanho do vetor atual,
        //faz o redimensionamento dinamico 
        if(qtd_elem == tamanho) redimensionar(2*tamanho);
        int i = hash(n);
        //Adiciona o noh na frente da lista do indice em questao
        hashtable[i] = new Node{n, s, hashtable[i]};
        ++qtd_elem;
        return true;
    }
};


int main(){

    return EXIT_SUCCESS;
}
