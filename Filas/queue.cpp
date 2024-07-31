#include <iostream>
const int max_itens = 10;


using namespace std;

struct queue
{
    int items[max_itens];
    int head = -1, tail;

    bool isEmpty(){
        return (head == -1);
    }

    bool isFull(){
        return (head == (tail+1) % max_itens);
    }

    void enqueue(int item){
        if(isFull()){
            cout << "A fila esta cheia\n";
            return;
        } else if(isEmpty()) {
            head = tail = 0;
            items[tail] = item;
        }
        else {
            tail++;
            items[tail % max_itens] = item;
                      
        }
    }

    int dequeue(){
        if(isEmpty()){
            cout << "a fila esta vazia\n";
            return 0;
        } else if(head == tail){
            head = -1;
        }
        else {
            head++;
            return items[(head-1) % max_itens];
        }
    }

    int print(){
        if(isEmpty()){
            cout << "Fila vazia";
        } else {
            cout << "[ ";
            for (int i = head; i <= tail; i++){
                cout << items[i % max_itens] << " ";
            }
            cout << "]\n";
        }
    }
};


int main(){
    queue q;


    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);


    q.print();

    q.enqueue(11);

    q.dequeue();
    q.dequeue();

    q.print();

    q.enqueue(11);
    q.enqueue(12);

    q.print();


    int opcao, num;


    while (opcao != 4){
        cout << "Digite a operacao: Enfilar (1), Desenfilar (2), Print (3), Encerrar a Operacao (4) \n";
        cin >> opcao;
        switch (opcao)
        {
        case 1:
            cout << "Digite o numero para enfilar: ";
            cin >> num;
            q.enqueue(num);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.print();
            break;
        default:
            break;
        }
    }
    return 0;

}
