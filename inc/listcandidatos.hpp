#ifndef LISTCANDIDATOS_HPP
#define LISTCANDIDATOS_HPP

#include "candidato.hpp"

using namespace std;

class Listcandidatos : public Candidato{
    
    protected:
    string nome_do_vice_candidato;
    string nome_pri_supsenador;
    string nome_seg_supsenador;

    public:
    //Métodos
    Listcandidatos();
    ~Listcandidatos();

    // Métodos de acesso aos atributos
    string get_nome_do_vice_candidato();
	void set_nome_do_vice_candidato(string nome_do_vice_candidato);
    string get_nome_pri_supsenador();
    void set_nome_pri_supsenador(string nome_pri_supsenador);
    string get_nome_seg_supsenador();
    void set_nome_seg_supsenador(string nome_seg_supsenador);

    void lista_presidentes();
    void lista_DF();
};
#endif