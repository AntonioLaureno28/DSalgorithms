#include <iostream>

const int max_items = 5;

using namespace std;

class binary
{
private:
    int tamanho;
    int* vetor;
public:
        binary(){
        tamanho = 0;
        vetor = new int[max_items];
    }

    bool binarysearch(int x) {
        int left = 0;
        int right = tamanho - 1;

        while (left <= right){
            int center = left + (right - left)/2;
            if (vetor[center] == x){
                cout << "Elemento encontrado";
                return true;
            } else if (x < vetor[center]){
                right = center - 1;
            } else {
                left = center + 1;
            }
        }
        cout << "Elemento nao encontrado";
        return false; 
    }

    int binarySearchRecursivo(int x, int left, int right){
        if (left <= right){
            int center = left + (right - left) /2;
            if (vetor[center] == x)
                return true;
            else if (x > vetor[center])
                left = center + 1;
            else 
                right = center - 1;
            return binarySearchRecursivo(x, left, right);
        } else {
            return -1;
        }
    }

    bool isEmpty(){
        return tamanho == 0;
    }

    bool isFull(){
        return tamanho == max_items;
    }


    bool contem(int x){
        if(isEmpty())             return false;
        int aux = binarySearchRecursivo(x, 0, tamanho - 1);
        return aux != -1;
    }

   void inserir(int x) {
    if (isEmpty()) {
        vetor[tamanho] = x;
        tamanho++;
        return;
    } else if (isFull()) {
        cout << "o conjunto está cheio\n";
    } else if (contem(x)) {
        cout << "O número já existe no conjunto.\n";
    } else {
        int left = 0, right = tamanho - 1;
        while (left <= right) {
            int center = (left + right) / 2;
            if (vetor[center] > x) {
                right = center - 1;
            } else {
                left = center + 1;
            }
        }
        
        for (int i = tamanho; i > left; i--) {
            vetor[i] = vetor[i - 1];
        }
        vetor[left] = x;
        tamanho++;
    }
}

    

    int print(){
        cout << "{ ";
        for (int i = 0; i < tamanho; i++){
            cout << " " << vetor[i] ;
        }
        cout << " }\n";
    }

};


int main(){
    binary b;
    int opcao, num;
    while (opcao != 6) {
        cout << "Digite a Operaçao (Adicionar(1), Pertence(2), cheio(3), vazio(4), print(5), Terminar a execucao (6))\n";
        cin >> opcao;
        switch (opcao)
        {
        case 1:
            cout << "Digite um numero para ser adicionado: \n";
            cin >> num;
            b.inserir(num);
            break;
        case 2:
            cout << "Digite um numero para verificar se ele pertence ao conjunto: \n";
            cin >> num;
            if (b.binarysearch(num) == true)            cout << "Esse numero pertence ao conjunto!\n";
            else                                    cout << "Esse numero nao pertence ao conjunto!\n";
        break;
        case 3:
            if (b.isFull())         cout << "Esse conjunto esta cheio!\n";
            else                    cout << "Esse conjunto nao esta cheio!\n";
        break;
        case 4:
            if (b.isEmpty())        cout << "Esse conjunto esta vazio!\n";
            else                    cout << "Esse conjunto nao esta vazio!\n";
        break;
        case 5:
            b.print();
            break;
        default:
            break;
        }
    }

    return 0;
    
}

