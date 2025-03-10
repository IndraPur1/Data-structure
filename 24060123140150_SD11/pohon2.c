#include <stdio.h>
#include <stdlib.h>
#include "pohon2.h"
#include "pohon1.c"

/*PENELUSURAN*/
/* procedure PrintTreeInden (input P : BinTree, input H : integer)
{ I.S. P terdefinisi, h adalah jarak indentasi subpohon }
{ F.S. Semua simpul P ditulis dengan indentasi berjenjang,mirip file explorer} */
void PrintTreeInden(bintree P, int H ){
    //KAMUS LOKAL

    //ALGORITMA
    if (P != NIL) {
        for (int i = 0; i < H; i++) {
            printf("  ");  // Memberikan indentasi
        }
        printf("%c\n", akar(P));
        PrintTreeInden(left(P), H + 1);  // Menelusuri subpohon kiri
        PrintTreeInden(right(P), H + 1);  // Menelusuri subpohon kanan
    }
}

/* procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N} */
void PrintLevel(bintree P, int N){
    //KAMUS LOKAL
    
    //ALGORITMA
    if (P != NIL) {
        if (N == 1) {
            printf("%c ", akar(P));  // Menampilkan info simpul pada level N
        } else {
            PrintLevel(left(P), N - 1);  // Menelusuri subpohon kiri
            PrintLevel(right(P), N - 1);  // Menelusuri subpohon kanan
        }
    }
}

/*KONSTRUKTOR*/
/*function BuildBalanceTree (n : integer) -> BinTree
{ Menghasilkan balanced tree dengan n node, nilai setiap node dibaca dari keyboard }*/
bintree BuildBalanceTree(int n){
   //KAMUS LOKAL
    bintree P;
    int leftSize, rightSize;
    //ALGORITMA
    if (n == 0) return NIL;
    P = (bintree)malloc(sizeof(node));
    printf("Masukkan nilai untuk node: ");
    scanf(" %c", &(info(P)));
    leftSize = (n - 1) / 2;
    rightSize = n - 1 - leftSize;
    left(P) = BuildBalanceTree(leftSize);
    right(P) = BuildBalanceTree(rightSize);

    return P;
}

/*PREDIKAT*/
/*function IsBalanceTree (P : BinTree) -> boolean
{ Menghasilkan true jika P seimbang, banyak node kiri ~= kanan }*/
boolean IsBalanceTree(bintree P){
    //KAMUS LOKAL
    int leftHeight, rightHeight;
    //ALGORITMA
    if (P == NULL) {
        return true;
    }
    leftHeight = 0;
    rightHeight = 0;
    if (left(P) != NULL) {
        if (!IsBalanceTree(left(P))) {
            return false;
        }
        leftHeight = Tinggi(left(P));
    }
    if (right(P) != NULL) {
        if (!IsBalanceTree(right(P))) {
            return false;
        }
        rightHeight = Tinggi(right(P));
    }
    if (abs(leftHeight - rightHeight) > 1) {
        return false;
    }
    return true;
}

/******* PENAMBAHAN ELEMEN bintree ********/
/*procedure AddDaunTerkiri (input/output P : BinTree, input X : infotype)
{ I.S. P boleh kosong }
{ F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri }*/
void AddDaunTerkiri(bintree P, infotype X){
    //KAMUS LOKAL
    
    //ALGORITMA
    if (P != NIL) {
        if (left(P) == NIL && right(P) == NIL) {
            left(P) = Alokasi(X);  // Menambahkan daun terkiri
        } else {
            AddDaunTerkiri(left(P), X);  // Rekursif ke subpohon kiri
        }
    }
}

/*procedure AddDaun (input/Output P : BinTree, input X, Y : infotype, input Kiri : boolean)
{ I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P }
{ F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau sebagai anak Kanan X (jika not Kiri) }*/
void AddDaun(bintree P, infotype X, infotype Y, boolean Kiri){
    //KAMUS LOKAL
    
    //ALGORITMA
    if (P != NIL) {
        if (akar(P) == X) {
            if (Kiri) {
                left(P) = Alokasi(Y);  // Menambah daun kiri
            } else {
                right(P) = Alokasi(Y);  // Menambah daun kanan
            }
        } else {
            AddDaun(left(P), X, Y, Kiri);  // Rekursif ke subpohon kiri
            AddDaun(right(P), X, Y, Kiri);  // Rekursif ke subpohon kanan
        }
    }
}

/*procedure InsertX (input/output P : BinTree, input X : infotype)
{ Menghasilkan sebuah pohon P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
void InsertX(bintree *P, infotype X){
    //KAMUS LOKAL
    
    //ALGORITMA
    if (*P == NIL) {
        *P = Alokasi(X);  // Jika pohon kosong, buat simpul baru
    } else {
        if (X < akar(*P)) {
            InsertX(&left(*P), X);  // Sisipkan ke kiri
        } else {
            InsertX(&right(*P), X);  // Sisipkan ke kanan
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*procedure DelDaunTerkiri (input/output P : BinTree, output X : infotype)
{ I.S. P tidak kosong }
{ F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang
semula disimpan pada daun terkiri yang dihapus }*/
void DelDaunTerkiri(bintree *P, infotype *X){
    //KAMUS LOKAL
    
    //ALGORITMA
    if (*P != NIL) {
        if (left(*P) == NIL && right(*P) == NIL) {
            *X = akar(*P);
            Dealokasi(P);  // Menghapus daun terkiri
        } else {
            DelDaunTerkiri(&left(*P), X);  // Rekursif ke subpohon kiri
        }
    }
}

