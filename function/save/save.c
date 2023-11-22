#include "save.h"

#include <stdio.h>
#include <sys/stat.h>  // Untuk fungsi mkdir dan struct stat
void concat(char *str1, char *str2, char *output) {
  int i, j;
  for (i = 0; str1[i] != '\0'; ++i) {
    output[i] = str1[i];
  }

  for (j = 0; str2[j] != '\0'; ++j, ++i) {
    output[i] = str2[j];
  }

  output[i] = '\0';
}

void saveUser(ListStatikUser *l, char folderName[]) {
  // Mengecek apakah direktori sudah ada
  struct stat st = {0};
  if (stat(folderName, &st) == -1) {
    mkdir(folderName, 0700);
  }

  char folderPath[200];
  concat(folderName, "/pengguna.config", folderPath);

  FILE *file = fopen(folderPath, "a");
  if (file == NULL) {
    printf("Tidak bisa membuat file pengguna.config\n");
    return;
  }

  // Menulis jumlah pengguna

  fprintf(file, "%d\n", userCount());
  // Menulis data setiap pengguna
  for (int i = 0; i < userCount(); i++) {
    User user = USER(i);

    // Potong karakter yang berlebihan
    if (user.nama.Length > 20) {
      user.nama.TabWord[20] = '\0';
    }
    if (user.password.Length > 20) {
      user.password.TabWord[20] = '\0';
    }
    if (user.bio.Length > 135) {
      user.bio.TabWord[135] = '\0';
    }

    fprintf(file, "%s\n", user.nama.TabWord);                  // Nama
    fprintf(file, "%s\n", user.password.TabWord);              // Password
    fprintf(file, "%s\n", user.bio.TabWord);                   // Bio
    fprintf(file, "%s\n", user.nomorHP.TabWord);               // No HP
    fprintf(file, "%s\n", user.weton.TabWord);                 // Weton
    fprintf(file, "%s\n", user.public ? "Publik" : "Privat");  // Jenis akun
    // Foto Profil
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        fprintf(file, "%c ", user.fotoProfil.color[j][k]);
        if (k < 4) {
          fprintf(file, "%c ", user.fotoProfil.content[j][k]);
        } else {
          fprintf(file, "%c ", user.fotoProfil.content[j][k]);
        }
      }
      fprintf(file, "\n");
    }
  }

  // for (int j = 0; j < userCount(); j++) {
  //   for (int k = 0; k < userCount(); k++) {
  //     if (k < userCount() - 1) {
  //       fprintf(file, "%c ", mFriend.Friendship.adjMatrix.mem[j][k]);
  //     } else {
  //       fprintf(file, "%c", mFriend.Friendship.adjMatrix.mem[j][k]);
  //     }
  //   }
  //   fprintf(file, "\n");
  // }
  fclose(file);
}