#include "marina.h"


//Fun��o principal (MENU)
main(void){
	setlocale(LC_ALL, "Portuguese");
	int opcao = -1;
	printf("===================================================\nBem-vindo � Marina de Viana do Castelo\n===================================================\n");
	printf("[1] - Atracar uma nova embarca��o\n");
	printf("[2] - Informa��o sobre todas as embarca��es atracadas\n");
	printf("[3] - Informa��o sobre  as embarca��es atracadas num determinado cais\n");
	printf("[4] - N� de lugares vagos em cada cais\n");
	printf("[5] - Pedir prolongamento de estadia\n");
	printf("[6] - Lista das embarca��es com sa�da prevista num determinado dia\n");
	printf("[7] - Sa�da de uma embarca��o\n");
	printf("[0] - Sair\n");
	scanf("%i", &opcao);
	switch(opcao){
		case 0:{
			exit(0);
		break;
		}
		case 1:{
			nova_embarcacao();
		break;
		} 
		case 2:{
			informacao_todas_embarcacoes();
			break;
		}
		case 3:{
			informacao_embarcacoes_cais();
			break;
		}
		case 4:{
			lugares_vagos();
			break;
		}
		case 5:{
			prolongamento_estadia();
			break;
		}
		case 6:{
			embarcacoes_saida_dia();
			break;
		}
		case 7:{
			simular_saida();
			break;
		}
	}	
}

