#include <stdio.h>
#include <string.h>
#include "animal.h"

int chercheNom(Animal liste[], int taille, char* nomAnimal) {
    for (int i = 0; i < taille; i++) {
        if ( strcmp(liste[i].name, nomAnimal) == 0) {
            return i; 
        }
    }
    return -1;
}



int chercheID(Animal liste[], int taille, int id) {
    for (int i = 0; i < taille; i++) {
        if (liste[i].id == id) {
            return i;
        }
    }
    return 0;
}