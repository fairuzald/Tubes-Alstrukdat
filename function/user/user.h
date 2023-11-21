#include "../../adt/liststatikuser.h"
#include "../../adt/input/wordmachine.h"

#ifndef USER_H
#define USER_H

boolean cekUnik(Word w);
/*true jika w tidak ada di dalam l, digunakan untuk mengecek keunikan nama
 * pengguna*/

void daftar();
/*prosedur pendaftaran user*/

void masuk();
/*prosedur log-in*/

void keluar();
/*prosedur log-out*/

#endif