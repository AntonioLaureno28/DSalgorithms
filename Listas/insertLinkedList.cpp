#include <iostream>


using namespace std;


struct node
{
    int x;
    node* next;
};


class LinkedList
{
public:
    node *head;

    LinkedList(){
        head = nullptr;
    }

    void insertSort(int y){
        node* aux = new node;
         y = aux->x; 
        if (head == nullptr || aux->x < head->x){
            aux->next = head;
            head = aux;
        } else {
            node* aux2 = head;
            while (aux2->next != nullptr && aux2->next->x < aux->x)
            {
                aux2 = aux2->next;
            }
            aux->next = aux2->next;
            aux2->next = aux;
            
        }
    }
    

    ~LinkedList();
};

