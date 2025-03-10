/* Program   : mtqueue2.C */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model II: head bergeser/jelajah */
/* NIM/Nama  : 24060123140150 / Indra Purwanto*/
/* Tanggal   : 4 Oktober 2024*/
/***********************************/

#include <stdio.h>
#include "tqueue2.h"
#include "tqueue2.c"
#include "boolean.h"

int main ( )
{
    //Kamus Main 
    tqueue2 A;
    tqueue2 B;
    tqueue2 C;
    char temp;
    int n;
    //Algoritma
    printf ("~CREATEQUEUE2~\n");
    createQueue2(&A);
    printf ("~PRINTQUEUE2~\n");
    printQueue2(A);
    printf("\n");
    printf ("Panjang antrian : %d\n", sizeQueue2(A));
    printf("\n");
    printf ("~VIEWQUEUE2~\n");
    printf ("~ISEMPTYQUEUE2~\n");
    printf ("Queue merupakan queue kosong : %d\n", isEmptyQueue2(A));
    printf ("FULLQUEUE2~\n");
    printf ("Queue merupakan queue penuh : %d\n", isFullQueue2(A));
    printf ("~ISONEELEMNT2~\n");
    printf ("Queue hanya memiliki satu elemen : %d\n", isOneElement2(A));
    printf ("~HEAD2~\n");
    printf ("Posisi elemen terdepan merupakan : %d\n", head2(A));
    printf ("~TAIL2~\n");
    printf ("Posisi elemen paling akhir merupakan : %d\n", head2(A));
    printf ("~ENQUEUE2~\n");
    enqueue2(&A, 'B');
    printQueue2(A);
    printf("\n");
    printf ("~INFOHEAD2~\n");
    printf ("Elemen di head adalah : %c\n", infoHead2(A));
    printf ("~INFOTAIL2~\n");
    printf ("Elemen di tail adalah : %c\n", infoTail2(A));
    printf ("~DEQUEUE2~\n");
    dequeue2(&A, &temp);
    printQueue2(A);
    printf("\n");
    printf ("Panjang antrian : %d\n", sizeQueue2(A));
    printf ("~ENQUEUE2N~\n");
    printf ("Masukkan nilai N : ");
    scanf ("%d",&n);
    enqueue2N(&A, n);
    printQueue2(A);
    printf("\n");
    printf ("~ISEQUALQUEUE2~\n");
    createQueue2(&C);
    enqueue2(&C, 'A');
    enqueue2(&C, 'Z');
    printf("Apakah queue sama : %s", isEqualQueue2(A, C) ? "Sama":"Tidak");
}