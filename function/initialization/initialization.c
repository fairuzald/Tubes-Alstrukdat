#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "../../adt/input/charmachine.h"
#include "../../adt/input/wordmachine.h"
#include "loadUser.h"

struct stat st;
Word configFolder;
// Function to construct the path from folderPath and folderName
void constructPath(const Word *folderPath, const Word *folderName, char *path) {
  int i;
  for (i = 0; i < folderPath->Length && folderPath->TabWord[i] != '\0'; ++i) {
    path[i] = folderPath->TabWord[i];
  }

  // Append folderName to path
  int j;
  for (j = 0; i < folderPath->Length && folderName->TabWord[j] != '\0';
       ++i, ++j) {
    path[i] = folderName->TabWord[j];
  }

  path[i] = '\0';  // Null-terminate the string
}

// Folder config search
boolean searchConfigFolder(Word folderName) {
  // Membuat path lengkap untuk folder konfigurasi
  Word folderPath;
  Word configFolder;
  configFolder = stringToWord("config/");
  ConcatWords(&folderPath, &configFolder, &folderName);

  // Construct the path
  char path[folderPath.Length + folderName.Length];
  constructPath(&folderPath, &folderName, path);

  // Pengecekan keberadaan folder
  struct stat st;
  if (stat(path, &st) == -1) {
    printf("Folder %s tidak ditemukan.\n", folderName.TabWord);
    return false;
  } else {
    printf("Folder %s ditemukan!\n", folderName.TabWord);
    return true;
  }
}

boolean searchConfigFile(Word fileName) {
  // Membuat path lengkap untuk file konfigurasi
  Word filePath;
  ConcatWords(&filePath, &configFolder, &fileName);

  // Construct the path
  char path[configFolder.Length + fileName.Length];
  constructPath(&configFolder, &fileName, path);

  // Pengecekan keberadaan file
  if (stat(path, &st) == -1) {
    printf("File %s tidak ditemukan.\n", fileName.TabWord);
    return false;
  } else {
    printf("File %s ditemukan!\n", fileName.TabWord);
    return true;
  }
}

void initialization() {
  printf("Silakan masukan folder konfigurasi untuk dimuat: ");
  readWord();
  CopyWordwWord(&configFolder, &currentWord);

  if (!searchConfigFolder(configFolder)) {
    printf("Initialization failed. Folder not found.\n");
    return;
  }

  // Assume your configuration file is named "pengguna.config"
  Word configFileName = stringToWord("pengguna.config");

  if (!searchConfigFile(configFileName)) {
    printf("Initialization failed. Configuration file not found.\n");
    return;
  }

  // If both folder and file are found, proceed with reading the configuration
  readUserConfig();
}

int main() { return 0; }