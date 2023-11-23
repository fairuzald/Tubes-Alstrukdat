/*
How to compile:
>> cd driver/adt
>> gcc time_driver.c ../../adt/time.c -o time_driver

How to run:
>> ./time_driver
*/

#include <stdio.h>

#include "../../adt/time.h"

int main() {
  // Membuat Time baru
  int hour = 23;
  int minute = 59;
  int second = 59;
  TIME myTime;
  CreateTime(&myTime, hour, minute, second);

  // Menampilkan Time
  TulisTIME(myTime);
  printf("\n");

  return 0;
}
