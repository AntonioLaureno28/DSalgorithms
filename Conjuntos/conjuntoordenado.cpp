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

    void inserirElementos(conjunto &c, const char elementos[], int numElementos) {
    for (int i = 0; i < numElementos; i++) {
        c.vetor[i] = elementos[i];
        c.n++;
    }
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


int main(){
    conjunto conjunto;
    inicializar(conjunto, 5);
    
    char elementos[] = {1, 2, 3, 4, 5};
    inserirElementos(conjunto, elementos, sizeof(elementos) / sizeof(elementos[0]));

    while (true) {
        cout << "Escolha uma opcao Pertence(P), Cheio? (C), Vazio?(V), Sair(S)): ";
        char opcao;
        cin >> opcao;

        if (opcao == 'P'){
            char elemento;
            cin >> elemento;
            if (binarySearch(conjunto, elemento))
                cout << "Elemento encontrado!\n";
            else
                cout << "Elemento nao pertence!\n";
        
    }

    return 0;
}
   
}










 void inserir(int x){
        if (isEmpty()){
            vetor[tamanho] = x;
            tamanho++;
            return;
        } else if (isFull()){
            cout << "o conjunto esta cheio\n";
        } else if (contem(x)) {
            cout << "O numero ja existe no conjunto.\n";
        } else {
                int left = 0, right = tamanho-1;
                while(left <= right){
                    int center = (left+right)/2;
                    if(vetor[center] > x){
                        if(center == 0 || vetor[center-1] < x){ //elem is the lower || elem has to be in the middle
                            for(int i  = tamanho; i > center; i--){
                                vetor[i] = vetor[i-1];
                            }
                            vetor[center] = x;
                        }
                        else{
                            right = center-1;
                        }
                    }
                    else{
                        left = center+1;
                        if(left > right){  //elem is the higher
                            vetor[tamanho] = x;
                        }
                    }
                }
                tamanho++;
            }
        }