//Fun��o registar
int nova_embarcacao(){
	system("cls");
	
	//Verificar se h� lugares livres
	if(n_emb==186){
		printf("LOTA��O TOTAL, IMPOSSIV�L ATRACAR UMA NOVA EMBARCA��O!\n");
		system("cls");
		main();
	}
	
	else{
		//Introdu��o de dados
		printf("Introduza a matricula da embarcacao no formato (Nome-######-$-PT): ");
		fflush(stdin);
		gets(embarcacao[n_emb].matricula);	
		
		//Dividir a matricula 
		sscanf(embarcacao[n_emb].matricula, "%[^-]-%i-%i-%s", embarcacao[n_emb].nome, &embarcacao[n_emb].n_matricula, &embarcacao[n_emb].categoria, embarcacao[n_emb].pais);
		
			
		printf("Introduza o nome do proprietario: ");
		fflush(stdin);
		gets(embarcacao[n_emb].n_proprietario);
	
		printf("Introduza o nome do capitao: ");
		gets(embarcacao[n_emb].n_capitao);
		
		printf("Introduza o numero de passageiros: ");
		scanf("%i", &embarcacao[n_emb].passageiros);
		
		while(embarcacao[n_emb].dias<=0){ //validar datas e calcular o numero de dias no caso de o numero de dias ser menor ou igual a zero quer dizer que a data de sa�da � anterior � de entrada
			int datai_valida = 0;
			//validar data de entrada
			while(datai_valida == 0){
				printf("Introduza a data de entrada no formato (dd/mm/aa): ");
				scanf("%i/%i/%i", &embarcacao[n_emb].diai, &embarcacao[n_emb].mesi, &embarcacao[n_emb].anoi);
		
				if (embarcacao[n_emb].anoi >= 1900 && embarcacao[n_emb].anoi <= 9999){
			        //validar mes
			        if (embarcacao[n_emb].mesi >= 1 && embarcacao[n_emb].mesi <= 12){
			            //validar dia
			            if ((embarcacao[n_emb].diai >= 1 && embarcacao[n_emb].diai <= 31) && (embarcacao[n_emb].mesi == 1 || embarcacao[n_emb].mesi == 3 || embarcacao[n_emb].mesi == 5 || embarcacao[n_emb].mesi == 7 || embarcacao[n_emb].mesi == 8 || embarcacao[n_emb].mesi == 10 || embarcacao[n_emb].mesi == 12))
			                datai_valida = 1;
			            else if ((embarcacao[n_emb].diai >= 1 && embarcacao[n_emb].diai <= 30) && (embarcacao[n_emb].mesi == 4 || embarcacao[n_emb].mesi == 6 || embarcacao[n_emb].mesi == 9 || embarcacao[n_emb].mesi == 11))
			                datai_valida = 1;
			            else if((embarcacao[n_emb].diai >= 1 && embarcacao[n_emb].diai <= 28) && (embarcacao[n_emb].mesi == 2))
			                datai_valida = 1;
			            else if (embarcacao[n_emb].diai == 29 && embarcacao[n_emb].mesi == 2 && (embarcacao[n_emb].anoi % 400 == 0 || (embarcacao[n_emb].anoi % 4 == 0 && embarcacao[n_emb].anoi % 100 != 0)))
			                datai_valida = 1;
			            else
			                datai_valida = 0;
			        }
			        else{
			            datai_valida = 0;
			        }
				}
		    	else{
		        	datai_valida = 0;
		    	}	
				if(datai_valida == 0){
					printf("Data de entrada inv�lida!\n");
				}		
			}
	
			int dataf_valida = 0;
			
			//validar data de saida
			while(dataf_valida == 0){
				printf("Introduza a data de saida no formato (dd/mm/aa): ");
				scanf("%i/%i/%i", &embarcacao[n_emb].diaf, &embarcacao[n_emb].mesf, &embarcacao[n_emb].anof);
		    	if (embarcacao[n_emb].anof >= 1900 && embarcacao[n_emb].anof <= 9999){
			        //validar mes
			        if (embarcacao[n_emb].mesf >= 1 && embarcacao[n_emb].mesf <= 12){
			            //validar dia
			            if ((embarcacao[n_emb].diaf >= 1 && embarcacao[n_emb].diaf <= 31) && (embarcacao[n_emb].mesf == 1 || embarcacao[n_emb].mesf == 3 || embarcacao[n_emb].mesf == 5 || embarcacao[n_emb].mesf == 7 || embarcacao[n_emb].mesf == 8 || embarcacao[n_emb].mesf == 10 || embarcacao[n_emb].mesf == 12))
			                dataf_valida = 1;
			            else if ((embarcacao[n_emb].diaf >= 1 && embarcacao[n_emb].diaf <= 30) && (embarcacao[n_emb].mesf == 4 || embarcacao[n_emb].mesf == 6 || embarcacao[n_emb].mesf == 9 || embarcacao[n_emb].mesf == 11))
			                dataf_valida = 1;
			            else if ((embarcacao[n_emb].diaf >= 1 && embarcacao[n_emb].diaf <= 28) && (embarcacao[n_emb].mesf == 2))
			                dataf_valida = 1;
			            else if (embarcacao[n_emb].diaf == 29 && embarcacao[n_emb].mesf == 2 && (embarcacao[n_emb].anof % 400 == 0 || (embarcacao[n_emb].anof % 4 == 0 && embarcacao[n_emb].anof % 100 != 0)))
			                dataf_valida = 1;
			            else
			                dataf_valida = 0;
			        }
			        else{
			            dataf_valida = 0;
			        }
				}
		    	else{
		        	datai_valida = 0;
		    	}
		    	if(dataf_valida ==0){
		    		printf("Data de sa�da inv�lida!\n");	    		
				}
				else{
					if(embarcacao[n_emb].dias<=0){  
					printf("ERRO NO CALCULO DO NUMERO DE DIAS, � NECESS�RIO QUE A DATA DE SA�DA SEJA POSTERIOR � DATA DE ENTRADA!\n");
					}
				}
			}
			//C�lculo do numero de dias
			//atribuir valores da data de entrada aos parametros da struct	
			struct tm tm1 = {};
			tm1.tm_mday = embarcacao[n_emb].diai;
			tm1.tm_mon = embarcacao[n_emb].mesi -1;
			tm1.tm_year = embarcacao[n_emb].anoi -1900;
			
			struct tm tm2 = {};
			//atribuir valores da data de sa�da aos parametros da struct
			tm2.tm_mday = embarcacao[n_emb].diaf;
			tm2.tm_mon = embarcacao[n_emb].mesf -1;
			tm2.tm_year = embarcacao[n_emb].anof -1900;
			
			time_t tempo1 = mktime(&tm1); //transforma todos os parametros da struct tm1 em segundos
			time_t tempo2 = mktime(&tm2); //transforma todos os parametros da struct tm2 em segundos
			
			embarcacao[n_emb].dias = difftime(tempo2 , tempo1)/(60 * 60 * 24) + 1; //calcula a diferen�a dos varios parametros em segundos e transforma em dias
		}
		
		
		//Atribui��o do tipo de cais e respetivo pre�o
		switch(embarcacao[n_emb].categoria){
			case 1:{
				embarcacao[n_emb].cais= 'A';
				embarcacao[n_emb].preco = embarcacao[n_emb].dias * cais_a_preco;
				cais_a_lugares_vazios--;
				break;
			}
			case 2:{
				embarcacao[n_emb].cais = 'B';
				embarcacao[n_emb].preco = embarcacao[n_emb].dias * cais_b_preco;
				cais_b_lugares_vazios--;
				break;
			}
			case 3:{
				embarcacao[n_emb].cais = 'C';
				embarcacao[n_emb].preco = embarcacao[n_emb].dias * cais_c_preco;
				cais_c_lugares_vazios--;
				break;
			}
			case 4:{
				embarcacao[n_emb].cais = 'D';
				embarcacao[n_emb].preco = embarcacao[n_emb].dias * cais_d_preco;
				cais_d_lugares_vazios--;
				break;
			}
			case 5:{
				embarcacao[n_emb].cais = 'E';
				embarcacao[n_emb].preco = embarcacao[n_emb].dias * cais_e_preco;
				cais_e_lugares_vazios--;
				break;
			}
			case 6:{
				embarcacao[n_emb].cais = 'F';
				embarcacao[n_emb].preco = embarcacao[n_emb].dias * cais_f_preco;
				cais_f_lugares_vazios--;
				break;
			}
			case 7:{
				embarcacao[n_emb].cais = 'G';
				embarcacao[n_emb].preco = embarcacao[n_emb].dias * cais_g_preco;
				cais_g_lugares_vazios--;
				break;
			}
		}
	
		
		//Aplica��o de um desconto
		if(embarcacao[n_emb].dias>80){
			embarcacao[n_emb].preco = embarcacao[n_emb].preco *0.95;
		}
		n_emb ++;
		system("cls");
		main();
	}
}

