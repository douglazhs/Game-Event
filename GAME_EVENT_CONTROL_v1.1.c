//Programa de controle de stands de jogos em um evento de video games.
//Autores: Douglas Henrique de Souza Pereira|Joao Victor de Souza Portella.
//Matriculas: UC19107076|UC19100100.
//Instituicao de Ensino: Universidade Catolica de Brasilia.
//Data: 27 de Novembro de 2019.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h> 
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include "STRUCTS.h"
#include "VALIDACOES.h"
#include "STANDS.h"
#include "MENUS.h"
//------ TECLAS PARA FUNCAO GOTOXY(X,Y) ---------------------------------------------------------------------------------------------------------------------------------------------
#define ENTER 13
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define ESC 27
//------ DEFINICAO DE CORES --------------------------------------------------------------------------------------------------------------------------------------------------------
#define R "\e[1;31m" //Vermelho
#define B "\x1b[0m"  //Branco
#define G "\e[1;32m" //Verde
//------ PROTOTIPOS -----------------------------------------------------------------------------------------------------------------------------------------------------
void stands();
void stands_patrocinador();
void organizar_cads();
void sobre();
void copia_nome(char[], char);
float maior_pat(char[]);
//------ FUNCOES CONIO ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void gotoxy(int x, int y){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}
void HideCursor(){
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}
//------ MENU PRINCIPAL ----------------------------------------------------------------------------------------------------------------------------------------------
int main(void){
	char tecla;
	int pos = 15, i = 1;

	HideCursor();
	do{	
		system("cls");
		printf("\n\t\t\t\t\tUCBG - UNIVERSIDADE CATOLICA DE BRASILIA GAMES\n\n");
		printf(R"\n\t\t\t\t\t       //   / / //   ) )  //   ) )  //   ) )"); 
		printf("\n\t\t\t\t\t      //   / / //        //___/ /  //");        
		printf("\n\t\t\t\t\t     //   / / //        / __  (   //  ____");   
		printf("\n\t\t\t\t\t    //   / / //        //    ) ) //    / /");  
		printf("\n\t\t\t\t\t   ((___/ / ((____/ / //____/ / ((____/ /"B);    
		printf("\n\n\n\n\t\t\t\t\t\t       %c O QUE VOCE E?", 254);
		printf("\n\t\t\t\t\t\tษอออออออออออออออออออออออออออ%c", 187);
		gotoxy(49,15);printf("บ    %c PARTICIPANTE         บ", 254);
		printf("\n\t\t\t\t\t\tฬอออออออออออออออออออออออออออ%c", 185);
		gotoxy(49,17);printf("บ    %c EMPRESA              บ", 254);
		printf("\n\t\t\t\t\t\tฬอออออออออออออออออออออออออออ%c", 185);
		gotoxy(49,19);printf("บ    %c PATROCINADOR         บ", 254);
		printf("\n\t\t\t\t\t\tฬอออออออออออออออออออออออออออ%c", 185);
		gotoxy(49,21);printf("บ    %c SOBRE O EVENTO       บ", 254);
		printf("\n\t\t\t\t\t\tฬอออออออออออออออออออออออออออ%c", 185);
		gotoxy(49,23);printf("บ    %c SAIR DO PROGRAMA     บ", 254);
		printf("\n\t\t\t\t\t\tศอออออออออออออออออออออออออออผ");
		gotoxy(75, pos);printf(R"%c"B, 174);
		tecla = getch();
		if(tecla == DOWN)
			pos += 2;
		if(tecla == UP)
			pos -= 2;
		if(pos > 23)
			pos = 15;
		if(pos < 15)
			pos = 23;			 
	}while(tecla != ENTER);
	switch(pos){
		case 15: menu_participantes(); break;
		case 17: menu_organizadores(); break;
		case 19: menu_patrocinadores(); break;
		case 21: sobre();break;
		case 23: break;
	}
}
//------- ACESSAR DADOS -----------------------------------------------------------------------------------------------------------------------------------------------------------------------
gamers acessar_dados_participante(){
	FILE *arq;
	gamers participante;
	int flag = 0, pos = 0;
	char user[50];
	
	arq = fopen("cad_participantes.dat", "rb");
	if(arq == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");	
		return;
	}
	do{
		system("cls");
		flag = 0;
		rewind(arq);
		gotoxy(52,10);printf("ษอออออออออออออออออออออออออ%c", 187);
		gotoxy(52,11);printf("บ USUARIO:                บ");
		gotoxy(52,12);printf("ศอออออออออออออออออออออออออผ\n\t");
		gotoxy(63,11);
		fflush(stdin);
		gets(user);
		while(fread(&participante, sizeof(participante), 1, arq)){
			if(strcmp(user, participante.usuario) == 0){
				mostra_participante(participante);
				return participante;
			}
		}
		if(strcmp(user, participante.usuario) != 0){
			flag = 1;
			printf(R"\n\t\t\t\t   USUARIO NAO CADASTRADO NO SISTEMA, TENTE NOVAMENTE!"B);
			Sleep(500);
		}
	}while(flag == 1);
	fclose(arq);
}

