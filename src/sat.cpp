/*
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
*/