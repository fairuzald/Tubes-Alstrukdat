#ifndef LISTLINIERUTAS_H
#define LISTLINIERUTAS_H

#include "../tweet/tweet.h"
#include "boolean.h"

void insertUtas(ListDinTweet *listTweetMain, AddressTweet sambungan, int index);

int lengthUtas(Tweet pTweet);
// kicauan utama ikut dihitung

int maxIDUtas(ListDinTweet *listTweetMain);

#endif