patrocinadores acessar_dados_patrocinador(){
	char email[150];
	int flag = 0;
	patrocinadores empresa;
	FILE *arqPAT = fopen("cad_patrocinadores.dat", "rb");
	
	do{
		system("cls");
		flag = 0;
		rewind(arqPAT);
		gotoxy(52,10);printf("ษอออออออออออออออออออออออออ%c", 187);
		gotoxy(52,11);printf("บ EMAIL:                  บ");
		gotoxy(52,12);printf("ศอออออออออออออออออออออออออผ\n\t");
		gotoxy(60,11);
		fflush(stdin);
		gets(email);
		while(fread(&empresa, sizeof(empresa), 1, arqPAT)){
			if(strcmp(email, empresa.email) == 0){
				mostra_patrocinador(empresa);
				return empresa;
			}
		}
		if(strcmp(email, empresa.email) != 0){
			flag = 1;
			printf(R"\n\t\t\t\tUSUARIO NAO CADASTRADO NO SISTEMA, TENTE NOVAMENTE!"B);
			Sleep(500);
		}
	}while(flag == 1);
	fclose(arqPAT);
}
//------- MOSTRA DADOS ------------------------------------------------------------------------------------------------------------------------
void mostra_patrocinador(patrocinadores empresa){
	char nome[50];
	
	system("cls");
	copia_nome(nome, empresa.stand_escolhido);
	printf("\n\tษออออออออออออออออออออออออออออออ%c", 187);
	printf("\n\tบ   %c NOME %c                   บ", 254, 175);
	printf("\n\tฬออออออออออออออออออออออออออออออ%c", 185);
	printf("\n\tบ   %c EMAIL %c                  บ", 254, 175);
	printf("\n\tฬออออออออออออออออออออออออออออออ%c", 185);
	printf("\n\tบ   %c STAND %c                  บ", 254, 175);
	printf("\n\tฬออออออออออออออออออออออออออออออ%c", 185);
	printf("\n\tบ   %c PATROCINIO %c             บ", 254, 175);
	printf("\n\tศออออออออออออออออออออออออออออออผ");
	gotoxy(22,3);printf("%s", empresa.nome);
	gotoxy(23,5);printf("%s", empresa.email);
	gotoxy(23,7);printf(nome);
	gotoxy(28,9);printf("%.2f", empresa.quantia);
	printf("\n\n\t");
	system("pause");
}

void mostra_participante(gamers participante){
	char nome[50];
	
	copia_nome(nome, participante.stand);
	system("cls");
	printf("\n\tษออออออออออออออออออออออออออออออ%c", 187);
	printf("\n\tบ   %c USUARIO %c                บ", 254, 175);
	printf("\n\tฬออออออออออออออออออออออออออออออ%c", 185);
	printf("\n\tบ   %c NOME %c                   บ", 254, 175);
	printf("\n\tฬออออออออออออออออออออออออออออออ%c", 185);
	printf("\n\tบ   %c STAND %c                  บ", 254, 175);
	printf("\n\tศออออออออออออออออออออออออออออออผ");
	gotoxy(25,3);printf("%s", participante.usuario);
	gotoxy(23,5);printf("%s", participante.nome);
	gotoxy(23,7);printf("%s", nome);
	printf("\n\n\t");
	system("pause");
}

