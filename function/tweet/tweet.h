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

#define TextTweet(*kicauanUtama) (*kicauanUtama)->textTweet
#define AuthorTweet(*kicauanUtama) (*kicauanUtama)->authorTweet
#define TimeCreatedTweet(*kicauanUtama) (*kicauanUtama)->timeCreatedTweet
#define IdTweet(*kicauanUtama) (*kicauanUtama)->idTweet
#define IdReply(*kicauanUtama) (*kicauanUtama)->idReply
#define IdUtas(*kicauanUtama) (*kicauanUtama)->idUtas
#define Like(*kicauanUtama) (*kicauanUtama)->like
#define Depth(*kicauanUtama) (*kicauanUtama)->depth
#define Reply1(*kicauanUtama) (*kicauanUtama)->reply1
#define Reply2(*kicauanUtama) (*kicauanUtama)->reply2
#define Utas(*kicauanUtama) (*kicauanUtama)->utas
#define KicauanUtama(*kicauanUtama) (*kicauanUtama)->kicauanUtama

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

void deallocateTweet(AddressTweet *kicauanUtama);
/* I.S. *kicauanUtama terdefinisi
   F.S. *kicauanUtama dikembalikan ke sistem
   Melakukan dealokasi/pengembalian address *kicauanUtama */

/* Fungsi/prosedur Lain */

void displayTweet(AddressTweet *kicauanUtama);
/* Menampilkan ID, author, timeCreated, text, dan like dari suatu tweet */

void likeTweet(AddressTweet *kicauanUtama);
/* Menambah jumlah like dari suatu tweet */

void editTweet(AddressTweet *kicauanUtama, Word newText);
/* Mengganti text dari suatu tweet */

#endif
