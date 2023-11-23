#include "../reply/reply.h"
#include "initialization.h"

void readBalasanConfig(char filePath[]) {
  char fullPath[1000];
  concat(filePath, "/balasan.config", fullPath);
  STARTWORDFILE(fullPath);

  int countKicauan;

  countKicauan = wordToInt(currentWordFile);
  ADVWORDFILE();
  Word idWord, text, idParentWord, idReplierWord, date, time, replyCountWord,
      replyAuthor;
  int id, idUtas, replyCount, idParent, idReplier;
  DATETIME dt;
  for (int i = 0; i < countKicauan; i++) {
    // ID kicauan
    CopyWordwWord(&idWord, &currentWordFile);
    id = wordToInt(idWord);
    // printf("%d\n", id);
    ADVWORDFILE();

    // Reply COUNTor
    CopyWordwWord(&replyCountWord, &currentWordFile);
    replyCount = wordToInt(replyCountWord);
    ADVWORDFILEnoBLANK();

    for (int j = 0; j < replyCount; j++) {
      // ID Parent
      CopyWordwWord(&idParentWord, &currentWordFile);
      ExtractWordAfterDash(&idParentWord, &idReplierWord);
      idParent = wordToInt(idParentWord);
      // printf("id: %d", idParent);
      // printf("\n");
      ADVWORDFILEnoBLANK();

      // ID Replier
      CopyWordwWord(&idReplierWord, &currentWordFile);
      idReplier = wordToInt(idReplierWord);
      // printf("id: %d", idReplier);
      // printf("\n");
      ADVWORDFILE();

      // Text
      CopyWordwWord(&text, &currentWordFile);
      printWord(text);
      // printf("\n");
      ADVWORDFILE();

      // Author
      CopyWordwWord(&replyAuthor, &currentWordFile);
      printWord(replyAuthor);
      // printf("\n");
      ADVWORDFILEnoBLANK();

      // Datetime
      CopyWordwWord(&date, &currentWordFile);
      ADVWORDFILEnoBLANK();
      CopyWordwWord(&time, &currentWordFile);
      readDateTime(time, date, &dt);
      // TulisDATETIME(dt);
      // printf("\n");
      ADVWORDFILEnoBLANK();
      // CreateReply(text, replyAuthor, dt, idParent, idReplier);
    }
  }
}
