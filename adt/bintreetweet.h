/* File : bintreetweet.h */
/* ADT pohon biner untuk tweet */
/* Representasi Address dengan pointer */
/* ElType adalah Tweet */

#ifndef POHONBINER_H
#define POHONBINER_H

#include "../function/friend/friend.h"
#include "../function/tweet/tweet.h"
#include "../function/user/user.h"
#include "boolean.h"
#include "listdintweet.h"

void deleteNode(AddressTweet *root);
void displayNode(AddressTweet kicauanUtama, int space);

#endif