#include "stackdraft.h"

#include <stdio.h>
#include <stdlib.h>

/* ************ Prototype ************ */

/* *** Konstruktor/Kreator *** */

void CreateEmptyStackDraft(StackDraft* S, long capacity, Word authorDraft) {
  /* I.S. sembarang; */
  /* F.S. Membuat sebuah stack S yang kosong berkapasitas capacity */
  /* jadi indeksnya antara 0.. capacity */
  /* Ciri stack kosong : TOP bernilai Nil */
  Table(*S) = (infotype*)malloc(capacity * sizeof(infotype));
  Top(*S) = Nil;
  CapacityStackDraft(*S) = capacity;
  AuthorDraft(*S) = authorDraft;
}

void dealocateStackDraft(StackDraft* s) {
  /* I.S. s terdefinisi; */
  /* F.S. (s) dikembalikan ke system, Top(s)=Nil; CapacityStackDraft(s)=0 */
  free(Table(*s));
  Top(*s) = Nil;
  CapacityStackDraft(*s) = 0;
  AuthorDraft(*s).Length = 0;
}

/* ************ Predikat untuk test keadaan KOLEKSI ************ */

boolean IsEmptyStackDraft(StackDraft S) {
  /* Mengirim true jika Stack kosong: lihat definisi di atas */
  return Nil == Top(S);
}

boolean IsFullStackDraft(StackDraft S) {
  /* Mengirim true jika tabel penampung nilai elemen stack penuh */
  return Top(S) == CapacityStackDraft(S) - 1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */

void Push(StackDraft* S, infotype X) {
  /* Menambahkan X sebagai elemen Stack S. */
  /* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
  /* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
  if (IsEmptyStackDraft(*S)) {
    Top(*S) = 0;
  } else {
    Top(*S)++;
  }

  InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */

void Pop(StackDraft* S, infotype* X) {
  /* Menghapus X dari Stack S. */
  /* I.S. S tidak mungkin kosong */
  /* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
  *X = InfoTop(*S);
  if (Top(*S) == 0) {
    Top(*S) = Nil;
  } else {
    Top(*S)--;
  }
}

/* ********* Mengubah Ukuran Stack ********* */

void expandStackDraft(StackDraft* s, long num) {
  /* Proses : Menambahkan capacity s sebanyak num */
  /* I.S. Stack sudah terdefinisi */
  /* F.S. Ukuran Stack bertambah sebanyak num */
  Table(*s) = (infotype*)realloc(
      Table(*s), (CapacityStackDraft(*s) + num) * sizeof(infotype));
  CapacityStackDraft(*s) += num;
}

void shrinkStackDraft(StackDraft* s, long num) {
  /* Proses : Mengurangi capacity s sebanyak num */
  /* I.S. Stack sudah terdefinisi, ukuran capacity > num, dan nEff < capacity -
   * num. */
  /* F.S. Ukuran stack berkurang sebanyak num. */
  Table(*s) = (infotype*)realloc(
      Table(*s), (CapacityStackDraft(*s) - num) * sizeof(infotype));
  CapacityStackDraft(*s) -= num;
}
