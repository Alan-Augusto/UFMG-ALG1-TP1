#include <functions.hpp>

//=====FUNÇÕRD GERAIS=====
    void sayHello(){
        cout << "Hello World!" << endl;
    }

    void Assert(bool x, string text){
        if(!x){
            cout << text << endl;
            exit(1);
        }
    }

    char* checkLineArguments(int argc, char **argv, int x){
        if(argc < 2){
            cout << "--------Few arguments---------" << endl;
            cout << "---provide the file address---" << endl;
            exit(1);
        }
        return argv[x];
    }

    int neg(int x, int tamNat){
        return tamNat + x; 
    }

//============================
//_____FUNÇÕES DE CLASSES_____

//=====Follower=====
    //Preenche um seguidor a partir de uma linha
    Follower::Follower(){
        x1 = -1;
        x2 = -1;
        y1 = -1;
        y2 = -1;
    }
    Follower::Follower(string line){
        stringstream lineITvalues(line);
            lineITvalues >> x1;
            lineITvalues >> x2;
            lineITvalues >> y1;
            lineITvalues >> y2;
    }

    void Follower::print(){
        cout << x1 << " | ";
        cout << x2 << " | ";
        cout << y1 << " | ";
        cout << y2 << endl;;
    }

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
    
    bool Graph::dfs(int v, int y){
        //int inityNode = v;
        //cout << "Buscando caminho" << v  << " --> "<< y << endl;
        stack<int> pilha;
        bool visitados[V]; // vetor de visitados
    
        // marca todos como não visitados
        for(int i = 0; i < V; i++)
            visitados[i] = false;
    
        while(true)
        {
            
            if(!visitados[v]){
                //cout << "Visitando vertice " << v << " ...\n";
                if(v == y){
                    //cout << "######Encontrou caminho de " << inityNode << " até " << v << endl;
                    return true;
                }
                visitados[v] = true; // marca como visitado
                pilha.push(v); // insere "v" na pilha
            }
    
            bool achou = false;
            list<int>::iterator it;
    
            // busca por um vizinho não visitado
            for(it = adj[v].begin(); it != adj[v].end(); it++)
            {
                if(!visitados[*it])
                {
                    achou = true;
                    break;
                }
            }
    
            if(achou)
                v = *it; // atualiza o "v"
            else
            {
                // se todos os vizinhos estão visitados ou não existem vizinhos
                // remove da pilha
                pilha.pop();
                //cout << "Sem vizinhos -> volta um passo na pilha" << endl;
                // se a pilha ficar vazia, então terminou a busca
                if(pilha.empty())
                    break;
                // se chegou aqui, é porque pode pegar elemento do topo
                v = pilha.top();
            }
        }
        return false;
    }