#include "bintreetweet.h"

#include <stdio.h>
#include <stdlib.h>

void deleteNode(AddressTweet *root) {
  if (Reply2(*root) == NULL && Reply1(*root) == NULL) {
    deallocateTweet(*root);
  } else {
    deleteNode(&Reply1(*root));
    deleteNode(&Reply2(*root));
  }
}

void displayNode(AddressTweet kicauanUtama, int space) {
  if (Reply1(kicauanUtama) == NULL && Reply2(kicauanUtama) == NULL) {
    int i = 0;
    for (; i < 4 * space; i++) {
      printf(" ");
    }
    printf("| ID = %d\n", IdReply((kicauanUtama)));

    for (; i < 4 * space; i++) {
      printf(" ");
    }

    int idAuthorTweet = userIndex(AuthorTweet(kicauanUtama));
    boolean priv =
        !PUBLIC(idAuthorTweet) &&
        !isTeman(grafPertemanan, AuthorTweet(kicauanUtama), currentUser.nama);
    if (priv) {
      printf("| PRIVAT\n");
    } else {
      printf("| ");
      int j;
      for (j = 0; j < AuthorTweet(kicauanUtama).Length; j++) {
        printf("%c", AuthorTweet(kicauanUtama).TabWord[j]);
      }
    }
    printf("\n");

    for (; i < 4 * space; i++) {
      printf(" ");
    }

    if (priv) {
      printf("| PRIVAT\n");
    } else {
      // display timeCreated
      printf("| ");
      TulisDATETIME(TimeCreatedTweet(kicauanUtama));
      printf("\n");
    }

    for (; i < 4 * space; i++) {
      printf(" ");
    }

    if (priv) {
      printf("| PRIVAT\n");
    } else {
      // display text
      printf("| ");

      for (i = 0; i < TextTweet(kicauanUtama).Length; i++) {
        printf("%c", TextTweet(kicauanUtama).TabWord[i]);
      }
    }

    displayNode(Reply1(kicauanUtama), space + 1);
    displayNode(Reply2(kicauanUtama), space);
  }
}