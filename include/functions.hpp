#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//GERAIS
void sayHello();
void Assert(bool x, string text);
char* checkLineArguments(int argc, char **argv, int x);

//CLASSES
class Follower{
    public:
        //Construtor
        Follower();
        Follower(string line);
        //Propostas aceitas
        int x1;
        int x2;
        //Propostas recusadas
        int y1;
        int y2;

        //Méthods
        void fill(string line);
        void print();
};

class Graph{
    public:
        int nodes;
        int edges;

};