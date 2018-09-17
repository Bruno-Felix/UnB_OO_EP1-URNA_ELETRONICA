/*
 * Universidade de Brasília
 * Disciplina: Orientação a Objetos - 02/2018
 * Turma: B
 * Aluno: Bruno Alves Félix - 16/0114705
 *
 * Estudo Prático 01: URNA ELETRONICA
 */

#ifndef CANDIDATO_HPP
#define CANDIDATO_HPP
#include <string>
using namespace std;

class Candidato{
	
	private:
	string nome;
	string numero_do_candidato;
	string partido;
	public:
	
	//Métodos
	Candidato();//Método Construtor
	~Candidato();//Método Destrutor
	//Métodos Assesores
	string get_nome();
	void set_nome(string nome);

	string get_numero_do_candidato();
	void set_numero_do_candidato(string numero_do_candidato);

	string get_partido();
	void set_partido(string partido);

	virtual void imprime_dados();
};

#endif