#ifndef ANIMAL_H
#define ANIMAL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nom[50];      
    char espece[30];    
    int anneNaissance;       
    float poids;        
    char commentaire[250];   
} Animal;


void afficherAnimal(Animal a);


Animal creerAnimal(Animal *liste, int taille);


int genererId(Animal *liste, int taille);


int calculerAge(int anneNaissance);


int ajouterAnimal(Animal *animaux, int nombreAnimaux);


void besoinsQuotidiensCroquettes(Animal liste[], int taille);


void presenterRefuge(Animal liste[], int taille);

#endif