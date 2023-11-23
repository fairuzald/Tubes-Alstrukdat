#include "initialization.h"

void readDrafConfig(char filePath[]) {
  char fullPath[1000];
  concat(filePath, "/draf.config", fullPath);
  STARTWORDFILE(fullPath);
  CreateListStackDraft(&listStackDraftMain);

  int countUser;

  countUser = wordToInt(currentWordFile);
  ADVWORDFILE();
  Word nama, draf, date, time, clock;
  DATETIME dt;
  int countDraf;
  for (int i = 0; i < countUser; i++) {
    StackDraft stackDraft;
    countDraf = currentWordFile.TabWord[currentWordFile.Length - 1] - '0';
    CropWord(&currentWordFile, currentWordFile.Length - 2);
    CopyWordwWord(&nama, &currentWordFile);
    CropWord(&nama, 20);
    ADVWORDFILE();
    CreateEmptyStackDraft(&stackDraft, 20, nama);
    for (int j = 0; j < countDraf; j++) {
      Draft draft;
      CopyWordwWord(&draf, &currentWordFile);
      ADVWORDFILEnoBLANK();
      CopyWordwWord(&date, &currentWordFile);
      ADVWORDFILEnoBLANK();
      CopyWordwWord(&time, &currentWordFile);
      readDateTime(time, date, &dt);
      ADVWORDFILE();
      CreateDraft(&draft, draf, dt);
      Push(&stackDraft, draft);
    }
    insertLastListStackDraft(&listStackDraftMain, stackDraft);
  }
}