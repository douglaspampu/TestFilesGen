#include "arquivoentrada.h"
#include <stdlib.h>

string gera_campo(string regex)
{
    Regex *r1 = new Regex("");
    string campo = r1->cria_automato(regex);

    return campo;
}

ArquivoEntrada::ArquivoEntrada(string _arquivo)
{
    reg = new Regex("");
    string regex;
    string aux = "";
    int sep = 0;
    for (int i = 0; i < _arquivo.size(); i++)
    {
        if(regex == "CSV")
        {
            i++;
            sep = 1;

            regex = "";
        }
        else if(regex == "NUM")
        {
            i++;

            regex = "";
            while(_arquivo[i] != '\n')
            {
                aux += _arquivo[i];

                i++;
            }

            num_registros = atoi(aux.c_str());

            aux = "";
        }
        else if(sep == 1)
        {
            if(regex == "TRUE")
            {
                separador = true;

                sep = 2;
                regex = "";

                while(_arquivo[i] != '\n')
                {
                    i++;
                }

                char_separador = _arquivo[i-1];

                i++;
            }
            else if(regex == "FALSE")
            {
                separador = false;

                sep = 2;
                regex = "";
                i++;
            }

        }
        else if(_arquivo[i] == ':')
        {
            regex = "";
            i++;

            while(_arquivo[i] != char(10) && i < _arquivo.size())
            {
                regex += _arquivo[i];
                i++;
            }

            ListaRegex.push_back(regex);
            regex = "";

            i++;
        }


        regex += _arquivo[i];
    }

    for (int i = 0; i < ListaRegex.size(); i++)
        cout<<ListaRegex[i]<<endl;
}

ArquivoEntrada::~ArquivoEntrada()
{

}

string ArquivoEntrada::cria_registro()
{
    string regex;
    string registro;
    string linha;
    string aux, aux_tam;


    Regex r("");


    int tamanho_maximo;
    int NRegistros = 0;

    while(NRegistros < num_registros)
    {
        linha = "";
        for (int i = 0; i < ListaRegex.size(); i++)
        {
            int j = 0;
            aux = ListaRegex[i];

            regex = "";
            while(aux[j] != ';')
            {
                regex += aux[j];

                j++;
            }

            j++;
            aux_tam = "";
            while(j < aux.size())
            {
                aux_tam += aux[j];

                j++;
            }

            tamanho_maximo = atoi(aux_tam.c_str());

            if(separador)
            {
                if(!linha.empty())
                    linha += char_separador;

                aux = r.cria_automato(regex);

                linha = linha + aux;
                aux = "";
            }
            else
            {
                aux = r.cria_automato(regex);

                if(aux.size() < tamanho_maximo)
                {
                    while(aux.size() < tamanho_maximo)
                        aux += ' ';
                }
                else
                {
                    return "";
                }

                linha = linha + aux;
                aux = "";
            }
        }
        registro += linha + '\n';
        NRegistros++;

    }

    cout<<"registro:\n"<<registro<<endl;
    return registro;
}

