#include <iostream>
#include <exception>

using namespace std;


class Matriz
{
private:

    int numeroLinhas;
    int numeroColunas;
    double **m;

public:
    Matriz(int linhas, int colunas){
        numeroLinhas = linhas; 
        numeroColunas = colunas;
        m = new double*[linhas];
        for (int l = 0; l < linhas; ++l){
            m[l] = new double[colunas] {};
        }

    }
    ~Matriz(){
        for (int l = 0; l < numeroLinhas; ++l){
            delete[] m[l];
        }

        delete[] m;
    }

    double& operator()(int l, int c) {
        if (l >= numeroLinhas || c >= numeroColunas || l < 0 || c < 0)
            throw std::out_of_range("Índice fora dos limites da matriz.");
        return m[l][c];
    }

    int getLinhas() const {return numeroLinhas;}
    int getColunas() const {return numeroColunas;}

    Matriz operator+(const Matriz& outra){ // Garante que os objetos usados como parametros não sejam modificados.
        if (numeroLinhas != outra.numeroLinhas || numeroColunas != outra.numeroColunas)
            throw invalid_argument("As matrizes devem ter as mesmas dimensões para soma.");

        Matriz resultado(numeroLinhas, numeroColunas);{
            for (int i = 0; i < numeroLinhas; ++i){
                for (int j = 0; j < numeroColunas; ++j){
                    resultado(i,j) = this->m[i][j] + outra.m[i][j];
                }
            }
        }
        return resultado;
    }

};


