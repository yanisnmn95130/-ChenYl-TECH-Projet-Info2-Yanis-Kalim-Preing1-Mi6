#include "animal.h"
#include <stdio.h>
#include <stdlib.h>


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

int loadAnimals(Animal *animals, int maxSize) {
    int NumberAnimal = 0;
    int count = 0;

    // Demande le nombre d'animaux à charger.
    printf("Combien d'animaux voulez-vous charger (max %d) ? ", maxSize);
    if (scanf("%d", &NumberAnimal) != 1) {
        fprintf(stderr, "Erreur de lecture du nombre d'animaux.\n");
        return 0;
    }

    if (NumberAnimal > maxSize) {
        printf("Limite max atteinte (%d). Seuls %d animaux seront chargés.\n", maxSize, maxSize);
        NumberAnimal = maxSize;
    }

    // Boucle de chargement des animaux.
    for (int i = 0; i < NumberAnimal; i++) {
        printf("\nAnimal %d :\n", i + 1);

        // Génération automatique de l'ID
        animals[i].id = (i == 0) ? 1 : animals[i - 1].id + 1;
        printf("  ID généré automatiquement : %d\n", animals[i].id);

        // Saisie du nom
        printf("  Nom : ");
        scanf("%s", animals[i].name);

        // Saisie et validation de l'espèce
        int especeValide = 0;
        do {
            printf("  Espèce (chat, chien, autruche, hamster) : ");
            scanf("%s", animals[i].species);

            if (strcmp(animals[i].species, "chat") == 0 ||
                strcmp(animals[i].species, "chien") == 0 ||
                strcmp(animals[i].species, "autruche") == 0 ||
                strcmp(animals[i].species, "hamster") == 0) {
                especeValide = 1;
            } else {
                printf("Erreur : Espèce invalide. Veuillez entrer une espèce valide.\n");
            }
        } while (!especeValide);

        // Saisie de l'année de naissance
        printf("  Année de naissance : ");
        scanf("%d", &animals[i].birthYear);

        // Saisie du poids
        printf("  Poids (en kg) : ");
        scanf("%f", &animals[i].weight);

        // Saisie du commentaire
        printf("  Commentaire : ");
        getchar(); // Consomme le caractère '\n' restant dans le buffer
        fgets(animals[i].comment, sizeof(animals[i].comment), stdin);

        // Supprime le caractère de nouvelle ligne (\n) à la fin du commentaire
        size_t len = strlen(animals[i].comment);
        if (len > 0 && animals[i].comment[len - 1] == '\n') {
            animals[i].comment[len - 1] = '\0';
        }

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

int deleteAnimal(Animal *animals, int *size, int id)
{
    for (int i = 0; i < *size; i++)
    {
        if (animals[i].id == id)
        {
            animals[i] = animals[*size - 1];
            (*size)--;
            return 1;
        }
    }
    return 0;
}
