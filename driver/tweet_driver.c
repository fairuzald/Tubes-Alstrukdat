#include <stdio.h>

#include "../adt/listdintweet.h"

int main() {
  ListDinTweet myListTweet;
  CreateListDinTweet(&myListTweet, 3);

  tweet(&myListTweet);
  tweet(&myListTweet);
  tweet(&myListTweet);
  tweet(&myListTweet);
  tweet(&myListTweet);
  displayListTweet(myListTweet);
}
