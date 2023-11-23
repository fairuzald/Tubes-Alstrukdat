/*
How to compile:
>> cd driver/adt
>> gcc listdintweet_driver.c ../../adt/listdintweet.c
../../function/tweet/tweet.c ../../adt/datetime.c
../../adt/time.c ../../adt/input/wordmachine.c ../../adt/input/charmachine.c -o
listdintweet_driver

How to run:
./listdintweet_driver
*/

#include <stdio.h>

#include "../../adt/listdintweet.h"

int main() {
  // Membuat beberapa Tweet untuk dimasukkan sebagai elemen ListDinTweet
  Word textA = stringToWord("Tweet pertama saya!");
  Word authorA = stringToWord("Maman Suraman");
  DATETIME timeA = getCurrentDateTime();
  long idTweetA = 1;
  long idReplyA = 0;
  long idUtasA = 0;
  long likeA = 0;
  long depthA = 0;
  AddressTweet reply1A = NULL;
  AddressTweet reply2A = NULL;
  AddressTweet utasA = NULL;
  AddressTweet pTweetA =
      CreateTweet(textA, authorA, timeA, idTweetA, idReplyA, idUtasA, likeA,
                  depthA, reply1A, reply2A, utasA);

  Word textB = stringToWord("Tweet kedua saya!");
  Word authorB = stringToWord("Dudung Surudung");
  DATETIME timeB = getCurrentDateTime();
  long idTweetB = 1;
  long idReplyB = 0;
  long idUtasB = 0;
  long likeB = 0;
  long depthB = 0;
  AddressTweet reply1B = NULL;
  AddressTweet reply2B = NULL;
  AddressTweet utasB = NULL;
  AddressTweet pTweetB =
      CreateTweet(textB, authorB, timeB, idTweetB, idReplyB, idUtasB, likeB,
                  depthB, reply1B, reply2B, utasB);

  Word textC = stringToWord("Tweet ketiga saya!");
  Word authorC = stringToWord("Heri Suheri");
  DATETIME timeC = getCurrentDateTime();
  long idTweetC = 1;
  long idReplyC = 0;
  long idUtasC = 0;
  long likeC = 0;
  long depthC = 0;
  AddressTweet reply1C = NULL;
  AddressTweet reply2C = NULL;
  AddressTweet utasC = NULL;
  AddressTweet pTweetC =
      CreateTweet(textC, authorC, timeC, idTweetC, idReplyC, idUtasC, likeC,
                  depthC, reply1C, reply2C, utasC);

  // Membuat ListDinTweet
  ListDinTweet myListTweet;
  int capacity = 2;
  CreateListDinTweet(&myListTweet, capacity);

  // Banyak elemen
  printf("Banyak elemen: %d\n", listTweetLength(myListTweet));

  // Cek apakah list kosong
  printf("Empty? (0/1): %d\n", isEmptyListTweet(myListTweet));

  // Cek apakah list penuh
  printf("Full? (0/1): %d\n", isFullListTweet(myListTweet));

  // Memasukkan elemen ke dalam list
  insertLastListTweet(&myListTweet, pTweetA);
  displayTweet(ELMT_LISTDINTWEET(myListTweet, 0));
  printf("Banyak elemen: %d\n", listTweetLength(myListTweet));
  printf("Empty? (0/1): %d\n", isEmptyListTweet(myListTweet));
  printf("Full? (0/1): %d\n", isFullListTweet(myListTweet));

  insertLastListTweet(&myListTweet, pTweetB);
  displayTweet(ELMT_LISTDINTWEET(myListTweet, 1));
  printf("Banyak elemen: %d\n", listTweetLength(myListTweet));
  printf("Empty? (0/1): %d\n", isEmptyListTweet(myListTweet));
  printf("Full? (0/1): %d\n", isFullListTweet(myListTweet));

  // Menambah kapasitas list
  expandListTweet(&myListTweet, 1);
  printf("Banyak elemen: %d\n", listTweetLength(myListTweet));
  printf("Empty? (0/1): %d\n", isEmptyListTweet(myListTweet));
  printf("Full? (0/1): %d\n", isFullListTweet(myListTweet));
  insertLastListTweet(&myListTweet, pTweetC);
  displayTweet(ELMT_LISTDINTWEET(myListTweet, 2));
  printf("Banyak elemen: %d\n", listTweetLength(myListTweet));
  printf("Empty? (0/1): %d\n", isEmptyListTweet(myListTweet));
  printf("Full? (0/1): %d\n", isFullListTweet(myListTweet));

  // Dealokasi ListDinTweet
  dealocateListDinTweet(&myListTweet);

  return 0;
}
