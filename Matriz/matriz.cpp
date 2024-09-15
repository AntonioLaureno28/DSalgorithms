#include <iostream>
#include <exception>

using namespace std;

class matriz
{
private:
    int numeroLinhas;
    int numeroColunas;
    double **m;

public:
    matriz(int linhas, int colunas){
        numeroLinhas = linhas;
        numeroColunas = colunas;

        m = new double*[linhas];

        for (int l = 0; l < linhas; ++l){
            m[l] = new double [colunas];
        }
    }

    ~matriz(){
        for (int l = 0; l < numeroLinhas; ++l){
            delete[] m[l];
        }

        delete[] m;
    }

   

    double& operator()(int l, int c) {
        if (l < 0 || l >= numeroLinhas || c < 0 || c >= numeroColunas) {
            throw std::out_of_range("Índice fora dos limites da matriz");
    }
    return m[l][c];
}


};

int main(){
    {
        try
        {
            int l; cout << "linhas:"; cin >> l;
            int c; cout << "colunas: "; cin >> c;

            matriz M(l,c);

            int i = 0;
            int j = 0;
            double valor = 3.14;

            M(i,j) = valor;

            cout << M(i,j);
            
        }
        catch(const exception& e)
        {
            cerr << "Exceção: " << e.what() << '\n';
            return 1;
        }
        
    }
}



