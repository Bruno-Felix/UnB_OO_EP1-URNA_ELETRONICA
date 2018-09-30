#include "candidato.hpp"

Candidato::Candidato(){}

Candidato::~Candidato(){}

string Candidato::get_nome_do_candidato(){
	return nome_do_candidato;
}
void Candidato::set_nome_do_candidato(string nome_do_candidato){
	this-> nome_do_candidato = nome_do_candidato;
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
	this-> partido = partido;
}