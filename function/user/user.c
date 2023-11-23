#include "user.h"
#include <stdio.h>

User currentUser;
boolean sudahMasuk;

boolean cekUnik(Word w){
/*true jika w tidak ada di userList, digunakan untuk mengecek keunikan nama pengguna*/
  /*KAMUS LOKAL*/
  int i;
  boolean unique;

  /*ALGORITMA*/
  i=0;
  unique=true;
  while(i<userCount() && unique){
    boolean a=compareWordwWord(NAMA(i),w);
    if (compareWordwWord(NAMA(i),w)) unique=false;
    i+=1;
  }
  return unique;
}

void daftar(){
/*prosedur pendaftaran user*/
  /*KAMUS LOKAL*/
  Word nama,pass;

  /*ALGORITMA*/
  if (userFull()) printf("Maaf, jumlah user saat ini sudah maksimal./n");
  else{
    printf("Masukkan nama: \n");
    STARTWORDnoIgnore(20);
    while(!cekUnik(currentWord)){
      printf("\nWah, sayang sekali nama tersebut telah diambil.\n");
      printf("Masukkan nama: \n");
      STARTWORDnoIgnore(20);
    }
    nama=currentWord;
    printf("\nMasukkan kata sandi: \n");
    STARTWORDnoIgnore(20);
    pass=currentWord;
    addUser(nama,pass);
    printf("\nPengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
  }
}

void masuk(){
/*prosedur log-in*/
  /*KAMUS LOKAL*/
  Word name;
  int i;

  /*ALGORITMA*/
  if (sudahMasuk) printf("Wah, Anda sudah masuk. Keluar dulu yuk!\n");
  else {
      printf("Masukkan nama:\n");
      STARTWORDnoIgnore(20);
      i=userIndex(currentWord);
      while (i==IDX_UNDEF_U){
        printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
        printf("\nMasukkan nama:\n");
        STARTWORDnoIgnore(20);
        i=userIndex(currentWord);
      }
      name=currentWord;
      printf("\nMasukkan kata sandi:\n");
      STARTWORDnoIgnore(20);
      while (!compareWordwWord(currentWord,PASS(i))){
        printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
        printf("\nMasukkan kata sandi:\n");
        STARTWORDnoIgnore(20);
      }
      currentUser=USER(i);
      sudahMasuk=true;
      printf("\nAnda telah berhasil masuk dengan nama pengguna ");
      printWord(currentUser.nama);
      printf(". Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n");
  }
}

void keluar(){
/*prosedur log-out*/
  /*KAMUS LOKAL*/

  /*ALGORITMA*/
  if(!sudahMasuk) printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
  else{
    printf("Anda berhasil logout. Sampai jumpa di pertemuan berikutnya!");
    sudahMasuk=false;
    /*currentUser tidak diganti karena untuk bisa-tidaknya menggunakan fungsi, dicek dari sudahMasuk.*/
  }
}