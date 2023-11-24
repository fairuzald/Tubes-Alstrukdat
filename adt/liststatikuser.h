#ifndef LISTSTATIKUSER_H
#define LISTSTATIKUSER_H

#include "boolean.h"
#include "input/charmachine.h"
#include "input/wordmachine.h"

/*ADT untuk user dan foto profil*/
typedef struct {
  char content[5][5];
  char color[5][5];
} PhotoMat;

#define CONTENT(M, i, j) (M).content[(i)][(j)]
#define COLOR(M, i, j) (M).color[(i)][(j)]

typedef struct {
  Word nama;     /* nama pengguna, unik*/
  Word password; /* password pengguna */
  Word bio;
  Word nomorHP;
  Word weton;
  boolean public;
  PhotoMat fotoProfil;
} User;

extern User currentUser;
extern boolean sudahMasuk;

/* ********** SELEKTOR ********** */
#define USER(i) (userList).contents[(i)]
#define NAMA(i) USER(i).nama
#define PASS(i) USER(i).password
#define BIO(i) USER(i).bio
#define HP(i) USER(i).nomorHP
#define WETON(i) USER(i).weton
#define PUBLIC(i) USER(i).public
#define FOTO(i) USER(i).fotoProfil

/*  Kamus Umum */
#define CAPACITYUSER 20
/* Kapasitas penyimpanan */
#define IDX_UNDEF_U -1
/* Indeks tak terdefinisi*/
#define EMPTY ""
/* Elemen string yang kosong*/

/* Definisi elemen dan koleksi objek */
typedef struct {
  User contents[CAPACITYUSER]; /* memori tempat penyimpan elemen (container) */
} ListStatikUser;
/* Definisi :
   List kosong: semua user berisi nilai bawaan (Word kosong untuk Word, 0 untuk
   nomor HP, true untuk public, dan simbol * merah untuk foto profil) Word
   kosong adalah word dengan TabWord "" dan length==0*/

extern ListStatikUser userList; /*men-global-kan userList*/

/* ********** KONSTRUKTOR ********** */
PhotoMat initPP();

void CreateuserList();

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya user *** */
int userCount();

/* *** Selektor INDEKS *** */
int getLastUserId();

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean noUsers();
/* *** Test List penuh *** */
boolean userFull();

/* ********** SEARCHING ********** */
int userIndex(Word val);

/* ********** MENAMBAH ELEMEN ********** */
void addUser(Word N, Word P);

void loadUser(Word N, Word P, Word B, Word HP, Word Weton, boolean Public, PhotoMat Foto);

void displayAllUsers();
#endif