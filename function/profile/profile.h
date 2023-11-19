#include "../../adt/input/wordmachine.h"
#include "../pcolor/pcolor.h"
#ifndef PROFILE_H
#define PROFILE_H

typedef int IdxType;
typedef struct {
  char content[5][5];
  char color[5][5];
} PhotoMat;
#define CONTENT(M, i, j) (M).content[(i)][(j)]
#define COLOR(M, i, j) (M).color[(i)][(j)]

void initPP(PhotoMat P);
/* Menginitialisasi foto profil */

void readMatrix(PhotoMat *m, int nRow, int nCol);
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/

void displayMatrix(PhotoMat m);
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen
   per baris dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan
   newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan
 * per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
#endif