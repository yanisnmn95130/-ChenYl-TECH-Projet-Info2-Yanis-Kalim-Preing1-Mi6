
#include "animal.h"
#include "fichier.h"
#include "search.h"

int chercheNom(Animal liste[], int taille, char *nomAnimal)
{
    for (int i = 0; i < taille; i++)
    {
        if (strcmp(liste[i].nom, nomAnimal) == 0)
        {
            afficherAnimal(liste[i]);
        }
    }
    return 0;
}

int chercheEspece(Animal liste[], int taille, char *specie)
{
    for (int i = 0; i < taille; i++)
    {
        if (strcmp(liste[i].espece, specie) == 0)
        {
            afficherAnimal(liste[i]);
        }
    }
    return 0;
}

int chercheAge(Animal liste[], int taille, char *age)
{
    for (int i = 0; i < taille; i++)
    {
        if (strcmp(age, "jeune") == 0)
        {
            if (calculerAge(liste[i].anneNaissance) < 2)
            {
                afficherAnimal(liste[i]);
            }
        }
        if (strcmp(age, "senior") == 0)
        {
            if (calculerAge(liste[i].anneNaissance) > 10)
            {
                afficherAnimal(liste[i]);
            }
        }
    }

    return 0;
}
