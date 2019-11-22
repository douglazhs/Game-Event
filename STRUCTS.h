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
