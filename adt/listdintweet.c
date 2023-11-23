#include "listdintweet.h"

#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */

/* Konstruktor : create list kosong  */

void CreateListDinTweet(ListDinTweet *l, long capacity) {
  /* I.S. l sembarang, capacity > 0 */
  /* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
  BUFFER(*l) = (ElTypeListDin *)malloc(capacity * sizeof(ElTypeListDin));
  NEFF_LISTDINTWEET(*l) = 0;
  CAPACITY_LISTDINTWEET(*l) = capacity;
}

void dealocateListDinTweet(ListDinTweet *l) {
  /* I.S. l terdefinisi; */
  /* F.S. (l) dikembalikan ke system, CAPACITY_LISTDINTWEET(l)=0;
   * NEFF_LISTDINTWEET(l)=0 */
  free(BUFFER(*l));
  NEFF_LISTDINTWEET(*l) = 0;
  CAPACITY_LISTDINTWEET(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */

/* *** Banyaknya elemen *** */

int listTweetLength(ListDinTweet l) {
  /* Mengirimkan banyaknya elemen efektif list */
  /* Mengirimkan nol jika list l kosong */
  return NEFF_LISTDINTWEET(l);
}

/* ********** TEST KOSONG/PENUH ********** */

/* *** Test list kosong *** */

boolean isEmptyListTweet(ListDinTweet l) {
  /* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
  return listTweetLength(l) == 0;
}

/* *** Test list penuh *** */

boolean isFullListTweet(ListDinTweet l) {
  /* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
  return listTweetLength(l) == CAPACITY_LISTDINTWEET(l);
}

/* ********** MENAMBAH DAN ELEMEN DI AKHIR ********** */

/* *** Menambahkan elemen terakhir *** */

void insertLastListTweet(ListDinTweet *l, ElTypeListDin val) {
  /* Proses: Menambahkan val sebagai elemen terakhir list */
  /* I.S. List l boleh kosong, tetapi tidak penuh */
  /* F.S. val adalah elemen terakhir l yang baru */
  ELMT_LISTDINTWEET(*l, listTweetLength(*l)) = val;
  NEFF_LISTDINTWEET(*l)++;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */

void expandListTweet(ListDinTweet *l, int num) {
  /* Proses : Menambahkan capacity l sebanyak num */
  /* I.S. List sudah terdefinisi */
  /* F.S. Ukuran list bertambah sebanyak num */
  BUFFER(*l) = (ElTypeListDin *)realloc(
      BUFFER(*l), (CAPACITY_LISTDINTWEET(*l) + num) * sizeof(ElTypeListDin));
  CAPACITY_LISTDINTWEET(*l) += num;
}
