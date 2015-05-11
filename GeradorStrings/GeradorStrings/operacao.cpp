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
    string aux;

    switch (checa_conteudo)
    {
        case 1:
            return Set->cria_operacao_set();
            break;
        case 2:
            aux = Ponto->get_string();
            return aux;
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

char operacao::get_ponto()
{
    return Ponto->get_string();
}

void operacao::put_ponto()
{
    Ponto = new operacao_ponto();

    checa_conteudo = 2;
}
