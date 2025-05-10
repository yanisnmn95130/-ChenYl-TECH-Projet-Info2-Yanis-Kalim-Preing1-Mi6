#include <stdio.h>
#include <string.h>
#include "animal.h"

int chercheNom(Animal liste[], int taille, char* nomAnimal) {
    for (int i = 0; i < taille; i++) {
        if ( strcmp(liste[i].name, nomAnimal) == 0) {
            printAnimal(liste[i]); 
        }
    }
    return 0;
}



int chercheID(Animal liste[], int taille, int id) {
    for (int i = 0; i < taille; i++) {
        if (liste[i].id == id) {
            return i;;
        }
    }
    return 0;
}

int chercheSpecies(Animal liste[], int taille, char* specie) {
    for (int i = 0; i < taille; i++) {
        if (strcmp(liste[i].species,  specie) == 0) {
            printAnimal(liste[i]);
        }
    }
    return 0;
}

int chercheAge(Animal liste[], int taille, char* age) {
    for (int i = 0; i < taille; i++) {
        if (strcmp(age, "jeune") == 0) {
            if(calculateage(liste[i].birthYear) < 2){
                printAnimal(liste[i]);
            }
        }
        if (strcmp(age, "senior") == 0){
            if (calculateage(liste[i].birthYear) > 10) {
                printAnimal(liste[i]);
            }
            
        }
    }
    
    return 0;
}