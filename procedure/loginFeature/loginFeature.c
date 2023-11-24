#include "loginFeature.h"

void getIdFromCommand(Word *id) {
  ADVWORD();
  *id = currentWord;
  while (currentChar != MARK) {
    ADVWORD();
    ConcatWords(id, id, &currentWord);
  }
}

void loginFeatureUser(Word *command) {
  if (compareWordwString(*command, "GANTI_PROFIL")) {
    ganti_profil();
    ADV();
  } else if (compareWordwString(*command, "LIHAT_PROFIL")) {
    Word usn;
    getIdFromCommand(&usn);
    lihat_profil(usn);
    ADV();
  } else if (compareWordwString(*command, "ATUR_JENIS_AKUN")) {
    atur_jenis_akun();
    ADV();
  } else if (compareWordwString(*command, "UBAH_FOTO_PROFIL")) {
    ubah_foto_profil();
    ADV();
  } else {
    printf("Command perintah tidak ditemukan: ");
    printWord(*command);
    printf("\n");
  }
}

void loginFeatureTeman(Word *command, boolean sudahMasuk) {
  if (compareWordwString(*command, "DAFTAR_TEMAN")) {
    DaftarTeman(grafPertemanan, userList, currentUser.nama, sudahMasuk);
    ADV();
  } else if (compareWordwString(*command, "HAPUS_TEMAN")) {
    HapusTeman(&grafPertemanan, &userList, currentUser.nama, sudahMasuk);
    ADV();
  } else {
    printf("Command perintah tidak ditemukan: ");
    printWord(*command);
    printf("\n");
  }
}

void loginFeatureTemanReq(Word *command) {
  if (compareWordwString(*command, "TAMBAH_TEMAN")) {
    addFriend(&friendRequestQueue, userList, currentUser.nama);
    ADV();
  } else if (compareWordwString(*command, "DAFTAR_PERMINTAAN_PERTEMANAN")) {
    displayFriendRequests(friendRequestQueue, userList, currentUser.nama);
    ADV();
  } else if (compareWordwString(*command, "SETUJUI_PERTEMANAN")) {
    approveFriendRequest(&friendRequestQueue, userList, currentUser.nama);
    ADV();
  } else {
    printf("Command perintah tidak ditemukan: ");
    printWord(*command);
    printf("\n");
  }
}

void loginFeatureTweet(Word *command) {
  if (compareWordwString(*command, "KICAU")) {
    inputNewTweet(&listTweetMain, currentUser);
    ADV();
  } else if (compareWordwString(*command, "KICAUAN")) {
    displayListTweet(listTweetMain, userList, grafPertemanan, currentUser);
    ADV();
  } else if (compareWordwString(*command, "SUKA_KICAUAN")) {
    Word id;
    getIdFromCommand(&id);
    int idInt = wordToInt(id);
    like(&listTweetMain, idInt, userList, grafPertemanan, currentUser);
    ADV();
  } else if (compareWordwString(*command, "UBAH_KICAUAN")) {
    Word id;
    getIdFromCommand(&id);
    int idInt = wordToInt(id);
    editTweetInList(&listTweetMain, idInt, currentUser);
  } else {
    printf("Command perintah tidak ditemukan: ");
    printWord(*command);
    printf("\n");
    ADV();
  }
}

void loginFeature(Word *command, boolean sudahMasuk) {
  loginFeatureUser(command);
  loginFeatureTeman(command, sudahMasuk);
  loginFeatureTemanReq(command);
  loginFeatureTweet(command);
}
