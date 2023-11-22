#ifndef REPLY_H
#define REPLY_H

#include "../tweet/tweet.h"
#include "./../adt/input/wordmachine.h"

void CreateReply(Tweet *tweet, Word);

void deleteReply();

void displayReply();

#endif