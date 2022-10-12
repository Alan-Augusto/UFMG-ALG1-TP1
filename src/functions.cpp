#include <functions.hpp>

//_____FUNÇÕES GERAIS___

    //Conferências gerais
    void Assert(bool x, string text){
        if(!x){
            if(text == ""){
                cout << text;
                exit(0);
            }
            cout << text << endl;
            exit(0);
        }
    }

    //ler a linha de comando
    char* checkLineArguments(int argc, char **argv, int x){
        if(argc < 2){
            cout << "--------Few arguments---------" << endl;
            cout << "---provide the file address---" << endl;
            exit(0);
        }
        return argv[x];
    }

    //Retorna a negação de um literal de acordo com a quantidade de propostas/literais
    int neg(int x, int numProposals){
        return numProposals + x; 
    }

    //ALGORITMO CENTRAL DE SATISFAÇÃO --> 2-SAT
        //Com impementação do grafo
    void satisfiabilityCheck(Follower followers[], int Numfollowers, int Numproposals){
        //Cria um grafo a partir do número de propostas
            //Multiplicado por 2 pos os valores negativos serão as negações
        Graph grafo(Numproposals*2+1);

        bool satisfazivel = true;
        
        //Faz a tradução da pesquisa em um grafo relacionado
        for(int i = 0; i < Numfollowers; i++){
            //Para uma decisão (X1 v x2) -> Para manter

                //Se x1 é 0
                if(followers[i].x1==0){
                    //Se x2 não é 0
                    if(followers[i].x2 != 0){
                        //Faz x2 ser verdade sempre
                        grafo.addEdge(neg(followers[i].x2, Numproposals), followers[i].x2);
                    }//Se x2 tbm é 0
                    else{
                        break;
                    }
                }//Se x1 não é 0
                else{
                    //Se x2 é 0
                    if(followers[i].x2==0){
                        //Faz x1 ser sempre verdadeiro
                        grafo.addEdge(neg(followers[i].x1, Numproposals), followers[i].x1);
                    }//Se x2 não é 0
                    else{
                        //Segue a lógica normal
                        // ~X1 -> x2
                        grafo.addEdge(neg(followers[i].x1, Numproposals), followers[i].x2);
                        // ~X2 -> x1
                        grafo.addEdge(neg(followers[i].x2, Numproposals), followers[i].x1);
                    }
                }

            
            //Para uma decisão (Y1 v Y2) -> Para remover
                //Se Y1 é 0
                if(followers[i].y1==0){
                    //Se y2 não é 0
                    if(followers[i].y2 != 0){
                        //Faz o y2 ser removido com certeza
                        //Y2 -> ~Y2
                        grafo.addEdge(followers[i].y2, neg(followers[i].y2, Numproposals));
                    }//Se y2 tbm é 0
                    else{
                        break;
                    }
                }//Se y1 não é 0
                else{
                    //Se y2 é 0
                    if(followers[i].y2 == 0){
                        //Faz o Y1 sempre ser removido
                        //Y1 -> ~Y1
                        grafo.addEdge(followers[i].y1, neg(followers[i].y1, Numproposals));
                    }//Se y2 não é 0
                    else{
                        //Segue logica normal
                        //Y1 -> ~Y2
                        grafo.addEdge(followers[i].y1, neg(followers[i].y2, Numproposals));
                        //Y2 -> ~Y1
                        grafo.addEdge(followers[i].y2, neg(followers[i].y1, Numproposals));
                    }
                }
        }

        //=#==#==#== 2-SAT =#==#==#==
        //Para cada ma das propostas/literais/vertices
        for(int j = 1; j<Numproposals; j++){
            //Confere o DFS de "ida" e o de "volta" da proposta com sua negação
            if(grafo.dfs(j, neg(j, Numproposals)) && grafo.dfs(neg(j, Numproposals), j)){
                //Se encontrar esses dois caminhos -> não é satisfazível
                satisfazivel = false;
                break;
            }
        }

        //Impressão final
        if(satisfazivel){
            cout << "sim" << endl;
        }
        else{
            cout << "nao" << endl;
        }
    }




//_____FUNÇÕES DE CLASSES_____

//=====Follower=====
    //Construtor caso não haja parâmetro
    Follower::Follower(){
        x1 = -1;
        x2 = -1;
        y1 = -1;
        y2 = -1;
    }

    //Preenche um seguidor a partir de uma linha padrão e o número de propostas para conferir
    Follower::Follower(string line, int p){
        stringstream lineITvalues(line);
            lineITvalues >> x1;
            Assert((x1>=0 && x1<=p), "Voto inválido");
            lineITvalues >> x2;
            Assert((x2>=0 && x2<=p), "Voto inválido");
            lineITvalues >> y1;
            Assert((y1>=0 && y1<=p), "Voto inválido");
            lineITvalues >> y2;
            Assert((y2>=0 && y2<=p), "Voto inválido");
    }


//=======Graph=======
    //Construtor a partir do número de vértices/literais/propostas
    Graph::Graph(int V){
        this->V = V;
        //Vetor com as listas de adjascencia -> Quantidade de vertice
        adj = new list<int>[V];
    }

    //Adiciona uma aresta entre o vértice v1 e v2
    void Graph::addEdge(int v1, int v2){
        //Apenas coloca o v2 na lista de adjascência de v1
        adj[v1].push_back(v2);
    }
    
    //Faz uma busca em profundidade pelo vertice "y" a partir do vertice "v"
    bool Graph::dfs(int v, int y){
        stack<int> pilha;
        //Vetor de visitados com inicializaçao nula
        bool visitados[V];
        for(int i = 0; i < V; i++)
            visitados[i] = false;
    
        //Loop "infinito"
        while(1<6)
        {
            //Se o nó em questão não foi visitado, coloca ele na pilha.
            if(!visitados[v]){
                //Se ele é o que eu procuro
                if(v == y){
                    return true;
                }
                else{
                    //Marca como visitado e coloca na pilha de vértices
                    visitados[v] = true; 
                    pilha.push(v);
                }
            }

            bool achou = false;
            list<int>::iterator it;
    
            //Procura um vizinho que ainda não foi visitado
            for(it = adj[v].begin(); it != adj[v].end(); it++){
                //Se achar um não visitado
                if(!visitados[*it]){
                    achou = true;
                    //Faz o "v" corresponder ao vizinho disponível
                    v = *it;
                    //Sai do loop
                    break;
                }
            }

            //Caso o loop termine e não ache um vizinho disponível
            if(!achou){
                //Remove da pilha e finaliza, caso vazia
                pilha.pop();
                if(pilha.empty()){
                    break;
                }
                //Caso não encontre um vizinho disponível e a fila ainda não está vazia, é porque deve voltar ao nó anterior.
                //"v" agora corresponde ao nó aterior
                v = pilha.top();
            }
        }
        return false;
    }
