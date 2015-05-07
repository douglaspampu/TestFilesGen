#ifndef ESTADO_H
#define ESTADO_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Estado
{
public:
    Estado(string Nome, bool _final);
    ~Estado();

    string get_nome();
    Estado *add_filho(string Nome, bool _final);
    void add_estado(Estado *_filho);

    vector<Estado *> get_adjascentes();
    Estado *get_n_estado(int i);
    int get_num_estados();

    bool is_final();

private:
    string NomeEstado;
    vector <Estado*> EstadosAdjascentes;

    bool EstadoFinal;
};

#endif // ESTADO_H
