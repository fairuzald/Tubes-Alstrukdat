
#include "initialization.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void concat(char *str1, char *str2, char *output) {
  int i, j;
  for (i = 0; str1[i] != '\0'; ++i) {
    output[i] = str1[i];
  }

  for (j = 0; str2[j] != '\0'; ++j, ++i) {
    output[i] = str2[j];
  }

  output[i] = '\0';
}

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

// Folder config search
boolean searchConfigFolder(char path[1000]) {
  // Membuat path lengkap untuk folder konfigurasi

  // Pengecekan keberadaan folder
  struct stat st;
  if (stat(path, &st) == -1) {
    printf("Folder %s tidak ditemukan.\n", path);
    return false;
  } else {
    printf("Folder %s ditemukan!\n", path);
    return true;
  }
}

void loadSemuaConfig(Word *folderName) {
  Word configFolder;
  CopyWordwWord(&configFolder, &folderName);
  char path[200];
  configFolder.TabWord[configFolder.Length] = '\0';
  if (!searchConfigFolder(path)) {
    return;
  }

  readUserConfig(path);
  readUtasConfig(path);
  readDrafConfig(path);
  readKicauanConfig(path);
  readBalasanConfig(path);
}
void initialization(Word *command) {
  printf("Silakan masukan folder konfigurasi untuk dimuat: ");
  readInputNoIgnore(command);
  loadSemuaConfig(command);
  printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");
}
