#include "tweet_draft.h"

#include <stdio.h>

/* Constructor Draft */

void CreateDraft(Draft *draft, Word text, DATETIME timeCreated) {
  TextDraft(*draft) = text;
  TimeCreatedDraft(*draft) = timeCreated;
}

/* Fungsi/prosedur Lain*/

void displayDraft(Draft draft) {
  printf("| ");
  TulisDATETIME(TimeCreatedDraft(draft));
  printf("\n");

  printf("| ");
  int i;
  for (i = 0; i < TextDraft(draft).Length; i++) {
    printf("%c", TextDraft(draft).TabWord[i]);
  }

  printf("\n");
}

void editDraft(Draft *draft, Word newText, DATETIME newTime) {
  TextDraft(*draft) = newText;
  TimeCreatedDraft(*draft) = newTime;
}
