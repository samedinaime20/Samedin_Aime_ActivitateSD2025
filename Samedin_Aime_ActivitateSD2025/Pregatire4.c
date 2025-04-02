#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct StructuraMasina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};
typedef struct StructuraMasina Masina;

//creare structura pentru un nod dintr-o lista simplu inlantuita
struct Nod {
	Masina* info;
	struct Nod* next;
};
typedef struct Nod Nod;


//creare structura pentru tabela de dispersie
struct HashTable {
	int dim;
	struct Nod** vector;
};
typedef struct HashTable HashTable;
// aceasta este un vector de liste
struct HashTable {
	int dim;
};
typedef struct HashTable HashTable;

Masina citireMasinaDinFisier(FILE* file) {
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);
	char* aux;
	Masina m1;
	aux = strtok(buffer, sep);
	m1.id = atoi(aux);
	m1.nrUsi = atoi(strtok(NULL, sep));
	m1.pret = atof(strtok(NULL, sep));
	aux = strtok(NULL, sep);
	m1.model = malloc(strlen(aux) + 1);
	strcpy_s(m1.model, strlen(aux) + 1, aux);

	aux = strtok(NULL, sep);
	m1.numeSofer = malloc(strlen(aux) + 1);
	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);

	m1.serie = *strtok(NULL, sep);
	return m1;
}

void afisareMasina(Masina masina) {
	printf("Id: %d\n", masina.id);
	printf("Nr. usi : %d\n", masina.nrUsi);
	printf("Pret: %.2f\n", masina.pret);
	printf("Model: %s\n", masina.model);
	printf("Nume sofer: %s\n", masina.numeSofer);
	printf("Serie: %c\n\n", masina.serie);
}

void afisareListaMasini(Nod* lista) {
	//afiseaza toate elemente de tip masina din lista dublu inlantuita
	Nod* p = lista;
	while (p) {
		afisareMasina(*(p->info));
		p = p->next;
	}
	

	//prin apelarea functiei afisareMasina()
}

void adaugaMasinaInLista(Nod** lista, Masina masinaNoua) {
	//adauga la final in lista primita o noua masina pe care o primim ca parametru
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = masinaNoua;
	nou->next = NULL;
	if (*lista) {
		Nod* p = *lista;
		while (p->next) {
			p = p->next;
		}
		p->next = nou;
	}
	else {
		*lista = nou;
	}
}


HashTable initializareHashTable(int dimensiune) {
	HashTable ht;
	//initializeaza vectorul de liste si seteaza fiecare lista ca fiind NULL;
	ht.vector = (Nod**)malloc(sizeof(Nod*) * dimensiune);
	ht.dim = dimensiune;
	for (int i = 0; i < dimensiune; i++) {
		ht.vector[i] = NULL;
	}
	return ht;
}

int calculeazaHash(char key, int dimensiune) {
	// este calculat hash-ul in functie de dimensiunea tabelei si un atribut al masinii
	int hash;
	if (dimensiune != 0) {
		hash = key % dimensiune;
		return hash;
	}
	else {
		return 0;
	}
}

void inserareMasinaInTabela(HashTable hash, Masina masina) {
	//este folosit mecanismul CHAINING
	int pozitie = calculeazaHash(masina.serie, hash.dim);
	if (pozitie < hash.dim) {
		if (hash.vector[pozitie] != NULL) {
			adaugaMasinaInLista(&hash.vector[pozitie], masina);
		}
		else {
			hash.vector[pozitie] = (Nod*)malloc(sizeof(Nod));
			hash.vector[pozitie]->info = &masina;

			}
			Nod* nou = (Nod*)malloc(sizeof(Nod));
			nou->info = &masina;
			nou->next = NULL;
			p->next = nou;
		}
	}
}

HashTable citireMasiniDinFisier(const char* numeFisier, int dimensiune) {
	FILE* f = fopen(numeFisier, "r");
	HashTable ht = initializareHashTable(7);
	while (!feof(f)) {
		Masina m;
		m = citireMasinaDinFisier(f);
		inserareMasinaInTabela(ht, m);
	}
	fclose(f);
	return ht;
}

void afisareTabelaDeMasini(HashTable ht) {
	for (int i = 0; i < ht.dim; i++) {
		if (ht.vector[i]) {
			printf("\nPozitia %d\n", i);
			afisareListaMasini(ht.vector[i]);
		}
	}
}

void dezalocareTabelaDeMasini(HashTable *ht) {
	for (int i = 0; i < ht->dim; i++) {
		if (ht->vector[i]) {
			Nod* p = ht->vector[i];
			while (p) {
				Nod* aux = p;
				p = p->next;
				free(aux->info->model);
				free(aux->info->numeSofer);
				free(aux->info);
				free(aux);
			}
		}
	}
	free(ht->vector);
	ht->dim = 0;
}

float* calculeazaPreturiMediiPerClustere(HashTable ht, int* nrClustere) {
	//calculeaza pretul mediu al masinilor din fiecare cluster.
	//trebuie sa returnam un vector cu valorile medii per cluster.
	//lungimea vectorului este data de numarul de clustere care contin masini
	return NULL;
}

Masina getMasinaDupaCheie(HashTable ht, char serie) {
	Masina m;
	int pozitie = calculeazaHash(m.serie, ht.dim);
	if (ht.vector[pozitie]!=NULL) {
		Nod* p = ht.vector[pozitie];
		while (p && p->info.serie != serie) {
			p = p->next;
		}
		if (p) {
			m = p->info;
			m.model = (char*)malloc(strlen(p->info.model) + 1);
			strcpy(m.model, p->info.model);
			m.numeSofer = (char*)malloc(strlen(p->info.numeSofer) + 1);
			strcpy(m.numeSofer, p->info.numeSofer);
		}
	}
	return m;
}

int main() {
	HashTable ht;
	ht = citireMasiniDinFisier("masini.txt", 7);
	afisareTabelaDeMasini(ht);
	dezalocareTabelaDeMasini(&ht);
	Masina m = getMasinaDupaCheie(ht, 'A');
	if (m.id != 0) {
		printf("Masina cu serie A este:\n");
		afisareMasina(m);
		free(m.model);
		free(m.numeSofer);
	}

	return 0;
}