/*procedure DelDaun (input/output P : BinTree, input X : infotype)
{ I.S. P tidak kosong, X adalah salah satu daun }
{ F.S. X dihapus dari P }*/
void DelDaun(bintree *P, infotype X){
    //KAMUS LOKAL
    
    //ALGORITMA
    if (*P != NIL) {
        if (akar(*P) == X && left(*P) == NIL && right(*P) == NIL) {
            Dealokasi(P);  // Menghapus daun yang ditemukan
        } else {
            DelDaun(&left(*P), X);  // Rekursif ke subpohon kiri
            DelDaun(&right(*P), X);  // Rekursif ke subpohon kanan
        }
    }
}

/*procedure DeleteX (input/output P : BinTree, input X : infotype)
{ Menghapus simpul bernilai X bila ada dari P, HATI-HATI! }*/
void DeleteX(bintree *P, infotype X){
    //KAMUS LOKAL
    bintree temp;
    //ALGORITMA
    if (*P != NIL) {
        if (akar(*P) == X) {
            if (left(*P) == NIL && right(*P) == NIL) {
                Dealokasi(P);  // Daun, hapus langsung
            } else if (left(*P) != NIL && right(*P) == NIL) {
                temp = left(*P);
                *P = temp;
            } else if (left(*P) == NIL && right(*P) != NIL) {
                temp = right(*P);
                *P = temp;
            } else {
                // Jika dua anak, carilah pengganti yang tepat
                temp = left(*P);
                while (right(temp) != NIL) temp = right(temp);
                akar(*P) = akar(temp);  // Ganti info
                DeleteX(&left(*P), akar(*P));  // Hapus pengganti
            }
        } else {
            DeleteX(&left(*P), X);  // Rekursif ke subpohon kiri
            DeleteX(&right(*P), X);  // Rekursif ke subpohon kanan
        }
    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateAllX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y. Mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(bintree *P, infotype X, infotype Y){
    //KAMUS LOKAL
    
    //ALGORITMA
    if (*P != NIL) {
        if (akar(*P) == X) {
            akar(*P) = Y;  // Update nilai X dengan Y
        }
        UpdateAllX(&left(*P), X, Y);  // Rekursif ke kiri
        UpdateAllX(&right(*P), X, Y);  // Rekursif ke kanan
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/* function maxTree(P:bintree)->character
{mengembalikan huruf "maksimal" dari elemen P, A<B<C<..<Z }*/
int maxTree(bintree P){
    //KAMUS LOKAL
    int maxLeft, maxRight;
    //ALGORITMA
    if (P == NIL) return 'A';  // Pohon kosong, nilai minimal
    maxLeft = maxTree(left(P));
    maxRight = maxTree(right(P));
    return (akar(P) > maxLeft ? (akar(P) > maxRight ? akar(P) : maxRight) : (maxLeft > maxRight ? maxLeft : maxRight));
}

/* function minTree(P:bintree)->character
{mengembalikan huruf "minimal" dari elemen P, A<B<C<..<Z }*/
int minTree(bintree P){
    //KAMUS LOKAL
    int minLeft, minRight;
    //ALGORITMA
    if (P == NIL) return 'Z';  // Pohon kosong, nilai maksimal
    minLeft = minTree(left(P));
    minRight = minTree(right(P));
    return (akar(P) < minLeft ? (akar(P) < minRight ? akar(P) : minRight) : (minLeft < minRight ? minLeft : minRight));
}

/*{ Operator KHUSUS Binary Search Tree, node kiri selalu lebih kecil daripada node kanan }

/*function BSearch (P : BinTree, X : infotype) → boolean
{ Mengirimkan true jika ada node dari pohon binary search P yang bernilai X }*/
boolean BSearch(bintree P, infotype X){
    //KAMUS LOKAL
    
    //ALGORITMA
    if (P == NIL) return false;
    if (akar(P) == X) return true;
    if (X < akar(P)) return BSearch(left(P), X);
    return BSearch(right(P), X);
}

/*function InsSearch (P : BinTree, X : infotype) → BinTree
{ Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
bintree InsSearch(bintree P, infotype X){
    //KAMUS LOKAL
    
    //ALGORITMA
    if (P == NIL) {
        return Alokasi(X);
    }
    if (X < akar(P)) {
        left(P) = InsSearch(left(P), X);
    } else {
        right(P) = InsSearch(right(P), X);
    }
    return P;
}

/*procedure DelBtree (input/output P : BinTree, input X : infotype)
{ I.S. Pohon binary search P tidak kosong }
{ F.S. Nilai X yang dihapus pasti ada }
{ Sebuah node dg nilai X dihapus }*/
void DelBtree(bintree *P, infotype X){
    //KAMUS LOKAL
    bintree temp, min;
    //ALGORITMA
    if (*P != NIL) {
        if (akar(*P) == X) {
            temp;
            if (left(*P) == NIL) {
                temp = *P;
                *P = right(*P);
                Dealokasi(&temp);
            } else if (right(*P) == NIL) {
                temp = *P;
                *P = left(*P);
                Dealokasi(&temp);
            } else {
                min = left(*P);
                while (right(min) != NIL) min = right(min);
                akar(*P) = akar(min);
                DelBtree(&left(*P), akar(*P));
            }
        } else if (X < akar(*P)) {
            DelBtree(&left(*P), X);
        } else {
            DelBtree(&right(*P), X);
        }
    }
}