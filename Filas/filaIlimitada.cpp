#include <iostream>

using namespace std;

class filaIlimitada
{
private:
    int *dados;
    int capacidade;
    int head;
    int tail;
    int tam_vetor;

    void redimensionar(){
        int newCapacidade = capacidade * 2;
        int *novo_vetor = new int [newCapacidade];

        for (int i = 0; i < tam_vetor; i++)
        {
            novo_vetor[i] = dados[(head + i) % capacidade]; 
        }

        delete[] dados;


        dados = novo_vetor;
        capacidade = newCapacidade;
        head = 0;
        tail = tam_vetor;
        
    }
public:
    filaIlimitada(){
        capacidade = 2;
        head = 0;
        tail = 0;
        dados = new int[capacidade];
        tam_vetor = 0;
    }
    ~filaIlimitada(){
        delete[] dados;
    }

    void enfilar(int x){
        if (tam_vetor == capacidade){
            redimensionar();
        }

        dados[tail] = x;
        tail = (tail + 1) % capacidade;
        tam_vetor++;
    }

    void desenfilar(){
        head = (head + 1) % capacidade;
        tam_vetor--;
    }



};

