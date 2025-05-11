
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "animal.h"
#include "fichier.h"
#include "search.h"

#define MAX_ANIMAUX 50

int main()
{
    Animal animaux[MAX_ANIMAUX];
    /*int taille = loadAnimals(animaux, MAX_ANIMAUX);*/
    int taille = 0; // Initialisation de la taille à 0
    int choix;
    do
    {
        printf("\n===== Menu du Refuge Animalier =====\n");
        printf("1. Ajouter un animal\n");
        printf("2. Rechercher un/des animaux\n");
        printf("3. Adopter un animal\n");
        printf("4. Afficher l'inventaire\n");
        printf("5. Gérer le quotidien (Nourriture)\n");
        printf("6. charger un refuge \n");
        printf("7. Sauvegarder\n");
        printf("8. Quitter\n");
        printf("Choisissez une option : ");
        if (scanf("%d", &choix) != 1)
        {
            printf("Entrée invalide. Veuillez entrer un nombre.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        switch (choix)
        {
        case 1: // Ajouter un animal
            if (taille < MAX_ANIMAUX)
            {
                Animal nouvelAnimal;
                nouvelAnimal.id = generateId(animaux, taille);

                printf("Entrez le nom de l'animal : ");
                scanf("%s", nouvelAnimal.name);

                int especeValide = 0;
                do
                {
                    printf("Entrez l'espèce de l'animal (chat, chien, autruche, hamster) : ");
                    scanf("%s", nouvelAnimal.species);

                    if (strcmp(nouvelAnimal.species, "chat") == 0 ||
                        strcmp(nouvelAnimal.species, "chien") == 0 ||
                        strcmp(nouvelAnimal.species, "autruche") == 0 ||
                        strcmp(nouvelAnimal.species, "hamster") == 0)
                    {
                        especeValide = 1;
                    }
                    else
                    {
                        printf("Erreur : Le refuge n'accepte que les chats, chiens, autruches et hamsters.\n");
                    }
                } while (!especeValide);

                printf("Entrez l'année de naissance de l'animal : ");
                scanf("%d", &nouvelAnimal.birthYear);

                printf("Entrez le poids de l'animal (en kg) : ");
                scanf("%f", &nouvelAnimal.weight);

                printf("Entrez un commentaire sur l'animal : ");
                scanf(" %[^\n]", nouvelAnimal.comment);

                animaux[taille] = nouvelAnimal;
                taille++;
                printf("Animal ajouté avec succès !\n");
                printAnimal(nouvelAnimal);
            }
            else
            {
                printf("Erreur : Nombre maximum d'animaux atteint (%d).\n", MAX_ANIMAUX);
            }
            break;

        case 2:
        {
            char critere[20];
            printf("Entrez le critère de recherche (nom, espèce, age) : ");
            scanf("%s", critere);

            if (strcmp(critere, "nom") == 0)
            {
                char nom[50];
                printf("Nom de l'animal : ");
                scanf("%s", nom);
                if (chercheNom(animaux, taille, nom) == 0)
                {
                    printf("Aucun animal trouvé avec ce nom.\n");
                }
            }
            else if (strcmp(critere, "espèce") == 0)
            {
                char espece[30];
                printf("Espèce de l'animal : ");
                scanf("%s", espece);
                if (chercheSpecies(animaux, taille, espece) == 0)
                {
                    printf("Aucun animal trouvé avec cette espèce.\n");
                }
            }
            else if (strcmp(critere, "age") == 0)
            {
                char age[10];
                printf("Âge (jeune/senior) : ");
                scanf("%s", age);
                if (chercheAge(animaux, taille, age) == 0)
                {
                    printf("Aucun animal trouvé avec cet âge.\n");
                }
            }
            else
            {
                printf("Critère invalide.\n");
            }
            break;
        }

        case 3:
        {
            int id;
            printf("Entrez l'ID de l'animal à adopter : ");
            if (scanf("%d", &id) != 1)
            {
                printf("Entrée invalide. Veuillez entrer un nombre.\n");
                while (getchar() != '\n')
                    ;
                break;
            }
            if (deleteAnimal(animaux, &taille, id))
            {
                printf("Adoption réussie !\n");
            }
            else
            {
                printf("Animal introuvable.\n");
            }
            break;
        }

        case 4:
            presentRefuge(animaux, taille);
            break;

        case 5:
            dayFood(animaux, taille);
            break;

        case 6:
            printf("Chargement des animaux depuis le fichier...\n");
            taille = loadAnimals(animaux, MAX_ANIMAUX);
            if (taille > 0)
            {
                printf("Animaux chargés avec succès !\n");
                presentRefuge(animaux, taille);
            }
            else
            {
                printf("Aucun animal trouvé dans le fichier.\n");
            }
            break;
        case 7:
            printf("Sauvegarde des données...\n");
            saveAnimals(animaux, taille);
            break;
        case 8:
            printf("Sauvegarde des données...\n");
            saveAnimals(animaux, taille);
            printf("Au revoir !\n");
            break;

        default:
            printf("Option invalide, veuillez réessayer.\n");
        }
    } while (choix != 8);

    return 0;
}