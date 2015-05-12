
#include <time.h>
#include <stdlib.h>
#include<iostream>

using namespace std;
operador_or::operador_or()
{
}

operador_or::~operador_or()
{

}

void operador_or::set_expressao(string _aux)
{
    expressao = _aux;
}

string operador_or::gera_expressao()
{
    int num_strings = 1;
    int range;

    string result;

    for(int i  = 0; i < expressao.size(); i++)
    {
        if(expressao[i] == '|')
        {
            num_strings++;
        }
    }

    range = rand() % num_strings;

    num_strings = 0;


    for(int i  = 0; i < expressao.size(); i++)
    {
        if(num_strings == range)
        {
            while(expressao[i]!= '|' && i < expressao.size())
            {
                result += expressao[i];
                i++;
            }

            return result;
        }

        if(expressao[i] == '|')
        {
            num_strings++;
        }
    }
}
