/*
How to compile:
>> cd driver/adt
>> gcc liststackdraft_driver.c ../../adt/liststackdraft.c
../../function/tweet_draft/tweet_draft.c ../../adt/stackdraft.c
../../adt/datetime.c
../../adt/time.c ../../adt/input/wordmachine.c ../../adt/input/charmachine.c -o
liststackdraft_driver

How to run:
./liststackdraft_driver
*/

#include <stdio.h>

#include "../../adt/liststackdraft.h"

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

  // Membuat beberapa StackDraft
  StackDraft myStackDraftA;
  long capacityA = 2;
  Word authorA = stringToWord("Maman Suraman");
  CreateEmptyStackDraft(&myStackDraftA, capacityA, authorA);
  Push(&myStackDraftA, draftA);

  StackDraft myStackDraftB;
  long capacityB = 2;
  Word authorB = stringToWord("Dudung Surudung");
  CreateEmptyStackDraft(&myStackDraftB, capacityB, authorB);
  Push(&myStackDraftB, draftA);
  Push(&myStackDraftB, draftB);

  StackDraft myStackDraftC;
  long capacityC = 3;
  Word authorC = stringToWord("Eva");
  CreateEmptyStackDraft(&myStackDraftC, capacityC, authorC);
  Push(&myStackDraftC, draftA);
  Push(&myStackDraftC, draftB);
  Push(&myStackDraftC, draftC);

  // Membuat ListStackDraft
  ListStackDraft myListStackDraft;
  CreateListStackDraft(&myListStackDraft);

  // Banyak elemen
  printf("Banyak elemen: %d\n", listStackDraftLength(myListStackDraft));

  // Cek apakah list kosong
  printf("Empty? (0/1): %d\n", isEmptyListStackDraft(myListStackDraft));

  // Cek apakah list penuh
  printf("Full? (0/1): %d\n", isFullListStackDraft(myListStackDraft));

  // Mencari index StackDraft dengan username
  printf("Index: %d\n",
         indexOfAuthorDraft(myListStackDraft, stringToWord("Dudung Surudung")));

  // Memasukkan StackDraft ke dalam list
  insertLastListStackDraft(&myListStackDraft, myStackDraftA);
  printf("Banyak elemen: %d\n", listStackDraftLength(myListStackDraft));
  printf("Empty? (0/1): %d\n", isEmptyListStackDraft(myListStackDraft));
  printf("Full? (0/1): %d\n", isFullListStackDraft(myListStackDraft));
  printf("Index: %d\n",
         indexOfAuthorDraft(myListStackDraft, stringToWord("Dudung Surudung")));

  insertLastListStackDraft(&myListStackDraft, myStackDraftB);
  insertLastListStackDraft(&myListStackDraft, myStackDraftC);
  printf("Banyak elemen: %d\n", listStackDraftLength(myListStackDraft));
  printf("Empty? (0/1): %d\n", isEmptyListStackDraft(myListStackDraft));
  printf("Full? (0/1): %d\n", isFullListStackDraft(myListStackDraft));
  int index =
      indexOfAuthorDraft(myListStackDraft, stringToWord("Dudung Surudung"));
  printf("Index: %d\n", index);
  displayDraft(InfoTop(ELMT_LISTSTACKDRAFT(myListStackDraft, index)));

  return 0;
}
