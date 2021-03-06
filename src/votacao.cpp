#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "votacao.hpp"
#include "listcandidatos.hpp"

using namespace std;

Votacao::Votacao(){}
Votacao::~Votacao(){}

string Votacao::get_nome_pri_supsenador(){
    return nome_pri_supsenador;
}
void Votacao::set_nome_pri_supsenador(string nome_pri_supsenador){
    this -> nome_pri_supsenador = nome_pri_supsenador;
}
string Votacao::get_nome_seg_supsenador(){
    return nome_seg_supsenador;
}
void Votacao::set_nome_seg_supsenador(string nome_seg_supsenador){
    this -> nome_seg_supsenador = nome_seg_supsenador;
}
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
    string vice_gov = "VICE-GOVERNADOR";
    string aux1 = "1";
    string aux2 = "2";
    string nulo = "NULO";
    string branco = "BRANCO";
    int aux;
    int verdade;
    char resposta;
    
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
        resposta = 'r';
	    cout << endl << endl <<"---------------------------------------------------------" << endl;
	    cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
        
        //Leitura do Nome Completo
        cin.ignore();
        cin.clear();
        cout << "\tEleitor " << i+1 << ", Digite seu Nome Completo: ";
        getline(cin, nome_do_eleitor);
        eleicao[i][0] = nome_do_eleitor;

        while(resposta != 's' && resposta != 'c'){

        //Voto Deputado Distrital
        system("clear");
        verdade = 0;
        aux = 0;
        cout << endl << endl <<"---------------------------------------------------------" << endl;
	    cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
        cout << "\tEleitor: " << eleicao[i][0];
        cout << endl << endl <<"---------------------------------------------------------" << endl << endl;
        cout << "\t\tVOTO PARA DEPUTADO DISTRITAL" << endl << endl;
        
        cout << "\tDigite \"0\" para Voto NULO;" << endl;
        cout << "\tDigite \"1\" para Voto BRANCO;" << endl;
        cout << endl <<"\tDigite Número Válido do Candidato: ";
	    cin >> numero_do_candidato;

            // Voto = 0 é voto nulo
            if(numero_do_candidato == "0"){
                eleicao[i][1] = nulo;
            }

            // Voto = 1 é voto Branco
            else if(numero_do_candidato == "1"){
                eleicao[i][1] = branco;
            }

            else{
                for(int k=0; k<1238; k++){
	                for(int j=0; j<58; j++){
                        if(numero_do_candidato == dfcands[k][16] && dfcands[k][14] == dep_distrital){
                            verdade++;
                            eleicao[i][1] = dfcands[k][18];
                            nome_do_candidato = dfcands[k][18];
                            numero_do_candidato = dfcands[k][16];
                            partido = dfcands[k][28];
                        }
                    }
                    aux++;
                }
            }

        if(verdade>0){
            //Confirmação do Voto
            system("clear");
            cout << endl << endl <<"---------------------------------------------------------" << endl;
	        cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
            cout << "\tEleitor: " << eleicao[i][0];
            cout << endl << endl <<"---------------------------------------------------------" << endl << endl;
        
            cout << "\t\tSEU VOTO PARA DEPUTADO DISTRITAL" << endl << endl;
            cout << "\n\tCANDIDATO: " << nome_do_candidato << ";" << endl << endl;
            cout << "\tNUMERO DO PARTIDO: " << numero_do_candidato << ";" <<endl;
            cout << "\tNOME DO PARTIDO: " << partido << "." << endl<< endl;
            cout << endl <<"---------------------------------------------------------" << endl << endl;
                          
            cout << "\nDigite \"R\" para Corrigir;" << endl;
            cout << "Digite \"S\" para Cancelar;" << endl << endl;
            cout << "Digite \"C\" para Confirmar." << endl << endl;  
            cout << "Escolha: ";
	        cin >> resposta;
               
	        if(resposta < 97){
		        // Transforma as letras maiúsculas da resposta do usuario em minúsculas
		        resposta = resposta + 32;
	        }

	        while(resposta != 'c' && resposta != 's' && resposta != 'r'){
		        cout << endl << "Por Favor, Escolha uma das Opções: \"R\", \"C\" ou \"S\"" << endl;
		        cout << "Escolha: ";
		        cin >> resposta;

		        if(resposta < 97){
			        // Transforma as letras maiúsculas da resposta do usuario em minúsculas
			        resposta = resposta + 32;
		        }
	        }  
        }   

        else if(verdade == 0){
            system("clear");
            cout << endl << endl <<"---------------------------------------------------------" << endl;
	        cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
            cout << "\tEleitor: " << eleicao[i][0];
            cout << endl << endl <<"---------------------------------------------------------" << endl << endl;
        
            cout << "\t\tSEU VOTO PARA DEPUTADO DISTRITAL" << endl << endl;
            cout << "\n\tVOTO " << eleicao[i][1] << "." << endl << endl;
            cout << endl <<"---------------------------------------------------------" << endl << endl;

            cout << "\nDigite \"R\" para Corrigir;" << endl;
            cout << "Digite \"S\" para Cancelar;" << endl << endl;
            cout << "Digite \"C\" para Confirmar." << endl << endl;  
            cout << "Escolha: ";
            cin >> resposta;

	        if(resposta < 97){
		        // Transforma as letras maiúsculas da resposta do usuario em minúsculas
		        resposta = resposta + 32;
	        }

	        while(resposta != 'c' && resposta != 's' && resposta != 'r'){
		        cout << endl << "Por Favor, Escolha uma das Opções: \"R\", \"C\" ou \"S\"" << endl;
		        cout << "Escolha: ";
		        cin >> resposta;

		        if(resposta < 97){
			        // Transforma as letras maiúsculas da resposta do usuario em minúsculas
			        resposta = resposta + 32;
		        }
	        }
        }
    }
    
    if(resposta == 's'){
		system("clear");
	    cout << "\n\n\tVOTAÇÃO CANCELADA." << endl;
        resposta = 'r';
        break;
	}
    
    resposta = 'r';
    while(resposta != 's' && resposta != 'c'){
            
        //Voto Deputado Federal
        system("clear");
        verdade = 0;
        aux = 0;
        cout << endl << endl <<"---------------------------------------------------------" << endl;
        cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
        cout << "\tEleitor: " << eleicao[i][0];
        cout << endl << endl <<"---------------------------------------------------------" << endl << endl;
        cout << "\t\tVOTO PARA DEPUTADO FEDERAL" << endl << endl;
        
        cout << "\tDigite \"0\" para Voto NULO;" << endl;
        cout << "\tDigite \"1\" para Voto BRANCO;" << endl;
        cout << endl <<"\tDigite Número Válido do Candidato: ";
        cin >> numero_do_candidato;
    
        // Voto = 0 é voto nulo
        if(numero_do_candidato == "0"){
            eleicao[i][2] = nulo;;
        }

        // Voto = 1 é voto Branco
        else if(numero_do_candidato == "1"){
            eleicao[i][2] = branco;
        }

        else{
            for(int k=0; k<1238; k++){
                for(int j=0; j<58; j++){
                    if(numero_do_candidato == dfcands[k][16] && dfcands[k][14] == dep_federal){
                        verdade++;
                        eleicao[i][2] = dfcands[k][18];

                        nome_do_candidato = dfcands[k][18];
                        numero_do_candidato = dfcands[k][16];
                        partido = dfcands[k][28];
                    }
                }
                aux++;
            }
        }

        if(verdade>0){
            
            //Confirmação do Voto
            system("clear");
            cout << endl << endl <<"---------------------------------------------------------" << endl;
            cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
            cout << "\tEleitor: " << eleicao[i][0];
            cout << endl << endl <<"---------------------------------------------------------" << endl << endl;
        
            cout << "\t\tSEU VOTO PARA DEPUTADO FEDERAL" << endl << endl;
            cout << "\n\tCANDIDATO: " << nome_do_candidato << ";" << endl << endl;
            cout << "\tNUMERO DO PARTIDO: " << numero_do_candidato << ";" <<endl;
            cout << "\tNOME DO PARTIDO: " << partido << "." << endl<< endl;
            cout << endl <<"---------------------------------------------------------" << endl << endl; 

            cout << "\nDigite \"R\" para Corrigir;" << endl;
            cout << "Digite \"S\" para Cancelar;" << endl << endl;
            cout << "Digite \"C\" para Confirmar." << endl << endl;  
            cout << "Escolha: ";
            cin >> resposta;
            
            if(resposta < 97){
                // Transforma as letras maiúsculas da resposta do usuario em minúsculas
                resposta = resposta + 32;
            }

            while(resposta != 'c' && resposta != 's' && resposta != 'r'){
                cout << endl << "Por Favor, Escolha uma das Opções: \"R\", \"C\" ou \"S\"" << endl;
                cout << "Escolha: ";
                cin >> resposta;

                if(resposta < 97){
                    // Transforma as letras maiúsculas da resposta do usuario em minúsculas
                    resposta = resposta + 32;
                }
            }  
        }   

        else if(verdade == 0){
            system("clear");
            cout << endl << endl <<"---------------------------------------------------------" << endl;
	        cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
            cout << "\tEleitor: " << eleicao[i][0];
            cout << endl << endl <<"---------------------------------------------------------" << endl << endl;
        
            cout << "\t\tSEU VOTO PARA DEPUTADO FEDERAL" << endl << endl;
            cout << "\n\tVOTO " << eleicao[i][2] << "." << endl << endl;
            cout << endl <<"---------------------------------------------------------" << endl << endl;

            cout << "\nDigite \"R\" para Corrigir;" << endl;
            cout << "Digite \"S\" para Cancelar;" << endl << endl;
            cout << "Digite \"C\" para Confirmar." << endl << endl;  
            cout << "Escolha: ";
            cin >> resposta;

	        if(resposta < 97){
		        // Transforma as letras maiúsculas da resposta do usuario em minúsculas
		        resposta = resposta + 32;
	        }

	        while(resposta != 'c' && resposta != 's' && resposta != 'r'){
		        cout << endl << "Por Favor, Escolha uma das Opções: \"R\", \"C\" ou \"S\"" << endl;
		        cout << "Escolha: ";
		        cin >> resposta;

		        if(resposta < 97){
			        // Transforma as letras maiúsculas da resposta do usuario em minúsculas
			        resposta = resposta + 32;
		        }
	        }
        }
    }
    
    if(resposta == 's'){
		system("clear");
	    cout << "\n\n\tVOTAÇÃO CANCELADA." << endl;
        resposta = 'r';
        break;
	}
    
    resposta = 'r';
    while(resposta != 's' && resposta != 'c'){
        
        //Voto Senador - 1ª Vaga
        system("clear");
        verdade = 0;
        aux = 0;
        string numero_do_candidato = "0";
        cout << endl << endl <<"---------------------------------------------------------" << endl;
	    cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
        cout << "\tEleitor: " << eleicao[i][0];
        cout << endl << endl <<"---------------------------------------------------------" << endl << endl;
        cout << "\t\tVOTO PARA SENADOR - 1ª VAGA:" << endl << endl;

        cout << "\tDigite \"0\" para Voto NULO;" << endl;
        cout << "\tDigite \"1\" para Voto BRANCO;" << endl;
        cout << endl <<"\tDigite Número Válido do Candidato: ";
	    cin >> numero_do_candidato;
        cout <<" Numero:" << numero_do_candidato << endl;
        
        // Voto = 0 é voto nulo
        if(numero_do_candidato == "0"){
            eleicao[i][3] = nulo;
        }

        // Voto = 1 é voto Branco
        else if(numero_do_candidato == "1"){
            eleicao[i][3] = branco;
        }

        else{
            for(int k=0; k<1238; k++){
                for(int j=0; j<58; j++){
                    if(numero_do_candidato == dfcands[k][16] && dfcands[k][14] == sen){
                        verdade++;
                        eleicao[i][3] = dfcands[k][18];

                        nome_do_candidato = dfcands[k][18];
                        numero_do_candidato = dfcands[k][16];
                        partido = dfcands[k][28];
                    }
        
                    else if(numero_do_candidato == dfcands[k][16] && dfcands[k][13] == sen1){
                        nome_pri_supsenador = dfcands[k][18];
                    }
        
                    else if(numero_do_candidato == dfcands[k][16] && dfcands[k][13] == sen2){
                        nome_seg_supsenador = dfcands[k][18];
                    }
                }
                aux++;
            }
        }

        if(verdade>0){
            system("clear");
            //Confirmação do Voto
            cout << endl << endl <<"---------------------------------------------------------" << endl;
            cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
            cout << "\tEleitor: " << eleicao[i][0];
            cout << endl << endl <<"---------------------------------------------------------" << endl << endl;
        
            cout << "\t\tSEU VOTO PARA SENADOR - 1ª VAGA" << endl << endl;
            cout << "\n\tCANDIDATO: " << nome_do_candidato << ";" << endl << endl;
            cout << "\t1º SUPLENTE: " << nome_pri_supsenador << ";" << endl;
            cout << "\t2º SUPLENTE: " << nome_seg_supsenador << ";" << endl;
            cout << "\tNUMERO DO PARTIDO: " << numero_do_candidato << ";" << endl;
            cout << "\tNOME DO PARTIDO: " << partido << "." << endl << endl;
            cout << endl <<"---------------------------------------------------------" << endl << endl;

            cout << "\nDigite \"R\" para Corrigir;" << endl;
            cout << "Digite \"S\" para Cancelar;" << endl << endl;
            cout << "Digite \"C\" para Confirmar." << endl << endl;  
            cout << "Escolha: ";
            cin >> resposta;
            
            if(resposta < 97){
                // Transforma as letras maiúsculas da resposta do usuario em minúsculas
                resposta = resposta + 32;
            }

            while(resposta != 'c' && resposta != 's' && resposta != 'r'){
                cout << endl << "Por Favor, Escolha uma das Opções: \"R\", \"C\" ou \"S\"" << endl;
                cout << "Escolha: ";
                cin >> resposta;

                if(resposta < 97){
                    // Transforma as letras maiúsculas da resposta do usuario em minúsculas
                    resposta = resposta + 32;
                }
            }  
        }   

        else if(verdade == 0){
            system("clear");
            cout << endl << endl <<"---------------------------------------------------------" << endl;
	        cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
            cout << "\tEleitor: " << eleicao[i][0];
            cout << endl << endl <<"---------------------------------------------------------" << endl << endl;
        
            cout << "\t\tSEU VOTO PARA SENADOR - 1ª VAGA" << endl << endl;
            cout << "\n\tVOTO " << eleicao[i][3] << "." << endl << endl;
            cout << endl <<"---------------------------------------------------------" << endl << endl;

            cout << "\nDigite \"R\" para Corrigir;" << endl;
            cout << "Digite \"S\" para Cancelar;" << endl << endl;
            cout << "Digite \"C\" para Confirmar." << endl << endl;  
            cout << "Escolha: ";
            cin >> resposta;

	        if(resposta < 97){
		        // Transforma as letras maiúsculas da resposta do usuario em minúsculas
		        resposta = resposta + 32;
	        }

	        while(resposta != 'c' && resposta != 's' && resposta != 'r'){
		        cout << endl << "Por Favor, Escolha uma das Opções: \"R\", \"C\" ou \"S\"" << endl;
		        cout << "Escolha: ";
		        cin >> resposta;

		        if(resposta < 97){
			        // Transforma as letras maiúsculas da resposta do usuario em minúsculas
			        resposta = resposta + 32;
		        }
	        }
        }
    }

    if(resposta == 's'){
		system("clear");
	    cout << "\n\n\tVOTAÇÃO CANCELADA." << endl;
        resposta = 'r';
        break;
	}

    resposta = 'r';
    while(resposta != 's' && resposta != 'c'){

        //Voto Senador - 2ª Vaga
        system("clear");
        verdade = 0;
        aux = 0;
        cout << endl << endl <<"---------------------------------------------------------" << endl;
	    cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
        cout << "\tEleitor: " << eleicao[i][0];
        cout << endl << endl <<"---------------------------------------------------------" << endl << endl;
        cout << "\t\tVOTO PARA SENADOR - 2ª VAGA:" << endl << endl;

        cout << "\tDigite \"0\" para Voto NULO;" << endl;
        cout << "\tDigite \"1\" para Voto BRANCO;" << endl;
        cout << endl <<"\tDigite Número Válido do Candidato: ";
	    cin >> numero_do_candidato;
        
        // Voto = 0 é voto nulo
        if(numero_do_candidato == "0"){
            eleicao[i][4] = nulo;
        }

        // Voto = 1 é voto Branco
        else if(numero_do_candidato == "1"){
            eleicao[i][4] = branco;
        }

        else{
            for(int k=0; k<1238; k++){
                for(int j=0; j<58; j++){
                    if(numero_do_candidato == dfcands[k][16] && dfcands[k][14] == sen){
                        verdade++;
                        eleicao[i][4] = dfcands[k][18];
                        nome_do_candidato = dfcands[k][18];
                        numero_do_candidato = dfcands[k][16];
                        partido = dfcands[k][28];
                    }
        
                    else if(numero_do_candidato == dfcands[k][16] && dfcands[k][13] == sen1){
                        nome_pri_supsenador = dfcands[k][18];
                    }
        
                    else if(numero_do_candidato == dfcands[k][16] && dfcands[k][13] == sen2){
                        nome_seg_supsenador = dfcands[k][18];
                    }
                }
                aux++;
            }
        }

        if(verdade>0){
            
            //Confirmação do Voto
            system("clear");
            cout << endl << endl <<"---------------------------------------------------------" << endl;
            cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
            cout << "\tEleitor: " << eleicao[i][0];
            cout << endl << endl <<"---------------------------------------------------------" << endl << endl;
        
            cout << "\t\tSEU VOTO PARA SENADOR - 2ª VAGA" << endl << endl;
            cout << "\n\tCANDIDATO: " << nome_do_candidato << ";" << endl << endl;
            cout << "\t1º SUPLENTE: " << nome_pri_supsenador << ";" << endl;
            cout << "\t2º SUPLENTE: " << nome_seg_supsenador << ";" << endl;
            cout << "\tNUMERO DO PARTIDO: " << numero_do_candidato << ";" << endl;
            cout << "\tNOME DO PARTIDO: " << partido << "." << endl << endl;
            cout << endl <<"---------------------------------------------------------" << endl << endl;

            cout << "\nDigite \"R\" para Corrigir;" << endl;
            cout << "Digite \"S\" para Cancelar;" << endl << endl;
            cout << "Digite \"C\" para Confirmar." << endl << endl;  
            cout << "Escolha: ";
            cin >> resposta;
            
            if(resposta < 97){
                // Transforma as letras maiúsculas da resposta do usuario em minúsculas
                resposta = resposta + 32;
            }

            while(resposta != 'c' && resposta != 's' && resposta != 'r'){
                cout << endl << "Por Favor, Escolha uma das Opções: \"R\", \"C\" ou \"S\"" << endl;
                cout << "Escolha: ";
                cin >> resposta;

                if(resposta < 97){
                    // Transforma as letras maiúsculas da resposta do usuario em minúsculas
                    resposta = resposta + 32;
                }
            }  
        }   

        else if(verdade == 0){
            system("clear");
            cout << endl << endl <<"---------------------------------------------------------" << endl;
	        cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
            cout << "\tEleitor: " << eleicao[i][0];
            cout << endl << endl <<"---------------------------------------------------------" << endl << endl;
        
            cout << "\t\tSEU VOTO PARA SENADOR - 2ª VAGA" << endl << endl;
            cout << "\n\tVOTO " << eleicao[i][4] << "." << endl << endl;
            cout << endl <<"---------------------------------------------------------" << endl << endl;

            cout << "\nDigite \"R\" para Corrigir;" << endl;
            cout << "Digite \"S\" para Cancelar;" << endl << endl;
            cout << "Digite \"C\" para Confirmar." << endl << endl;  
            cout << "Escolha: ";
            cin >> resposta;

	        if(resposta < 97){
		        // Transforma as letras maiúsculas da resposta do usuario em minúsculas
		        resposta = resposta + 32;
	        }

	        while(resposta != 'c' && resposta != 's' && resposta != 'r'){
		        cout << endl << "Por Favor, Escolha uma das Opções: \"R\", \"C\" ou \"S\"" << endl;
		        cout << "Escolha: ";
		        cin >> resposta;

		        if(resposta < 97){
			        // Transforma as letras maiúsculas da resposta do usuario em minúsculas
			        resposta = resposta + 32;
		        }
	        }
        }
    }

    if(resposta == 's'){
		system("clear");
	    cout << "\n\n\tVOTAÇÃO CANCELADA." << endl;
        resposta = 'r';
        break;
	}

    resposta = 'r';
    while(resposta != 's' && resposta != 'c'){

        //Voto Governador
        system("clear");
        verdade = 0;
        aux = 0;
        cout << endl << endl <<"---------------------------------------------------------" << endl;
	    cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
        cout << "\tEleitor: " << eleicao[i][0];
        cout << endl << endl <<"---------------------------------------------------------" << endl << endl;
        cout << "\t\tVOTO PARA GOVERNADOR" << endl << endl;
       
        cout << "\tDigite \"0\" para Voto NULO;" << endl;
        cout << "\tDigite \"1\" para Voto BRANCO;" << endl;
        cout << endl <<"\tDigite Número Válido do Candidato: ";
	    cin >> numero_do_candidato;
        
        // Voto = 0 é voto nulo
        if(numero_do_candidato == "0"){
            eleicao[i][5] = nulo;
        }

        // Voto = 1 é voto Branco
        else if(numero_do_candidato == "1"){
            eleicao[i][5] = branco;
        }

        else{
            for(int k=0; k<1238; k++){
	            for(int j=0; j<58; j++){
                    if(numero_do_candidato == dfcands[k][16] && dfcands[k][14] == gov){
                        verdade++;
                        eleicao[i][5] = dfcands[k][18];
                        
                        nome_do_candidato = dfcands[k][18];
                        numero_do_candidato = dfcands[k][16];
                        partido = dfcands[k][28];
                    }
                    else if(numero_do_candidato == dfcands[k][16] && dfcands[k][14] == vice_gov){
                        nome_do_vice_candidato = dfcands [k][18];
                    }
                }
                aux++;
            }
        }

        if(verdade>0){
            
            //Confirmação do Voto
            system("clear");
            cout << endl << endl <<"---------------------------------------------------------" << endl;
            cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
            cout << "\tEleitor: " << eleicao[i][0];
            cout << endl << endl <<"---------------------------------------------------------" << endl << endl;
        
            cout << "\t\tSEU VOTO PARA GOVERNADOR" << endl << endl;
            cout << "\n\tCANDIDATO: " << nome_do_candidato << ";" << endl << endl;
            cout << "\tVICE-GOVERNADOR: " << nome_do_vice_candidato << ";" << endl;
            cout << "\tNUMERO DO PARTIDO: " << numero_do_candidato << ";" << endl;
            cout << "\tNOME DO PARTIDO: " << partido << "." << endl << endl;
            cout << endl <<"---------------------------------------------------------" << endl << endl;

            cout << "\nDigite \"R\" para Corrigir;" << endl;
            cout << "Digite \"S\" para Cancelar;" << endl << endl;
            cout << "Digite \"C\" para Confirmar." << endl << endl;  
            cout << "Escolha: ";
            cin >> resposta;
            
            if(resposta < 97){
                // Transforma as letras maiúsculas da resposta do usuario em minúsculas
                resposta = resposta + 32;
            }

            while(resposta != 'c' && resposta != 's' && resposta != 'r'){
                cout << endl << "Por Favor, Escolha uma das Opções: \"R\", \"C\" ou \"S\"" << endl;
                cout << "Escolha: ";
                cin >> resposta;

                if(resposta < 97){
                    // Transforma as letras maiúsculas da resposta do usuario em minúsculas
                    resposta = resposta + 32;
                }
            }  
        }   

        else if(verdade == 0){
            system("clear");
            cout << endl << endl <<"---------------------------------------------------------" << endl;
	        cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
            cout << "\tEleitor: " << eleicao[i][0];
            cout << endl << endl <<"---------------------------------------------------------" << endl << endl;
        
            cout << "\t\tSEU VOTO PARA GOVERNADOR" << endl << endl;
            cout << "\n\tVOTO " << eleicao[i][5] << "." << endl << endl;
            cout << endl <<"---------------------------------------------------------" << endl << endl;

            cout << "\nDigite \"R\" para Corrigir;" << endl;
            cout << "Digite \"S\" para Cancelar;" << endl << endl;
            cout << "Digite \"C\" para Confirmar." << endl << endl;  
            cout << "Escolha: ";
            cin >> resposta;

	        if(resposta < 97){
		        // Transforma as letras maiúsculas da resposta do usuario em minúsculas
		        resposta = resposta + 32;
	        }

	        while(resposta != 'c' && resposta != 's' && resposta != 'r'){
		        cout << endl << "Por Favor, Escolha uma das Opções: \"R\", \"C\" ou \"S\"" << endl;
		        cout << "Escolha: ";
		        cin >> resposta;

		        if(resposta < 97){
			        // Transforma as letras maiúsculas da resposta do usuario em minúsculas
			        resposta = resposta + 32;
		        }
	        }
        }
    }

    if(resposta == 's'){
		system("clear");
	    cout << "\n\n\tVOTAÇÃO CANCELADA." << endl;
        resposta = 'r';
        break;
	}

    resposta = 'r';
    while(resposta != 's' && resposta != 'c'){
        
        //Voto Presidente
        system("clear");
        verdade = 0;
        aux = 0;
        cout << endl << endl <<"---------------------------------------------------------" << endl;
	    cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
        cout << "\tEleitor: " << eleicao[i][0];
        cout << endl << endl <<"---------------------------------------------------------" << endl << endl;
        cout << "\t\tVOTO PARA PRESIDENTE" << endl << endl;
       
        cout << "\tDigite \"0\" para Voto NULO;" << endl;
        cout << "\tDigite \"1\" para Voto BRANCO;" << endl;
        cout << endl <<"\tDigite Número Válido do Candidato: ";
	    cin >> numero_do_candidato;

        // Voto = 0 é voto nulo
        if(numero_do_candidato == "0"){
            eleicao[i][6] = nulo;
        }

        // Voto = 1 é voto Branco
        else if(numero_do_candidato == "1"){
            eleicao[i][6] = branco;
        }

        else{
            for(int k=0; k<1238; k++){
	            for(int j=0; j<58; j++){
                    if(numero_do_candidato == presidencia[k][16] && presidencia[k][13] == aux1){
                        verdade++;
                        eleicao[i][6] = presidencia[k][18];
                        
                        numero_do_candidato = presidencia[k][16];
                        nome_do_candidato = presidencia[k][18];
                        partido = presidencia[k][28];
                    }
        
                    else if(numero_do_candidato == presidencia[k][16] && presidencia[k][13] == aux2){
                        nome_do_vice_candidato = presidencia[k][18];
                    }
                }
                aux++;
            }
        }

     if(verdade>0){
            
            //Confirmação do Voto
            system("clear");
            cout << endl << endl <<"---------------------------------------------------------" << endl;
            cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
            cout << "\tEleitor: " << eleicao[i][0];
            cout << endl << endl <<"---------------------------------------------------------" << endl << endl;
        
            cout << "\t\tSEU VOTO PARA PRESIDENTE" << endl << endl;
            cout << "\n\tCANDIDATO: " << nome_do_candidato << ";" << endl << endl;
            cout << "\tVICE-GOVERNADOR: " << nome_do_vice_candidato << ";" << endl;
            cout << "\tNUMERO DO PARTIDO: " << numero_do_candidato << ";" << endl;
            cout << "\tNOME DO PARTIDO: " << partido << "." << endl << endl;
            cout << endl <<"---------------------------------------------------------" << endl << endl;

            cout << "\nDigite \"R\" para Corrigir;" << endl;
            cout << "Digite \"S\" para Cancelar;" << endl << endl;
            cout << "Digite \"C\" para Confirmar." << endl << endl;  
            cout << "Escolha: ";
            cin >> resposta;
            
            if(resposta < 97){
                // Transforma as letras maiúsculas da resposta do usuario em minúsculas
                resposta = resposta + 32;
            }

            while(resposta != 'c' && resposta != 's' && resposta != 'r'){
                cout << endl << "Por Favor, Escolha uma das Opções: \"R\", \"C\" ou \"S\"" << endl;
                cout << "Escolha: ";
                cin >> resposta;

                if(resposta < 97){
                    // Transforma as letras maiúsculas da resposta do usuario em minúsculas
                    resposta = resposta + 32;
                }
            }  
        }   

        else if(verdade == 0){
            system("clear");
            cout << endl << endl <<"---------------------------------------------------------" << endl;
	        cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
            cout << "\tEleitor: " << eleicao[i][0];
            cout << endl << endl <<"---------------------------------------------------------" << endl << endl;
        
            cout << "\t\tSEU VOTO PARA PREDIDENTE" << endl << endl;
            cout << "\n\tVOTO " << eleicao[i][6] << "." << endl << endl;
            cout << endl <<"---------------------------------------------------------" << endl << endl;

            cout << "\nDigite \"R\" para Corrigir;" << endl;
            cout << "Digite \"S\" para Cancelar;" << endl << endl;
            cout << "Digite \"C\" para Confirmar." << endl << endl;  
            cout << "Escolha: ";
            cin >> resposta;

	        if(resposta < 97){
		        // Transforma as letras maiúsculas da resposta do usuario em minúsculas
		        resposta = resposta + 32;
	        }

	        while(resposta != 'c' && resposta != 's' && resposta != 'r'){
		        cout << endl << "Por Favor, Escolha uma das Opções: \"R\", \"C\" ou \"S\"" << endl;
		        cout << "Escolha: ";
		        cin >> resposta;

		        if(resposta < 97){
			        // Transforma as letras maiúsculas da resposta do usuario em minúsculas
			        resposta = resposta + 32;
		        }
	        }
        }
    }

    //Teste
    //cout << eleicao[0][0] << endl;
    //cout << eleicao[0][1] << endl;
    //cout << eleicao[0][2] << endl;
    //cout << eleicao[0][3] << endl;
    //cout << eleicao[0][4] << endl;
    //cout << eleicao[0][5] << endl;
    //cout << eleicao[0][6] << endl;

    }

    cout << endl <<"---------------------------------------------------------" << endl << endl;
    cout << "FIM DE VOTAÇÃO" << endl << endl;
    cout << "Digite \"H\" para ver Histórico de Votação;" << endl << endl;
    cout << "Digite \"S\" para Sair." << endl;
    cout << "Escolha: ";
    cin >> resposta;

    if(resposta < 97){
        // Transforma as letras maiúsculas da resposta do usuario em minúsculas
        resposta = resposta + 32;
    }

    while(resposta != 'a' && resposta != 's' && resposta != 'h'){
        cout << endl << "Por Favor, Escolha uma das Opções: \"A\", \"S\" ou \"H\"" << endl;
        cout << "Escolha: ";
        cin >> resposta;

        if(resposta < 97){
            // Transforma as letras maiúsculas da resposta do usuario em minúsculas
            resposta = resposta + 32;
        }
    }

    if(resposta == 'h'){
        for(int i=0; i<numero_de_eleitores; i++){
            cout << endl << endl <<"---------------------------------------------------------" << endl;
	        cout << endl <<"	VOTAÇÃO 2018" << endl << endl << endl;
            cout << "\tEleitor: " << eleicao[i][0];
            cout << endl << endl <<"---------------------------------------------------------" << endl << endl;
            
            cout << "VOTO PARA DEPUTADO DISTRITAL: " <<  eleicao[i][1] << endl;
            cout << "VOTO PARA DEPUTADO FEDERAL: " <<  eleicao[i][2] << endl;
            cout << "VOTO PARA SENADOR - 1ª VAGA: " <<  eleicao[i][3] << endl;
            cout << "VOTO PARA SENADOR - 2ª VAGA: " <<  eleicao[i][4] << endl;
            cout << "VOTO PARA GOVERNADOR: " <<  eleicao[i][5] << endl;
            cout << "VOTO PARA PRESINDENTE: " <<  eleicao[i][6] << endl;
        }
    }
}