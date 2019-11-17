//Programa de controle de stands de jogos em um evento de video games.
//Autores: Douglas Henrique de Souza Pereira|Joao Victor de Souza Portella.
//Matriculas: UC19107076|UC19100100.
//Instituicao de Ensino: Universidade Catolica de Brasilia.
//Data: 02 de Novembro de 2019.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>

typedef struct{
	char nome[100];
	char email[150];
	int senha;
}organizadores;

typedef struct{
	char nome[100];
	char stand;
	char usuario[50];
	char stand_patrocinador;
	char deletado;
}gamers;

typedef struct{
	char nome[100];
	char email[150];
	float quantia;
	char stand_escolhido;
}patrocinadores;

//----- Menus --------------------------------------------------------------------------------------------------------------------------------------------------
void menu_participantes();
void menu_organizadores();
void menu_patrocinadores();
//----- Cadastros -----------------------------------------------------------------------------------------------------------------------------------------------
void cad_empresas();
void cad_participantes(int []);
void cad_patrocinadores();
//Possibilidades no menu de participantes
void stands();
void sobre();
//----- Funcoes para acessar dados ----------------------------------------------------------------------------------------------------------------------------
gamers acessar_dados_participante();
patrocinadores acessar_dados_patrocinador();
//----- Mostrar dados ------------------------------------------------------------------------------------------------------------------------------------------- 
void mostra_patrocinador(patrocinadores);
void mostra_participantes();
void mostra_participante(gamers);
void mostra_patrocinio();
//----- Funcoes para alterar dados ------------------------------------------------------------------------------------------------------------------------------- 
void alterar_dados_participante();
void excluir_cadastro_participante();
void organizar_cads();
//----- Funcoes de validacao ------------------------------------------------------------------------------------------------------------------------------------- 
void leValidaUsuario(char []);
char leValidaStand();
void leValidaNome(char []);
void leValidaSenha();
void leValidaEmailOrg(char[]);
void leValidaEmailPat(char []);
int verifica_limite(int);
//------ Estatisticas -----------------------------------------------------------------------------------------------------------------------------------------------------
void estatisticas();
void copia_nome(char [], char);
//------ MENU PRINCIPAL ----------------------------------------------------------------------------------------------------------------------------------------------
int main(void){
	char escolha;

	system("cls");
	do{
		printf("\n\t\t\t\t\tUCBG - UNIVERSIDADE CATOLICA DE BRASILIA GAMES\n\n");
		printf("\t\t\t\t\t          @@@                  @@@\n");
		printf("\t\t\t\t\t        @@@@@@               @@@@@@\n");      
		printf("\t\t\t\t\t      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");  
		printf("\t\t\t\t\t     @@@@@   @@@@@@@@@@@@@@@@@@@   @@@@\n");   
		printf("\t\t\t\t\t     @@   @@   @@@@@@@@@@@@@@   @@   @@\n");
		printf("\t\t\t\t\t     @@@@@   @@@@@@@   @@@@@@@@   @@@@@\n");   
		printf("\t\t\t\t\t     @@@@@@@@@    @@@@@@@    @@@@@@@@@@\n");   
		printf("\t\t\t\t\t    @@@@@@@@@@    @@@@@@@    @@@@@@@@@@\n");  
		printf("\t\t\t\t\t    @@@@@@@@  @@@@       @@@@  @@@@@@@@\n");  
		printf("\t\t\t\t\t    @@@@@@@                     @@@@@@@\n");  
		printf("\t\t\t\t\t     @@@@@                       @@@@@\n");
		printf("ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
		printf("\n\t\t\t\t\t\t     %c O QUE VOCE E?", 254);
		printf("\n\t\t\t\t\t\tษอออออออออออออออออออออออออออ%c", 187);
		printf("\n\t\t\t\t\t\tบ    1 %c PARTICIPANTE       บ", 254);
		printf("\n\t\t\t\t\t\tฬอออออออออออออออออออออออออออ%c", 185);
		printf("\n\t\t\t\t\t\tบ    2 %c EMPRESA            บ", 254);
		printf("\n\t\t\t\t\t\tฬอออออออออออออออออออออออออออ%c", 185);
		printf("\n\t\t\t\t\t\tบ    3 %c SOBRE O EVENTO     บ", 254);
		printf("\n\t\t\t\t\t\tฬอออออออออออออออออออออออออออ%c", 185);
		printf("\n\t\t\t\t\t\tบ    4 %c PATROCINADOR       บ", 254);
		printf("\n\t\t\t\t\t\tฬอออออออออออออออออออออออออออ%c", 185);
		printf("\n\t\t\t\t\t\tบ    0 %c SAIR DO PROGRAMA   บ", 254);
		printf("\n\t\t\t\t\t\tศอออออออออออออออออออออออออออผ");
		printf("\n\n\t\t\t\t\t        %c APERTE A RESPECTIVA OPCAO %c ", 254, 175);
		escolha = getch();
		escolha = toupper(escolha);
		if(escolha != '1' && escolha != '2' && escolha != '3' && escolha != '4' && escolha != '0'){
			printf("\n\t\t\t\t\t\t    CARACTER INVALIDO!");
			Sleep(800);
		}
		system("cls");
	}while(escolha != '1' && escolha != '2' && escolha != '3' && escolha != '4' && escolha != '0');
	switch(escolha){
		case '1': menu_participantes(); break;
		case '2': menu_organizadores(); break;
		case '3': sobre(); break;
		case '4': menu_patrocinadores(); break;
	}
}
// ------ MENU PARTICIPANTES ----------------------------------------------------------------------------------------------------------------------------------------------

void menu_participantes(){
	int opcao, pos, total_stands[6];
	
	do{
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\n\t\t\t\t\t\tษอออออออออออออออออออออออออออ%c", 187);
		printf("\n\t\t\t\t\t\tบ    1 %c CADASTRAR          บ", 254);
		printf("\n\t\t\t\t\t\tฬอออออออออออออออออออออออออออ%c", 185);
		printf("\n\t\t\t\t\t\tบ    2 %c ACESSAR            บ", 254);
		printf("\n\t\t\t\t\t\tฬอออออออออออออออออออออออออออ%c", 185);
		printf("\n\t\t\t\t\t\tบ    3 %c ALTERAR DADOS      บ", 254);
		printf("\n\t\t\t\t\t\tฬอออออออออออออออออออออออออออ%c", 185);
		printf("\n\t\t\t\t\t\tบ    4 %c STANDS             บ", 254);
		printf("\n\t\t\t\t\t\tฬอออออออออออออออออออออออออออ%c", 185);
		printf("\n\t\t\t\t\t\tบ    5 %c VOLTAR AO INICIO   บ", 254);
		printf("\n\t\t\t\t\t\tศอออออออออออออออออออออออออออผ");
		printf("\n\t\t\t\t\t\t\t  %c OPCAO %c ", 254, 175);
		opcao = getch();
		if(opcao != '1' && opcao != '2' && opcao != '3' && opcao != '4' && opcao != '5'){
			printf("\n\t\t\t\t\t\t      OPCAO INVALIDA!");
			Sleep(800);
		}
		switch(opcao){
			case '1': cad_participantes(total_stands); break;
			case '2': acessar_dados_participante(); break;
			case '3': alterar_dados_participante(); break;
			case '4': stands(); break;
			case '5': main(); break;
		}
	}while(opcao != '5');
}
// ------ MENU ORGANIZADORES ----------------------------------------------------------------------------------------------------------------------------------------------
void menu_organizadores(){
	int opcao, flag;
	char resp;
	
//	printf("\n\t\t\t\t\t\t  VERIFICACAO DE ORGANIZADOR");
//	printf("\nออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");  
//	printf("\n\n\t%c DIGITE [S] SE JA E CADASTRADO E QUALQUER OUTRA TECLA SE NAO E %c ", 254, 175);
//	fflush(stdin);
//	resp = getchar();
//	resp = toupper(resp);
//	if(resp == 'S'){
//		leValidaSenha();
//	}else
//		cad_empresas();
	do{
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\n\t\t\t\t\t\tษอออออออออออออออออออออออออออ%c", 187);
		printf("\n\t\t\t\t\t\tบ   1 %c ACESSO A INFORMACOESบ", 254);
		printf("\n\t\t\t\t\t\tฬอออออออออออออออออออออออออออ%c", 185);
		printf("\n\t\t\t\t\t\tบ   2 %c STANDS              บ", 254);
		printf("\n\t\t\t\t\t\tฬอออออออออออออออออออออออออออ%c", 185);
		printf("\n\t\t\t\t\t\tบ   3 %c PATROCINIO TOTAL    บ", 254);
		printf("\n\t\t\t\t\t\tฬอออออออออออออออออออออออออออ%c", 185);
		printf("\n\t\t\t\t\t\tบ   4 %c ORGANIZAR CADASTROS บ", 254);
		printf("\n\t\t\t\t\t\tฬอออออออออออออออออออออออออออ%c", 185);
		printf("\n\t\t\t\t\t\tบ   5 %c DADOS ESTATISTICOS  บ", 254);
		printf("\n\t\t\t\t\t\tฬอออออออออออออออออออออออออออ%c", 185);
		printf("\n\t\t\t\t\t\tบ   6 %c VOLTAR AO INICIO    บ", 254);
		printf("\n\t\t\t\t\t\tศอออออออออออออออออออออออออออผ");
		printf("\n\t\t\t\t\t\t\t%c  OPCAO %c", 254, 175);
		opcao = getch();
		if(opcao != '1' && opcao != '2' && opcao != '3' && opcao != '4' && opcao != '5' && opcao != '6'){
			printf("\n\t\t\t\t\t\t      OPCAO INVALIDA!");
			Sleep(800);
		}
		switch(opcao){
			case '1': mostra_participantes(); break;
			case '2': stands(); break;
			case '3': mostra_patrocinio(); break;
			case '4': excluir_cadastro_participante(); break;
			case '5': estatisticas(); break;
			case '6': main(); break;	
		}
	}while(opcao != '6');
}
// ------ MENU PATROCINADORES ----------------------------------------------------------------------------------------------------------------------------------------------
void menu_patrocinadores(){
	int opcao;
	do{
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\n\t\t\t\t\t\tษอออออออออออออออออออออออออออ%c", 187);
		printf("\n\t\t\t\t\t\tบ   1 %c CADASTRAR           บ", 254);
		printf("\n\t\t\t\t\t\tฬอออออออออออออออออออออออออออ%c", 185);
		printf("\n\t\t\t\t\t\tบ   2 %c ACESSO A INFORMACOESบ", 254);
		printf("\n\t\t\t\t\t\tฬอออออออออออออออออออออออออออ%c", 185);
		printf("\n\t\t\t\t\t\tบ   3 %c VOLTAR AO INICIO    บ", 254);
		printf("\n\t\t\t\t\t\tศอออออออออออออออออออออออออออผ");
		printf("\n\t\t\t\t\t\t\t  %c OPCAO %c", 254, 175);
		opcao = getch();
		if(opcao != '1' && opcao != '2' && opcao != '3' && opcao != '4' && opcao != '5' && opcao != '0'){
			printf("\n\t\t\t\t\t\t      OPCAO INVALIDA!");
			Sleep(800);
		}
		switch(opcao){
			case '1': cad_patrocinadores(); break;
			case '2': acessar_dados_patrocinador(); break;
			case '3': main(); break;	
		}
	}while(opcao != '3');
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
	system("cls");
	do{
		flag = 0;
		rewind(arq);
		printf("\n\t%c USUARIO %c ", 254, 175);
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
			printf("\n\tUSUARIO NAO CADASTRADO NO SISTEMA, TENTE NOVAMENTE!");
		}
	}while(flag == 1);
	fclose(arq);
}

