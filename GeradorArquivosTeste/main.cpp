#include <iostream>
#include "arquivoentrada.h"
#include <fstream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    time_t sec;
    time(&sec);
    srand((unsigned int) sec);

    ifstream fin;
    fin.open("teste.txt");

    ofstream fout;
    fout.open("output.dat");

    string registros;

    string arquivo = "", aux;

    if (fin.is_open())
    {
        while(getline(fin, aux))
        {
            arquivo = arquivo + aux+'\n';

            aux = "";
        }
    }


    ArquivoEntrada *arq = new ArquivoEntrada(arquivo);

    registros = arq->cria_registro();

    fout<<registros;

    return 0;
}

