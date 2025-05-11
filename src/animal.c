#include "animal.h"
#include <time.h>
#include "fichier.h"

// Fonction pour saisir un texte avec une limite de caractères
void saisirTexte(const char *invite, char *buffer, int tailleBuffer)
{
        printf("%s: ", invite);
        fgets(buffer, tailleBuffer, stdin);

        // Supprimer le caractère de nouvelle ligne (\n) si présent
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
        {
                buffer[len - 1] = '\0';
        }
}

// Fonction pour afficher les détails d'un animal
void afficherAnimal(Animal a)
{
        printf("[ ");
        printf("ID : %d ", a.id);
        printf("| NOM : %s ", a.nom);
        printf("| ESPECE : %s ", a.espece);
        printf("| Année de naissance : %d ", a.anneNaissance);
        printf("| POIDS : %.2f ", a.poids);
        printf("| DESCRIPTION : %s ", a.commentaire);
        printf(" ]\n");
}

// Fonction pour générer un ID unique pour un animal
int genererId(Animal *liste, int taille)
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

// Fonction pour créer un nouvel animal
Animal creerAnimal(Animal *liste, int taille)
{
        Animal a;
        a.id = genererId(liste, taille);
        saisirTexte("saisir le nom", a.nom, 50);
        saisirTexte("saisir l'espece", a.espece, 30);
        printf("saisir l’année de naissance");
        scanf("%d", &a.anneNaissance);
        printf("saisir le poids");
        scanf("%f", &a.poids);
        saisirTexte("décrire l'animal", a.commentaire, 250);
        return a;
}

// Fonction pour calculer l'âge d'un animal
int calculerAge(int anneeNaissance)
{
        int anneeCourante = 2025; // Remplacez par l'année actuelle
        return anneeCourante - anneeNaissance;
}

// Fonction pour ajouter un animal à la liste
int ajouterAnimal(Animal *animaux, int nombreAnimaux)
{
        // Vérifie si le tableau est plein
        if (nombreAnimaux >= 50)
        {
                printf("Erreur : Nombre maximum d'animaux atteint (50).\n");
                return nombreAnimaux; // Retourne le nombre actuel d'animaux sans modification
        }

        // Crée un nouvel animal
        Animal nouvelAnimal = creerAnimal(animaux, nombreAnimaux);

        // Ajoute le nouvel animal dans le tableau
        animaux[nombreAnimaux] = nouvelAnimal;

        // Affiche un message de succès
        printf("Animal ajouté avec succès !\n");
        afficherAnimal(nouvelAnimal);

        // Retourne le nouveau nombre d'animaux
        return nombreAnimaux + 1;
}

// Fonction pour présenter les animaux du refuge
void presenterRefuge(Animal liste[], int taille)
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
                afficherAnimal(liste[i]);
        }
}

// Fonction pour adopter un animal
void adopterAnimal(Animal liste[], int *taille)
{
        char nomAnimal[50];

        presenterRefuge(liste, *taille);

        printf("Tapez le nom de l'animal que vous voulez adopter : ");
        scanf("%s", nomAnimal);

        int trouve = 0;

        for (int i = 0; i < *taille; i++)
        {
                if (strcmp(liste[i].nom, nomAnimal) == 0)
                {
                        printf("Félicitations !! %s vous appartient désormais, prenez-en soin !\n", nomAnimal);
                        // Supprimer l'animal adopté en décalant le reste
                        for (int j = i; j < *taille - 1; j++)
                        {
                                liste[j] = liste[j + 1];
                        }
                        (*taille)--;
                        trouve = 1;
                        break;
                }
        }

        if (trouve == 0)
        {
                printf("Erreur : animal non trouvé.\n");
        }
}

// Fonction pour calculer les besoins quotidiens en croquettes
void besoinsQuotidiensCroquettes(Animal liste[], int taille)
{
        int tabNourriture[4] = {0, 0, 0, 0}; // Initialisation à 0 pour éviter des valeurs aléatoires
        int tabNourritureTotal = 0;

        printf("\n===== Besoin quotidien en croquettes =====\n");
        for (int i = 0; i < taille; i++)
        {
                if (strcmp(liste[i].espece, "hamster") == 0)
                {
                        int quantite = 20;
                        printf("%s a besoin de %d grammes de croquettes par jour.\n", liste[i].nom, quantite);
                        tabNourriture[2] += quantite; // Index 2 pour hamster
                }
                else if (strcmp(liste[i].espece, "autruche") == 0)
                {
                        int quantite = 2500;
                        printf("%s a besoin de %d grammes de croquettes par jour.\n", liste[i].nom, quantite);
                        tabNourriture[3] += quantite; // Index 3 pour autruche
                }
                else if (strcmp(liste[i].espece, "chat") == 0)
                {
                        int quantite = 500;
                        if (calculerAge(liste[i].anneNaissance) < 2)
                        {
                                printf("%s a besoin de %d grammes de croquettes par jour.\n", liste[i].nom, quantite);
                                tabNourriture[0] += quantite; // Index 0 pour chat
                        }
                        else
                        {
                                quantite = (int)(10 * liste[i].poids); // 10% du poids en grammes
                                printf("%s a besoin de %d grammes de croquettes par jour.\n", liste[i].nom, quantite);
                                tabNourriture[0] += quantite;
                        }
                }
                else if (strcmp(liste[i].espece, "chien") == 0)
                {
                        int quantite = 500;
                        if (calculerAge(liste[i].anneNaissance) < 2)
                        {
                                printf("%s a besoin de %d grammes de croquettes par jour.\n", liste[i].nom, quantite);
                                tabNourriture[1] += quantite; // Index 1 pour chien
                        }
                        else
                        {
                                quantite = (int)(10 * liste[i].poids); // 10% du poids en grammes
                                printf("%s a besoin de %d grammes de croquettes par jour.\n", liste[i].nom, quantite);
                                tabNourriture[1] += quantite;
                        }
                }
                else
                {
                        printf("Espèce inconnue pour l'animal %s.\n", liste[i].nom);
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