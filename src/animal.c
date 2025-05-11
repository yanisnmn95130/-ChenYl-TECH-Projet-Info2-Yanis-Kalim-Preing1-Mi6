#include "animal.h"
#include <time.h>
#include "fichier.h"

void inputText(const char *prompt, char *buffer, int bufferSize)
{
        printf("%s: ", prompt);
        fgets(buffer, bufferSize, stdin);

        // Supprimer le caractère de nouvelle ligne (\n) si présent
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
        {
                buffer[len - 1] = '\0';
        }
}
void printAnimal(Animal a)
{
        printf("[ ");
        printf("ID : %d ", a.id);
        printf("| NOM : %s ", a.name);
        printf("| ESPECE : %s ", a.species);
        printf("| Année de naissance : %d ", a.birthYear);
        printf("| POIDS : %.2f ", a.weight);
        printf("| DESCRIPTION : %s ", a.comment);
        printf(" ]\n");
}

int generateId(Animal *liste, int taille)
{
        int maxId = 0;

        // Parcourt la liste pour trouver l'ID maximum
        for (int i = 0; i < taille; i++)
        {
                if (liste[i].id > maxId)
                {
                        maxId = liste[i].id;
                }
        }

        return maxId + 1; // Retourne un ID unique
}

Animal createAnimal(Animal *liste, int taille)
{
        Animal a;
        a.id = generateId(liste, taille);
        inputText("saisir le nom", a.name, 50); // inputText: fonction permettant laffichage dun champs de texte, le stockage de ce texte et def dune limite de caractere
        inputText("saisir l'espece", a.species, 30);
        printf("saisir l'année de naissance");
        scanf("%d", &a.birthYear);
        printf("sasir le poids");
        scanf("%f", &a.weight);
        inputText("décrire l'animal", a.comment, 250);
        return a;
}

int calculateage(int birthYear)
{
        int currentYear = 2025; // Remplacez par l'année actuelle
        return currentYear - birthYear;
}

int addAnimal(Animal *animals, int animalCount)
{
        // Vérifie si le tableau est plein
        if (animalCount >= 50)
        {
                printf("Erreur : Nombre maximum d'animaux atteint (50).\n");
                return animalCount; // Retourne le nombre actuel d'animaux sans modification
        }

        // Crée un nouvel animal
        Animal newAnimal = createAnimal(animals, animalCount);

        // Ajoute le nouvel animal dans le tableau
        animals[animalCount] = newAnimal;

        // Affiche un message de succès
        printf("Animal ajouté avec succès !\n");
        printAnimal(newAnimal);

        // Retourne le nouveau nombre d'animaux
        return animalCount + 1;
}

void presentRefuge(Animal liste[], int taille)
{
        printf("\n===== Inventaire du Refuge =====\n");

        if (taille == 0)
        {
                printf("Aucun animal dans le refuge.\n");
                return;
        }
        for (int i = 0; i < taille; i++)
        {
                printf("animal %d :\n ", i + 1);
                printAnimal(liste[i]); // printAnimal() prend un animal et affiche ses détails
        }
}

void adoptAnimal(Animal liste[], int *taille)
{
        char nomAnimal[50];

        presentRefuge(liste, *taille);

        printf("Tapez le nom de l'animal que vous voulez adopter : ");
        scanf("%s", nomAnimal);

        int trouve = 0;

        for (int i = 0; i < *taille; i++)
        {
                if (strcmp(liste[i].name, nomAnimal) == 0)
                { // vérifie si les deux noms sont identiques,Si strcmp() retourne 0, cela signifie que l'animal recherché a été trouvé.
                        printf("Félicitations !! %s vous appartient désormais, prenez-en soin !\n", nomAnimal);
                        // Supprimer l'animal adopté en décalant le reste
                        for (int j = i; j < *taille - 1; j++)
                        { // Décale tous les animaux vers la gauche après l'animal supprimé.
                                liste[j] = liste[j + 1];
                        }
                        (*taille)--; // Réduit la taille du refuge ((*taille)--).
                        trouve = 1;
                        break;
                }
        }

        if (trouve == 0)
        {
                printf("Erreur : animal non trouvé.\n");
        }
}

void dayFood(Animal liste[], int size)
{
        int tabNourriture[4] = {0, 0, 0, 0}; // Initialisation à 0 pour éviter des valeurs aléatoires
        int tabNourritureTotal = 0;

        printf("\n===== Besoin quotidien en croquettes =====\n");
        for (int i = 0; i < size; i++)
        {
                if (strcmp(liste[i].species, "hamster") == 0)
                {
                        int quantite = 20;
                        printf("%s a besoin de %d grammes de croquettes par jour.\n", liste[i].name, quantite);
                        tabNourriture[2] += quantite; // Index 2 pour hamster
                }
                else if (strcmp(liste[i].species, "autruche") == 0)
                {
                        int quantite = 2500;
                        printf("%s a besoin de %d grammes de croquettes par jour.\n", liste[i].name, quantite);
                        tabNourriture[3] += quantite; // Index 3 pour autruche
                }
                else if (strcmp(liste[i].species, "chat") == 0)
                {
                        int quantite = 500;
                        if (calculateage(liste[i].birthYear) < 2)
                        {
                                printf("%s a besoin de %d grammes de croquettes par jour.\n", liste[i].name, quantite);
                                tabNourriture[0] += quantite; // Index 0 pour chat
                        }
                        else
                        {
                                quantite = (int)(10 * liste[i].weight); // 10% du poids en grammes
                                printf("%s a besoin de %d grammes de croquettes par jour.\n", liste[i].name, quantite);
                                tabNourriture[0] += quantite;
                        }
                }
                else if (strcmp(liste[i].species, "chien") == 0)
                {
                        int quantite = 500;
                        if (calculateage(liste[i].birthYear) < 2)
                        {
                                printf("%s a besoin de %d grammes de croquettes par jour.\n", liste[i].name, quantite);
                                tabNourriture[1] += quantite; // Index 1 pour chien
                        }
                        else
                        {
                                quantite = (int)(10 * liste[i].weight); // 10% du poids en grammes
                                printf("%s a besoin de %d grammes de croquettes par jour.\n", liste[i].name, quantite);
                                tabNourriture[1] += quantite;
                        }
                }
                else
                {
                        printf("Espèce inconnue pour l'animal %s.\n", liste[i].name);
                }
        }

        // Calcul du total des croquettes
        for (int i = 0; i < 4; i++)
        {
                tabNourritureTotal += tabNourriture[i];
        }

        // Affichage du total
        printf("Quantité totale de croquettes nécessaires pour tous les animaux : %d grammes.\n", tabNourritureTotal);
}