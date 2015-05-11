#include "estado.h"

Estado::Estado(string Nome, bool _final)
{
    NomeEstado = Nome;

    EstadoFinal = _final;
}

Estado::~Estado()
{

}

string Estado::get_nome()
{
    return NomeEstado;
}

Estado *Estado::add_filho(string Nome, bool _final)
{
    Estado *NE = new Estado(Nome, _final);

    EstadosAdjascentes.push_back(NE);

    return NE;
}

void Estado::add_estado(Estado *_filho)
{
    EstadosAdjascentes.push_back(_filho);
}

vector<Estado*> Estado::get_adjascentes()
{
    return EstadosAdjascentes;
}

Estado *Estado::get_n_estado(int i)
{
    return EstadosAdjascentes[i];
}

int Estado::get_num_estados()
{
    return EstadosAdjascentes.size();
}

bool Estado::is_final()
{
    return EstadoFinal;
}
