/* File: bintree.c*/
/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type infotype, type addrNode, dan beberapa fungsi disesuikan 
   karena melibatkan modul list rekursif. */

/* Modul lain yang digunakan : */
#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
#include "listrek.h"
#include "boolean.h"

/* *** Konstruktor *** */
BinTree Tree(infotype Akar, BinTree L, BinTree R) {
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
   /* KAMUS */
   BinTree T;

   /* ALGORITMA */
   T = AlokNode(Akar);
   if (T != Nil) {
      Left(T) = L;
      Right(T) = R;
   }
   return T;
}
void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P){
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokasi berhasil. P = Nil jika alokasi gagal. */
   /* KAMUS */

   /* ALGORITMA */
   *P = Tree(Akar, L, R);
}
BinTree BuildBalanceTree(int n){
/* Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca */
   /* KAMUS */
   infotype X;
   addrNode P;
   BinTree L, R;
   int nL, nR;

   /* ALGORITMA */
   if (n==0) {
      return Nil;
   } else {
      scanf("%d", &X);
      P = AlokNode(X);
      if (P != Nil) {
         nL = n/2;
         nR = n - nL - 1;
         L = BuildBalanceTree(nL);
         R = BuildBalanceTree(nR);
         Left(P) = L;
         Right(P) = R;
      }
      return P;
   }
}

/* Manajemen Memory */
addrNode AlokNode(infotype X){
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
   /* KAMUS */
   addrNode P;

   /* ALGORITMA */
   P = (addrNode) malloc(sizeof(Node));
   if (P != Nil) {
      Akar(P) = X;
      Left(P) = Nil;
      Right(P) = Nil;
   }
   return P;
}
void DealokNode(addrNode P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
   /* KAMUS */

   /* ALGORITMA */
   free(P);
}

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P){
/* Mengirimkan true jika P adalah pohon biner kosong */
   /* KAMUS */

   /* ALGORITMA */
   return P == Nil;
}
boolean IsTreeOneElmt(BinTree P){
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
   /* KAMUS */

   /* ALGORITMA */
   return (P != Nil && Left(P) == Nil && Right(P) == Nil);
}
boolean IsUnerLeft(BinTree P){
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
   /* KAMUS */

   /* ALGORITMA */
   return (P != Nil && Left(P) != Nil && Right(P) == Nil);
}
boolean IsUnerRight(BinTree P){
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
   /* KAMUS */

   /* ALGORITMA */
   return (P != Nil && Left(P) == Nil && Right(P) != Nil);
}
boolean IsBiner(BinTree P){
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
   /* KAMUS */

   /* ALGORITMA */
   return (P != Nil && Left(P) != Nil && Right(P) != Nil);
}

/* *** Traversal *** */
void PrintPreorder(BinTree P){
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
   /* KAMUS */

   /* ALGORITMA */
   if (IsTreeEmpty(P)) {
      printf("()");
   } else {
      printf("(");
      printf("%d", Akar(P));
      PrintPreorder(Left(P));
      PrintPreorder(Right(P));
      printf(")");
   }
}
void PrintInorder(BinTree P){
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
   /* KAMUS */

   /* ALGORITMA */
   if (IsTreeEmpty(P)) {
      printf("()");
   } else {
      printf("(");
      PrintInorder(Left(P));
      printf("%d", Akar(P));
      PrintInorder(Right(P));
      printf(")");
   }
}
void PrintPostorder(BinTree P){
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
   /* KAMUS */

   /* ALGORITMA */
   if (IsTreeEmpty(P)) {
      printf("()");
   } else {
      printf("(");
      PrintPostorder(Left(P));
      PrintPostorder(Right(P));
      printf("%d", Akar(P));
      printf(")");
   }
}
void PrintTree(BinTree P, int h){
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/
   /* KAMUS */
   int i;

   /* ALGORITMA */
   if (IsTreeEmpty(P)) {
      // Do nothing
   } else {
      for (i=1; i<=h; i++) {
         printf(" ");
      }
      printf("%d\n", Akar(P));
      if (Left(P) != Nil) {
         PrintTree(Left(P), h+1);
      } else {
         PrintTree(Right(P), h+1);
      }
   }
}

