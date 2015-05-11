#include "operacao.h"

operacao::operacao()
{

}

operacao::~operacao()
{

}

set *operacao::get_set()
{
    return Set;
}

void operacao::put_set(set *_aux)
{
    Set = _aux;

    checa_conteudo = 1;
}

operador_or *operacao::get_or()
{
    return Or;
}

void operacao::put_or(operador_or *_aux)
{
    Or = _aux;
    checa_conteudo = 2;
}

operador_string *operacao::get_string()
{
    return Expressao;
}

void operacao::put_expressao(operador_string *_aux)
{
    Expressao = _aux;
    checa_conteudo = 3;
}

string operacao::get_expressao()
{
    switch (checa_conteudo)
    {
        case 1:
            return Set->cria_operacao_set();
            break;
        case 2:
            return Or->gera_expressao();
            break;
        case 3:
            return Expressao->get_string();
            break;
    }
}

int operacao::verifica_conteudo()
{
    return checa_conteudo;
}
