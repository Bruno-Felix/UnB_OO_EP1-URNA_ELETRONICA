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
#include "listcandidatos.hpp"

using namespace std;

void menu_options();
char escolha_menu();
void func_list();
void func_voto();
void sair_menu();
char resposta();
void saida();

int main (){

	char auxEscolha_Menu, auxResposta;
	
	//Menu
	while(auxEscolha_Menu != 's' && auxResposta != 's'){
		auxEscolha_Menu = 'i'; auxResposta = 'r';
		menu_options();
		auxEscolha_Menu = escolha_menu();

		if(auxEscolha_Menu == 'i'){
			while(auxResposta == 'r'){
				func_list();
				auxResposta = resposta();

				if(auxResposta =='i'){
					func_list();
					auxResposta = resposta();
				}

				if(auxResposta == 's'){
					saida();
				}
			}
		}

		else if(auxEscolha_Menu == 'v'){
			auxResposta = 'r';
			while(auxResposta == 'r'){
				func_voto();
				auxResposta = resposta();

				if(auxResposta == 's'){
					saida();
				}
			}
		}
	}
	
	if(auxEscolha_Menu == 's'){
		sair_menu();
	}

	return 0;
}

void menu_options(){

	system("clear");
	//Introdução
	cout << endl << "		      URNA ELETRONICA" << endl << endl;
	cout << "		Eleição Geral Federal 2018" << endl << "		   1º Turno - 07/10/2018" << endl;
	
	//Menu
	cout << endl << endl <<"---------------------------------------------------------" << endl;
	cout <<"		      MENU PRINCIPAL" << endl;
	cout <<"---------------------------------------------------------" << endl;

	cout << endl << "Digite \"I\" para Visualizar Informações dos Candidato" << endl;
	cout << "Digite \"V\" para Iniciar uma Votação" << endl;
	cout << "Digite \"S\" para Sair" << endl;
}

char escolha_menu(){
	
	char escolha_do_menu;

	//Escolhas, 1 para Informaçoes dos Candidatos e 2 para Votação 2018
	cout << endl <<"Escolha do Menu: ";
	cin >> escolha_do_menu;

	if (escolha_do_menu < 97) {
		// Transforma as letras maiúsculas da escolha_do_menu do usuario em minúsculas
		escolha_do_menu = escolha_do_menu + 32;
	}

	//Teste de exceção para a Escolha do Menu
	while(escolha_do_menu != 'i' && escolha_do_menu != 'v' && escolha_do_menu != 's'){
		cout << endl << "Por Favor, Escolha uma das Opções: \"I\", \"V\" ou \"S\". ";
		cout << endl <<"Escolha do Menu: ";
		cin >> escolha_do_menu;

		if (escolha_do_menu < 97) {
			// Transforma as letras maiúsculas da escolha_do_menu do usuario em minúsculas
			escolha_do_menu = escolha_do_menu + 32;
		}
	}
	return escolha_do_menu;
}

//Escolha 1, Informações dos Candidatos
void func_list(){

		Listcandidatos * listcandidatos1 = new Listcandidatos();

		system("clear");
		char escolha;

		cout << endl << endl <<"---------------------------------------------------------" << endl;
		cout << endl <<"\tINFORMAÇÕES DOS CANDIDATOS" << endl << endl;
		cout << "\n\tDigite \"P\" para Candidatos à Presidencia;"<< endl;
		cout << "\tDigite \"D\" para Candidatos os Demais." << endl;
		cout << "\tEscolha: ";
		cin >> escolha;
		cout << endl;

		if (escolha < 97) {
			// Transforma as letras maiúsculas da escolha_menu do usuario em minúsculas
			escolha = escolha + 32;
		}

		while(escolha != 'p' && escolha != 'd'){
			cout << "	Por Favor, Escolha uma das Opções: \"P\" ou \"D\"" << endl;
			cout << "\tEscolha: ";
			cin >> escolha;

			if(escolha < 97) {
				// Transforma as letras maiúsculas da escolha do usuario em minúsculas
				escolha = escolha + 32;
			}
		}

		if(escolha == 'p'){
			system("clear");
			listcandidatos1->lista_presidentes();
		}

		else if(escolha =='d'){
			system("clear");
			listcandidatos1->lista_DF();
		};
}

//Escolha 2, Votação 2018
void func_voto(){

	int numero_de_eleitores;

		system("clear");
		cout << endl << endl <<"---------------------------------------------------------" << endl;
		cout << endl <<"	VOTAÇÃO 2018:" << endl;
	
		cout << "	Digite Número de Eleitores: ";
		cin >> numero_de_eleitores;
}

//Escolha 3, Sair
void sair_menu(){
		saida();
}

char resposta(){

	char resposta;

	cout << "\nDigite \"R\" para refazer ação;" << endl;
	cout << "Digite \"M\" para voltar ao menu;"<< endl;
	cout << "Digite \"S\" para Sair." << endl;
	
	cout << "Escolha: ";
	
	cin >> resposta;

	if(resposta < 97){
		// Transforma as letras maiúsculas da resposta do usuario em minúsculas
		resposta = resposta + 32;
	}

	while(resposta != 'm' && resposta != 's' && resposta != 'r'){
		cout << endl << "Por Favor, Escolha uma das Opções: \"R\", \"M\" ou \"S\"" << endl;
		cout << "Escolha: ";
		cin >> resposta;

		if(resposta < 97){
			// Transforma as letras maiúsculas da resposta do usuario em minúsculas
			resposta = resposta + 32;
		}
	}
	return resposta;
  
}

void saida(){
	system("clear");
	cout << "\n\n\tInsira make run para reiniciar o programa, Obrigado!\n\n" << endl;
	exit(0);
}

void qual_candidato(){

}