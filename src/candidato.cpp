/*
 * Universidade de Brasília
 * Disciplina: Orientação a Objetos - 02/2018
 * Turma: B
 * Aluno: Bruno Alves Félix - 16/0114705
 *
 * Estudo Prático 01: URNA ELETRONICA
 */

#include "candidato.hpp"
#include <iostream>

Candidato::Candidato(){
	nome = "Nenhum";
	numero_do_candidato = "0";
	partido = "Nenhum";
}

Candidato::~Candidato(){}

string Candidato::get_nome(){
	return nome;
}
void Candidato::set_nome(string nome){
	this->nome = nome;
}

string Candidato::get_numero_do_candidato(){
	return numero_do_candidato;
}
void Candidato::set_numero_do_candidato(string numero_do_candidato){
	this->numero_do_candidato = numero_do_candidato;
}
string Candidato::get_partido(){
	return partido;
}
void Candidato::set_partido(string partido){
	this->partido = partido;
}	

void Candidato::imprime_dados(){
	cout << endl <<"	Nome: " << get_nome() << endl;
	cout << "	Numero_do_candidato: " << get_numero_do_candidato() << endl;
	cout << "	Partido: " << get_partido() << endl;
}
