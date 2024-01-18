#include <QApplication>
#include <QPushButton>
#include "../database/createDatabase.h"
#include <sqlite3.h>
#include "../Controller/card.h"
#include "../Controller/deck.h"


// Déclaration de la fonction ajouterDeck (assurez-vous d'ajuster les paramètres selon vos besoins)
int addDeck(sqlite3* db, const struct deck* Deck);
int deleteDeck(sqlite3* db, const struct deck* Deck, int deck_id);
int addCard(sqlite3* db, const struct card *Card);
int deleteCard(sqlite3* db, const struct card *Card, int card_id);

int main(int argc, char **argv)
{
    struct deck monDeck = {
            "Sujet du deck",
            "Description du deck",
            "Tag du deck",
            "Statut du deck",
            3     // Valeur arbitraire pour l'ID de l'utilisateur
    };


    struct card maCarte = {
            "Recto du texte",
            "Verso du texte",
            5,       // Valeur arbitraire pour le rang
            10,      // Valeur arbitraire pour les points
            1,       // Valeur arbitraire pour l'ID du deck
            3    // Valeur arbitraire pour l'ID de l'utilisateur
    };



    // Ouvrir la base de données
    sqlite3* db;
    int result = sqlite3_open("Ykna.db", &db);
    if (result != SQLITE_OK) {
        printf("Impossible d'ouvrir la base de données : %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Créer et delete deck
    //result = addDeck(db, &monDeck); // 1 est l'ID de l'utilisateur
    //result = deleteDeck(db, 5, 3);

    //ajouter et delete carte
    //result = addCard(db,"Hello", "Bonjour", 0, 10, 1, 1);
    //result = addCard(db,"ByeBye", "Au revoir", 0, 10, 4, 2);

    //result = deleteCard(db, 2, 2);

    // Fermer la base de données
    sqlite3_close(db);

    if (result != 0) {
        printf("Erreur lors de l'ajout du deck.\n");
        return 1;
    }

    // Le reste de votre programme ici...

    return 0;
}
