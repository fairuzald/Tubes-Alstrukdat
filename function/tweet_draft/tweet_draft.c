#include "tweet_draft.h"

#include <stdio.h>

/* Constructor Draft */

void CreateDraft(Draft *draft, Word textDraft, DATETIME timeCreatedDraft) {
  /* Membentuk draft baru dan memasukkan semua informasi ke dalam draft tersebut
   */

  TextDraft(*draft) = textDraft;
  TimeCreatedDraft(*draft) = timeCreatedDraft;
}

/* Fungsi/prosedur Lain*/

void displayDraft(Draft draft) {
  /* Menampilkan text dan timeCreated dari suatu draft */

  // display timeCreated
  printf("| ");
  TulisDATETIME(TimeCreatedDraft(draft));
  printf("\n");

  // display text
  printf("| ");
  int i;
  for (i = 0; i < TextDraft(draft).Length; i++) {
    printf("%c", TextDraft(draft).TabWord[i]);
  }

  printf("\n");
  printf("\n");
}

void editDraft(Draft *draft, Word newTextDraft, DATETIME newTimeCreatedDraft) {
  /* Mengganti text dan timeCreated dari suatu draft */

  TextDraft(*draft) = newTextDraft;
  TimeCreatedDraft(*draft) = newTimeCreatedDraft;
}
