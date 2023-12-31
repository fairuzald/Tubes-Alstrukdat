/* File : stackdraft.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi dinamis */

#ifndef STACKDRAFT_H
#define STACKDRAFT_H

#include "../function/tweet_draft/tweet_draft.h"
#include "boolean.h"
#include "input/wordmachine.h"

#define Nil -1
#define MaxEl 100
/* Nil adalah stack dengan elemen kosong . */

typedef Draft InfoTypeStackDraft;
typedef int Address; /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
  InfoTypeStackDraft* T; /* tabel penyimpan elemen */
  Address TOP;           /* alamat TOP: elemen puncak */
  int capacity;          /* kapasitas Stack */
  Word authorDraft;      /* username pemilik Draft */
} StackDraft;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
/* S.T[(S.TOP)] untuk mengakses elemen TOP */
/* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */

#define Table(S) (S).T
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
#define CapacityStackDraft(S) (S).capacity
#define AuthorDraft(S) (S).authorDraft

/* ************ Prototype ************ */

/* *** Konstruktor/Kreator *** */

void CreateEmptyStackDraft(StackDraft* S, int capacity, Word authorDraft);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas capacity */
/* jadi indeksnya antara 0.. capacity */
/* Ciri stack kosong : TOP bernilai Nil */

void dealocateStackDraft(StackDraft* s);
/* I.S. s terdefinisi; */
/* F.S. (s) dikembalikan ke system, Top(s)=Nil; CapacityStackDraft(s)=0 */

/* ************ Predikat untuk test keadaan KOLEKSI ************ */

boolean IsEmptyStackDraft(StackDraft S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */

boolean IsFullStackDraft(StackDraft S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */

void Push(StackDraft* S, InfoTypeStackDraft X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */

void Pop(StackDraft* S, InfoTypeStackDraft* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

/* ********* Mengubah Ukuran Stack ********* */

void expandStackDraft(StackDraft* s, int num);
/* Proses : Menambahkan capacity s sebanyak num */
/* I.S. Stack sudah terdefinisi */
/* F.S. Ukuran Stack bertambah sebanyak num */

void shrinkStackDraft(StackDraft* s, int num);
/* Proses : Mengurangi capacity s sebanyak num */
/* I.S. Stack sudah terdefinisi, ukuran capacity > num, dan nEff < capacity -
 * num. */
/* F.S. Ukuran stack berkurang sebanyak num. */

#endif
