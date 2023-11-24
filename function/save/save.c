#include "save.h"

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void saveUser(ListStatikUser *l, char folderName[]) {
  // Mengecek apakah direktori sudah ada

  char folderPath[200];
  concat(folderName, "/pengguna.config", folderPath);
  printf("%s\n", folderPath);

  FILE *file = fopen(folderPath, "a");
  if (file == NULL) {
    printf("Tidak bisa membuat file pengguna.config\n");
    return;
  }

  // Menulis jumlah pengguna

  fprintf(file, "%d\n", userCount());
  // Menulis data setiap pengguna
  for (int i = 0; i < userCount(); i++) {
    // Potong karakter yang berlebihan
    if (NAMA(i).Length > 20) {
      NAMA(i).TabWord[20] = '\0';
    } else {
      NAMA(i).TabWord[NAMA(i).Length] = '\0';
    }
    if (PASS(i).Length > 20) {
      PASS(i).TabWord[20] = '\0';
    } else {
      PASS(i).TabWord[PASS(i).Length] = '\0';
    }
    if (BIO(i).Length > 135) {
      BIO(i).TabWord[135] = '\0';
    } else {
      BIO(i).TabWord[BIO(i).Length] = '\0';
    }

    fprintf(file, "%s\n", NAMA(i).TabWord);  // Nama
    fprintf(file, "%s\n", PASS(i).TabWord);  // Password
    fprintf(file, "%s\n", BIO(i).TabWord);   // Bio
    HP(i).TabWord[HP(i).Length] = '\0';
    fprintf(file, "%s\n", HP(i).TabWord);  // No HP
    WETON(i).TabWord[WETON(i).Length] = '\0';
    fprintf(file, "%s\n", WETON(i).TabWord);                 // Weton
    fprintf(file, "%s\n", PUBLIC(i) ? "Publik" : "Privat");  // Jenis akun
    // Foto Profil
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        fprintf(file, "%c ", FOTO(i).color[j][k]);
        if (k < 4) {
          fprintf(file, "%c ", FOTO(i).content[j][k]);
        } else {
          fprintf(file, "%c ", FOTO(i).content[j][k]);
        }
      }
      fprintf(file, "\n");
    }
  }

  for (int j = 0; j < grafPertemanan.n; j++) {
    for (int k = 0; k < grafPertemanan.n; k++) {
      if (k < grafPertemanan.n - 1) {
        fprintf(file, "%c ", grafPertemanan.mem[j][k]);
      } else {
        fprintf(file, "%c", grafPertemanan.mem[j][k]);
      }
    }
    fprintf(file, "\n");
  }

  fclose(file);
}
void saveTweet(ListDinTweet *l, char folderName[]) {
  char folderPath[200];
  concat(folderName, "/kicauan.config", folderPath);
  FILE *file = fopen(folderPath, "w");
  if (file == NULL) {
    printf("Tidak bisa membuat file kicauan.config\n");
    return;
  }

  // Menulis jumlah kicauan
  fprintf(file, "%ld\n", NEFF_LISTDINTWEET(*l));

  // Menulis data setiap kicauan
  for (int i = 0; i < NEFF_LISTDINTWEET(*l); i++) {
    AddressTweet tweet = ELMT_LISTDINTWEET(*l, i);

    fprintf(file, "%ld\n", IdTweet(tweet));             // ID kicauan
    fprintf(file, "%s\n", TextTweet(tweet).TabWord);    // Text
    fprintf(file, "%ld\n", Like(tweet));                // Like
    fprintf(file, "%s\n", AuthorTweet(tweet).TabWord);  // Author
    fprintf(file, "%02d/%02d/%04d %02d:%02d:%02d\n",    // Datetime
            TimeCreatedTweet(tweet).DD, TimeCreatedTweet(tweet).MM,
            TimeCreatedTweet(tweet).YYYY, TimeCreatedTweet(tweet).T.HH,
            TimeCreatedTweet(tweet).T.MM, TimeCreatedTweet(tweet).T.SS);
  }

  fclose(file);
}

