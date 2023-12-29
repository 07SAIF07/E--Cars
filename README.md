# Application de location des voitures E Cars
# Description :
E-Cars est une simple application de location des voitures écrite en langage C. Elle permet de consulter l’état des voitures à l’agence, ainsi que l'historique des locations  ,modifier l'état des voitures et plusieurs autres fonctions.
# Tâches :
   ## Les fonctions que j'ai traitées dans cette application :
1. Louer une voiture :
   - Cette fonction permet à l'utilisateur de louer une voiture en spécifiant l'ID de la voiture souhaitée. Elle vérifie si la voiture est disponible à la location, puis enregistre les informations de location, y compris la date.

2. Afficher la description d'une voiture :
   - Cette fonction invite l'utilisateur à saisir l'ID d'une voiture et affiche ensuite sa description détaillée, y compris la marque, le modèle et son statut actuel (par exemple, disponible, louée).

3. Supprimer une voiture en panne :
   - Cette fonction supprime les voitures marquées comme "En panne" de la liste des voitures disponibles. Elle nettoie l'inventaire des voitures en excluant celles qui sont actuellement hors service.

4. Modifier la description et l'état d'une voiture :
   - Cette fonction permet à l'utilisateur de mettre à jour les informations (marque, modèle et état) d'une voiture spécifique en fournissant son ID. Elle contribue à maintenir les enregistrements des voitures précis et à jour.

5. Afficher l'historique des locations :
   - Cette fonction affiche les enregistrements historiques de toutes les locations de voitures. Elle fournit des détails tels que l'ID de la location, l'ID de la voiture louée, la date de location et la date de retour (si la voiture a été restituée).

6. Retour d'une voiture en cas de réclamation :
   - Cette fonction gère le retour d'une voiture suite à une réclamation. L'utilisateur saisit l'ID de la voiture retournée et la date de retour. Elle met à jour le statut de la voiture à "Disponible" et marque la fin de la période de location.

7. Afficher les statistiques de location :
   - Cette fonction calcule et affiche les statistiques liées aux locations de voitures. Elle comprend le taux moyen d'occupation des voitures et identifie les voitures les plus et moins louées en fonction du nombre de locations.

