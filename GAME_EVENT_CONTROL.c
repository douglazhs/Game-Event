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
void cad_participantes();
void cad_patrocinadores();
//Possibilidades no menu de participantes
void stands();
void sobre();
//----- Funcoes para acessar dados ----------------------------------------------------------------------------------------------------------------------------
gamers acessar_dados_participante();
patrocinadores acessar_dados_patrocinador();
//----- Mostrar dados ------------------------------------------------------------------------------------------------------------------------------------------- 
void mostra_patrocinador();
void mostra_participantes();
void mostra_participante(gamers);
//----- Funcoes para alterar dados ------------------------------------------------------------------------------------------------------------------------------- 
void alterar_dados_participante();
void excluir_cadastro();
void organizar_cads();
//----- Funcoes de validacao ------------------------------------------------------------------------------------------------------------------------------------- 
void leValidaUsuario(char []);
char leValidaStand();
void leValidaNome(char []);
void leValidaSenha();
void leValidaEmailOrg(char[]);
void leValidaEmailPat(char []);
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------


int main(void){
	char escolha;

	system("cls");
	do{
		printf("\n\t\t\t\t\t UCBG - UNIVERSIDADE CATOLICA DE BRASILIA GAMES\n\n");
		printf("\t\t\t\t\t          @@@                  @@@\n");
		printf("\t\t\t\t\t        @@@@@@               @@@@@@\n");      
		printf("\t\t\t\t\t      @@@@ @@@@@@@@@@@@@@@@@@@@ @@@@@\n");  
		printf("\t\t\t\t\t     @@@@@   @@@@@@@@@@@@@@@@@@@   @@@@\n");   
		printf("\t\t\t\t\t     @@   @@   @@@@@@@@@@@@@@@  @@  @@@\n");
		printf("\t\t\t\t\t     @@@@@   @@@@@@@   @@@@@@@@   @@@@@\n");   
		printf("\t\t\t\t\t     @@@@@@@@@    @@@@@@@    @@@@@@@@@\n");   
		printf("\t\t\t\t\t    @@@@@@@@@@    @@@@@@@    @@@@@@@@@@\n");  
		printf("\t\t\t\t\t    @@@@@@@@  @@@@       @@@@  @@@@@@@@\n");  
		printf("\t\t\t\t\t    @@@@@@@                     @@@@@@@\n");  
		printf("\t\t\t\t\t     @@@@@                       @@@@@\n");  
		printf("\n\t\t\t\t\t\t     %c O QUE VOCE E?\n", 254);
		printf("\n\t\t\t\t\t\t     %c [1]PARTICIPANTE", 254);
		printf("\n\t\t\t\t\t\t     %c [2]EMPRESA", 254);
		printf("\n\t\t\t\t\t\t     %c [3]SOBRE O EVENTO", 254);
		printf("\n\t\t\t\t\t\t     %c [4]PATROCINADOR", 254);
		printf("\n\t\t\t\t\t\t     %c [0]SAIR DO PROGRAMA", 254);
		printf("\n\n\t\t\t\t\t         %c APERTE A RESPECTIVA OPCAO %c ", 254, 175);
		escolha = getch();
		escolha = toupper(escolha);
		if(escolha != '1' && escolha != '2' && escolha != '3' && escolha != '4'){
			printf("\n\t\t\t\t\t\t\tCARACTER INVALIDO!");
			Sleep(800);
		}
		system("cls");
	}while(escolha != '1' && escolha != '2' && escolha != '3' && escolha != '4');
	switch(escolha){
		case '1': menu_participantes(); break;
		case '2': menu_organizadores(); break;
		case '3': sobre(); break;
		case '4': menu_patrocinadores(); break;
	}
}

void menu_participantes(){
	int opcao, pos;
	
	do{
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\n                                  ษอออออออออออออออออ MENU PARTICIPANTE อออออออออออออออ%c\n", 187);
		printf("                                  บ                                                   บ\n");
		printf("                                  บ                   %c 1[CADASTRAR]                  บ\n", 254);
		printf("                                  บ                   %c 2[ACESSAR]                    บ\n", 254);
		printf("                                  บ                   %c 3[ALTERAR DADOS]              บ\n", 254);
		printf("                                  บ                   %c 4[STANDS]                     บ\n", 254);
		printf("                                  บ                   %c 5[VOLTAR AO INICIO]           บ\n", 254);
		printf("                                  บ                                                   บ\n");
		printf("                                  ศอออออออออออออออออออออออออออออออออออออออออออออออออออ%c", 188);
		printf("\n\t\t\t\t\t\t\t%c OPCAO %c ", 254, 175);
		opcao = getch();
		if(opcao != '1' && opcao != '2' && opcao != '3' && opcao != '4' && opcao != '5' && opcao != '6'){
			printf("\n\t\t\t\t\t\t      OPCAO INVALIDA!");
			Sleep(800);
		}
		switch(opcao){
			case '1': cad_participantes(); break;
			case '2': acessar_dados_participante(); break;
			case '3': alterar_dados_participante(); break;
			case '4': stands(); break;
			case '5': main(); break;
		}
	}while(opcao != '5');
}

