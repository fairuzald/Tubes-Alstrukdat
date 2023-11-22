#include "save.h"

#include <stdio.h>

void saveUser(ListStatikUser *l, char folderName[]) {
  FILE *file = fopen("pengguna.config", "w");
  if (file == NULL) {
    printf("Tidak bisa membuka file pengguna.config\n");
    return;
  }

  // Menulis jumlah pengguna
  fprintf(file, "%d\n", userCount());

  // Menulis data setiap pengguna
  for (int i = 0; i < userCount(); i++) {
    User user = USER(i);
    fprintf(file, "%s\n", user.nama.TabWord);                  // Nama
    fprintf(file, "%s\n", user.password.TabWord);              // Password
    fprintf(file, "%s\n", user.bio.TabWord);                   // Bio
    fprintf(file, "%s\n", user.nomorHP.TabWord);               // No HP
    fprintf(file, "%s\n", user.weton.TabWord);                 // Weton
    fprintf(file, "%s\n", user.public ? "Publik" : "Privat");  // Jenis akun

    // Foto Profil
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        fprintf(file, "%c ", user.fotoProfil.content[j][k]);
      }
      fprintf(file, "\n");
    }
  }

  fclose(file);
}
