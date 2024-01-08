/*==========================================|
|===========================================|
|				Trabalho AED				|
|Tema: Gestão da Marina de Viana do Castelo	|
|Realizadores:  Grupo B6					|
|Diogo Rocha Azevedo (Nª29059)				|
|Pedro Martins Correia (Nª29241)			|
|===========================================|
|==========================================*/


#ifndef marina_h
#define marina_h

//Bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

//Declarar struct de embarcações
typedef struct NovaEmbarcacao {
	char matricula[20];
	char nome[20];
	int n_matricula;
	int categoria;
	char pais[20];
	char n_proprietario[20];
	char n_capitao[20];
	char cais;
	int passageiros;
	int diai;
	int mesi;
	int anoi;
	int diaf;
	int mesf;
	int anof;
	int dias;
	int preco;
}embarcacoes;

//Declarar vetor 
#define MAX_EMBARCACOES 186
embarcacoes embarcacao[MAX_EMBARCACOES];
int n_emb = 0;

//Declarar valores dos cais
#define cais_a_lugares 40;
#define cais_b_lugares 32;
#define cais_c_lugares 35;
#define cais_d_lugares 30;
#define cais_e_lugares 25;
#define cais_f_lugares 17;
#define cais_g_lugares 7;

int cais_a_lugares_vazios = cais_a_lugares;
int cais_b_lugares_vazios = cais_b_lugares;
int cais_c_lugares_vazios = cais_c_lugares;
int cais_d_lugares_vazios = cais_d_lugares;
int cais_e_lugares_vazios = cais_e_lugares;
int cais_f_lugares_vazios = cais_f_lugares;
int cais_g_lugares_vazios = cais_g_lugares;

#define cais_a_preco 10.40;
#define cais_b_preco 15.50;
#define cais_c_preco 19.50;
#define cais_d_preco 25.60;
#define cais_e_preco 50.5;
#define cais_f_preco 62.8;
#define cais_g_preco 80;

int main(void);
int nova_embarcacao();
int informacao_todas_embarcacoes();
int informacao_embarcacoes_cais();
int lugares_vagos();
int prolongamento_estadia();
int embarcacoes_saida_dia ();
int simular_saida();

#endif
