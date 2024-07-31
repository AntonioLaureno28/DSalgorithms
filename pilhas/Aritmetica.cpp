soma = 0;
            for(int j = 0; j < x; j++){
                //cout << soma << endl;
                soma += (sequencia[i+j] - '0') * pow(10,x-(j+1));
                //cout << (sequencia[i+j] - '0') * pow(10,x-(j+1)) << endl;
                cout << soma << endl;
            }

            inserir(inteiros,soma);
            i+=x-1;
        }else{
            if(sequencia[i] != '(' && sequencia[i] != ')' )
                inserir(caracteres,sequencia[i]);
        }
        if(sequencia[i] == ')'){
            int a = remover(inteiros);
            int o = remover(caracteres);
            int b = remover(inteiros);
            if(o == 43)
                inserir(inteiros,a + b);
            if(o == 45)
                inserir(inteiros,b - a);
            if(o == 42)
                inserir(inteiros,a * b);
            if(o == 47)
                inserir(inteiros,b / a);
        }
    }
    topo(inteiros);
}