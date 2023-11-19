#include "profile.h"

#include <stdio.h>
void initPP(PhotoMat P) {
  /* Menginitialisasi foto profil */
  /*KAMUS LOKAL*/
  int i, j;

  /*ALGORITMA*/
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      CONTENT(P, i, j) = '*';
      COLOR(P, i, j) = 'R';
    }
  }
}

void displayMatrix(PhotoMat m) {
  /* I.S. m terdefinisi */
  /* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing
  elemen per baris dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan
  newline */
  /* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris
   * dan per kolom */
  /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
  1 2 3
  4 5 6
  8 9 10
  */

  IdxType i, j;

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      if (COLOR(m, i, j) == 'R') {
        print_red(CONTENT(m, i, j));
      } else if (COLOR(m, i, j) == 'G') {
        print_green(CONTENT(m, i, j));
      } else {
        print_blue(CONTENT(m, i, j));
      }
      if (j == 4) {
        printf("\n");
      }
    }
  }
}
