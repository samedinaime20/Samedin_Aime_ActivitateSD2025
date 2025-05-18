//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//struct Casa {
//	int nr;
//	char* strada;
//	int nrLocatari;
//	int varsta;
//};
//
//struct Casa initializare(int nr, const char* strada, int nrLocatari, int varsta) {
//	struct Casa a1;
//	a1.nr = nr;
//	a1.strada = (char*)malloc(sizeof(char) * (strlen(strada) + 1));
//	strcpy_s(a1.strada, strlen(strada) + 1, strada);
//	a1.nrLocatari = nrLocatari;
//	a1.varsta = varsta;
//	return a1;
//}
//void afisareVector(struct Casa* a, int nrElemente) {
//	for (int i = 0; i < nrElemente; i++) {
//		afisare(a[i]);
//	}
//}
//
//
//void afisare(struct Casa a) {
//	printf("Casa cu nr %d de pe strada %s are %d locatari cu varstele de %d", a.nr, a.strada, a.nrLocatari, a.varsta);
//}
//
//
//void modificaLocatari(struct Casa* a2, int noiLocatari) {
//	if (noiLocatari > 0) {
//		a2->nrLocatari = noiLocatari;
//	}
//}
//
//void dezalocare(struct Casa** v, int* nrElem) {
//	for (int i = 0; i <(* nrElem); i++) {
//		if ((*v)[i].strada != NULL) {
//			free((*v)[i].strada);
//		}
//	}
//	free(*v);
//	*v = NULL;
//	*nrElem = 0;
//}
//struct Casa* copierePrimeleNElem(struct Casa* v, int nrElem, int nrElemCopiate) {
//	struct Casa* vNou = NULL;
//	vNou = (struct Casa*)malloc(sizeof(struct Casa) * nrElemCopiate);
//	for (int i = 0; i < nrElem; i++) {
//		vNou[i] = v[i];
//		vNou[i].strada = (char*)malloc(sizeof(char) * (strlen(v[i].strada) + 1));
//		strcpy_s(vNou[i].strada, strlen(v[i].strada) + 1, v[i].strada);
//	}
//	return vNou;
//}
//int main() 
//{
//	struct Casa c;
//	c = initializare(28, "Str. Ovidius", 3, 50);
//	afisare(c);
//	modificareLocatari(&c, 4);
//	afisare(c);
//	dezalocare(&c,6);
//	afisare(c);
//	return 0;
//}