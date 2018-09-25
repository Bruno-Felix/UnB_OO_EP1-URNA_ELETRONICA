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
    
    //Variáveis
    string dfcands[1238][58];
    string presidencia[27][58];
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
    string aux1 = "1";
    string aux2 = "2";
    int aux3;

    //Leitura dos dois arquivos
    ifstream file("data/data_consulta_cand_2018_BR.csv");//Arquivo BR - file
	if(!file.is_open()) cout << "ERRO NA LEITURA DO ARQUIVO BR" << '\n';
    ifstream ip("data/data_consulta_cand_2018_DF.csv");//Arquivo DF - ip
	if(!ip.is_open()) cout << "ERROR NA LEITURA DO ARQUIVO DF" << '\n';

    //Inserção do número do candidato
    aux3 = 0;
    cout << endl << endl <<"---------------------------------------------------------" << endl;
	cout << endl <<"	INFORMAÇÕES DOS CANDIDATOS:" << endl;
	cout << endl <<"	Digite Número do Candidato para Busca: ";
	cin >> numero_do_candidato;

    //Leitura dos arquivos
    //Leitura do arquivo BR
    for(int i=0; i<27; i++){
		for(int j=0; j<58; j++){
			if(j!=57){
				getline(file, presidencia[i][j], ';');	
                presidencia[i][j] = presidencia[i][j].substr(1, presidencia[i][j].size() - 2);//Retirando as aspas das strings

			}
			else{
				getline(file, presidencia[i][j], '\n');
                presidencia[i][j] = presidencia[i][j].substr(1, presidencia[i][j].size() - 2);//Retirando as aspas das strings
			}
        }
    }

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
    
    //Armazenamento dos dados:
    //[i][28] = partido
    //[i][16] = numero do partido
    //[i][18] = nome
    //[i][14] = cargo

    //Armazenamento dos dados BR
    for(int i=0; i<1238; i++){
		for(int j=0; j<58; j++){
            if(numero_do_candidato == presidencia[i][16] && presidencia[i][13] == aux1){
                numero_do_candidato = presidencia[i][16];
                nome_do_candidato = presidencia[i][18];
                partido = presidencia[i][28];
                aux3 = 1;
            }
        
            else if(numero_do_candidato == presidencia[i][16] && presidencia[i][13] == aux2){
                nome_do_vice_candidato = presidencia[i][18];
            }
        }
    }

    //Armazenamento dos dados DF
    for(int i=0; i<1238; i++){
		for(int j=0; j<58; j++){
            //Deputados
            if(numero_do_candidato == dfcands[i][16] && dfcands[i][14] == dep_federal){
                deputado[0] = dfcands[i][18];
                deputado[1] = dfcands[i][16];
                deputado[2] = dfcands[i][28];
                aux3 = 2;
            }
            else if(numero_do_candidato == dfcands[i][16] && dfcands[i][14] == dep_distrital){
                deputado[0] = dfcands[i][18];
                deputado[1] = dfcands[i][16];
                deputado[2] = dfcands[i][28];
                aux3 = 2;
            }
            //Senador
            else if(numero_do_candidato == dfcands[i][16] && dfcands[i][14] == sen){
                senador[0] = dfcands[i][18];
                senador[1] = dfcands[i][16];
                senador[2] = dfcands[i][28];
                aux3 = 2;
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
                aux3 = 2;
            }
            else if(numero_do_candidato == dfcands[i][16] && dfcands[i][14] == gov1){
                governador[3] = dfcands [i][18];
            }
        }
    }

    //Imprime dados BR
    if(aux3 == 1){
        cout << "\n\n\tCANDIDATO À PRESIDENCIA: " << nome_do_candidato << ";" << endl << endl;
        cout << "\t"<<"VICE-PRESIDENCIA: " << nome_do_vice_candidato << ";" << endl;
        cout << "\tNUMERO DO PARTIDO: " << numero_do_candidato << ";" <<endl;
        cout << "\tNOME DO PARTIDO: " << partido << "." <<endl;
    }

    //Imprime dados DF
    else if(aux3 == 2){
        for(int i=0; i<1238; i++){
            //Deputado Distrital
            if(numero_do_candidato == dfcands[i][16] && dfcands[i][14] == dep_federal){
                cout << "\n\n\tCANDIDATO: " << deputado[0] << ";" << endl << endl;
                cout << "\tNUMERO DO PARTIDO: " << deputado[1] << ";" <<endl;
                cout << "\tNOME DO PARTIDO: " << deputado[2] << "." <<endl<< endl;
            }
            //Deputado Federal
            else if(numero_do_candidato == dfcands[i][16] && dfcands[i][14] == dep_distrital){
                cout << "\n\n\tCANDIDATO: " << deputado[0] << ";" << endl << endl;
                cout << "\tNUMERO DO PARTIDO: " << deputado[1] << ";" <<endl;
                    cout << "\tNOME DO PARTIDO: " << deputado[2] << "." <<endl<< endl;
            }
            //Governador
            else if(numero_do_candidato == dfcands[i][16] && dfcands[i][14] == gov){
                cout << "\n\n\tCANDIDATO: " << governador[0] << ";" << endl << endl;
                cout << "\tVICE-GOVERNADOR: " << governador[3] << ";" << endl;
                cout << "\tNUMERO DO PARTIDO: " << governador[1] << ";" << endl;
                cout << "\tNOME DO PARTIDO: " << governador[2] << "." << endl << endl;
            }
            //Senador
            else if(numero_do_candidato == dfcands[i][16] && dfcands[i][14] == sen){
                cout << "\n\n\tCANDIDATO: " << senador[0] << ";" << endl << endl;
                cout << "\t1º SUPLENTE: " << senador[3] << ";" << endl;
                cout << "\t2º SUPLENTE: " << senador[4] << ";" << endl;
                cout << "\tNUMERO DO PARTIDO: " << senador[1] << ";" << endl;
                cout << "\tNOME DO PARTIDO: " << senador[2] << "." << endl << endl;
            }
        }
    }
}