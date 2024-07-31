#include <iostream>
const int max_itens = 5;
typedef int Tipoitem;


using namespace std;


struct conjunto{
    int n;
    int tam;
    char *vetor;
};


    void inicializar (conjunto &c, int t){
        c.n = 0;
        c.tam = t;
        c.vetor = (char *) malloc(sizeof(char) * t);
    }


    bool isEmpty(conjunto &c){
        return (c.n == 0);
    }

    bool isFull(conjunto &c){
        return (c.n == max_itens);
    }

    bool binarySearch(conjunto &c, char aux){
        int left = 0;
        int right = c.n - 1;

        while (left <= right){
            int center = left + (right - left) / 2;
            if (c.vetor[center] == aux){
                return true;
            }
    
            if (c.vetor[center] > aux){
                right = center - 1;
            } else {
                left = center + 1;
            }
        }

        return false;
    }

    void inserir (conjunto &c, char aux){
        if (c.n < c.tam){
            if (c.n == 0){
                c.vetor[c.n] = aux; 
                c.n++;
                return;
            }


        int left = 0;
        int right = c.n - 1;
        int center;
            
        while (left <= right){
            center = left + (right - left) / 2;
            if (c.vetor[center] > aux){
                right = center - 1;
            } else {
                left = center + 1;
            }
        }

        int index = left;
        for (int j = c.n; j > index; j--) {
            c.vetor[j] = c.vetor[j - 1];
        }
        c.vetor[index] = aux;
        c.n++;
    }    

    }

    void mostrar(conjunto &c) {
    for (int i = 0; i < c.n; i++) {
        if (i == 0)
            cout << "{ ";
        cout << c.vetor[i] << " ";
        if (i == c.n - 1)
            cout << "}\n";
    }
}

int main() {
    conjunto conjunto;
    inicializar(conjunto, 5);

    while (true) {
        cout << "Escolha uma opcao (Inserir(I), Pertence(P), Mostrar(M), Sair(S)): ";
        char opc;
        cin >> opc;

        if (opc == 'I') {
            char elemento;
            cin >> elemento;
            if (!binarySearch(conjunto, elemento)) 
                inserir(conjunto, elemento);
        }
        else if (opc == 'P'){
            char elemento;
            cin >> elemento;
            if (binarySearch(conjunto, elemento))
                cout << "Elemento encontrado!\n";
            else
                cout << "Elemento nao pertence!\n";
        }
        else if (opc == 'M') {
            mostrar(conjunto);
        }       
    }
    return 0;
}

    