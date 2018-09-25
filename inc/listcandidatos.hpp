#ifndef LISTCANDIDATOS_HPP
#define LISTCANDIDATOS_HPP

#include "candidato.hpp"

using namespace std;

class Listcandidatos : public Candidato{
    
    protected:
    string nome_do_vice_candidato;

    public:
    //Métodos
    Listcandidatos();
    ~Listcandidatos();

    // Métodos de acesso aos atributos
    string get_nome_do_vice_candidato();
	void set_nome_do_vice_candidato(string nome_do_vice_candidato);

    void lista_candidatos();
    void informacao_candidato(int numero);
    void lista_presidentes();
    void lista_DF();
};
#endif