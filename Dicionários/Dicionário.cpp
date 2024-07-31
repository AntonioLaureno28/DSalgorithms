#include <iostream>
#include <string>
const int max_items = 50;


using namespace std;


class Dicionario
{
private:
    int keys[max_items];
    string names[max_items];
    int tamanho;
public:

    Dicionario(): tamanho(0) {}
    

    void inserir (int key, const string name){
        for (int i = 0; i < tamanho; i++){
            if (this->keys[i] == key) {
                this->names[i] = name;
                cout << "Matricula" << key << "atualizada com sucesso" << endl;
            }
        }

        if (tamanho < max_items) {
            this->keys[tamanho] = key;
            this->names[tamanho] = name;
            tamanho++;
        }
    }

    void consultar (int key){
        for (int i = 0; i < tamanho; i++){
            if (this->keys[i] == key) {
                cout << "Dados da matricula: " << this->names[i] << endl;
            }
        }

        cout << "Numero de matricula nao existe.";
    }

    void remover (int key) {
        for (int i = 0; i < tamanho; i++){
            if (this->keys[i] == key) {
                for (int j = i; j < tamanho - 1; j++){
                    this->keys[j] = this->keys[j+1];
                    this->names[j] = this->names[j+1];
                }
                tamanho--;
                cout << "Matricula removida";
            }
        }
        cout << "Matricula nao existe no banco de dados.";
    }

    void print(){
        if (tamanho > 0){
            for (int i = 0; i < tamanho; i++){
                cout << this->keys[i] << ":" << this->names[i] << endl;
            }
        } else {
            cout << "Lista de matriculas vazia. Cadastre alguma matricula para inicar a lista.";
        }
        
    }

};

int main() {
    Dicionario d;
    string Nome;
    int Matricula;
    int opcao;


    while (opcao != 5) {
        cout << "Selecione uma opcao: Cadastrar Matricula (1); Consultar Matricula (2); Remover Cadastro de Matricula (3); Lista de Matriculas (4);Encerrar Operacao (5)\n";
        cin >> opcao;
        switch (opcao) {
        case 1:
            cout << "Digite a matricula: \n";
            cin >> Matricula;
            cout << "Digite o nome: \n";
            cin.ignore();
            getline(cin, Nome);
            d.inserir(Matricula, Nome);
            break;
        case 2:
            cout << "Digite a matricula a ser cunsultada: \n";
            cin >> Matricula;
            d.consultar(Matricula);
            break;
        case 3: 
            cout <<  "Digite a matricula a ser removida: \n";
            cin >> Matricula;
            d.remover(Matricula);
            break;
        case 4:
            d.print();
            break;
        default:
            break;
        }
    }
    
    return 0;

}


