/* File : pohon1t3.c */
/* Deskripsi : realisasi body ADT tree1 berkait dengan representasi fisik pointer */
/* NIM & Nama : Indra Purwanto & 24060123140150*/
/* Tanggal : 22 November 2024*/

#include <stdio.h>
#include <stdlib.h>
#include "pohon1.h"

/* DEFINISI bintree kosong = NIL = ( ) */

/************************ PROTOTYPE ************************/
/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* function Alokasi( E: infotype)-> bintree */
/* {menghasilkan alokasi memori pohon dengan info=E, left=NIL, right=NIL  } */
bintree Alokasi(infotype E){ //representasi fisik fungsi
    // Alokasi memori untuk node baru
    bintree P = (bintree)malloc(sizeof(node));

    // Jika alokasi berhasil
    if (P != NULL) {
        // Inisialisasi node dengan info = E dan left & right = NIL
        akar(P) = E;
        left(P) = NIL;
        right(P) = NIL;
    }
    
    return P;
}
/* procedure Dealokasi (input/output P:bintree) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian bintree P} */
void Dealokasi (bintree *P){
    if(P != NIL){
        left(*P) = NIL;
        right(*P) = NIL;
    }
    free(*P);
    *P = NIL;
}

/********** PEMBUATAN bintree KOSONG ***********/
/* function Tree(Akar:infotype, Left:BinTree, Right:BinTree)-> BinTree
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree Tree (infotype akar, bintree left, bintree right){
    // kamus lokal
    bintree T;

    // algoritma
    T = Alokasi(akar);
    if(T != NIL){
    left(T) = left;
    right(T) = right;
    }
    return T;
}

/****** SELEKTOR *****/
/*function GetAkar (P : BinTree) -> infotype
{ Mengirimkan nilai Akar pohon biner P }*/
infotype GetAkar(bintree P){
    if(P != NIL){
        return info(P);
    }
}

/*function GetLeft (P : BinTree) -> BinTree
{ Mengirimkan Anak Kiri pohon biner P }*/
bintree GetLeft(bintree P){
    if(P != NIL){
        return left(P);
    }
}

/*function GetRight (P : BinTree) -> BinTree
{ Mengirimkan Anak Kanan pohon biner P }*/
bintree GetRight(bintree P){
    if(P != NIL){
        return right(P);
    }
}

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree) --> boolean 
   {mengembalikan true bila bintree L kosong} */
boolean IsEmptyTree (bintree P){
    return P == NIL;
}

/* function IsDaun (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree P){
    // algoritma
    if(!IsEmptyTree(P)){
        return left(P) == NIL && right(P) == NIL;
    } else{
        return false;
    }
}

/* function IsBiner (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree P){
    // algoritma
    if(!IsEmptyTree(P)){
        return (P != NIL) && (left(P) != NIL) && (right(P) != NIL);
    } else{
        return false;
    }
}

/* function IsUnerLeft(P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree P){
    // algoritma
    if(!IsEmptyTree(P)){
        return left(P) != NIL && right(P) == NIL;
    } else{
        return false;
    }
}

/* function IsUnerRight(P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree P){
    // algoritma
    if(!IsEmptyTree(P)){
        return left(P) == NIL && right(P) != NIL;
    } else{
        return false;
    }    
}

/*PENELUSURAN*/
/* procedure PrintPrefix(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier lengkap} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void PrintPrefix(bintree P){
    // algoritma
    if (IsEmptyTree(P)) {
        printf("()");
    } else {
        printf("(");
        printf("%c", GetAkar(P));
        printf("(");
        PrintPrefix(GetLeft(P));
        printf(",");
        PrintPrefix(GetRight(P));
        printf(")");
        printf(")");
    }
}

/* function NbElm(P:bintree) --> integer
{ menghitung banyaknya elemen bintree P} */
int NbElm(bintree P){
    if (IsEmptyTree(P)){
        return 0 ;
    }else{
        return 1 + NbElm(right(P)) + NbElm(left(P));
    }
}

/* function NbDaun(P:BinTree)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree P){
    //algoritma
    if (IsEmptyTree(P)){
        return 0;
    }else if (IsDaun(P)){
        return 1;
    }else{
        return NbDaun(right(P)) + NbDaun(left(P));
    }
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int max2(int a, int b){
    // algoritma
    if(a > b){
        return a;
    } else{
        return b;
    }
}

/* function Tinggi(P:BinTree)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen yaitu 0 }*/
int Tinggi(bintree P){
    // kamus lokal
    int high;
    // algoritma
    high = 0;
    if(IsEmptyTree(P)){
        return high = -1;
    } else{
        return high = 1 + max2(Tinggi(GetLeft(P)), Tinggi(GetRight(P)));
    }
}

/******* PENAMBAHAN ELEMEN bintree ********/

/******* PENGHAPUSAN ELEMEN ********/

