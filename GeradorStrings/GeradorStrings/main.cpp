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

    /*for (int i = 1; i < argc; i++)
    {
        if(argv[i] == "-file")
        {
            filename = argv[i+1];
            i++;
        }
        else
        {
            r = new Regex(argv[i]);

            StringsGeradas += r->cria_automato() + ',';

            myfile << r->cria_automato();
        }
    }*/

    r = new Regex("");

    StringsGeradas += r->cria_automato("(30|31|a0[0-9]|b1[0-9]|c2[0-9])");

    cout<<"String gerada: "<<StringsGeradas<<endl;

    myfile.open (filename.c_str());

    myfile << StringsGeradas;

    myfile.close();

    return 0;
}



