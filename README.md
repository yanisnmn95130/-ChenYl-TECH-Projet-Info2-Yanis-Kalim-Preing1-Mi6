# -ChenYl-TECH-Projet-Info2-Yanis-Kalim-Preing1-Mi6
saisirTexte() : Lit du texte utilisateur (avec protection contre les retours à la ligne).

creerAnimal() : Crée un animal à partir d'une saisie utilisateur (nom, espèce, poids, etc.).

genererId() : Génère automatiquement un ID unique en fonction de la liste actuelle.

afficherAnimal() : Affiche les détails d’un animal.

presenterRefuge() : Affiche tous les animaux actuellement dans le refuge.

ajouterAnimal() : Ajoute un animal à la liste après validation.

supprimerAnimal() : Supprime un animal à partir de son ID.

chercheNom() : Affiche tous les animaux correspondant à un nom donné.

chercheEspece() : Affiche tous les animaux d’une espèce spécifique.

chercheAge() : Affiche tous les animaux considérés comme « jeunes » (< 2 ans) ou « seniors » (> 10 ans).

adopterAnimal() : Permet d’adopter un animal via son nom (version alternative de la suppression).

besoinsQuotidiensCroquettes() : Calcule et affiche les besoins en nourriture en grammes selon l’espèce et l’âge.

sauvegarderAnimal() : Sauvegarde un animal dans un fichier texte (animals.txt).

sauvegarderAnimaux() : Sauvegarde la liste entière dans un fichier donné.

chargerAnimaux() : Charge la liste des animaux depuis un fichier.

compterAnimaux() : Compte les entrées valides dans un fichier animalier.

Lorsque vous choisissez l'option ajouter un animal, l’application vous guide pour saisir les informations nécessaires à l’ajout d’un nouvel animal. Un identifiant unique est automatiquement généré. L’animal est alors ajouté à la base de données (en mémoire), et un message confirme son enregistrement avec un affichage complet de ses informations.

Lorsque vous choisissez l'option rechercher un ou plusieurs aniamux, trois types de recherches sont possibles. Saisissez un nom, et tous les animaux portant ce nom seront affichés. Entrez une espèce, et tous les animaux correspondants apparaîtront. Tapez jeune (moins de 2 ans) ou senior (plus de 10 ans), et les animaux correspondant à cette tranche d'âge apparaitront. 

Lorsque vous choisissez l'option adopter un animal, vous pouvez adopter un animal en saisissant son identifiant. L’animal est alors supprimé de la liste des animaux du refuge, et un message vous félicite pour l’adoption. Si l'ID est incorrect ou absent, un message d'erreur s'affiche.

Lorsque vous choisissez l'option afficher l’inventaire, la liste complète de tous les animaux actuellement dans le refuge, chacun avec ses caractéristiques( nom, id, espece, annee de naissance, poids, commentaire). Si aucun animal n’est enregistré, un message le signale.

Lorsque vous choisissez l'option gérer le quotidien en nourriture, la fontion qui calcule et affiche les besoins quotidiens en croquettes pour chaque animal, selon son espèce et son âge est appelée( chats et chiens : jeunes=500g, adultes=10% de leur poids en kg, hamsters : 20g, autruches : 2,5kg). Le programme donne également la quantité totale de nourriture à prévoir pour la journée.

Lorsque vous choisissez l'option charger un refuge, le programme charge une liste d’animaux à partir d’un fichier texte stocké dans le dossier ./src/animals/. Vous devez entrer le nom du fichier (ex. refuge.txt). Les données sont alors lues et ajoutées dans la mémoire du programme. Chaque animal chargé est affiché.

Lorsque vous choisissez l'option sauvegarder, l'utilisateur peut enregistrer les données du refuge dans un fichier texte. Il lui est demandé de fournir un nom de fichier. Le fichier est enregistré dans ./src/animals/.

Lorsque vous choisissez l'option quitter, le programme sauvegarde automatiquement les données dans un fichier de votre choix, pour éviter toute perte ensuite un message vous souhaite une bonne journée.



