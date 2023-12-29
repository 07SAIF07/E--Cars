
// E - Cars Project Code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//   car structure
typedef struct {
    int id;
    char marque[50];
    char modele[50];
    char etat[20];
} Voiture;

//  location structure
typedef struct {
    int id;
    int voitureId;
    char date[20];
    char dateRetour[20];
} Location;




                               //////////// FUNCTIONS /////////////



void loadVoituresFromFile(Voiture *voitures, int *nbVoitures) {
    FILE *file = fopen("cars.txt", "r");
    if (file == NULL) {
        // File doesn't exist, initialize with empty data
        *nbVoitures = 0;
        return;
    }

    while (fscanf(file, "%d %s %s %s", &voitures[*nbVoitures].id, voitures[*nbVoitures].marque, voitures[*nbVoitures].modele, voitures[*nbVoitures].etat) == 4) {
        (*nbVoitures)++;
    }

    fclose(file);
}

void loadLocationsFromFile(Location *locations, int *nbLocations) {
    FILE *file = fopen("locations.txt", "r");
    if (file == NULL) {
        // File doesn't exist, initialize with empty data
        *nbLocations = 0;
        return;
    }

    while (fscanf(file, "%d %d %s %s", &locations[*nbLocations].id, &locations[*nbLocations].voitureId, locations[*nbLocations].date, locations[*nbLocations].dateRetour) == 4) {
        (*nbLocations)++;
    }

    fclose(file);
}

void saveVoituresToFile(Voiture *voitures, int nbVoitures) {
    FILE *file = fopen("cars.txt", "w");
    if (file == NULL) {
        printf("Erreur lors de la sauvegarde des voitures.\n");
        return;
    }

    for (int i = 0; i < nbVoitures; i++) {
        fprintf(file, "%d %s %s %s\n", voitures[i].id, voitures[i].marque, voitures[i].modele, voitures[i].etat);
    }

    fclose(file);
}

void saveLocationsToFile(Location *locations, int nbLocations) {
    FILE *file = fopen("locations.txt", "w");
    if (file == NULL) {
        printf("Erreur lors de la sauvegarde des locations.\n");
        return;
    }

    for (int i = 0; i < nbLocations; i++) {
        fprintf(file, "%d %d %s %s\n", locations[i].id, locations[i].voitureId, locations[i].date, locations[i].dateRetour);
    }

    fclose(file);
}

void louerVoiture(Voiture *voitures, int nbVoitures, Location *locations, int *nbLocations) {
    int voitureId;
    printf("Entrez l'ID de la voiture que vous souhaitez louer : ");
    scanf("%d", &voitureId);

    int voitureFound = 0;
    for (int i = 0; i < nbVoitures; i++) {
        if (voitures[i].id == voitureId && strcmp(voitures[i].etat, "Disponible") == 0) {
            voitureFound = 1;

            locations[*nbLocations].id = *nbLocations + 1;
            locations[*nbLocations].voitureId = voitureId;
            printf("Entrez la date de location (format DD/MM/YYYY) : ");
            scanf("%s", locations[*nbLocations].date);

            strcpy(voitures[i].etat, "En location");

            (*nbLocations)++;

            printf("La voiture a ete louee avec succes.\n");
            break;
        }
    }

    if (!voitureFound) {
        printf("La voiture n'est pas disponible ou l'ID est incorrect.\n");
    }
}

void afficherDescriptionVoiture(Voiture *voitures, int nbVoitures) {
    int voitureId;
    printf("Entrez l'ID de la voiture dont vous souhaitez afficher la description : ");
    scanf("%d", &voitureId);

    int voitureFound = 0;
    for (int i = 0; i < nbVoitures; i++) {
        if (voitures[i].id == voitureId) {
            voitureFound = 1;
            printf("Description de la voiture (ID %d) :\n", voitureId);
            printf("Marque : %s\n", voitures[i].marque);
            printf("Modele : %s\n", voitures[i].modele);
            printf("Etat : %s\n", voitures[i].etat);
            break;
        }
    }

    if (!voitureFound) {
        printf("Aucune voiture trouvee avec l'ID %d.\n", voitureId);
    }
}

void supprimerVoitureEnPanne(Voiture *voitures, int *nbVoitures) {
    for (int i = 0; i < *nbVoitures; i++) {
        if (strcmp(voitures[i].etat, "En panne") == 0) {
            for (int j = i; j < *nbVoitures - 1; j++) {
                voitures[j] = voitures[j + 1];
            }

            (*nbVoitures)--;
            i--;
        }
    }

    printf("Les voitures en panne ont ete supprimees avec succes.\n");
}

void modifierVoiture(Voiture *voitures, int nbVoitures) {
    int voitureId;
    printf("Entrez l'ID de la voiture que vous souhaitez modifier : ");
    scanf("%d", &voitureId);

    int voitureFound = 0;
    for (int i = 0; i < nbVoitures; i++) {
        if (voitures[i].id == voitureId) {
            voitureFound = 1;

            printf("Nouvelle marque : ");
            scanf("%s", voitures[i].marque);
            printf("Nouveau modele : ");
            scanf("%s", voitures[i].modele);
            printf("Nouvel etat : ");
            scanf("%s", voitures[i].etat);

            printf("La voiture a ete modifiee avec succes.\n");
            break;
        }
    }

    if (!voitureFound) {
        printf("Aucune voiture trouvee avec l'ID %d.\n", voitureId);
    }
}

