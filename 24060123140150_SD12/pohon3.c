/* File : pohon3.c */
/* Deskripsi : realisasi body ADT tree3 berkait dengan representasi fisik pointer */
/* NIM & Nama : Indra Purwanto & 24060123140150*/
/* Tanggal : 09 Desember 2024*/

#include <stdio.h>
#include <stdlib.h>
#include "pohon3.h"
#include "list1.c"

/************************ PROTOTYPE ************************/
/********** PEMBUATAN POHON BARU ***********/
/* function Tree(A:bintree3, X:infotype, V:boolean, kiri:bintree3, kanan:bintree3)-> bintree3
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree3 Tree3 (bintree3 A, infotype X, boolean V, bintree3 kiri, bintree3 kanan){
   // kamus lokal
   bintree3 P;

   // algoritma
   P = (bintree3)malloc(sizeof(node3));
   if(P != NIL){
      parent(P) = A;
      info(P) = X;
      visited(P) = V;
      left(P) = kiri;
      right(P) = kanan;
   }
   return P;
}

/*procedure resetVisited( input/output P : bintree3 )
{I.S: P terdefinisi; F.S: -}
{proses mengubah status visited semua node di P menjadi false}*/
void resetVisited (bintree3 P){
   // kamus lokal

   // algoritma
   if(P != NIL){
      visited(P) = false;
      resetVisited(left(P));
      resetVisited(right(P));
   }
}

/****** SELEKTOR *****/
/* menggunakan macro */

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree3) --> boolean 
   {mengembalikan true bila bintree3 L kosong} */
boolean IsEmptyTree (bintree3 P){
   return P == NIL;
}

/* function IsDaun (P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun (bintree3 P){
   // kamus lokal
   boolean IsEmptyList;

   // algoritma
   return !IsEmptyTree(P) && (left(P) == NIL && right(P) == NIL);
}

/* function IsBiner (P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner (bintree3 P){
   // kamus lokal
   boolean IsEmptyList;
   
   // algoritma
   return !IsEmptyTree(P) && (left(P) != NIL && right(P) != NIL);
}

/* function IsUnerLeft(P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft (bintree3 P){
   // kamus lokal
   boolean IsEmptyList;
   
   // algoritma
   return !IsEmptyTree(P) && (left(P) != NIL && right(P) == NIL);
}

/* function IsUnerRight(P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight (bintree3 P){
   // kamus lokal
   boolean IsEmptyList;
   
   // algoritma
   return !IsEmptyTree(P) && (left(P) == NIL && right(P) != NIL);
}

/*PENELUSURAN*/
/* procedure printDFS( input P:bintree3)
{mencetak node-node P dari elemen terkiri mendalam baru ke kanan} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void printDFS (bintree3 P){
   // kamus lokal

   // algoritma
   if (IsEmptyTree(P)) {
        printf("()");
    } else {
        printf("%c(", info(P));
        printDFS(left(P));
        printf(",");
        printDFS(right(P));
        printf(")");
    }
}

/*procedure printPathX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga node bernilai X }*/
void printPathX (bintree3 P, infotype X){
   // kamus lokal 

   // algoritma 
   if(P != NIL){
   printf("%c ", akar(P));
      if (akar(P) == X) {
         printf("\n");
         return;
      }
      else{
         if (left(P) != NIL) {
            printPathX(left(P), X);
         }
         if (right(P) != NIL) {
            printPathX(right(P), X);
         }
      }
   }
}

/*procedure printPathDaunX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga daun bernilai X }*/
void printPathDaunX(bintree3 P, infotype X) {
   // kamus lokal 

   // algoritma 
   if (P != NIL){
      printf("%c ", akar(P));
      if (akar(P) == X && left(P) == NIL && right(P) == NIL) {
         printf("\n");
         return;
      }
      if (left(P) != NIL) {
         printPathDaunX(left(P), X);
      }
      if (right(P) != NIL) {
         printPathDaunX(right(P), X);
      }
   }
}

/*procedure printAllPaths( input P:bintree3)
{menampilkan semua jalur yang mungkin dari akar P hingga setiap daun}*/
void printAllPaths(bintree3 P) {
   // kamus lokal 
    
   // algoritma 
   if (!IsEmptyTree(P)){
      printf("%c ",info(P));
      if (IsDaun(P)) {
         printf("\n");
      } 
      else {
         printAllPaths(left(P));
         printAllPaths(right(P));
      }
   }
}

/* function NbElm(P:bintree) --> integer
{ menghitung banyaknya elemen bintree P} */
int NbElmTree(bintree3 P){
   // kamus lokal

   // algoritma
   if (IsEmptyTree(P)){
      return 0;
   } else {
      return 1 + NbElmTree(left(P)) + NbElmTree(right(P));
   }
}

/* function NbDaun(P:BinTree)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree3 P) {
   // Kamus Lokal

   // Algoritma
   if (P == NIL) { 
      return 0;
   }
   if (left(P) == NIL && right(P) == NIL) {
      return 1;
   }
   return NbDaun(left(P)) + NbDaun(right(P));
}


/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int max2(int a, int b){
   // kamus lokal

   // algoritma
   if (a > b){
      return a;
   } else {
      return b;
   }
    
}

/* function Tinggi(P:BinTree)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen yaitu 0 }*/
int Tinggi(bintree3 P){
   // kamus lokal

   // algoritma
   if (IsEmptyTree(P)) {
      return -1;
   } else {
      return 1 + max2(Tinggi(left(P)), Tinggi(right(P)));
   }
}

