#include <iostream>
#include <fstream>
#include "presidente.hpp"

using namespace std;

Presidente::Presidente(){
    
    set_nome_do_candidato ("Nenhum");
    set_numero_do_candidato ("0");
    set_partido ("Nenhum");

    nome_do_vice_candidato = "Nenhum";
}

Presidente::~Presidente(){}
    string Presidente::get_nome_do_vice_candidato(){
	return nome_do_vice_candidato;
    }
    
    void Presidente::set_nome_do_vice_candidato(string nome_do_vice_candidato){
	this-> nome_do_vice_candidato = nome_do_vice_candidato;
    }

void Presidente::lista_candidatos(){
    string vetor[27][58];
    string presidencia[6];//[CNUM_PARTIDO, NOME_P, CARGO_P, NOME_VP, CARGO_VP]
    string aux1 = "1";
    string aux2 = "2";
    string numero;

    ifstream file("data/data_consulta_cand_2018_BR.csv");

	if(!file.is_open()) cout << "ERROR" << '\n';

    cout << endl << endl <<"---------------------------------------------------------" << endl;
	cout << endl <<"	INFORMAÇÕES DOS CANDIDATOS:" << endl;
		
	cout << endl <<"	Digite Número do Candidato para Busca: ";
	cin >> numero;

    for(int i=0; i<27; i++){
		for(int j=0; j<58; j++){
			if(j!=57){
				getline(file, vetor[i][j], ';');	
                vetor[i][j] = vetor[i][j].substr(1, vetor[i][j].size() - 2);
			}
			else{
				getline(file, vetor[i][j], '\n');
                vetor[i][j] = vetor[i][j].substr(1, vetor[i][j].size() - 2);
			}
        }
    }

    for(int i=0;i<27;i++){
    if(numero == vetor[i][16] && vetor[i][13] == aux1){
            presidencia[0] = vetor[i][16];
            presidencia[1] = vetor[i][18];
            presidencia[2] = vetor[i][14];
            presidencia[5] = vetor[i][28];

        }

        else if(numero == vetor[i][16] && vetor[i][13] == aux2){
            presidencia[3] = vetor[i][18];
            presidencia[4] = vetor[i][14];
        }
    }

    cout <<"\n\tCANDIDATO À PRESIDENCIA: " << presidencia[1] << ";" << endl << endl;

    cout << "\t"<<presidencia[4]<< ": " << presidencia[3] << ";" << endl;

    cout <<"\tNUMERO DO PARTIDO: "<< presidencia[0] << ";" <<endl;
    cout <<"\tNOME DO PARTIDO: "<< presidencia[5] << "." <<endl;
}