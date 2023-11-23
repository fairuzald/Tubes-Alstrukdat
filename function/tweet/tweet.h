#ifndef TWEET_H
#define TWEET_H

#include "../../adt/boolean.h"
#include "../../adt/datetime.h"
#include "../../adt/input/wordmachine.h"

/* Definisi Konstanta */

#define MAX_TWEET_LENGTH 280

/* Definisi type Tweet */

typedef struct tweet *AddressTweet;
typedef struct tweet {
  Word textTweet;
  Word authorTweet;
  DATETIME timeCreatedTweet;
  int idTweet;
  int idReply;
  int idUtas;
  int like;
  int depth;
  AddressTweet reply1;  // ke depth yang sama
  AddressTweet reply2;  // ke children
  AddressTweet utas;
  boolean kicauanUtama;
} Tweet;

/* Selector Tweet */

#define TextTweet(pTweet) (pTweet)->textTweet
#define AuthorTweet(pTweet) (pTweet)->authorTweet
#define TimeCreatedTweet(pTweet) (pTweet)->timeCreatedTweet
#define IdTweet(pTweet) (pTweet)->idTweet
#define IdReply(pTweet) (pTweet)->idReply
#define IdUtas(pTweet) (pTweet)->idUtas
#define Like(pTweet) (pTweet)->like
#define Depth(pTweet) (pTweet)->depth
#define Reply1(pTweet) (pTweet)->reply1
#define Reply2(pTweet) (pTweet)->reply2
#define Utas(pTweet) (pTweet)->utas
#define KicauanUtama(pTweet) (pTweet)->kicauanUtama

/* Constructor Tweet */

AddressTweet CreateTweet(Word textTweet, Word authorTweet,
                         DATETIME timeCreatedTweet, int idTweet, int idReply,
                         int idUtas, int like, int depth, AddressTweet reply1,
                         AddressTweet reply2, AddressTweet utas,
                         boolean kicauanUtama);
/* Membentuk tweet baru dan memasukkan semua informasi ke dalam tweet tersebut
 */
/* Mengirimkan address hasil alokasi semua informasi tweet */
/* Jika alokasi gagal, mengirimkan NULL */

void deallocateTweet(AddressTweet pTweet);
/* I.S. pTweet terdefinisi
   F.S. pTweet dikembalikan ke sistem
   Melakukan dealokasi/pengembalian address pTweet */

/* Fungsi/prosedur Lain */

void displayTweet(AddressTweet pTweet);
/* Menampilkan ID, author, timeCreated, text, dan like dari suatu tweet */

void likeTweet(AddressTweet ptweet);
/* Menambah jumlah like dari suatu tweet */

void editTweet(AddressTweet ptweet, Word newText);
/* Mengganti text dari suatu tweet */

#endif
