#include "../../adt/input/wordmachine.h"
#include <stdio.h>

int main(){
  printf("Tes startword biasa\n");
  STARTWORD();
  printf("Kata yang dimasukkan: ");
  printWord(currentWord);
  printf(", Length: %d\n",currentWord.Length);
  while (currentChar!=MARK){
    ADVWORD();
    printf("Kata yang dimasukkan: ");
    printWord(currentWord);
    printf(", Length: %d\n",currentWord.Length);
  }
  printf("\nTes startword tanpa ignore\n");
  printf("Spasi dan newline akan masuk ke dalam Word, seluruh input akan menjadi satu word dengan panjang maksimal 100 karakter.\n");
  STARTWORDnoIgnore(100); 
  printf("Kata yang dimasukkan: ");
  printWord(currentWord);

  printf("\nTes lowercase menggunakan input sebelumnya\n");
  LowerCase();
  printWord(currentWord);

  printf("\nTes konversi string ke word dan membandingkan dengan string awal\n");
  Word w1 = stringToWord("testing");
  if (compareWordwString(w1,"testing")) printf("tes berhasil\n");
  
  printf("\nTes copy word ke word lain dan membandingkannya dengan w1\n");
  Word w2;
  CopyWordwWord(&w2,&w1);
  if (compareWordwWord(w2,w1)) printf("tes berhasil\n");

  printf("\nTes mengubah word menjadi integer\n");
  printf("\ninput angka\n");
  STARTWORDnoIgnore(20);
  int converted=wordToInt(currentWord);
  printf("input: %d\n",converted);

  printf("\nTes concat word\n");
  Word wAwal,wAkhir,wConcat;
  printf("Masukkan kata awal: \n");
  STARTWORDnoIgnore(10);
  wAwal=currentWord;
  printf("\nMasukkan kata akhir: \n");
  STARTWORDnoIgnore(10);
  wAkhir=currentWord;
  wConcat=stringToWord("i");
  ConcatWords(&wConcat,&wAwal,&wAkhir);
  printf("hasil concat: ");
  printWord(wConcat);
  return 0;
}