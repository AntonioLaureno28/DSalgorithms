#include <iostream>
const int max_items = 100;


using namespace std;


class Stack
{
private:
    int* vetor;
    int last;
public:
    Stack(){
        last = -1;
        vetor = new int[max_items];
    }
    
    bool isEmpty(){
        return (last == -1);
    }

    bool isFull(){
        return (last == (max_items - 1));
    }

    void push(int x){
        if (isFull()){
            cout << "A fila esta cheia\n";
        } else {
            vetor[last + 1] = x;
            last++;
        }
    }

    int pop(){
        if (isEmpty()){
            cout << "A fila esta vazia\n";
            return -1;
        } else {
            return vetor[last--];
        }
    }

    void print(){
        cout << "stack: [ ";
        for (int i = 0; i <= last; i++){
            cout << vetor[i] << " ";
        }
        cout << "]\n";
    }
};

class filaAlternativa
{
private:
    Stack pilha_enfilar; 
    Stack pilha_desenfilar;
public:

    bool isEmpty(){
        return (pilha_enfilar.isEmpty() && pilha_desenfilar.isEmpty());
    }

    bool isFull(){
        return (pilha_enfilar.isFull() && pilha_desenfilar.isFull());
    }

    void enqueue(int x){
        while (!pilha_desenfilar.isEmpty()){ 
            pilha_enfilar.push(pilha_desenfilar.pop());
        }

        pilha_enfilar.push(x);
    }

    int dequeue(){
        if (isEmpty()){
            cout << "A fila esta vazia.\n";
            return -1;
        } 

        while (!pilha_enfilar.isEmpty()){
            pilha_desenfilar.push(pilha_enfilar.pop());
        }

        return pilha_desenfilar.pop();
    }

    void print(){
        pilha_enfilar.print();
        pilha_desenfilar.print();
    }

};

int main(){
    filaAlternativa f;

    f.enqueue(1);
    f.enqueue(2);
    f.enqueue(3);
    f.enqueue(4);
    f.enqueue(5);
    f.enqueue(6);
    f.enqueue(7);
    f.enqueue(8);
    f.enqueue(9);
    f.enqueue(10);
    

    f.print();

    f.enqueue(11);

    return 0;

}





