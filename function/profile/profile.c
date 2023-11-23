#include "profile.h"
#include <stdio.h>

void displayPhoto(PhotoMat m) {
  /* I.S. m terdefinisi */
  /* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing
  elemen per baris dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan
  newline */
  /* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris
   * dan per kolom */
  /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
  1 2 3
  4 5 6
  8 9 10
  */

  int i, j;

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      if (COLOR(m, i, j) == 'R') {
        print_red(CONTENT(m, i, j));
      } else if (COLOR(m, i, j) == 'G') {
        print_green(CONTENT(m, i, j));
      } else {
        print_blue(CONTENT(m, i, j));
      }
      if (j == 4) {
        printf("\n");
      }
    }
  }
}


boolean numberCheck(Word w){
  /*mengembalikan true jika w adalah angka*/
  /*KAMUS LOKAL*/
  int i;
  boolean angka;
  /*ALGORITMA*/
  i=0;
  angka=true;
  while (i<w.Length && angka){
    if (w.TabWord[i]<'0' || w.TabWord[i]>'9'){
      angka=false;
    }
    i++;
  }
  return angka;
}

void ganti_profil(){
/*Digunakan untuk mengganti isi profil Currentuser (selain foto profil dan jenis akun)*/
  /*KAMUS LOKAL*/
  int id;
  /*ALGORITMA*/
  printf("\n| Nama: "); printWord(currentUser.nama);
  printf("\n| Bio Akun: "); printWord(currentUser.bio);
  printf("\n| No HP:" ); printWord(currentUser.nomorHP);
  printf("\n| Weton:" ); printWord(currentUser.weton);
 

  printf("\nMasukkan bio akun: \n");
  STARTWORDnoIgnore(135);
  currentUser.bio=currentWord;
  printf("\nMasukkan No HP dengan panjang maksimal 15 angka: \n");
  STARTWORDnoIgnore(15);
  while(!numberCheck(currentWord)){
    printf("\nNo HP tidak valid. Masukkan lagi, yuk!\n");
    printf("\nMasukkan No HP dengan panjang maksimal 15 angka: \n");
    STARTWORDnoIgnore(15);    
  }
  currentUser.nomorHP=currentWord;
  printf("\nMasukkan Weton: \n");
  STARTWORD();
  LowerCase();
  while((!compareWordwString(currentWord,"pahing"))&&(!compareWordwString(currentWord,"kliwon"))&&(!compareWordwString(currentWord,"wage"))&&(!compareWordwString(currentWord,"pon"))&&(!compareWordwString(currentWord,"legi"))){
    printf("Weton anda tidak valid! Masukkan lagi, yuk!\n");
    printf("\nMasukkan Weton: \n");
    STARTWORD();
    LowerCase();
  }
  currentUser.weton=currentWord;
  id=userIndex(currentUser.nama);
  USER(id)=currentUser;
  printf("\nProfil anda sudah berhasil diperbarui!\n");

}

void lihat_profil(Word Username){
/*Digunakan untuk melihat profil milik Username*/
  /*KAMUS LOKAL*/
  int i;

  /*ALGORITMA*/
  i=userIndex(Username);
  if(i!=IDX_UNDEF){
    if(PUBLIC(i)){
      printf("\n| Nama: "); printWord(NAMA(i));
      printf("\n| Bio Akun: "); printWord(BIO(i));
      printf("\n| No HP: " ); printWord(HP(i));
      printf("\n| Weton: " ); printWord(WETON(i));
      printf("\nFoto profil akun "); printWord(NAMA(i));
      printf("\n");
      displayPhoto(FOTO(i)); printf("\n");
    }
    else{
      printf("Wah, akun "); printWord(NAMA(i)); printf(" diprivat nih. Ikuti dulu yuk untuk bisa melihat profil "); printf("!\n");
    }
  }
  else{
    printf("Wah, akun dengan nama "); printWord(Username); printf(" tidak ditemukan. Coba lagi, yuk!\n");
  }

}


void atur_jenis_akun(){
/*Digunakan untuk mengganti jenis akun Currentuser*/
  /*KAMUS LOKAL*/ 
  int id;
  /*ALGORITMA*/
  printf("\nSaat ini, akun Anda adalah akun ");
  if (currentUser.public) printf("Publik. Ingin mengubah ke akun Privat? (YA/TIDAK)\n");
  else printf("Privat. Ingin mengubah ke akun Publik? (YA/TIDAK)\n");

  STARTWORD();
  while (!compareWordwString(currentWord,"YA") && !compareWordwString(currentWord,"TIDAK")){
    printf("Wah, masukan anda tidak valid!\n");
    printf("\nSaat ini, akun Anda adalah akun ");
    if (currentUser.public) printf("Publik. Ingin mengubah ke akun Privat? (YA/TIDAK)\n");
    else printf("Privat. Ingin mengubah ke akun Publik? (YA/TIDAK)\n");
    STARTWORD();
  }
  
  if(compareWordwString(currentWord,"YA")){
    currentUser.public=!currentUser.public;
    if (currentUser.public) printf("\nAkun anda sudah diubah menjadi akun Publik.\n");
    else printf("\nAkun anda sudah diubah menjadi akun Privat.\n");
    id=userIndex(currentUser.nama);
    USER(id)=currentUser;
  }
  else{
    printf("\nAkun anda tidak berubah.\n");
  }
}

void ubah_foto_profil(){
/*Digunakan untuk mengubah foto profil Currentuser*/
  /*KAMUS LOKAL*/
  int i,j,k,id;
  /*ALGORITMA*/
  printf("\nFoto profil Anda saat ini adalah\n");
  displayPhoto(currentUser.fotoProfil);
  printf("\nMasukkan foto profil yang baru!\n");
  printf("(Masukkan TIDAK jika anda tidak jadi merubah foto profil)\n");
  STARTWORD();
  i=0;
  j=0;
  while(currentChar!=MARK){
    for (k=0;k<5;k++){
      if (k==4){
        COLOR(currentUser.fotoProfil,i,j)=currentWord.TabWord[0];
        CONTENT(currentUser.fotoProfil,i,j)=currentChar;
        ADV();
        ADVWORD();
        i++;
        j=0;
      }
      else{
        COLOR(currentUser.fotoProfil,i,j)=currentWord.TabWord[0];
        ADVWORD();
        CONTENT(currentUser.fotoProfil,i,j)=currentWord.TabWord[0];
        j++;
        ADVWORD();
      }
    }
  }
  id=userIndex(currentUser.nama);
  USER(id)=currentUser;
  printf("\nFoto profil anda sudah berhasil diganti!\n");
}