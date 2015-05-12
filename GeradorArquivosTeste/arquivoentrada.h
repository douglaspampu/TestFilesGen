#ifndef ARQUIVOENTRADA_H
#define ARQUIVOENTRADA_H
#include <string>
#include <vector>
#include <iostream>
#include "C:\Users\douglas.pampu\Documents\TestFileGenerator\GeradorStrings\GeradorStrings\regex.h"


using namespace std;

class ArquivoEntrada
{
public:
    ArquivoEntrada(string _arquivo);
    ~ArquivoEntrada();

    string cria_registro();

private:
    vector<string> ListaRegex;
    bool separador;

    int num_registros;

    Regex *reg;

};

#endif // ARQUIVOENTRADA_H
