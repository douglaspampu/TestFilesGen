#include <iostream>
#include "arquivoentrada.h"
#include <fstream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("teste.txt");

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

    arq->cria_registro();

    return 0;
}

