#include "operacao_ponto.h"
#include <time.h>
#include <stdlib.h>

operacao_ponto::operacao_ponto()
{

}

operacao_ponto::~operacao_ponto()
{

}

char operacao_ponto::get_string()
{
    return char(rand() % 128);
}
