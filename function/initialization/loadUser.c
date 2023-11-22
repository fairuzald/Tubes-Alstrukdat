#include "loadUser.h"

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

void readUserConfig() {
  CreateuserList();
  STARTWORDFILE("pengguna.config");
  ADVFILE();

  int countUser;

  countUser = wordToInt(currentWordFile);
  ADVWORDFILE();
  Word nama, pass, bio, numberHP, weton, status;
  PhotoMat pp;

  for (int i = 0; i < countUser; i++) {
    CopyWordwWord(&nama, &currentWordFile);
    CropWord(&nama, 20);
    // printf("Nama: ");
    // printWord(nama);
    // printf("\n");
    ADVWORDFILE();

    CopyWordwWord(&pass, &currentWordFile);
    CropWord(&pass, 20);
    // printf("Pass: ");
    // printWord(pass);
    // printf("\n");
    ADVWORDFILE();

    CopyWordwWord(&bio, &currentWordFile);
    CropWord(&bio, 135);
    // printf("Bio: ");
    // printWord(bio);
    // printf("\n");
    ADVWORDFILE();

    CopyWordwWord(&numberHP, &currentWordFile);
    // printf("Number HP: ");
    // printWord(numberHP);
    // printf("\n");
    ADVWORDFILE();
    CopyWordwWord(&weton, &currentWordFile);
    // printf("Weton: ");
    // printWord(weton);
    // printf("\n");
    ADVWORDFILE();

    boolean isPublic = compareWordwString(status, "PUBLIC");
    CopyWordwWord(&status, &currentWordFile);
    // printf("Status: ");
    // printWord(status);
    // printf("\n");
    ADVWORDFILE();

    readMatrix(&pp, 5, 5);
    // displayMatrix(pp);
    loadUser(nama, pass, bio, numberHP, weton, isPublic, pp);
    // nunggu matrix pertemanan
  }
  // displayAllUsers();
}

int main() {
  readUserConfig();

  return 0;
}