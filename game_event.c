//Programa de controle de stands de jogos em um evento de video games.
//Autores: Douglas Henrique de Souza Pereira|João Victor de Souza Portella.
//Matrículas: UC19107076|UC19100100.
//Instituição de Ensino: Universidade Católica de Brasília.
//Data: 02 de Novembro de 2019.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
	char nome[100];
	char email[100];
	int senha;
}organizadores;

typedef struct{
	char nome[100];
	char tipo_stand;
	int identidade;
}gamers;

typedef struct{
	char nome[100];
	int email;
	float quantia;
}patrocinadores;

void menu_participantes();
void menu_organizadores();
void menu_patrocinadores();
int cad_empresas();
void cad_participantes();
void cad_patrocinadores();
void stands();
void backup();
void restore();
void vagas();
void sobre();

int main(void){
	char escolha;
	do{
		printf("\n\t\t\t\t\tUCBG - UNIVERSIDADE CATOLICA DE BRASILIA GAMES");
		printf("");
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tO QUE VOCE E? [1]PARTICIPANTE/[2]EMPRESA/[3]PATROCINADOR");
		printf("\n\t\t\t\t\t      APERTE A RESPECTIVA LETRA>> ");
		escolha = getch();
		escolha = toupper(escolha);
		if(escolha != '1' && escolha != '2' && escolha != '3'){
			printf("\n\t\t\t\t\t\t  CARACTER INVALIDO!");
			Sleep(800);
		}
		system("cls");
	}while(escolha != '1' && escolha != '2' && escolha != '3');
	
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
	do{
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\n                                          ÚÄÄÄÄÄÄÄÄ MENU PARTICIPANTE ÄÄÄÄÄÄÄÄ¿\n");
		printf("                                          ³                                   ³\n");
		printf("                                          ³           #1[CADASTRAR]           ³\n");
		printf("                                          ³           #2[STANDS]              ³\n");
		printf("                                          ³           #3[SOBRE O EVENTO]      ³\n");
		printf("                                          ³           #0[FECHAR]              ³\n");
		printf("                                          ³                                   ³\n");
		printf("                                          ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		printf("\n\t\t\t\t\t\t\t#OPCAO>> ");
		opcao = getch();
		if(opcao != '1' && opcao != '2' && opcao != '3' && opcao != '0'){
			printf("\n\t\t\t\t\t\t    OPCAO INVALIDA!");
			Sleep(800);
		}
		switch(opcao){
			case '1':
				cad_participantes();
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
	int opcao, tentativa;
	int senha = cad_empresas();
	do{
		printf("\nDIGITE A SENHA DE ACESSO>> ");
		scanf("%d", &tentativa);
		printf("\n\t\t\t\t\t\t    SENHA INVALIDA!");
		Sleep(800);
	}while(senha != tentativa);
	do{
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\n                                          ÚÄÄÄÄÄÄÄÄ MENU ORGANIZADOR ÄÄÄÄÄÄÄÄ¿\n");
		printf("                                          ³                                  ³\n");
		printf("                                          ³           #1[VAGAS]              ³\n");
		printf("                                          ³           #2[BACKUP DE DADOS]    ³\n");
		printf("                                          ³           #3[RECUPERAR DADOS]    ³\n");
		printf("                                          ³           #0[FECHAR]             ³\n");
		printf("                                          ³                                  ³\n");
		printf("                                          ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
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
				printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				backup();
				printf("PRESSIONE UMA TECLA PARA CONTINUAR...");
				getch();
				break;
			case '3':
				system("cls");
				printf("\n\t\t\t\t\t\t\tRESTAURAR DADOS");
				printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				restore();
				printf("PRESSIONE UMA TECLA PARA CONTINUAR...");
				getch();
				break;		
		}
	}while(opcao != '0');
}

void menu_patrocinadores() {
	printf("NOME DA EMPRESA>> ");
}

void stands(){
	system("cls");
	printf("\n\t\t\t\t\t\t\tSTANDS");
	printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
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
	printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
	printf("PRESSIONE UMA TECLA PARA CONTINUAR...");
	getch();
}

void sobre(){
	system("cls");
	printf("\n\t\t\t\t\t\t\tSOBRE O EVENTO");
	printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
	printf("PRESSIONE UMA TECLA PARA CONTINUAR...");
	getch();
}

void cad_participantes(){
	gamers participante;
	system("cls");
	printf("\n\t\t\t\t\t\t\tCADASTRAR");
	printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
	printf("\nBEM-VINDO GAMER, DIGITE SEU NOME>> ");
	fflush(stdin);
	gets(participante.nome);
	printf("\nOLA %s,", strcat(participante.nome, " GAMER"));
	printf("\nESCOLHA O STAND DE JOGO QUE IRA PARTICIPAR>> ");
	printf("PRESSIONE UMA TECLA PARA CONTINUAR...");
	getch();
}

int cad_empresas(){
	organizadores empresa;
	int senha_cadastrada = 190190;
	printf("\nNOME DA EMPRESA ORGANIZADORA>>>>>>>>>>>>>>>> ");
	fflush(stdin);
	gets(empresa.nome);
	printf("\nE-MAIL>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> ");
	fflush(stdin);
	gets(empresa.email);
	printf("\nSENHA DE ACESSO PARA INFORMACOES DO EVENTO>> %d", senha_cadastrada);
	getch();
	return senha_cadastrada;
}

void cad_patrocinadores(){
	
}
