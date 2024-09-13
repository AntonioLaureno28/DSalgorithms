#include <iostream>
using namespace std;

struct Aluno {
    int Ra;
    string Nome;
    Aluno() : Ra(-1), Nome("") {}  
    Aluno(int ra, string nome) : Ra(ra), Nome(nome) {}  
};

struct Node {
    Aluno aluno;
    Node* next;
    
    Node(Aluno a) : aluno(a), next(nullptr) {}
};

class Hash
{
private:
    Aluno aluno;
    Node node;
    int m;
    int quant_elem;
    float limite_carga = 0.8;
    Node** estrutura;
    int funcaoHash(Aluno aluno){
        return aluno.Ra % m;
    }

    void redimensionar(int novo_tam){
        Node** nova_estrutura = new Node*[novo_tam];
        for (int i = 0; i < novo_tam; i++)
        {
            nova_estrutura[i] = nullptr;
        }

        for (int i = 0; i < m; i++)
        {
            Node* atual = estrutura[i];
            while (atual != nullptr)
            {
                Node* proximo = atual->next;
                int novo_indice = atual->aluno.Ra % novo_tam;
                atual->next = nova_estrutura[novo_indice];  
                nova_estrutura[novo_indice] = atual;  
                atual = proximo;  
            }
            
        }
        
        delete[] estrutura;
        estrutura = nova_estrutura;
        m = novo_tam;

    }

    void fatorDeCarga(){
        float carga_atual = quant_elem/m;
        if (carga_atual > limite_carga){
            redimensionar(m*2);
        }

    }
public:
    Hash(int tam_vetor){
        m = tam_vetor;
        estrutura = new Node*[tam_vetor];
        for (int i = 0; i < m; i++){
            estrutura[i] = nullptr;
        }
    }
    ~Hash(){
        delete [] estrutura;
    }

    void inserir(Aluno aluno){

        fatorDeCarga();

        int local = funcaoHash(aluno);
        Node* aux = new Node(aluno);

        aux->next = estrutura[local];
        estrutura[local] = aux;
        quant_elem++;
    }

    void deletar(Aluno aluno){
        int local = funcaoHash(aluno);
        Node* atual = estrutura[local];
        Node* anterior = nullptr;

        while(atual != nullptr && atual->aluno.Ra != aluno.Ra){
            anterior = atual;
            atual = atual->next;
        }

        if (atual != nullptr){
            if (anterior == nullptr){
                estrutura[local] = atual->next;
            } else {
                anterior->next = atual->next;
            }
        }
        
    }

    void buscar(Aluno& aluno, bool& busca){
        int local = funcaoHash(aluno);
        Node* atual = estrutura[local];
        busca = false;

        while (atual != nullptr)
        {
            if (atual->aluno.Ra == aluno.Ra){
                aluno = atual->aluno;
                busca = true;
                return;
            }
        }
        atual = atual->next;
        
    }

    void imprimir(){
        for (int i = 0; i < m; i++){
            Node* aux = estrutura[i];
            if (aux == nullptr){
                cout << "poha nenhuma";
            }
            while (aux != nullptr) {
                cout << "[" << aux->aluno.Ra << ", " << aux->aluno.Nome << "] -> ";
                aux = aux->next;
            }
            cout << "NULL" << endl;
        }
    }
};