//Listar informa��o de todas as embarca��es atracadas
int informacao_todas_embarcacoes(){
	system("cls");
	int i;
	if(n_emb < 1){									//caso n�o haja embarca��es atracadas
		printf("N�o h� embarca��es atracadas.\n");
		system("pause");
		system("cls");
		
	}
	else{
		for(i=0; i<n_emb;i++){
			printf("===================================================\n");
			printf("Matr�cula: %s\n",embarcacao[i].matricula);
			printf("Propriet�rio: %s\n",embarcacao[i].n_proprietario);	
			printf("Capit�o: %s\n",embarcacao[i].n_capitao);
			printf("N� Passageiros: %i\n",embarcacao[i].passageiros);
			printf("Tipo de cais: %c\n",embarcacao[i].cais);
			printf("Data de entrada: %i/%i/%i\n",embarcacao[i].diai, embarcacao[i].mesi, embarcacao[i].anoi);
			printf("Data de sa�da: %i/%i/%i\n", embarcacao[i].diaf, embarcacao[i].mesf, embarcacao[i].anof);
			printf("Pre�o final: %i euros\n", embarcacao[i].preco);		
		}
		system("pause");
		system("cls");
		main();
	}
}

//Listar informa��o de todas as embarca��es de um determinado cais
int informacao_embarcacoes_cais(){
	system("cls");
	char i_cais;
	printf("===================================================\nInforma��o das embarca��es atracadas num determinado cais\n===================================================\n");
	printf("Introduza o cais:\n");
	printf("[A] - Cais A\n");
	printf("[B] - Cais B\n");
	printf("[C] - Cais C\n");
	printf("[D] - Cais D\n");
	printf("[E] - Cais E\n");
	printf("[F] - Cais F\n");
	printf("[G] - Cais G\n");
	fflush(stdin);
	scanf("%c", &i_cais);
	int i;
	system("cls");
	switch(i_cais){
		case 'A':{
			for(i=0;i<n_emb;i++){
				if(embarcacao[i].cais == 'A'){
					printf("===================================================\n");
					printf("Matr�cula: %s\n",embarcacao[i].matricula);
					printf("Propriet�rio: %s\n",embarcacao[i].n_proprietario);	
					printf("Capit�o: %s\n",embarcacao[i].n_capitao);
					printf("N� Passageiros: %i\n",embarcacao[i].passageiros);
					printf("Tipo de cais: %c\n",embarcacao[i].cais);
					printf("Data de entrada: %i/%i/%i\n", embarcacao[i].diai, embarcacao[i].mesi, embarcacao[i].anoi);
					printf("Data de sa�da: %i/%i/%i\n", embarcacao[i].diaf, embarcacao[i].mesf, embarcacao[i].anof);
					printf("Pre�o final: %i euros\n", embarcacao[i].preco);		
				}
			}
			break;
		}
		case 'B':{
			for(i=0;i<n_emb;i++){
				if(embarcacao[i].cais == 'B'){
					printf("===================================================\n");
					printf("Matr�cula: %s\n",embarcacao[i].matricula);
					printf("Propriet�rio: %s\n",embarcacao[i].n_proprietario);	
					printf("Capit�o: %s\n",embarcacao[i].n_capitao);
					printf("N� Passageiros: %i\n",embarcacao[i].passageiros);
					printf("Tipo de cais: %c\n",embarcacao[i].cais);
					printf("Data de entrada: %i/%i/%i\n", embarcacao[i].diai, embarcacao[i].mesi, embarcacao[i].anoi);
					printf("Data de sa�da: %i/%i/%i\n", embarcacao[i].diaf, embarcacao[i].mesf, embarcacao[i].anof);
					printf("Pre�o final: %i euros\n", embarcacao[i].preco);	
				}
			}			
			break;
		}
		case 'C':{
			for(i=0;i<n_emb;i++){
				if(embarcacao[i].cais == 'C'){
					printf("===================================================\n");
					printf("Matr�cula: %s\n",embarcacao[i].matricula);
					printf("Propriet�rio: %s\n",embarcacao[i].n_proprietario);	
					printf("Capit�o: %s\n",embarcacao[i].n_capitao);
					printf("N� Passageiros: %i\n",embarcacao[i].passageiros);
					printf("Tipo de cais: %c\n",embarcacao[i].cais);
					printf("Data de entrada: %i/%i/%i\n", embarcacao[i].diai, embarcacao[i].mesi, embarcacao[i].anoi);
					printf("Data de sa�da: %i/%i/%i\n", embarcacao[i].diaf, embarcacao[i].mesf, embarcacao[i].anof);
					printf("Pre�o final: %i euros\n", embarcacao[i].preco);		
				}
			}
			break;
		}
		case 'D':{
			for(i=0;i<n_emb;i++){
				if(embarcacao[i].cais == 'D'){
					printf("===================================================\n");
					printf("Matr�cula: %s\n",embarcacao[i].matricula);
					printf("Propriet�rio: %s\n",embarcacao[i].n_proprietario);	
					printf("Capit�o: %s\n",embarcacao[i].n_capitao);
					printf("N� Passageiros: %i\n",embarcacao[i].passageiros);
					printf("Tipo de cais: %c\n",embarcacao[i].cais);
					printf("Data de entrada: %i/%i/%i\n", embarcacao[i].diai, embarcacao[i].mesi, embarcacao[i].anoi);
					printf("Data de sa�da: %i/%i/%i\n", embarcacao[i].diaf, embarcacao[i].mesf, embarcacao[i].anof);
					printf("Pre�o final: %i euros\n", embarcacao[i].preco);		
				}
			}			
			break;
		}
		case 'E':{
			for(i=0;i<n_emb;i++){
				if(embarcacao[i].cais == 'E'){
					printf("===================================================\n");
					printf("Matr�cula: %s\n",embarcacao[i].matricula);
					printf("Propriet�rio: %s\n",embarcacao[i].n_proprietario);	
					printf("Capit�o: %s\n",embarcacao[i].n_capitao);
					printf("N� Passageiros: %i\n",embarcacao[i].passageiros);
					printf("Tipo de cais: %c\n",embarcacao[i].cais);
					printf("Data de entrada: %i/%i/%i\n", embarcacao[i].diai, embarcacao[i].mesi, embarcacao[i].anoi);
					printf("Data de sa�da: %i/%i/%i\n", embarcacao[i].diaf, embarcacao[i].mesf, embarcacao[i].anof);
					printf("Pre�o final: %i euros\n", embarcacao[i].preco);		
				}
			}			
			break;
		}
		case 'F':{
			for(i=0;i<n_emb;i++){
				if(embarcacao[i].cais == 'F'){
					printf("===================================================\n");
					printf("Matr�cula: %s\n",embarcacao[i].matricula);
					printf("Propriet�rio: %s\n",embarcacao[i].n_proprietario);	
					printf("Capit�o: %s\n",embarcacao[i].n_capitao);
					printf("N� Passageiros: %i\n",embarcacao[i].passageiros);
					printf("Tipo de cais: %c\n",embarcacao[i].cais);
					printf("Data de entrada: %i/%i/%i\n", embarcacao[i].diai, embarcacao[i].mesi, embarcacao[i].anoi);
					printf("Data de sa�da: %i/%i/%i\n", embarcacao[i].diaf, embarcacao[i].mesf, embarcacao[i].anof);
					printf("Pre�o final: %i euros\n", embarcacao[i].preco);		
				}
			}			
			break;
		}
		case 'G':{
			for(i=0;i<n_emb;i++){
				if(embarcacao[i].cais == 'G'){
					printf("===================================================\n");
					printf("Matr�cula: %s\n",embarcacao[i].matricula);
					printf("Propriet�rio: %s\n",embarcacao[i].n_proprietario);	
					printf("Capit�o: %s\n",embarcacao[i].n_capitao);
					printf("N� Passageiros: %i\n",embarcacao[i].passageiros);
					printf("Tipo de cais: %c\n",embarcacao[i].cais);
					printf("Data de entrada: %i/%i/%i\n", embarcacao[i].diai, embarcacao[i].mesi, embarcacao[i].anoi);
					printf("Data de sa�da: %i/%i/%i\n", embarcacao[i].diaf, embarcacao[i].mesf, embarcacao[i].anof);
					printf("Pre�o final: %i euros\n", embarcacao[i].preco);
				}
			}			
			break;
		}
	}
	system("pause");
	system("cls");
	main();
}

