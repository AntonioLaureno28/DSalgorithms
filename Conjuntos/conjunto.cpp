#include <iostream>
const int max_itens = 5;
typedef int Tipoitem;

using namespace std;

struct conjunto {
    Tipoitem v[max_itens];
    int n = 0;

    bool isEmpty(){
        return (n == 0);
    }

    bool isFull(){
        return (n == max_itens);
    }

    void adicionar(Tipoitem x){
        if (isFull()){
            cout << "impossivel realizar essa açao!\n";
            return;
        } else {
            v[n] = x;
            n++;
            cout << "o elemento foi adicionado com sucesso!\n";
        }
    }

    void remover(Tipoitem x){
        if (isEmpty()){
            cout << "impossivel realizar essa açao!\n";
            return;
        } else {
            for (int i = 0; i < n; i++)
            {
                if (v[i] == x) {
                    v[i] = v[n-1];
                    n--;
                } 
            }
            
        }
        
    }

    bool pertence(Tipoitem x){
        for (int i = 0; i < n; i++){
            if (v[i] == x) {
                return true;
            }
        }
    return false;
    }


    void adicionarSeNovo(Tipoitem x){
        if (pertence(x) == true){
            cout << "Esse elemento ja existe!\n";
            return;
        } else {
            return (adicionar(x));
        }
    }

    int print(){
        if(isEmpty()){
            cout << "Conjunto vazio\n";
        } else {
            cout << "[ ";
            for (int i = 0; i < n; i++){
                cout << v[i] << " ";
            }
            cout << "]\n";
        }
    }

};


int main(){
    conjunto c;
    int opcao, num;
    while (opcao != 7) {
        cout << "Digite a Operaçao (Adicionar(1), Remover(2), Pertence(3), Esta Cheia?(4), Esta Vazia?(5), Print(6), Terminar a execuçao (7))\n";
        cin >> opcao;
        switch (opcao)
        {
        case 1:
            cout << "Digite um numero para ser adicionado: \n";
            cin >> num;
            c.adicionarSeNovo(num);
            break;
        case 2: 
            cout << "Digite um numero para ser removido: \n";
            cin >> num;
            if (c.pertence(num)) {
                c.remover(num);
            } else {
                cout << "Esse elemento nao pertence ao conjunto! \n";
            }
            break;
        case 3:
            cout << "Digite um numero para verificar se ele pertence ao conjunto: \n";
            cin >> num;
            if (c.pertence(num) == true)            cout << "Esse numero pertence ao conjunto!\n";
            else                                    cout << "Esse numero nao pertence ao conjunto!\n";
        break;
        case 4:
            if (c.isFull())         cout << "Esse conjunto esta cheio!\n";
            else                    cout << "Esse conjunto nao esta cheio!\n";
        break;
        case 5:
            if (c.isEmpty())        cout << "Esse conjunto esta vazio!\n";
            else                    cout << "Esse conjunto nao esta vazio!\n";
        break;
        case 6:
            c.print();
            break;
        default:
            break;
        }
    }

    return 0;
    
}
