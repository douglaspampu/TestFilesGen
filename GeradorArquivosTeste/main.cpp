#include <iostream>
#include "arquivoentrada.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    ArquivoEntrada *arq = new ArquivoEntrada("CSV:TRUE\nnome_do_campo:regex;tamanho\nnome_do_campo:regex;tamanho");

    return 0;
}

