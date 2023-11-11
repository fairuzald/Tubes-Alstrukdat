#include "tweet.h"

#include <stdio.h>

/* Constructor Tweet */

void CreateTweet(Tweet *tweet, Word textTweet, Word authorTweet,
                 DATETIME timeCreatedTweet, long idTweet, long idReply,
                 long idUtas, long like, long depth, Tweet *reply1,
                 Tweet *reply2, Tweet *utas) {
  TextTweet(*tweet) = textTweet;
  AuthorTweet(*tweet) = authorTweet;
  TimeCreatedTweet(*tweet) = timeCreatedTweet;
  IdTweet(*tweet) = idTweet;
  IdReply(*tweet) = idReply;  // inisialisasi dengan 0
  IdUtas(*tweet) = idUtas;    // inisialisasi dengan 0
  Like(*tweet) = like;        // inisialisasi dengan 0
  Depth(*tweet) = depth;      // inisialisasi dengan 0
  Reply1(*tweet) = reply1;    // inisialisasi dengan NULL
  Reply2(*tweet) = reply2;    // inisialisasi dengan NULL
  Utas(*tweet) = utas;        // inisialisasi dengan NULL
}

/* Fungsi/prosedur lain */

void displayTweet(Tweet tweet) {
  // display ID
  printf("| ID = %ld\n", IdTweet(tweet));

  // display author
  printf("| ");
  int i;
  for (i = 0; i < AuthorTweet(tweet).Length; i++) {
    printf("%c", AuthorTweet(tweet).TabWord[i]);
  }

  printf("\n");

  // display timeCreated
  printf("| ");
  TulisDATETIME(TimeCreatedTweet(tweet));
  printf("\n");

  // display text
  printf("| ");
  for (i = 0; i < TextTweet(tweet).Length; i++) {
    printf("%c", TextTweet(tweet).TabWord[i]);
  }

  printf("\n");

  // display like
  printf("| Disukai: %ld\n", Like(tweet));

  printf("\n");
}

void likeTweet(Tweet *tweet) { Like(*tweet)++; }

void editTweet(Tweet *tweet, Word newText) { TextTweet(*tweet) = newText; }
