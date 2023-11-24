#ifndef PROFILE_H
#define PROFILE_H
#include "../../adt/input/wordmachine.h"
#include "../../adt/input/charmachine.h"
#include "../../adt/boolean.h"
#include "../pcolor/pcolor.h"
#include "../user/user.h"
#include "../friend/friend.h"



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

void displayPhoto(PhotoMat m);
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

void ganti_profil();
/*Digunakan untuk mengganti isi profil Currentuser (selain foto profil dan jenis akun)*/

void lihat_profil(Word Username, Graph grafPertemanan);
/*Digunakan untuk melihat profil milik Username*/

void atur_jenis_akun();
/*Digunakan untuk mengganti jenis akun Currentuser*/

void ubah_foto_profil();
/*Digunakan untuk mengubah foto profil Currentuser*/
#endif
