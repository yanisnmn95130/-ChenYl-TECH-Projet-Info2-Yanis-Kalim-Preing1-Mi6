#include "animal.h"
#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"
#include "animal.c"

int saveAnimal(Animal a)
{
    FILE *file = fopen("animals.txt", "a"); //"a"	Ajout (append) à la fin du fichier, sans supprimer son contenu.
    if (file == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier");
        return 0;
    }

    if (fprintf(file, "%d;%s;%s;%d;%.2f;%s\n", a.id, a.name, a.species, a.birthYear, a.weight, a.comment) < 0)
    {
        fclose(file);
        printf("Erreur lors de l'écriture du fichier");
        return 0;
    }

    fclose(file);
    return 1;
}

int loadAnimals(Animal *animals, int maxSize)
{
    int NumberAnimal = 0;
    int count = 0;

    // Demande le nombre d'animaux à charger.
    printf("Combien d'animaux voulez-vous charger (max %d) ? ", maxSize);
    if (scanf("%d", &NumberAnimal) != 1)
    {
        fprintf(stderr, "Erreur de lecture du nombre d'animaux.\n"); // mesage errur dans le fichier
        return 0;
    }

    if (NumberAnimal > maxSize)
    {
        printf("Limite max atteinte (%d). Seuls %d animaux seront chargés.\n", maxSize, maxSize);
        NumberAnimal = maxSize;
    }

    // Boucle de chargement des animaux.
    for (int i = 0; i < NumberAnimal; i++)
    {
        printf("\nAnimal %d :\n", i + 1);

        printf("  ID : ");
        scanf("%d", &animals[i].id);

        printf("  Nom : ");
        scanf("%s", animals[i].name);

        printf("  Espèce : ");
        scanf("%s", animals[i].species);

        printf("  Année de naissance : ");
        scanf("%d", &animals[i].birthYear);

        printf("  Poids : ");
        scanf("%f", &animals[i].weight);

        printf("  Commentaire : ");
        getchar(); // Consomme le caractère '\n' restant dans le buffer
        fgets(animals[i].comment, sizeof(animals[i].comment), stdin);

        count++;
    }
    return count;
}

int countAnimals(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Erreur : impossible d'ouvrir le fichier.\n");
        return -1;
    }

    int count = 0;
    Animal a;
    while (fscanf(file, "%d %49s %29s %d %f %249s", &a.id, a.name, a.species, &a.birthYear, &a.weight, a.comment) == 6)
    {
        count++;
    }

    fclose(file);
    return count;
}



void adoptAnimal(Animal liste[], int *taille) {
        int idAnimal;
    
        presentRefuge(liste, *taille);
    
        printf("Tapez l'ID de l'animal que vous voulez adopter : ");
        scanf("%d", &idAnimal);
    
        int trouve = 0;
    
        for (int i = 0; i < *taille; i++) {
            if (liste[i].id == idAnimal) {
                printf("Félicitations !! %s vous appartient désormais, prenez-en soin !\n", liste[i].name);
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

