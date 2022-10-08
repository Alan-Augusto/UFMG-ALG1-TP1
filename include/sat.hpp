#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//PROBLEMA CENTRAL DO ALGORITMO SAT:

//EXISTER ALGUMMA COMBINAÇÃO DE VARIÁVEIS QUE FAZ COM 
//QUE A EXRPESSÃO "S" RESULTE EM VERDADEIRO???
    //-> Expressões na forma normal conjuntiva
    // S = (a+b)&(a+c)&(c+t)&....

//SOlUÇÃO:
    //Precisamos criar um grafo com 2*n nós, onde "n" é o número de variáveis.
        //Para cada variável teremos sua afirmação e sua negação
        //A partrir dai, vamos criar as arestas de implicação, ou seja:
            // Se a cláusula é (x1+x2), sabemos que, [~x1 -> x2] e [~x2 -> x1]
            //Dependendo do resultado da verificação, craiermos as arestas.
        //Satisfação:
            //A expressão !!NÃO É SATISFATÍVEL!! se, e somente se:
            //Existir um caminho de uma variável x até a sua negação (~x)
            //Existir o caminho contrário, de ~x até x.
                //Isso significa que existe um ciclo patológico:
                    //Se eu tenho um caminho de implicações que levam uma afirmação 
                    //à sua egação, significa que ela deve ser falsa e verdadeira ao 
                    //mesmo tempo, o que é uma contradição.
    //Algoritmo:
        //Para cada variável da minha expressão:
            //Se [existir caminho BFS(x -> ~x) && existir o caminho BFS(~x -> x) ]
                //Então a expressão NÃO é satisfatível
            //Caso contrário
                //É satisfazível

