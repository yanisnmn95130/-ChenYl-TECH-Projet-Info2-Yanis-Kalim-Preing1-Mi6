#ifndef FICHIER_H
#define FICHIER_H
#include "animal.h"


int sauvegarderAnimal(Animal a);


int chargerAnimaux(Animal* animaux, int tailleMax);


int supprimerAnimal(Animal *animaux, int *taille, int id);


int compterAnimaux(const char *nomFichier);


int sauvegarderAnimaux(Animal *animaux, int taille);

#endif