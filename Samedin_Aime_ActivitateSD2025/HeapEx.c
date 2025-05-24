//#define _CRT_SECURE_NO_WARNINGS
//#include<stdlib.h>
//#include<stdio.h>
//#include<string.h>
//#include<malloc.h>
//
//struct Casa
//{
//	int nr;
//	char* culoare;
//	float pret;
//};
//typedef struct Casa Casa;
//struct Heap
//{
//	int lungime;
//	Casa* vector;
//	int nrCase;
//};
//typedef struct Heap Heap;
////citire casa
//Casa citireCasaDinFisier(FILE* file) {
//	Casa c;
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//	Casa* aux;
//	aux = strtok(buffer, sep);
//	c.nr = atoi(aux);
//	aux = strtok(NULL, sep);
//	c.culoare = malloc(strlen(aux) + 1);
//	strcpy(c.culoare, aux);
//	c.pret = atof(strtok(NULL, sep));
//	return c;
//}
//
////afisare casa
//void afisareCasa(Casa c) {
//	printf("Nr: %d\n", c.nr);
//	printf("Culoare: %s\n", c.culoare);
//	printf("Pret: %.2f\n\n", c.pret);
//}
//
////initializare heap
//Heap initializareHeap(int lungime) {
//	Heap h;
//	h.lungime = lungime;
//	h.vector = (Casa*)malloc(sizeof(Casa) * lungime);
//	h.nrCase = 0;
//	return h;
//}
//
////filtrare Heap
//void filtrareHeap(Heap h, int pozNod) {
//	int pozS = 2 * pozNod + 1;
//	int pozD = 2 * pozD + 2;
//	int pozMax = pozNod;
//	if (pozS<h.nrCase && h.vector[pozS].nr>h.vector[pozMax].nr)
//		pozMax = pozS;
//	if (pozD<h.nrCase && h.vector[pozD].nr>h.vector[pozMax].nr)
//		pozMax = pozD;
//	if (pozMax != pozNod) {
//		Casa aux;
//		aux = h.vector[pozMax];
//		h.vector[pozMax] = h.vector[pozNod];
//		h.vector[pozNod] = aux;
//		if(pozMax<(h.nrCase-2)/2){
//			filtrareHeap(h, pozMax);
//		}
//	}
//}
//
////citire Heap
//
//Heap citireHeap(const char* fisier) {
//	FILE* file = fopen(fisier, "r");
//	Heap h = initializareHeap(6);
//	while (!feof(file)) {
//		h.vector[h.nrCase++] = citireCasaDinFisier(file);
//	}
//	fclose(file);
//	for (int i = (h.nrCase - 2) / 2; i >= 0; i--) {
//		filtrareHeap(h, i);
//	}
//	return h;
//}
//
////afisare Heap
//void afisareHeap(Heap h) {
//	for (int i = 0; i < h.lungime; i++)
//		afisareCasa(h.vector[i]);
//}
//
////afisare Heap ascuns
//void afisareHeapAscuns(Heap h) {
//	for (int i = h.nrCase; i < h.lungime; i++) {
//		afisareCasa(h.vector[i]);
//	}
//}
//
////extragere Casa
//
//Casa extragereCasa(Heap* h) {
//	Casa aux;
//	if (h->nrCase > 0) {
//		aux = h->vector[0];
//		h->vector[0] = h->vector[h->nrCase - 1];
//		h->vector[h->nrCase - 1] = aux;
//		h->nrCase--;
//		for (int i = (h->nrCase - 2) / 2; i >= 0; i--) {
//			filtrareHeap(*h, i);
//		}
//	}
//	return aux;
//}
//
////dezalocare Heap
//void dexalocareHeap(Heap* h) {
//	for (int i = 0; i < h->lungime; i++) {
//		free(h->vector[i].culoare);
//	}
//	free(h->vector);
//	h->vector = NULL;
//	h->lungime = 0;
//	h->nrCase = 0;
//}
//int main() {
//	Heap h = citireHeap("casa.txt");
//	afisareHeap(h);
//	printf("Masini extrase: \n");
//	afisareCasa(extragereCasa(&h));
//	afisareCasa(extragereCasa(&h));
//	afisareCasa(extragereCasa(&h));
//	afisareCasa(extragereCasa(&h));
//
//	printf("Afisare heap ascuns:\n");
//	afisareHeapAscuns(h);
//	dexalocareHeap(&h);
//	return 0;
//}
