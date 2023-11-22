#include "loadUtas.h"

void readDateTime(Word time, Word date, DATETIME *output) {
  int hh, mm, ss;
  splitTime(time, &hh, &mm, &ss);
  *output = splitDate(date, hh, mm, ss);
}

void ExtractWordAfterDash(const Word *inputWord, Word *outputWord) {
  /* Mengambil kata setelah tanda '-' pada inputWord dan menyimpannya di
     outputWord I.S. : inputWord terdefinisi F.S. : outputWord berisi kata
     setelah tanda '-', jika tidak ada tanda '-' atau bertemu dengan '\n', maka
     outputWord kosong */
  const int initialLength = inputWord->Length;
  const char *inputString = inputWord->TabWord;
  int indexFound = -1;
  int i = 0;

  // Temukan posisi tanda '-' pertama
  while (inputString[i] != '\0' && inputString[i] != '\n') {
    if (inputString[i] == '-') {
      indexFound = i;
      break;
    }
    i++;
  }
  if (indexFound != -1) {
    i = 0;
    while (inputString[indexFound + 1] != '\0' &&
           inputString[indexFound + 1] != '\n' &&
           indexFound < initialLength - 1) {
      outputWord->TabWord[i] = inputString[indexFound + 1];

      indexFound++;
      i++;
    }
    outputWord->TabWord[i] = '\0';
    outputWord->Length = i;
  } else {
    outputWord->TabWord[0] = '\0';
    outputWord->Length = 0;
  }
}

void readUtasConfig() {
  STARTWORDFILE("utas.config");

  int countKicauan;

  countKicauan = wordToInt(currentWordFile);
  ADVWORDFILE();
  Word idWord, text, idUtasWord, date, time, utasCountWord;
  int id, idUtas, utasCount;
  DATETIME dt;
  for (int i = 0; i < countKicauan; i++) {
    CopyWordwWord(&idWord, &currentWordFile);
    id = wordToInt(idWord);
    // printf("%d\n", id);
    ADVWORDFILE();

    // UTAS COUNT
    CopyWordwWord(&utasCountWord, &currentWordFile);
    utasCount = wordToInt(utasCountWord);
    // printf("counter: %d\n", utasCount);
    ADVWORDFILE();

    for (int i = 0; i < utasCount; i++) {
      // ID UTAS
      CopyWordwWord(&idUtasWord, &currentWordFile);
      ExtractWordAfterDash(&idUtasWord, &idUtasWord);
      idUtas = wordToInt(idUtasWord);
      // printWord(idUtasWord);
      // printf("\n");
      ADVWORDFILE();

      // Text
      CopyWordwWord(&text, &currentWordFile);
      // printWord(text);
      // printf("\n");

      // Datetime
      ADVWORDFILEnoBLANK();
      CopyWordwWord(&date, &currentWordFile);
      ADVWORDFILEnoBLANK();
      CopyWordwWord(&time, &currentWordFile);
      readDateTime(time, date, &dt);
      // TulisDATETIME(dt);
      // printf("\n");
      ADVWORDFILE();
    }
  }
}

int main() {
  readUtasConfig();
  return 0;
}