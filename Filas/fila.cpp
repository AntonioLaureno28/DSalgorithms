#include <iostream>;
#include "fila.h";

using namespace std;


    fila::fila()
    {
        first = 0;
        last = 0;
        estrutura = new TipoItem[max_itens];
    }

    bool fila::isEmpty()
    {
        return(first == last);
    }

    bool fila::isFull()
    {
        return((first - last) == max_itens);
    }

    void fila::push(TipoItem item)
    {
        if (isFull()) {
            cout << "A fila esta cheia!";
        } else {
            estrutura[last % max_itens] = item;
            last++;
        }
    }

    TipoItem fila::pop()
    {
        if (isEmpty()){
            cout << "A fila esta vazia";
            return 0;
        } else {
            first++;
            return estrutura[(first-1) % max_itens];
        }
    }

    void fila::print()
    {
        cout << "[ ";
        for (int i = first; i < last; i++) {
            cout << estrutura[i % max_itens] << " ";
        }
        cout << "]/n";
    }



