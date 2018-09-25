#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "listcandidatos.hpp"

using namespace std;

Listcandidatos::Listcandidatos(){}

Listcandidatos::~Listcandidatos(){}

string Listcandidatos::get_nome_do_vice_candidato(){
	return nome_do_vice_candidato;
}    
void Listcandidatos::set_nome_do_vice_candidato(string nome_do_vice_candidato){
	this-> nome_do_vice_candidato = nome_do_vice_candidato;
}

//Informaçoes dos Candidatos à Presidencia
void Listcandidatos::lista_presidentes(){
    
    string presidencia[27][58];
    string aux1 = "1";
    string aux2 = "2";
    string numero_do_candidato; //Número do Candidato
    
    //Leitura dos dois arquivos
    ifstream file("data/data_consulta_cand_2018_BR.csv");//Arquivo BR - file
	if(!file.is_open()) cout << "ERRO NA LEITURA DO ARQUIVO BR" << '\n';

    //Inserção do número do candidato
    cout << endl << endl <<"---------------------------------------------------------" << endl;
	cout << endl <<"\tINFORMAÇÕES DOS CANDIDATOS" << endl << endl;
    cout << endl <<"\tPRESIDÊNCIA" << endl;
	cout << endl <<"\tDigite Número do Candidato para Busca: ";
	cin >> numero_do_candidato;

    //Leitura do arquivo BR
    for(int i=0; i<27; i++){
		for(int j=0; j<58; j++){
			if(j!=57){
				getline(file, presidencia[i][j], ';');//Leitura de cada string, divididas pos "; no arquivo.csv
                presidencia[i][j] = presidencia[i][j].substr(1, presidencia[i][j].size() - 2);//Retirando as aspas das strings

			}
			else{
				getline(file, presidencia[i][j], '\n');//Leitura última string da linha, finalizada por "\n"
                presidencia[i][j] = presidencia[i][j].substr(1, presidencia[i][j].size() - 2);//Retirando as aspas das strings
			}
        }
    }

    //Armazenamento dos dados BR
    // [i][28] = partido
    // [i][16] = numero do partido
    // [i][18] = nome
    // [i][14] = cargo
    for(int i=0; i<27; i++){
		for(int j=0; j<58; j++){
            if(numero_do_candidato == presidencia[i][16] && presidencia[i][13] == aux1){
                numero_do_candidato = presidencia[i][16];
                nome_do_candidato = presidencia[i][18];
                partido = presidencia[i][28];
            }
        
            else if(numero_do_candidato == presidencia[i][16] && presidencia[i][13] == aux2){
                nome_do_vice_candidato = presidencia[i][18];
            }
        }
    }

    //Impressão do dados BR
    system("clear");
    cout << endl << endl <<"---------------------------------------------------------" << endl;
    cout << "\n\t\tPRESIDENTE" << endl << endl;
    cout << "\n\tCANDIDATO: " << nome_do_candidato << ";" << endl << endl;
    cout << "\t"<<"VICE-PRESIDENCIA: " << nome_do_vice_candidato << ";" << endl;
    cout << "\tNUMERO DO PARTIDO: " << numero_do_candidato << ";" <<endl;
    cout << "\tNOME DO PARTIDO: " << partido << "." <<endl;
    cout <<"\n---------------------------------------------------------" << endl;
}