void menu_organizadores(){
	int opcao, flag;
	char resp;

	printf("\n\t%c DIGITE [S] SE JA E CADASTRADO E QUALQUER OUTRA TECLA SE NAO E %c ", 254, 175);
	fflush(stdin);
	resp = getchar();
	resp = toupper(resp);
	if(resp == 'S'){
		leValidaSenha();
	}else
		cad_empresas();
	do{
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\n                                  ษอออออออออออออออออ MENU ORGANIZADOR ออออออออออออออออ%c\n", 187);
		printf("                                  บ                                                   บ\n");
		printf("                                  บ                   %c 1[ACESSO A INFORMACOES]       บ\n", 254);
		printf("                                  บ                   %c 2[STANDS]                     บ\n", 254);
	    printf("                                  บ                   %c 3[PATROCINIO TOTAL]           บ\n", 254);
		printf("                                  บ                   %c 4[ORGANIZAR CADASTROS]        บ\n", 254);
		printf("                                  บ                   %c 5[DADOS ESTATISTICOS]         บ\n", 254);
		printf("                                  บ                   %c 6[VOLTAR AO INICIO]           บ\n", 254);
		printf("                                  บ                                                   บ\n");
		printf("                                  ศอออออออออออออออออออออออออออออออออออออออออออออออออออ%c", 188);
		printf("\n\t\t\t\t\t\t\t%c OPCAO %c", 254, 175);
		opcao = getch();
		if(opcao != '1' && opcao != '2' && opcao != '3' && opcao != '4' && opcao != '5' && opcao != '6'){
			printf("\n\t\t\t\t\t\t      OPCAO INVALIDA!");
			Sleep(800);
		}
		switch(opcao){
			case '1': mostra_participantes(); break;
			case '2': stands(); break;
			case '3': break;
			case '4': excluir_cadastro(); break;
			case '5': break;
			case '6': main(); break;	
		}
	}while(opcao != '6');
}

void stands(){
	system("cls");
	printf("\n\t\t\t\t\tษออออออออออออหออออออออออออหออออออออออออ%c", 187);
	printf("\n\t\t\t\t\tบ    FPS     บ    RPG     บ    ESP     บ");
	printf("\n\t\t\t\t\tบ            บ            บ            บ");
	printf("\n\t\t\t\t\tบ  vagas =   บ  vagas =   บ  vagas =   บ");
	printf("\n\t\t\t\t\tฬออออออออออออฮออออออออออออฮออออออออออออ%c", 185);
	printf("\n\t\t\t\t\tบ    AVE     บ    LUT     บ    COR     บ");
	printf("\n\t\t\t\t\tบ            บ            บ            บ");
	printf("\n\t\t\t\t\tบ  total =   บ  vagas =   บ  vagas =   บ");
	printf("\n\t\t\t\t\tศออออออออออออสออออออออออออสออออออออออออผ");
	printf("\n\n\t");
	system("pause");
}

