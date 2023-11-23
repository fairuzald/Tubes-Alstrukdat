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

void deallocateTweet(AddressTweet *kicauanUtama) {
  /* I.S. *kicauanUtama terdefinisi
     F.S. *kicauanUtama dikembalikan ke sistem
     Melakukan dealokasi/pengembalian address *kicauanUtama */

  free(*kicauanUtama);
}

/* Fungsi/prosedur lain */

void displayTweet(AddressTweet *kicauanUtama) {
  /* Menampilkan ID, author, timeCreated, text, dan like dari suatu tweet */

  // display ID
  printf("| ID = %d\n", IdTweet(*kicauanUtama));

  // display author
  printf("| ");
  int i;
  for (i = 0; i < AuthorTweet(*kicauanUtama).Length; i++) {
    printf("%c", AuthorTweet(*kicauanUtama).TabWord[i]);
  }

  printf("\n");

  // display timeCreated
  printf("| ");
  TulisDATETIME(TimeCreatedTweet(*kicauanUtama));
  printf("\n");

  // display text
  printf("| ");
  for (i = 0; i < TextTweet(*kicauanUtama).Length; i++) {
    printf("%c", TextTweet(*kicauanUtama).TabWord[i]);
  }

  printf("\n");

  // display like
  printf("| Disukai: %d\n", Like(*kicauanUtama));

  printf("\n");
}

void likeTweet(AddressTweet *kicauanUtama) {
  /* Menambah jumlah like dari suatu tweet */

  Like(*kicauanUtama)++;
}

void editTweet(AddressTweet *kicauanUtama, Word newText) {
  /* Mengganti text dari suatu tweet */

  TextTweet(*kicauanUtama) = newText;
}