/* *** Searching *** */
boolean SearchTree(BinTree P, infotype X){
/* Mengirimkan true jika ada node dari P yang bernilai X */
   /* KAMUS */

   /* ALGORITMA */
   if (IsTreeEmpty(P)) {
      return false;
   } else {
      if (Akar(P) == X) {
         return true;
      } else {
         return (SearchTree(Left(P), X) || SearchTree(Right(P), X));
      }
   }
}

/* *** Fungsi-Fungsi Lain *** */
int NbElmt(BinTree P){
/* Mengirimkan banyaknya elemen (node) pohon biner P */
   /* KAMUS */

   /* ALGORITMA */
   if (IsTreeEmpty(P)) {
      return 0;
   } else {
      return (1 + NbElmt(Left(P)) + NbElmt(Right(P)));
   }
}
int NbDaun(BinTree P){
/* Mengirimkan banyaknya daun (node) pohon biner P */
   /* KAMUS */

   /* ALGORITMA */
   if (IsTreeEmpty(P)) {
      return 0;
   } else if (IsTreeOneElmt(P)) {
      return 1;
   } else {
      if (IsUnerLeft(P)) {
         return NbDaun(Left(P));
      } else if (IsUnerRight(P)) {
         return NbDaun(Right(P));
      } else {
         return NbDaun(Left(P)) + NbDaun(Right(P));
      }
   }
}
/* Prekondisi: P tidak kosong */
boolean IsSkewLeft(BinTree P){
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
   /* KAMUS */

   /* ALGORITMA */
   if (IsTreeEmpty(P)) {
      return true;
   } else if (IsTreeOneElmt(P)) {
      return true;
   } else {
      if (IsUnerLeft(P)) {
         return IsSkewLeft(Left(P));
      } else {
         return false;
      }
   } 
}
boolean IsSkewRight(BinTree P){
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
   /* KAMUS */

   /* ALGORITMA */
   if (IsTreeEmpty(P)) {
      return true;
   } else if (IsTreeOneElmt(P)) {
      return true;
   } else {
      if (IsUnerRight(P)) {
         return IsSkewRight(Right(P));
      } else {
         return false;
      }
   } 

}
int Level(BinTree P, infotype X){
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. 
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
   /* KAMUS */

   /* ALGORITMA */
   if (SearchTree(P, X)) {
      if (IsTreeOneElmt(P)) {
         return 1;
      } else {
         return (1 + Level(Left(P), X) + Level(Right(P),X)); 
      }
   } else {
      return 0;
   }
}
int Tinggi(BinTree P){
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */
   /* KAMUS */

   /* ALGORITMA */
   if (IsTreeEmpty(P)) {
      return 0;
   } else {
      if (Tinggi(Left(P)) > Tinggi(Right(P))) {
         return 1 + Tinggi(Left(P));
      } else {
         return 1 + Tinggi(Right(P));
      }
   }
}

