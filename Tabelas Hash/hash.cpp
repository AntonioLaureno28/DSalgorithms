#include <iostream>
using namespace std;

struct Aluno {
    int Ra;
    string Nome;
    Aluno() : Ra(-1), Nome("") {}  
    Aluno(int ra, string nome) : Ra(ra), Nome(nome) {}  
};


class Hash
{
private:
    Aluno aluno;
    int m;
    int funcaoHash(Aluno aluno){
        return aluno.Ra % m;
    }
    Aluno* estrutura;

public:
    Hash(int tam_vetor){
        m = tam_vetor;
        estrutura = new Aluno[tam_vetor];
    }
    ~Hash(){
        delete [] estrutura;
    }

    void inserir(Aluno aluno){
        int local = funcaoHash(aluno);
        estrutura[local] = aluno;
    }

    void deletar(Aluno aluno){
        int local = funcaoHash(aluno);
        if (estrutura[local].Ra != -1){
            estrutura[local] = Aluno();
        }
    }

    void buscar(Aluno& aluno, bool& busca){
        int local = funcaoHash(aluno);
        Aluno aux = estrutura[local];
        if (aluno.Ra != aux.Ra){
            busca = false;
        } else {
            busca = true;
            aluno = aux; 
        }
    }

    void imprimir(){
        for (int i = 0; i < m; i++){
            if (estrutura[i].Ra != -1){
                cout << i << ":" << estrutura[i].Ra;
                cout << estrutura[i].Nome << endl;
            }
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



