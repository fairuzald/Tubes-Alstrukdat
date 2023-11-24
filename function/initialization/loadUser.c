#include "initialization.h"
Graph grafPertemanan;

void readMatrix(PhotoMat *m, int nRow, int nCol) {
  /* I.S. isIdxValid(nRow,nCol) */
  /* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
  int i, j;
  initPP(*m);
  // Read the matrix from the input string
  for (i = 0; i < nRow; i++) {
    ADVWORDFILE();
    for (j = 0; j < nCol; j++) {
      if (currentWordFile.Length > 0) {
        COLOR(*m, i, j) = currentWordFile.TabWord[4 * j];
        CONTENT(*m, i, j) = currentWordFile.TabWord[4 * j + 2];
      }
    }
  }
}

void readGraphPertemanan(int countUser) {
  CreateGraph(&grafPertemanan, countUser);
  for (int i = 0; i < countUser; i++) {
    ADVWORDFILE();
    for (int j = 0; j < countUser; j++) {
      if (currentWordFile.Length > 0) {
        if (currentWordFile.TabWord[2 * j] == '1') {
          insertEdge(&grafPertemanan, i, j);
        }
      }
    }
  }
}

void readReqPertemanan(int row) {
  CreateQueue(&friendRequestQueue);
  for (int i = 0; i < row; i++) {
    // Yang meminta pertemanan
    ADVWORDFILEnoBLANK();
    Word id, addressId, friendCount;
    CopyWordwWord(&id, &currentWordFile);
    int idInt = wordToInt(id);
    // printf("idInt: %d\n", idInt);

    // Yang dimintai pertemanan
    ADVWORDFILEnoBLANK();
    CopyWordwWord(&addressId, &currentWordFile);
    int idAddressInt = wordToInt(addressId);
    // printf("idAddressInt: %d\n", idAddressInt);
    ADVWORDFILEnoBLANK();

    // Current word is friend count
    CopyWordwWord(&friendCount, &currentWordFile);
    int friendCountInt = wordToInt(friendCount);
    // printf("friendCountInt: %d\n", friendCountInt);
    AppendQueue(&friendRequestQueue, idInt, idAddressInt, friendCountInt);
  }
}

void readUserConfig(char filePath[]) {
  CreateuserList();
  char fullPath[200];
  concat(filePath, "/pengguna.config", fullPath);
  boolean found = searchConfigFile(fullPath);
  if (!found) {
    printf("File %s tidak ditemukan.\n", fullPath);
    return;
  }
  STARTWORDFILE(fullPath);
  ADVFILE();

  int countUser;

  countUser = wordToInt(currentWordFile);
  ADVWORDFILE();
  Word nama, pass, bio, numberHP, weton, status;
  PhotoMat pp;
  boolean isPublic;

  for (int i = 0; i < countUser; i++) {
    CopyWordwWord(&nama, &currentWordFile);
    CropWord(&nama, 20);
    ADVWORDFILE();

    CopyWordwWord(&pass, &currentWordFile);
    CropWord(&pass, 20);
    ADVWORDFILE();

    CopyWordwWord(&bio, &currentWordFile);
    CropWord(&bio, 135);
    ADVWORDFILE();

    CopyWordwWord(&numberHP, &currentWordFile);
    ADVWORDFILE();

    CopyWordwWord(&weton, &currentWordFile);
    ADVWORDFILE();

    isPublic = compareWordwString(status, "PUBLIC");
    CopyWordwWord(&status, &currentWordFile);
    ADVWORDFILE();

    readMatrix(&pp, 5, 5);
    loadUser(nama, pass, bio, numberHP, weton, isPublic, pp);
  }
  // displayAllUsers();
  readGraphPertemanan(countUser);

  Word countRequest;
  CopyWordwWord(&countRequest, &currentWordFile);
  int countReq = wordToInt(countRequest);
  readReqPertemanan(countReq);
}
