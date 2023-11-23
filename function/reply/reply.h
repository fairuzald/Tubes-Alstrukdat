#ifndef REPLY_H
#define REPLY_H

#include "../../adt/input/wordmachine.h"
#include "../tweet/tweet.h"

void CreateReply(Word textTweet, Word authorTweet, DATETIME timeCreatedTweet,
                 long idUtas, AddressTweet utas, Tweet *prev, Tweet root,
                 AddressTweet *newReply);

void deleteReply();

void displayReply();

#endif