#include "friend.h"

#include <stdio.h>

Graph grafPertemanan;
ListStatikUser userList;
boolean sudahMasuk;

Word findUser(ListStatikUser userList, int userID) {
  return (userList.contents[userID].nama);
}

int countTeman(Graph grafPertemanan, ListStatikUser userList, Word username) {
  int i, ctr, userID;
  ctr = 0;
  userID = userIndex(username);

  for (i = 0; i < JumlahSimpul(grafPertemanan); i++) {
    if (ELMT(grafPertemanan, userID, i) == 1) {
      ctr++;
    }
  }

  return ctr - 1;
}

void DaftarTeman(Graph grafPertemanan, ListStatikUser userList,
                 Word CurrentUser, boolean sudahMasuk) {
  int i, userID, jumlahTeman;
  userID = userIndex(CurrentUser);
  jumlahTeman = countTeman(grafPertemanan, userList, CurrentUser);
  if (!sudahMasuk) {
    printf(
        "\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan "
        "BurBir.\n");
  } else {
    if (jumlahTeman == 0) {
      printf("\nWADOOHHHHH ");
      printWord(CurrentUser);
      printf(
          " belum punya teman nich hiks! cariin dia temen donkk xixixi :D \n");
    } else {
      printf("\n");
      printWord(CurrentUser);
      printf(" memiliki %d teman\n", jumlahTeman);
      printf("Daftar teman ");
      printWord(CurrentUser);
      printf("\n");

      for (i = 0; i < JumlahSimpul(grafPertemanan); i++) {
        if (ELMT(grafPertemanan, userID, i) == 1 &&
            userIndex(userList.contents[i].nama) != userID) {
          printf("| ");
          printWord(userList.contents[i].nama);
          printf("\n");
        }
      }
    }
  }
}

boolean isTeman(Graph grafPertemanan, Word userFriend, Word currentUser) {
  boolean isTeman;
  isTeman = false;
  int IDUser, IDTeman;

  IDUser = userIndex(currentUser);
  IDTeman = userIndex(userFriend);

  if (ELMT(grafPertemanan, IDUser, IDTeman) == 1) {
    isTeman = true;
  } else {
    isTeman = false;
  }

  return isTeman;
}

void HapusTeman(Graph* grafPertemanan, ListStatikUser* userList,
                Word currentUser, boolean sudahMasuk) {
  Word userFriend;
  int friendID, userID;

  userID = userIndex(currentUser);
  friendID = userIndex(userFriend);

  if (!sudahMasuk) {
    printf(
        "Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan "
        "BurBir.\n");
  } else {
    printf("\nMasukkan nama pengguna: \n");
    STARTWORDnoIgnore(20);
    CopyWordwWord(&userFriend, &currentWord);
    if (isTeman(*grafPertemanan, currentUser, userFriend)) {
      printf("\nHAHHH? Apakah anda yakin ingin menghapus ");
      printWord(userFriend);
      printf(" dari daftar teman Anda? (YA/TIDAK) ");
      STARTWORD();
      if (compareWordwString(currentWord, "YA")) {
        removeFriend(grafPertemanan, userFriend, currentUser);
        printf("\n");
        printWord(userFriend);
        printf(" berhasil dihapus dari daftar teman Anda.\n");
      } else {
        printf("\nPenghapusan teman dibatalkan.\n");
      }
    } else {
      printf("\n");
      printWord(userFriend);
      printf(" bukan teman Anda.\n");
    }
  }
}

// Hapus informasi pertemanan dari Adjacency Matrix
void removeFriend(Graph* grafPertemanan, Word userFriend, Word currentUser) {
  int userID, friendID;

  userID = userIndex(currentUser);
  friendID = userIndex(userFriend);

  deleteEdge(grafPertemanan, userID, friendID);
  deleteEdge(grafPertemanan, friendID, userID);
}

// Menambah informasi pertemanan dari Adjacency Matrix
void insertFriend(Graph* grafPertemanan, Word userFriend, Word currentUser) {
  int userID, friendID;

  userID = userIndex(currentUser);
  friendID = userIndex(userFriend);

  insertEdge(grafPertemanan, userID, friendID);
  insertEdge(grafPertemanan, friendID, userID);
}