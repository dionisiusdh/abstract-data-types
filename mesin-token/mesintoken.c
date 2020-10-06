/* File: mesintoken.c */
/* *** Body ADT mesintoken *** */

#include <stdio.h>
#include "mesinkar.h"
#include "mesintoken.h"
#include "boolean.h"

/* State Mesin Token */
boolean EndToken;
Token CToken;

void IgnoreBlank(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
   /* KAMUS LOKAL */

    /* ALGORITMA */
    while (CC == BLANK) {
        ADV();
    }
}

void STARTTOKEN(){
/* I.S. : CC sembarang 
   F.S. : EndToken = true, dan CC = MARK; 
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */
   /* KAMUS LOKAL */

    /* ALGORITMA */
    START();
    IgnoreBlank();
    if (CC == MARK) {
        EndToken = true;
    } else {
        EndToken = false;
        SalinToken();
    }
}

void ADVTOKEN(){
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
   /* KAMUS LOKAL */

    /* ALGORITMA */
    IgnoreBlank();
    if (CC == MARK) {
        EndToken = true;
    } else {
        SalinToken();
    }
    IgnoreBlank();
}

void SalinToken(){
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
   /* KAMUS LOKAL */
   int i;
   /* ALGORITMA */
   i = 0;

   while ((CC != MARK) && (CC != BLANK) && (i < NMax)) {
      if (((CC == '+') || (CC == '-') || (CC == '*') || (CC == '/') || (CC == '^'))) {
         CToken.tkn = CC;
         CToken.val = -1;
      } else {
         int j = 0;
         int bil[NMax-i];

         while ((CC != MARK) && (CC != BLANK) && (i+j < NMax)) {
               int bilCC = CC - '0';
               bil[j] = bilCC;
               j++;
               ADV();
         }

         i += j;
         CToken.val = bil[0];

         for (int k = 1; k < j; k++) {
            CToken.val = CToken.val * 10;
            CToken.val = CToken.val + bil[k];
         }

         CToken.tkn = 'b';
      }
      ADV();
      i++;
   }

}
