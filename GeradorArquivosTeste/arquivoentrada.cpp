#include "arquivoentrada.h"

ArquivoEntrada::ArquivoEntrada(string _arquivo)
{
    string regex;
    int sep = 0;
    for (int i = 0; i < _arquivo.size(); i++)
    {
        if(regex == "CSV")
        {
            i++;
            sep = 1;

            regex = "";
        }
        else if(sep == 1)
        {
            if(regex == "TRUE")
            {
                separador = true;

                sep = 2;
                regex = "";
            }
            else if(regex == "FALSE")
            {
                separador = false;

                sep = 2;
                regex = "";
            }
        }
        else if(_arquivo[i] == ':')
        {
            regex = "";
            i++;

            while(_arquivo[i] != '\n' && i < _arquivo.size())
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

