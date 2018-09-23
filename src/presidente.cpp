#include <iostream>
#include <fstream>
#include "presidente.hpp"

using namespace std;

Presidente::Presidente(){}

Presidente::~Presidente(){}

string Presidente::get_nome_do_vice_candidato(){
	return nome_do_vice_candidato;
}    
void Presidente::set_nome_do_vice_candidato(string nome_do_vice_candidato){
	this-> nome_do_vice_candidato = nome_do_vice_candidato;
}

void Presidente::lista_candidatos(){
    string vetor[27][58];
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
        
        if(numero == vetor[i][16] && vetor[i][13] == aux1){
            numero_do_candidato = vetor[i][16];
            nome_do_candidato = vetor[i][18];
            partido = vetor[i][28];
        }

        else if(numero == vetor[i][16] && vetor[i][13] == aux2){
            nome_do_vice_candidato = vetor[i][18];
        }
    }

    cout << "\n\n\tCANDIDATO À PRESIDENCIA: " << nome_do_candidato << ";" << endl << endl;
    cout << "\t"<<"VICE-PRESIDENCIA: " << nome_do_vice_candidato << ";" << endl;
    cout << "\tNUMERO DO PARTIDO: " << numero_do_candidato << ";" <<endl;
    cout << "\tNOME DO PARTIDO: " << partido << "." <<endl;
}