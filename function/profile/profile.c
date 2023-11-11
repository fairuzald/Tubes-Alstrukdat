#include "profile.h"


void initPP(PhotoMat P){
/* Menginitialisasi foto profil */
  /*KAMUS LOKAL*/
  int i,j;

  /*ALGORITMA*/
  for (i=0;i<5;i++){
    for(j=0;j<5;j++){
      CONTENT(P,i,j)='*';
      COLOR(P,i,j)='R';
    }
  }
}