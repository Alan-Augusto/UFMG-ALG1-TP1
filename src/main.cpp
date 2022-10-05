#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <functions.hpp>

using namespace std;

int main(int argc,char ** argv){

    //Recolhe endereço do arquivo e confere os argumentos:
    char *inputNameArq = lineArguments(argc, argv, 1);
    
    //Variaveis principais
    ifstream InputFile(inputNameArq);
    Assert(InputFile.is_open(), "Opening error in input file");

    int Numfollowers;
    int Numproposals;
    string line;

    //Recolhe as variáveis em cada linha e execura a função
    while(getline(InputFile, line)){
        //Cria variável de iteração da linha
        stringstream lineITfirst(line);

        //Recolhe a primeira linha
        lineITfirst >> Numfollowers;
        lineITfirst >> Numproposals;

        cout << Numfollowers << " | " << Numproposals << endl;

        for(int i = 0; i < Numfollowers; i++){
            getline(InputFile, line);
            stringstream lineITvalues(line);
             int x1;
             int x2;
             int y1;
             int y2;

             lineITvalues >> x1;
             lineITvalues >> x2;
             lineITvalues >> y1;
             lineITvalues >> y2;

             cout << x1 << " | " << x2 << " | " << y1 << " | " << y2 << endl;
             
        }
    }

    return 0;
}