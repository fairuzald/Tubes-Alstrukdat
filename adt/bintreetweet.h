/* File : bintreetweet.h */
/* ADT pohon biner untuk tweet */
/* Representasi Address dengan pointer */
/* ElType adalah Tweet */

#ifndef POHONBINER_H
#define POHONBINER_H

#include "boolean.h"
#include "listdintweet.h"
#include "../function/tweet/tweet.h"

void deleteNode(AddressTweet *nodeBalasan);

void displayNode(AddressTweet *kicauanUtama, int space);

#endif