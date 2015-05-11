#ifndef OPERADOR_OR_H
#define OPERADOR_OR_H

#include <string>

using namespace std;

class operador_or
{
public:
    operador_or();
    ~operador_or();

    void set_expressao(string _aux);

    string gera_expressao();

private:
    string expressao;
};

#endif // OPERADOR_OR_H
