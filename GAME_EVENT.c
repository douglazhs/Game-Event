//Programa de controle de stands de jogos em um evento de video games.
//Autores: Douglas Henrique de Souza Pereira|Joใo Victor de Souza Portella.
//Matrํculas: UC19107076|UC19100100.
//Institui็ใo de Ensino: Universidade Cat๓lica de Brasํlia.
//Data: 02 de Novembro de 2019.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct{
	char nome[100];
	char email[150];
	int senha;
}organizadores;

typedef struct{
	char nome[100];
	char stand;
	char usuario[50];
}gamers;

typedef struct{
	char nome[100];
	int email[150];
	float quantia;
}patrocinadores;

//Menus
void menu_participantes();
void menu_organizadores();
void menu_patrocinadores();
//Cadastros
void cad_empresas();
void cad_participantes();
void cad_patrocinadores();
//Possibilidades no menu de participantes
void stands();
void sobre();
//Possibilidades no menu de organizadores
void backup();
void restore();
void vagas();
//Alteracao de dados de participantes
void acessar_dados();
void alterar_dados();
//Funcoes de validacao
void leValidaUsuario(char []);
char leValidaStand();
void leValidaNome(char []);

int main(void){
	char escolha;

	system("cls");
	do{
		printf("\n\t\t\t\t\t UCBG - UNIVERSIDADE CATOLICA DE BRASILIA GAMES");
		printf("\n\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t\t\t\t%c O QUE VOCE E?\n", 254);
		printf("\n\t\t\t\t\t\t\t%c [1]PARTICIPANTE", 254);
		printf("\n\t\t\t\t\t\t\t%c [2]EMPRESA", 254);
		printf("\n\t\t\t\t\t\t\t%c [3]PATROCINADOR", 254);
		printf("\n\t\t\t\t\t\t\t%c [4]SOBRE O EVENTO", 254);
		printf("\n\t\t\t\t\t\t\t%c [0]SAIR DO PROGRAMA", 254);
		printf("\n\n\t\t\t\t\t          %c APERTE A RESPECTIVA OPCAO %c ", 254, 175);
		escolha = getch();
		escolha = toupper(escolha);
		if(escolha != '1' && escolha != '2' && escolha != '3' && escolha != '4' && escolha != '0'){
			printf("\n\t\t\t\t\t\t\tCARACTER INVALIDO!");
			Sleep(800);
		}
		system("cls");
	}while(escolha != '1' && escolha != '2' && escolha != '3' && escolha != '4'&& escolha != '0');

	switch(escolha){
		case '1':
			menu_participantes();
			break;
		case '2':
			menu_organizadores();
			break;
		case '3':
			menu_patrocinadores();
			break;
		case '4':
			sobre();
			break;
	}
}

void menu_participantes(){
	int opcao;
	
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
		printf("                                  บ                   %c 0[FECHAR]                     บ\n", 254);
		printf("                                  บ                                                   บ\n");
		printf("                                  ศอออออออออออออออออออออออออออออออออออออออออออออออออออ%c", 188);
		printf("\n\t\t\t\t\t\t\t%c OPCAO %c ", 254, 175);
		opcao = getch();
		if(opcao != '1' && opcao != '2' && opcao != '3' && opcao != '4' && opcao != '5' && opcao != '6'&&opcao != '0'){
			printf("\n\t\t\t\t\t\t      OPCAO INVALIDA!");
			Sleep(800);
		}
		switch(opcao){
			case '1':
				cad_participantes();
				break;
			case '2':
				acessar_dados();
				break;
			case '3':
				alterar_dados();
				break;
			case '4':
				stands();
				break;
			case '5':
				main();
				break;
		}
	}while(opcao != '0');
}

