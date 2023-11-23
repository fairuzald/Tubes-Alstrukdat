/*
How to compile:
cd driver/adt
gcc datetime_driver.c ../../adt/datetime.c ../../adt/time.c -o datetime_driver

How to run:
./datetime_driver
*/

#include <stdio.h>

#include "../../adt/datetime.h"

int main() {
  // Membuat Datetime baru
  int day = 1;
  int month = 1;
  int year = 1;
  int hour = 0;
  int minute = 0;
  int second = 0;
  DATETIME myDatetime;
  CreateDATETIME(&myDatetime, day, month, year, hour, minute, second);

  // Menampilkan Datetime
  TulisDATETIME(myDatetime);
  printf("\n");

  // Mengambil waktu saat ini
  DATETIME currentTime = getCurrentDateTime();
  TulisDATETIME(currentTime);
  printf("\n");

  return 0;
}
