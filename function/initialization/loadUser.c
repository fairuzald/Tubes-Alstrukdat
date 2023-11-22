#include "initialization.h"

void readMatrix(PhotoMat *m, int nRow, int nCol) {
  /* I.S. isIdxValid(nRow,nCol) */
  /* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
  int i, j;
  initPP(*m);
  // Read the matrix from the input string
  for (i = 0; i < nRow; i++) {
    for (j = 0; j < nCol; j++) {
      if (currentWordFile.Length > 0) {
        COLOR(*m, i, j) = currentWordFile.TabWord[4 * j];
        CONTENT(*m, i, j) = currentWordFile.TabWord[4 * j + 2];
      }
    }
    ADVWORDFILE();
  }
}

void readUserConfig(char filePath[]) {
  CreateuserList();
  char fullPath[1000];
  concat(filePath, "/user.config", fullPath);
  STARTWORDFILE(fullPath);

  int countUser;

  countUser = wordToInt(currentWordFile);
  ADVWORDFILE();
  Word nama, pass, bio, numberHP, weton, status;
  PhotoMat pp;

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

    boolean isPublic = compareWordwString(status, "PUBLIC");
    CopyWordwWord(&status, &currentWordFile);

    ADVWORDFILE();

    readMatrix(&pp, 5, 5);
    loadUser(nama, pass, bio, numberHP, weton, isPublic, pp);
  }
  displayAllUsers();
}
