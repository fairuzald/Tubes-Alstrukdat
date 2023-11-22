
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

void initialization(Word *command) {
  printf("Silakan masukan folder konfigurasi untuk dimuat: ");
  readInputNoIgnore(command);
  Word configFolder;
  CopyWordwWord(&configFolder, &currentWord);
  printWord(configFolder);
  char path[200];
  configFolder.TabWord[configFolder.Length] = '\0';
  printWord(configFolder);
  if (!searchConfigFolder(path)) {
    return;
  }

  readUserConfig(path);
  readUtasConfig(path);
  readDrafConfig(path);
  readKicauanConfig(path);
  readBalasanConfig(path);

  printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");
}

int main() {
  Word command;
  initialization(&command);

  return 0;
}