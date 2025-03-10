#include <stdio.h>
#include "tqueue3.h"
#include "tqueue3.c"
#include "boolean.h"

/* Program   : tqueue3.h */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model III: head memutar searah jarum jam */
/* NIM/Nama  : 24060123140150 / Indra Purwanto */
/* Tanggal   : 4 Oktober 2024*/
/***********************************/


int main(){
    //Kamus Main
    tqueue3 A;
    char temp;
    //Algoritma
    createQueue3(&A);
    printf ("~PRINTQUEUE3~\n");
    printQueue3(A);
    printf("\n");
    printf ("~ISEMPTYQUEUE3~\n");
    printf ("Queue merupakan queue adalah kosong : %d\n", isEmptyQueue3(A));
    printf("\n");
    printf ("~ISFULLQUEUE3~\n");
    printf ("Queue merupakan queue penuh : %d\n", isFullQueue3(A));
    printf("\n");
    printf ("~ISONEELEMENT3~\n");
    printf ("Elemen queue hanya ada satu : %d\n", isFullQueue3(A));
    printf("\n");
    printf ("~SIZEQUEUE3~\n");
    printf("Ukuran queue adalah = %d\n", sizeQueue3(A));
    printf("\n");
    printf ("~ENQUEUE3~ {Sebanyak 5 kali}\n");
    enqueue3(&A,'S');
    enqueue3(&A,'A');
    enqueue3(&A,'M');
    enqueue3(&A,'B');
    enqueue3(&A,'A');
    printQueue3(A);
    printf("\n");
    printf ("~DEQUEUE3~\n");
    dequeue3(&A, &temp);
    printf ("Elemen yang dikeluarkan dari queue adalah : %c\n", temp);
    printQueue3(A);
    printf("\n");
    printf ("~ENQUEUE3E~ {Elemen ada di queue}\n");
    enqueue3E(&A, 'B');
    printQueue3(A);
    printf("\n");
    printf ("~ENQUEUE3E~ {Elemen tidak ada di queue}\n");
    enqueue3E(&A, 'S');
    printQueue3(A);
    printf("\n");
    printf("~ISTAILOVERHEAD~\n");
    printf("Apakah posisi tail berada didepan head : %d\n", isTailOverHead(A));
    printf("\n");
    printf ("~INFOHEAD3~\n");
    printf ("Elemen head adalah = %c\n", infoHead3(A));
    printf("\n");
    printf ("~INFOTAIL3~\n");
    printf ("Elemen tail adalah = %c\n", infoTail3(A));
    printf("\n");
    printf ("~COUNTMEMBER~\n");
    printf ("Banyaknya elemen 'S' dalam queue adalah : %d\n", countMember(A,'S'));
    printf ("\n");
    printf ("~VIEWQUEUE3~\n");
    viewQueue3(A);
    return 0;
}