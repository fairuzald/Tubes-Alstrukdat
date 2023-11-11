#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack* S, long capacity) {
  /* I.S. sembarang; */
  /* F.S. Membuat sebuah stack S yang kosong berkapasitas capacity */
  /* jadi indeksnya antara 0.. capacity */
  /* Ciri stack kosong : TOP bernilai Nil */
  Table(*S) = (infotype*)malloc(capacity * sizeof(infotype));
  Top(*S) = Nil;
  Capacity(*S) = capacity;
}

void dealocateList(Stack* s) {
  /* I.S. s terdefinisi; */
  /* F.S. (s) dikembalikan ke system, Top(s)=Nil; Capacity(s)=0 */
  free(Table(*s));
  Top(*s) = Nil;
  Capacity(*s) = 0;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S) {
  /* Mengirim true jika Stack kosong: lihat definisi di atas */
  return Top(S) == Nil;
}
boolean IsFull(Stack S) {
  /* Mengirim true jika tabel penampung nilai elemen stack penuh */
  return Top(S) == Capacity(S) - 1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack* S, infotype X) {
  /* Menambahkan X sebagai elemen Stack S. */
  /* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
  /* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
  if (IsEmpty(*S)) {
    Top(*S) = 0;
  } else {
    Top(*S)++;
  }

  InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack* S, infotype* X) {
  /* Menghapus X dari Stack S. */
  /* I.S. S  tidak mungkin kosong */
  /* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
  *X = InfoTop(*S);
  if (Top(*S) == 0) {
    Top(*S) = Nil;
  } else {
    Top(*S)--;
  }
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandStack(Stack* s, long num) {
  /* Proses : Menambahkan capacity s sebanyak num */
  /* I.S. Stack sudah terdefinisi */
  /* F.S. Ukuran Stack bertambah sebanyak num */
  Table(*s) =
      (infotype*)realloc(Table(*s), (Capacity(*s) + num) * sizeof(infotype));
  Capacity(*s) += num;
}

void shrinkStack(Stack* s, long num) {
  /* Proses : Mengurangi capacity sebanyak num */
  /* I.S. Stack sudah terdefinisi, ukuran capacity > num, dan nEff < capacity -
   * num. */
  /* F.S. Ukuran list berkurang sebanyak num. */
  Table(*s) =
      (infotype*)realloc(Table(*s), (Capacity(*s) - num) * sizeof(infotype));
  Capacity(*s) -= num;
}

/* FITUR-FITUR UTAMA */
void createNewDraft(Stack* stackDraft) {
  printf("Masukkan draf:\n");
  Word text;
  int i = 0;
  START();
  while (!EOP && i < NMax) {
    text.TabWord[i] = currentChar;
    i++;
    ADV();
  }
  text.Length = i;

  if (isOnlySpace(text)) {
    // Jika masukan tidak valid, menampilkan pesan bahwa draft gagal dibuat
    printf("Draft tidak boleh hanya berisi spasi!\n");
  } else {
    print(
        "Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
    Word choice;
    int i = 0;
    START();
    while (!EOP && i < NMax) {
      choice.TabWord[i] = currentChar;
      i++;
      ADV();
    }
    choice.Length = i;
  }
}
void saveDraft(Stack* stackDraft, Draft draft) {}
void uploadDraft(ListDinTweet* listTweet, Draft draft) {}
void displayLatestDraft(Stack stackDraft) {}
void editLatestDraft(Stack* stackDraft) {}
void deleteLatestDraft(Stack* stackDraft) {}
