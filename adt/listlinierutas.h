#ifndef LISTLINIERUTAS_H
#define LISTLINIERUTAS_H

#include "../tweet/tweet.h"
#include "boolean.h"

void insertUtas(AddressTweet *kicauanUtama, AddressTweet sambungan, int index);

int lengthUtas(AddressTweet *kicauanUtama);
// kicauan utama ikut dihitung

int maxIDUtas(ListDinTweet *listTweetMain);

#endif