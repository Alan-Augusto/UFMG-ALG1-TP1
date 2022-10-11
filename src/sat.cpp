#include <sat.hpp>


void satisfiabilityCheck(Follower followers[], int Numfollowers, int Numproposals){
    //Cria um grafo a partir do número de propostas
		//Multiplicado por 2 pos os valores negativos serão as negações
    bool satisfazivel = true;
	Graph grafo(Numproposals*2+1);

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
	int x = 0;
	for(int j = 1; j<Numproposals; j++){
		if(grafo.dfs(j, neg(j, Numproposals)) && grafo.dfs(neg(j, Numproposals), j)){
			x = j;
			satisfazivel = false;
			break;
		}
	}

	if(satisfazivel){
		cout << "satisfazível" << endl;
	}
	else{
		cout << "Não é satisfazível, pois existe caminho de " << x << " até " <<neg(x, Numproposals) << " e vice versa."<< endl;
	}

	/*
    grafo.addEdge(0, 1);
	grafo.addEdge(0, 2);
	grafo.addEdge(1, 3);
	grafo.addEdge(1, 4);
	grafo.addEdge(2, 5);
	grafo.addEdge(2, 6);
	grafo.addEdge(6, 7);
	
	grafo.dfs(0, 7);
    */
}