void sobre(){
	system("cls");
	printf("\n\t\t\t\t\t\t\tSOBRE O EVENTO\n");
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

void cad_participantes(){
	char user[50], nome[100];
	int flag = 0, cheio = 0, total_stands[6], aux = 0, total = 0, i;
	gamers participante;
	FILE *arqPAR = fopen("cadastro_participantes.dat", "ab+");
	FILE *stands = fopen("total_stands.dat", "ab+");

	system("cls");
	if(arqPAR == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");	
		return;
	}
	for(i = 0; i < 6; i++){
		//aux[i] = 0;
	}
	fread(&total_stands, sizeof(total_stands), 1, stands);
	do{
		cheio = 0;
		printf("\n\t\t\t\t\t\t\tCADASTRAR");
		printf("\n");
		printf("\n\t%c BEM-VINDO, GAMER. DIGITE SEU NOME %c ", 254, 175);
		leValidaNome(participante.nome);
		printf("\n\t%c OLA, %s.", 254, participante.nome);
		leValidaUsuario(user);
		strcpy(participante.usuario, user);
		participante.stand = leValidaStand();
		participante.deletado = ' ';
		switch(participante.stand){
			case 'R':
				aux++;
				total_stands[0] += aux;
				printf("\n\tTOTAL: %d", total_stands[0]);
				break;
			case 'F':
				total_stands[1]++;
				printf("\n\tTOTAL: %d", total_stands[1]);
				break;
			case 'C':
				total_stands[2]++;
				break;
			case 'L':
				total_stands[3]++;
				break;
			case 'E':
				total_stands[4]++;
				break;
			case 'A':
				total_stands[5]++;
				break;
		}
		fwrite(&participante, sizeof(participante), 1, arqPAR);
		fwrite(&total_stands, sizeof(total_stands), 1, stands);
		fclose(arqPAR);
		fclose(stands);
		printf("\n\tCADASTRO REALIZADO COM SUCESSO!");
		Sleep(1000);
		menu_participantes();
	}while(cheio == 1);
}

void menu_patrocinadores(){
	int opcao;
	do{
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\n                                  ษอออออออออออออออออ MENU PATROCINADOR ออออออออออออออออ%c\n", 187);		
		printf("                                  บ                                                    บ\n");
		printf("                                  บ                   %c 1[CADASTRAR]                   บ\n", 254);
		printf("                                  บ                   %c 2[ACESSO A INFORMACOES]        บ\n", 254);
		printf("                                  บ                   %c 3[VOLTAR AO INICIO]            บ\n", 254);
		printf("                                  บ                                                    บ\n");
		printf("                                  ศอออออออออออออออออออออออออออออออออออออออออออออออออออ%c", 188);
		printf("\n\t\t\t\t\t\t\t%c OPCAO %c", 254, 175);
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

void cad_empresas(){
	FILE *arqEMP;
	char email[150];
	int senha;
	organizadores empresa;
	
	srand(time(NULL));
	arqEMP = fopen("organizadores.dat", "ab");
	if(arqEMP == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");	
		return;
	}
	printf("\n\t%c NOME DA EMPRESA ORGANIZADORA %c ", 254, 175);
	fflush(stdin);
	leValidaNome(empresa.nome);
	leValidaEmailOrg(email);
	strcpy(empresa.email, email);
	senha = 1000 + (rand() % 1000);
	empresa.senha = senha;
	printf("\n\n\t%c SENHA DE ACESSO PARA INFORMACOES DO EVENTO %c %d", 254, 175, empresa.senha);
	fwrite(&empresa, sizeof(empresa), 1, arqEMP);
	fclose(arqEMP);
	printf("\n\n\t");
	system("pause");
}

gamers acessar_dados_participante(){
	FILE *arq;
	gamers participante;
	int flag = 0, pos = 0;
	char user[50];
	
	arq = fopen("cadastro_participantes.dat", "rb");
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
				break;
			}
		}
		if(strcmp(user, participante.usuario) != 0){
			flag = 1;
			printf("\n\tUSUARIO NAO CADASTRADO NO SISTEMA, TENTE NOVAMENTE!");
		}
	}while(flag == 1);
	fclose(arq);
	return participante;
}

patrocinadores acessar_dados_patrocinador(){
	char email[150];
	int flag = 0;
	patrocinadores empresa;
	FILE *arqPAT = fopen("cad_patrocinadores", "rb");
	do{
		flag = 0;
		printf("\n\t%cENDERECO DE EMAIL %c ");
		fflush(stdin);
		gets(email);
		while(fread(&empresa, sizeof(empresa), 1, arqPAT)){
			if(strcmp(email, empresa.email) == 0){
				mostra_patrocinador(empresa);
			}
			if(strcmp(email, empresa.email) > 0){
				flag = 1;
				printf("\n\tENDERECO DE EMAIL NAO CADASTRADO NO SISTEMA! TENTE NOVAMENTE!");
			}
		}
	}while(flag == 1);
	return empresa;
}

void mostra_patrocinador(patrocinadores empresa){
	printf("\n\t%c NOME %c ", 254, 175, empresa.nome);
	printf("\n\t%c EMAIL %c ", 254, 175, empresa.email);
	printf("\n\t%c STAND %c", 254, 175, empresa.stand_escolhido);
	printf("\n\t %c PATROCINIO %c ", 254, 175, empresa.quantia);
	printf("\n\n\t");
	system("pause");
}

