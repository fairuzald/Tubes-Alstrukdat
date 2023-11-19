#include "matrix.h"

#include <stdio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m) {
  /* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di
   * "ujung kiri" memori */
  /* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
  /* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
  ROW_EFF(*m) = nRows;
  COL_EFF(*m) = nCols;
}

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j) {
  /* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
  return ((i >= 0) && (i < ROW_CAP) && (j >= 0) && (j < COL_CAP));
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m) {
  /* Mengirimkan Index baris terbesar m */
  return ((ROW_EFF(m) - 1));
}

IdxType getLastIdxCol(Matrix m) {
  /* Mengirimkan Index kolom terbesar m */
  return ((COL_EFF(m) - 1));
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j) {
  /* Mengirimkan true jika i, j adalah Index efektif bagi m */
  return ((i >= 0) && (i < ROW_EFF(m)) && (j >= 0) && (j < COL_EFF(m)));
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut) {
  /* Melakukan assignment mOut <- mIn */
  createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
  for (int i = 0; i < ROW_EFF(mIn); i++) {
    for (int j = 0; j < COL_EFF(mIn); j++) {
      ELMT(*mOut, i, j) = ELMT(mIn, i, j);
    }
  }
}

void displayMatrix(Matrix m) {
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
  for (int i = 0; i < ROW_EFF(m); i++) {
    for (int j = 0; j < COL_EFF(m) - 1; j++) {
      printf("%c ", ELMT(m, i, j));
    }
    printf("%c\n", ELMT(m, i, COL_EFF(m) - 1));
  }
}

/* ********** Operasi lain ********** */
int countElmt(Matrix m) {
  /* Mengirimkan banyaknya elemen m */
  return (ROW_EFF(m) * COL_EFF(m));
}