patrocinadores acessar_dados_patrocinador(){
	char email[150];
	int flag = 0;
	patrocinadores empresa;
	FILE *arqPAT = fopen("cad_patrocinadores.dat", "rb");
	system("cls");
	do{
		flag = 0;
		rewind(arqPAT);
		printf("\n\t%c ENDERECO DE EMAIL %c ", 254, 175);
		fflush(stdin);
		gets(email);
		while(fread(&empresa, sizeof(empresa), 1, arqPAT)){
			if(strcmp(email, empresa.email) == 0){
				mostra_patrocinador(empresa);
				return empresa;
			}
		}
		if(strcmp(email, empresa.email) > 0){
			flag = 1;
			printf("\n\tENDERECO DE EMAIL NAO CADASTRADO NO SISTEMA! TENTE NOVAMENTE!");
		}
	}while(flag == 1);
	fclose(arqPAT);
}
//------- MOSTRA DADOS -----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void mostra_patrocinador(patrocinadores empresa){
	char nome[50];
	printf("\n\t%c NOME %c %s", 254, 175, empresa.nome);
	printf("\n\t%c EMAIL %c %s", 254, 175, empresa.email);
	copia_nome(nome, empresa.stand_escolhido);
	printf("\n\t%c STAND %c %s", 254, 175, nome);
	printf("\n\t%c PATROCINIO %c R$%.2f", 254, 175, empresa.quantia);
	printf("\n\n\t");
	system("pause");
}

