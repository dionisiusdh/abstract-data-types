/* File : stacklist.c */
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "stacklist.h"

/* Prototype manajemen memori */
void Alokasi (address *P, infotype X){
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
    /* KAMUS LOKAL */

    /* KONSTANTA */
    *P = (address) malloc (sizeof(ElmtStack));

    if (*P != Nil) {
        Info(*P) = X;
        Next(*P) = Nil;
    }
}
void Dealokasi (address P){
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */ 
    /* KAMUS LOKAL */

    /* KONSTANTA */
    free(P);
}

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty (Stack S){
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
    /* KAMUS LOKAL */

    /* KONSTANTA */
    return Top(S) == Nil;
}
void CreateEmpty (Stack * S){
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack S yang kosong */
    /* KAMUS LOKAL */

    /* KONSTANTA */
    Top(*S) = Nil;
}
void Push (Stack * S, infotype X){
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
    /* KAMUS LOKAL */
    address P;

    /* KONSTANTA */
    Alokasi(&P, X);
    
    if (P != Nil) {
        Next(P) = Top(*S);
        Top(*S) = P;
    }
}
void Pop (Stack * S, infotype * X){
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */
    /* KAMUS LOKAL */
    address P;

    /* KONSTANTA */
    P = Top(*S);
    *X = Info(P);
    Top(*S) = Next(Top(*S));
    Next(P) = Nil;
    Dealokasi(P);
}