#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "votacao.hpp"
#include "listcandidatos.hpp"

using namespace std;

Votacao::Votacao(){}
Votacao::~Votacao(){}

string Votacao::get_nome_do_eleitor(){
    return nome_do_eleitor;
}
void Votacao::set_nome_do_eleitor(string nome_do_eleitor){
    this-> nome_do_eleitor = nome_do_eleitor;
}
int Votacao::get_numero_de_eleitores(){
    return numero_de_eleitores;
}
void Votacao::set_numero_de_eleitores(int numero_de_eleitores){
    this-> numero_de_eleitores = numero_de_eleitores;
}

int Votacao::num_de_eleitores(){
    int numero;
	system("clear");
	cout << endl << endl <<"---------------------------------------------------------" << endl;
	cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
	
	cout << "	Digite Número de Eleitores: ";
	//Inserindo Número de Eleitores
    while(!(cin>>numero)){

        system("clear");
        
        cout << endl << endl <<"---------------------------------------------------------" << endl;
	    cout << endl <<"\tVOTAÇÃO 2018" << endl << endl << endl;

        cin.clear();
        cin.ignore();

        cout << "\tValor inválido, Digite Novamente:\n";
    }

    return numero;
}

void Votacao::votacao(){
    
    string presidencia[27][58];
    string dfcands[1238][58];
    string numero_do_candidato;
    string dep_federal = "DEPUTADO FEDERAL";
    string dep_distrital = "DEPUTADO DISTRITAL";
    string sen = "SENADOR";
    string sen1 = "9";
    string sen2 = "10";
    string gov = "GOVERNADOR";
    string gov1 = "VICE-GOVERNADOR";
    string aux1 = "1";
    string aux2 = "2";
    int aux;

    //Inserindo Número de Eleitores
    numero_de_eleitores = num_de_eleitores();
    cout << numero_de_eleitores<< endl;
    string eleicao[100][6];

    //Leitura do arquivo BR
        ifstream file("data/data_consulta_cand_2018_BR.csv");//Arquivo BR - file
	    if(!file.is_open()) cout << "ERRO NA LEITURA DO ARQUIVO BR" << '\n';
       
        //Leitura dos arquivos DF
        ifstream ip("data/data_consulta_cand_2018_DF.csv");//Arquivo DF - ip
        if(!ip.is_open()) cout << "ERROR NA LEITURA DO ARQUIVO DF" << '\n';
    
        //Leitura do arquivo DF
        for(int k=0; k<1238; k++){
	        for(int j=0; j<58; j++){
	    	    if(j!=57){
	    		    getline(ip, dfcands[k][j], ';');	
                    dfcands[k][j] = dfcands[k][j].substr(1, dfcands[k][j].size() - 2);
	        	}

	        	else{
	    	    	getline(ip, dfcands[k][j], '\n');
                    dfcands[k][j] = dfcands[k][j].substr(1, dfcands[k][j].size() - 2);
    	    	}
            }
        }

        //Leitura do arquivo BR
        for(int k=0; k<27; k++){
		    for(int j=0; j<58; j++){
			    if(j!=57){
			    	getline(file, presidencia[k][j], ';');//Leitura de cada string, divididas pos "; no arquivo.csv
                  presidencia[k][j] = presidencia[k][j].substr(1, presidencia[k][j].size() - 2);//Retirando as aspas das strings
			    }
			    
                else{
				    getline(file, presidencia[k][j], '\n');//Leitura última string da linha, finalizada por "\n"
                    presidencia[k][j] = presidencia[k][j].substr(1, presidencia[k][j].size() - 2);//Retirando as aspas das strings
			    }
            }
        }

    for(int i=0; i<numero_de_eleitores; i++){

    	system("clear");

	    cout << endl << endl <<"---------------------------------------------------------" << endl;
	    cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
        
        //Leitura do Nome Completo
        cin.ignore();
        cin.clear();
        cout << "\tDigite seu Nome Completo: ";
        getline(cin, nome_do_eleitor);
        eleicao[i][0] = nome_do_eleitor;
        
        //Voto Deputado Distrital
        system("clear");
        cout << endl << endl <<"---------------------------------------------------------" << endl;
	    cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
        cout << "\tEleitor: " << eleicao[i][0];
        cout << endl << endl <<"---------------------------------------------------------" << endl << endl;
        cout << "\t\t   DEPUTADO DISTRITAL" << endl << endl;
        
        cout << endl <<"\tDigite Número do Candidato: ";
	    cin >> numero_do_candidato;
        
        for(int k=0; k<1238; k++){
	        for(int j=0; j<58; j++){
                if(numero_do_candidato == dfcands[k][16] && dfcands[k][14] == dep_distrital){
                    aux++;
                    eleicao[i][1] = dfcands[k][18];
                }
            }
        }

        //Voto Deputado Federal
        system("clear");
        cout << endl << endl <<"---------------------------------------------------------" << endl;
	    cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
        cout << "\tEleitor: " << eleicao[i][0];
        cout << endl << endl <<"---------------------------------------------------------" << endl << endl;
        cout << "\t\t   DEPUTADO FEDERAL" << endl << endl;
        
        cout << endl <<"\tDigite Número do Candidato: ";
	    cin >> numero_do_candidato;
        
        for(int k=0; k<1238; k++){
	        for(int j=0; j<58; j++){
                if(numero_do_candidato == dfcands[k][16] && dfcands[k][14] == dep_federal){
                    aux++;
                    eleicao[i][2] = dfcands[k][18];
                }
            }
        }

        //Voto Senador
        system("clear");
        cout << endl << endl <<"---------------------------------------------------------" << endl;
	    cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
        cout << "\tEleitor: " << eleicao[i][0];
        cout << endl << endl <<"---------------------------------------------------------" << endl << endl;
        cout << "\t\t   SENADOR" << endl << endl;

        cout << endl <<"\tDigite Número do Candidato: ";
	    cin >> numero_do_candidato;
        
        for(int k=0; k<1238; k++){
	        for(int j=0; j<58; j++){
                if(numero_do_candidato == dfcands[k][16] && dfcands[k][14] == sen){
                    aux++;
                    eleicao[i][3] = dfcands[k][18];
                }
            }
        }

        //Voto Governador
        system("clear");
        cout << endl << endl <<"---------------------------------------------------------" << endl;
	    cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
        cout << "\tEleitor: " << eleicao[i][0];
        cout << endl << endl <<"---------------------------------------------------------" << endl << endl;
        cout << "\t\t   GOVERNADOR" << endl << endl;
       
        cout << endl <<"\tDigite Número do Candidato: ";
	    cin >> numero_do_candidato;
        
        for(int k=0; k<1238; k++){
	        for(int j=0; j<58; j++){
                if(numero_do_candidato == dfcands[k][16] && dfcands[k][14] == gov){
                    aux++;
                    eleicao[i][4] = dfcands[k][18];
                }
            }
        }

        //Voto Presidente
        system("clear");
        cout << endl << endl <<"---------------------------------------------------------" << endl;
	    cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
        cout << "\tEleitor: " << eleicao[i][0];
        cout << endl << endl <<"---------------------------------------------------------" << endl << endl;
        cout << "\t\t   PRESIDENTE" << endl << endl;
       
        cout << endl <<"\tDigite Número do Candidato: ";
	    cin >> numero_do_candidato;

        for(int k=0; k<27; k++){
		    for(int j=0; j<58; j++){
                if(numero_do_candidato == presidencia[k][16] && presidencia[k][13] == aux1){
                    eleicao[i][5] = presidencia[k][18];
                }
            }
        }
    }
    
    //Teste
    cout << eleicao[0][0] << endl;
    cout << eleicao[0][1] << endl;
    cout << eleicao[0][2] << endl;
    cout << eleicao[0][3] << endl;
    cout << eleicao[0][4] << endl;
    cout << eleicao[0][5] << endl;
}