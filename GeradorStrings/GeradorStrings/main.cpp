#include <iostream>
#include <fstream>
#include "regex.h"

using namespace std;

int main(int argc, char *argv[])
{
    Regex *r;

    ofstream myfile;
    string filename;
    string StringsGeradas = "";

    myfile.open ("example.txt");

    for (int i = 1; i < argc; i++)
    {
        if(argv[i] == "-file")
        {
            myfile.open ("example.txt");
        }
        else
        {
            r = new Regex(argv[i]);

            StringsGeradas += r->cria_automato() + ',';

            myfile << r->cria_automato();
        }
    }

    myfile.open (filename.c_str());

    myfile << StringsGeradas;

    myfile.close();

    return 0;
}



