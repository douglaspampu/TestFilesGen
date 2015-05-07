#include <iostream>
#include <fstream>
#include "regex.h"

using namespace std;

int main()
{
    Regex *r;

    r = new Regex("[3589]0[03][0-9]{6}[0-9]*");

    r->cria_automato();

    ofstream myfile;
    myfile.open ("example.txt");
    myfile << r->cria_automato();;
    myfile.close();

    return 0;
}


