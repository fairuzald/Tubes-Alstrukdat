#include "logoutFeature.h"

void loadFromFolder(char* folderName) {
  printf("Anda akan melakukan pemuatan dari %s.\n\n", folderName);
  for (int i = 1; i <= 3; i++) {
    printf("%d...\n", i);
  }

  printf("Pemuatan selesai!\n\n");
}

void muat(boolean sudahMasuk) {
  if (sudahMasuk) {
    printf("Anda harus keluar terlebih dahulu sebelum melakukan pemuatan!\n\n");
    return;
  }
  char fullPath[200];
  Word folderName;
  struct stat st = {0};

  printf("Masukkan nama folder yang hendak dimuat.\n");
  readInputNoIgnore(&folderName);
  folderName.TabWord[folderName.Length] = '\0';
  concat("config/", folderName.TabWord, fullPath);
  if (stat(fullPath, &st) == -1) {
    printf("Tidak ada folder yang dimaksud!\n\n");
  } else {
    loadSemuaConfig(&folderName);
    loadFromFolder(fullPath);
  }
}

void logoutFeature(Word* command, boolean sudahMasuk) {
  if (compareWordwString(*command, "DAFTAR")) {
    ADV();
    daftar();
  } else if (compareWordwString(*command, "MASUK")) {
    ADV();
    masuk();
  } else if (compareWordwString(*command, "KELUAR")) {
    ADV();
    keluar();
  } else if (compareWordwString(*command, "MUAT")) {
    ADV();
    muat(sudahMasuk);
  } else {
    printf("Command yang anda pilih belum bisa dilakukan, masuk dulu, yuk!");
  }
}