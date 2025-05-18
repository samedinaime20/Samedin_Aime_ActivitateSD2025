//#include <stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//struct Masina
//{
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//	char serie;
//};
//typedef struct Masina Masina;
//
//Masina initializare(int id,
//int nrUsi,
//float pret,
//char* model,
//char* numeSofer,
//char serie) {
//	Masina m;
//	m.id = id;
//	m.pret = pret;
//	m.model = (char*)malloc(sizeof(char) * (strlen(model) + 1));
//	strcpy_s(m.model, strlen(model) + 1, model);
//	m.numeSofer= (char*)malloc(sizeof(char) * (strlen(numeSofer) + 1));
//	strcpy_s(m.numeSofer, strlen(numeSofer) + 1, numeSofer);
//	m.serie = serie;
//	return m;
//}
