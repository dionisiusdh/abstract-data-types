/* File: arraydin.c */
/* *** Body ADT arraydin *** */

#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"
#include "boolean.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel){
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    TI(*T) = (ElType *) malloc (maxel*sizeof(ElType));
    Neff(*T) = 0;
    MaxEl(*T) = maxel;
}

void Dealokasi(TabInt *T){
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
    free(TI(*T));
    MaxEl(*T) = 0;
    Neff(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T){
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
    /*KAMUS LOKAL*/
    
    /*ALGORITMA*/
    return Neff(T);
}
int MaxElement(TabInt T){
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    /*KAMUS LOKAL*/
    
    /*ALGORITMA*/
    return MaxEl(T);
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
    /*KAMUS LOKAL*/
    
    /*ALGORITMA*/
    return IdxMin;
}
IdxType GetLastIdx(TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
    /*KAMUS LOKAL*/
    
    /*ALGORITMA*/
    return (NbElmt(T)-1);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
    /*KAMUS LOKAL*/
    
    /*ALGORITMA*/
    return ((i >= IdxMin) && (i <= MaxElement(T)-1));
}
boolean IsIdxEff(TabInt T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
    /*KAMUS LOKAL*/
    
    /*ALGORITMA*/
    return ((i >= IdxMin) && (i <= NbElmt(T)-1));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
    /*KAMUS LOKAL*/
    
    /*ALGORITMA*/
    return (Neff(T) == 0);
}
/* *** Test tabel penuh *** */
boolean IsFull(TabInt T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    /*KAMUS LOKAL*/
    
    /*ALGORITMA*/
    return (NbElmt(T) == MaxElement(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T){
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
    /*KAMUS LOKAL*/
    int N;
    IdxType i;

    /*ALGORITMA*/
    do {
        scanf("%d",&N);
    } while ((N<0) || (N > (MaxElement(*T))));

    for (i=IdxMin; i<N; i++){
        scanf("%d", &Elmt(*T,i));
    }

    Neff(*T) = N;
}
void TulisIsiTab(TabInt T){
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
    /*KAMUS LOKAL*/
   IdxType i;

   /*ALGORITMA*/
   if(IsEmpty(T)){
      printf("[]");
   } else {
      printf("[");
      for(i=IdxMin; i<=GetLastIdx(T);i++){
         if (i == GetLastIdx(T)){
            printf("%d",Elmt(T,i));
         } else {
            printf("%d,",Elmt(T,i));
         }
      }
      printf("]");
   }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus){
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
    /*KAMUS LOKAL*/
    IdxType i;
    TabInt T3;

    /*ALGORITMA*/
    MakeEmpty(&T3,MaxElement(T1));

    if(plus){
        for(i=IdxMin; i<=GetLastIdx(T1); i++){
            Elmt(T3,i) = Elmt(T1,i) + Elmt(T2,i);
        }
    } else {
        for(i=IdxMin; i<=GetLastIdx(T1); i++){
            Elmt(T3,i) = Elmt(T1,i) - Elmt(T2,i);
        }
    }

    Neff(T3) = NbElmt(T1);

    return T3;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2){
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
    /*KAMUS LOKAL*/
    IdxType i=0;
    boolean equal;

    equal = true;

    /*ALGORITMA*/
    if(NbElmt(T1) == NbElmt(T2)){
        while((equal == true) && (i<=GetLastIdx(T1))){
                if(Elmt(T1,i) != Elmt(T2,i)){
                    equal = false;
                }
            i += 1;
        }
    } else {
        equal = false;
    }
    return equal;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
    /*KAMUS LOKAL*/
    IdxType i;
    IdxType idx;
    boolean found = false;
    i = IdxMin;

    /*ALGORITMA*/
    if(IsEmpty(T)){
        return IdxUndef;
    } else {
        while((found == false) && (i<=GetLastIdx(T))){
            if(Elmt(T,i) == X){
                idx = i;
                found = true;
            }
            i += 1;
        }
    }

    if(found == true){
            return idx;
    } else {
        return IdxUndef;
    }
}
boolean SearchB(TabInt T, ElType X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    return Search1(T,X) != IdxUndef;
}

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min){
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
    /*KAMUS LOKAL*/
   IdxType i;
   *Max = Elmt(T,IdxMin);
   *Min = Elmt(T,IdxMin);
   
   /*ALGORITMA*/
   for(i=IdxMin; i<=GetLastIdx(T); i++){
      if(Elmt(T,i) > *Max){
         *Max = Elmt(T,i);
      }
      if(Elmt(T,i) < *Min){
         *Min = Elmt(T,i);
      }
   }
}

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout){
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
    /*KAMUS LOKAL*/
    int i;
    /*ALGORITMA*/
    MakeEmpty(Tout, MaxElement(Tin));

    Neff(*Tout) = NbElmt(Tin);
    MaxEl(*Tout) = MaxElement(Tin);

    for(i=IdxMin; i<=GetLastIdx(Tin);i++){
        Elmt(*Tout,i) = Elmt(Tin,i);
    }
}
ElType SumTab(TabInt T){
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
    /*KAMUS LOKAL*/
    IdxType i;
    int sum=0;

    /*ALGORITMA*/
    for(i=IdxMin; i<=GetLastIdx(T); i++){
        sum += Elmt(T,i);
    }
    
    return sum;
}
int CountX(TabInt T, ElType X){
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
    /*KAMUS LOKAL*/
    IdxType i;
    int n = 0;
    
    /*ALGORITMA*/
    if(IsEmpty(T)){
        return 0;
    } else {
        for(i=IdxMin; i<=GetLastIdx(T); i++){
            if(Elmt(T,i) == X){
                n += 1;
                }
            }
        }
    return n;
}
boolean IsAllGenap(TabInt T){
/* Menghailkan true jika semua elemen T genap. T boleh kosong */
    /*KAMUS LOKAL*/
    IdxType i;
    boolean genap;

    i = IdxMin;
    genap = true;

    /*ALGORITMA*/
    if(IsEmpty(T)){
        return true;
    } else {
        while((genap == true) && (i<=GetLastIdx(T))){
            if(Elmt(T,i)%2 != 0){
                genap=false;
                }
            i += 1;
            }
        }
    return genap;
}

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc){
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
    /*KAMUS LOKAL*/
   IdxType i, j;
   IdxType n;
   ElType temp;
   
   /*ALGORITMA*/
   n = GetLastIdx(*T);

   if(asc == true){
      for(i=IdxMin; i<=n; i++){
         for(j=i+1; j<=n;j++){
            if(T->TI[i] > T->TI[j]){
               temp = T->TI[i];
               T->TI[i] = T->TI[j];
               T->TI[j] = temp;
            }
         }
      }
   } else {
      for(i=IdxMin; i<=n; i++){
         for(j=i+1; j<=n;j++){
            if(T->TI[i] < T->TI[j]){
               temp = T->TI[i];
               T->TI[i] = T->TI[j];
               T->TI[j] = temp;
            }
         }
      }
   }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X){
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
    /*ALGORITMA*/
   Elmt(*T, Neff(*T)) = X;
   Neff(*T) += 1;
}
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X){
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
    /*KAMUS LOKAL*/
   
   /*ALGORITMA*/
   *X = Elmt(*T, GetLastIdx(*T));
   Neff(*T) -= 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num){
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
    /*KAMUS LOKAL*/
    TabInt temp;
    int i;

    /*ALGORITMA*/
    MakeEmpty(&temp, MaxElement(*T));
    CopyTab(*T,&temp);

    Dealokasi(T);
    MakeEmpty(T, MaxElement(temp)+num);

    Neff(*T) = Neff(temp);
    for (i = GetFirstIdx(temp); i  <= GetLastIdx(temp);  ++i){
        Elmt(*T, i) = Elmt(temp, i);
    }

    Dealokasi(&temp);
}

void ShrinkTab(TabInt *T, int num){
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
    /*KAMUS LOKAL*/
    TabInt temp;
    int i;

    /*ALGORITMA*/
    MakeEmpty(&temp, MaxElement(*T));
    CopyTab(*T,&temp);

    Dealokasi(T);
    MakeEmpty(T, MaxElement(temp)-num);
    
    Neff(*T) = Neff(temp);
    for (i = GetFirstIdx(temp); i  <= GetLastIdx(temp);  ++i){
        Elmt(*T, i) = Elmt(temp, i);
    }

    Dealokasi(&temp);
}

void CompactTab(TabInt *T){
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
    /*KAMUS LOKAL*/
    TabInt temp;

    /*ALGORITMA*/
    MakeEmpty(&temp, MaxElement(*T));
    CopyTab(*T,&temp);

    Dealokasi(T);
    MakeEmpty(T, NbElmt(temp));
    
    CopyTab(temp,T);

    Dealokasi(&temp);
    MaxEl(*T) = NbElmt(*T);
}
