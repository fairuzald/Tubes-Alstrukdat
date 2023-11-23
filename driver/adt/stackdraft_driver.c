/*
How to compile:
>> cd driver/adt
>> gcc stackdraft_driver.c ../../function/tweet_draft/tweet_draft.c
../../adt/stackdraft.c ../../adt/datetime.c
../../adt/time.c ../../adt/input/wordmachine.c ../../adt/input/charmachine.c -o
stackdraft_driver

How to run:
>> ./stackdraft_driver
*/

#include <stdio.h>

#include "../../adt/stackdraft.h"

int main() {
  // Membuat beberapa Draft
  Word text = stringToWord("Draf pertama saya !  hdawiud982167196%$%@!#");
  DATETIME time = getCurrentDateTime();
  Draft draftA;
  CreateDraft(&draftA, text, time);
  text = stringToWord("Draf kedua saya !  hdawiud982167196%$%@!#");
  time = getCurrentDateTime();
  Draft draftB;
  CreateDraft(&draftB, text, time);
  text = stringToWord("Draf ketiga saya !  hdawiud982167196%$%@!#");
  time = getCurrentDateTime();
  Draft draftC;
  CreateDraft(&draftC, text, time);

  // Membuat StackDraft kosong
  StackDraft myStackDraft;
  long capacity = 2;
  Word author = stringToWord("Maman Suraman");
  CreateEmptyStackDraft(&myStackDraft, capacity, author);

  // Cek apakah StackDraft kosong
  printf("Empty? (0/1): %d\n", IsEmptyStackDraft(myStackDraft));

  // Cek apakah StackDraft penuh
  printf("Full? (0/1): %d\n", IsFullStackDraft(myStackDraft));

  // Push elemen (Draft) ke dalam Stackdraft
  printf("Percobaan push:\n");
  Push(&myStackDraft, draftA);
  displayDraft(InfoTop(myStackDraft));
  printf("Empty? (0/1): %d\n", IsEmptyStackDraft(myStackDraft));
  printf("Full? (0/1): %d\n", IsFullStackDraft(myStackDraft));

  // Pop elemen teratas StackDraft
  printf("Percobaan pop:\n");
  Draft deletedDraft;
  Pop(&myStackDraft, &deletedDraft);
  displayDraft(deletedDraft);
  printf("Empty? (0/1): %d\n", IsEmptyStackDraft(myStackDraft));
  printf("Full? (0/1): %d\n", IsFullStackDraft(myStackDraft));

  // Menambah kapasitas StackDraft
  printf("Percobaan expand:\n");
  Push(&myStackDraft, draftA);
  displayDraft(InfoTop(myStackDraft));
  Push(&myStackDraft, draftB);
  displayDraft(InfoTop(myStackDraft));
  printf("Empty? (0/1): %d\n", IsEmptyStackDraft(myStackDraft));
  printf("Full? (0/1): %d\n", IsFullStackDraft(myStackDraft));
  expandStackDraft(&myStackDraft, 1);
  printf("Empty? (0/1): %d\n", IsEmptyStackDraft(myStackDraft));
  printf("Full? (0/1): %d\n", IsFullStackDraft(myStackDraft));
  Push(&myStackDraft, draftC);
  displayDraft(InfoTop(myStackDraft));
  printf("Empty? (0/1): %d\n", IsEmptyStackDraft(myStackDraft));
  printf("Full? (0/1): %d\n", IsFullStackDraft(myStackDraft));

  // Mengurangi kapasitas StackDraft
  printf("Percobaan shrink:\n");
  Pop(&myStackDraft, &deletedDraft);
  displayDraft(deletedDraft);
  printf("Empty? (0/1): %d\n", IsEmptyStackDraft(myStackDraft));
  printf("Full? (0/1): %d\n", IsFullStackDraft(myStackDraft));
  shrinkStackDraft(&myStackDraft, 1);
  printf("Empty? (0/1): %d\n", IsEmptyStackDraft(myStackDraft));
  printf("Full? (0/1): %d\n", IsFullStackDraft(myStackDraft));
  displayDraft(InfoTop(myStackDraft));

  // Dealokasi StackDraft
  dealocateStackDraft(&myStackDraft);

  return 0;
}
