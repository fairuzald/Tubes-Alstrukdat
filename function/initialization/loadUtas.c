#include "initialization.h"
#include "utas.h"

void readUtasConfig(char filePath[]) {
  char fullPath[1000];
  concat(filePath, "/utas.config", fullPath);
  STARTWORDFILE(fullPath);

  int countKicauan;

  countKicauan = wordToInt(currentWordFile);
  ADVWORDFILE();
  Word idWord, author, text, date, time, utasCountWord;
  int id, idUtas, utasCount;
  DATETIME dt;
  for (int i = 0; i < countKicauan; i++) {
    CopyWordwWord(&idWord, &currentWordFile);
    id = wordToInt(idWord);
    printf("%d\n", id);
    ADVWORDFILE();

    // UTAS COUNT
    CopyWordwWord(&utasCountWord, &currentWordFile);
    utasCount = wordToInt(utasCountWord);
    printf("counter: %d\n", utasCount);
    ADVWORDFILE();

    for (int j = 0; j < utasCount; j++) {
      // Text
      CopyWordwWord(&text, &currentWordFile);

      printf("\n");
      ADVWORDFILE();

      // author
      CopyWordwWord(&author, &currentWordFile);
      printWord(author);
      printf("\n");

      // Datetime
      ADVWORDFILEnoBLANK();
      CopyWordwWord(&date, &currentWordFile);
      ADVWORDFILEnoBLANK();
      CopyWordwWord(&time, &currentWordFile);
      readDateTime(time, date, &dt);
      // TulisDATETIME(dt);
      printf("\n");
      // CreateUtas(text, author, dt, j,);
      ADVWORDFILE();
    }
  }
}