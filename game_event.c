//Programa de controle de stands de jogos em um evento de video games.
//Autores: Douglas Henrique de Souza Pereira|João Victor de Souza Portella.
//Matrículas: UC19107076|UC19100100.
//Instituição de Ensino: Universidade Católica de Brasília.
//Data: 02 de Novembro de 2019.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
	char tipo_stand;
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
int cad_empresas();
void cad_participantes(Stands);
void cad_patrocinadores();
void stands(Stands);
void backup();
void restore();
void vagas();
void sobre();
void leValidaEmail();

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
	Stands tipo;
	do{
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\n                                           MENU PARTICIPANTE\n");
		printf("                                          ³                                   ³\n");
		printf("                                          ³           #1[CADASTRAR]           ³\n");
		printf("                                          ³           #2[STANDS]              ³\n");
		printf("                                          ³           #3[SOBRE O EVENTO]      ³\n");
		printf("                                          ³           #0[FECHAR]              ³\n");
		printf("                                          ³                                   ³\n");
		printf("                                          ");
		printf("\n\t\t\t\t\t\t\t#OPCAO>> ");
		opcao = getch();
		if(opcao != '1' && opcao != '2' && opcao != '3' && opcao != '0'){
			printf("\n\t\t\t\t\t\t    OPCAO INVALIDA!");
			Sleep(800);
		}
		switch(opcao){
			case '1':
				cad_participantes(tipo);
				break;
			case '2':
				stands(tipo);
				break;
			case '3':
				sobre();
				break;		
		}
	}while(opcao != '0');
}

void menu_organizadores(){
	int opcao, tentativa;
	Stands total;
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
		printf("                                          ");
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
				printf("\n");
				backup();
				printf("PRESSIONE UMA TECLA PARA CONTINUAR...");
				getch();
				break;
			case '3':
				system("cls");
				printf("\n\t\t\t\t\t\t\tRESTAURAR DADOS");
				printf("\n");
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

void stands(Stands tipo){
	system("cls");
	printf("\n\t\t\t\t\t\t\tSTANDS");
	printf("\nPRESSIONE UMA TECLA PARA CONTINUAR...");
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
	printf("PRESSIONE UMA TECLA PARA CONTINUAR...");
	getch();
}

void sobre(){
	system("cls");
	printf("\n\t\t\t\t\t\t\tSOBRE O EVENTO");
	printf("\n");
	printf("PRESSIONE UMA TECLA PARA CONTINUAR...");
	getch();
}

void cad_participantes(Stands tipo){
	gamers participante;
	FILE *arqPAR;
	char email[150];
	int flag = 0,cheio = 0;
	
	system("cls");
	arqPAR = fopen("cadastro_partcipante.dat", "ab+");
	do{
		printf("\n\t\t\t\t\t\t\tCADASTRAR");
		printf("\n");
		printf("\nBEM-VINDO, GAMER. DIGITE SEU NOME>> ");
		fflush(stdin);
		gets(participante.nome);
		while(fread(&participante, sizeof(participante), 1, arqPAR)){
			system("cls");
			printf("\nOLA %s", participante.nome, " GAMER");
			do{
				printf("\nENDERECO DE E-MAIL>> ");
				fflush(stdin);
				gets(email);
				if(strcmp(email, participante.email) == 0){
					printf("\nE-MAIL JA CADASTRADO NO SISTEMA, TENTE NOVAMENTE!");
					flag = 1;
				}
			}while(flag == 1);
		}
		strcpy(participante.email, email);
		do{
			stands(tipo);
			printf("\nESCOLHA O STAND DE JOGO QUE DESEJA PARTICIPAR>> ");
			getch (participante.tipo_stand);
			participante.tipo_stand = toupper(participante.tipo_stand);
			switch(participante.tipo_stand){
				case 'R':
					if(tipo.totalRPG < 10)
						tipo.totalRPG++;
					else{
						printf("\nLIMITE DE VAGAS ATINGIDO!");
						Sleep(500);
						cheio = 1;	
					}
					break;
				case 'F':
					if(tipo.totalFPS < 10)
						tipo.totalFPS++;
					else{
						printf("\nLIMITE DE VAGAS ATINGIDO!");
						Sleep(500);
						cheio = 1;	
					}	
					break;
				case 'C':
					if(tipo.totalCOR < 10)
						tipo.totalCOR++;
					else{
						printf("\nLIMITE DE VAGAS ATINGIDO!");
						Sleep(500);
						cheio = 1;
					}
					break;
				case 'L':
					if(tipo.totalLUT < 10)
						tipo.totalLUT++;
					else{
						printf("\nLIMITE DE VAGAS ATINGIDO!");
						Sleep(500);
						cheio = 1;
					}
					break;
				case 'E':
					if(tipo.totalESP < 10)
						tipo.totalESP++;
					else{
						printf("\nLIMITE DE VAGAS ATINGIDO!");
						Sleep(500);
						cheio = 1;
					}
					break;
				case 'A':
					if(tipo.totalAVE < 10)
						tipo.totalAVE++;
					else{
						printf("\nLIMITE DE VAGAS ATINGIDO PARA O ESTILO AVENTURA ATINGIDO!");
						Sleep(500);
						cheio = 1;	
					}
					break;						
			}
		}while(cheio == 1);
		fwrite(&participante, sizeof(participante), 1, arqPAR);
		fclose(arqPAR);
		printf("\nCADASTRO REALIZADO COM SUCESSO!");
		Sleep(500);
		menu_participantes();
	}while(tipo.totalRPG <= 10);	
}

int cad_empresas(){
	FILE *arqEMP;
	organizadores empresa;
	int senha_cadastrada;
	printf("\nNOME DA EMPRESA ORGANIZADORA>>>>>>>>>>>>>>>> ");
	fflush(stdin);
	gets(empresa.nome);
	printf("\nE-MAIL>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> ");
	fflush(stdin);
	gets(empresa.email);
	printf("\nSENHA DE ACESSO PARA INFORMACOES DO EVENTO>> %d", senha_cadastrada);
	getch();
	return senha_cadastrada;
}

void cad_patrocinadores(){
	FILE *arqPAT;
}

void leValidaEmail(){
	FILE *arqPAR;
	int flag = 0;
	gamers participante;
	char email[150];
	
	arqPAR = fopen("cadastro_partcipante.dat", "ab+");
	while(fread(&participante, sizeof(participante), 1, arqPAR)){
			do{
				printf("\nENDERE�O DE E-MAIL>> ");
				fflush(stdin);
				gets(email);
				if(strcmp(email, participante.email) > 0){
					printf("\nE-MAIL J� CADASTRADO NO SISTEMA, TENTE NOVAMENTE!");
					flag = 1;
				}
			}while(flag == 1);
		strcpy(participante.email, email);
	}
	fwrite(&participante, sizeof(participante), 1, arqPAR);
	fclose(arqPAR);
}
