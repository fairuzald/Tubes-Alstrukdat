#include "tweet.h"

#include <stdio.h>
#include <stdlib.h>

/* Constructor Tweet */

AddressTweet CreateTweet(Word textTweet, Word authorTweet,
                         DATETIME timeCreatedTweet, int idTweet, int idReply,
                         int idUtas, int like, int depth, AddressTweet reply1,
                         AddressTweet reply2, AddressTweet utas,
                         boolean kicauanUtama) {
  /* Membentuk tweet baru dan memasukkan semua informasi ke dalam tweet tersebut
   */
  /* Mengirimkan address hasil alokasi semua informasi tweet */
  /* Jika alokasi gagal, mengirimkan NULL */

  AddressTweet pNew = (AddressTweet)malloc(sizeof(Tweet));
  if (NULL != pNew) {
    TextTweet(pNew) = textTweet;
    AuthorTweet(pNew) = authorTweet;
    TimeCreatedTweet(pNew) = timeCreatedTweet;
    IdTweet(pNew) = idTweet;
    IdReply(pNew) = idReply;            // inisialisasi dengan 0
    IdUtas(pNew) = idUtas;              // inisialisasi dengan 0
    Like(pNew) = like;                  // inisialisasi dengan 0
    Depth(pNew) = depth;                // inisialisasi dengan 0
    Reply1(pNew) = reply1;              // inisialisasi dengan NULL
    Reply2(pNew) = reply2;              // inisialisasi dengan NULL
    Utas(pNew) = utas;                  // inisialisasi dengan NULL
    KicauanUtama(pNew) = kicauanUtama;  // inisialisasi dengan false
  }

  return pNew;
}

void deallocateTweet(AddressTweet pTweet) {
  /* I.S. pTweet terdefinisi
     F.S. pTweet dikembalikan ke sistem
     Melakukan dealokasi/pengembalian address pTweet */

  free(pTweet);
}

/* Fungsi/prosedur lain */

void displayTweet(AddressTweet pTweet) {
  /* Menampilkan ID, author, timeCreated, text, dan like dari suatu tweet */

  // display ID
  printf("| ID = %d\n", IdTweet(pTweet));

  // display author
  printf("| ");
  int i;
  for (i = 0; i < AuthorTweet(pTweet).Length; i++) {
    printf("%c", AuthorTweet(pTweet).TabWord[i]);
  }

  printf("\n");

  // display timeCreated
  printf("| ");
  TulisDATETIME(TimeCreatedTweet(pTweet));
  printf("\n");

  // display text
  printf("| ");
  for (i = 0; i < TextTweet(pTweet).Length; i++) {
    printf("%c", TextTweet(pTweet).TabWord[i]);
  }

  printf("\n");

  // display like
  printf("| Disukai: %d\n", Like(pTweet));

  printf("\n");
}

void likeTweet(AddressTweet ptweet) {
  /* Menambah jumlah like dari suatu tweet */

  Like(ptweet)++;
}

void editTweet(AddressTweet ptweet, Word newText) {
  /* Mengganti text dari suatu tweet */

  TextTweet(ptweet) = newText;
}