void mostra_participante(gamers participante){
	char nome[50];
	printf("\n\t%c USUARIO %c %s", 254, 175, participante.usuario);
	printf("\n\t%c NOME %c %s", 254, 175, participante.nome);
	copia_nome(nome, participante.stand);
	printf("\n\t%c TIPO DE STAND %c %s\n", 254, 175, nome);
	printf("\n\t");
	system("pause");
}

void mostra_participantes(){
	char nome[50];
	gamers participante;
	FILE *arq = fopen("cad_participantes.dat", "rb");
	
	if(arq == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");
		return;
	}
	system("cls");
	printf("\n\t\t\t\t\t     USUARIOS CADASTRADOS NO SISTEMA");
	while((fread(&participante, sizeof(participante), 1, arq)) && (participante.deletado != '*')){
		printf("\n\t%c USUARIO %c %s", 254, 175, participante.usuario);
		printf("\n\t%c NOME %c %s", 254, 175, participante.nome);
		copia_nome(nome, participante.stand);
		printf("\n\t%c TIPO DE STAND %c %s", 254, 175, nome);
		printf("\n");
	}
	printf("\n\t");
	system("\n\tpause");
	fclose(arq);
}

void mostra_patrocinio(){
	float pat_total = 0;
	patrocinadores empresa;
	FILE *arq = fopen("cad_patrocinadores.dat", "rb");
	
	system("cls");
	printf("\n\t\t\t\t\t\t\tPATROCINIOS\n");
	while(fread(&empresa, sizeof(empresa), 1, arq)){
		printf("\n\t%c NOME %c %s", 254, 175, empresa.nome);
		printf("\t\tPATROCINIO %c R$%.2f", 175, empresa.quantia);
		pat_total += empresa.quantia;
	}
	printf("\n\n\t%c PATROCINIO TOTAL %c R$%.2f", 254, 175, pat_total);
	printf("\n\n\t");
	system("pause");
	fclose(arq);
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
	printf("\n\t%c NOME DA EMPRESA %c ", 254, 175);
	fflush(stdin);
	leValidaNome(empresa.nome);
	leValidaEmailPat(email);
	strcpy(empresa.email, email);
	empresa.stand_escolhido = leValidaStand();
	printf("\n\t%c PATROCINIO %c ", 254, 175);
	scanf("%f", &empresa.quantia);
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
	printf("\n\t\t\t\t\t\t\tCADASTRAR");
	printf("\nออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
	printf("\n");
	printf("\n\t%c BEM-VINDO, GAMER. DIGITE SEU NOME %c ", 254, 175);
	leValidaNome(participante.nome);
	printf("\n\t%c OLA, %s.", 254, participante.nome);
	leValidaUsuario(user);
	strcpy(participante.usuario, user);
	participante.stand = leValidaStand();
	participante.deletado = ' ';
	fwrite(&participante, sizeof(participante), 1, arqPAR);
	fclose(arqPAR);
	printf("\n\tCADASTRO REALIZADO COM SUCESSO!");
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
	printf("\n\t%c SENHA DE ACESSO PARA INFORMACOES DO EVENTO %c %d", 254, 175, empresa.senha);
	fwrite(&empresa, sizeof(empresa), 1, arqEMP);
	fclose(arqEMP);
	printf("\n\n\t");
	system("pause");
}
//------- ALTERACAO DE DADOS -------------------------------------------------------------------------------------------------------------------------------------------------------------
void alterar_dados_participante(){
	int op, flag = 0;
	char stand, user[50];
	gamers participante;
	FILE *arqPAR = fopen("cad_participantes.dat", "ab+");
	
	if(arqPAR == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");	
		return;
	}
	system("cls");
	do{
		flag = 0;
		rewind(arqPAR);
		printf("\n\t%c USUARIO %c ", 254, 175);
		fflush(stdin);
		gets(user);
		while(fread(&participante, sizeof(participante), 1, arqPAR) && participante.deletado != '*'){
			if(strcmp(user, participante.usuario) == 0){
				mostra_participante(participante);
				printf("\n\t%c ESCOLHA O QUE DESEJA ALTERAR\n", 254, 175);
				printf("\n\t%c [1]STAND", 254);
				printf("\n\t%c [2]USUARIO", 254);
				printf("\n\t%c OPCAO %c ", 254, 175);
				scanf("%d", &op);
				switch(op){
					case 1: 
						participante.stand = leValidaStand();
						break;
					case 2:
						leValidaUsuario(user);
						strcpy(participante.usuario, user);
						break;
				}
				fseek(arqPAR, -sizeof(participante), SEEK_CUR);
				fwrite(&participante, sizeof(participante), 1, arqPAR);
				fseek(arqPAR, 0, SEEK_CUR);
			}
		}
		if(strcmp(user, participante.usuario) != 0){
			flag = 1;
			printf("\n\tUSUARIO NAO CADASTRADO NO SISTEMA, TENTE NOVAMENTE!");
		}
	}while(flag == 1);
	fclose(arqPAR);
}

//------ EXCLUIR CADASTRO DE PARTICIPANTE ---------------------------------------------------------------------------------------------------------------------------------------
void excluir_cadastro_participante(){
	int flag = 0;
	char user[50], resp;
	gamers participante;
	FILE  *arqPAR = fopen("cad_participantes.dat", "ab+");
	
	if(arqPAR == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");
		return;
	}
	system("cls");
	printf("\n\t\t\t\t\t        EXCLUSAO DE CADASTROS");
	printf("\nออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ"); 
	participante = acessar_dados_participante(); 
	printf("\n\t%c TEM CERTEZA QUE DESEJA FAZER A EXCLUSAO?", 254);
	printf("\n\t%c [S][N] %c ", 254, 175);
	resp = getch();
	resp = toupper(resp);
	if(resp == 'S'){
		participante.deletado = '*';
		fseek(arqPAR, -sizeof(participante), SEEK_CUR);
		fwrite(&participante, sizeof(participante), 1, arqPAR);
		fseek(arqPAR, 0, SEEK_CUR);
		organizar_cads();	
		printf("\n\n\tEXCLUSAO FEITA COM SUCESSO");
		Sleep(1000);
	}
	fclose(arqPAR);
}

void organizar_cads(){
	gamers participante;
	FILE *arq = fopen("cad_participantes.dat", "rb");
	FILE *arq2 = fopen("cad_participantes.bak", "ab");
	
	if ((arq == NULL) || (arq2 == NULL)) {
		printf("\n\tERRO AO ABRIR O ARQUIVO!");
		return;
	}
	while(fread(&participante, sizeof(participante), 1, arq)){
		if(participante.deletado != '*')
			fwrite(&participante, sizeof(participante), 1, arq2);
	}
	remove("cad_participantes.dat");
	rename("cad_participantes.bak", "cadastro_participantes.dat");	
	fclose(arq);
	fclose(arq2);
}	
//------ FUNCOES DE VALIDACAO --------------------------------------------------------------------------------------------------------------------------------------------------
void leValidaUsuario(char user[]){
	gamers participante;
	FILE *arq;
	int flag = 0;
	
	arq = fopen("cad_participantes.dat", "ab+");
	if(arq == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");
		return;
	}
	do{
		flag = 0;
		rewind(arq);
		printf("\n\t%c USUARIO %c ", 254, 175);
		fflush(stdin);
		gets(user);
		while(fread(&participante, sizeof(participante), 1, arq) && flag == 0){	
			if(strcmp(user, participante.usuario) == 0){
				printf("\n\tUSUARIO JA CADASTRADO NO SISTEMA, TENTE NOVAMENTE!");
				flag = 1;
			}
		}
	}while(flag == 1);
	fclose(arq);
}

char leValidaStand(){
	gamers participante;
	int flag = 0;
	int totalR = 0, totalF = 0, totalE = 0, totalA = 0, totalL = 0, totalC = 0;
	FILE *arq = fopen("cad_participantes.dat", "rb");
	
	while(fread(&participante, sizeof(participante), 1, arq)){
		switch(participante.stand){
			case 'F': totalF++; break;
			case 'R': totalR++; break;
			case 'E': totalE++; break;
			case 'A': totalA++; break;
			case 'L': totalL++; break;
			case 'C': totalC++; break;					
		}
	}
	do{
		flag = 0;
		system("cls");
		stands();
		printf("\n\n\t%c ESCOLHA O STAND DE JOGO QUE DESEJA PARTICIPAR %c ", 254, 175);
		fflush(stdin);
		participante.stand = getchar();
		participante.stand = toupper(participante.stand);
		if(participante.stand != 'R' && participante.stand != 'F' && participante.stand != 'A' && participante.stand != 'E' && participante.stand != 'L' && participante.stand != 'C'){
            printf("\n\t\t\t\t\t\t    OPCAO INVALIDA!");
            Sleep(800);
		}
		switch(participante.stand){
			case 'F': 
				if(verifica_limite(totalF) == -1)
					flag = 1;
				break;
			case 'R': 
				if(verifica_limite(totalR) == -1)
					flag = 1;
				break;
			case 'E':
				if(verifica_limite(totalE) == -1)
					flag = 1;
				break;
			case 'A': 
				if(verifica_limite(totalA) == -1)
					flag = 1;
				break;
			case 'L': 
				if(verifica_limite(totalL) == -1)
					flag = 1;
				break;
			case 'C':
				if(verifica_limite(totalC) == -1)
					flag = 1;
				break;					
		}
	}while(flag == 1);
	return participante.stand;
}

void leValidaNome(char nome[]){
	int flag = 0;
	do{
		flag = 0;
		fflush(stdin);
		gets(nome);
		if(strlen(nome) == 0){
			flag = 1;
			printf("\n\tDIGITE ALGO!");
		}
	}while(flag == 1);
}

void leValidaSenha(){
	int flag = 0, tentativa;
	organizadores empresas;
	FILE *arqEMP = fopen("cad_organizadores.dat", "rb");
	
	if(arqEMP == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");	
		return;
	}
	do{
		flag = 0;
		rewind(arqEMP);
		printf("\n\t%c DIGITE A SENHA DE ACESSO %c ", 254, 175);
		scanf("%d", &tentativa);
		while(fread(&empresas, sizeof(empresas), 1, arqEMP) && flag == 0){
			if(tentativa != empresas.senha){
				printf("\n\tSENHA INVALIDA!\n");
				flag = 1;
				Sleep(800);
			}
		}
	}while(flag == 1);
	fclose(arqEMP);
}

void leValidaEmailOrg(char email[]){
	int flag = 0;
	organizadores empresas;
	FILE *arq = fopen("cad_organizadores.dat", "rb");
	
	if(arq == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");
		return;
	}
	do{
		flag = 0;
		rewind(arq);
		printf("\n\t%c EMAIL %c ", 254, 175);
		fflush(stdin);
		gets(email);
		while(fread(&empresas, sizeof(empresas), 1, arq) && flag == 0){
			if(strcmp(email, empresas.email) == 0){
				printf("\n\tEMAIL JA CADASTRADO NO SISTEMA. TENTE NOVAMENTE!");
				flag = 1;
			}
		}
	}while(flag == 1);
}

void leValidaEmailPat(char email[]){
	int flag = 0;
	organizadores empresas;
	FILE *arq = fopen("cad_patrocinadores.dat", "rb");
	
	if(arq == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");
		return;
	}
	do{
		flag = 0;
		rewind(arq);
		printf("\n\t%c EMAIL %c ", 254, 175);
		fflush(stdin);
		gets(email);
		while(fread(&empresas, sizeof(empresas), 1, arq) && flag == 0){
			if(strcmp(email, empresas.email) == 0){
				printf("\n\tEMAIL JA CADASTRADO NO SISTEMA. TENTE NOVAMENTE!");
				flag = 1;
			}
		}
	}while(flag == 1);
	fclose(arq);
}

int verifica_limite(int total){
	if(total >= 4){
		printf("\n\tLIMITE ATINGIDO NESTE STAND!");
		getch();	
		return -1;			
	}
	return 0;
}
//------ STANDS ---------------------------------------------------------------------------------------------------------------------------------------
void stands(){
	gamers participante;
	int totalR = 0, totalF = 0, totalE = 0, totalA = 0, totalL = 0, totalC = 0;
	int m = 20;//Limite
	FILE *arq = fopen("cad_participantes.dat", "rb");
	
	while(fread(&participante, sizeof(participante), 1, arq)){
		switch(participante.stand){
			case 'F': totalF++; break;
			case 'R': totalR++; break;
			case 'E': totalE++; break;
			case 'A': totalA++; break;
			case 'L': totalL++; break;
			case 'C': totalC++; break;					
		}
	}
	system("cls");
	printf("\n\t\t\t\t\t\t\tSTANDS");
	printf("\nออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
	printf("\n\t\t\t\t\tษออออออออออออหออออออออออออหออออออออออออ%c", 187);
	printf("\n\t\t\t\t\tบ  FPS       บ  RPG       บ  ESPORTE   บ");
	printf("\n\t\t\t\t\tบ            บ            บ            บ");
	printf("\n\t\t\t\t\tบ  vagas = %dบ  vagas = %dบ  vagas = %dบ", m-totalF, m-totalR, m-totalE);
	printf("\n\t\t\t\t\tฬออออออออออออฮออออออออออออฮออออออออออออ%c", 185);
	printf("\n\t\t\t\t\tบ  AVENTURA  บ  LUTA      บ  CORRIDA   บ");
	printf("\n\t\t\t\t\tบ            บ            บ            บ");
	printf("\n\t\t\t\t\tบ  vagas = %dบ  vagas = %dบ  vagas = %dบ", m-totalA, m-totalL, m-totalC);
	printf("\n\t\t\t\t\tศออออออออออออสออออออออออออสออออออออออออผ");
	printf("\n\n\t\t\t\t\t");
	system("pause");
	fclose(arq);
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
	char op;
	int totalR = 0, totalF = 0, totalE = 0, totalA = 0, totalL = 0, totalC = 0;
	float p1, p2, p3, p4, p5, p6;
	int total = 0, max = 12;//Maximo de participantes no evento
	gamers participante;
	FILE *arq = fopen("cad_participantes.dat", "rb");
	
	while(fread(&participante, sizeof(participante), 1, arq)){
		total++;
		switch(participante.stand){
			case 'F': totalF++; break;
			case 'R': totalR++; break;
			case 'E': totalE++; break;
			case 'A': totalA++; break;
			case 'L': totalL++; break;
			case 'C': totalC++; break;					
		}
	}
	do{
	system("cls");
	printf("\n\t%c O QUE DESEJA VER?\n", 254);
	printf("\n\t%c [T]TOTAL DE PARTICIPANTES", 254); 
	printf("\n\t%c [P]PORCENTAGEM DE CADA STAND", 254);
	printf("\n\t%c [R]MAIS RENTAVEIS", 254);
	printf("\n\t%c [0]VOLTAR AO MENU DO ORGANIZADOR", 254);
	printf("\n\t%c ", 175);
	op = getch();
	op = toupper(op);
	switch(op){
		case 'T':
			system("cls");
			printf("\n\tษอออออออออออออออออออออออออออออออออออออออออออ%c", 187);
			printf("\n\tบ   TOTAL DE PARTICIPANTES DO EVENTO %c  %d   บ", 175, total);
			printf("\n\tศอออออออออออออออออออออออออออออออออออออออออออผ\n\t");
			system("pause");
			break;
		case 'P':
			
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
			printf("\n\tบLUTA     บ %8.2f      บ", p6 = (totalF*100)/max);
			printf("\n\tศอออออออออสอออออออออออออออผ\n\t");
			system("pause");
			break;
		case 'R':
			break;
		case '0':
			system("cls");
			menu_organizadores();
			break;			
	}
	}while(op != '0');
}
//------ Mostrar o nome dos stands ----------------------------------------------------------------------------------------------------------------------------------------
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
