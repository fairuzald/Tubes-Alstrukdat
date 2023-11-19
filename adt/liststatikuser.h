#ifndef LISTSTATIKUSER_H
#define LISTSTATIKUSER_H

#include "../function/user/user.h"
#include "boolean.h"
#include "input/wordmachine.h"

/*  Kamus Umum */
#define CAPACITY 20
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define EMPTY ""
/* Elemen string yang kosong*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef struct {
  User contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
} ListStatikUser;
/* Definisi :
   List kosong: semua user berisi nilai bawaan (Word kosong untuk Word, 0 untuk
   nomor HP, true untuk public, dan simbol * merah untuk foto profil) Word
   kosong adalah word dengan TabWord "" dan length==0*/

extern ListStatikUser userList; /*men-global-kan userList*/

/* ********** KONSTRUKTOR ********** */
void CreateuserList();
/* I.S. userList sembarang */
/* F.S. Terbentuk userList kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen userList sesuai nilai bawaan */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya user *** */
int userCount();
/* Mengirimkan banyaknya user yang terdaftar */
/* Mengirimkan nol jika belum ada user */

/* *** Selektor INDEKS *** */
IdxType getLastIdx();
/* Prekondisi : userList tidak kosong */
/* Mengirimkan indeks elemen userList terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxEff(IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk userList */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean noUsers();
/* Mengirimkan true jika userList kosong, mengirimkan false jika tidak */

/* *** Test List penuh *** */
boolean userFull();
/* Mengirimkan true jika userList penuh, mengirimkan false jika tidak */

/* ********** SEARCHING ********** */
int userIndex(Word val);
/* Search apakah ada user bernama val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */

/* ********** MENAMBAH ELEMEN ********** */
void addUser(Word N, Word P);
/* I.S. l terdefinisi dan tidak penuh, n dan p dipastikan valid*/
/* F.S. Ditambahkan 1 user dengan nama dan password terisi, sedangkan sisanya
 * value bawaan*/

void loadUser(Word N, Word P, Word B, Word HP, Word Weton, boolean Public,
              PhotoMat Foto);
void displayAllUsers();

#endif