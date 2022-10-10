#include <graph.hpp>

//Construtor
Graph::Graph(int V){
	this->V = V;
    //Vetor com as listas de adjascencia -> Quantidade de vertice
	adj = new list<int>[V];
}

//Adiciona uma aresta entre o vértice v1 e v2
void Graph::addEdge(int v1, int v2){
	adj[v1].push_back(v2);
}
 
void Graph::dfs(int v){


	stack<int> pilha;
    //Verificar os vetices visitados e marcar todos, inicialmente como False.
	bool visitados[V];
	for(int i = 0; i < V; i++){
		visitados[i] = false;
    }

    //Precisamo rodar o loop "infinitamente" até que tenhamos a condição de parada
	while(true)
	{
        bool achou = false;
        //Variável de iteração
		list<int>::iterator it;


        //Se o item atual não foi visitado:
		if(!visitados[v]){
			//Marca como visitado e insere na pilha
            cout << "Visitando vertice " << v << " ...\n";
			visitados[v] = true;
			pilha.push(v);
		}

		//Buscamos por um vizinho que não foi visitado
		for(it = adj[v].begin(); it != adj[v].end(); it++){
			if(!visitados[*it]){
				achou = true;
				break;
			}
		}

        //Se achar um vizinho que não foi visitado, atualizamos o valor de "v"
		if(achou)
			cout << "Achamos " << *it << endl;
		else
		{
			// se todos os vizinhos estão visitados ou não existem vizinhos
			// remove da pilha
			pilha.pop();
			// se a pilha ficar vazia, então terminou a busca
			if(pilha.empty())
				break;
			// se chegou aqui, é porque pode pegar elemento do topo
			v = pilha.top();
		}
	}
}