/* File: time.c */
/* Tanggal: 30 Agustus 2023 */
/* Realisasi ADT TIME */

#include "time.h"

#include <stdio.h>

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */

void CreateTime(TIME* T, int HH, int MM, int SS) {
  /* Membentuk sebuah TIME dari komponen-komponennya yang valid */
  /* Prekondisi : HH, MM, SS valid untuk membentuk TIME */
  Hour(*T) = HH;
  Minute(*T) = MM;
  Second(*T) = SS;
}

/* Tulis TIME */

void TulisTIME(TIME T) {
  /* I.S. : T sembarang */
  /* F.S. : Nilai T ditulis dg format HH:MM:SS */
  /* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
     tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter,
     dll.*/
  printf("%02d:%02d:%02d", Hour(T), Minute(T), Second(T));
}
