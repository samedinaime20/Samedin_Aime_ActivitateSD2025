#include<stdio.h>
#include<malloc.h>

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


int main() {

}