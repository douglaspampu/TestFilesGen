#ifndef OPERACAO_H
#define OPERACAO_H
#include "set.h"
#include "operador_string.h"
#include "operacao_ponto.h"

class operacao
{
public:
    operacao();
    ~operacao();

    set *get_set();
    void put_set(set *_aux);

    operador_string *get_string();
    void put_expressao(operador_string *_aux);

    string get_expressao();

    void put_ponto();
    char get_ponto();

    int verifica_conteudo();

private:
    set *Set;
    operador_string *Expressao;
    operacao_ponto *Ponto;

    int checa_conteudo;
};

#endif // OPERACAO_H
