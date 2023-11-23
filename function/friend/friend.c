#include <stdio.h>
#include "friend.h"

Graph grafPertemanan;
ListStatikUser userList;
boolean sudahMasuk;

int findID(ListStatikUser userList, Word username) {
  int i;

  for (i = 0; i < CAPACITY; i++) {
    if (compareWordwWord(userList.contents[i].nama, username)) {
      return i;
    } else {
      return IDX_UNDEF;
    }
  }
}

Word findUser(ListStatikUser userList, int userID) {
  return (userList.contents[userID].nama);
}

int countTeman(Graph grafPertemanan, ListStatikUser userList, Word username) {
  int i, ctr, userID;
  ctr = 0;
  userID = findID(userList, username);

  for (i = 0; i < JumlahSimpul(grafPertemanan); i++) {
    if (ELMT(grafPertemanan, userID, i) == 1) {
      ctr++;
    }
  }

  return ctr - 1; // Ada 1 kemungkinan suatu user akan berteman dengan dirinya sendiri
}

void DaftarTeman(Graph grafPertemanan, ListStatikUser userList, Word CurrentUser, boolean sudahMasuk) {
  int i, userID, jumlahTeman;
  userID = findID(userList, CurrentUser);
  jumlahTeman = countTeman(grafPertemanan, userList, CurrentUser);

  if (!sudahMasuk) {
    printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
  } else {
    if (jumlahTeman == 0) {
      printf("WADOOHHHHH ");
      printWord(CurrentUser);
      printf(" belum punya teman nich hiks! cariin dia temen donkk xixixi :D \n");
    } else {
      printWord(CurrentUser);
      printf(" memiliki %d teman\n", jumlahTeman);
      printf("Daftar teman ");
      printWord(CurrentUser);
      printf("\n");

      for (i = 0; i < JumlahSimpul(grafPertemanan); i++) {
        if (ELMT(grafPertemanan, userID, i) == 1 && i != userID) {
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
  int IDUser, IDTeman;

  IDUser = findID(userList, currentUser);
  IDTeman = findID(userList, userFriend);

  if (ELMT(grafPertemanan, IDUser, IDTeman) == 1) {
    isTeman = true;
  } else {
    isTeman = false;
  }

  return isTeman;
}

void HapusTeman(Graph * grafPertemanan, ListStatikUser * userList, Word currentUser, boolean sudahMasuk) {
  Word userFriend;
  int friendID, userID;

  userID = findID(*userList, currentUser);
  friendID = findID(*userList, userFriend);

  if (!sudahMasuk) {
    printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
  } else {
    printf("Masukkan nama pengguna: \n");
    STARTWORDnoIgnore(20);
    CopyWordwWord(&userFriend, &currentWord);
    if (isTeman(*grafPertemanan, currentUser, userFriend)) {
      printf("HAHHH? Apakah anda yakin ingin menghapus ");
      printWord(userFriend);
      printf(" dari daftar teman Anda? (YA/TIDAK) ");
      STARTWORD();
      if (compareWordwString(currentWord, "YA")) {
        removeFriend(grafPertemanan, userFriend, currentUser);
      } else {
        printf("Penghapusan teman dibatalkan.\n");
      }
    } else {
      printWord(userFriend);
      printf(" bukan teman Anda.\n");
    }
  }
}

// Hapus informasi pertemanan dari Adjacency Matrix
void removeFriend(Graph * grafPertemanan, Word userFriend, Word currentUser) {
  int userID, friendID;

  userID = findID(userList, currentUser);
  friendID = findID(userList, userFriend);

  deleteEdge(grafPertemanan, userID, friendID);
  deleteEdge(grafPertemanan, friendID, userID);
}

// Menambah informasi pertemanan dari Adjacency Matrix
void insertFriend(Graph * grafPertemanan, Word userFriend, Word currentUser) {
  int userID, friendID;

  userID = findID(userList, currentUser);
  friendID = findID(userList, userFriend);

  insertEdge(grafPertemanan, userID, friendID);
  insertEdge(grafPertemanan, friendID, userID);
}