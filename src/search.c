
#include "animal.h"
#include "fichier.h"
#include "search.h"

int chercheNom(Animal liste[], int taille, char *nomAnimal)
{
    int trouve = 0;
    for (int i = 0; i < taille; i++)
    {
        if (strcmp(liste[i].nom, nomAnimal) == 0)
        {
            afficherAnimal(liste[i]);
            trouve += 1;    
        }

    }
    return trouve;
}

int chercheEspece(Animal liste[], int taille, char *espece)
{
    int trouve = 0;
    for (int i = 0; i < taille; i++)
    {
        if (strcmp(liste[i].espece, espece) == 0)
        {
            afficherAnimal(liste[i]);
            trouve += 1;
        }
    }
    return trouve;
}

int chercheAge(Animal liste[], int taille, char *age)
{
    int trouve = 0;
    for (int i = 0; i < taille; i++)
    {
        if (strcmp(age, "jeune") == 0)
        {
            if (calculerAge(liste[i].anneNaissance) < 2)
            {
                afficherAnimal(liste[i]);
                trouve += 1;
            }

        }
        if (strcmp(age, "senior") == 0)
        {
            if (calculerAge(liste[i].anneNaissance) > 10)
            {
                afficherAnimal(liste[i]);
                trouve += 1;
            }
        }
    }

    return trouve;
}