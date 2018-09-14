/*
 * Universidade de Brasília
 * Disciplina: Orientação a Objetos - 02/2018
 * Turma: B
 * Aluno: Bruno Alves Félix - 16/0114705
 *
 * Estudo Prático 01: URNA ELETRONICA


    Eleição Geral Federal 2018
    1 Turno - 07/10/2018
*/

#include <iostream>


using namespace std;

int main (int argc, char ** argv){
	int escolha_menu, numero_candidato, numero_de_eleitores;
	//Introdução
	cout << endl << "		      URNA ELETRONICA" << endl << endl;
	cout << "		Eleição Geral Federal 2018" << endl << "		   1º Turno - 07/10/2018" << endl;
	
	//Menu
	while(1){
		cout << endl <<"MENU PRINCIPAL:" << endl;
		cout << endl << "Digite 1 para Visualizar Informações dos Candidato" << endl;
		cout << "Digite 2 para Iniciar uma Votação" << endl;
	
		cout << endl <<"Escolha do Menu: ";
		cin >> escolha_menu;
	
	//Escolhas, 1 para Informaçoes dos Candidatos e 2 para Votação 2018
		if(escolha_menu == 1){
			cout << endl << endl <<"	INFORMAÇÕES DOS CANDIDATOS:" << endl;
		
			cout <<"	Digite Número do Candidato para Busca: ";
			cin >> numero_candidato;
		}

		else if(escolha_menu == 2){
			cout << endl << endl <<"	VOTAÇÃO 2018:" << endl;
		
			cout << "Digite Número de Eleitores: ";
			cin >> numero_de_eleitores;

			for(int i=0; i<numero_de_eleitores; i++){
				cout << i << endl;
			}
		}
	}
}