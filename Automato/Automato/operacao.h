#ifndef OPERACAO_H
#define OPERACAO_H
#include "set.h"

class operacao
{
public:
    operacao();
    ~operacao();

    set *get_set();
    void put_set(set *_aux);

private:
    set *Set;
};

#endif // OPERACAO_H
