#ifndef FICHIER_H
#define FICHIER_H
#include "animal.h"

int saveAnimal(Animal a);
int loadAnimals(Animal* animals, int maxSize);
int deleteAnimal(Animal id);
int countAnimals(const char *filename);
void adoptAnimal(Animal liste[], int *taille);
#endif


