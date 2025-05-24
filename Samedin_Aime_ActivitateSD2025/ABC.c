#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Casa
{
	int nr;
	char* strada;
	float pret;
};
typedef struct Casa Casa;

struct Nod
{
	Casa info;
	struct Nod* st;
	struct Nod* dr;
};
typedef struct Nod Nod;

Casa citireCasaDinFisier(FILE* file) {
	Casa c;
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);
	char* aux;
	aux = strtok(buffer, sep);
	c.nr = atoi(aux);
	aux = strtok(NULL, sep);
	c.strada = malloc(strlen(aux) + 1);
	strcpy(c.strada, aux);
	aux = strtok(NULL, sep);
	c.pret = atof(aux);
	return c;
}

void afisareCasa(Casa c) {
	printf("Nr: %d\n", c.nr);
	printf("Strada: %s\n", c.strada);
	printf("Pret: %.2f\n\n", c.pret);
}

void adugareCasaInArbor(Nod** arbore, Casa casaNoua) {
	if (!(*arbore)) {
		Nod* nou = (Nod*)malloc(sizeof(Nod));
		nou->info = casaNoua;
		nou->st = NULL;
		nou->dr = NULL;
		(*arbore) = nou;
	}
	else {
		if ((*arbore)->info.pret > casaNoua.pret) {
			adugareCasaInArbor(&((*arbore)->st), casaNoua);
		}
		else if ((*arbore)->info.pret < casaNoua.pret) {
			adugareCasaInArbor(&((*arbore)->dr), casaNoua);
		}
	}
}
Nod* citireArboreDeCase(const char* fisier) {
	FILE* file = fopen(fisier, "r");
	Nod* arbore = NULL;
	while (!feof(file)) {
		Casa c = citireCasaDinFisier(file);
		adugareCasaInArbor(&arbore, c);
	}
	fclose(file);
	return arbore;
}
void afisareInOrdine(Nod* arbore) {
	if (arbore) {
		afisareInOrdine(arbore->st);
		afisareCasa(arbore->info);
		afisareInOrdine(arbore->dr);
	}
}
void afisareIPrenOrdine(Nod* arbore) {
	if (arbore) {
		afisareCasa(arbore->info);
		afisareInPreOrdine(arbore->st);
		
		afisareInPreOrdine(arbore->dr);
	}
}
void afisareInPostOrdine(Nod* arbore) {
	if (arbore) {
		afisareInPostOrdine(arbore->st);
	
		afisareInPostOrdine(arbore->dr);
		afisareCasa(arbore->info);
	}
}
void dezalocareArbore(Nod** arbore) {
	if (*arbore) {
		dezalocareArbore((*arbore)->st);
		dezalocareArbore((*arbore)->dr);
		free((*arbore)->info.strada);
		free(*arbore);
		(*arbore) = NULL;
	}
}
int main() {



	return 0;
}