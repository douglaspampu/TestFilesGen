#ifndef SET_H
#define SET_H


#include <string>

using namespace std;

class set
{
public:
    set();
    ~set();

    void set_operacao(string _aux);
    string cria_operacao_set();

private:

    string operacao;
};

#endif // SET_H
