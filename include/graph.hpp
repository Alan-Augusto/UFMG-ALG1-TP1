#include <iostream>
#include <list>
#include <stack>
 
using namespace std;
 
class Graph
{
    //Número Vértices
	int V;
    //Vetor com as listas de adjascencia
	list<int> *adj;
 
    public:
        //Construtor que recebe o número de vértices, pois já sabemos quantos serão.
        Graph(int V);

        //Adiciona uma aresta entre o vértice v1 e v2
        void addEdge(int v1, int v2);
    
        //Faz DFS em busca de um vértice v.
        void dfs(int v);
};
 
