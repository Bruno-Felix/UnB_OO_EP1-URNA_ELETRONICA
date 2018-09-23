/*
 * Universidade de Brasília
 * Disciplina: Orientação a Objetos - 02/2018
 * Turma: B
 * Aluno: Bruno Alves Félix - 16/0114705
 *
 * Estudo Prático 01: URNA ELETRONICA
 */

#include <iostream>
#include <stdio.h>
#include "candidato.hpp"
#include "presidente.hpp"

using namespace std;

int main (){

	Presidente * presidente1 = new Presidente();
	int escolha_menu, numero_de_eleitores;
	//Introdução
	cout << endl << "		      URNA ELETRONICA" << endl << endl;
	cout << "		Eleição Geral Federal 2018" << endl << "		   1º Turno - 07/10/2018" << endl;
	
	while(1){
	//Menu
		cout << endl << endl <<"---------------------------------------------------------" << endl;
		cout << endl <<"MENU PRINCIPAL:" << endl;
		cout << endl << "Digite 1 para Visualizar Informações dos Candidato" << endl;
		cout << "Digite 2 para Iniciar uma Votação" << endl;
	
		cout << endl <<"Escolha do Menu: ";
		cin >> escolha_menu;
	
	//Escolhas, 1 para Informaçoes dos Candidatos e 2 para Votação 2018
		//Escolha 1, Informações dos Candidatos
		if(escolha_menu == 1){
			presidente1->lista_candidatos();
		}

		//Escolha 2, Votação 2018
		else if(escolha_menu == 2){
			cout << endl << endl <<"---------------------------------------------------------" << endl;
			cout << endl <<"	VOTAÇÃO 2018:" << endl;
		
			cout << "	Digite Número de Eleitores: ";
			cin >> numero_de_eleitores;
		}
	}
	return 0;
}