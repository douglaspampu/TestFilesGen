#ifndef AUTOMATO_H
#define AUTOMATO_H

#include "estado.h"

class Automato
{
public:
    Automato(string _nome, bool _final);
    ~Automato();

    Estado *busca_estado(string _nome);
    Estado *get_raiz();
    bool add_filho(string _pai, string _filho, bool _final);
    bool add_estado(Estado* _filho);
    void percorre_automato();
    void imprime_automato();

    void uniao_automato(Automato *_aux);

private:
    Estado *EstadoInicial;

    vector <Estado*> ListaEstados;

    void interno_percorre_automato(Estado *_e);
};

#endif // AUTOMATO_H
