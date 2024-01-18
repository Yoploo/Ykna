//
// Created by Mathéo on 18/01/2024.
//

#ifndef YKNA_CARD_H
#define YKNA_CARD_H
struct card {
    const char* recto;
    const char* verso;
    int rank;
    int points;
    int deck_id;
    int user_id;
};


int addCard(sqlite3* db, const struct card *Card);

#endif //YKNA_CARD_H
