#include "operador_string.h"

operador_string::operador_string()
{

}

operador_string::~operador_string()
{

}

void operador_string::set_string(string _aux)
{
    expressao = _aux;
}

string operador_string::get_string()
{
    return expressao;
}
