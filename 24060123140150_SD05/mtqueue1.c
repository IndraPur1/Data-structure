/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : Indra Purwanto*/
/* Tanggal   : 27 Spetember 2024*/
/***********************************/

#include <stdio.h>
#include "tqueue1.h"
#include "tqueue1.c"
#include "boolean.h"\

int main ()
{
    //Kamus Main
    tqueue A; // Variabel A bertipe std::queue 
    tqueue B;
    char temp;
    //Algoritma
    printf ("~CREATEQUEUE~ \n");
    createQueue(&A);
    createQueue(&B);
    printQueue(A);
    printf("\n");
    printQueue(B);
    printf("\n");
    viewQueue(A);
    printf("\n");
    viewQueue(B);
    printf("\n");
    printf ("~ENQUEUE~");
    printf("\n");
    enqueue(&A, 'A');
    enqueue(&B, 'B');
    printQueue(A);
    printf("\n");
    printQueue(B);
    printf("\n");
    printf ("~DEQUEUE~");
    printf("\n");
    dequeue(&A, &temp);
    printf ("Elemen yang keluar adalah = %c\n", temp);
    dequeue(&B, &temp);
    printf ("Elemen yang keluar adalah = %c\n", temp);
    printQueue(A);
    printf("\n");
    printQueue(B);
    printf("\n");
    printf ("~ENQUEUE1~");
    printf("\n");
    enqueue1(&A, 'A');
    enqueue1(&A, 'B');
    enqueue1(&A, 'C');
    enqueue1(&A, 'D');
    enqueue1(&A, 'E');
    enqueue1(&A, 'F');
    enqueue1(&A, 'G');
    enqueue1(&A, 'H');
    enqueue1(&A, 'I');
    enqueue1(&A, 'J');
    enqueue1(&A, 'K');
    printQueue(A);
    printf("\n");
    printf("setelah penuh ditambah lagi menjadi");
    enqueue1(&A, 'L');
    printf("\n");
    printQueue(A);
    printf("\n");
    printf ("~MAXLENGTH~");
    printf("\n");
    printf ("ukuran queue yang lebih panjang adalah = %d\n", maxlength(A, B));
    printQueue(A);
    printf("\n");
    printQueue(B);
    printf("\n");
    printf ("~ENQUEUE2~");
    printf("\n");
    enqueue2(&A, &B, 'B');
    printQueue(A);
    printf("\n");
    printQueue(B);
    printf("\n");
    printf ("~DEQUEUE2~");
    printf("\n");
    dequeue2(&A, &B, &temp);
    printQueue(A);
    printf("\n");
    printQueue(B);
    printf("\n");
    printf ("~INFOHEAD~ \n");
    printf ("Elemen pertama adalah = %c\n", infoHead(A));
    printf ("~INFOTAIL~ \n");
    printf ("Elemen terakhir adalah = %c\n", infoTail(A));
    printf ("~SIZEQUEUE~ \n");
    printf ("Ukuran Queue adalah = %d\n", sizeQueue(A));
    printf ("~ISONEELEMNT~ \n");
    printf ("Queue hanya memiliki satu elemen = %d\n",isOneElement(A));
    printf ("~INFOEMPTYQUEUE~ \n");
    printf ("Queue adalah queue kosong = %d\n", isEmptyQueue(A));
    printf ("~ISFULLQUEUE~ \n");
    printf ("Queue adalah queue penuh = %d\n", isFullQueue(A));
}