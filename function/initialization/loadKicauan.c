#include "initialization.h"

void readKicauanConfig(char filePath[]) {
  char fullPath[1000];
  concat(filePath, "/kicauan.config", fullPath);
  STARTWORDFILE(fullPath);
  CreateListDinTweet(&listTweetMain, 100);

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
    displayTweet(tweet);
    insertLastListTweet(&listTweetMain, tweet);
    // TulisDATETIME(dt);
    ADVWORDFILE();
  }
}
