#include "liststatikuser.h"

#include <stdio.h>

ListStatikUser userList;

/* ********** KONSTRUKTOR ********** */
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

void CreateuserList() {
  /* I.S. userList sembarang */
  /* F.S. Terbentuk userList kosong dengan kapasitas CAPACITY */
  /* Proses: Inisialisasi semua elemen userList sesuai nilai bawaan */
  /*KAMUS LOKAL*/
  int i, j, k;
  Word emptyWord;

  /*ALGORITMA*/
  /* Definisi Word kosong */
  emptyWord.TabWord[0] = BLANK;
  emptyWord.Length = 0;

  for (i = IDX_MIN; i < CAPACITY; i++) {
    NAMA(i) = emptyWord;
    PASS(i) = emptyWord;
    BIO(i) = emptyWord;
    HP(i) = emptyWord;
    WETON(i) = emptyWord;
    PUBLIC(i) = true;
    initPP(FOTO(i));
  }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya user *** */
int userCount() {
  /* Mengirimkan banyaknya user yang terdaftar */
  /* Mengirimkan nol jika belum ada user */
  /*kamus*/
  int counter;

  /*algoritma*/
  counter = 0;
  while (NAMA(counter).Length != 0 && counter < CAPACITY) {
    counter += 1;
  }
  return counter;
}

/* *** Selektor INDEKS *** */
int getLastIdx() {
  /* Prekondisi : userList tidak kosong */
  /* Mengirimkan indeks elemen userList terakhir */
  return (userCount() - 1);
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean noUsers() {
  /* Mengirimkan true jika userList kosong, mengirimkan false jika tidak */
  return (userCount() == 0);
}
/* *** Test List penuh *** */
boolean userFull() {
  /* Mengirimkan true jika userList l penuh, mengirimkan false jika tidak */
  return (userCount() == CAPACITY);
}

/* ********** SEARCHING ********** */
int userIndex(Word val) {
  /* Search apakah ada user bernama val */
  /* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
  /*kamus*/
  int i;

  /*algoritma*/
  if (noUsers()) {
    return IDX_UNDEF;
  } else {
    for (i = IDX_MIN; i <= getLastIdx(); i++) {
      if (compareWordwWord(NAMA(i), val)) {
        return i;
      }
    }
    return IDX_UNDEF;
  }
}

/* ********** MENAMBAH ELEMEN ********** */
void addUser(Word N, Word P) {
  /* I.S. l terdefinisi dan tidak penuh, n dan p dipastikan valid*/
  /* F.S. Ditambahkan 1 user dengan nama dan password terisi, sedangkan sisanya
   * value bawaan*/
  /*KAMUS LOKAL*/
  int i;

  /*ALGORITMA*/
  i = userCount();
  NAMA(i) = N;
  PASS(i) = P;
}

void loadUser(Word N, Word P, Word B, Word HP, Word Weton, boolean Public,
              PhotoMat Foto) {
  if (!userFull()) {
    int idx = getLastIdx() + 1;
    NAMA(idx) = N;
    PASS(idx) = P;
    BIO(idx) = B;
    HP(idx) = HP;
    WETON(idx) = Weton;
    PUBLIC(idx) = Public;
    FOTO(idx) = Foto;
  }
}

void displayAllUsers() {
  if (noUsers()) {
    printf("No users found.\n");
  } else {
    printf("List of Users:\n");
    printf("=====================\n");

    for (int i = IDX_MIN; i <= getLastIdx(); i++) {
      printf("Index: %d\n", i);
      printf("Name: %s\n", NAMA(i).TabWord);
      printf("Password: %s\n", PASS(i).TabWord);
      printf("Bio: %s\n", BIO(i).TabWord);
      printf("HP: %s\n", HP(i).TabWord);
      printf("Weton: %s\n", WETON(i).TabWord);
      printf("Public: %s\n", (PUBLIC(i) ? "true" : "false"));
      printf("---------------------\n");
    }

    printf("=====================\n");
  }
}