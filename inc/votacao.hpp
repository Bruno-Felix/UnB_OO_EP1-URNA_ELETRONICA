#ifndef VOTACAO_HPP
#define VOTACAO_HPP

#include "candidato.hpp"

using namespace std;

class Votacao : public Candidato{

    protected:
    string nome_do_eleitor;
    int numero_de_eleitores;

    public:
    //Métodos
    Votacao();
    ~Votacao();

    string get_nome_do_eleitor();
    void set_nome_do_eleitor(string nome_do_eleitor);
    int get_numero_de_eleitores();
    void set_numero_de_eleitores(int numero_de_eleitores);

    int num_de_eleitores();
   
    void votacao();
};
#endif