void gotoxy(int, int);
void cad_participantes();
void cad_organizadores();
void cad_patrocinadores();
void cad_empresas();
void stands();
void stands_patrocinador();
void sobre();
void estatisticas();
void mostra_patrocinio();
void mostra_patrocinador(patrocinadores);
void mostra_participante(gamers);
void mostra_participantes();
void alterar_dados_participante();
void excluir_cadastro_participante();
void organizar_cads();
gamers acessar_dados_participante();
patrocinadores acessar_dados_patrocinador();
// ------ MENU PARTICIPANTES ----------------------------------------------------------------------------------------------------------------------------------------------
void menu_participantes(){
	int opcao, pos = 10, total_stands[6];
	char tecla;
	
	do{
		do{
			system("cls");
			printf("\n\n\n\n\n\n\n\n");
			printf("\t\t\t\t\t\tษอออออออออออออออออออออออออออ%c", 187);
			gotoxy(49,10);printf("บ    %c CADASTRAR            บ", 254);
			printf("\n\t\t\t\t\t\tฬอออออออออออออออออออออออออออ%c", 185);
			gotoxy(49,12);printf("บ    %c ACESSAR              บ", 254);
			printf("\n\t\t\t\t\t\tฬอออออออออออออออออออออออออออ%c", 185);
			gotoxy(49,14);printf("บ    %c ALTERAR DADOS        บ", 254);
			printf("\n\t\t\t\t\t\tฬอออออออออออออออออออออออออออ%c", 185);
			gotoxy(49,16);printf("บ    %c STANDS               บ", 254);
			printf("\n\t\t\t\t\t\tฬอออออออออออออออออออออออออออ%c", 185);
			gotoxy(49,18);printf("บ    %c VOLTAR AO INICIO     บ", 254);
			printf("\n\t\t\t\t\t\tศอออออออออออออออออออออออออออผ");
			gotoxy(75, pos);printf("%c", 174);
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
			case 10: cad_participantes(total_stands); break;
			case 12: acessar_dados_participante(); break;
			case 14: alterar_dados_participante(); break;
			case 16: 
					stands();
					gotoxy(41,13);system("pause");
					break;
			case 18: main(); break;
		}
	}while(pos != 18);
	
}
// ------ MENU ORGANIZADORES ----------------------------------------------------------------------------------------------------------------------------------------------
void menu_organizadores(){
	int flag, pos = 5;
	char tecla;
	do{
		system("cls");
		printf("\n\t\t\t\t\t\t  VERIFICACAO DE ORGANIZADOR");
		printf("\nออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");  
		gotoxy(5,5);printf("%c SOU CADASTRADO ", 254);
		gotoxy(5,6);printf("%c DESEJO ME CADASTRAR", 254);
		gotoxy(27, pos);printf("%c", 174);
		fflush(stdin);
		tecla = getch();
		if(tecla == DOWN)
			pos += 1;
		if(tecla == UP)
			pos -= 1;
		if(pos > 6)
			pos = 5;
		if(pos < 5)
			pos = 6;
	}while(tecla != ENTER);
	switch(pos){
		case 5:
			leValidaSenha();
			break;
		case 6:
			cad_empresas();
			break;
	}
	pos=11;
	do{
		do{
			system("cls");
			printf("\n\n\n\n\n\n\n\n");
			printf("\n\t\t\t\t\t\tษออออออออออออออออออออออออออออออ%c", 187);
			gotoxy(49,11);printf("บ     %c ACESSO A INFORMACOES   บ", 254);
			printf("\n\t\t\t\t\t\tฬออออออออออออออออออออออออออออออ%c", 185);
			gotoxy(49,13);printf("บ     %c STANDS                 บ", 254);
			printf("\n\t\t\t\t\t\tฬออออออออออออออออออออออออออออออ%c", 185);
			gotoxy(49,15);printf("บ     %c PATROCINIO TOTAL       บ", 254);
			printf("\n\t\t\t\t\t\tฬออออออออออออออออออออออออออออออ%c", 185);
			gotoxy(49,17);printf("บ     %c ORGANIZAR CADASTROS    บ", 254);
			printf("\n\t\t\t\t\t\tฬออออออออออออออออออออออออออออออ%c", 185);
			gotoxy(49,19);printf("บ     %c DADOS ESTATISTICOS     บ", 254);
			printf("\n\t\t\t\t\t\tฬออออออออออออออออออออออออออออออ%c", 185);
			gotoxy(49,21);printf("บ     %c VOLTAR AO INICIO       บ", 254);
			printf("\n\t\t\t\t\t\tศออออออออออออออออออออออออออออออผ");
			gotoxy(77, pos);printf("%c", 174);
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
			printf("\n\t\t\t\t\t\tษออออออออออออออออออออออออออออออ%c", 187);
			gotoxy(49,11);printf("บ     %c CADASTRAR              บ", 254);
			printf("\n\t\t\t\t\t\tฬออออออออออออออออออออออออออออออ%c", 185);
			gotoxy(49,13);printf("บ     %c ACESSO A INFORMACOES   บ", 254);
			printf("\n\t\t\t\t\t\tฬออออออออออออออออออออออออออออออ%c", 185);
			gotoxy(49,15);printf("บ     %c VOLTAR AO INICIO       บ", 254);
			printf("\n\t\t\t\t\t\tศออออออออออออออออออออออออออออออผ");
			gotoxy(78, pos);printf("%c", 174);
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
