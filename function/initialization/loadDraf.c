#include "initialization.h"

void readDrafConfig(char filePath[]) {
  CreateListStackDraft(&listStackDraftMain);
  char fullPath[200];
  concat(filePath, "/draf.config", fullPath);
  boolean found = searchConfigFile(fullPath);
  if (!found) {
    printf("File %s tidak ditemukan.\n", fullPath);
    return;
  }
  STARTWORDFILE(fullPath);
  ADVFILE();

  int countUser;

  countUser = wordToInt(currentWordFile);
  // printf("%d\n", countUser);

  ADVWORDFILE();
  Word nama, draf, date, time, clock;
  DATETIME dt;
  int countDraf;
  for (int i = 0; i < countUser; i++) {
    StackDraft stackDraft;
    countDraf = currentWordFile.TabWord[currentWordFile.Length - 1] - '0';
    // Nama
    CropWord(&currentWordFile, currentWordFile.Length - 2);
    CopyWordwWord(&nama, &currentWordFile);
    CropWord(&nama, 20);
    // printWord(nama);
    // printf("\n");
    ADVWORDFILE();

    CreateEmptyStackDraft(&stackDraft, 20, nama);

    for (int j = 0; j < countDraf; j++) {
      Draft draft;
      // Text
      CopyWordwWord(&draf, &currentWordFile);
      // printWord(draf);
      // printf("\n");
      ADVWORDFILEnoBLANK();
      // Date
      CopyWordwWord(&date, &currentWordFile);
      ADVWORDFILEnoBLANK();
      CopyWordwWord(&time, &currentWordFile);
      readDateTime(time, date, &dt);
      ADVWORDFILE();
      // TulisDATETIME(dt);
      // printf("\n");
      CreateDraft(&draft, draf, dt);
      Push(&stackDraft, draft);
    }
    insertLastListStackDraft(&listStackDraftMain, stackDraft);
  }
}