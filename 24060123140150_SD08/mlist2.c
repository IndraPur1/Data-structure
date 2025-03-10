/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123140150 & Indra Purwanto*/
/* Tanggal : 8 November 2024*/

#include <stdio.h>
#include <stdlib.h>
#include "list2.h"
#include "list2.c"

int main()
{ //kamus
  address A; 
  address B;
  address P;
  List2 Senarai;
  //algoritma
  printf("~LIST2~\n");
  printf("~CREATELIST~\n");
  CreateList(&Senarai);
  printf ("List merupakan list kosong : %d", IsEmptyList(Senarai));
  printf("\n");
  printf("~INSERTVFIRST~");
  InsertVFirst(&Senarai, 'K');
  printf("\n");
  PrintList(Senarai);
  printf("\n");
  printf("~INSERTVLAST~");
  InsertVLast(&Senarai, 'O');
  printf("\n");
  PrintList(Senarai);
  printf("\n");
  printf("~DELETEVFIRST~");
  infotype F;
  DeleteVFirst(&Senarai, &F);
  printf("\n");
  PrintList(Senarai);
  printf("\n");
  printf("~DELETEVLAST~");
  InsertVLast(&Senarai, 'K');
  printf("\n");
  PrintList(Senarai);
  infotype V;
  DeleteVLast(&Senarai, &V);
  printf("\n");
  PrintList(Senarai);
  printf("\n");
  printf("~INVERSLIST~");
  printf("\n");
  InsertVLast(&Senarai, 'K');
  InsertVLast(&Senarai, 'E');
  PrintList(Senarai);
  Invers(&Senarai);
  printf("\n");
  PrintList(Senarai);
  printf("\n");
  printf("~SEARCHX~");
  printf("\n");
  address S;
  SearchX(Senarai, 'E', &S);
  printf ("Alamat dari elemen adalah : %p", S);
  printf("\n");
  printf("~DELETEX~");
  printf("\n");
  DeleteX(&Senarai, 'E');
  PrintList(Senarai);
  printf("\n");
  printf("~UPDATEX~");
  printf("\n");
  InsertVFirst(&Senarai, 'E');
  PrintList(Senarai);
  printf("\n");
  UpdateX(&Senarai, 'E', 'I');
  PrintList(Senarai);
}