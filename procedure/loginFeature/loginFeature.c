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
  } else if (compareWordwString(*command, "LIHAT_PROFIL")) {
    Word usn;
    IgnoreBlanks();
    ADVWORDnoIgnore();
    usn = currentWord;
    lihat_profil(usn);
  } else if (compareWordwString(*command, "ATUR_JENIS_AKUN")) {
    atur_jenis_akun();
  } else if (compareWordwString(*command, "UBAH_FOTO_PROFIL")) {
    ubah_foto_profil();
  } else if (compareWordwString(*command, "KELUAR")) {
    keluar();
  }
}

void loginFeatureTeman(Word *command, boolean sudahMasuk) {
  if (compareWordwString(*command, "DAFTAR_TEMAN")) {
    DaftarTeman(grafPertemanan, userList, currentUser.nama, sudahMasuk);
  } else if (compareWordwString(*command, "HAPUS_TEMAN")) {
    HapusTeman(&grafPertemanan, &userList, currentUser.nama, sudahMasuk);
  }
}

void loginFeatureTemanReq(Word *command) {
  if (compareWordwString(*command, "TAMBAH_TEMAN")) {
    addFriend(&friendRequestQueue, userList, currentUser.nama);
  } else if (compareWordwString(*command, "DAFTAR_PERMINTAAN_PERTEMANAN")) {
    displayFriendRequests(friendRequestQueue, userList, currentUser.nama);
  } else if (compareWordwString(*command, "SETUJUI_PERTEMANAN")) {
    approveFriendRequest(&friendRequestQueue, userList, currentUser.nama);
  }
}

void loginFeatureTweet(Word *command) {
  if (compareWordwString(*command, "KICAU")) {
    inputNewTweet(&listTweetMain, currentUser);
  } else if (compareWordwString(*command, "KICAUAN")) {
    displayListTweet(listTweetMain, userList, grafPertemanan, currentUser);
  } else if (compareWordwString(*command, "SUKA_KICAUAN")) {
    Word id;
    IgnoreBlanks();
    ADVWORDnoIgnore();
    id = currentWord;
    int idInt = wordToInt(id);
    like(&listTweetMain, idInt, userList, grafPertemanan, currentUser);
  } else if (compareWordwString(*command, "UBAH_KICAUAN")) {
    Word id;
    ADVWORD();
    IgnoreBlanks();
    ADVWORDnoIgnore();
    int idInt = wordToInt(id);
    editTweetInList(&listTweetMain, idInt, currentUser);
  } else {
    printf("Perintah tidak ditemukan\n");
  }
}

void loginFeatureUtas(Word *command) {
  if (compareWordwString(*command, "UTAS")) {
    Word id;
    IgnoreBlanks();
    ADVWORDnoIgnore();
    id = currentWord;
    int intId = wordToInt(id);
    initUtas(&listTweetMain, intId, currentUser);
  } else if (compareWordwString(*command, "SAMBUNG_UTAS")) {
    IgnoreBlanks;
    Word idUtas;
    ADVWORD();
    idUtas = currentWord;
    int intIdUtas = wordToInt(idUtas);
    Word index;
    ADVWORD();
    index = currentWord;
    int intIndex = wordToInt(currentWord);
    connectUtas(&listTweetMain, intIdUtas, intIndex, currentUser);
  } else if (compareWordwString(*command, "HAPUS_UTAS")) {
    IgnoreBlanks;
    Word idUtas;
    ADVWORD();
    idUtas = currentWord;
    int intIdUtas = wordToInt(idUtas);
    Word index;
    ADVWORD();
    index = currentWord;
    int intIndex = wordToInt(currentWord);
    deleteUtas(&listTweetMain, intIdUtas, intIndex, currentUser);
  } else if (compareWordwString(*command, "CETAK_UTAS")) {
    IgnoreBlanks;
    Word idUtas;
    ADVWORD();
    idUtas = currentWord;
    int intIdUtas = wordToInt(idUtas);
    displayUtas(&listTweetMain, intIdUtas, currentUser, grafPertemanan);
  }
}

void loginFeature(Word *command, boolean sudahMasuk) {
  loginFeatureUser(command);
  loginFeatureTeman(command, sudahMasuk);
  loginFeatureTemanReq(command);
  loginFeatureTweet(command);
  loginFeatureUtas(command);
}
