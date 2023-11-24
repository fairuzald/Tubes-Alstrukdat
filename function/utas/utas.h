#ifndef UTAS_H
#define UTAS_H

#include "../tweet/tweet.h"
#include "../friend/friend.h"
#include "./../adt/input/wordmachine.h"
#include "./../adt/listdintweet.h"
#include "./../adt/liststatikuser.h"
#include "./../adt/datetime.h"
#include "./../adt/listlinierutas.h"
#include "./../adt/boolean.h"

void CreateUtas(ListDinTweet *listTweetMain, int idKicau, Word textTweet, Word authorTweet, DATETIME timeCreatedTweet);

void initUtas(ListDinTweet *listTweetMain, int idKicau, User currentUser);

void connectUtas(ListDinTweet *listTweetMain, int idUtas, int index);

void deleteUtas(ListDinTweet *listTweetMain, int idUtas, int idKicau);

void displayUtas(ListDinTweet *listTweetMain, int idUtas);

#endif
