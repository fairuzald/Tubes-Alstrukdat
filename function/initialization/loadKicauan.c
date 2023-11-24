#include "initialization.h"

void readKicauanConfig(char filePath[]) {
  CreateListDinTweet(&listTweetMain, 100);
  char fullPath[200];
  concat(filePath, "/kicauan.config", fullPath);
  boolean found = searchConfigFile(fullPath);
  if (!found) {
    printf("File %s tidak ditemukan.\n", fullPath);
    return;
  }
  STARTWORDFILE(fullPath);
  ADVFILE();

  int countKicauan;

  countKicauan = wordToInt(currentWordFile);
  ADVWORDFILE();
  Word idWord, text, date, time, like, author;
  int id, likeCount;
  DATETIME dt;
  AddressTweet tweet;
  for (int i = 0; i < countKicauan; i++) {
    CopyWordwWord(&idWord, &currentWordFile);
    int id = wordToInt(idWord);
    // printf("%d\n", id);
    ADVWORDFILE();

    CopyWordwWord(&text, &currentWordFile);
    // printWord(text);
    // printf("\n");
    ADVWORDFILE();

    CopyWordwWord(&like, &currentWordFile);
    likeCount = wordToInt(like);
    // printf("%d\n", likeCount);
    ADVWORDFILE();

    CopyWordwWord(&author, &currentWordFile);
    CropWord(&author, 20);
    // printWord(author);
    // printf("\n");

    ADVWORDFILEnoBLANK();
    CopyWordwWord(&date, &currentWordFile);
    ADVWORDFILEnoBLANK();
    CopyWordwWord(&time, &currentWordFile);
    readDateTime(time, date, &dt);
    tweet = CreateTweet(text, author, dt, id, 0, 0, likeCount, 0, NULL, NULL,
                        NULL, false);
    // displayTweet(tweet);
    insertLastListTweet(&listTweetMain, tweet);
    // TulisDATETIME(dt);
  }
}
