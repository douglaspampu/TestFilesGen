#ifndef OPERADOR_STRING_H
#define OPERADOR_STRING_H

#include <string>

using namespace std;

class operador_string
{
public:
    operador_string();
    ~operador_string();

    void set_string(string _aux);
    string get_string();


private:
    string expressao;
};

#endif // OPERADOR_STRING_H
