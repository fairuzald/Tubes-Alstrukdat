#include <stdio.h>

#include "../../adt/boolean.h"
#include "../../adt/input/wordmachine.h"
#include "../../adt/queue.h"
#include "../friend/friend.h"

#define MAX_USERS 20

// Fungsi untuk menambahkan teman
void addFriend(Queue *friendRequests, UserList *users, User currentUser) {
  if (isEmpty(*friendRequests)) {
    char friendName[50];
    printf("Masukkan nama pengguna: ");
    scanf("%s", friendName);

    int found = false;
    for (int i = 0; i < MAX_USERS; i++) {
      if (isEqual(users->users[i].name, friendName)) {
        found = true;

        // Pemeriksaan apakah pengguna sudah mengirim permintaan sebelumnya
        int existingRequest = false;
        Queue tempQueue;
        CreateQueue(&tempQueue);

        // Iterasi melalui queue untuk mencari permintaan pertemanan
        while (!isEmpty(*friendRequests)) {
          User existingRequestUser;
          dequeue(friendRequests, &existingRequestUser);
          enqueue(&tempQueue, existingRequestUser);

          // Jika ditemukan permintaan dari pengguna yang sama, set
          // existingRequest menjadi true dan hentikan iterasi
          if (isEqual(existingRequestUser.name, friendName)) {
            existingRequest = true;
            break;
          }
        }

        // Mengembalikan elemen ke queue semula
        while (!isEmpty(tempQueue)) {
          User tempUser;
          dequeue(&tempQueue, &tempUser);
          enqueue(friendRequests, tempUser);
        }

        if (existingRequest) {
          printf(
              "Anda telah mengirimkan permintaan pertemanan kepada %s "
              "sebelumnya. Silakan tunggu hingga permintaan Anda disetujui.\n",
              friendName);
        } else {
          User friendRequest;
          strcpy(friendRequest.name, friendName);
          friendRequest.popularity = users->users[i].popularity;
          enqueue(friendRequests, friendRequest);
          printf(
              "Permintaan pertemanan kepada %s telah dikirim. Tunggu beberapa "
              "saat hingga permintaan Anda disetujui.\n",
              friendName);
        }

        break;
      }
    }

    if (!found) {
      printf("Pengguna bernama %s tidak ditemukan.\n", friendName);
    }
  } else {
    printf(
        "Terdapat permintaan pertemanan yang belum Anda setujui. Silakan "
        "kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
  }
}

void displayFriendRequests(Queue *friendRequests) {
  printf("\nTerdapat %d permintaan pertemanan untuk Anda.\n\n",
         length(*friendRequests));
  if (!isEmpty(*friendRequests)) {
    for (int i = IDX_HEAD(*friendRequests);
         i != (IDX_TAIL(*friendRequests) + 1) % CAPACITY;
         i = (i + 1) % CAPACITY) {
      printf("| %s\n", friendRequests->buffer[i].name);
      printf("| Jumlah teman: %d\n", friendRequests->buffer[i].popularity);
    }
  }
}

// Fungsi untuk menyetujui permintaan pertemanan
void approveFriendRequest(Queue *friendRequests) {
  if (!isEmpty(*friendRequests)) {
    User topRequest;
    dequeue(friendRequests, &topRequest);

    printf("\nPermintaan pertemanan teratas dari %s\n", topRequest.name);
    printf("| %s\n", topRequest.name);
    printf("| Jumlah teman: %d\n", topRequest.popularity);

    char response[3];
    printf(
        "Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK) ");
    scanf("%s", response);

    if (isEqual(response, "YA")) {
      printf(
          "Permintaan pertemanan dari %s telah disetujui. Selamat! Anda telah "
          "berteman dengan %s.\n",
          topRequest.name, topRequest.name);
    } else {
      printf("Permintaan pertemanan dari %s telah ditolak.\n", topRequest.name);
      enqueue(friendRequests,
              topRequest);  // Menambahkan kembali ke antrian jika ditolak
    }
  } else {
    printf("Tidak ada permintaan pertemanan untuk Anda.\n");
  }
}