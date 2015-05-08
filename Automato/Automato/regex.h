#ifndef REGEX_H
#define REGEX_H

#include "automato.h"
#include "operacao.h"

class Regex
{
public:
    Regex(string re);
    ~Regex();

    string cria_automato();

private:
    string regex;

    Automato *Aut;

    string get_subexpressions(string _pilha, char token);
    string get_operacao(string _pilha);
    string get_strings (string _pilha);

    int cria_operacao_asterisco();
    string cria_operacao_mais(string _operacao);
    int cria_operacao_size(string _operacao);
    Automato *cria_operacao_or(string _operacao);
    string cria_operacao_set(string _operacao);

};

#endif // REGEX_H
