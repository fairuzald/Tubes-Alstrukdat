#include <stdio.h>

#include "function/error/error.h"
#include "procedure/splashscreen.h"
#include "function/input/input.h"

int main() {
  welcome();
  /*DISINI CONFIG*/

  CreateuserList();
  sudahMasuk=false;
  Word command;

  /*contoh main, buat testing- belum final*/
  printf("\nSilakan masukkan command: \n");
  readInput(&command);
  while(!compareWordwString(command,"TUTUP_PROGRAM")){
    if (!sudahMasuk){
      if (compareWordwString(command,"DAFTAR")) {
        ADV();
        daftar();
      }
      else if (compareWordwString(command,"MASUK")) {
        ADV();
        masuk();
      }
      else if (compareWordwString(command,"KELUAR")) {
        ADV();
        keluar();
      }
      else{
        printf("Command yang anda pilih belum bisa dilakukan, masuk dulu, yuk!");
      }
    }
    else{
      if (compareWordwString(command,"GANTI_PROFIL")) {
        ADV();
        ganti_profil();
      }
      else if (compareWordwString(command,"LIHAT_PROFIL")) {
        Word usn;
        ADVWORD();
        usn=currentWord;
        while(currentChar!=MARK){
          ADVWORD();
          ConcatWords(&usn,&usn,&currentWord);
          printWord(usn);
        }
        lihat_profil(usn);
      }
      else if (compareWordwString(command,"ATUR_JENIS_AKUN")){
        ADV();
        atur_jenis_akun();
      }
      else if (compareWordwString(command,"UBAH_FOTO_PROFIL")){
        ADV();
        ubah_foto_profil();
      }
    }
    printf("\nSilakan masukkan command: \n");
    readInput(&command);
  }
  printf("\nAnda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");

  return 0;
}