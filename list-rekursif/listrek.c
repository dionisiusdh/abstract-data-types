/* File: listrek.c*/
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listrek.h"

/* *** Manajemen Memori *** */
address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, 
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
	/* KAMUS */
	address P;

	/* ALGORITMA */
	P = (address) malloc(sizeof(ElmtList));

	if (P != Nil) {
		Info(P) = X;
		Next(P) = Nil;
		return P;
	}

	return Nil;
}
void Dealokasi (address P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
	/* KAMUS */

	/* ALGORITMA */
	free(P);
}

/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi List */
int IsEmpty(List L){
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
	/* KAMUS */

	/* ALGORITMA */
	if (L == Nil) {
		return 1;
	}
	return 0;
}
int IsOneElmt(List L){
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */
	/* KAMUS */

	/* ALGORITMA */
	if ((!IsEmpty(L)) && Next(L) == Nil) {
		return 1;
	}
	return 0;
}

/* *** Selektor *** */
infotype FirstElmt (List L){
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
	/* KAMUS */

	/* ALGORITMA */
	return Info(L);
}
List Tail(List L){
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */
	/* KAMUS */
	List L2;

	/* ALGORITMA */
	if (IsOneElmt(L)) {
		return Nil;
	} else {
		L2 = Next(L);
	}
	return L2;
}

/* *** Konstruktor *** */
List Konso(infotype e, List L){
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
	/* KAMUS */
	address P;
	List LHsl;

	/* ALGORITMA */
	P = Alokasi(e);
	if (P != Nil) {
		Next(P) = L;
		LHsl = P;
	} else {
		LHsl = L;
	}
	return LHsl;
}
List KonsB(List L, infotype e){
/* Mengirimkan list L dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 
	/* KAMUS */
	address P;

	/* ALGORITMA */
	if (IsEmpty(L)) {
		P = Alokasi(e);
		if (P != Nil) {
			return P;
		}
		return Nil;
	} else {
		Next(L) = KonsB(Tail(L), e);
		return L;
	}
}

/* *** Operasi Lain *** */
List Copy (List L){
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan L */ 
	/* KAMUS */

	/* ALGORITMA */
	if (IsEmpty(L)) {
		return Nil;
	} else {
		return Konso(FirstElmt(L), Copy(Tail(L)));
	}
}
void MCopy (List Lin, List *Lout){
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
	/* KAMUS */

	/* ALGORITMA */
	*Lout = Copy(Lin);
}
List Concat (List L1, List L2){
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan Nil */
	/* KAMUS */

	/* ALGORITMA */
	if (IsEmpty(L1)) {
		return L2;
	} else if (IsEmpty(L2)) {
		return L1;
	}

	return Konso(FirstElmt(L1), Concat(Tail(L1), L2));
}
void MConcat (List L1, List L2, List *LHsl){
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
	/* KAMUS */

	/* ALGORITMA */
	*LHsl = Concat(L1, L2);
}
void PrintList (List L){
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */
	/* KAMUS */

	/* ALGORITMA */
	if (!IsEmpty(L)) {
		printf("%d\n", FirstElmt(L));
		PrintList(Tail(L));
	}
}
int NbElmtList (List L){
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
	/* KAMUS */
	int n;

	/* ALGORITMA */
	n = 0;
	if (!IsEmpty(L)) {
		n = 1 + NbElmtList(Tail(L));
	}

	return n;
}
boolean Search (List L, infotype X){
/* Mengirim true jika X adalah anggota list, false jika tidak */
	/* KAMUS */

	/* ALGORITMA */
	if (IsEmpty(L)) {
		return false;
	} else {
		if (FirstElmt(L) == X) {
			return true;
		} else {
			return (Search(Tail(L), X));
		}
	}
}

/*** Pencarian nilai ekstrim ***/
/* Prekondisi untuk Max/Min/Sum/Average : List tidak kosong */
infotype MaxList (List L){
/* Mengirimkan nilai info(P) yang maksimum */
	/* KAMUS */
	infotype max, element;

	/* ALGORITMA */
	if (IsOneElmt(L)) {
		return FirstElmt(L);
	}

	max = FirstElmt(L);
	element = MaxList(Tail(L));

	if (element < max) {
		return max;
	} else {
		return element;
	}
}

infotype MinList (List L){
/* Mengirimkan nilai info(P) yang minimum */
	/* KAMUS */
	infotype min, element;

	/* ALGORITMA */
	if (IsOneElmt(L)) {
		return FirstElmt(L);
	}

	min = FirstElmt(L);
	element = MinList(Tail(L));

	if (element > min) {
		return min;
	} else {
		return element;
	}
}

