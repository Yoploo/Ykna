//
// Created by Mathéo on 17/01/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int addDeck(sqlite3* db, const char* subject, const char* description, const char* tag, const char* status, int user_id) {
    // Préparez la requête SQL avec des paramètres préparés
    const char* sql = "INSERT INTO decks (subject, description, tag, status, user_id) VALUES (?, ?, ?, ?, ?);";

    sqlite3_stmt* stmt;

    // Préparez la requête SQL
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Erreur lors de la préparation de la requête : %s\n", sqlite3_errmsg(db));
        return rc;
    }

    // Liez les valeurs aux paramètres préparés
    sqlite3_bind_text(stmt, 1, subject, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, description, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, tag, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, status, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 5, user_id);

    // Exécutez la requête préparée
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Erreur lors de l'exécution de la requête : %s\n", sqlite3_errmsg(db));
        return rc;
    }

    // Finalisez la requête préparée
    sqlite3_finalize(stmt);

    printf("Deck ajouté avec succès.\n");

    return 0;
}

int deleteDeck(sqlite3* db, int deck_id, int user_id) {
    const char* sql = "DELETE FROM decks WHERE deck_id = ? AND user_id = ?";

    sqlite3_stmt* stmt;

    int req = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    //gestion erreur
    if(req != SQLITE_OK) {
        fprintf(stderr, "Erreur lors de l'execution de la requete : %s\n", sqlite3_errmsg(db));
        return req;
    }

    sqlite3_bind_int(stmt, 1, deck_id);
    sqlite3_bind_int(stmt, 2, user_id);

    req = sqlite3_step(stmt);
    if(req != SQLITE_DONE) {
        fprintf(stderr, "Erreur lors de l'execution de la requete : %s\n", sqlite3_errmsg(db));
        return req;
    }

    sqlite3_finalize(stmt);

    if (sqlite3_changes(db) == 0) {
        printf("Le deck n'appartient pas à l'utilisateur connecté.\n");
        return SQLITE_ERROR;
    }


    printf("Deck supprimé avec succès.\n");

    return 0;

}