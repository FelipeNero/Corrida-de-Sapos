#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
using namespace std;

		class Sapos{
		
		string nome;
		int identificador;
		int pulo;
		/*
		int pulos_dados;
		int vitorias;
		int empates;
		int provas_disputadas;
		*/
		public:
			string getnome();
			void setnome(string no);
			int getidentificador();
			void setidentificador(int id);
			int getpulo();
			void setpulo(int p);
			/*int getvitorias();
			int getpulos_dados();
			void setpulos_dados(int pd);
			void setvitorias(int v);
			int getempates();
			void setempates(int v);
			int getprovas_disputadas();
			void setprovas_disputadas(int v);
	*/
	};

	int Sapos::getidentificador(){
		return identificador;
	}

	void Sapos::setidentificador(int id){
		identificador = id;
	}
	
	string Sapos::getnome(){
		return nome;
	}
	void Sapos::setnome(string no){
		
		nome = no;
	}


	int Sapos::getpulo(){
		return pulo;
	}

	void Sapos::setpulo(int p){
		pulo = p;
	}
	
	class Pistas{
		string Nome;
		int tamanho;
		int identificador;
	public:
		int getidentificador();
		void setidentificador(int id);
		string getNome();
		void setNome(string n);
		int gettamanho();
		void settamanho(int t); 
	};

	void Pistas::setidentificador(int id){
		identificador = id;
	}
	int Pistas::getidentificador(){
		return identificador;
	}

	string Pistas::getNome(){
		return Nome;
	}

	void Pistas::setNome(string n){
		Nome = n;
	}
	int Pistas::gettamanho(){
		return tamanho;
	}
	void Pistas::settamanho(int t){
		tamanho = t;

	}
/*-------------------------------------------- FUNÇÃO PARA MOSTRAR ESTATÍSTICAS DOS SAPOS -----------------------------------------------*/	
	void estatisticas_sapos(){

		fstream arqSapo("../dats/Sapos.dat", ios::in | ios::out | ios::ate | ios::app | ios::binary);

		string linha;

		arqSapo.seekg(0);

		while(!arqSapo.eof()){

			getline(arqSapo, linha);

			cerr << linha << endl;

			}
			arqSapo.close();
	}
/*------------------------------------------- FUNÇÃO PARA MOSTRAR ESTATÍSTICAS DAS PISTAS ----------------------------------------------*/		
	void estatisticas_pistas(){
		fstream arqPista("../dats/Pistas.dat", ios::in | ios::out | ios::ate | ios::app |ios::binary);

		string linha;

		arqPista.seekg(0);

		while(!arqPista.eof()){

			getline(arqPista, linha);

			cerr << linha << endl;

			}
			arqPista.close();
	}
/*----------------------------------- FUNÇÃO PARA ARMAZENAR O ALCANCE DOS SAPOS ----------------------------------------*/		
	void armazena_sapos(int alcance_maximo){

		fstream arqAlcance("../dats/AlcanceSapos.dat", ios::in | ios::out | ios::ate | ios::app |ios::binary);	

		if (arqAlcance.is_open()){
		
		arqAlcance.tellp();

		arqAlcance << alcance_maximo << endl;

	}
		arqAlcance.close();
}
/*----------------------------------- FUNÇÃO PARA ARMAZENAR O TAMANHO DAS PISTAS ----------------------------------------*/		
	void armazena_pistas(int tamanho_pista){

		fstream arqTamanho("../dats/TamanhoPistas.dat", ios::in | ios::out | ios::ate | ios::app |ios::binary);	

		if (arqTamanho.is_open())
		{
			arqTamanho.tellp();

			arqTamanho << tamanho_pista << endl;
		}
		arqTamanho.close();		
	}

/*------------------------------------------- FUNÇÃO PARA O SAPO PULAR ---------------------------------------------*/		
	int pular(int sapo){

		ifstream arqAlcance("../dats/AlcanceSapos.dat", ios::in | ios::ate | ios::app |ios::binary);

		int alcance_maximo;

		Sapos s;
					
		arqAlcance.seekg(sapo*3);

		arqAlcance >> alcance_maximo;

		s.setpulo(1+(rand() % alcance_maximo));
		
		arqAlcance.close();
		
		return s.getpulo();
	
		}

