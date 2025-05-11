#ifndef SEARCH_H
#define SEARCH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "animal.h"

int chercheNom(Animal liste[], int taille, char *nomAnimal);
int chercheSpecies(Animal liste[], int taille, char *specie);
int chercheAge(Animal liste[], int taille, char *age);
#endif