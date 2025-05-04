#include "animal.h"
#include <time.h>
#include "fichier.h"


void printAnimal (Animal a){
        printf("ID : %d", a.id);
        printf("NOM : %s", a.name);
        printf("ESPECE : %s", a.species);
        printf("Année de naissaice : %d", a.birthYear);
        printf("POIDS : %f", a.weight);
        printf("DESCRIPTION : %s" a.comment);
}

Animal createAnimal(){
    Animal a;
    a.id = generateId();
    inputText("saisir le nom", a.name, 50); 
    inputText("saisir l'espece", a.species, 30 );
    printf("saisir l'année de naissance");
    scanf("%d" &a.birthyear);
    printf("sasir le poids"); 
    scanf("%f", &a.weight);
    inputText("décrire l'animal", a.comment, 250 );


}

int generateId(){
        return (int)time(NULL) % 1000000
}

int calculateage( int birthYear){
        // utiliser time t
}

int addAnimal( Animal* animals, int animalCount){
        // la taille de nb d'animaux dans le tab ne depassent pas la limite(50), elle doit creer un animal et l'enregister
        // elle doit ainsi retourner le nv nb d'animaux
    }