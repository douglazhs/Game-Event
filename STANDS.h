#define TAM 19
void gotoxy(int, int);

void stands(){
	gamers participante;
	patrocinadores empresa;
	int totalR = 0, totalF = 0, totalE = 0, totalA = 0, totalL = 0, totalC = 0;
	int m = 20, total = 0, i = 0;
	int pos1 = TAM, pos2 = TAM, pos3 = TAM, pos4 = TAM, pos5 = TAM, pos6 = TAM;
	FILE *arq = fopen("cad_participantes.dat", "rb");
	FILE *arqPAT = fopen("cad_patrocinadores.dat", "rb");
	
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
	gotoxy(35,17);printf("%c%c EMPRESAS PATROCINADORAS DOS RESPECTIVOS STANDS %c%c",175,175,174,174);
	gotoxy(5,pos1);printf("FPS");
	gotoxy(30,pos2);printf("RPG");
	gotoxy(50,pos3);printf("ESPORTE");
	gotoxy(70,pos4);printf("AVENTURA");
	gotoxy(90,pos5);printf("LUTA");
	gotoxy(110,pos6);printf("CORRIDA");
	printf("\nออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
	while(fread(&empresa, sizeof(empresa), 1, arqPAT)){
		switch(empresa.stand_escolhido){
			case 'F':
				gotoxy(5,pos1+2);printf("%c %s", 175, empresa.nome);
				pos1+=1;
				break;	
			case 'R':
				gotoxy(30,pos2+2);printf("%c %s", 175, empresa.nome);
				pos2+=1;
				break;
			case 'E':
				gotoxy(50,pos3+2);printf("%c %s", 175, empresa.nome);
				pos3+=1;
				break;
			case 'A':
				gotoxy(70,pos4+2);printf("%c %s", 175, empresa.nome);
				pos4+=1;
				break;
			case 'L':
				gotoxy(90,pos5+2);printf("%c %s", 175, empresa.nome);
				pos5+=1;
				break;
			case 'C':
				gotoxy(110,pos6+2);printf("%c %s", 175, empresa.nome);
				pos6+=1;
				break;				
		}
	}
	fclose(arq);
	fclose(arqPAT);
}

void stands_patrocinador(){
	system("cls");
	printf("\n\t\t\t\t\t\t\tSTANDS");
	printf("\nออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
	printf("\n\t\t\t\t\tษออออออออออออหออออออออออออหออออออออออออ%c", 187);
	printf("\n\t\t\t\t\tบ  FPS       บ  RPG       บ  ESPORTE   บ");
	printf("\n\t\t\t\t\tบ            บ            บ            บ");
	printf("\n\t\t\t\t\tบ            บ            บ            บ");
	printf("\n\t\t\t\t\tฬออออออออออออฮออออออออออออฮออออออออออออ%c", 185);
	printf("\n\t\t\t\t\tบ  AVENTURA  บ  LUTA      บ  CORRIDA   บ");
	printf("\n\t\t\t\t\tบ            บ            บ            บ");
	printf("\n\t\t\t\t\tบ            บ            บ            บ");
	printf("\n\t\t\t\t\tศออออออออออออสออออออออออออสออออออออออออผ");
	printf("\n\n\t\t\t\t\t");
}
