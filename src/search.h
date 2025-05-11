#ifndef SEARCH_H
#define SEARCH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "animal.h"

int chercheNom(Animal liste[], int taille, char *nomAnimal);
int chercheEspece(Animal liste[], int taille, char *espece);
int chercheAge(Animal liste[], int taille, char *age);
#endif