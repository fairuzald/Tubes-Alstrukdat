/* File: datetime.h */
/* Tanggal: 30 Agustus 2023 */
/* Definisi ADT DATETIME */

#ifndef DATETIME_H
#define DATETIME_H

#include "boolean.h"
#include "time.h"

/* *** Definisi TYPE DATETIME <DD/MM/YY HH:MM:SS> *** */
typedef struct {
  int DD;   /* integer [1..31] */
  int MM;   /* integer [1..12] */
  int YYYY; /* integer [1900..2030] */
  TIME T;
} DATETIME;

/* *** Notasi Akses: selektor DATETIME *** */
#define Day(D) (D).DD
#define Month(D) (D).MM
#define Year(D) (D).YYYY
#define Time(D) (D).T

/* *** Konstruktor: Membentuk sebuah DATETIME dari komponen-komponennya *** */

void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm,
                    int ss);
/* Membentuk sebuah DATETIME dari komponen-komponennya yang valid */
/* Prekondisi : DD, MM, YYYY, h, m, s valid untuk membentuk DATETIME */

/* Tulis DATETIME */

void TulisDATETIME(DATETIME D);
/* I.S. : D sembarang */
/* F.S. : Nilai D ditulis dg format DD/MM/YYYY HH:MM:SS */
/* Proses : menulis nilai setiap komponen D ke layar dalam format DD/MM/YYYY
   HH:MM:SS tanpa karakter apa pun di depan atau belakangnya, termasuk spasi,
   enter, dll.*/

/* Mendapatkan waktu lokal */

DATETIME getCurrentDateTime();
/* Mengembalikan waktu lokal saat ini */

#endif
