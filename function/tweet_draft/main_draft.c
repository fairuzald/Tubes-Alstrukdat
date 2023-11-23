#include "main_draft.h"

#include <stdio.h>

const int MAX_CHOICE_LENGTH = 7;

/* State Global ListStackDraft */
ListStackDraft listStackDraftMain;

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
    const int INITIAL_CAPACITY = 20;
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
  boolean kicauanUtama = false;
  AddressTweet pNewTweet =
      CreateTweet(newText, author, timeCreated, idTweet, idReply, idUtas, like,
                  depth, reply1, reply2, utas, kicauanUtama);

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
      Draft deletedDraft;
      deleteUserDraft(listStackDraft, user, &deletedDraft);
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

void deleteUserDraft(ListStackDraft *listStackDraft, User user,
                     Draft *deletedDraft) {
  /* Menghapus draft terakhir milik user */

  int indexUser = indexOfAuthorDraft(*listStackDraft, user.nama);
  StackDraft stackDraftUser = ELMT_LISTSTACKDRAFT(*listStackDraft, indexUser);
  Pop(&stackDraftUser, deletedDraft);

  // Mengurangi kapasitas StackDtaft jika terisi < 25% dari kapasitas
  // Kapasitas minimal StackDraft adalah 20
  if ((Top(stackDraftUser) + 1) < (CapacityStackDraft(stackDraftUser) / 4) &&
      (CapacityStackDraft(stackDraftUser) / 2) >= 20) {
    // Kapasitas berkurang menjadi 50% dari kapasitas semula
    shrinkStackDraft(&stackDraftUser, (CapacityStackDraft(stackDraftUser) / 2));
  }
}

void modifyUserDraft(ListStackDraft *listStackDraft, ListDinTweet *listTweet,
                     User user) {
  /* Mengubah draft terakhir milik user */

  Draft deletedDraft;
  deleteUserDraft(listStackDraft, user, &deletedDraft);
  inputNewDraft(listStackDraft, listTweet, user);
}

void publishUserDraft(ListStackDraft *listStackDraft, ListDinTweet *listTweet,
                      User user) {
  /* Menerbitkan draft terakhir milik user */

  Draft deletedDraft;
  deleteUserDraft(listStackDraft, user, &deletedDraft);

  // Memasukkan semua informasi yang dibutuhkan ke dalam Tweet
  Word newText = TextDraft(deletedDraft);
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
  boolean kicauanUtama = false;
  AddressTweet pNewTweet =
      CreateTweet(newText, author, timeCreated, idTweet, idReply, idUtas, like,
                  depth, reply1, reply2, utas, kicauanUtama);

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
