#include "animal.h"
#include <stdio.h>
#include <stdlib.h>

// Fonction pour sauvegarder un animal dans un fichier
int sauvegarderAnimal(Animal a)
{
    FILE *file = fopen("animals.txt", "a"); // "a" Ajout (append) à la fin du fichier, sans supprimer son contenu.
    if (file == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier");
        return 0;
    }

    if (fprintf(file, "%d;%s;%s;%d;%.2f;%s\n", a.id, a.nom, a.espece, a.anneNaissance, a.poids, a.commentaire) < 0)
    {
        fclose(file);
        printf("Erreur lors de l'écriture du fichier");
        return 0;
    }

    fclose(file);
    return 1;
}

// Fonction pour sauvegarder plusieurs animaux dans un fichier
int sauvegarderAnimaux(Animal *animaux, int taille)
{
    printf("Donnez le nom du fichier \n");
    char nomFichier[50];
    scanf("%s", nomFichier);
    char cheminFichier[100];
    snprintf(cheminFichier, sizeof(cheminFichier), "./src/animals/%s", nomFichier);

    FILE *file = fopen(cheminFichier, "w"); // "w" écrase le contenu existant du fichier.
    if (file == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 0;
    }

    for (int i = 0; i < taille; i++)
    {
        if (fprintf(file, "%d;%s;%s;%d;%.2f;%s\n",
                    animaux[i].id,
                    animaux[i].nom,
                    animaux[i].espece,
                    animaux[i].anneNaissance,
                    animaux[i].poids,
                    animaux[i].commentaire) < 0)
        {
            fclose(file);
            printf("Erreur lors de l'écriture dans le fichier.\n");
            return 0;
        }
    }

    fclose(file);
    return 1;
}

// Fonction pour charger des animaux depuis un fichier
int chargerAnimaux(Animal *animaux, int tailleMax)
{
    printf("Donnez le nom du fichier \n");
    char nomFichier[50];
    scanf("%s", nomFichier);
    char cheminFichier[100];
    snprintf(cheminFichier, sizeof(cheminFichier), "./src/animals/%s", nomFichier);

    FILE *file = fopen(cheminFichier, "r");
    if (file == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier.\n");
        return 0;
    }

    int compteur = 0;
    while (compteur < tailleMax && fscanf(file, "%d;%49[^;];%29[^;];%d;%f;%249[^\n]",
                                          &animaux[compteur].id,
                                          animaux[compteur].nom,
                                          animaux[compteur].espece,
                                          &animaux[compteur].anneNaissance,
                                          &animaux[compteur].poids,
                                          animaux[compteur].commentaire) == 6)
    {
        compteur++;
    }

    fclose(file);
    return compteur;
}

// Fonction pour compter le nombre d'animaux dans un fichier
int compterAnimaux(const char *nomFichier)
{
    FILE *file = fopen(nomFichier, "r");
    if (!file)
    {
        printf("Erreur : impossible d'ouvrir le fichier.\n");
        return -1;
    }

    int compteur = 0;
    Animal a;
    while (fscanf(file, "%d %49s %29s %d %f %249s", &a.id, a.nom, a.espece, &a.anneNaissance, &a.poids, a.commentaire) == 6)
    {
        compteur++;
    }

    fclose(file);
    return compteur;
}

// Fonction pour supprimer un animal de la liste
int supprimerAnimal(Animal *animaux, int *taille, int id)
{
    for (int i = 0; i < *taille; i++)
    {
        if (animaux[i].id == id)
        {
            animaux[i] = animaux[*taille - 1];
            (*taille)--;
            return 1;
        }
    }
    return 0;
}