typedef int TipoItem;
const int max_itens = 100;



class pilha
{
private:
   int tamanho;
   TipoItem* estrutura;
public:
    pilha();
    ~pilha();
    bool IsFull();
    bool IsEmpty();
    void push(TipoItem item);
    TipoItem pop();
    void print();
    int lenght();
};