void saveUtas(ListDinTweet *l, char folderName[]) {
  char folderPath[200];
  concat(folderName, "/utas.config", folderPath);
  FILE *file = fopen(folderPath, "w");
  if (file == NULL) {
    printf("Tidak bisa membuat file utas.config\n");
    return;
  }

  // Menulis jumlah kicauan yang memiliki utas
  fprintf(file, "%ld\n", NEFF_LISTDINTWEET(*l));

  // Menulis data setiap utas
  for (int i = 0; i < NEFF_LISTDINTWEET(*l); i++) {
    AddressTweet tweet = ELMT_LISTDINTWEET(*l, i);

    if (Utas(tweet) != NULL) {                 // Jika tweet ini memiliki utas
      fprintf(file, "%ld\n", IdTweet(tweet));  // ID kicauan

      AddressTweet utas = Utas(tweet);
      int utasCount = 0;
      while (utas != NULL) {  // Menghitung jumlah utas
        utasCount++;
        utas = Utas(utas);
      }

      fprintf(file, "%d\n", utasCount);  // Jumlah utas

      utas = Utas(tweet);
      while (utas != NULL) {  // Menulis setiap utas
        fprintf(file, "%s\n", TextTweet(utas).TabWord);
        fprintf(file, "%s\n", AuthorTweet(utas).TabWord);
        fprintf(file, "%02d/%02d/%04d %02d:%02d:%02d\n",  // Datetime
                TimeCreatedTweet(utas).DD, TimeCreatedTweet(utas).MM,
                TimeCreatedTweet(utas).YYYY, TimeCreatedTweet(utas).T.HH,
                TimeCreatedTweet(utas).T.MM, TimeCreatedTweet(utas).T.SS);

        utas = Utas(utas);
      }
    }
  }

  fclose(file);
}
void saveReply(ListDinTweet *l, char folderName[]) {
  char folderPath[200];
  concat(folderName, "/balasan.config", folderPath);
  FILE *file = fopen(folderPath, "w");
  if (file == NULL) {
    printf("Tidak bisa membuat file balasan.config\n");
    return;
  }

  // Menulis jumlah kicauan yang memiliki balasan
  fprintf(file, "%ld\n", NEFF_LISTDINTWEET(*l));

  // Menulis data setiap balasan
  for (int i = 0; i < NEFF_LISTDINTWEET(*l); i++) {
    AddressTweet tweet = ELMT_LISTDINTWEET(*l, i);

    if (Reply1(tweet) != NULL ||
        Reply2(tweet) != NULL) {  // Jika tweet ini memiliki balasan
      fprintf(file, "%ld\n", IdTweet(tweet));  // ID kicauan

      AddressTweet reply = Reply1(tweet);
      int replyCount = 0;
      while (reply != NULL) {  // Menghitung jumlah balasan
        replyCount++;
        reply = Reply1(reply);
      }

      fprintf(file, "%d\n", replyCount);  // Jumlah balasan

      reply = Reply1(tweet);
      int couter = 0;
      while (reply != NULL) {
        if (couter == 0) {
          fprintf(file, "-1 %ld\n", IdReply(reply));
        }  // Parent dan ID balasan
        else {
          fprintf(file, "1 %ld\n", IdTweet(reply));  // ID balasan
        }
        fprintf(file, "%s\n", TextTweet(reply).TabWord);    // Isi balasan
        fprintf(file, "%s\n", AuthorTweet(reply).TabWord);  // Author
        fprintf(file, "%02d/%02d/%04d %02d:%02d:%02d\n",    // Datetime
                TimeCreatedTweet(reply).DD, TimeCreatedTweet(reply).MM,
                TimeCreatedTweet(reply).YYYY, TimeCreatedTweet(reply).T.HH,
                TimeCreatedTweet(reply).T.MM, TimeCreatedTweet(reply).T.SS);

        reply = Reply1(reply);
      }
      reply = Reply1(tweet);
    }
  }

  fclose(file);
}

void saveTweetReplyUtas(ListDinTweet *l, char folderName[]) {
  /// Mengecek apakah direktori sudah ada

  saveTweet(l, folderName);
  saveUtas(l, folderName);
}

void saveDraft(ListStackDraft *l, char folderName[]) {
  // Mengecek apakah direktori sudah ada

  char folderPath[200];
  concat(folderName, "/draf.config", folderPath);

  FILE *file = fopen(folderPath, "w");
  if (file == NULL) {
    printf("Tidak bisa membuat file draf.config\n");
    return;
  }

  // Menulis jumlah pengguna yang punya draft
  fprintf(file, "%d\n", NEFF_LISTSTACKDRAFT(*l));

  // Menulis data setiap draft
  for (int i = 0; i < NEFF_LISTSTACKDRAFT(*l); i++) {
    StackDraft draft = ELMT_LISTSTACKDRAFT(*l, i);

    fprintf(file, "%s %ld\n", AuthorDraft(draft).TabWord,
            draft.TOP + 1);  // username pengguna dan banyak draft

    for (int j = 0; j <= draft.TOP; j++) {
      fprintf(file, "%s\n", TextDraft(draft.T[j]).TabWord);
      fprintf(
          file, "%02d/%02d/%04d %02d:%02d:%02d\n",  // Datetime
          TimeCreatedDraft(draft.T[j]).DD, TimeCreatedDraft(draft.T[j]).MM,
          TimeCreatedDraft(draft.T[j]).YYYY, TimeCreatedDraft(draft.T[j]).T.HH,
          TimeCreatedDraft(draft.T[j]).T.MM, TimeCreatedDraft(draft.T[j]).T.SS);
      // isi draft dan tanggal pembuatan draf terakhir
    }
  }

  fclose(file);
}

void createFolder(char *folderName) {
#ifdef __linux__
  mkdir(folderName, 0777);
#else
  mkdir(folderName);
#endif
}

void saveToFolder(char *folderName) {
  printf("Anda akan melakukan penyimpanan di %s.\n\n", folderName);
  for (int i = 1; i <= 3; i++) {
    printf("%d...\n", i);
  }

  // Masukin fungsi penyimpanan disini
  saveUser(&userList, folderName);

  printf("Penyimpanan telah berhasil dilakukan!\n\n");
}

void simpan() {
  char folderName[256];
  struct stat st = {0};

  printf("Masukkan nama folder penyimpanan\n");
  scanf("%s", folderName);
  if (stat(folderName, &st) == -1) {
    printf(
        "Belum terdapat %s. Akan dilakukan pembuatan %s terlebih dahulu.\n\n",
        folderName, folderName);
    for (int i = 1; i <= 3; i++) {
      printf("%d...\n", i);
    }
    createFolder(folderName);
    printf("%s sudah berhasil dibuat.\n\n", folderName);
  }

  saveToFolder(folderName);
}