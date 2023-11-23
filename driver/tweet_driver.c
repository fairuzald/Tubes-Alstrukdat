/*
How to compile:
>> cd driver
>> gcc tweet_driver.c ../function/tweet/tweet.c ../adt/datetime.c ../adt/time.c
../adt/input/wordmachine.c ../adt/input/charmachine.c -o tweet_driver

How to run:
>> ./tweet_driver
*/

#include <stdio.h>

#include "../function/tweet/tweet.h"

int main() {
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

  // Membuat Tweet
  AddressTweet pTweetA =
      CreateTweet(textA, authorA, timeA, idTweetA, idReplyA, idUtasA, likeA,
                  depthA, reply1A, reply2A, utasA);

  // Menampilkan Tweet
  displayTweet(pTweetA);

  // Menampilkan Tweet
  likeTweet(pTweetA);
  displayTweet(pTweetA);

  // Mengganti isi Tweet
  Word textARevision = stringToWord("Revisi tweet pertama    aadawda71987&^&*");
  editTweet(pTweetA, textARevision);
  displayTweet(pTweetA);

  // Dealokasi Tweet
  deallocateTweet(pTweetA);

  return 0;
}