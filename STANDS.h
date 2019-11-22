void stands(){
	gamers participante;
	patrocinadores empresa;
	int totalR = 0, totalF = 0, totalE = 0, totalA = 0, totalL = 0, totalC = 0;
	int m = 20;//Limite
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
	fclose(arq);
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
