// #include "utas.h"

// void CreateUtas(Word textTweet, Word authorTweet,
//                          DATETIME timeCreatedTweet,
//                          long idUtas,
//                          AddressTweet utas, Tweet *prev){
//     // id tweet sudah ditemukan

//     AddressTweet temp = CreateTweet(textTweet, authorTweet,timeCreatedTweet,
//     0, 0,0, 0, 0, NULL, NULL, NULL);

//     // set id utas
//     Utas(temp) = Utas(prev)++;

//     // set address sebelumnya ke kicauan yang baru untuk utas
//     Utas(*prev) = temp;
// }

// void connectUtas(Word textTweet, Word authorTweet,
//                          DATETIME timeCreatedTweet, long idUtas, long index,
//                          Tweet *prev){
//     // id utas dan index sudah terkonfirmasi

//     AddressTweet temp = CreateTweet(textTweet, authorTweet,timeCreatedTweet,
//     0, 0, 0, 0, 0, NULL, NULL, NULL);

//     Utas(temp) = Utas(*prev);
//     Utas(*prev) = temp;
// }

// void deleteUtas(int index, Tweet *utama){
//     // utas sudah ditemukan
//     // menghapus id pada utas
//     // uas dimiliki oleh author tersebut
//     if(index == 0){
//         printf("\nAnda tidak bisa menghapus kicauan utama!\n");
//     }else{
//         int i = 1;
//         AddressTweet loc = Utas(utama);
//         while(i < index - 1){
//             i++;
//             loc = Utas(loc);
//         }
//         // ketemu sebelum index
//         AddressTweet p = Utas(loc);

//         Utas(loc) = Utas(p);
//         deallocateTweet(p)
//     }
// }

// void displayUtas(ListDinTweet l, int idUtas, AddressTweet pTweet){
//     // display ID
//     printf("| ID = %ld\n", Id(pTweet));

//     // display author
//     printf("| ");
//     int i;
//     for (i = 0; i < AuthorTweet(pTweet).Length; i++) {
//         printf("%c", AuthorTweet(pTweet).TabWord[i]);
//     }

//     printf("\n");

//     // display timeCreated
//     printf("| ");
//     TulisDATETIME(TimeCreatedTweet(pTweet));
//     printf("\n");

//     // display text
//     printf("| ");

//     for (i = 0; i < TextTweet(pTweet).Length; i++) {
//         printf("%c", TextTweet(pTweet).TabWord[i]);
//     }

//     printf("\n");

//     int id = 1
//     while(Utas(pTweet) != NULL){
//         // display id
//         printf("\n");
//         printf("    | INDEX = %d\n", id);

//         // display author
//         printf("    | ");
//         int i;
//         for (i = 0; i < AuthorTweet(pTweet).Length; i++) {
//             printf("%c", AuthorTweet(pTweet).TabWord[i]);
//         }
//         printf("\n");

//         // display timeCreated
//         printf("    | ");
//         TulisDATETIME(TimeCreatedTweet(pTweet));
//         printf("\n");

//         // display text
//         printf("    | ");

//         for (i = 0; i < TextTweet(pTweet).Length; i++) {
//             printf("%c", TextTweet(pTweet).TabWord[i]);
//         }

//         printf("\n");

//         printf("\n");
//         id++;
//         pTweet = Utas(pTweet)
//     }
// }