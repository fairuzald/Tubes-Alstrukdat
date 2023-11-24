#include "friend_request.h"

#include <stdio.h>

FriendRequestQueue friendRequestQueue;

void CreateQueue(FriendRequestQueue* friendRequestQueue) {
  friendRequestQueue->idxHead = IDX_UNDEF;
  friendRequestQueue->idxTail = IDX_UNDEF;
  friendRequestQueue->n = 0;
}

void AppendQueue(FriendRequestQueue* friendRequestQueue, int senderID,
                 int receiverID, int senderFriendCount) {
  friendRequestQueue->buffer[lengthQueue(*friendRequestQueue)].senderID =
      senderID;
  friendRequestQueue->buffer[lengthQueue(*friendRequestQueue)].receiverID =
      receiverID;
  friendRequestQueue->buffer[lengthQueue(*friendRequestQueue)]
      .senderFriendCount = senderFriendCount;
  friendRequestQueue->idxTail++;
  friendRequestQueue->n++;
}

boolean isEmptyQueue(FriendRequestQueue friendRequestQueue) {
  return (friendRequestQueue.n == 0);
}

boolean isFullQueue(FriendRequestQueue friendRequestQueue) {
  return (friendRequestQueue.n == MAX_CAP);
}

int lengthQueue(FriendRequestQueue friendRequestQueue) {
  return (friendRequestQueue.n);
}

void addFriend(FriendRequestQueue* friendRequestQueue, ListStatikUser userList,
               Word currentUser) {
  int i;
  Word CalonTeman;
  int userID = userIndex(currentUser);
  if (NRequest(*friendRequestQueue, userList, currentUser) > 0) {
    printf(
        "\nWADOOOHHHH masih terdapat permintaan pertemanan yang belum Anda "
        "setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda "
        "terlebih dahulu.\n");
  } else {
    printf("\nMasukkan nama pengguna: \n");
    STARTWORDnoIgnore(20);
    CopyWordwWord(&CalonTeman, &currentWord);

    if (userIndex(CalonTeman) == IDX_UNDEF) {
      printf("\nYAHHHH Pengguna bernama ");
      printWord(CalonTeman);
      printf(" tidak ditemukan.\n");
    } else if (isRequestExist(CalonTeman, currentUser)) {
      printf("\nAnda sudah mengirimkan permintaan pertemanan kepada ");
      printWord(CalonTeman);
      printf(". Silakan tunggu hingga permintaan Anda disetujui.\n");
    } else if (isTeman(grafPertemanan, CalonTeman, currentUser)) {
      printf("\nMaaf, Anda sudah melakukan pertemanan dengan \n");
      printWord(CalonTeman);
      printf("\n");
    } else {
      if (isEmptyQueue(*friendRequestQueue)) {
        CreateQueue(friendRequestQueue);
        friendRequestQueue->buffer[0].senderID = userID;
        friendRequestQueue->buffer[0].receiverID = userIndex(CalonTeman);
        friendRequestQueue->buffer[0].senderFriendCount =
            countTeman(grafPertemanan, userList, currentUser);
      } else {
        friendRequestQueue->idxTail++;
        i = friendRequestQueue->idxTail - 1;
        while (countTeman(grafPertemanan, userList, currentUser) >
               friendRequestQueue->buffer[i].senderFriendCount) {
          friendRequestQueue->buffer[i + 1].senderID =
              friendRequestQueue->buffer[i].senderID;
          friendRequestQueue->buffer[i + 1].receiverID =
              friendRequestQueue->buffer[i].receiverID;
          friendRequestQueue->buffer[i + 1].senderFriendCount =
              friendRequestQueue->buffer[i].senderFriendCount;
          i--;
        }
        friendRequestQueue->buffer[i + 1].senderID =
            friendRequestQueue->buffer[i].senderID;
        friendRequestQueue->buffer[i + 1].receiverID =
            friendRequestQueue->buffer[i].receiverID;
        friendRequestQueue->buffer[i + 1].senderFriendCount =
            friendRequestQueue->buffer[i].senderFriendCount;
        friendRequestQueue->buffer[i].senderID = userID;
        friendRequestQueue->buffer[i].receiverID = userIndex(CalonTeman);
        friendRequestQueue->buffer[i].senderFriendCount =
            countTeman(grafPertemanan, userList, currentUser);
      }
      friendRequestQueue->idxTail++;
      friendRequestQueue->n++;
      printf("Permintaan pertemanan kepada ");
      printWord(CalonTeman);
      printf(
          " telah dikirim. Tunggu beberapa saat hingga permintaan Anda "
          "disetujui.");
    }
  }
}

