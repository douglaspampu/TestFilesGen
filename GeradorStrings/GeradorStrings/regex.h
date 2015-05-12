#ifndef REGEX_H
#define REGEX_H

#include "operacao.h"
#include <vector>
#include <iostream>

using namespace std;

class Regex
{
public:
    Regex(string re);
    ~Regex();

    string cria_automato(string _reg);

private:
    string regex;

    string get_subexpressions(string _pilha, char token);
    string get_operacao(string _pilha);
    string get_strings (string _pilha);

    int cria_operacao_asterisco();
    string cria_operacao_mais(string _operacao);
    int cria_operacao_size(string _operacao);
    string cria_operacao_set(string _operacao);

};

#endif // REGEX_H
