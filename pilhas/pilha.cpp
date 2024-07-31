#include <iostream>;
#include "pilha.h";

using namespace std;


    pilha::pilha()
    {
        tamanho = 0;
        estrutura = new TipoItem[max_itens];
    }

    pilha::~pilha()
    {
        delete [] estrutura;
    }

    bool pilha::IsFull()
    {
        return (tamanho == max_itens);
    }

    bool pilha::IsEmpty()
    {
        return (tamanho == 0);
    }

    void pilha::push(TipoItem item)
    {
        if (IsEmpty)
        {
            cout << "nao e possivel acrescentar mais itens";
        } else {

        }
        
    }

    TipoItem pilha::pop()
    {

    }

    void pilha::print()
    {

    }

    int pilha::lenght()
    {

    }