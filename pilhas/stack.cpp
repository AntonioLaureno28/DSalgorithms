#include <iostream>
const int max_itens = 10;

using namespace std;

struct stack
{
    int items[max_itens];
    int last;

    stack(){
       last = -1;
    }

    bool isEmpty(){
        return (last == -1);
    }

    bool isFull(){
        return (last == (max_itens - 1));
    }

    void push(int item){
        if(isFull()){
            cout << "A pilha esta cheia\n";
        } else {
            items[last + 1] = item;
            last++;
        }
    }

    int pop(){
        if(isEmpty()){
            cout << " A pilha esta vazia\n";
        } else {
            last--;
            return items[last-1];
        }
    }

    void print(){
        cout << "stack: [ ";
        for (int i = 0; i <= last; i++){
            cout << items[i] << " ";
        }
        cout << "]\n";
    }
};

int main(){
    stack s;
    s.pop();
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);

    s.print();

    s.push(1);

    s.print();
    
    
}