void afficherHistoriqueLocations(Location *locations, int nbLocations) {
    if (nbLocations > 0) {
        printf("Historique des locations :\n");
        for (int i = 0; i < nbLocations; i++) {
            printf("Location %d :\n", locations[i].id);
            printf("ID de la voiture louee : %d\n", locations[i].voitureId);
            printf("Date de location : %s\n", locations[i].date);
            if (strlen(locations[i].dateRetour) > 0) {
                printf("Date de retour : %s\n", locations[i].dateRetour);
            }
            printf("\n");
        }
    } else {
        printf("Aucune location enregistree.\n");
    }
}

void retourVoitureReclamation(Location *locations, int *nbLocations,Voiture *voitures) {
    int voitureId;
    printf("Entrez l'ID de la voiture a retourner suite a une reclamation : ");
    scanf("%d", &voitureId);

    int locationFound = 0;
    for (int i = *nbLocations - 1; i >= 0; i--) {
        if (locations[i].voitureId == voitureId) {
            locationFound = 1;

            printf("Entrez la date de retour (format DD/MM/YYYY) : ");
            scanf("%s", locations[i].dateRetour);

            // Update the state of the correct voiture
            strcpy(voitures[locations[i].voitureId - 1].etat, "Disponible");

            printf("La voiture a ete retournee suite a une reclamation avec succes.\n");
            break;
        }
    }

    if (!locationFound) {
        printf("Aucune location enregistree pour la voiture avec l'ID %d.\n", voitureId);
    }
}

void afficherStatistiques(Voiture *voitures, int nbVoitures, Location *locations, int nbLocations) {
    double tauxOccupationMoyen = 0.0;

    if (nbVoitures > 0 && nbLocations > 0) {
        tauxOccupationMoyen = ((double)nbLocations / nbVoitures) * 100;
    }

    printf("Taux d'occupation moyen : %.2f%%\n", tauxOccupationMoyen);

    int maxLocations = -1;
    int minLocations = nbLocations + 1;
    int voiturePlusLoueeId = -1;
    int voitureMoinsLoueeId = -1;

    for (int i = 0; i < nbVoitures; i++) {
        int locationsVoiture = 0;

        for (int j = 0; j < nbLocations; j++) {
            if (locations[j].voitureId == voitures[i].id) {
                locationsVoiture++;
            }
        }

        if (locationsVoiture > maxLocations) {
            maxLocations = locationsVoiture;
            voiturePlusLoueeId = voitures[i].id;
        }

        if (locationsVoiture < minLocations) {
            minLocations = locationsVoiture;
            voitureMoinsLoueeId = voitures[i].id;
        }
    }

    if (voiturePlusLoueeId != -1) {
        printf("Voiture la plus louee (ID %d) : %s %s\n", voiturePlusLoueeId, voitures[voiturePlusLoueeId - 1].marque, voitures[voiturePlusLoueeId - 1].modele);
    } else {
        printf("Aucune location enregistree.\n");
    }

    if (voitureMoinsLoueeId != -1) {
        printf("Voiture la moins louee (ID %d) : %s %s\n", voitureMoinsLoueeId, voitures[voitureMoinsLoueeId - 1].marque, voitures[voitureMoinsLoueeId - 1].modele);
    } else {
        printf("Aucune location enregistree.\n");
    }
}

                                                    
            // ************************************************************************************************************* //
            //                                       MAIN PROG                                                               //
            //               ******************************************************************                              //



int main() {
    Voiture voitures[100];
    Location locations[500];
    int nbVoitures = 0;
    int nbLocations = 0;

    loadVoituresFromFile(voitures, &nbVoitures);
    loadLocationsFromFile(locations, &nbLocations);

    int choix;
    do {
        printf("\nMenu:\n");
        printf("1. Louer une voiture\n");
        printf("2. Afficher la description d'une voiture\n");
        printf("3. Supprimer une voiture en panne\n");
        printf("4. Modifier la description et l'etat d'une voiture\n");
        printf("5. Afficher l'historique des locations\n");
        printf("6. Retour d'une voiture en cas de reclamation\n");
        printf("7. Afficher des statistiques sur l'utilisation des voitures\n");
        printf("0. Quitter\n");

        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                louerVoiture(voitures, nbVoitures, locations, &nbLocations);
                break;
            case 2:
                afficherDescriptionVoiture(voitures, nbVoitures);
                break;
            case 3:
                supprimerVoitureEnPanne(voitures, &nbVoitures);
                break;
            case 4:
                modifierVoiture(voitures, nbVoitures);
                break;
            case 5:
                afficherHistoriqueLocations(locations, nbLocations);
                break;
            case 6:
                retourVoitureReclamation(locations, &nbLocations, voitures);
                break;
            case 7:
                afficherStatistiques(voitures, nbVoitures, locations, nbLocations);
                break;
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 0);

    saveVoituresToFile(voitures, nbVoitures);
    saveLocationsToFile(locations, nbLocations);

    return 0;
}




