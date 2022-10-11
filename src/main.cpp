#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <sat.hpp>

using namespace std;

int main(int argc,char ** argv){

    //Recolhe endereço do arquivo e confere os argumentos:
    char *inputNameArq = checkLineArguments(argc, argv, 1);
    
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

        cout << Numfollowers << " Seguidores | ";
        cout << Numproposals << " Propostas" << endl;

        //Vetor temporários de cada rodada
        Follower followers[Numfollowers];

        //Recolhe os valores de cada seguidor
        for(int i = 0; i < Numfollowers; i++){
            getline(InputFile, line);
            
            //Recolhe os valores do seguidor
            Follower person(line);
            //person.fill(line);

            //Coloca o seguidor no vetor
            followers[i] = person;
        }

        //Verifica se a satisfabilidade
        satisfiabilityCheck(followers, Numfollowers, Numproposals);
    }

    return 0;
}