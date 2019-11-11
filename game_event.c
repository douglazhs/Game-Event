//Programa de controle de stands de jogos em um evento de video games.
//Autores: Douglas Henrique de Souza Pereira|Joรยฃo Victor de Souza Portella.
//Matrรยญculas: UC19107076|UC19100100.
//Instituiรยงรยฃo de Ensino: Universidade Catรยณlica de Brasรยญlia.
//Data: 02 de Novembro de 2019.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct{
	int totalRPG;
	int totalFPS;
	int totalESP;
	int totalCOR;
	int totalLUT;
	int totalAVE;
}Stands;

typedef struct{
	char nome[100];
	char email[150];
	int senha;
}organizadores;

typedef struct{
	char nome[100];
	char stand;
	char email[150];
}gamers;

typedef struct{
	char nome[100];
	int email[150];
	float quantia;
}patrocinadores;

void menu_participantes();
void menu_organizadores();
void menu_patrocinadores();
void cad_empresas();
void cad_participantes(Stands);
void cad_patrocinadores();
void stands(Stands);
void backup();
void restore();
void vagas();
void sobre();
void acessar();
void leValidaEmail(FILE *, char []);

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
		printf("\n\t\t\t\t\t\t\t%c [0]SAIR DO PROGRAMA", 254);
		printf("\n\n\t\t\t\t\t          %c APERTE A RESPECTIVA OPCAO %c ", 254, 175);
		escolha = getch();
		escolha = toupper(escolha);
		if(escolha != '1' && escolha != '2' && escolha != '3' && escolha != '0'){
			printf("\n\t\t\t\t\t\t\tCARACTER INVALIDO!");
			Sleep(800);
		}
		system("cls");
	}while(escolha != '1' && escolha != '2' && escolha != '3' && escolha != '0');

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
	}
}

void menu_participantes(){
	int opcao;
	Stands tipo;
	do{
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\n                                  ษอออออออออออออออออ MENU PARTICIPANTE อออออออออออออออ%c\n", 187);
		printf("                                  บ                                                   บ\n");
		printf("                                  บ                   %c 1[CADASTRAR]                  บ\n", 254);
		printf("                                  บ                   %c 2[ACESSAR]                    บ\n", 254);
		printf("                                  บ                   %c 3[STANDS]                     บ\n", 254);
		printf("                                  บ                   %c 4[SOBRE O EVENTO]             บ\n", 254);
		printf("                                  บ                   %c 5[VOLTAR AO INICIO]           บ\n", 254);
		printf("                                  บ                   %c 0[FECHAR]                     บ\n", 254);
		printf("                                  บ                                                   บ\n");
		printf("                                  ศอออออออออออออออออออออออออออออออออออออออออออออออออออ%c", 188);
		printf("\n\t\t\t\t\t\t\t%c OPCAO %c ", 254, 175);
		opcao = getch();
		if(opcao != '1' && opcao != '2' && opcao != '3' && opcao != '4' && opcao != '5' &&opcao != '0'){
			printf("\n\t\t\t\t\t\t      OPCAO INVALIDA!");
			Sleep(800);
		}
		switch(opcao){
			case '1':
				cad_participantes(tipo);
				break;
			case '2':
				acessar();
				break;
			case '3':
				stands(tipo);
				break;
			case '4':
				sobre();
			case '5':
				main();
				break;
		}
	}while(opcao != '0');
}

void menu_organizadores(){
	int opcao, tentativa, flag;
		char resp;
	Stands total;
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

void stands(Stands tipo){
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
	printf("\n\t\t\t\t\t\t\tSOBRE O EVENTO");
	printf("\n");
	printf("\n\tPRESSIONE UMA TECLA PARA CONTINUAR...");
	getch();
}

void cad_participantes(Stands tipo){
	gamers participante;
	FILE *arqPAR;
	char email[150], nome[100];
	int flag = 0,cheio = 0;

	system("cls");
	arqPAR = fopen("cadastro_partcipante.dat", "ab+");
	do{
		printf("\n\t\t\t\t\t\t\tCADASTRAR");
		printf("\n");
		printf("\n\t%c BEM-VINDO, GAMER. DIGITE SEU NOME %c ", 254, 175);
		fflush(stdin);
		gets(participante.nome);
		strcpy(nome, participante.nome);
		printf("\n\t%c OLA, %s", 254, nome, ".");
		leValidaEmail(arqPAR, &email);
		strcpy(participante.email, email);
		do{
			stands(tipo);
			printf("\n\n\t%c ESCOLHA O STAND DE JOGO QUE DESEJA PARTICIPAR %c ", 254, 175);
			fflush(stdin);
			participante.stand = getchar();
			participante.stand = toupper(participante.stand);
			if(participante.stand != 'R' && participante.stand != 'F' && participante.stand != 'A' && participante.stand != 'E' && participante.stand != 'L' && participante.stand != 'C'){
                printf("\n\t\t\t\t\t\t  OPCAO INVALIDA!");
                Sleep(800);
			}
		}while(participante.stand != 'R' && participante.stand != 'F' && participante.stand != 'A' && participante.stand != 'E' && participante.stand != 'L' && participante.stand != 'C');
			switch(participante.stand){
				case 'R':
						tipo.totalRPG++;
						printf("\n%d", tipo.totalRPG);
						getch();
					break;
				case 'F':

					break;
				case 'C':

					break;
				case 'L':

					break;
				case 'E':

					break;
				case 'A':

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
	leValidaEmail(arqEMP, email);
	strcpy(empresa.email, email);
	empresa.senha = 1414;
	printf("\n\t%c SENHA DE ACESSO PARA INFORMACOES DO EVENTO %c %d", 254, 175, empresa.senha);
	fwrite(&empresa, sizeof(empresa), 1, arqEMP);
	fclose(arqEMP);
	getch();
}

void cad_patrocinadores(){

	FILE *arqPAT;
}

void acessar(){
	FILE *arqPAR;
	gamers participante;
	int flag = 0;
	char email[150];

	arqPAR = fopen("cadastro_partcipante.dat", "rb");
	system("cls");
	do{
		printf("\n\t%c DIGITE SEU EMAIL %c ", 254, 175);
		fflush(stdin);
		gets(email);
		while(fread(&participante, sizeof(participante), 1, arqPAR)){
			if(strcmp(email, participante.email) > 0){
				printf("\n\t%c NOME %c %s", 254, 175, participante.nome);
				printf("\n\t%c TIPO DE STAND %c %c", 254, 175, participante.stand);
			}else{
				flag = 1;
			}
		}
		if(flag == 1)
			printf("\n\tE-MAIL NAO CADASTRADO NO SISTEMA, TENTE NOVAMENTE!");
		getch();
		menu_participantes();
	}while(flag == 1);
	fclose(arqPAR);
}

void leValidaEmail(FILE *arq, char email[]){
	gamers participante;
	int flag = 0;

	arq = fopen("cadastro_partcipante.dat", "rb");
	do{
		printf("\n\t%c ENDERECO DE E-MAIL %c ", 254, 175);
		fflush(stdin);
		gets(email);
		while(fread(&participante, sizeof(participante), 1, arq)){
			if(strcmp(email, participante.email) == 0){
				printf("\n\tE-MAIL JA CADASTRADO NO SISTEMA, TENTE NOVAMENTE!");
				flag = 1;
			}
		}
	}while(flag == 1);
	fclose(arq);
}
