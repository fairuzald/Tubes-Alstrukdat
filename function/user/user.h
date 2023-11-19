#include "../../adt/liststatikuser.h"
#include "../profile/profile.h"

#ifndef USER_H
#define USER_H

typedef struct {
  Word nama;     /* nama pengguna, unik*/
  Word password; /* password pengguna */
  Word bio;
  Word nomorHP;
  Word weton;
  boolean public;
  PhotoMat fotoProfil;
} User;

/* ********** SELEKTOR ********** */
#define USER(i) (userList).contents[(i)]
#define NAMA(i) USER(i).nama
#define PASS(i) USER(i).password
#define BIO(i) USER(i).bio
#define HP(i) USER(i).nomorHP
#define WETON(i) USER(i).weton
#define PUBLIC(i) USER(i).public
#define FOTO(i) USER(i).fotoProfil

extern User currentUser;
extern boolean sudahMasuk;

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