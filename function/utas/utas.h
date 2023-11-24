#ifndef UTAS_H
#define UTAS_H

#include "../../adt/boolean.h"
#include "../../adt/datetime.h"
#include "../../adt/input/wordmachine.h"
#include "../../adt/listdintweet.h"
#include "../../adt/listlinierutas.h"
#include "../../adt/liststatikuser.h"
#include "../friend/friend.h"
#include "../tweet/tweet.h"

void CreateUtas(ListDinTweet *listTweetMain, int idKicau, Word textTweet,
                Word authorTweet, DATETIME timeCreatedTweet);

void initUtas(ListDinTweet *listTweetMain, int idKicau, User currentUser);

void connectUtas(ListDinTweet *listTweetMain, int idUtas, int index,
                 User currentUser);

void deleteUtas(ListDinTweet *listTweetMain, int idUtas, int index,
                User currentUser);

void displayUtas(ListDinTweet *listTweetMain, int idUtas, User currentUser,
                 Graph grafPertemanan);

#endif