infotype SumList (List L){
/* Mengirimkan total jumlah elemen List L */
	/* KAMUS */
	infotype sum;

	/* ALGORITMA */
	sum = 0;

	if (IsEmpty(L)) {
		// Do nothing
	} else {
		sum = FirstElmt(L) + SumList(Tail(L));
	}
	return sum;
}

float AverageList (List L){
/* Mengirimkan nilai rata-rata elemen list L */
	/* KAMUS */

	/* ALGORITMA */
	return (float) SumList(L) / (float) NbElmtList(L);
}

/*** Operasi-Operasi Lain ***/
List InverseList (List L){
/* Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */
	/* KAMUS */

	/* ALGORITMA */
	if (IsEmpty(L)) {
		return Nil;
	} else {
		return KonsB(InverseList(Tail(L)), FirstElmt(L));
	}
}

void SplitPosNeg (List L, List *L1, List *L2){
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */ 
/* L1 berisi semua elemen L yang positif atau 0, sedangkan L2 berisi
semua elemen L yang negatif; semua dengan urutan yang sama seperti di L */
/* L tidak berubah: Semua elemen L1 dan L2 harus dialokasi */
/* Jika L kosong, maka L1 dan L2 kosong */
	/* KAMUS */
	List LCopy;

	/* ALGORITMA */
	LCopy = Copy(L);
	*L1 = Nil;
	*L2 = Nil;
	
	if (IsEmpty(LCopy)) {
		// Do nothing
	} else {
		SplitPosNeg(Tail(LCopy), L1, L2);
		if (FirstElmt(LCopy) >= 0) {
			*L1 = Konso(FirstElmt(LCopy), *L1);
		} else {
			*L2 = Konso(FirstElmt(LCopy), *L2);
		}
	}
}

void SplitOnX (List L, infotype X, List *L1, List *L2){
/* I.S. L dan X terdefinisi, L1 dan L2 sembarang. */
/* F.S. L1 berisi semua elemen L yang lebih kecil dari X, dengan urutan
kemunculan yang sama, L2 berisi semua elemen L yang tidak masuk ke
L1, dengan urutan kemunculan yang sama. */
	/* KAMUS */

	/* ALGORITMA */
	*L1 = Nil;
	*L2 = Nil;
	
	if (IsEmpty(L)) {
		// Do nothing
	} else {
		SplitOnX(Tail(L), X, L1, L2);
		if (FirstElmt(L) < X) {
			*L1 = Konso(FirstElmt(L), *L1);
		} else {
			*L2 = Konso(FirstElmt(L), *L2);
		}
	}
}

int ListCompare (List L1, List L2){
/* Menghasilkan: -1 jika L1 < L2, 0 jika L1 = L2, dan 1 jika L1 > L2 */
/* Jika L[i] adalah elemen L pada urutan ke-i dan |L| adalah panjang L: */
/* L1 = L2: |L1| = |L2| dan untuk semua i, L1[i] = L2[i] */
/* L1 < L2: Jika i adalah urutan elemen yang berbeda yang terkecil
dari L1 dan L2, L1[i]<L2[i] atau: Jika pada semua elemen pada
urutan i yang sama, L1[i]=L2[i], namun |L1|<|L2| */
/* Contoh: [3,5,6,7] < [4,4,5,6]; [1,2,3]<[1,2,3,4] */
/* L1>L2: kebalikan dari L1<L2 */
	/* KAMUS */

	/* ALGORITMA */
	if (NbElmtList(L1) == NbElmtList(L1)) {
		if (IsEmpty(L1) && IsEmpty(L2)) {
			return 0;
		} else {
			if (FirstElmt(L1) == FirstElmt(L2)) {
				return (ListCompare(Tail(L1), Tail(L2)));
			} else if (FirstElmt(L1) < FirstElmt(L2)) {
				return -1;
			} else {
				return 1;
			}
		}
	} else if (NbElmtList(L1) < NbElmtList(L2)) {
		return -1;
	} else {
		return 1;
	}
}

boolean IsAllExist (List L1, List L2){
/* Menghasilkan true jika semua elemen dalam L1 terdapat dalam L2 (tanpa
memperhatikan urutan ataupun banyaknya elemen).
Kedua list mungkin kosong. Jika L1 kosong, maka hasilnya false. */
	/* KAMUS */

	/* ALGORITMA */
	if (IsEmpty(L1) || IsEmpty(L2)) {
		return false;
	} else {
		if (IsOneElmt(L1) && Search(L2, FirstElmt(L1))) {
			return true;
		} else if (!IsOneElmt(L1) && Search(L2, FirstElmt(L1))) {
			return IsAllExist(Tail(L1), L2);
		} else {
			return false;
		}
	}
}