void mostra_participantes(){
	char nome[50];
	int pos = 5;
	gamers participante;
	FILE *arq = fopen("cad_participantes.dat", "rb");
	
	if(arq == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");
		return;
	}
	system("cls");
	printf("\n\t\t\t\t\t\tUSUARIOS CADASTRADOS NO SISTEMA");
	printf("\nออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ"); 
	while(fread(&participante, sizeof(participante), 1, arq) && participante.deletado != '*'){
		copia_nome(nome, participante.stand);
		printf("\n\tษออออออออออออออออออออออออออออออ%c", 187);
		printf("\n\tบ   %c USUARIO %c                บ", 254, 175);
		printf("\n\tฬออออออออออออออออออออออออออออออ%c", 185);
		printf("\n\tบ   %c NOME %c                   บ", 254, 175);
		printf("\n\tฬออออออออออออออออออออออออออออออ%c", 185);
		printf("\n\tบ   %c STAND %c                  บ", 254, 175);
		printf("\n\tศออออออออออออออออออออออออออออออผ");
		gotoxy(25,pos);printf("%s", participante.usuario);
		gotoxy(22,pos+2);printf("%s", participante.nome);
		gotoxy(23,pos+4);printf("%s", nome);
		printf("\n");
		pos+=7;
	}
	printf("\n\t");
	system("\n\tpause");
	fclose(arq);
}

