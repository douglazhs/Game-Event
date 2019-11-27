#define R "\e[1;31m"
#define B "\x1b[0m"

void gotoxy(int, int);
void estatisticas();
void cad_participantes();
void cad_organizadores();
void cad_patrocinadores();
void cad_empresas();
void mostra_patrocinio();
void mostra_patrocinador(patrocinadores);
void mostra_participante(gamers);
void mostra_participantes();
void mostra_patrocinadores();
void alterar_dados_participante();
void excluir_cadastro_participante();
void organizar_cads();
gamers acessar_dados_participante();
patrocinadores acessar_dados_patrocinador();
void mostra_patrocinador_stand();
// ------ MENU PARTICIPANTES ----------------------------------------------------------------------------------------------------------------------------------------------
void menu_participantes(){
	int opcao, pos = 10, total_stands[6];
	char tecla;
	
	do{
		do{
			system("cls");
			printf("\n\n\n\n\n\n\n\n");
			printf("\t\t\t\t\t\t����������������������������%c", 187);
			gotoxy(49,10);printf("�    %c CADASTRAR            �", 254);
			printf("\n\t\t\t\t\t\t����������������������������%c", 185);
			gotoxy(49,12);printf("�    %c ACESSAR              �", 254);
			printf("\n\t\t\t\t\t\t����������������������������%c", 185);
			gotoxy(49,14);printf("�    %c VER PATROCINADORES   �", 254);
			printf("\n\t\t\t\t\t\t����������������������������%c", 185);
			gotoxy(49,16);printf("�    %c ALTERAR DADOS        �", 254);
			printf("\n\t\t\t\t\t\t����������������������������%c", 185);
			gotoxy(49,18);printf("�    %c STANDS               �", 254);
			printf("\n\t\t\t\t\t\t����������������������������%c", 185);
			gotoxy(49,20);printf("�    %c VOLTAR AO INICIO     �", 254);
			printf("\n\t\t\t\t\t\t���������������������������ͼ");
			gotoxy(75, pos);printf(R"%c"B, 174);
			tecla = getch();
			if(tecla == DOWN)
				pos += 2;
			if(tecla == UP)
				pos -= 2;
			if(pos > 20)
				pos = 10;
			if(pos < 10)
				pos = 20;	
		}while(tecla != ENTER);	
		switch(pos){
			case 10: cad_participantes(total_stands); break;
			case 12: acessar_dados_participante(); break;
			case 14: mostra_patrocinador_stand(); break;
			case 16: alterar_dados_participante(); break;	
			case 18: 
				stands();
				gotoxy(41,13);system("pause");
				break;
			case 20:main(); break;
		}
	}while(pos != 18);
	
}
// ------ MENU ORGANIZADORES ----------------------------------------------------------------------------------------------------------------------------------------------
void menu_organizadores(){
	int flag, pos = 5;
	char tecla;
	do{
		system("cls");
		printf("\n\t\t\t\t\t\t VERIFICACAO DE ORGANIZADOR");
		printf("\n������������������������������������������������������������������������������������������������������������������������");  
		printf("\n\t\t\t\t\t     �������������������������������%c", 187);
		printf("\n\t\t\t\t\t     �   %c SOU CADASTRADO           �", 254);
		printf("\n\t\t\t\t\t     �������������������������������%c", 185);
		printf("\n\t\t\t\t\t     �   %c DESEJO ME CADASTRAR      �", 254);
		printf("\n\t\t\t\t\t     ������������������������������ͼ");
		gotoxy(75, pos);printf(R"%c"B, 174);
		fflush(stdin);
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
			leValidaSenha();
			break;
		case 7:
			cad_empresas();
			break;
	}
	pos=11;
	do{
		do{
			system("cls");
			printf("\n\n\n\n\n\n\n\n");
			printf("\n\t\t\t\t\t\t�������������������������������%c", 187);
			gotoxy(49,11);printf("�     %c ACESSO A INFORMACOES   �", 254);
			printf("\n\t\t\t\t\t\t�������������������������������%c", 185);
			gotoxy(49,13);printf("�     %c STANDS                 �", 254);
			printf("\n\t\t\t\t\t\t�������������������������������%c", 185);
			gotoxy(49,15);printf("�     %c PATROCINIO TOTAL       �", 254);
			printf("\n\t\t\t\t\t\t�������������������������������%c", 185);
			gotoxy(49,17);printf("�     %c ORGANIZAR CADASTROS    �", 254);
			printf("\n\t\t\t\t\t\t�������������������������������%c", 185);
			gotoxy(49,19);printf("�     %c DADOS ESTATISTICOS     �", 254);
			printf("\n\t\t\t\t\t\t�������������������������������%c", 185);
			gotoxy(49,21);printf("�     %c VOLTAR AO INICIO       �", 254);
			printf("\n\t\t\t\t\t\t������������������������������ͼ");
			gotoxy(77, pos);printf(R"%c"B, 174);
			fflush(stdin);
			tecla = getch();
			if(tecla == DOWN)
				pos += 2;
			if(tecla == UP)
				pos -= 2;
			if(pos > 21)
				pos = 11;
			if(pos < 11)
				pos = 21;
		}while(tecla != ENTER);
		switch(pos){
			case 11: mostra_participantes(); break;
			case 13: 
				stands();
				gotoxy(41,13);system("pause");
				break;
			case 15: mostra_patrocinio(); break;
			case 17: excluir_cadastro_participante(); break;
			case 19: estatisticas(); break;
			case 21: main(); break;	
		}
	}while(pos != 21);
}
// ------ MENU PATROCINADORES ----------------------------------------------------------------------------------------------------------------------------------------------
void menu_patrocinadores(){
	int pos = 11;
	char tecla;
	
	do{
		do{
			system("cls");
			printf("\n\n\n\n\n\n\n\n");
			printf("\n\t\t\t\t\t\t�������������������������������%c", 187);
			gotoxy(49,11);printf("�     %c CADASTRAR              �", 254);
			printf("\n\t\t\t\t\t\t�������������������������������%c", 185);
			gotoxy(49,13);printf("�     %c ACESSO A INFORMACOES   �", 254);
			printf("\n\t\t\t\t\t\t�������������������������������%c", 185);
			gotoxy(49,15);printf("�     %c VOLTAR AO INICIO       �", 254);
			printf("\n\t\t\t\t\t\t������������������������������ͼ");
			gotoxy(78, pos);printf(R"%c"B, 174);
			tecla = getch();
			if(tecla == DOWN)
					pos += 2;
				if(tecla == UP)
					pos -= 2;
				if(pos > 15)
					pos = 11;
				if(pos < 11)
					pos = 15;
		}while(tecla != ENTER);
		switch(pos){
			case 11: cad_patrocinadores(); break;
			case 13: acessar_dados_patrocinador(); break;
			case 15: main(); break;	
		}
	}while(pos != 15);
}
