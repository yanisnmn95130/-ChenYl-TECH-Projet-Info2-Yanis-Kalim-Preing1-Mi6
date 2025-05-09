#ifndef ANIMAL_H
#define ANIMAL_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void inputText(const char *message, char *buffer, int size) {
    printf("%s", message);
    fgets(buffer, size, stdin);
    printf("\n");
}

typedef struct {
    int id ;
    char name [50];
    char species [30];
    int birthYear;
    float weight; 
    char comment [250];
} Animal ;

void printAnimal (Animal a);

Animal createAnimal();

int generateId();

int calculateage( int birthYear);

int addAnimal( Animal* animals, int animalCount);





#endif 