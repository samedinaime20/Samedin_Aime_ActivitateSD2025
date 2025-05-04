#include<stdio.h>
#include<malloc.h>
#include<string.h>

struct Telefon {
	int serie;
	char* producator;
	float pret;
	int RAM;
};

//initializare
struct Telefon initializare(int serie, const char* producator, float pret, int ram) {
	struct Telefon t;
	t.serie = serie;
	t.producator = (char*)malloc(sizeof(char) * (strlen(producator) + 1));
	strcpy_s(t.producator, strlen(producator) + 1, producator);
	t.pret = pret;
	t.RAM = ram;
	return t;
}

//afisare
void afisare(struct Telefon a) {
	if (a.producator != NULL) {
		printf("Telefonul cu seria %d, creat de producatorul %s, are %d RAM si este vadut cu pretul de %5.2f\n", a.serie, a.producator, a.RAM, a.pret);
	}
	else {
		printf("Telefonul din seria %d are %d RAM si este vandut la pretul de %5.2f\n", a.serie, a.RAM, a.pret);
	}
}

//afisare vector
void afisareVector(struct Telefon* a, int nrElemente) {
	for (int i = 0; i < nrElemente; i++) {
		afisare(a[i]);
	}
}

void modificare(struct Telefon*t, int pretNou) {
	if (pretNou > 0)
		t->pret = pretNou;
}
void dezalocare(struct Telefon**v, int*nrElem){
	for (int i = 0; i < nrElem; i++) {
		if (v[i]->producator != NULL) {
			free(*v[i]->producator);
		}
	}
	free(*v);
	*v = NULL;
	*nrElem = 0;
}
struct Telefon* copiazaPrimeleNElem(struct Telefon* v, int nrElem, int nrElemCopiate) {
	struct Telefon* vNou = NULL;
	vNou = (struct Telefon*)malloc(sizeof(struct Telefon) * nrElemCopiate);
	for (int i = 0; i < nrElem; i++) {
		vNou[i] = v[i];
		vNou[i].producator = (char*)malloc(sizeof(char) * (strlen(v[i].producator) + 1));
		strcpy_s(vNou[i].producator, strlen(v[i].producator) + 1, v[i].producator);
	}
	return vNou;
}
struct Telefon afiseazaPrimulTelefonByProducator(struct Telefon t, const char* producator, int nrElem,struct Telefon* v) {
	t.producator = NULL;
	for (int i = 0; i < nrElem; i++) {
		if (strcmp(v[i].producator, producator) == 0) {
			t = v[i];
			t.producator = (char*)malloc(strlen(v[i].producator) + 1);
			strcpy_s(t.producator, strlen(v[i].producator) + 1, v[i].producator);
			return t;
		}

	}
	return t;
}
void copiazaTelefoaneleScumpe(struct Telefon*v, int nrElem, float pretMin, int* dimensiune, struct Telefon** vNou) {
	*dimensiune = 0;
	for (int i = 0; i < nrElem; i++) {
		if (v[i].pret >= pretMin) {
			(*dimensiune)++;
		}
	}
	if ((*vNou) != NULL)
		free(*vNou);
	int k = 0;
	(*vNou) = (struct Telefon*)malloc(sizeof(struct Telefon) * (*dimensiune));
	for (int i = 0; i < nrElem; i++) {
		if (v[i].pret >= pretMin) {
			(*vNou)[k] = v[i];
			(*vNou)[k].producator = (char*)malloc(sizeof(char) * (strlen(v[i].producator) + 1));
			strcpy_s((*vNou)[i].producator, strlen(v[i].producator) + 1, v[i].producator);
			k++;
		}
	}
}
int main() {

}