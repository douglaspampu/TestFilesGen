#include <iostream>
#include <fstream>
#include "regex.h"

using namespace std;

int main()
{
    Regex *r;

    r = new Regex("([1-9][a])|([b][1-9])");

    r->cria_automato();

    ofstream myfile;
    myfile.open ("example.txt");
    myfile << r->cria_automato();;
    myfile.close();

    return 0;
}



