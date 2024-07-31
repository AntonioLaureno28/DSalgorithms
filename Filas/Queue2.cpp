#include <iostream>
const int max_items = 5;
typedef int Tipoitem;

using namespace std;

class fila2
{
private:
    int head, tail;
    Tipoitem* queue;
public:
    fila2(){
        head = -1;
        queue = new Tipoitem[max_items];
    }

    bool isFull(){
       return  (head == (tail+1) % max_items);
    }

    bool isEmpty(){
        return (head == tail);
    }

    void enqueue(int x){
        if (isEmpty()) {
            head = tail = 0;
            queue[tail] = x;
        } else if (isFull()) {
            cout << "A fila esta cheia\n";
            return;
        } else {
            tail++;
            queue[tail % max_items] = x;
        }
    }

    int dequeue(){
        if (isEmpty()){
            cout << "fila vazia.\n";
            return 0;
        } else if (head == tail) {
            head = -1;
        } else  {
            head++;
            return queue[(head-1) % max_items];
        }
    }

    void print(){
         cout << "[ ";
         for (int i = head; i <= tail; i++){
            cout << queue[i % max_items] << " ";
         }
         cout << "]\n";
        
    }
    
};

int main(){
    fila2 f;
    int opcao, num;


    while (opcao != 4){
        cout << "Digite a operacao: Enfilar (1), Desenfilar (2), Print (3), Encerrar a Operacao (4) \n";
        cin >> opcao;
        switch (opcao)
        {
        case 1:
            cout << "Digite o numero para enfilar: ";
            cin >> num;
            f.enqueue(num);
            break;
        case 2:
            f.dequeue();
            break;
        case 3:
            f.print();
            break;
        default:
            break;
        }
    }
    return 0;
}

