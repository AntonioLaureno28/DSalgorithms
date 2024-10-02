#include <iostream>
using namespace std;

struct Aluno {
    int Ra;
    string Nome;
    Aluno() : Ra(-1), Nome("") {}  
    Aluno(int ra, string nome) : Ra(ra), Nome(nome) {}  
};

struct Node {
    Aluno aluno;
    Node* next;
    
    Node(Aluno a) : aluno(a), next(nullptr) {}
};

class Hash
{
private:
    Aluno aluno;
    Node node;
    int m;
    Node** estrutura;
    int funcaoHash(Aluno aluno){
        return aluno.Ra % m;
    }

public:
    Hash(int tam_vetor){
        m = tam_vetor;
        estrutura = new Node*[tam_vetor]; // criando a hash table
        for (int i = 0; i < m; i++){
            estrutura[i] = nullptr;
        }
    }
    ~Hash(){
        delete [] estrutura;
    }

    void inserir(Aluno aluno){
        int local = funcaoHash(aluno);
        Node* aux = new Node(aluno); // crio o nó 

        aux->next = estrutura[local];
        estrutura[local] = aux;
    }

    void deletar(Aluno aluno){
        int local = funcaoHash(aluno);
        Node* atual = estrutura[local];
        Node* anterior = nullptr;

        while(atual != nullptr && atual->aluno.Ra != aluno.Ra){
            anterior = atual;
            atual = atual->next;
        }

        if (atual != nullptr){
            if (anterior == nullptr){
                estrutura[local] = atual->next;
            } else {
                anterior->next = atual->next;
            }
        }
        
    }

    void buscar(Aluno& aluno, bool& busca){
        int local = funcaoHash(aluno);
        Node* atual = estrutura[local];
        busca = false;

        while (atual != nullptr)
        {
            if (atual->aluno.Ra == aluno.Ra){
                aluno = atual->aluno;
                busca = true;
                return;
            }
        }
        atual = atual->next;
        
    }

    void imprimir(){
        for (int i = 0; i < m; i++){
            Node* aux = estrutura[i];
            if (aux == nullptr){
                cout << "poha nenhuma";
            }
            while (aux != nullptr) {
                cout << "[" << aux->aluno.Ra << ", " << aux->aluno.Nome << "] -> ";
                aux = aux->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main(){
    int tam_vetor;
    cout << "digite o tamanho da tabela hash: ";
    cin >> tam_vetor;
    Hash hash(tam_vetor);
    int opcao, ra;
    string nome;
    bool busca;

    do
    {
        cout << "digite 0 para parar\n";
        cout << "digite 1 para inserir\n";
        cout << "digite 2 para remover\n";
        cout << "digite 3 para buscar\n";
        cout << "digite 4 para imprimir a tabela\n";
        cin >> opcao;

        if (opcao == 0) {
    // O caso 0 é normalmente para sair, então não há nada para executar aqui
    } else if (opcao == 1) {
        cout << "Informe o RA do aluno: ";
        cin >> ra;
        cout << "Informe o nome do aluno: ";
        cin >> nome;
        hash.inserir(Aluno(ra, nome));
    } else if (opcao == 2) {
        cout << "Informe o RA do aluno para remover: ";
        cin >> ra;
        Aluno aluno(ra, " ");  // Supondo que o nome não é relevante para a operação de remoção
        hash.deletar(aluno);
    } else if (opcao == 3) {
        cout << "Informe o RA do aluno para buscar: ";
        cin >> ra;
        Aluno aluno(ra, " ");  // Nome é irrelevante para a busca
        hash.buscar(aluno, busca);
        cout << (busca ? "Aluno encontrado." : "Aluno não encontrado.") << endl;
    } else if (opcao == 4) {
        hash.imprimir();
    } else {
        cout << "Opção inválida!" << endl;
}

    } while (opcao != 0);

}


