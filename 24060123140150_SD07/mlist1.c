/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : 24060123140150 & Indra Purwanto*/
/* Tanggal : 1 November 2024 */
#include <stdio.h>
#include "list1.c"
#include <stdlib.h>
#include "list1.h"
int main()
{ //kamus
  address A; 
  address B;
  address P;
  List1 Senarai;
  //algoritma
  
  //aplikasi tipe address
  // A = (address) malloc ( sizeof (Elm) ); // Alokasi('G')
  // A->info = 'G';   A->next = NIL;
  // printf("info(A)=%c\t", A->info );
  // B = (address) malloc ( sizeof (Elm) ); // Alokasi('N')
  // B->info = 'N';   B->next = A;
  // printf("info(B)=%c\n", B->info );
  
  // //aplikasi tipe List1
  // Senarai.First = B; //First(Senarai) = B;
  // printf("Isi Senarai :");
  // P = First(Senarai);
  // while (P != NIL) {
	//   printf("\t%c",info(P));
	//   P = next(P);
  // }
  // PrintList( Senarai );
  // printf("\n");

  printf("~LIST1~\n");
  printf("~CREATELIST~\n");
  CreateList(&Senarai);
  printf ("List merupakan list kosong : %d", IsEmptyList(Senarai));
  printf("\n");
  printf("~INSERTVFIRST~");
  InsertVFirst(&Senarai, 'K');
  printf("\n");
  PrintList(Senarai);
  InsertVFirst(&Senarai, 'A');
  printf("\n");
  PrintList(Senarai);
  InsertVFirst(&Senarai, 'C');
  printf("\n");
  PrintList(Senarai);
  InsertVFirst(&Senarai, 'O');
  printf("\n");
  PrintList(Senarai);
  InsertVFirst(&Senarai, 'K');
  printf("\n");
  PrintList(Senarai);
  printf("\n");
  printf("~ISEMPTYLIST~");
  printf("\n");
  printf ("List merupakan list kosong : %d", IsEmptyList(Senarai));
  printf("\n");
  printf("~INSERTVLAST~");
  InsertVLast(&Senarai, 'O');
  printf("\n");
  PrintList(Senarai);
  printf("\n");
  printf("~DELETEVLAST~");
  infotype V;
  DeleteVLast(&Senarai, &V);
  printf("\n");
  PrintList(Senarai);
  printf("\n");
  printf("~DELETEVFIRST~");
  InsertVFirst(&Senarai, 'O');
  printf("\n");
  PrintList(Senarai);
  infotype F;
  DeleteVFirst(&Senarai, &F);
  printf("\n");
  PrintList(Senarai);
  printf("\n");
  printf("~INVERSLIST~");
  printf("\n");
  PrintList(Senarai);
  Invers(&Senarai);
  printf("\n");
  PrintList(Senarai);
  printf("\n");
  printf("~UPDATEX~");
  printf("\n");
  PrintList(Senarai);
  UpdateX(&Senarai, 'A', 'O');
  printf("\n");
  PrintList(Senarai);
  printf("\n");
  printf("~JUMLAH ELEMEN DALAM LIST~");
  printf("\n");
  printf("Jumlah elemen : %d", NbElm(Senarai));
  printf("\n");
  printf("~SEARCHX~");
  printf("\n");
  address S;
  SearchX(Senarai, 'O', &S);
  printf ("Alamat dari elemen adalah : %p", S);
  printf("\n");
  printf("~COUNTX~");
  printf("\n");
  printf ("Jumlah elemen O pada list adalah : %d", CountX(Senarai, 'O'));
  printf("\n");
  printf("~FREKUENSI~");
  printf("\n");
  printf ("Frekuensi elemen O pada list adalah : %f", FrekuensiX(Senarai, 'O'));
  printf("\n");
  printf("~SEARCHALLX~");
  printf("\n");
  SearchAllX(Senarai, 'O');
  printf("~UPDDATEALLX~");
  UpdateAllX(&Senarai, 'O', 'A');
  printf("\n");
  PrintList(Senarai);
  printf("\n");
  printf("~INSERTVAFTER~");
  printf("\n");
  PrintList(Senarai);
  InsertVAfter(&Senarai, 'K', 'O');
  printf("\n");
  PrintList(Senarai);
  printf("\n");
  printf("~MAXMEMBER DAN MODUS~");
  printf("\n");
  UpdateX(&Senarai, 'O', 'A');
  PrintList(Senarai);
  printf("\n");
  printf ("elemen paling sering muncul : %d kali", MaxMember(Senarai));
  printf("\n");
  printf("yaitu : %c", Modus(Senarai));
  printf("\n");
  printf("~SPLITLIST~");
  List1 S1;
  List1 S2;
  CreateList(&S1);
  CreateList(&S2);
  SplitList(Senarai, &S1, &S2);
  printf("\n");
  PrintList(S1);
  printf("\n");
  PrintList(S2);
  printf("\n");
  printf("~COPYLIST~");
  List1 S3;
  CreateList(&S3);
  CopyList(Senarai, &S3);
  printf("\n");
  PrintList(S3);
  printf("\n");
  printf("~CONCATLIST~");
  printf("\n");
  PrintList(S1);
  printf("\n");
  PrintList(S2);
  printf("\n");
  List1 S4;
  CreateList(&S4);
  ConcatList(S1, S2, &S4);
  PrintList(S4);
  return 0;
}
