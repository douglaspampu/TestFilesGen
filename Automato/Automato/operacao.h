#ifndef OPERACAO_H
#define OPERACAO_H
#include "set.h"
#include "operador_or.h"
#include "operador_string.h"

class operacao
{
public:
    operacao();
    ~operacao();

    set *get_set();
    void put_set(set *_aux);

    operador_or *get_or();
    void put_or(operador_or *_aux);

    operador_string *get_string();
    void put_expressao(operador_string *_aux);

    string get_expressao();

    int verifica_conteudo();

private:
    set *Set;
    operador_or *Or;
    operador_string *Expressao;

    int checa_conteudo;
};

#endif // OPERACAO_H
