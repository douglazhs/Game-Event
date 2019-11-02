//Programa de controle de stands de jogos em um evento de video games.
//Autores: Douglas Henrique de Souza Pereira|Jo�o Victor de Souza Portella.
//Matr�culas: UC19107076|          .
//Institui��o de Ensino: Universidade Cat�lica de Bras�lia.
//Data: 02 de Novembro de 2019.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
	char nome[100];
	int CNPJ;
}empresas;

typedef struct{
	char nome[100];
	char tipo_stand;
	int identidade;
}gamers;

typedef struct{
	char nome[100];
	int CNPJ;
}patrocinadores;

void menu_participantes();
void menu_organizadores();
void cadastrar();
void stands();
void backup();
void restore();
void vagas();
void sobre();

int main(void){
	char escolha;
	do{
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tO QUE VOCE E? [P]PARTICIPANTE/[O]ORGANIZADOR");
		printf("\n\t\t\t\t\t      APERTE A RESPECTIVA LETRA>> ");
		escolha = getch();
		escolha = toupper(escolha);
		if(escolha != 'P' && escolha != 'O'){
			printf("\n\t\t\t\t\t\t  CARACTER INVALIDO!");
			Sleep(800);
		}
		system("cls");
	}while(escolha != 'P' && escolha != 'O');
	
	switch(escolha){
		case 'P':
			menu_participantes();
			break;
		case 'O':
			menu_organizadores();	
			break;
	}
}

void menu_participantes(){
	int opcao;
	do{
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\n                                          ��������� MENU PARTICIPANTE �������Ŀ\n");
		printf("                                          �                                   �\n");
		printf("                                          �           #1[CADASTRAR]           �\n");
		printf("                                          �           #2[STANDS]              �\n");
		printf("                                          �           #3[SOBRE O EVENTO]      �\n");
		printf("                                          �           #0[FECHAR]              �\n");
		printf("                                          �                                   �\n");
		printf("                                          �������������������������������������");
		printf("\n\t\t\t\t\t\t\t#OPCAO>> ");
		opcao = getch();
		if(opcao != '1' && opcao != '2' && opcao != '3' && opcao != '0'){
			printf("\n\t\t\t\t\t\t    OPCAO INVALIDA!");
			Sleep(800);
		}
		switch(opcao){
			case '1':
				cadastrar();
				break;
			case '2':
				stands();
				break;
			case '3':
				sobre();
				break;		
		}
	}while(opcao != '0');
}

void menu_organizadores(){
	int opcao;
	do{
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\n                                          ��������� MENU ORGANIZADOR �������Ŀ\n");
		printf("                                          �                                  �\n");
		printf("                                          �           #1[VAGAS]              �\n");
		printf("                                          �           #2[BACKUP DE DADOS]    �\n");
		printf("                                          �           #3[RECUPERAR DADOS]    �\n");
		printf("                                          �           #0[FECHAR]             �\n");
		printf("                                          �                                  �\n");
		printf("                                          ������������������������������������");
		printf("\n\t\t\t\t\t\t\t#OPCAO>> ");
		opcao = getch();
		if(opcao != '1' && opcao != '2' && opcao != '3' && opcao != '0'){
			printf("\n\t\t\t\t\t\t  OPCAO INVALIDA!");
			Sleep(800);
		}
		switch(opcao){
			case '1':
				vagas();
				break;
			case '2':
				system("cls");
				printf("\n\t\t\t\t\t\t\tBACKUP DE DADOS");
				printf("\n������������������������������������������������������������������������������������������������������������������������");
				backup();
				printf("PRESSIONE UMA TECLA PARA CONTINUAR...");
				getch();
				break;
			case '3':
				system("cls");
				printf("\n\t\t\t\t\t\t\tRESTAURAR DADOS");
				printf("\n������������������������������������������������������������������������������������������������������������������������");
				restore();
				printf("PRESSIONE UMA TECLA PARA CONTINUAR...");
				getch();
				break;		
		}
	}while(opcao != '0');
}

void cadastrar(){
	gamers participante;
	system("cls");
	printf("\n\t\t\t\t\t\t\tCADASTRAR");
	printf("\n������������������������������������������������������������������������������������������������������������������������");
	printf("\nBEM-VINDO GAMER, DIGITE SEU NOME>> ");
	fflush(stdin);
	gets(participante.nome);
	printf("\nOLA %s,", strcat(participante.nome, " GAMER"));
	printf("\nESCOLHA O STAND DE JOGO QUE IRA PARTICIPAR>> ");
	printf("PRESSIONE UMA TECLA PARA CONTINUAR...");
	getch();
}

void stands(){
	system("cls");
	printf("\n\t\t\t\t\t\t\tSTANDS");
	printf("\n������������������������������������������������������������������������������������������������������������������������");
	printf("PRESSIONE UMA TECLA PARA CONTINUAR...");
	getch();
}

void backup(){

} 

void restore(){
	
}

void vagas(){
	system("cls");
	printf("\n\t\t\t\t\t\t\tVAGAS");
	printf("\n������������������������������������������������������������������������������������������������������������������������");
	printf("PRESSIONE UMA TECLA PARA CONTINUAR...");
	getch();
}

void sobre(){
	system("cls");
	printf("\n\t\t\t\t\t\t\tSOBRE O EVENTO");
	printf("\n������������������������������������������������������������������������������������������������������������������������");
	printf("PRESSIONE UMA TECLA PARA CONTINUAR...");
	getch();
}
