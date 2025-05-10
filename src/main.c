#include <stdio.h>
#include <stdlib.h>
#include "animal.h"
#include "fichier.h"
#include "search.h"
#include "animal.c"
#include "fichier.c"
#include "search.c"



int main () {
    int choixMenu;
    printf("Bienvenue dans notre animalerie! Quel action souhaitez-vous faire ?\n");
    printf("menu :\n 1 : rechercher un/des animaux \n 2 : Nous confier votre animal\n 3 : Adopter un animal \n 4 : Afficher l'inventaire \n 5 : Besoin de nourriture pour la journée\n 6 : Quitter\n");
    scanf("%d", &choixMenu);
    if (choixMenu == 1){
        printf("voulez vous rechercher un animal par \n 1 : Nom\n 2 : Espèce\n 3 : Age\n");
        int choixRecherche;
        scanf("%d", &choixRecherche);
        
        if ( choixRecherche == 1){
            char nomAnimal[50];
            printf("Quel est le nom de l'animal ?\n");
            scanf("%s", nomAnimal);
            chercheNom(liste, taille, nomAnimal);
            if(chercheNom(liste, taille, nomAnimal) == 0){
                printf("animal non trouvé");
            }

        }
        
        else if (choixRecherche == 2){
            char specie[30];
            printf("Quel est l'espèce de l'animal ?\n");
            scanf("%s", specie);
            chercheSpecies(liste, taille, specie);
            if(chercheSpecies(liste, taille, specie) == 0){
                printf("animal non trouvé");
            }
        }
        else if (choixRecherche == 3){
            int age;
            printf("Quel est l'age de l'animal ?\n");
            scanf("%d", age);
            chercheAge(liste, taille, age);
            if(chercheAge(liste, taille, age) == 0){
                printf("animal non trouvé");
            }
        }
        
        
        
    }
    else if (choixMenu == 2){
        addAnimal(liste, taille);
    }
    else if (choixMenu == 3){
        adoptAnimal(liste, &taille);
    }
    else if (choixMenu == 4){
        presentRefuge(liste, taille);
    }
    else if (choixMenu == 5){
        dayFood(liste, taille);
    }
    else if (choixMenu == 6){
        printf("Merci d'avoir utilisé notre service !\n");
        return 0;
    }
    
    else{
        printf("erreur\n");
    }

    return 0;
}


