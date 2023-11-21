#include "datetime.h"

#include <stdio.h>
#include <time.h>

/* *** Konstruktor: Membentuk sebuah DATETIME dari komponen-komponennya *** */

void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm,
                    int ss) {
  /* Membentuk sebuah DATETIME dari komponen-komponennya yang valid */
  /* Prekondisi : DD, MM, YYYY, h, m, s valid untuk membentuk DATETIME */

  Day(*D) = DD;
  Month(*D) = MM;
  Year(*D) = YYYY;
  CreateTime(&Time(*D), hh, mm, ss);
}

/* Tulis DATETIME */

void TulisDATETIME(DATETIME D) {
  /* I.S. : D sembarang */
  /* F.S. : Nilai D ditulis dg format DD/MM/YYYY HH:MM:SS */
  /* Proses : menulis nilai setiap komponen D ke layar dalam format DD/MM/YYYY
     HH:MM:SS tanpa karakter apa pun di depan atau belakangnya, termasuk spasi,
     enter, dll.*/

  printf("%02d/%02d/%04d ", Day(D), Month(D), Year(D));
  TulisTIME(Time(D));
}

/* Mendapatkan waktu lokal */

DATETIME getCurrentDateTime() {
  /* Mengembalikan waktu lokal saat ini */

  time_t t = time(NULL);
  struct tm *p;
  p = localtime(&t);
  DATETIME dt;
  CreateDATETIME(&dt, p->tm_mday, p->tm_mon + 1, p->tm_year + 1900, p->tm_hour,
                 p->tm_min, p->tm_sec);
  return dt;
}
