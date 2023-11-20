#ifndef TWEET_H
#define TWEET_H

#include <time.h>

#include "../../adt/datetime.h"
#include "../../adt/input/wordmachine.h"

/* Definisi type Tweet */

typedef struct tweet {
  Word textTweet;
  Word authorTweet;
  DATETIME timeCreatedTweet;
  long idTweet;
  long idReply;
  long idUtas;
  long like;
  long depth;
  struct tweet *reply1;  // ke depth yang sama
  struct tweet *reply2;  // ke children
  struct tweet *utas;
} Tweet;

/* Selector Tweet */

#define TextTweet(t) (t).textTweet
#define AuthorTweet(t) (t).authorTweet
#define TimeCreatedTweet(t) (t).timeCreatedTweet
#define IdTweet(t) (t).idTweet
#define IdReply(t) (t).idReply
#define IdUtas(t) (t).idUtas
#define Like(t) (t).like
#define Depth(t) (t).depth
#define Reply1(t) (t).reply1
#define Reply2(t) (t).reply2
#define Utas(t) (t).utas

/* Constructor Tweet */

void CreateTweet(Tweet *tweet, Word textTweet, Word authorTweet,
                 DATETIME timeCreatedTweet, long idTweet, long idReply,
                 long idUtas, long like, long depth, Tweet *reply1,
                 Tweet *reply2, Tweet *utas);
/* Membentuk tweet baru dan memasukkan semua informasi ke dalam tweet tersebut
 */

/* Fungsi/prosedur Lain */

void displayTweet(Tweet tweet);
/* Menampilkan ID, author, timeCreated, text, dan like dari suatu tweet */

void likeTweet(Tweet *tweet);
/* Menambah jumlah like dari suatu tweet */

void editTweet(Tweet *tweet, Word newText);
/* Mengganti text dari suatu tweet */

#endif
