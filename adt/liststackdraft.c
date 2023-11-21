#include "liststackdraft.h"

#include <stdio.h>

const MAX_CHOICE_LENGTH = 7;

/* ********** KONSTRUKTOR ********** */

/* Konstruktor : create List kosong  */

void CreateListStackDraft(ListStackDraft *l) {
  /* I.S. l sembarang */
  /* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY_LISTSTACKDRAFT */
  /* Proses: Inisialisasi nEff = 0 */

  NEFF_LISTSTACKDRAFT(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */

/* *** Banyaknya elemen *** */

int listStackDraftLength(ListStackDraft l) {
  /* Mengirimkan banyaknya elemen efektif List */
  /* Mengirimkan nol jika List kosong */

  return NEFF_LISTSTACKDRAFT(l);
}

/* ********** TEST KOSONG/PENUH ********** */

/* *** Test List kosong *** */

boolean isEmptyListStackDraft(ListStackDraft l) {
  /* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */

  return 0 == NEFF_LISTSTACKDRAFT(l);
}

/* *** Test List penuh *** */

boolean isFullListStackDraft(ListStackDraft l) {
  /* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

  return CAPACITY_LISTSTACKDRAFT == NEFF_LISTSTACKDRAFT(l);
}

/* ********** SEARCHING ********** */

/* ***  Perhatian : List boleh kosong!! *** */

int indexOfAuthorDraft(ListStackDraft l, Word authorDraft) {
  /* Search apakah ada elemen List l yang atribut authorDraft-nya bernilai
   * "authorDraft" */
  /* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF_LISTSTACKDRAFT */

  if (isEmptyListStackDraft(l)) {
    return IDX_UNDEF_LISTSTACKDRAFT;
  }

  boolean found = false;
  int i = 0;
  while (!found && i < listStackDraftLength(l)) {
    if (compareWordwWord(AuthorDraft(ELMT_LISTSTACKDRAFT(l, i)), authorDraft)) {
      found = true;
    } else {
      i++;
    }
  }

  if (found) {
    return i;
  }

  return IDX_UNDEF_LISTSTACKDRAFT;
}

/* ********** MENAMBAH ELEMEN ********** */

/* *** Menambahkan elemen terakhir *** */

void insertLastListStackDraft(ListStackDraft *l, ElType val) {
  /* Proses: Menambahkan val sebagai elemen terakhir List */
  /* I.S. List l boleh kosong, tetapi tidak penuh */
  /* F.S. val adalah elemen terakhir l yang baru */

  if (isEmpty(*l)) {
    ELMT_LISTSTACKDRAFT(*l, IDX_MIN_LISTSTACKDRAFT) = val;
  } else {
    ELMT_LISTSTACKDRAFT(*l, listStackDraftLength(*l)) = val;
  }

  NEFF_LISTSTACKDRAFT(*l)++;
}

/* Fitur-Fitur Utama */

void inputNewDraft(ListStackDraft *listStackDraft, ListDinTweet *listTweet,
                   User user) {
  /* Menambahkan sebuah draft */
  /* Kemudian, user dapat memilih untuk menghapus, menyimpan, atau menerbitkan
   * draft */

  // Memasukkan text draft
  printf("Masukkan draf:\n");
  STARTWORDnoIgnore(MAX_TWEET_LENGTH);

  // Validasi masukan text draft
  if (isOnlySpace(currentWord)) {
    // Jika masukan tidak valid, menampilkan pesan bahwa draft gagal dibuat
    printf("Draf tidak boleh hanya berisi spasi!\n");
  } else {
    // Memilih hapus, simpan, atau terbit
    printf(
        "Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
    STARTWORDnoIgnore(MAX_CHOICE_LENGTH);

    if (compareWordwWord(currentWord, stringToWord("HAPUS"))) {
      deleteNewDraft();
    } else if (compareWordwWord(currentWord, stringToWord("SIMPAN"))) {
      saveNewDraft(listStackDraft, user, currentWord);
    } else if (compareWordwWord(currentWord, stringToWord("TERBIT"))) {
      publishNewDraft(listTweet, user, currentWord);
    } else {
      printf("Masukan tidak valid\n");
      printf("Draf terhapus secara otomatis\n");
    }
  }
}

void deleteNewDraft() {
  /* Menghapus draft yang baru dibuat */

  printf("Draf telah berhasil dihapus!\n");
}

void saveNewDraft(ListStackDraft *listStackDraft, User user, Word newText) {
  /* Menyimpan draft yang baru dibuat */

  int indexUser = indexOfAuthorDraft(*listStackDraft, user.nama);

  // Cek apakah ada StackDraft untuk user
  // Jika belum, buat StackDraft baru
  if (IDX_UNDEF_LISTSTACKDRAFT == indexUser) {
    StackDraft newStackDraft;
    const INITIAL_CAPACITY = 10;
    CreateEmptyStackDraft(&newStackDraft, INITIAL_CAPACITY, user.nama);
    insertLastListStackDraft(listStackDraft, newStackDraft);
    indexUser = NEFF_LISTSTACKDRAFT(*listStackDraft) - 1;
  }

  // Cek apakah StackDraft user sudah penuh
  // Jika sudah penuh, tambah kapasitasnya
  if (IsFullStackDraft(ELMT_LISTSTACKDRAFT(*listStackDraft, indexUser))) {
    expandStackDraft(&ELMT_LISTSTACKDRAFT(*listStackDraft, indexUser),
                     NEFF_LISTSTACKDRAFT(*listStackDraft));
  }

  // Memasukkan informasi ke dalam Draft
  DATETIME timeCreated = getCurrentDateTime();
  Draft newDraft;
  CreateDraft(&newDraft, currentWord, timeCreated);

  // Memasukkan Draft ke dalam StackDraft user
  Push(&ELMT_LISTSTACKDRAFT(*listStackDraft, indexUser), newDraft);

  printf("Draf telah berhasil disimpan!\n");
}

void publishNewDraft(ListDinTweet *listTweet, User user, Word newText) {
  /* Menerbitkan draft yang baru dibuat */

  // Memasukkan semua informasi yang dibutuhkan ke dalam Tweet
  Word author = user.nama;
  DATETIME timeCreated = getCurrentDateTime();
  long idTweet = NEFF_LISTDINTWEET(*listTweet) + 1;
  long idReply = 0;
  long idUtas = 0;
  long like = 0;
  long depth = 0;
  AddressTweet reply1 = NULL;
  AddressTweet reply2 = NULL;
  AddressTweet utas = NULL;
  AddressTweet pNewTweet =
      CreateTweet(newText, author, timeCreated, idTweet, idReply, idUtas, like,
                  depth, reply1, reply2, utas);

  // Cek apakah ListTweet sudah penuh
  // Jika sudah penuh, tambah kapasitasnya
  if (isFullListTweet(*listTweet)) {
    expandListTweet(listTweet, CAPACITY_LISTDINTWEET(*listTweet));
  }

  // Memasukkan Tweet ke dalam ListTweet
  insertLastListTweet(listTweet, pNewTweet);

  // Menampilkan pesan bahwa Draft berhasil diterbitkan
  printf("Selamat! Draf kicauan telah diterbitkan!\n");
  printf("Detil kicauan:\n");
  displayTweet(pNewTweet);
}

void displayUserDraft(ListStackDraft *listStackDraft, ListDinTweet *listTweet,
                      User user) {
  /* Menampilkan draft terakhir */
  /* Kemudian, user dapat memilih untuk menghapus, mengubah, atau menerbitkan
   * draft */

  int indexUser = indexOfAuthorDraft(*listStackDraft, user.nama);

  if (IDX_UNDEF_LISTSTACKDRAFT == indexUser) {
    printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
  } else if (IsEmptyStackDraft(
                 ELMT_LISTSTACKDRAFT(*listStackDraft, indexUser))) {
    printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
  } else {
    printf("Ini draf terakhir anda:\n");
    displayDraft(InfoTop(ELMT_LISTSTACKDRAFT(*listStackDraft, indexUser)));

    // Memilih hapus, ubah, atau terbit
    printf(
        "Apakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? "
        "(KEMBALI jika ingin kembali)\n");
    STARTWORDnoIgnore(MAX_CHOICE_LENGTH);

    if (compareWordwWord(currentWord, stringToWord("HAPUS"))) {
      deleteUserDraft(listStackDraft, user);
      printf("Draf telah berhasil dihapus!\n");
    } else if (compareWordwWord(currentWord, stringToWord("UBAH"))) {
      modifyUserDraft(listStackDraft, listTweet, user);
    } else if (compareWordwWord(currentWord, stringToWord("TERBIT"))) {
      publishUserDraft(listStackDraft, listTweet, user);
    } else {
      printf("Aksi dibatalkan\n");
    }
  }
}

void deleteUserDraft(ListStackDraft *listStackDraft, User user) {
  /* Menghapus draft terakhir milik user */

  int indexUser = indexOfAuthorDraft(*listStackDraft, user.nama);
  Draft deletedDraft;
  Pop(&ELMT_LISTSTACKDRAFT(*listStackDraft, indexUser), &deletedDraft);
}

void modifyUserDraft(ListStackDraft *listStackDraft, ListDinTweet *listTweet,
                     User user) {
  /* Mengubah draft terakhir milik user */
  deleteUserDraft(listStackDraft, user);
  inputNewDraft(listStackDraft, listTweet, user);
}

void publishUserDraft(ListStackDraft *listStackDraft, ListDinTweet *listTweet,
                      User user) {
  /* Menerbitkan draft terakhir milik user */

  int indexUser = indexOfAuthorDraft(*listStackDraft, user.nama);

  // Memasukkan semua informasi yang dibutuhkan ke dalam Tweet
  Word newText =
      TextDraft(InfoTop(ELMT_LISTSTACKDRAFT(*listStackDraft, indexUser)));
  Word author = user.nama;
  DATETIME timeCreated = getCurrentDateTime();
  long idTweet = NEFF_LISTDINTWEET(*listTweet) + 1;
  long idReply = 0;
  long idUtas = 0;
  long like = 0;
  long depth = 0;
  AddressTweet reply1 = NULL;
  AddressTweet reply2 = NULL;
  AddressTweet utas = NULL;
  AddressTweet pNewTweet =
      CreateTweet(newText, author, timeCreated, idTweet, idReply, idUtas, like,
                  depth, reply1, reply2, utas);

  // Cek apakah ListTweet sudah penuh
  // Jika sudah penuh, tambah kapasitasnya
  if (isFullListTweet(*listTweet)) {
    expandListTweet(listTweet, CAPACITY_LISTDINTWEET(*listTweet));
  }

  // Memasukkan Tweet ke dalam ListTweet
  insertLastListTweet(listTweet, pNewTweet);

  // Menampilkan pesan bahwa Draft berhasil diterbitkan
  printf("Selamat! Draf kicauan telah diterbitkan!\n");
  printf("Detil kicauan:\n");
  displayTweet(pNewTweet);
}
