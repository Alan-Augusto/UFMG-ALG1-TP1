#include <functions.hpp>

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

        //Recolhe a primeira linha e confere
        lineITfirst >> Numfollowers;
        lineITfirst >> Numproposals;

        Assert((Numfollowers != 0 || Numproposals != 0), "");

        Assert((Numfollowers<=1000 && Numfollowers >0), "Valor incorreto de 'S' (1 <= S <= 1000)");
        Assert((Numproposals<=10000 && Numproposals >0), "Valor incorreto de 'P' (1 <= P <= 10000)");

        //cout << Numfollowers << " Seguidores | ";
        //cout << Numproposals << " Propostas" << endl;

        //Vetor temporários de cada rodada
        Follower followers[Numfollowers];

        //Recolhe os valores de cada seguidor
        for(int i = 0; i < Numfollowers; i++){
            getline(InputFile, line);
            
            //Recolhe os valores do seguidor
            Follower person(line, Numproposals);
            //person.fill(line);

            //Coloca o seguidor no vetor
            followers[i] = person;
        }

        //Verifica se a satisfabilidade
        satisfiabilityCheck(followers, Numfollowers, Numproposals);
    }

    return 0;
}