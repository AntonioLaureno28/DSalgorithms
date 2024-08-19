#include <iostream>
using namespace std;

struct Aluno {
    int Ra;
    string Nome;
    Aluno* prox;
    Aluno(int ra, string nome) : Ra(ra), Nome(nome), prox(nullptr) {}  
};

class hashColisao
{
private:
    Aluno** estrutura; //array de ponteiros onde cada posição pode apontar para uma lista encadeada.
    int m;
    int funcaoHash(int Ra){
        return (Ra % m);
    }

public:
    hashColisao(int tam_vetor){
        m = tam_vetor;
        estrutura = new Aluno*[tam_vetor];
        for (int i = 0; i < tam_vetor; ++i)
        {
            estrutura[i] = nullptr;
        }
        
    }
    ~hashColisao();

    void inserir(Aluno aluno){
        int pos = funcaoHash(aluno.Ra);
        Aluno* novo = new Aluno(aluno.Ra, aluno.Nome);
        novo->prox = estrutura[pos];
        estrutura[pos] = novo;
        // NÃO ESTÃO CONTIDOS TODOS OS CASOS PARA RESOLVER O PROBLEMA.
        // COMO VOU ALTERAR O CÓDIGO AFIM DE POSSIBILITAR ADICIONAR MAIS DE UM ELEMENTO EM UMA POSIÇÃO DO VETOR ESTRUTURA??
        

    }
};





