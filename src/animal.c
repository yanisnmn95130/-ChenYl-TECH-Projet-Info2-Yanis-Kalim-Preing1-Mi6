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
    inputText("saisir le nom", a.name, 50);// inputText: fonction permettant laffichage dun champs de texte, le stockage de ce texte et def dune limite de caractere
    inputText("saisir l'espece", a.species, 30 );
    printf("saisir l'année de naissance");
    scanf("%d", &a.birthYear);
    printf("sasir le poids"); 
    scanf("%f", &a.weight);
    inputText("décrire l'animal", a.comment, 250 );
        return a;

}

int generateId(){
        return (int)time(NULL) % 1000000;// genere un nombre aleatoire comprt entre 0 et 999999
}

int calculateage( int birthYear){
        time_t currentTime;//time_t stocke le temps sous forme de seconde 
        struct tm *localTime;// localTime est un pointeur vers une structure tm, qui stocke des informations détaillées sur la date et l'heure
        
        time(&currentTime); // time():récupère le temps  ,donc time(&currentTime) recup temps actuelle
        localTime = localtime(&currentTime); // localtime(&currentTime) convertit ce temps brut en une structure tm, 
        //localTime : Devient un pointeur vers cette structure contenant la date et l'heure locales.
        
        return (localTime->tm_year + 1900) - birthYear; // Le champ tm_year dans la structure tm stocke l'année, courante moins 1900.
        }//Accéder à la valeur du champ tm_year dans la structure tm pointée par localTime.
        
int addAnimal( Animal* animals, int animalCount){
        if (animalCount >= 50) {
        printf("Erreur : Nombre maximum d'animaux atteint (50)\n");
        return animalCount;
        }
        
        // Créer et ajouter le nouvel animal seulement si le tableau n'est pas plein
        Animal newAnimal = createAnimal();//newAnimal : Variable qui stocke cet animal 
        animals[animalCount] = newAnimal;// Ajoute le nouvel animal dans le tableau
        
        printf("Animal ajouté avec succès !\n");
        printAnimal(newAnimal);
        
        // Retourner le nouveau nombre d'animaux
        return animalCount + 1; // la taille de nb d'animaux dans le tab ne depassent pas la limite(50), elle doit creer un animal et l'enregister
        // elle doit ainsi retourner le nv nb d'animaux
        }

void presentRefuge( Animal liste[], int taille){
        for (int i = 0; i < taille ; i++){
                printf("animal %d :\n ", i);
                printAnimal(liste[i]);// printAnimal() prend un animal et affiche ses détails 
                
        }
}

void adoptAnimal(Animal liste[], int *taille) {
        char nomAnimal[50];
    
        presentRefuge(liste, *taille);
    
        printf("Tapez le nom de l'animal que vous voulez adopter : ");
        scanf("%s", nomAnimal);
    
        int trouve = 0;
    
        for (int i = 0; i < *taille; i++) {
            if (strcmp(liste[i].name, nomAnimal) == 0) { //vérifie si les deux noms sont identiques,Si strcmp() retourne 0, cela signifie que l'animal recherché a été trouvé.
                printf("Félicitations !! %s vous appartient désormais, prenez-en soin !\n", nomAnimal);
                // Supprimer l'animal adopté en décalant le reste
                for (int j = i; j < *taille - 1; j++) {//Décale tous les animaux vers la gauche après l'animal supprimé. 
                    liste[j] = liste[j + 1];
                }
                (*taille)--; //Réduit la taille du refuge ((*taille)--).
                trouve = 1;
                break; 
            }
        }
    
        if (trouve == NULL) {
            printf("Erreur : animal non trouvé.\n");
        }
}

void dayFood (Animal liste[], int size){
        int tabNourriture[3];
        int tabNourritureTotal = 0;

        for ( int i = 0 ; i < size ; i++){
                if( strcmp(liste[i].species, "hamster" ) == 0){
                        int quantite = 20;
                        printf("%s a besoin de %d grammes de croquettes par jour", liste[i].name, quantite);
                        tabNourriture[2] += 20;
                }
                if( strcmp(liste[i].species, "autruche" ) == 0){
                        int quantite = 2500;
                        printf("%s a besoin de %d grammes de croquettes par jour", liste[i].name, quantite);
                        tabNourriture[3] += 2500;
                }
                if( strcmp(liste[i].species, "chat" ) == 0){
                        int quantite = 500;
                        if( calculateage(liste[i].birthYear) < 2){
                                printf("%s a besoin de %d grammes de croquettes par jour", liste[i].name, quantite);
                                tabNourriture[0] += 500;
                        }
                        else{
                                quantite = (int)(10*liste[i].weight)/ 100;
                                printf("%s a besoin de %d grammes de croquettes par jour", liste[i].name, quantite);
                                tabNourriture[0] += quantite;
                        }
                }
                if( strcmp(liste[i].species, "chien" ) == 0){
                        int quantite = 500;
                        if( calculateage(liste[i].birthYear) < 2){
                                printf("%s a besoin de %d grammes de croquettes par jour", liste[i].name, quantite);
                                tabNourriture[1] += quantite;
                        }
                        else{
                                quantite = (int)((10*liste[i].weight)/ 100);
                                printf("%s a besoin de %d grammes de croquettes par jour", liste[i].name, quantite);
                                tabNourriture[1] += quantite;
                        }
                }
                for ( int i = 0 ; i < 3; i++){
                        tabNourritureTotal += tabNourriture[i];
                }
                printf("%d", tabNourritureTotal);
                
                

        }
}
