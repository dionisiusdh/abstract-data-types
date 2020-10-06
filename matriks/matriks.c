/* File: matriks.c */
/* *** Body ADT matriks *** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matriks.h"
#include "boolean.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M) {
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
   NBrsEff(*M) = NB;
   NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
   return ((i >= BrsMin) && (i <= BrsMax)) && ((j >= KolMin) && (j <= KolMax));
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terkecil M */
   return (BrsMin);
}
indeks GetFirstIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terkecil M */
   return (KolMin);
}
indeks GetLastIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terbesar M */
   return (NBrsEff(M) - 1);
}
indeks GetLastIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terbesar M */
   return (NKolEff(M) - 1);
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
   return ((i >= BrsMin) && (i <= GetLastIdxBrs(M))) && ((j >= KolMin) && (j <= GetLastIdxKol(M)));
}
ElType GetElmtDiagonal (MATRIKS M, indeks i){
/* Mengirimkan elemen M(i,i) */
   return Elmt(M,i,i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
/* Melakukan assignment MHsl  MIn */
   /*KAMUS*/
   indeks i, j;

   /*ALGORITMA*/
   MakeMATRIKS(NBrsEff(MIn),NKolEff(MIn),MHsl);
   
   for(i=0; i<=GetLastIdxBrs(MIn);i++){
      for(j=0; j<=GetLastIdxKol(MIn);j++){
         Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
      }
   }
}

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK){
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
   /*KAMUS*/
   indeks i, j;
   /*ALGORITMA*/
   MakeMATRIKS(NB, NK, M);

   for(i=0; i<=GetLastIdxBrs(*M);i++){
      for(j=0; j<=GetLastIdxKol(*M);j++){
         scanf("%d", &Elmt(*M, i, j)); 
      }
   }
}
void TulisMATRIKS (MATRIKS M){
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
   /*KAMUS*/
   indeks i, j;
   /*ALGORITMA*/
   for(i=0; i<=GetLastIdxBrs(M);i++){
      for(j=0; j<=GetLastIdxKol(M);j++){
         if(j == GetLastIdxKol(M)){
            printf("%d",Elmt(M, i, j)); 
         } else {
            printf("%d ",Elmt(M, i, j)); 
         }
      }
      if(i != GetLastIdxBrs(M)){
         printf("\n");
      }
   }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */ 
   /*KAMUS*/
   indeks i, j;
   MATRIKS MHsl;
   /*ALGORITMA*/
   MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &MHsl);
   
   for(i=0; i<=GetLastIdxBrs(M1);i++){
      for(j=0; j<=GetLastIdxKol(M1);j++){
         Elmt(MHsl, i, j) = Elmt(M1, i, j) + Elmt(M2, i, j);
      }
   }

   return MHsl;
}
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
   /*KAMUS*/
   indeks i, j;
   MATRIKS MHsl;
   /*ALGORITMA*/
   MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &MHsl);

   for(i=0; i<=GetLastIdxBrs(M1);i++){
      for(j=0; j<=GetLastIdxKol(M1);j++){
         Elmt(MHsl, i, j) = Elmt(M1, i, j) - Elmt(M2, i, j);
      }
   }

   return MHsl;
} 
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
   /*KAMUS*/
   indeks i, j, k;
   MATRIKS MHsl;

   /*ALGORITMA*/
   MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &MHsl);

   for(i=0; i<=GetLastIdxBrs(M1);i++){
      for(j=0; j<=GetLastIdxKol(M2);j++){
         Elmt(MHsl, i, j) = 0;
         for(k=0; k<=GetLastIdxBrs(M2);k++){
            Elmt(MHsl, i, j) += Elmt(M1, i, k) * Elmt(M2, k, j);
         }
      }
   }

   return MHsl;
}
MATRIKS KaliKons (MATRIKS M, ElType X){
/* Mengirim hasil perkalian setiap elemen M dengan X */
   /*KAMUS*/
   indeks i, j;
   MATRIKS MHsl;
   /*ALGORITMA*/
   MakeMATRIKS(NBrsEff(M), NKolEff(M), &MHsl);

   for(i=0; i<=GetLastIdxBrs(M);i++){
      for(j=0; j<=GetLastIdxKol(M);j++){
         Elmt(MHsl, i, j) = X * Elmt(M, i, j);
      }
   }

   return MHsl;
}
void PKaliKons (MATRIKS * M, ElType K){
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
   /*KAMUS*/
   indeks i, j;

   /*ALGORITMA*/
   for(i=0; i<=GetLastIdxBrs(*M);i++){
      for(j=0; j<=GetLastIdxKol(*M);j++){
         Elmt(*M, i, j) = K * Elmt(*M, i, j);
      }
   }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
   /*KAMUS*/
   indeks i, j;
   boolean equal=true;
   /*ALGORITMA*/
   if(NBElmt(M1) != NBElmt(M2)){
      return false;
   }

   i = 0;

   while((equal) && i<=GetLastIdxBrs(M1)){
   	  j = 0;
      while((equal) && j<=GetLastIdxKol(M2)){
         if(Elmt(M1,i,j) != Elmt(M2,i,j)){
            equal = false;
         }
         j += 1;
      }
      i += 1;
   }
   
   return equal;
}
boolean NEQ (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika M1 tidak sama dengan M2 */
   /*KAMUS*/
   indeks i, j;
   boolean not_equal = false;
   /*ALGORITMA*/
   if(NBElmt(M1) != NBElmt(M2)){
      return true;
   }

   i = 0;

   while((!not_equal) && i<=GetLastIdxBrs(M1)){
   	  j = 0;
      while((!not_equal) && j<=GetLastIdxKol(M1)){
         if(Elmt(M1,i,j) != Elmt(M2,i,j)){
            not_equal = true;
         }
         j += 1;
      }
      i += 1;
   }
   
   return not_equal;
}
boolean EQSize (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
   return (NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) == NKolEff(M2)) ;
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M){
/* Mengirimkan banyaknya elemen M */
   return (NBrsEff(M) * NKolEff(M));
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M){
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
   return (NBrsEff(M) == NKolEff(M));
}
boolean IsSimetri (MATRIKS M){
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
   /*KAMUS*/
   indeks i, j;
   boolean simetri = true;
   /*ALGORITMA*/
   i = 0;

   while((simetri) && i<=GetLastIdxBrs(M)){
   	  j = 0;
      while((simetri) && j<=GetLastIdxKol(M)){
         if(Elmt(M,i,j) != Elmt(M,j,i)){
            simetri = false;
         }
         j += 1;
      }
      i += 1;
   }
   
   return simetri;
}
boolean IsSatuan (MATRIKS M){
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
   /*KAMUS*/
   indeks i, j;
   boolean satuan = true;
   /*ALGORITMA*/
   if(!IsBujurSangkar(M)){
      return false;
   }

   i = 0;

   while((satuan) && i<=GetLastIdxBrs(M)){
   	  j = 0;
      while((satuan) && j<=GetLastIdxKol(M)){
         if((i == j) && (Elmt(M,i,j) != 1)){
            satuan = false;
         } else if ((i != j) && (Elmt(M,i,j) != 0)){
            satuan = false;
         }
         j += 1;
      }
      i += 1;
   }
   
   return satuan;
}
boolean IsSparse (MATRIKS M){
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
   /*KAMUS*/
   indeks i, j;
   int bukan_nol = 0;
   float sparsity;
   /*ALGORITMA*/
   for(i=0; i<=GetLastIdxBrs(M);i++){
      for(j=0; j<=GetLastIdxKol(M);j++){
         if(Elmt(M, i, j) != 0){
            bukan_nol += 1;
         }
      }
   }

   sparsity = 0.05 * NBElmt(M);

   return bukan_nol <= sparsity;
}
MATRIKS Inverse1 (MATRIKS M){
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
   /*KAMUS*/
   indeks i, j;
   MATRIKS MHsl; 
   /*ALGORITMA*/
   MakeMATRIKS(NBrsEff(M), NKolEff(M), &MHsl);

   for(i=0; i<=GetLastIdxBrs(M);i++){
      for(j=0; j<=GetLastIdxKol(M);j++){
            Elmt(MHsl, i, j) = Elmt(M, i, j) * -1;
         }
      }

   return MHsl;
}
float Determinan (MATRIKS M){
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
    /* KAMUS LOKAL */
   indeks i, j, k, m, n;
   MATRIKS MTemp;
   float det;

   /* ALGORITMA */
   det = 0.0;
   MakeMATRIKS(NBrsEff(M)-1, NKolEff(M)-1, &MTemp);

    /* Basis */
   if (NBrsEff(M) == 2 && NKolEff(M) == 2){
      return ((Elmt(M, 0, 0)*Elmt(M, 1, 1)) - (Elmt(M, 0, 1)*Elmt(M, 1, 0)));
   } else if (NBElmt(M) == 1) {
      return Elmt(M, 0, 0);
   }

   /* Rekursi */
   /* Membuat matriks kofaktor */
   /* Pivot pada baris pertama, yaitu i*/
   for (i = GetFirstIdxKol(M); i <= GetLastIdxKol(M); i++){

      /* Kofaktor matriks, m = baris, n = kolom*/
      m = 0;
      n = 0;

      for(j = GetFirstIdxBrs(M)+1; j <= GetLastIdxBrs(M); j++){
         for (k = GetFirstIdxKol(M); k <= GetLastIdxKol(M); k++){
            if(i==k){
               continue; /* Jika elemen i sama dengan k*/
            }

            Elmt(MTemp, m, n) = Elmt(M, j, k);
            n += 1;

            if (n == GetLastIdxKol(M)){ 
               n = 0;
               m++;
            }
         }
      }
   	 det += pow(-1,i) * Elmt(M, 0, i) * Determinan(MTemp);
   }

   return det;
}
void PInverse1 (MATRIKS * M){
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
   /*KAMUS*/
   indeks i, j;

   /*ALGORITMA*/
   for(i=0; i<=GetLastIdxBrs(*M);i++){
      for(j=0; j<=GetLastIdxKol(*M);j++){
            Elmt(*M, i, j) *= -1;
         }
      }
   }
void Transpose (MATRIKS * M){
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
   /*KAMUS*/
   indeks i, j;
   MATRIKS MHsl;

   /*ALGORITMA*/
   MakeMATRIKS(NBrsEff(*M), NKolEff(*M), &MHsl);

   for(i=0; i<=GetLastIdxBrs(*M);i++){
      for(j=0; j<=GetLastIdxKol(*M);j++){
            Elmt(MHsl, i, j) = Elmt(*M, j, i);
         }
      }

   CopyMATRIKS(MHsl, M);
}