//Listar lugares livres de cada cais
int lugares_vagos(){
	system("cls");
	printf("===================================================\nLugares Vagos\n===================================================\n");
	printf("Cais A - %i\n", cais_a_lugares_vazios);
	printf("Cais B - %i\n", cais_b_lugares_vazios);
	printf("Cais C - %i\n", cais_c_lugares_vazios);
	printf("Cais D - %i\n", cais_d_lugares_vazios);
	printf("Cais E - %i\n", cais_e_lugares_vazios);
	printf("Cais F - %i\n", cais_f_lugares_vazios);
	printf("Cais G - %i\n", cais_g_lugares_vazios);
	system("pause");
	system("cls");
	main();	
}

//Pedido para prolongar estadia estadia
int prolongamento_estadia(){
	char matricula[20];
	system("cls");
	printf("===================================================\nProlongamento da estadia\n===================================================\n");
	printf("Introduza a matr�cula da embarca��o que deseja prolongar a estadia: ");
	fflush(stdin);
	gets(matricula);
	int p_dia;
	int p_mes;
	int p_ano;
	
	int dataf_valida = 0;
	
	int i;
	int ret = 0;
	//Procura a embarca��o com determinada matricula
	for(i=0;i<n_emb;i++){
		ret = strcmp(embarcacao[i].matricula, matricula);
		//Substitui��o de dados
		if(ret == 0){
			while(dataf_valida == 0){
				printf("Introduza a data final no formato (dd/mm/aaaa): ");
				fflush(stdin);
				scanf("%i/%i/%i", &p_dia, &p_mes, &p_ano);
				if (p_ano >= 1900 && p_ano <= 9999){
					//validar mes
					if (p_mes >= 1 && p_mes <= 12){
					    //validar dia
					    if ((p_dia >= 1 && p_dia <= 31) && (p_mes == 1 || p_mes == 3 || p_mes == 5 || p_mes == 7 || p_mes == 8 || p_mes == 10 || p_mes == 12))
					        dataf_valida = 1;
					    else if ((p_dia >= 1 && p_dia <= 30) && (p_mes == 4 || p_mes == 6 || p_mes == 9 || p_mes == 11))
					        dataf_valida = 1;
					    else if ((p_dia >= 1 && p_dia <= 28) && (p_mes == 2))
					        dataf_valida = 1;
					    else if (p_dia == 29 && p_mes == 2 && (p_ano % 400 == 0 || (p_ano % 4 == 0 && p_ano % 100 != 0)))
					        dataf_valida = 1;
					    else
					        dataf_valida = 0;
					    }
					else{
					    dataf_valida = 0;
					}
				}
				else{
				    dataf_valida = 0;
				}
				if(dataf_valida ==0){
				    printf("Data inv�lida!\n");	    		
				}
				embarcacao[i].diaf = p_dia;
				embarcacao[i].mesf = p_mes;
				embarcacao[i].anof = p_ano;
				//C�lculo do numero de dias	
				struct tm tm1 = {};
				tm1.tm_mday = embarcacao[i].diai;
				tm1.tm_mon = embarcacao[i].mesi -1;
				tm1.tm_year = embarcacao[i].anoi -1900;
				
				struct tm tm2 = {};
				tm2.tm_mday = embarcacao[i].diaf;
				tm2.tm_mon = embarcacao[i].mesf -1;
				tm2.tm_year = embarcacao[i].anof -1900;
				
				time_t tempo1 = mktime(&tm1); //transforma todos os parametros da struct tm1 em segundos
				time_t tempo2 = mktime(&tm2); //transforma todos os parametros da struct tm2 em segundos
				
				embarcacao[i].dias = difftime(tempo2 , tempo1)/(60 * 60 * 24) + 1; //calcula a diferen�a dos varios parametros em segundos e transforma em dias
			}
			//Calcular pre�o
			switch(embarcacao[i].cais){
				case 'A':{
						embarcacao[i].preco = embarcacao[i].dias * cais_a_preco;
					break;
				}
				case 'B':{
						embarcacao[i].preco = embarcacao[i].dias * cais_b_preco;
					break;
				}
				case 'C':{
						embarcacao[i].preco = embarcacao[i].dias * cais_c_preco;
					break;
				}
				case 'D':{
						embarcacao[i].preco = embarcacao[i].dias * cais_d_preco;
					break;
				}
				case 'E':{
						embarcacao[i].preco = embarcacao[i].dias * cais_e_preco;
					break;
				}
				case 'F':{
						embarcacao[i].preco = embarcacao[i].dias * cais_f_preco;
					break;
				}
				case 'G':{
						embarcacao[i].preco = embarcacao[i].dias * cais_g_preco;
					break;
				}		
			}
		//Aplicar desconto
			if(embarcacao[i].dias>80){
				embarcacao[i].preco = embarcacao[i].preco *0.95;
			}
			printf("Data de sa�da alterada com sucesso!\n");
		}
	}
	if(ret != 0){
		printf("A embarca��o com a matricula (%s) n�o foi encontrada nos registos\n", matricula);
	}
	system("pause");
	system("cls");
	main();
}