/* function Level(P:bintree3)-> integer
{menghitung tingkat/generasi node pohon P, level akar=1 }*/
int Level (bintree3 P){
   //kamus lokal

   //algoritma
   if(IsEmptyTree(P)){
      return 0;
   }else{
      if(IsDaun(P)){
         return 1;
      }else{
         return 1 + max2(Level(left(P)), Level(right(P)));
      }
   }
}

/*function CountLevelT(P:bintree3, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT(bintree3 P, int T){
   // kamus lokal

   // algoritma
   if (IsEmptyTree(P) || T < 0){
      return 0;
   } else {
      if (T == 1){
         return 1;
      } else {
         CountLevelT(left(P), T-1) + CountLevelT(right(P), T-1);
      }  
   }
}

/* procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N} */
void PrintLevel(bintree3 P, int N) {
   // Kamus lokal

   // Algoritma
   if (!IsEmptyTree(P)) {  
      if (N == 1) { 
         printf("%c ", info(P));  
      } else {  
         PrintLevel(left(P), N - 1);  
         PrintLevel(right(P), N - 1);  
      }
   }
}

/* procedure PrintBFS( input P:bintree3)
{mencetak node-node P dari generasi paling terkecil ke terbesar}*/
/*contoh: A B C D */
void PrintBFS(bintree3 P) {
   // Kamus lokal
   int i, level;

   // Algoritma
   if (IsEmptyTree(P)) {
      printf("Pohon Kosong");
   } else {
      level = Level(P); 
      for (i = 1; i <= level; i++) { 
         PrintLevel(P, i); 
      }
   }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*** operator khusus LIST1 ***/
//printList sudah ADA di list1.h

/*procedure Pconcat( input/output Asli:list1, input Tambahan:list1) */
/*{I.S:- ; F.S: list Asli berubah karena disambung list Tambahan}*/
/*{menyambung list Tambahan ke belakang list Asli}*/
void pconcat(List1 *Asli, List1 Tambahan) {
   // kamus lokal
   address Last;

   // algoritma
   if (IsEmptyList(*Asli)) {
      First(*Asli) = First(Tambahan);
   } else {
      Last = First(*Asli);
      while (next(Last) != NIL) {
         Last = next(Last);
      }
      next(Last) = First(Tambahan);
   }
}


/*function fconcat( Asli:list1, Tambahan:list1) -> list1 */
/*{membentuk list Baru hasil penyambungan list Tambahan ke belakang list Asli}*/
/*{periksa dampaknya, list Asli tidak boleh berubah }*/
List1 Fconcat (List1 Asli, List1 Tambahan){
   //kamus lokal
   List1 Listconcat;
   address A;
   address Last;

   //algoritma
   CreateList(&Listconcat);
   if (!IsEmptyList(Asli)){
      A = First(Asli);
      while (A != NIL){
         InsertVLast(&Listconcat, info(A));
            A = next(A);
      }  
   }
   if (!IsEmptyList(Tambahan)){
      A = First(Tambahan);
      while (A != NIL){
         InsertVLast(&Listconcat, info(A));
         A = next(A);
      }  
   }return Listconcat;
}

/*** LINEARISASI POHON ***/
/*function linearPrefix(P:bintree3) -> list1
{menghasilkan list node dari P terurut prefix akar,kiri,kanan}*/
List1 LinearPrefix(bintree3 P) {
   // Kamus lokal
   List1 A;

   // Algoritma
   CreateList(&A); 

   if (!IsEmptyTree(P)) {
      InsertVLast(&A, info(P)); 
      List1 LeftList = LinearPrefix(left(P));  
      List1 RightList = LinearPrefix(right(P)); 
      pconcat(&A, LeftList);  
      pconcat(&A, RightList);  
   }
   return A;
}


/*function linearPosfix(P:bintree3) -> list1
{menghasilkan list node dari P terurut posfix kiri,kanan,akar}*/
List1 LinearPosfix(bintree3 P) {
   // Kamus lokal
   List1 A;

   // Algoritma
   CreateList(&A);  
   if (!IsEmptyTree(P)) {
      List1 LeftList = LinearPosfix(left(P)); 
      List1 RightList = LinearPosfix(right(P)); 
      pconcat(&A, LeftList);   
      pconcat(&A, RightList);  
      InsertVLast(&A, info(P)); 
   }
   return A; 
}

/*function linearInfix(P:bintree3) -> list1
{menghasilkan list node dari P terurut infix kiri,akar,kanan}*/
List1 LinearInfix(bintree3 P) {
   // Kamus lokal
   List1 A;

   // Algoritma
   CreateList(&A);  
   if (!IsEmptyTree(P)) {
      List1 LeftList = LinearInfix(left(P)); 
      InsertVLast(&A, info(P)); 
      List1 RightList = LinearInfix(right(P)); 
      pconcat(&A, LeftList);  
      pconcat(&A, RightList);  
   }
   return A; 
}

/*function linearBreadthFS(P:bintree3) -> list1
{menghasilkan list node dari P terurut level/tingkat}*/
List1 LinearBreadthFS(bintree3 P) {
   // Kamus Lokal
   List1 A; 
   int level, i;

   // Algoritma
   CreateList(&A);
   if (!IsEmptyTree(P)) {
      level = Level(P);
      for (i = 1; i <= level; i++) {
         if (!IsEmptyTree(P)) {
            if (i == 1) {
               InsertVLast(&A, info(P));
            } else {
               List1 LeftList = LinearBreadthFS(left(P));
               List1 RightList = LinearBreadthFS(right(P));
               pconcat(&A, LeftList);
               pconcat(&A, RightList);
            }
         }
      }
   }
   return A;
}