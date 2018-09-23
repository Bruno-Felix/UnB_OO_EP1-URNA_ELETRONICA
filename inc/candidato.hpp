#ifndef CANDIDATO_HPP
#define CANDIDATO_HPP

#include <string>

using namespace std;

class Candidato{
	
	protected:
	string nome_do_candidato;
	string numero_do_candidato;
	string partido;

	public:
	
	Candidato();
	~Candidato();

	string get_nome_do_candidato();
	void set_nome_do_candidato(string nome_do_candidato);
	string get_numero_do_candidato();
	void set_numero_do_candidato(string numero_do_candidato);
	string get_partido();
	void set_partido(string partido);
};
#endif