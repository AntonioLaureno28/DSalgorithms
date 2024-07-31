#include <iostream>
#include <string>
#include <algorithm>

const int max_items = 100;


using namespace std;

class Stack
{
private:
    double* vetor;
    int last;
public:
    Stack(){
        last = -1;
        vetor = new double[max_items];
    }
    
    bool isEmpty(){
        return (last == -1);
    }

    bool isFull(){
        return (last == (max_items - 1));
    }

    void push(int x){
        if (isFull()){
            std::cout << "A Pilha esta cheia\n";
        } else {
            vetor[last + 1] = x;
            last++;
        }
    }

    double pop(){
        if (isEmpty()){
            std::cout << "A Pilha esta vazia\n";
            return -1;
        } else {
            return vetor[last--];
        }
    }

    double peek() {
        if (isEmpty()) {
            std::cout << "A pilha está vazia\n";
            return -1; 
        }
        return vetor[last];
    }

    void print(){
        std::cout << "[ ";
        for (int i = 0; i <= last; i++){
            std::cout << vetor[i] << " ";
        }
        std::cout << "]\n";
    }
};

class Stack2
{
private:
    char vetor[max_items];
    int last;
public:
    Stack2(){
        last = -1;
    }
    
    bool isEmpty(){
        return (last == -1);
    }

    bool isFull(){
        return (last == (max_items - 1));
    }

    void push(char x){
        if (isFull()){
            std::cout << "A Pilha esta cheia\n";
        } else {
            vetor[last + 1] = x;
            last++;
        }
    }

    char pop(){
        if (isEmpty()){
            std::cout << "A Pilha esta vazia\n";
            
        } else {
            return vetor[last--];
        }
    }

    char peek() {
        if (isEmpty()) {
            std::cout << "A pilha está vazia\n";
            return -1; 
        }
        return vetor[last];
    }

    void print(){
        std::cout << "[ ";
        for (int i = 0; i <= last; i++){
            std::cout << vetor[i] << " ";
        }
        std::cout << "]\n";
    }
};

bool isNumber(char n){
    return ((n >= 0 && n <= 9) || (n == '.'));
}

double operacao(double operando1, double operando2, char opcao){
    switch (opcao) {
        case '+':
            return operando1 + operando2;
        case '-': 
            return operando1 - operando2;
        case '*':
            return operando1 * operando2;
        case '/':
            return operando1 / operando2;
        default:
        return 0.0;
    }
}

double converter( Stack2 &sequence ){
    string expressao;
    while (!sequence.isEmpty() && isNumber(sequence.peek())){
        expressao = expressao + sequence.peek();

    }


   
    
}
