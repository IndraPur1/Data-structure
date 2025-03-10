/* File : list3.h */
/* Deskripsi : aplikasi driver ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : Indra Purwanto & 24060123140150*/
/* Tanggal : 15 November 2024*/

#include <stdio.h>
#include <stdlib.h>
#include "list3.h"
#include "list3.c"

int main(){
    //kamus
    address P;
    List3 Senarai;
    printf("~LIST3~\n");

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
    printf("elemen yang dibuang = %c", V);
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
    printf("elemen yang dibuang = %c", V);
    printf("\n");

    printf("~DELETEX~");
    printf("\n");
    printf("menghapus elemen K");
    DeleteX(&Senarai, 'K');
    printf("\n");
    PrintList(Senarai);
    printf("\n");
    InsertVFirst(&Senarai, 'P');

    printf("~SEARCHX~");
    address U;
    SearchX(Senarai, 'A',&U);
    printf("\n");
    printf("elemen A ditemukan pada alamat %p", U);
    printf("\n");
    PrintList(Senarai);
    printf("\n");
    
    printf("~UPDATEX~");
    printf("\n");
    PrintList(Senarai);
    UpdateX(&Senarai, 'P', 'Q');
    printf("\n");
    PrintList(Senarai);
    printf("\n");

    printf("~INVERSX~");
    printf("\n");
    PrintList(Senarai);
    Invers(&Senarai);
    printf("\n");
    PrintList(Senarai);
    printf("\n");

    printf("~INSERTVAFTERX~");
    printf("\n");
    PrintList(Senarai);
    InsertVAfterX(&Senarai, 'A', 'U');
    printf("\n");
    PrintList(Senarai);
    printf("\n");

    printf("~INSERTVBEFOREX~");
    printf("\n");
    PrintList(Senarai);
    InsertVBeforeX(&Senarai, 'Q', 'U');
    printf("\n");
    PrintList(Senarai);
    printf("\n");

    printf("~DELETEAFTERX~");
    printf("\n");
    infotype A;
    PrintList(Senarai);
    DeleteVAfterX(&Senarai, 'A', &A);
    printf("\n");
    printf("elemen setelah A yaitu %c akan dihapus", A);
    printf("\n");
    PrintList(Senarai);
    printf("\n");

    printf("~DELETEBEFOREX~");
    printf("\n");
    infotype B;
    PrintList(Senarai);
    DeleteVBeforeX(&Senarai, 'Q', &B);
    printf("\n");
    printf("elemen sebelum Q yaitu %c akan dihapus", B);
    printf("\n");
    PrintList(Senarai);
    printf("\n");

    printf("~COUNTX~");
    printf("\n");
    InsertVFirst(&Senarai, 'Q');
    PrintList(Senarai);
    printf("\n");
    printf ("Jumlah elemen Q pada list adalah : %d", CountX(Senarai, 'Q'));
    printf("\n");

    printf("~FREKUENSIX~");
    printf("\n");
    PrintList(Senarai);
    printf("\n");
    printf ("Frekuensi elemen Q pada list adalah : %f", FrekuensiX(Senarai, 'Q'));
    printf("\n");

    printf("~MAXMEMBER~");
    printf("\n");
    PrintList(Senarai);
    printf("\n");
    printf ("banyaknya elemen paling banyak muncul pada list adalah : %d", MaxMember(Senarai));
    printf("\n");

    printf("~MODUS~");
    printf("\n");
    PrintList(Senarai);
    printf("\n");
    printf ("elemen paling banyak muncul pada list adalah : %c", Modus(Senarai));
    printf("\n");

    printf("~COUNTVOCAL~");
    printf("\n");
    PrintList(Senarai);
    printf("\n");
    printf ("jumlah elemen vocal pada list adalah : %d", CountVocal(Senarai));
    printf("\n");

    printf("~COUNTNG~");
    printf("\n");
    InsertVLast(&Senarai, 'N');
    InsertVLast(&Senarai, 'G');
    PrintList(Senarai);
    printf("\n");
    printf ("jumlah elemen N sebelum G pada list adalah : %d", CountNG(Senarai));
    printf("\n");

    printf("~SEARCALLX~");
    printf("\n");
    PrintList(Senarai);
    printf("\n");
    SearchAllX(Senarai,'Q');

    printf("~DELETEALLX~");
    printf("\n");
    PrintList(Senarai);
    printf("\n");
    printf("semua elemen Q dihapus menjadi");
    printf("\n");
    DeleteAllX(&Senarai,'Q');
    PrintList(Senarai);
    printf("\n");

    printf("~SPLITLIST~");
    printf("\n");
    PrintList(Senarai);
    List3 sena;
    List3 rai;
    SplitList(Senarai, &sena, &rai);
    printf("\n");
    PrintList(sena);
    printf("\n");
    PrintList(rai);
    printf("\n");

    printf("~CONCATLIST~");
    printf("\n");
    List3 L1;
    PrintList(sena);
    printf("\n");
    PrintList(rai);
    printf("\n");
    ConcatList(sena, rai, &L1);
    PrintList(L1);
    printf("\n");

    printf("~COPYLIST~");
    printf("\n");
    PrintList(Senarai);
    printf("\n");
    List3 Senarai2;
    CopyList(Senarai, &Senarai2);
    PrintList(Senarai2);
}