//Informaçoes dos Candidatos ao DF
void Listcandidatos::lista_DF(){
    
    //Variáveis
    string dfcands[1238][58];
    string deputado[3];
    string senador[5];
    string governador[4];
    string numero_do_candidato; //Número do Candidato
    string dep_federal = "DEPUTADO FEDERAL";
    string dep_distrital = "DEPUTADO DISTRITAL";
    string sen = "SENADOR";
    string sen1 = "9";
    string sen2 = "10";
    string gov = "GOVERNADOR";
    string gov1 = "VICE-GOVERNADOR";

    //Leitura dos dois arquivos
    ifstream ip("data/data_consulta_cand_2018_DF.csv");//Arquivo DF - ip
	if(!ip.is_open()) cout << "ERROR NA LEITURA DO ARQUIVO DF" << '\n';

    //Inserção do número do candidato
    cout << endl << endl <<"---------------------------------------------------------" << endl;
    cout << endl <<"\tINFORMAÇÕES DOS CANDIDATOS" << endl << endl;
    cout << endl <<"\tDEP. DISTRITAL, DEP. FEDERAL, SENADOR E GOVERNADOR" << endl;
	cout << endl <<"\tDigite Número do Candidato para Busca: ";
	cin >> numero_do_candidato;

    //Leitura do arquivo DF
    for(int i=0; i<1238; i++){
		for(int j=0; j<58; j++){
			if(j!=57){
				getline(ip, dfcands[i][j], ';');	
                dfcands[i][j] = dfcands[i][j].substr(1, dfcands[i][j].size() - 2);
			}

			else{
				getline(ip, dfcands[i][j], '\n');
                dfcands[i][j] = dfcands[i][j].substr(1, dfcands[i][j].size() - 2);
			}
        }
    }
    
    //Armazenamento dos dados DF
    // [i][28] = partido
    // [i][16] = numero do partido
    // [i][18] = nome
    // [i][14] = cargo
    // [i][13] = "códico" do cargo
    for(int i=0; i<1238; i++){
		for(int j=0; j<58; j++){
            //Deputados
            if(numero_do_candidato == dfcands[i][16] && dfcands[i][14] == dep_federal){
                deputado[0] = dfcands[i][18];
                deputado[1] = dfcands[i][16];
                deputado[2] = dfcands[i][28];
            }
            else if(numero_do_candidato == dfcands[i][16] && dfcands[i][14] == dep_distrital){
                deputado[0] = dfcands[i][18];
                deputado[1] = dfcands[i][16];
                deputado[2] = dfcands[i][28];
            }
            //Senador
            else if(numero_do_candidato == dfcands[i][16] && dfcands[i][14] == sen){
                senador[0] = dfcands[i][18];
                senador[1] = dfcands[i][16];
                senador[2] = dfcands[i][28];
            }
            else if(numero_do_candidato == dfcands[i][16] && dfcands[i][13] == sen1){
                senador[3] = dfcands[i][18];
            }
            else if(numero_do_candidato == dfcands[i][16] && dfcands[i][13] == sen2){
                senador[4] = dfcands[i][18];
            }
            //Governador
            else if(numero_do_candidato == dfcands[i][16] && dfcands[i][14] == gov){
                governador[0] = dfcands[i][18];
                governador[1] = dfcands[i][16];
                governador[2] = dfcands[i][28];
            }
            else if(numero_do_candidato == dfcands[i][16] && dfcands[i][14] == gov1){
                governador[3] = dfcands [i][18];
            }
        }
    }

    //Imprime dados DF
        for(int i=0; i<1238; i++){
            //Deputado Distrital
            if(numero_do_candidato == dfcands[i][16] && dfcands[i][14] == dep_federal){
                system("clear");
                cout << endl << endl <<"---------------------------------------------------------" << endl;
                cout << "\n\t\tDEPUTADO FEDERAL" << endl << endl;
                cout << "\n\tCANDIDATO: " << deputado[0] << ";" << endl << endl;
                cout << "\tNUMERO DO PARTIDO: " << deputado[1] << ";" <<endl;
                cout << "\tNOME DO PARTIDO: " << deputado[2] << "." <<endl<< endl;
                cout << "---------------------------------------------------------" << endl;
            }
            //Deputado Federal
            else if(numero_do_candidato == dfcands[i][16] && dfcands[i][14] == dep_distrital){
                system("clear");
                cout << endl << endl <<"---------------------------------------------------------" << endl;
                cout << "\n\t\tDEPUTADO DISTRITAL" << endl << endl;
                cout << "\n\tCANDIDATO: " << deputado[0] << ";" << endl << endl;
                cout << "\tNUMERO DO PARTIDO: " << deputado[1] << ";" <<endl;
                cout << "\tNOME DO PARTIDO: " << deputado[2] << "." <<endl<< endl;
                cout << "---------------------------------------------------------" << endl;
            }
            //Governador
            else if(numero_do_candidato == dfcands[i][16] && dfcands[i][14] == gov){
                system("clear");
                cout << endl << endl <<"---------------------------------------------------------" << endl;
                cout << "\n\t\tGOVERNADOR" << endl << endl;
                cout << "\n\tCANDIDATO: " << governador[0] << ";" << endl << endl;
                cout << "\tVICE-GOVERNADOR: " << governador[3] << ";" << endl;
                cout << "\tNUMERO DO PARTIDO: " << governador[1] << ";" << endl;
                cout << "\tNOME DO PARTIDO: " << governador[2] << "." << endl << endl;
                cout << "---------------------------------------------------------" << endl;
            }
            //Senador
            else if(numero_do_candidato == dfcands[i][16] && dfcands[i][14] == sen){
                system("clear");
                cout << endl << endl <<"---------------------------------------------------------" << endl;
                cout << "\n\t\tSENADOR" << endl << endl;
                cout << "\n\tCANDIDATO: " << senador[0] << ";" << endl << endl;
                cout << "\t1º SUPLENTE: " << senador[3] << ";" << endl;
                cout << "\t2º SUPLENTE: " << senador[4] << ";" << endl;
                cout << "\tNUMERO DO PARTIDO: " << senador[1] << ";" << endl;
                cout << "\tNOME DO PARTIDO: " << senador[2] << "." << endl << endl;
                cout << "---------------------------------------------------------" << endl;
            }
        }
}