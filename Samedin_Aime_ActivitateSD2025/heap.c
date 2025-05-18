#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

struct StructuraMasina
{
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};
typedef struct StructuraMasina Masina;

struct Heap
{
	int lungime;
	Masina* vector;
	int nrMasini;
};
typedef Heap Heap;
//citire din fisier
Masina citireDinFisier(FILE* file) {
	Masina m;
	char buffer[100];
	char sep[4] = ",;\n";
	fgets(buffer, 100, sep);
	m.id = atoi(strtok(buffer, sep));
	m.nrUsi = atoi(strtok(NULL, sep));
	m.pret = atof(strtok(NULL, sep));
	char* aux = strtok(NULL, sep);
	m.model = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
	strcpy(m.model, aux);
	aux = strtok(NULL, sep);
	m.numeSofer = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
	strcpy(m.numeSofer, aux);
	m.serie = *strtok(NULL, sep);
	return m;
}
//afisare
void afisareMasina(Masina m) {
	printf("ID: %d\n", m.id);
	printf("Numar de usi: %d\n", m.nrUsi);
	printf("Pret: %.2\n", m.pret);
	printf("Model: % s\n", m.model);
	printf("Nume sofer: %s\n", m.numeSofer);
	printf("Serie: %c\n\n", m.serie);
}
//initializare
Heap initializare(int lungime) {
	Heap h;
	h.lungime = lungime;
	h.nrMasini = 0;
	h.vector = (Masina*)malloc(sizeof(Masina) * lungime);
	return h;
}