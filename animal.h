#ifndef ANIMAL_H
#define ANIMAL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inputText(const char *prompt, char *buffer, int bufferSize) {
    printf("%s: ", prompt);
    fgets(buffer, bufferSize, stdin);

    // Supprimer le caractère de nouvelle ligne (\n) si présent
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
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