void cad_patrocinadores(){
	char email[150];
	patrocinadores empresa;
	FILE *arqPAT = fopen("cad_patrocinadores", "ab+");
	
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

void mostra_participante(gamers participante){
	printf("\n\t%c USUARIO %c %s", 254, 175, participante.usuario);
	printf("\n\t%c NOME %c %s", 254, 175, participante.nome);
	printf("\n\t%c TIPO DE STAND %c %c\n", 254, 175, participante.stand);
	printf("\n\t");
	system("pause");
}

void alterar_dados_participante(){
	int op, flag = 0;
	char stand, user[50];
	gamers participante;
	FILE *arqPAR = fopen("cadastro_participantes.dat", "ab+");
	
	if(arqPAR == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");	
		return;
	}
	participante = acessar_dados_participante();
	printf("\n\t%s", participante.nome);
	printf("\n\n\t%c ESCOLHA O QUE DESEJA ALTERAR\n", 254, 175);
	printf("\n\t%c [1]STAND", 254);
	printf("\n\t%c [2]USUARIO", 254);
	printf("\n\t%c OPCAO %c ", 254, 175);
	scanf("%d", &op);
	switch(op){
		case 1: participante.stand = leValidaStand(); break;
		case 2:
			leValidaUsuario(user);
			strcpy(participante.usuario, user);
			break;
	}
	fseek(arqPAR, -sizeof(participante), SEEK_CUR);
	fwrite(&participante, sizeof(participante), 1, arqPAR);
	fseek(arqPAR, 0, SEEK_CUR);
	fclose(arqPAR);
}

void mostra_participantes(){
	gamers participante;
	FILE *arq = fopen("cadastro_participantes.dat", "rb");
	
	if(arq == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");
		return;
	}
	system("cls");
	printf("\n\t\t\t\t\t     USUARIOS CADASTRADOS NO SISTEMA");
	while((fread(&participante, sizeof(participante), 1, arq)) && (participante.deletado != '*')){
		printf("\n\t%c USUARIO %c %s", 254, 175, participante.usuario);
		printf("\n\t%c NOME %c %s", 254, 175, participante.nome);
		printf("\n\t%c TIPO DE STAND %c %c", 254, 175, participante.stand);
		printf("\n");
	}
	printf("\n\t");
	system("\n\tpause");
	fclose(arq);
}

void excluir_cadastro(){
	int flag = 0;
	char user[50], resp;
	gamers participante;
	FILE  *arqPAR = fopen("cadastro_participantes.dat", "ab+");
	
	if(arqPAR == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");
		return;
	}
	system("cls");
	printf("\n\t\t\t\t\t        EXCLUSAO DE CADASTROS");
	participante = acessar_dados_participante(); 
	printf("\n\n\t%c TEM CERTEZA QUE DESEJA FAZER A EXCLUSAO?", 254);
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
	FILE *arq = fopen("cadastro_participantes.dat", "rb");
	FILE *arq2 = fopen("cadastro_participantes.bak", "ab");
	
	if ((arq == NULL) || (arq2 == NULL)) {
		printf("\n\tERRO AO ABRIR O ARQUIVO!");
		return;
	}
	while(fread(&participante, sizeof(participante), 1, arq)){
		if(participante.deletado != '*')
			fwrite(&participante, sizeof(participante), 1, arq2);
	}
	remove("cadastro_participantes.dat");
	rename("cadastro_participantes.bak", "cadastro_participantes.dat");	
	fclose(arq);
	fclose(arq2);
}	

//Funcoes de validacao

void leValidaUsuario(char user[]){
	gamers participante;
	FILE *arq;
	int flag = 0;
	
	arq = fopen("cadastro_participantes.dat", "ab+");
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
	do{
		stands();
		printf("\n\n\t%c ESCOLHA O STAND DE JOGO QUE DESEJA PARTICIPAR %c ", 254, 175);
		fflush(stdin);
		participante.stand = getchar();
		participante.stand = toupper(participante.stand);
		if(participante.stand != 'R' && participante.stand != 'F' && participante.stand != 'A' && participante.stand != 'E' && participante.stand != 'L' && participante.stand != 'C'){
            printf("\n\t\t\t\t\t\t    OPCAO INVALIDA!");
            Sleep(800);
		}
	}while(participante.stand != 'R' && participante.stand != 'F' && participante.stand != 'A' && participante.stand != 'E' && participante.stand != 'L' && participante.stand != 'C');
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
	FILE *arqEMP = fopen("organizadores.dat", "rb");
	
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
				printf("\n\t\t\t\t\t\t    SENHA INVALIDA!");
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
	FILE *arq = fopen("organizadores.dat", "rb");
	
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


