/* MODUL LIST STACKDRAFT STATIK */
/* Berisi definisi dan semua primitif pemrosesan list stackdraft statik */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara eksplisit, memori list statik */

#ifndef LISTSTACKDRAFT_H
#define LISTSTACKDRAFT_H

#include "boolean.h"
#include "stackdraft.h"

/*  Kamus Umum */

#define CAPACITY_LISTSTACKDRAFT 20
/* Kapasitas penyimpanan */
#define IDX_MIN_LISTSTACKDRAFT 0
/* Indeks minimum list */
#define IDX_UNDEF_LISTSTACKDRAFT -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */

typedef StackDraft ElType; /* type elemen List */
typedef int IdxType;
typedef struct {
  ElType contents[CAPACITY_LISTSTACKDRAFT]; /* memori tempat penyimpan elemen
                                               (container) */
  int nEff;
} ListStackDraft;
/* Indeks yang digunakan [0..CAPACITY_LISTSTACKDRAFT-1] */
/* Jika l adalah ListStackDraft, cara deklarasi dan akses: */
/* Deklarasi : l : ListStackDraft */
/* Maka cara akses:
   ELMT_LISTSTACKDRAFT(l,i) untuk mengakses elemen ke-i */
/* Definisi :
   List kosong: nEff = 0
   Definisi elemen pertama: ELMT_LISTSTACKDRAFT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */

#define ELMT_LISTSTACKDRAFT(l, i) (l).contents[(i)]
#define NEFF_LISTSTACKDRAFT(l) (l).nEff

/* ********** KONSTRUKTOR ********** */

/* Konstruktor : create List kosong  */

void CreateListStackDraft(ListStackDraft *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY_LISTSTACKDRAFT */
/* Proses: Inisialisasi nEff = 0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */

/* *** Banyaknya elemen *** */

int listStackDraftLength(ListStackDraft l);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

/* ********** TEST KOSONG/PENUH ********** */

/* *** Test List kosong *** */

boolean isEmptyListStackDraft(ListStackDraft l);
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */

/* *** Test List penuh *** */

boolean isFullListStackDraft(ListStackDraft l);
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** SEARCHING ********** */

/* ***  Perhatian : List boleh kosong!! *** */

int indexOfAuthorDraft(ListStackDraft l, Word authorDraft);
/* Search apakah ada elemen List l yang atribut authorDraft-nya bernilai
 * "authorDraft" */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF_LISTSTACKDRAFT */

/* ********** MENAMBAH ELEMEN ********** */

/* *** Menambahkan elemen terakhir *** */

void insertLastListStackDraft(ListStackDraft *l, ElType val);
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

#endif
