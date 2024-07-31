typedef int TipoItem;
const int max_itens=5;


class fila
{
private:
    int first, last;
    TipoItem* estrutura; 
public:
    fila();
    bool isFull();
    bool isEmpty();
    void push(TipoItem item);
    TipoItem pop();
    void print();
};




