#include "animal.h"
#include <stdio.h>
#include <stdlib.h>

int saveAnimal(Animal a)
{
    FILE *file = fopen("animals.txt", "a");//fopen("animals.txt", "a") ouvre le fichier animals.txt ,"a" Ajout à la fin du fichier, sans supprimer son contenu.
    //FILE= gere les fichier, *file = pointeur accede au fichier ouvert
    if (file == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier");
        return 0;
    }

    if (fprintf(file, "%d;%s;%s;%d;%.2f;%s\n", a.id, a.name, a.species, a.birthYear, a.weight, a.comment) < 0)// fprintf = ecrit des infos dans un fichier
    {
        fclose(file);// ferme le fichier OBLIGATOIRE a la fin
        printf("Erreur lors de l'écriture du fichier");
        return 0;// sauvegarde rater, return 0
    }

    fclose(file);
    return 1;// reussi donc return 1
}

int loadAnimals(Animal *animals, int maxSize)
{
    int NumberAnimal = 0;//nbr a charger
    int count = 0;//nbr charger

    
    printf("Combien d'animaux voulez-vous charger (max %d) ? ", maxSize);
    if (scanf("%d", &NumberAnimal) != 1)//Si scanf() ne renvoie pas 1, erreru dcp ca retourne 0
    {
        fprintf(stderr, "Erreur de lecture du nombre d'animaux.\n"); // fprint ecerit dans lefichier ,, stderr ecrit un mess derreur
        return 0;
    }

    if (NumberAnimal > maxSize)
    {
        printf("Limite max atteinte (%d). Seuls %d animaux seront chargés.\n", maxSize, maxSize);
        NumberAnimal = maxSize;
    }

    // Boucle de chargement des animaux.
    /*for (int i = 0; i < NumberAnimal; i++)
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
*/
int countAnimals(const char *filename)
{
    FILE *file = fopen(filename, "r");//ouvre filename en mode lecture "r"
    if (file == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier.\n");
        return 0;
    }

    int count = 0;
    Animal a;
    while (fscanf(file, "%d %49s %29s %d %f %249s", &a.id, a.name, a.species, &a.birthYear, &a.weight, a.comment) == 6)//fscanf() lit chaque ligne du fichier et extrait les infos de l'animal 
    //boucle continue tant que fscanf lit 6 valeur et Chaque ligne valide augmente count de +1
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
        if (animals[i].id == id)//Compare l’ID de chaque animal avec celui donner . 
        {
            animals[i] = animals[*size - 1]; // sil’ID correspond, l’animal trouvé  delete.
            (*size)--;
            return 1;//succes return 1
        }
    }
    return 0;// echec retourn 0
}
