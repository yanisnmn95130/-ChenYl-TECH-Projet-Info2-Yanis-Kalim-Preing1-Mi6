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
int saveAnimals(Animal *animals, int size)
{
    printf("donne le nom du fichier \n");
    char filename[50];
    scanf("%s", filename);
    char finalFilename[100];
    snprintf(finalFilename, sizeof(finalFilename), "../animals/%s", filename);

    FILE *file = fopen(finalFilename, "w"); // "w" écrase le contenu existant du fichier.
    if (file == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 0;
    }

    for (int i = 0; i < size; i++)
    {
        if (fprintf(file, "%d;%s;%s;%d;%.2f;%s\n",
                    animals[i].id,
                    animals[i].name,
                    animals[i].species,
                    animals[i].birthYear,
                    animals[i].weight,
                    animals[i].comment) < 0)
        {
            fclose(file);
            printf("Erreur lors de l'écriture dans le fichier.\n");
            return 0;
        }
    }

    fclose(file);
    return 1;
}
int loadAnimals(Animal *animals, int maxSize)
{
    printf("donne le nom du fichier \n");
    char filename[50];
    scanf("%s", filename);
    char finalFilename[100];
    snprintf(finalFilename, sizeof(finalFilename), "../animals/%s", filename);

    FILE *file = fopen(finalFilename, "r");
    if (file == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier.\n");
        return 0;
    }

    int count = 0;
    while (count < maxSize && fscanf(file, "%d;%49[^;];%29[^;];%d;%f;%249[^\n]",
                                     &animals[count].id,
                                     animals[count].name,
                                     animals[count].species,
                                     &animals[count].birthYear,
                                     &animals[count].weight,
                                     animals[count].comment) == 6)
    {
        count++;
    }

    fclose(file);
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