#include <iostream>
#include <fstream>
#include "regex.h"

using namespace std;

int main()
{
    Regex *r;

    r = new Regex("([ads])");

    r->cria_automato();

    ofstream myfile;
    myfile.open ("example.txt");
    myfile << r->cria_automato();;
    myfile.close();

    return 0;
}



