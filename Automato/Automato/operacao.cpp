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
}
