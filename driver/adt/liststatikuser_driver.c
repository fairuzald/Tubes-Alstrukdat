#include "../../adt/input/wordmachine.h"
#include "../../adt/liststatikuser.h"
#include "../../function/profile/profile.h"
#include "../../function/friend/friend.h"
#include <stdio.h>

int main(){
  
  //test create userList
  CreateuserList(); //fungsi initPP juga dijalankan di dalam fungsi ini
  displayAllUsers(); //memastikan userList kosong, fungsi noUsers dan getlastuserId dipanggil di sini
  printWord(NAMA(0)); printf("\n"); //memastikan nama masih kosong
  displayPhoto(FOTO(0)); //memastikan foto profil terinisialisasi dengan benar

  //menyoba menambahkan beberapa user
  Word u1 = stringToWord("user1");
  Word p1 = stringToWord("pass1");
  Word u2 = stringToWord("user2");
  Word p2 = stringToWord("pass2");
  addUser(u1, p1);
  addUser(u2, p2);
  printf("userCount: %d\n", userCount()); //memastikan usercount == 2
  displayAllUsers(); //memastikan user berhasil ditambahkan
  int id = userIndex(u1); //melihat index user dengan nama u1 (seharusnya 0)
  printf("id: %d\n", id);

  //mengecek userFull
  while(!userFull()){
    addUser(u1, p1); //nama tidak perlu unik karena pengecekan dilakukan di user.c, bukan di fungsi addUser
  }
  printf("userCount: %d\n", userCount()); //memastikan usercount == 20
  return 0;
}