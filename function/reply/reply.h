#ifndef REPLY_H
#define REPLY_H

#include "../../adt/bintreetweet.h"
#include "../../adt/input/wordmachine.h"
#include "../../adt/listdintweet.h"
#include "../friend/friend.h"
#include "../tweet/tweet.h"
#include "../user/user.h"

void CreateReply(ListDinTweet *listTweetMain, AddressTweet *temp,
                 Word textTweet, Word authorTweet, DATETIME timeCreatedTweet,
                 int idKicau, int idBalasan);

void displayNewReply(AddressTweet temp);

AddressTweet findPrevReply(AddressTweet root, int idBalasan);

void inputNewReply(ListDinTweet *listTweetMain, User user, int idKicau,
                   int idBalasan);

void deleteReply(ListDinTweet *listTweetMain, int idKicau, int idBalasan);

void displayReply(ListDinTweet *listTweetMain, int idKicau);

#endif
