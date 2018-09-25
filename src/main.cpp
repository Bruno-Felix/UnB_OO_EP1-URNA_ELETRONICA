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
#include <stdlib.h>
#include <string.h>
#include "candidato.hpp"
#include "presidente.hpp"

using namespace std;

void menu_options();
void escolha();
void resposta();
void saida();

int main (){
	//Menu
	menu_options();
	return 0;
}

void menu_options(){
	system("clear");
	//Introdução
	cout << endl << "		      URNA ELETRONICA" << endl << endl;
	cout << "		Eleição Geral Federal 2018" << endl << "		   1º Turno - 07/10/2018" << endl;
	
	//Menu
	cout << endl << endl <<"---------------------------------------------------------" << endl;
	cout <<"		      MENU PRINCIPAL:" << endl;
	cout <<"---------------------------------------------------------" << endl;

	cout << endl << "Digite \"I\" para Visualizar Informações dos Candidato" << endl;
	cout << "Digite \"V\" para Iniciar uma Votação" << endl;
	cout << "Digite \"S\" para Sair" << endl;

	escolha();
}

void escolha(){
	
	Presidente * presidente1 = new Presidente();
	int numero_de_eleitores;
	char escolha_menu;

	//Escolhas, 1 para Informaçoes dos Candidatos e 2 para Votação 2018
	cout << endl <<"Escolha do Menu: ";
	cin >> escolha_menu;

	if (escolha_menu < 97) {
		// Transforma as letras maiúsculas da escolha_menu do usuario em minúsculas
		escolha_menu = escolha_menu + 32;
	}

	//Teste de exceção para a Escolha do Menu
	while(escolha_menu != 'i' && escolha_menu != 'v' && escolha_menu != 's'){
		cout << endl << "Por Favor, Escolha uma das Opções: \"1\" ou \"2\". ";
		cout << endl <<"Escolha do Menu: ";
		cin >> escolha_menu;
	}

	//Escolha 1, Informações dos Candidatos
	if(escolha_menu == 'i'){
		system("clear");
		presidente1->lista_candidatos();
		resposta();
	}

	//Escolha 2, Votação 2018
	else if(escolha_menu == 'v'){
		system("clear");
		cout << endl << endl <<"---------------------------------------------------------" << endl;
		cout << endl <<"	VOTAÇÃO 2018:" << endl;
	
		cout << "	Digite Número de Eleitores: ";
		cin >> numero_de_eleitores;
	}
	//Escolha 3, Sair
	else if(escolha_menu == 's'){
		saida();
	}
}

void resposta(){
	char resposta;
	cout << "\n	Digite \"M\" para voltar ao menu"<< endl;
	cout << "	Digite \"S\" para Sair" << endl;
	cout << endl <<"	Escolha: ";
	
	cin >> resposta;

	if(resposta < 97) {
		// Transforma as letras maiúsculas da resposta do usuario em minúsculas
		resposta = resposta + 32;
	}

	while(resposta != 'm' && resposta != 's'){
		cout << endl << "	Por Favor, Escolha uma das Opções: \"M\" ou \"S\": ";
		cin >> resposta;
	}

	if(resposta == 'm'){
		menu_options();
	}

	else if(resposta == 's'){
		saida();
	}
  
}

void saida(){
	system("clear");
	cout << "\n\n		Insira make run para reiniciar o programa, Obrigado!\n\n" << endl;
	exit(0);
}