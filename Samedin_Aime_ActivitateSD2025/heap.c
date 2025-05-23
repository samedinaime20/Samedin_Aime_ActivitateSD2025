#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


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
typedef struct Heap Heap;
//citire din fisier
Masina citireDinFisier(FILE* file) {
	Masina m;
	char buffer[100];
	char sep[4] = ",;\n";
	fgets(buffer, 100, file);
	m.id = atoi(strtok(buffer, sep));
	m.nrUsi = atoi(strtok(NULL, sep));
	m.pret = atof(strtok(NULL, sep));
	char* aux;
	aux= strtok(NULL, sep);
	m.model = malloc(strlen(aux)+1);
	strcpy(m.model, aux);
	aux = strtok(NULL, sep);
	m.numeSofer = malloc(strlen(aux) + 1);
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
void filtrareHeap(Heap h, int pozNod) {
	int pozS = 2 * pozNod + 1;
	int pozD = 2 * pozNod + 2;
	int pozMax = pozNod;
	if (pozS<h.nrMasini && h.vector[pozS].pret>h.vector[pozMax].pret)
		pozMax = pozS;
	if (pozD<h.nrMasini && h.vector[pozD].pret>h.vector[pozMax].pret)
		pozMax = pozD;
	if (pozMax != pozNod) {
		Masina aux;
		aux = h.vector[pozMax];
		h.vector[pozMax] = h.vector[pozNod];
		h.vector[pozNod] = aux;
		if(pozMax<(h.nrMasini-2)/2) {
			filtrareHeap(h, pozMax);
		}
	}
}
Heap citireHeapDinFisier(const char* fisier) {
	FILE* file = fopen(fisier, "r");
	Heap h = initializare(22);
	while (!feof(file)) {
		h.vector[h.nrMasini++] = citireDinFisier(file);
	}
	fclose(file);
	for (int i = (h.nrMasini - 2) / 2; i >= 0; i--) {
		filtrareHeap(h, i);
	}
	return h;
}
void afisareHeap(Heap h) {
	for (int i = 0; i < h.nrMasini; i++)
		afisareMasina(h.vector[i]);
}
void afisareHeapAscuns(Heap h) {
	for (int i = h.nrMasini; i < h.lungime; i++)
		afisareMasina(h.vector[i]);
}

Masina extrageHeap(Heap* h) {
	Masina aux;
	if (h->nrMasini > 0) {
		aux = h->vector[0];
		h->vector[0] = h->vector[h->nrMasini - 1];
		h->vector[h->nrMasini - 1] = aux;
		h->nrMasini--;
		for (int i = (h->nrMasini - 2) / 2; i >= 0; i--) {
			filtrareHeap(*h, i);
		}
	}
	return aux;
}

void dezalocareHeap(Heap* h) {
	for (int i = 0; i < h->lungime; i++) {
		free(h->vector[i].model);
		free(h->vector[i].numeSofer);
	}
	free(h->vector);
	h->vector = NULL;
	h->lungime = 0;
	h->nrMasini = 0;
}
int main() {
	Heap h = citireHeapDinFisier("MASINA.txt");
	afisareHeap(h);
	printf("Masini extrase: \n");
	afisareMasina(extrageHeap(&h));
	afisareMasina(extrageHeap(&h));
	afisareMasina(extrageHeap(&h));
	afisareMasina(extrageHeap(&h));
	afisareMasina(extrageHeap(&h));
	afisareMasina(extrageHeap(&h));

	printf("Heap ascuns:\n");
	afisareHeapAscuns(h);
	dezalocareHeap(&h);
	return 0;
}