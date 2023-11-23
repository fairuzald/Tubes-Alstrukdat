/*
How to compile:
>> cd driver
>> gcc tweet_draft_driver.c ../function/tweet_draft/tweet_draft.c
../adt/datetime.c ../adt/time.c
../adt/input/wordmachine.c ../adt/input/charmachine.c -o tweet_draft_driver

How to run:
>> ./tweet_draft_driver
*/

#include "../function/tweet_draft/tweet_draft.h"

int main() {
  Word textA = stringToWord("Draf pertama saya !  hdawiud982167196%$%@!#");
  DATETIME timeA = getCurrentDateTime();
  Draft draftA;

  // Membuat Draft baru
  CreateDraft(&draftA, textA, timeA);

  // Menampilkan Draft
  displayDraft(draftA);

  // Mengubah isi Draft
  Word textARevision = stringToWord("Draf sudah   diedit 696969##$$&$&");
  DATETIME timeARevision = getCurrentDateTime();
  editDraft(&draftA, textARevision, timeARevision);
  displayDraft(draftA);

  return 0;
}
