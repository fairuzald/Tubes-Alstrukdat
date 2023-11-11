/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi dinamis */
#ifndef STACK_H
#define STACK_H

#include "../function/tweet_draft/tweet_draft.h"
#include "boolean.h"
#include "listdintweet.h"

#define Nil -1
#define MaxEl 100
/* Nil adalah stack dengan elemen kosong . */

typedef Draft infotype;
typedef long address; /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
  infotype* T; /* tabel penyimpan elemen */
  address TOP;
  long capacity /* alamat TOP: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
/* S.T[(S.TOP)] untuk mengakses elemen TOP */
/* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
#define Table(S) (S).T
#define Capacity(S) (S).capacity

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack* S, long capacity);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas capacity */
/* jadi indeksnya antara 0.. capacity */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack* S, infotype X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack* S, infotype* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

/* FITUR-FITUR UTAMA */
void createNewDraft(Stack* stackDraft);
void saveDraft(Stack* stackDraft, Draft draft);
void uploadDraft(ListDinTweet* listTweet, Draft draft);
void displayLatestDraft(Stack stackDraft);
void editLatestDraft(Stack* stackDraft);
void deleteLatestDraft(Stack* stackDraft);

/* FITUR TAMBAHAN*/
boolean isSameWord(Word word1, Word word2) {
  if (word1.Length != word2.Length) {
    return false;
  } else {
    boolean same = true;
    int i = 0;
    while (i < word1.Length) {
      if (word1.TabWord[i] != word2.TabWord[i]) {
        same = false;
      } else {
        i++;
      }
    }
  }
}

#endif
