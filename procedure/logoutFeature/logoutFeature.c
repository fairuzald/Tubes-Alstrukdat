#include "logoutFeature.h"

void logoutFeature(Word* command, boolean sudahMasuk) {
  if (compareWordwString(*command, "DAFTAR")) {
    daftar();
  } else if (compareWordwString(*command, "MASUK")) {
    masuk();
  } else if (compareWordwString(*command, "KELUAR")) {
    keluar();
  } else {
    printf("Command yang anda pilih belum bisa dilakukan, masuk dulu, yuk!");
  }
}