/* *** Operasi lain *** */
void AddDaunTerkiri(BinTree *P, infotype X){
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
   /* KAMUS */

   /* ALGORITMA */
   if (IsTreeEmpty(*P)) {
      *P = AlokNode(X);
   } else {
      AddDaunTerkiri(&Left(*P), X);
   }
}
void AddDaun(BinTree *P, infotype X, infotype Y, boolean Kiri){
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau 
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
   /* KAMUS */

   /* ALGORITMA */
   if (IsTreeOneElmt(*P)) {
      if (Kiri) {
         Left(*P) = AlokNode(Y);
      } else {
         Right(*P) = AlokNode(Y);
      }
   } else {
      if (SearchTree(Left(*P), X)) {
         AddDaun(&Left(*P), X, Y, Kiri);
      } else {
         AddDaun(&Right(*P), X, Y, Kiri);
      }
   }
}
void DelDaunTerkiri(BinTree *P, infotype *X){
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula 
        disimpan pada daun terkiri yang dihapus */
      /* KAMUS */
      addrNode P2;

      /* ALGORITMA */
      if (IsTreeOneElmt(*P)) {
         *X = Akar(*P);
         P2 = *P;
         *P = Nil;
         DealokNode(P2);
      } else {
         if (IsUnerRight(*P)) {
            DelDaunTerkiri(&Right(*P), X);
         } else {
            DelDaunTerkiri(&Left(*P), X);
         }
      }
}
void DelDaun(BinTree *P, infotype X){
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */
   /* KAMUS */
   addrNode P2;

   /* ALGORITMA */
   if (IsTreeOneElmt(*P)) {
      if (Akar(*P) == X) {
         P2 = *P;
         *P = Nil;
         DealokNode(P2);
      }
   } else {
      DelDaun(&Left(*P), X);
      DelDaun(&Right(*P), X);
   }
}
List MakeListDaun(BinTree P){
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun pohon P,
   jika semua alokasi list berhasil.
   Daun terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
   /* KAMUS */
   List L;

   /* ALGORITMA */
   if (IsTreeEmpty(P)) {
      return Nil;
   }
   if (IsTreeOneElmt(P)) {
      L = Alokasi(Akar(P));
      return L;
   }
   return Concat(MakeListDaun(Left(P)), MakeListDaun(Right(P)));
}
List MakeListPreorder(BinTree P){
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P 
   dengan urutan preorder, jika semua alokasi berhasil.   
   Menghasilkan list kosong jika ada alokasi yang gagal. */
   /* KAMUS */
   List L;
   
   /* ALGORITMA */
   if (IsTreeEmpty(P)) {
      return Nil;
   } else {
      L = Alokasi(Akar(P));
      if (L != Nil) {
         Next(L) = MakeListPreorder(Left(P));
         return Concat(L, MakeListPreorder(Right(P)));
      }
      return Nil;
   }
}
List MakeListLevel(BinTree P, int N){
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P 
   yang levelnya=N, jika semua alokasi berhasil. 
   Elemen terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
   /* KAMUS */
   List L;
   
   /* ALGORITMA */
   if (IsTreeEmpty(P)) {
      return Nil;
   }
   if (N == 1) {
      L = Alokasi(Akar(P));
      return L;
   }
   return (Concat(MakeListLevel(Left(P), N-1), MakeListLevel(Right(P), N-1)));
}

/* *** Binary  Search  Tree  *** */
boolean BSearch(BinTree P, infotype X){
/* Mengirimkan true jika ada node dari P yang bernilai X */
   /* KAMUS */

   /* ALGORITMA */
   if (IsTreeEmpty(P)) {
      return false;
   } else {
      if (Akar(P) == X) {
         return true;
      } else if (Akar(P) > X) {
         return BSearch(Left(P), X);
      } else {
         return BSearch(Right(P), X);
      }
   }
}

void InsSearch(BinTree *P, infotype X){
/* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. */
   /* KAMUS */

   /* ALGORITMA */
   if (IsTreeEmpty(*P)) {
      MakeTree(X, Nil, Nil, P);
   } else {
      if (X < Akar(*P)) {
         InsSearch(&Left(*P), X); 
      } else {
         InsSearch(&Right(*P), X);
      }
   }
}

void DelBtree(BinTree *P, infotype X){
/* I.S. Pohon P tidak kosong */
/* F.S. Nilai X yang dihapus pasti ada */
/* Sebuah node dengan nilai X dihapus */
   /* KAMUS */
   addrNode P2;

   /* ALGORITMA */
   if (X < Akar(*P)) {
      DelBtree(&Left(*P), X);
   } else if (X > Akar(*P)) {
      DelBtree(&Right(*P), X);
   } else {
      P2 = *P;
      if (IsTreeOneElmt(P2)) {
         *P = Nil;
      } else if (IsUnerLeft(P2)) {
         *P = Left(P2);
      } else if (IsUnerRight(P2)) {
         *P = Right(P2);
      } else {
         while (Right(P2) != Nil) {
            P2 = Right(P2);   
         }
         Akar(*P) = Akar(P2);
         *P = P2;
         P2 = Left(P2);
      }
      DealokNode(P2);
   }
}