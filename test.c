#include <stdio.h>

#include "adt/listdintweet.h"

int main() {
  ListDinTweet myListTweet;
  CreateListDinTweet(&myListTweet, 3);

  newTweet(&myListTweet);
  newTweet(&myListTweet);
  newTweet(&myListTweet);
  newTweet(&myListTweet);
  newTweet(&myListTweet);
  displayListTweet(myListTweet);
  editTweetInList(&myListTweet, 2);
  editTweetInList(&myListTweet, -1);
  editTweetInList(&myListTweet, 6);
  like(&myListTweet, 2);
  like(&myListTweet, 2);
  like(&myListTweet, -1);
  like(&myListTweet, 6);
  displayListTweet(myListTweet);
}
