#include <QApplication>
#include <QPushButton>
#include "../database/createDatabase.h"
#include <sqlite3.h>

// Déclaration de la fonction ajouterDeck (assurez-vous d'ajuster les paramètres selon vos besoins)
int addDeck(sqlite3* db, const char* subject, const char* description, const char* tag, const char* status, int user_id);
int deleteDeck(sqlite3* db, int deck_id, int user_id);
int addCard(sqlite3* db, const char* recto, const char* verso, int rank, int points, int deck_id, int user_id);
int deleteCard(sqlite3* db, int deck_id, int user_id);

int main(int argc, char **argv)
{
    // Ouvrir la base de données
    sqlite3* db;
    int result = sqlite3_open("Ykna.db", &db);
    if (result != SQLITE_OK) {
        printf("Impossible d'ouvrir la base de données : %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Créer et delete deck
    //result = addDeck(db, "Kiki", "Révision kiki", "k", "0", 3); // 1 est l'ID de l'utilisateur
    //result = deleteDeck(db, 5, 3);

    //ajouter et delete carte
    //result = addCard(db,"Hello", "Bonjour", 0, 10, 1, 1);
    //result = addCard(db,"ByeBye", "Au revoir", 0, 10, 4, 2);

    result = deleteCard(db, 2, 1);

    // Fermer la base de données
    sqlite3_close(db);

    if (result != 0) {
        printf("Erreur lors de l'ajout du deck.\n");
        return 1;
    }

    // Le reste de votre programme ici...

    return 0;
}
