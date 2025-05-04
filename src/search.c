#include <stdio.h>
#include <string.h>
#include "animal.h"

int chercheNom(Animal liste[], int taille, char* tabAnimal) {
    for (int i = 0; i < taille; i++) {
        if (/* ........ */) {
            return 1; 
        }
    }
    return 0;
}



int chercheID(Animal liste[], int taille, int id) {
    for (int i = 0; i < taille; i++) {
        if (liste[i].id == id) {
            return i;
        }
    }
    return 0;
}