void menu_organizadores(){
	int opcao, tentativa, flag;
	char resp;
	FILE *arqEMP;
	organizadores empresas;

	arqEMP = fopen("organizadores.dat", "ab+");
	printf("\n\t%c DIGITE [S] SE JA E CADASTRADO E QUALQUER OUTRA TECLA SE NAO E %c ", 254, 175);
	resp = getchar();
	resp = toupper(resp);
	if(resp == 'S'){
		while(fread(&empresas, sizeof(empresas), 1, arqEMP) && flag == 1);
			do{
				printf("\n\t%c DIGITE A SENHA DE ACESSO %c ", 254, 175);
				scanf("%d", &tentativa);
				if(tentativa != empresas.senha){
					printf("\n\t\t\t\t\t\t    SENHA INVALIDA!");
					flag = 1;
					Sleep(800);
				}
			}while(empresas.senha != tentativa);
	}else
		cad_empresas();
	do{
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\n                                  ษอออออออออออออออออ MENU ORGANIZADOR ออออออออออออออออ%c\n", 187);
		printf("                                  บ                                                   บ\n");
		printf("                                  บ                   %c 1[VAGAS]                      บ\n", 254);
		printf("                                  บ                   %c 2[BACKUP DE DADOS]            บ\n", 254);
		printf("                                  บ                   %c 3[RESTAURAR DADOS]            บ\n", 254);
		printf("                                  บ                   %c 4[VOLTAR AO INICIO]           บ\n", 254);
		printf("                                  บ                   %c 0[FECHAR]                     บ\n", 254);
		printf("                                  บ                                                   บ\n");
		printf("                                  ศอออออออออออออออออออออออออออออออออออออออออออออออออออ%c", 188);
		printf("\n\t\t\t\t\t\t\t%c OPCAO %c", 254, 175);
		opcao = getch();
		if(opcao != '1' && opcao != '2' && opcao != '3' && opcao != '4' && opcao != '0'){
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
				printf("\n");
				backup();
				printf("\n\tPRESSIONE UMA TECLA PARA CONTINUAR...");
				getch();
				break;
			case '3':
				system("cls");
				printf("\n\t\t\t\t\t\t\tRESTAURAR DADOS");
				printf("\n");
				restore();
				printf("\n\tPRESSIONE UMA TECLA PARA CONTINUAR...");
				getch();
				break;
			case '4':
				main();
				break;
		}
	}while(opcao != '0');
	fclose(arqEMP);
}

void menu_patrocinadores() {
	printf("NOME DA EMPRESA>> ");
}

void stands(){
	system("cls");
	printf("\n\t\t\t\t\t\t\tSTANDS\n");
	printf("\n\t\t\t\t\tษออออออออออออหออออออออออออหออออออออออออ%c", 187);
	printf("\n\t\t\t\t\tบ    FPS     บ    RPG     บ    ESP     บ");
	printf("\n\t\t\t\t\tบ            บ            บ            บ");
	printf("\n\t\t\t\t\tบ  vagas =   บ  vagas =   บ  vagas =   บ");
	printf("\n\t\t\t\t\tฬออออออออออออฮออออออออออออฮออออออออออออ%c", 185);
	printf("\n\t\t\t\t\tบ    AVE     บ    LUT     บ    COR     บ");
	printf("\n\t\t\t\t\tบ            บ            บ            บ");
	printf("\n\t\t\t\t\tบ  total =   บ  vagas =   บ  vagas =   บ");
	printf("\n\t\t\t\t\tศออออออออออออสออออออออออออสออออออออออออผ");
	printf("\n\n\t\t\t\t\t PRESSIONE UMA TECLA PARA CONTINUAR...");
	getch();
}

void backup(){

}

void restore(){

}

void vagas(){
	system("cls");
	printf("\n\t\t\t\t\t\t\tVAGAS");
	printf("\n");
	printf("\n\tPRESSIONE UMA TECLA PARA CONTINUAR...");
	getch();
}

void sobre(){
	system("cls");
	printf("\n\t\t\t\t\t\t\tSOBRE O EVENTO\n");
	printf("\n\t%c EVENTO DE GAMES PARA A COMUNIDADE DE ALUNOS DA UCB E ENTORNO.\n", 254);
	printf("\n\t%c QUALQUER ALUNO DE QUALQUER CURSO PODE PARTICIPAR.\n", 254);
	printf("\n\t%c OS PATROCINADORES PODEM SE CADASTRAR E ANALISAREMOS O CADASTRO.\n", 254);
	printf("\n\t%c AS EMPRESAS QUE DESEJAM SER ORGANIZADORAS DO EVENTO DEVEM FAZER O CADASTRO.\n", 254);
	printf("\n\t%c O EVENTO CONTERม 6 STANDS DE JOGOS, SENDO ELES: RPG, FPS, LUTA, CORRIDA, AVENTURA E ESPORTES.\n", 254);
	printf("\n\t%c CADA PARTICIPANTE PODE ESCOLHER APENAS UM STAND.\n", 254);
	printf("\n\t%c ", 254);
	printf("\n\n\tPRESSIONE UMA TECLA PARA CONTINUAR...");
	getch();
	main();
}

