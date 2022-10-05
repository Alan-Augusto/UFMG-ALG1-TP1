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
        //Variável de iteração da linha
        stringstream lineITfirst(line);

        //Recolhe a primeira linha
        lineITfirst >> Numfollowers;
        lineITfirst >> Numproposals;

        //Bloco temporários de cada rodada
        follower followers[Numfollowers];

        //Recolhe os valores de cada seguidor
        for(int i = 0; i < Numfollowers; i++){
            getline(InputFile, line);
            
            //Recolhe os valores do seguidor
            follower person;
            person.fill(line);

            //Coloca o seguidor no vetor
            followers[i] = person;
        }

        //Verifica se a satisfabilidade
        //satisfiabilityCheck(followers);
    }

    return 0;
}