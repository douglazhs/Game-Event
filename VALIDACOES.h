#define ENTER 13
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define ESC 27

void stands();
void stands_patrocinador();
void gotoxy(int, int);

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
		printf("\n\n\t%c USUARIO %c ", 254, 175);
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

char leValidaStandPat(){
	int posX = 48, posY = 6;
	char tecla, stand;
	
	do{
		stands_patrocinador();
		gotoxy(53,13);printf("%cESCOLHA O STAND%c",174, 175);
		gotoxy(posX, posY);printf("%c", 178);
		tecla = getch();
		if(tecla == DOWN)
			posY+=4;
		if(tecla == UP)
			posY-=4;
		if(tecla == RIGHT)
			posX+=13;
		if(tecla == LEFT)
			posX-=13;	
		if(posY > 10)
			posY=6;
		if(posY < 6)
			posY=10;
		if(posX > 74)
			posX = 48;
		if(posX < 48)
			posX = 74;				
	}while(tecla != ENTER);
	switch(posY){
		case 6:
			if(posX == 48)
				stand = 'F';
			else if(posX == 60)
				stand = 'R';
			else if(posX == 72)
				stand = 'E';
			break;
		case 10:
			if(posX == 48)
				stand = 'A';
			else if(posX == 60)
				stand = 'L';
			else if(posX == 72)
				stand = 'C';
			break;	
		}
	return stand;
}

char leValidaStand(){
	gamers participante;
	int flag = 0, posY = 6, posX = 48;
	int totalR = 0, totalF = 0, totalE = 0, totalA = 0, totalL = 0, totalC = 0;
	char tecla;
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
		do{
			stands();
			gotoxy(53,13);printf("%cESCOLHA O STAND%c",174, 175);
			gotoxy(posX, posY);printf("%c", 178);
			tecla = getch();
			if(tecla == DOWN)
				posY+=4;
			if(tecla == UP)
				posY-=4;
			if(tecla == RIGHT)
				posX+=13;
			if(tecla == LEFT)
				posX-=13;	
			if(posY > 10)
				posY=6;
			if(posY < 6)
				posY=10;
			if(posX > 74)
				posX = 48;
			if(posX < 48)
				posX = 74;				
		}while(tecla != ENTER);
		switch(posY){
			case 6:
				if(posX == 48){
					participante.stand = 'F';
					if(verifica_limite(totalF) == -1)
						flag = 1;
				}else if(posX == 60){
					participante.stand = 'R';
					if(verifica_limite(totalR) == -1)
						flag = 1;
				}else if(posX == 72){
					participante.stand = 'E';
					if(verifica_limite(totalE) == -1)
						flag = 1;
				}
				break;
			case 10:
				if(posX == 48){
					participante.stand = 'A';
					if(verifica_limite(totalA) == -1)
						flag = 1;
				}else if(posX == 60){
					participante.stand = 'L';
					if(verifica_limite(totalL) == -1)
						flag = 1;
				}else if(posX == 72){
					participante.stand = 'C';
					if(verifica_limite(totalC) == -1)
						flag = 1;
				}				
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
		system("cls");
		flag = 0;
		rewind(arqEMP);
		gotoxy(52,10);printf("ษอออออออออออออออออออ%c", 187);
		gotoxy(52,11);printf("บ SENHA:            บ");
		gotoxy(52,12);printf("ศอออออออออออออออออออผ\n\t");
		gotoxy(60,11);
		scanf("%d", &tentativa);
		while(fread(&empresas, sizeof(empresas), 1, arqEMP) && flag == 0){
			if(tentativa != empresas.senha){
				gotoxy(55,13);printf("SENHA INVALIDA!");
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