//listar embarca��es com saida prevista 
int embarcacoes_saida_dia (){
	system("cls");
	int u_dia;
	int u_mes;
	int u_ano;
	printf("===================================================\nEmbarca��es com sa�da prevista numa determinada data\n===================================================\n");
	printf("Introduza a data: \n");
	scanf("%i/%i/%i", &u_dia, &u_mes, &u_ano);
	int i;
	int data_valida;
	//Procura as embarca��es com data de sa�da igual
	for(i=0; i<n_emb;i++){
		if(embarcacao[i].diaf == u_dia && embarcacao[i].mesf && embarcacao[i].anof){
			printf("===================================================\n");
			printf("Matr�cula: %s\n",embarcacao[i].matricula);
			printf("Propriet�rio: %s\n",embarcacao[i].n_proprietario);	
			printf("Capit�o: %s\n",embarcacao[i].n_capitao);
			printf("N� Passageiros: %i\n",embarcacao[i].passageiros);
			printf("Tipo de cais: %c\n",embarcacao[i].cais);
			printf("Data de entrada: %i/%i/%i\n", embarcacao[i].diai, embarcacao[i].mesi, embarcacao[i].anoi);
			printf("Data de sa�da: %i/%i/%i\n", embarcacao[i].diaf, embarcacao[i].mesf, embarcacao[i].anof);
			printf("Pre�o final: %i euros\n", embarcacao[i].preco);	
			data_valida = 1;	
		}
	}
	if(data_valida != 1){
		printf("Nenhuma embarca��o encontrada com sa�da prevista nessa data!\n");
	}
	system("pause");
	system("cls");
	main();		
}

