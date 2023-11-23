#include "liststackdraft.h"

#include <stdio.h>

/* ********** KONSTRUKTOR ********** */

/* Konstruktor : create List kosong  */

void CreateListStackDraft(ListStackDraft *l) {
  /* I.S. l sembarang */
  /* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY_LISTSTACKDRAFT */
  /* Proses: Inisialisasi nEff = 0 */

  NEFF_LISTSTACKDRAFT(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */

/* *** Banyaknya elemen *** */

int listStackDraftLength(ListStackDraft l) {
  /* Mengirimkan banyaknya elemen efektif List */
  /* Mengirimkan nol jika List kosong */

  return NEFF_LISTSTACKDRAFT(l);
}

/* ********** TEST KOSONG/PENUH ********** */

/* *** Test List kosong *** */

boolean isEmptyListStackDraft(ListStackDraft l) {
  /* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */

  return 0 == NEFF_LISTSTACKDRAFT(l);
}

/* *** Test List penuh *** */

boolean isFullListStackDraft(ListStackDraft l) {
  /* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

  return CAPACITY_LISTSTACKDRAFT == NEFF_LISTSTACKDRAFT(l);
}

/* ********** SEARCHING ********** */

/* ***  Perhatian : List boleh kosong!! *** */

int indexOfAuthorDraft(ListStackDraft l, Word authorDraft) {
  /* Search apakah ada elemen List l yang atribut authorDraft-nya bernilai
   * "authorDraft" */
  /* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF_LISTSTACKDRAFT */

  if (isEmptyListStackDraft(l)) {
    return IDX_UNDEF_LISTSTACKDRAFT;
  }

  boolean found = false;
  int i = 0;
  while (!found && i < listStackDraftLength(l)) {
    if (compareWordwWord(AuthorDraft(ELMT_LISTSTACKDRAFT(l, i)), authorDraft)) {
      found = true;
    } else {
      i++;
    }
  }

  if (found) {
    return i;
  }

  return IDX_UNDEF_LISTSTACKDRAFT;
}

/* ********** MENAMBAH ELEMEN ********** */

/* *** Menambahkan elemen terakhir *** */

void insertLastListStackDraft(ListStackDraft *l, ElTypeListStackDraft val) {
  /* Proses: Menambahkan val sebagai elemen terakhir List */
  /* I.S. List l boleh kosong, tetapi tidak penuh */
  /* F.S. val adalah elemen terakhir l yang baru */

  if (isEmptyListStackDraft(*l)) {
    ELMT_LISTSTACKDRAFT(*l, IDX_MIN_LISTSTACKDRAFT) = val;
  } else {
    ELMT_LISTSTACKDRAFT(*l, listStackDraftLength(*l)) = val;
  }

  NEFF_LISTSTACKDRAFT(*l)++;
}
