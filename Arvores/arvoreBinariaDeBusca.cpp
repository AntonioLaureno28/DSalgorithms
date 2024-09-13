#include <iostream>

using namespace std;

struct node
{
    int valor;
    node* esq;
    node* dir;
};
    
class arvoreBinariaDeBusca
{
private:
    node* raiz;
public:
    arvoreBinariaDeBusca(){
        raiz = nullptr;
    }

    node* ABB(int arr[], int left, int right){
        if (left > right){
            return nullptr;
        }


        int mid = left + (right - left)/2;
        node* no = new node;
        no->valor = arr[mid];

        no->esq = ABB(arr, left, mid - 1);
        no->dir = ABB(arr, mid + 1, right);

        return no;
    }

    node* array(int arr[], int tam_vetor){
        if (tam_vetor == 0){
            return nullptr;
        }

        return ABB(arr, 0, tam_vetor-1);
    }
    ~arvoreBinariaDeBusca();
};



