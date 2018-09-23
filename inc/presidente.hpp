#ifndef PRESINDETE_HPP
#define PRESIDENTE_HPP

#include "candidato.hpp"

using namespace std;

class Presidente : public Candidato{
    
    protected:
    string nome_do_vice_candidato;

    public:
    //Métodos
    Presidente();
    ~Presidente();

    // Métodos de acesso aos atributos
    string get_nome_do_vice_candidato();
	void set_nome_do_vice_candidato(string nome_do_vice_candidato);

    void lista_candidatos();
    void informacao_candidato(int numero);

};
#endif