#include "initialization.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void readDateTime(Word time, Word date, DATETIME *output) {
  int hh, mm, ss;
  splitTime(time, &hh, &mm, &ss);
  *output = splitDate(date, hh, mm, ss);
}

void ExtractWordAfterDash(const Word *inputWord, Word *outputWord) {
  const int initialLength = inputWord->Length;
  const char *inputString = inputWord->TabWord;
  int indexFound = -1;
  int i = 0;

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

boolean searchConfigFolder(char path[200]) {
  struct stat st;
  if (stat(path, &st) == -1) {
    printf("Folder %s tidak ditemukan.\n", path);
    return false;
  } else {
    printf("Folder %s ditemukan!\n", path);
    return true;
  }
}
boolean searchConfigFile(char path[200]) {
  struct stat st;
  if (stat(path, &st) == -1) {
    return false;
  } else {
    return true;
  }
}

void loadSemuaConfig(Word *folderName) {
  Word configPath;
  concat("config/", folderName->TabWord, configPath.TabWord);
  configPath.Length = folderName->Length + 7;
  if (!searchConfigFolder(configPath.TabWord)) {
    return;
  }

  readUserConfig(configPath.TabWord);
  readKicauanConfig(configPath.TabWord);
  readDrafConfig(configPath.TabWord);
  // readUtasConfig(folderName->TabWord);
  // readBalasanConfig(folderName->TabWord);
}

void initialization(Word *command) {
  printf("Silakan masukan folder konfigurasi untuk dimuat: ");
  readInputNoIgnore(command);
  loadSemuaConfig(command);
  printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");
}
