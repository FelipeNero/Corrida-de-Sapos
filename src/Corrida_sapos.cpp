#include "../include/Funções.hpp"
using namespace std;
	
	int main(){
		
		int qtdsapos; 
		int qtdpistas;
		int escolha;
		while(escolha != 0){
		cout << "O que deseja fazer?" << endl;
		cout << "0. Sair" << endl << "1. Ver estatísticas dos sapos" << endl << "2. Ver estatísticas das pistas" << endl << "3. Iniciar uma corrida" << endl << "4. Criar um sapo" << endl << "5. Criar uma pista" << endl;
		cin >> escolha; 
		switch(escolha){
			case 1:
			estatisticas_sapos();
			break;
			case 2:
			estatisticas_pistas();
			break;
			case 3:
			cout << "Quantos sapos participarão da corrida?" << endl;
			cin >> qtdsapos;
			iniciar_corrida(qtdsapos);
			break;
			case 4:
			cout << "Quantos sapos existem até agora?" << endl;
			cin >> qtdsapos;
			qtdsapos++;
			criar_sapo(qtdsapos);
			break;

			case 5:
			cout << "Quantas pistas existem até agora?" << endl;
			cin >> qtdpistas;
			qtdpistas++;
			criar_pista(qtdpistas);
			break;
		}
	}

		return 0;

	}
