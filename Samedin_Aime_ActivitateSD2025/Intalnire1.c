//#include<stdio.h>
//#include<malloc.h>
//
//struct Client {
//	int id;
//	int varsta;
//	char* nume;
//	float buget;
//	char initialaTata;
//};
//
//struct Client initializare(int id, int varsta, const char* nume, float buget, char initialaTata) {
//	struct Client c;
//	c.id = id;
//	c.varsta = varsta;
//	c.nume = (char*)malloc((strlen(nume) + 1) * sizeof(char));
//	strcpy_s(c.nume, strlen(nume) + 1, nume);
//	c.buget = buget;
//	c.initialaTata = initialaTata;
//	return c;
//}
//
//void afisare(struct Client c) {
//	printf("Clientul %s are id-ul %d, varsta %d, bugetul %.2f si initiala tatalui %c\n", c.nume, c.id, c.varsta, c.buget, c.initialaTata);
//}
//
//int main() {
//	struct Client client = initializare(1, 20, "Ion", 1000, 'I');
//	afisare(client);
//
//	struct Client multiClienti[30];
//	int nrClienti = 2;
//	struct Client* clienti;
//	clienti = (struct Client*)malloc(nrClienti * sizeof(struct Client));
//	clienti[0] = initializare(1, 22, "Ionescu", 1000, 'J');//deplasare + dereferentiere
//	clienti[1] = initializare(2, 23, "Vasilescu", 2000, 'D');
//	return 0;
//}