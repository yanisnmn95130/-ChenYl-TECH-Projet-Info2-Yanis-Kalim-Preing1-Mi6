#include "animal.h"
#include <time.h>
#include "fichier.h"


void printAnimal (Animal a){
        printf("ID : %d", a.id);
        printf("NOM : %s", a.name);
        printf("ESPECE : %s", a.species);
        printf("Année de naissaice : %d", a.birthYear);
        printf("POIDS : %f", a.weight);
        printf("DESCRIPTION : %s", a.comment);
}

Animal createAnimal(){
    Animal a;
    a.id = generateId();
    inputText("saisir le nom", a.name, 50); 
    inputText("saisir l'espece", a.species, 30 );
    printf("saisir l'année de naissance");
    scanf("%d", &a.birthYear);
    printf("sasir le poids"); 
    scanf("%f", &a.weight);
    inputText("décrire l'animal", a.comment, 250 );
        return a;

}

int generateId(){
        return (int)time(NULL) % 1000000;
}

int calculateage( int birthYear){
        time_t currentTime;
        struct tm *localTime;
        
        time(&currentTime); // trouver l'heure actuelle
        localTime = localtime(&currentTime); // Convertir en temps local
        
        return (localTime->tm_year + 1900) - birthYear; // utiliser time t
        }
        
int addAnimal( Animal* animals, int animalCount){
        if (animalCount >= 50) {
        printf("Erreur : Nombre maximum d'animaux atteint (50)\n");
        return animalCount;
        }
        
        // Créer et ajouter le nouvel animal seulement si le tableau n'est pas plein
        Animal newAnimal = createAnimal();
        animals[animalCount] = newAnimal;
        
        printf("Animal ajouté avec succès !\n");
        printAnimal(newAnimal);
        
        // Retourner le nouveau nombre d'animaux
        return animalCount + 1; // la taille de nb d'animaux dans le tab ne depassent pas la limite(50), elle doit creer un animal et l'enregister
        // elle doit ainsi retourner le nv nb d'animaux
        }

void presentRefuge( Animal liste[], int taille){
        for (int i = 0; i < taille ; i++){
                printf("animal %d :\n ", i);
                printAnimal(liste[i]);
                
        }
}

void adoptAnimal(Animal liste[], int *taille) {
        char nomAnimal[50];
    
        presentRefuge(liste, *taille);
    
        printf("Tapez le nom de l'animal que vous voulez adopter : ");
        scanf("%s", nomAnimal);
    
        int trouve = 0;
    
        for (int i = 0; i < *taille; i++) {
            if (strcmp(liste[i].name, nomAnimal) == 0) {
                printf("Félicitations !! %s vous appartient désormais, prenez-en soin !\n", nomAnimal);
                // Supprimer l'animal adopté en décalant le reste
                for (int j = i; j < *taille - 1; j++) {
                    liste[j] = liste[j + 1];
                }
                (*taille)--; 
                trouve = 1;
                break; 
            }
        }
    
        if (!trouve) {
            printf("Erreur : animal non trouvé.\n");
        }
}