void displayFriendRequests(FriendRequestQueue friendRequestQueue,
                           ListStatikUser userList, Word currentUser) {
  int i, userID;

  userID = userIndex(currentUser);

  if (NRequest(friendRequestQueue, userList, currentUser) == 0) {
    printf(
        "\nWADOOOHHHH Tidak ada permintaan pertemanan untuk Anda. Sabar, ya!\n");
  } else {
    printf("Terdapat %d permintaan pertemanan untuk Anda.\n",
           NRequest(friendRequestQueue, userList, currentUser));
    for (i = 0; i < friendRequestQueue.n; i++) {
      if (friendRequestQueue.buffer[i].receiverID == userID) {
        printf("| ");
        printWord(findUser(userList, friendRequestQueue.buffer[i].senderID));
        printf("\n");
        printf("| Jumlah teman: ");
        printf("%d", friendRequestQueue.buffer[i].senderFriendCount);
        printf("\n\n");
      }
    }
  }
}

void approveFriendRequest(FriendRequestQueue* friendRequestQueue,
                          ListStatikUser userList, Word currentUser) {
  int i = 0;
  int userID, friendID;
  userID = userIndex(currentUser);

  if (isEmptyQueue(*friendRequestQueue) ||
      NRequest(*friendRequestQueue, userList, currentUser) == 0) {
    printf("\nWaduhh belum ada permintaan pertemanan, nich :'D \n");
  } else {
    while (friendRequestQueue->buffer[i].receiverID != userID) {
      i++;
    }

    printf("Permintaan teratas dari ");
    printWord(findUser(userList, friendRequestQueue->buffer[i].senderID));
    printf("\n");
    printf("\n");
    printf("| ");
    printWord(findUser(userList, friendRequestQueue->buffer[i].senderID));
    printf("\n");
    printf("| Jumlah teman: ");
    printf("%d", friendRequestQueue->buffer[i].senderFriendCount);
    printf("\n");
    printf("\n");
    printf(
        "Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK) ");
    STARTWORD();
    if (compareWordwString(currentWord, "YA")) {
      printf("Permintaan pertemanan dari ");
      printWord(findUser(userList, friendRequestQueue->buffer[i].senderID));
      printf(" telah disetujui. Selamat! Anda telah berteman dengan ");
      printWord(findUser(userList, friendRequestQueue->buffer[i].senderID));
      printf(".\n");
      insertFriend(&grafPertemanan, currentUser,
                   findUser(userList, friendRequestQueue->buffer[i].senderID));
    } else {
      printf("Permintaan pertemanan dari ");
      printWord(findUser(userList, friendRequestQueue->buffer[i].senderID));
      printf(" telah ditolak.");
    }

    friendRequestQueue->n--;

    if (friendRequestQueue->n == 0) {
      CreateQueue(friendRequestQueue);
    } else {
      while (i < friendRequestQueue->idxTail) {
        friendRequestQueue->buffer[i].senderID =
            friendRequestQueue->buffer[i + 1].senderID;
        friendRequestQueue->buffer[i].receiverID =
            friendRequestQueue->buffer[i + 1].receiverID;
        friendRequestQueue->buffer[i].senderFriendCount =
            friendRequestQueue->buffer[i + 1].senderFriendCount;
        i++;
      }
      friendRequestQueue->idxTail--;
    }
  }
}

// Jumlah Permintaan Teman
int NRequest(FriendRequestQueue friendRequestQueue, ListStatikUser userList,
             Word currentUser) {
  int i, ctr, userID;

  ctr = 0;

  userID = userIndex(currentUser);

  if (isEmptyQueue(friendRequestQueue)) {
    ctr = 0;
  } else {
    for (i = 0; i < friendRequestQueue.n; i++) {
      if (friendRequestQueue.buffer[i].receiverID == userID) {
        ctr++;
      }
    }
  }

  return ctr;
}

boolean isRequestExist(Word username, Word currentUser) {
  int i, userID, friendID;
  boolean found;
  i = 0;

  userID = userIndex(currentUser);
  friendID = userIndex(username);

  while (i < friendRequestQueue.n && !found) {
    if (friendRequestQueue.buffer[i].senderID == userID &&
        friendRequestQueue.buffer[i].receiverID == friendID) {
      found = true;
    }
  }

  return found;
}