#include<stdio.h>
#include<malloc.h>

struct Casa {
	int nr;
	char* strada;
	int nrLocatari;
	int varsta;
};

struct Casa initializare(int nr, const char* strada, int nrLocatari, int varsta) {
	struct Casa a1;
	a1.nr = nr;
	a1.strada = (char*)malloc(sizeof(char) * (strlen(strada) + 1));
	strcpy_s(a1.strada, strlen(strada) + 1), strada);
	a1.nrLocatari = nrLocatari;
	a1.varsta = varsta;
	return a1;
}
void afisare(struct Casa a) {
	printf("Casa cu nr %d de pe strada %s are %d locatari cu varstele de %d", a.nr, a.strada, a.nrLocatari, a.varsta);
}
void modificaLocatari(struct Casa* a2, int noiLocatari) {
	if (noiLocatari > 0) {
		a2->nrLocatari = noiLocatari;
	}
}
void dezalocare(struct Casa* a3) {
	if (a3->strada != NULL) {
		free(a3->strada);
		a3->strada = NULL;
	}
}
int main() {
	struct Casa c;
	c = initializare(28, "Str. Ovidius", 3, 50);
	afisare(c);
	modificareLocatari(&c, 4);
	afisare(c);
	dezalocare(&c);
	afisare(c);
	return 0;
}