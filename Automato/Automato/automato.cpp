#include "automato.h"

Automato::Automato(string _nome, bool _final)
{
    Estado *Aux;
    Aux = new Estado(_nome, _final);

    EstadoInicial = Aux;

    ListaEstados.push_back(Aux);
}

Automato::~Automato()
{

}

Estado *Automato::busca_estado(string _nome)
{
    int i = 0;
    int NumEstados = ListaEstados.size();

    while(i < NumEstados)
    {
        if(_nome == ListaEstados[i]->get_nome())
        {
            return ListaEstados[i];
        }

        i++;
    }

    return NULL;
}

Estado *Automato::get_raiz()
{
    return EstadoInicial;
}

bool Automato::add_filho(string _pai, string _filho, bool _final)
{
    Estado *Aux, *NEstado;

    NEstado = busca_estado(_filho);

    Aux = busca_estado(_pai);

    if (NEstado != NULL)
    {
        Aux->add_estado(NEstado);
        return true;
    }
    else
    {
        NEstado = Aux->add_filho(_filho, _final);

        if(NEstado != NULL)
        {
            ListaEstados.push_back(NEstado);

            return true;
        }
        else
        {
            return false;
        }
    }
}

void Automato::percorre_automato()
{
    interno_percorre_automato(EstadoInicial);
}

void Automato::interno_percorre_automato(Estado *_e)
{
    int numEstados = _e->get_num_estados();

    cout<<_e->get_nome()<<endl;

    for (int i = 0; i < numEstados; i++)
    {
        interno_percorre_automato(_e->get_n_estado(i));
    }
}

void Automato::imprime_automato()
{
    int i = 0;

    while (i < ListaEstados.size())
    {
        cout << ListaEstados[i]->get_nome() << endl;

        i++;
    }
}

void Automato::uniao_automato(Automato *_aux)
{
    EstadoInicial->add_estado(_aux->get_raiz());
    ListaEstados.push_back(_aux->get_raiz());
}
