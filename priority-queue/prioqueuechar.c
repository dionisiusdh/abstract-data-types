#include <stdio.h>
#include <stdlib.h>
#include "prioqueuechar.h"
#include "boolean.h"

/* File : prioqueuechar.c */
/* Body ADT prioqueuechar */

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
    return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}
boolean IsFull (PrioQueueChar Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
    return (NBElmt(Q) == MaxEl(Q));
}
int NBElmt (PrioQueueChar Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    if (IsEmpty(Q)) {
        return 0;
    } else {
        if (Head(Q) == Tail(Q)) {
            return 1;
        } else if (Head(Q) < Tail(Q)) {
            return (Tail(Q) - Head(Q) + 1);  
        } else {
             return (MaxEl(Q) - Head(Q) + Tail(Q) + 1);
        }
    }
}

/* *** Kreator *** */
void MakeEmpty (PrioQueueChar * Q, int Max){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    (*Q).T = (infotype *) malloc (Max * sizeof(infotype));
    if ((*Q).T != NULL) {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        MaxEl(*Q) = 0;
    }
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    MaxEl(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infotype X){
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
    /* KAMUS LOKAL */
    boolean found = false;
    int i = 0;
    int j;

    /* ALGORITMA */
    if (IsEmpty(*Q)) {
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoHead(*Q) = X;
        InfoTail(*Q) = X;
    } else {
        if (Tail(*Q) == MaxEl(*Q) - 1) {
            Tail(*Q) = 0;
        } else {    
            Tail(*Q) += 1;
        }

        while (!found && (i < NBElmt(*Q) - 1)) {
            if (Elmt(*Q,i).prio > X.prio) {
                j = Tail(*Q)-1;

                while (j >= i) {
                    Elmt(*Q, j+1) = Elmt(*Q, j);
                    j -= 1;
                }

                Elmt(*Q, i) = X;

                found = true;
            }

            i += 1;
        }

        if (!found) {
            InfoTail(*Q) = X;
        }
    }
}
void Dequeue (PrioQueueChar * Q, infotype * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    *X = InfoHead(*Q);

    if (NBElmt(*Q) == 1) {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        if (Head(*Q) == MaxEl(*Q) - 1){
            Head(*Q) = 0;
        } else {  
            Head(*Q) += 1;
        }
    }
}

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q){
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
    /* KAMUS LOKAL */
    infotype X;

    /* ALGORITMA */
    while (!IsEmpty(Q)) {
        Dequeue(&Q,&X);
        printf("%d %c\n", X.prio, X.info);
    }

    printf("#\n");
}