//Simular sa�da
int simular_saida(){
	system("cls");
	char matricula[20];
	printf("===================================================\nSa�da de uma embarca��o\n===================================================\n");
	printf("Introduza a matricula da embarca��o: ");
	fflush(stdin);
	gets(matricula);
	int i;
	int posicao;
	int ret;
	int matricula_valida;
	//Procura embarca��o com a matricula igual
	for(i=0;i<n_emb;i++){
		ret = strcmp(embarcacao[i].matricula, matricula);
		if(ret == 0){
			matricula_valida = 1;
			printf("O valor a pagar por %i dias no cais %c � %i�.\nObrigado pela prefer�ncia!", embarcacao[i].dias, embarcacao[i].cais, embarcacao[i].preco);
			//retirar a embarca��o e aumentar um lugar livre ao cais que pertencia
			switch(embarcacao[i].cais){
				case 'A':{
					cais_a_lugares_vazios++;
					break;
				}
				case 'B':{
					cais_b_lugares_vazios++;
					break;
				}
				case 'C':{
					cais_c_lugares_vazios++;
					break;
				}
				case 'D':{
					cais_d_lugares_vazios ++;
					break;
				}
				case 'E':{
					cais_e_lugares_vazios++;
					break;
				}
				case 'F':{
					cais_f_lugares_vazios++;
					break;
				}
				case 'G':{
					cais_g_lugares_vazios++;
					break;
				}
			}
			//limpar dados da struct
			posicao = i;
			if(posicao == n_emb){
				n_emb--;
			}
			for(i = posicao; i <n_emb ; i++){
					embarcacao[i]= embarcacao[i+1];
			}
			n_emb--;
		}
	} 
	//caso a matricula n�o coincida com alguma registada
	if(matricula_valida != 1){
		printf("Embarca��o n�o encontrada\n");
	}
	system("pause");
	system("cls");
	main();
}