/*** PENCARIAN ***/
/*function SearchX(P:BinTree, X:infotype) -> boolean 
{ Mengirimkan true jika ada node dari P yang bernilai X }*/
boolean SearchX(bintree P, infotype X){
    // algoritma
    if(IsEmptyTree(P)){
        return false;
    } else if(GetAkar(P) == X){
        return true;
    } else{
        SearchX(GetLeft(P), X) || SearchX(GetRight(P), X);
    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(bintree *P, infotype X, infotype Y){
    // algoritma
    if(!IsEmptyTree(*P)){
        if(GetAkar(*P) == X){
            akar(*P) = Y;
        } else{
            UpdateX(&left(*P), X, Y);
            UpdateX(&right(*P), X, Y);
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(P:BinTree, X:infotype) -> integer 
{ Mengirimkan banyaknya node dari P yang bernilai X }*/
int CountX(bintree P, infotype X){
    // kamus lokal
    int count;
    // algoritma
    count = 0;
    if(!IsEmptyTree(P)){
        if(GetAkar(P) == X){
            count = 1 + CountX(left(P), X) + CountX(right(P), X) ;
        } else{
           count =  CountX(left(P), X) + CountX(right(P), X);
        }
    }
    return count;
}

/*function IsSkewLeft (P : BinTree)-> boolean 
{ Mengirim true jika P adalah pohon condong kiri } */
boolean IsSkewLeft (bintree P){
    // algoritma
    if (IsEmptyTree(P)){
        return true;
    } else if (IsDaun(P)){
        return true;
    } else if(IsUnerLeft(P)){
        return IsSkewLeft(GetLeft(P));
    } else{
        return false;
    }
}

/*function IsSkewRight (P : BinTree) -> boolean
{ Mengirim true jika P adalah pohon condong kanan }*/
boolean IsSkewRight (bintree P){
    // algortima
    if (IsEmptyTree(P)){
        return true;
    } else if(IsDaun(P)){
        return true;
    } else if(IsUnerRight(P)){
        return IsSkewLeft(GetRight(P));
    } else{
        return false;
    }
}

/* procedure PrintPrefix(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier ringkas} */
/*contoh: A(B(( ),D),C)*/
void PrintSurfix(bintree P){
    // algritma
    if(!IsEmptyTree(P)){
        printf("%c", info(P));
        if ((left(P) != NIL) || (right(P) != NIL)){
            printf("(");
            PrintSurfix(GetLeft(P));
            printf(",");
            PrintSurfix(GetRight(P));
            printf(")");
        }
    } else{
        printf("()");
    }
}

/*function LevelX(P:BinTree, X:infotype)-> integer
{ Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }*/
int LevelX(bintree P, infotype X){
    // algoritma
    if(IsEmptyTree(P)){
        return 0;
    } else if(info(P) == X){
        return 1;
    } else{
        if ((LevelX(left(P), X)) != 0) {
            return 1 + (LevelX(left(P), X));
        } else if ((LevelX(right(P), X)) != 0) {
            return 1 + (LevelX(right(P), X)) ;
        } else {
            return 0;
        }
    }
}

/*function CountLevelT(P:BinTree, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. akar(P) level 0 }*/
int CountLevelT(bintree P, int T){
    // algoritma
    // Basis: pohon kosong
    if (IsEmptyTree(P)) {
        return 0;
    }else if (T == 0) {
        return 1;
    } else{
        return  1 + CountLevelT(GetLeft(P), T-1) + CountLevelT(GetRight(P), T-1);
    }
}

/*function GetDaunTerkiri(bintree P)-> infotype 
{mengembalikan nilai info daun terkiri, bila tidak ada, hasilnya '#' }*/
infotype GetDaunTerkiri(bintree P){
    // algoritma
    if (IsEmptyTree(P)){
        return '#';
    } else if (IsDaun(P)){
        return info(P);
    } else{
        GetDaunTerkiri(GetLeft(P));
    }
}

/*function FrekuensiX(L:bintree, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran bintree L }*/
float FrekuensiX(bintree P, infotype X){
    return (float) CountX(P, X) / NbElm(P);
}

/*function CountVocal(L:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam bintree L}*/
int CountVocal(bintree L){
    // kamus lokal
    int count;
    // algoritma
    count = 0;
    if(!IsEmptyTree(L)){
        if((GetAkar(L) == 'A') || (GetAkar(L) == 'I') || (GetAkar(L) == 'U') || (GetAkar(L) == 'E') || (GetAkar(L) == '0')){
            count = 1 + CountVocal(left(L)) + CountVocal(right(L));
        } else{
            count = CountVocal(left(L)) + CountVocal(right(L));
        }
    }
    return count;
}

/*function Modus(L:bintree) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam bintree L}*/
char Modus(bintree P){
    // kamus lokal
    char modus;
    char huruf;
    int max;
    int count;

    // algoritma
    if (IsEmptyTree(P)){
        return '#';
    } else{
        max = 0;
        for(huruf = 'A'; huruf <= 'Z'; huruf++){
            count = (CountX(P, huruf));
            if(count > max){
                max = count;
                modus = huruf;
            }
        }
    }
    return modus;
}
