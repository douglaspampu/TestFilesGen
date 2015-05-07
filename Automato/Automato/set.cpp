#include "set.h"
#include <time.h>
#include <stdlib.h>

#include <iostream>

using namespace std;

set::set()
{
    srand (time(NULL));
}

set::~set()
{

}

void set::set_operacao(string _aux)
{
    operacao = _aux;
}

string set::cria_operacao_set()
{
    string inicio_do_range;
    string fim_do_range;

    string retorno;

    bool inicio_fim = false;
    bool conjunto_negado = false;

    for(int i = 0; i < operacao.size(); i++)
    {
        switch (operacao[i])
        {
            case '[':

                break;
            case ']':

                break;
            case ' ':

                break;
            case '-':
                inicio_fim = true;
                break;
            case '^':
                conjunto_negado = true;
                break;
            default:
                if(!inicio_fim)
                    inicio_do_range += operacao[i];
                else
                    fim_do_range += operacao[i];
                break;
        }
    }

    cout << "inicio: " << inicio_do_range << " fim: " << fim_do_range << endl;

    if(inicio_fim)
    {
        int inicio = int(inicio_do_range[0]);
        int fim = int(fim_do_range[0]);

        int range = fim - inicio;

        range = rand() % range;

        retorno = char(range+inicio);

        cout<<"ascii: "<<range+inicio<<" char: " << char(range+inicio)<<endl;
    }
    else
    {
        if (conjunto_negado)
        {
            int char_in_set;
            bool char_escolhido = false;

            while(char_escolhido == false)
            {
                char_in_set = rand() % 256;
                char_escolhido = true;
                for (int i = 0; i < inicio_do_range.size(); i++)
                {
                    if(char_escolhido == int(inicio_do_range[i]))
                        char_escolhido = false;
                }
            }

            retorno = char(char_in_set);

            cout<<"char: " << char(char_in_set)<<endl;
        }
        else
        {
            int range = inicio_do_range.size();

            range = rand() % range;

            retorno = inicio_do_range[range];

            cout<<"char: " << inicio_do_range[range]<<endl;
        }
    }

    return retorno;
}