void cad_participantes(){
	gamers participante;
	FILE *arqPAR;
	char user[50], nome[100];
	int flag = 0, cheio = 0, total_stands[6];

	system("cls");
	arqPAR = fopen("cadastro_participantes.dat", "ab+");
	do{
		cheio = 0;
		printf("\n\t\t\t\t\t\t\tCADASTRAR");
		printf("\n");
		printf("\n\t%c BEM-VINDO, GAMER. DIGITE SEU NOME %c ", 254, 175);
		fflush(stdin);
		leValidaNome(participante.nome);
		printf("\n\t%c OLA, %s.", 254, participante.nome);
		leValidaUsuario(user);
		strcpy(participante.usuario, user);
		participante.stand = leValidaStand();
		switch(participante.stand){
			case 'R':
				total_stands[0]++;
				break;
			case 'F':
				total_stands[1]++;
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
		fclose(arqPAR);
		printf("\n\tCADASTRO REALIZADO COM SUCESSO!");
		Sleep(1000);
		menu_participantes();
	}while(cheio == 1);
}

void cad_empresas(){
	FILE *arqEMP;
	char email[150];
	organizadores empresa;
	
	arqEMP = fopen("organizadores.dat", "ab");
	printf("\n\t%c NOME DA EMPRESA ORGANIZADORA %c ", 254, 175);
	fflush(stdin);
	gets(empresa.nome);
	empresa.senha = 1414;
	printf("\n\t%c SENHA DE ACESSO PARA INFORMACOES DO EVENTO %c %d", 254, 175, empresa.senha);
	fwrite(&empresa, sizeof(empresa), 1, arqEMP);
	fclose(arqEMP);
	getch();
}

void cad_patrocinadores(){

	FILE *arqPAT;
}

void acessar_dados(){
	FILE *arq;
	gamers participante;
	int flag = 0;
	char user[50];
	
	arq = fopen("cadastro_participantes.dat", "rb");
	system("cls");
	do{
		flag = 0;
		printf("\n\t%c DIGITE SEU USUARIO %c ", 254, 175);
		fflush(stdin);
		gets(user);
		while(fread(&participante, sizeof(participante), 1, arq)){
			if(strcmp(user, participante.usuario) == 0){
				printf("\n\t%c USUARIO %c %s", 254, 175, participante.usuario);
				printf("\n\t%c NOME %c %s", 254, 175, participante.nome);
				printf("\n\t%c TIPO DE STAND %c %c", 254, 175, participante.stand);
				getch();
			}else{
				flag = 1;
			}
		}
		if(flag == 1)
			printf("\n\tUSUARIO NAO CADASTRADO NO SISTEMA, TENTE NOVAMENTE!");
	}while(flag == 1);
	fclose(arq);
}

void alterar_dados(){
	int op, flag = 0;
	char stand, user[50];
	FILE *arqPAR;
	gamers participante;
	
	arqPAR = fopen("cadastro_participantes.dat", "ab+");
	do{
		flag = 0;
		printf("\n\t%c DIGITE SEU USUARIO %c ", 254, 175);
		fflush(stdin);
		gets(user);
		while(fread(&participante, sizeof(participante), 1, arqPAR)){
			if(strcmp(user, participante.usuario) == 0){
				printf("\n\t%c USUARIO %c %s", 254, 175, participante.usuario);
				printf("\n\t%c NOME %c %s", 254, 175, participante.nome);
				printf("\n\t%c TIPO DE STAND %c %c", 254, 175, participante.stand);
				getch();
			}else{
				flag = 1;
			}
		}
		if(flag == 1)
			printf("\n\tUSUARIO NAO CADASTRADO NO SISTEMA, TENTE NOVAMENTE!");
	}while(flag == 1);
	printf("\n\n\t%c ESCOLHA O QUE DESEJA ALTERAR\n", 254, 175);
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
	fwrite(&participante, sizeof(participante), 1, arqPAR);
	fclose(arqPAR);
}

void leValidaUsuario(char user[]){
	gamers participante;
	FILE *arq;
	int flag = 0;
	
	arq = fopen("cadastro_participantes.dat", "rb");
	do{
		flag = 0;
		printf("\n\t%c USUARIO %c ", 254, 175);
		fflush(stdin);
		leValidaNome(user);
		while(fread(&participante, sizeof(participante), 1, arq)){
			if(strcmp(user, participante.usuario) == 0){
				flag = 1;
			}
		}
		if(flag == 1){
			printf("\n\tUSUARIO JA CADASTRADO NO SISTEMA, TENTE NOVAMENTE!");
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
	do{
		fflush(stdin);
		gets(nome);
		if(strlen(nome) == 0){
			printf("\n\tDIGITE ALGO!");
		}
	}while(strlen(nome) == 0);
}
	