void mostra_patrocinio(){
	float pat_total = 0;
	int pos = 5;
	patrocinadores empresa;
	FILE *arq = fopen("cad_patrocinadores.dat", "rb");
	
	system("cls");
	printf("\n\t\t\t\t\t\t\tPATROCINIOS\n");
	printf("ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
	while(fread(&empresa, sizeof(empresa), 1, arq)){
		printf("\n\tษออออออออออออออออออออออออออออออ%c", 187);
		printf("\n\tบ   %c NOME %c                   บ", 254, 175);
		printf("\n\tฬออออออออออออออออออออออออออออออ%c", 185);
		printf("\n\tบ   %c PATROCINIO %c             บ", 254, 175);
		printf("\n\tศออออออออออออออออออออออออออออออผ");
		gotoxy(22,pos);printf("%s", empresa.nome);
		gotoxy(28,pos+2);printf("R$%.2f", empresa.quantia);
		printf("\n");
		pat_total += empresa.quantia;
		pos+=5;
	}
	printf("\n\n\t%c PATROCINIO TOTAL %c R$%.2f", 254, 175, pat_total);
	printf("\n\n\t");
	system("pause");
	fclose(arq);
}

void mostra_patrocinador_stand(){
	FILE *arq = fopen("cad_patrocinadores.dat","rb");
	patrocinadores empresa;
	gamers participante;
	char stand;
	int pos = 10;
	
	participante = acessar_dados_participante();
	gotoxy(9,pos+1);printf("%c PATROCINADORES DO SEU STAND", 254);
	pos+=1;
	while(fread(&empresa, sizeof(empresa), 1, arq)){
		if(empresa.stand_escolhido == participante.stand){
			gotoxy(9,pos+1);printf("%c %s",175, empresa.nome);
			pos+=1;
		}
	}
	getch();
	fclose(arq);
}
//------ MOSTRAR NOME DOS STANDS ----------------------------------------------------------------------------------------------------------------------------------------
void copia_nome(char nome[], char stand){
	switch(stand){
		case 'R':
			strcpy(nome, "RPG");
			break;
		case 'F':
			strcpy(nome, "FPS");
			break;
		case 'E':
			strcpy(nome, "ESPORTE");
			break;
		case 'A':
			strcpy(nome, "AVENTURA");
			break;
		case 'L':
			strcpy(nome, "LUTA");
			break;
		case 'C':
			strcpy(nome, "CORRIDA");
			break;				
	}
}
//------- CADASTROS -----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void cad_patrocinadores(){
	char email[150];
	patrocinadores empresa;
	FILE *arqPAT = fopen("cad_patrocinadores.dat", "ab+");
	
	if(arqPAT == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");
		return;
	}
	system("cls");
	printf("\n\t\t\t\t\t\t\tCADASTRO DE PATROCINADOR");
	printf("\nออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
	printf("\n\t%c NOME DA EMPRESA %c ", 254, 175);
	fflush(stdin);
	leValidaNome(empresa.nome);
	leValidaEmailPat(email);
	strcpy(empresa.email, email);
	empresa.stand_escolhido = leValidaStandPat();
	gotoxy(55,15);printf("%c PATROCINIO %c ", 254, 175);
	scanf("%f", &empresa.quantia);
	gotoxy(48,17);printf(G"CADASTRO REALIZADO COM SUCESSO!"B);
	Sleep(1000);
	fwrite(&empresa, sizeof(empresa), 1, arqPAT);
	fclose(arqPAT);
}

void cad_participantes(int total_stands[]){
	char user[50], nome[100];
	gamers participante;
	FILE *arqPAR = fopen("cad_participantes.dat", "ab+");

	system("cls");
	if(arqPAR == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");	
		return;
	}
	printf("\n\t\t\t\t\t\t\tCADASTRO DE PARTICIPANTES");
	printf("\nออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
	printf("\n\t%c BEM-VINDO, GAMER. DIGITE SEU NOME %c ", 254, 175);
	leValidaNome(participante.nome);
	printf("\n\tOLA, %s.", participante.nome);
	leValidaUsuario(user);
	strcpy(participante.usuario, user);
	participante.stand = leValidaStand();
	participante.stand_patrocinador = participante.stand;
	participante.deletado = ' ';
	fwrite(&participante, sizeof(participante), 1, arqPAR);
	fclose(arqPAR);
	gotoxy(47, 15);printf(G"CADASTRO REALIZADO COM SUCESSO!"B);
	Sleep(1000);
	menu_participantes();
}

void cad_empresas(){
	FILE *arqEMP;
	char email[150];
	int senha;
	organizadores empresa;
	
	srand(time(NULL));
	arqEMP = fopen("cad_organizadores.dat", "ab");
	if(arqEMP == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");	
		return;
	}
	system("cls");
	printf("\n\t\t\t\t\t\t  CADASTRO DE ORGANIZADOR");
	printf("\nออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ"); 
	printf("\n\t%c NOME DA EMPRESA ORGANIZADORA %c ", 254, 175);
	fflush(stdin);
	leValidaNome(empresa.nome);
	leValidaEmailOrg(email);
	strcpy(empresa.email, email);
	senha = 1000 + (rand() % 1000);
	empresa.senha = senha;
	printf(R"\n*************************** GUARDE ESSA SENHA PARA ACESSOS A PARTE ADMINISTRADORA DO SISTEMA ***************************"B);
	printf("\n\n\t%c SENHA DE ACESSO PARA INFORMACOES DO EVENTO %c "R"%d"B, 254, 175, empresa.senha);
	fwrite(&empresa, sizeof(empresa), 1, arqEMP);
	fclose(arqEMP);
	printf("\n\n\t");
	system("pause");
}
//------- ALTERACAO DE DADOS -------------------------------------------------------------------------------------------------------------------------------------------------------------
void alterar_dados_participante(){
	int op, flag = 0, pos = 4;
	char stand, user[50], tecla;
	gamers participante;
	FILE *arqPAR = fopen("cad_participantes.dat", "r+b");
	
	if(arqPAR == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");	
		return;
	}
	do{
		system("cls");
		flag = 0;
		rewind(arqPAR);
		gotoxy(52,10);printf("ษอออออออออออออออออออออออออ%c", 187);
		gotoxy(52,11);printf("บ USUARIO:                บ");
		gotoxy(52,12);printf("ศอออออออออออออออออออออออออผ\n\t");
		gotoxy(63,11);
		fflush(stdin);
		gets(user);
		while(fread(&participante, sizeof(participante), 1, arqPAR) == 1 && strcmp(user, participante.usuario) != 0);
		if(strcmp(user, participante.usuario) == 0){
			mostra_participante(participante);
			do{
				system("cls");
				printf("\n\tESCOLHA O QUE DESEJA ALTERAR\n", 175);
				printf("\n\t%c STAND", 254);
				printf("\n\t%c USUARIO", 254);
				gotoxy(19, pos);printf(R"%c"B, 174);
				tecla = getch();
				if(tecla == DOWN)
					pos += 1;
				if(tecla == UP)
					pos -= 1;
				if(pos > 5)
					pos = 4;
				if(pos < 4)
					pos = 5;
			}while(tecla != ENTER);
			switch(pos){
				case 4: 
					participante.stand = leValidaStand();
					break;
				case 5:
					leValidaUsuario(user);
					strcpy(participante.usuario, user);
					break;
			}
			fseek(arqPAR, -sizeof(participante), SEEK_CUR);
			fwrite(&participante, sizeof(participante), 1, arqPAR);
		}
		if(strcmp(user, participante.usuario) != 0){
			flag = 1;
			printf(R"\n\t\t\t\tUSUARIO NAO CADASTRADO NO SISTEMA, TENTE NOVAMENTE!"B);
			Sleep(200);
		}
	}while(flag == 1);
	fclose(arqPAR);
}

//------ EXCLUIR CADASTRO DE PARTICIPANTE ---------------------------------------------------------------------------------------------------------------------------------------
void excluir_cadastro_participante(){
	int flag = 0, pos = 5, posX = 51;
	char user[50], tecla, tecla2;
	gamers participante;
	FILE  *arqPAR = fopen("cad_participantes.dat", "ab+");
	
	if(arqPAR == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");
		return;
	}
	do{
		system("cls");
		printf("\n\t\t\t\t\t        EXCLUSAO DE CADASTROS");
		printf("\nออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
		printf("\n\t\t\t\t\t    ษออออออออออออออออออออออออออออออ%c", 187);
		printf("\n\t\t\t\t\t    บ   %c EXCLUIR PARTICIPANTE     บ", 254);
		printf("\n\t\t\t\t\t    ฬออออออออออออออออออออออออออออออ%c", 185);
		printf("\n\t\t\t\t\t    บ   %c ORGANIZAR CADASTROS      บ", 254);
		printf("\n\t\t\t\t\t    ศออออออออออออออออออออออออออออออผ");
		gotoxy(75, pos);printf(R"%c"B, 174);
		tecla = getch();
		if(tecla == DOWN)
			pos += 2;
		if(tecla == UP)
			pos -= 2;
		if(pos > 7)
			pos = 5;
		if(pos < 5)
			pos = 7;
	}while(tecla != ENTER);
	switch(pos){
		case 5:
			do{
				system("cls");
				flag = 0;
				gotoxy(52,10);printf("ษอออออออออออออออออออออออออ%c", 187);
				gotoxy(52,11);printf("บ USUARIO:                บ");
				gotoxy(52,12);printf("ศอออออออออออออออออออออออออผ\n\t");
				gotoxy(63,11);
				fflush(stdin);
				gets(user);
				while(fread(&participante, sizeof(participante), 1, arqPAR) && strcmp(user, participante.usuario) != 0);
				if(strcmp(user, participante.usuario) == 0){
					mostra_participante(participante);
					do{
						system("cls");	
						gotoxy(42,10);printf("TEM CERTEZA QUE DESEJA FAZER A EXCLUSAO?");
						gotoxy(47,11);printf(G"SIM"B);
						gotoxy(74,11);printf(R"NAO"B);
						gotoxy(posX,11);printf(R"%c"B,174);
						tecla2 = getch();
						if(tecla2 == RIGHT)
							posX+=27;
						if(tecla2 == LEFT)
							posX-=27;
						if(posX > 78)
							posX = 51;
						if(posX < 51)
							posX = 78;			
					}while(tecla2 != ENTER);
					switch(posX){
						case 51:
							participante.deletado = '*';
							fseek(arqPAR, -sizeof(participante), SEEK_CUR);
							fwrite(&participante, sizeof(participante), 1, arqPAR);
							fseek(arqPAR, 0, SEEK_CUR);
							printf(G"\n\n\t\t\t\t\t\tEXCLUSAO FEITA COM SUCESSO"B);
							Sleep(700);
							break;
						case 78:
							return;
					}
					
				}
				if(strcmp(user, participante.usuario) != 0){
					flag = 1;
					printf(R"\n\t\t\t\tUSUARIO NAO CADASTRADO NO SISTEMA, TENTE NOVAMENTE!"B);
					Sleep(200);
				}
			}while(flag == 1);
			break;
		case 7:
			organizar_cads();
			break;
	}
	fclose(arqPAR);
}

void organizar_cads(){
	gamers participante;
	FILE *arq = fopen("cad_participantes.dat", "r+b");
	FILE *arq2 = fopen("cad_participantes.bak", "a+b");
	
	if((arq == NULL) || (arq2 == NULL)){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");
		return;
	}
	while(fread(&participante, sizeof(participante), 1, arq) && participante.deletado != '*'){
		fwrite(&participante, sizeof(participante), 1, arq2);
	}
	fclose(arq);
	fclose(arq2);
	remove("cad_participantes.dat");
	rename("cad_participantes.bak", "cad_participantes.dat");	
}	
//------ SOBRE O EVENTO ---------------------------------------------------------------------------------------------------------------------------------------
void sobre(){
	system("cls");
	printf("\n\t\t\t\t\t\t\tSOBRE O EVENTO");
	printf("\nออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ"); 
	printf("\n\t%c EVENTO DE GAMES PARA A COMUNIDADE DE ALUNOS DA UCB E ENTORNO.\n", 254);
	printf("\n\t%c QUALQUER ALUNO DE QUALQUER CURSO PODE PARTICIPAR.\n", 254);
	printf("\n\t%c OS PATROCINADORES PODEM SE CADASTRAR E ANALISAREMOS O CADASTRO.\n", 254);
	printf("\n\t%c AS EMPRESAS QUE DESEJAM SER ORGANIZADORAS DO EVENTO DEVEM FAZER O CADASTRO.\n", 254);
	printf("\n\t%c O EVENTO CONTERA 6 STANDS DE JOGOS, SENDO ELES: RPG, FPS, LUTA, CORRIDA, AVENTURA E ESPORTES.\n", 254);
	printf("\n\t%c CADA PARTICIPANTE PODE ESCOLHER APENAS UM STAND.\n", 254);
	printf("\n\t");
	system("pause");
	main();
}

void estatisticas(){
	char op, nome_maior_pat[50], tecla;
	int totalR = 0, totalF = 0, totalE = 0, totalA = 0, totalL = 0, totalC = 0, total = 0, pos = 10, totalS[6], i = 0, maior;
	int max = 120;//Maximo de participantes no evento
	float p1, p2, p3, p4, p5, p6, maior_patrocinio = 0;
	gamers participante;
	FILE *arq = fopen("cad_participantes.dat", "rb");
	FILE *arqPAT = fopen("cad_patrocinadores.dat", "rb");
	
	for(i = 0; i < 6; i++)
		totalS[i] = 0;
	while(fread(&participante, sizeof(participante), 1, arq)){
		total++;
		switch(participante.stand){
			case 'F': 
				totalF++;
				break;
			case 'R': 
				totalR++;
				break;
			case 'E': 
				totalE++;
				break;
			case 'A': 
				totalA++;
				break;
			case 'L': 
				totalL++;
				break;
			case 'C': 
				totalC++;
				break;					
		}
	}
	do{
		do{
			system("cls");
			gotoxy(45,9);printf("ษอออออออออออออออออออออออออออออออออออออออ%c", 187);
			gotoxy(45,10);printf("บ    %c TOTAL DE PARTICIPANTES           บ", 254);
			gotoxy(45,11);printf("ฬอออออออออออออออออออออออออออออออออออออออ%c", 185);
			gotoxy(45,12);printf("บ    %c PORCENTAGEM DE CADA STAND        บ", 254);
			gotoxy(45,13);printf("ฬอออออออออออออออออออออออออออออออออออออออ%c", 185);
			gotoxy(45,14);printf("บ    %c MAIOR ADESAO                     บ", 254);
			gotoxy(45,15);printf("ฬอออออออออออออออออออออออออออออออออออออออ%c", 185);
			gotoxy(45,16);printf("บ    %c STAND COM MAIOR PATROCINIO       บ", 254);
			gotoxy(45,17);printf("ฬอออออออออออออออออออออออออออออออออออออออ%c", 185);
			gotoxy(45,18);printf("บ    %c VOLTAR AO MENU DO ORGANIZADOR    บ", 254);
			gotoxy(45,19);printf("ศอออออออออออออออออออออออออออออออออออออออผ");
			gotoxy(82, pos);printf(R"%c"B, 174);
			tecla = getch();
			if(tecla == DOWN)
				pos += 2;
			if(tecla == UP)
				pos -= 2;
			if(pos > 18)
				pos = 10;
			if(pos < 10)
				pos = 18;
		}while(tecla != ENTER);
		switch(pos){
			case 10:
				system("cls");
				printf("\n\tษอออออออออออออออออออออออออออออออออออออออออออ%c", 187);
				printf("\n\tบ   TOTAL DE PARTICIPANTES DO EVENTO %c  %d   บ", 175, total);
				printf("\n\tศอออออออออออออออออออออออออออออออออออออออออออผ\n\t");
				system("pause");
				break;
			case 12:
				system("cls");
				printf("\n\tษอออออออออหอออออออออออออออ%c", 187);
				printf("\n\tบGENERO   บ PORCENTAGEM   บ");
				printf("\n\tฬอออออออออฮอออออออออออออออ%c", 185);
				printf("\n\tบRPG      บ %8.2f      บ", p1 = (totalR*100)/max);
				printf("\n\tฬอออออออออฮอออออออออออออออ%c", 185);
				printf("\n\tบFPS      บ %8.2f      บ", p2 = (totalF*100)/max);
				printf("\n\tฬอออออออออฮอออออออออออออออ%c", 185);
				printf("\n\tบESPORTES บ %8.2f      บ", p3 = (totalE*100)/max);
				printf("\n\tฬอออออออออฮอออออออออออออออ%c", 185);
				printf("\n\tบAVENTURA บ %8.2f      บ", p4 = (totalA*100)/max);
				printf("\n\tฬอออออออออฮอออออออออออออออ%c", 185);
				printf("\n\tบCORRIDA  บ %8.2f      บ", p5 = (totalC*100)/max);
				printf("\n\tฬอออออออออฮอออออออออออออออ%c", 185);
				printf("\n\tบLUTA     บ %8.2f      บ", p6 = (totalL*100)/max);
				printf("\n\tศอออออออออสอออออออออออออออผ\n\t");
				system("pause");
				break;
			case 14:
				system("cls");
				printf("\n\tษอออออออออออออออออออออออออออออออออ%c", 187);
				printf("\n\tบ %c MAIS RENTAVEL %c               บ", 254, 175);
				printf("\n\tฬอออออออออออออออออออออออออออออออออ%c", 185);
				printf("\n\tบ %c N. DE PARTICIPANTES %c         บ", 254, 175);
				printf("\n\tศอออออออออออออออออออออออออออออออออผ");
				if(totalR > totalF && totalR > totalE && totalR > totalA && totalR > totalC && totalR > totalL){
					gotoxy(29,3);printf("RPG");
					gotoxy(35,5);printf("%d",totalR);
				}else if(totalF > totalR && totalF > totalE && totalF > totalA && totalF > totalC && totalF > totalL){
					gotoxy(29,3);printf("FPS");
					gotoxy(35,5);printf("%d",totalF);
				}else if(totalE > totalF && totalE > totalR && totalE > totalA && totalE > totalC && totalE > totalL){
					gotoxy(29,3);printf("ESPORTE");
					gotoxy(35,5);printf("%d",totalE);
				}else if(totalA > totalF && totalA > totalE && totalA > totalR && totalA > totalC && totalA > totalL){
					gotoxy(29,3);printf("AVENTURA");
					gotoxy(35,5);printf("%d", totalA);
				}else if(totalC > totalF && totalC > totalE && totalC > totalR && totalC > totalA && totalC > totalL){
					gotoxy(29,3);printf("CORRIDA");
					gotoxy(35,5);printf("%d",totalC);
				}else if(totalL > totalF && totalL > totalE && totalL > totalA && totalL > totalC && totalL > totalR){
					gotoxy(29,3);printf("LUTA");
					gotoxy(35,5);printf("%d",totalL);
				}
				printf("\n\n\t");	
				system("pause");				
				break;
			case 16:
				maior_patrocinio = maior_pat(nome_maior_pat);
				system("cls");
				printf("\n\tษออออออออออออออออออออออออออออออ%c", 187);
				printf("\n\tบ   %c PATROCINIO %c             บ", 254, 175);
				printf("\n\tฬออออออออออออออออออออออออออออออ%c", 185);
				printf("\n\tบ   %c STAND %c                  บ", 254, 175);
				printf("\n\tศออออออออออออออออออออออออออออออผ");
				gotoxy(28,3);printf("%.2f", maior_patrocinio);
				gotoxy(23,5);printf("%s", nome_maior_pat);
				printf("\n\n\t");
				system("pause");
				break;
			case 18:
				system("cls");
				menu_organizadores();
				break;			
		}
	}while(pos != 18);
}

float maior_pat(char nome[]){
	FILE *arqPAT = fopen("cad_patrocinadores.dat", "rb");
	patrocinadores empresa;
	float patF = 0, patR = 0, patC = 0, patL = 0, patE = 0, patA = 0, maior = 0;
	
	while(fread(&empresa,sizeof(empresa), 1, arqPAT)){
		if(empresa.stand_escolhido == 'F')
			patF+=empresa.quantia;
		else if(empresa.stand_escolhido == 'R')	
			patR+=empresa.quantia;
		else if(empresa.stand_escolhido == 'E')	
			patE+=empresa.quantia;
		else if(empresa.stand_escolhido == 'A')
			patA+=empresa.quantia;
		else if(empresa.stand_escolhido == 'L')	
			patL+=empresa.quantia;
		else if(empresa.stand_escolhido == 'C')		
			patC+=empresa.quantia;
	}
	if((patF > patR) && (patF > patA) && (patF > patE) && (patF > patC) && (patF > patL)){
		maior = patF;
		strcpy(nome, "FPS");
	}else if(patR > patF && patR > patA && patR > patE && patR > patC && patR > patL){
		maior = patR;
		strcpy(nome, "RPG");
	}else if(patE > patR && patE > patA && patE > patF && patE > patC && patE > patL){
		maior = patE;
		strcpy(nome, "ESPORTE");
	}else if(patA > patR && patA > patF && patA > patE && patA > patC && patA > patL){
		maior = patA;
		strcpy(nome, "AVENTURA");
	}else if(patL > patR && patL > patA && patL > patE && patL > patC && patL > patF){
		maior = patL;
		strcpy(nome, "LUTA");
	}else if(patC > patR && patC> patA && patC > patE && patC > patF && patC > patL){
		maior = patC;
		strcpy(nome, "CORRIDA");
	}
	return maior;
}