/*------------------------------------------- FUNÇÃO PARA MOSTRAR ESTATÍSTICAS DA PISTA ---------------------------------------------*/		
	
	int escolher_pista(){

		fstream arqTamanho("../dats/TamanhoPistas.dat", ios::in | ios::out | ios::ate | ios::app |ios::binary);	
		
		int escolha;
		
		int tamanho_pista;
		
		estatisticas_pistas();

		cout << "Qual pista deseja utilizar?" << endl;
		
		cin >> escolha;
		
		arqTamanho.seekg((escolha - 1)*4);
		
		arqTamanho >> tamanho_pista;

		arqTamanho.close();
		
		return tamanho_pista;			
				
						
	}
		
/*-------------------------------------------------- FUNÇÃO PARA CRIAR UM SAPO --------------------------------------------------*/

	void criar_sapo(int qtdsapos){

		Sapos s;

		fstream arqSapo("../dats/Sapos.dat", ios::in | ios::out | ios::ate | ios::app |ios::binary);

		if (arqSapo.is_open())
			{

			string nomes;

			int alcance;

			cout << "Digite um nome: ";

			cin >> nomes;

			cout << "Digite um alcance [ideal entre 1 e 20]: ";

			cin >> alcance;

			arqSapo.tellp();

			arqSapo << "Sapo " << qtdsapos << endl;

			arqSapo << "Nome: " << nomes << endl;

			arqSapo << "Alcance de pulo: " << alcance << endl;	
			
			s.setidentificador(qtdsapos);

			s.setnome(nomes);

			s.setpulo(alcance);

			armazena_sapos(s.getpulo());	

			}				
		
		else 
			{

			cout << "Unable to open file";

			}
		arqSapo.close();
	}



	

/*-------------------------------------------------- FUNÇÃO PARA CRIAR UMA PISTA --------------------------------------------------*/

		void criar_pista(int qtdpistas){

			Pistas p;

			fstream arqPista("../dats/Pistas.dat", ios::in | ios::out | ios::ate | ios::app |ios::binary);

		if (arqPista.is_open()){

			string linha;

			string nomes;

			int tamanho;

			cout << "Digite um nome: ";

			cin >> nomes;

			cout << "Digite um tamanho[ideal entre 100 e 300]: ";

			cin >> tamanho;

			arqPista.tellp();

			arqPista << "Pista " << qtdpistas << endl;

			arqPista << "Nome: " << nomes << endl;

			arqPista << "Tamanho da pista: " << tamanho << endl;

			p.setidentificador(qtdpistas);

			p.setNome(nomes);

			p.settamanho(tamanho);
			
			armazena_pistas(p.gettamanho());
			
			}
		else {

			cout << "Unable to open file";

		}
		arqPista.close();
	}

/*-------------------------------------------------- FUNÇÃO PARA INICIAR UMA CORRIDA --------------------------------------------------*/

	void iniciar_corrida(int qtdsapos){
			
		estatisticas_sapos();
		
		int tamanho_da_pista = escolher_pista();

		int Posicao_sapos[qtdsapos];		
		
		for (int i = 0; i < qtdsapos; ++i)
		{
		
		Posicao_sapos[i] = 0;

		}
		
		int pulo;

		cout << "O tamanho da pista que você escolheu é: " << tamanho_da_pista << endl;
		
		for (int i = 0; i < tamanho_da_pista; ++i)
		{
			for (int j = 0; j < qtdsapos; ++j)
			{

			pulo = pular(j);

			Posicao_sapos[j] += pulo;
			
			cout << "O sapo " << j+1 << " deu um pulo de " << pulo << "m e está na posição " << Posicao_sapos[j] << endl; 
			
			if(Posicao_sapos[j] > tamanho_da_pista)
				{

				cout << "O sapo " << j+1 << " ganhou a corrida" << endl;
								
				return;

				}
			}

		}
					
	}

	