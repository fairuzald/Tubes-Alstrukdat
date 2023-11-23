#include <stdio.h>

#include "function/error/error.h"
#include "function/input/input.h"
#include "procedure/globalFeature/globalFeature.h"
#include "procedure/loginFeature/loginFeature.h"
#include "procedure/logoutFeature/logoutFeature.h"
#include "procedure/splashscreen.h"

int main() {
  welcome();
  /*DISINI CONFIG*/

  CreateuserList();
  sudahMasuk = false;
  Word command;

  /*contoh main, buat testing- belum final*/
  printf("\nSilakan masukkan command: \n");
  readInput(&command);
  while (!compareWordwString(command, "TUTUP_PROGRAM")) {
    globalFeature(&command);
    if (!sudahMasuk) {
      logoutFeature(&command, sudahMasuk);
    } else {
      loginFeature(&command, sudahMasuk);
    }
    printf("\nSilakan masukkan command: \n");
    readInput(&command);
  }
  printf(
      "\nAnda telah keluar dari program BurBir. Sampai jumpa di penjelajahan "
      "berikutnya.\n");

  return 0;
}