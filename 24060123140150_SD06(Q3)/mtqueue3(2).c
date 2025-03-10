#include <stdio.h>
#include "tqueue3.h"
#include "boolean.h"
#include "tqueue3.c"
/* Program   : Mqueue3.C */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model III: head memutar searah jarum jam */
/* NIM/Nama  : 24060123140150 / Indra Purwanto */
/* Tanggal   : 4 Oktober 2024*/
/***********************************/


int main(){
    tqueue3 Q1;
    char E;
    printf("Inisialisasi Q1...\n");
    createQueue3(&Q1);
    printQueue3(Q1);
    printf("\n");
    printf("isEmptyQueue3 = %d\n", isEmptyQueue3(Q1));
    printf("\n");

    printf("Enqueue3 sebanyak 5 kali...\n");
    enqueue3(&Q1, 'A');
    enqueue3(&Q1, 'A');
    enqueue3(&Q1, 'A');
    enqueue3(&Q1, 'A');
    enqueue3(&Q1, 'A');
    printQueue3(Q1);
    printf("\n");
    printf("head = %d dan tail = %d\n", head3(Q1), tail3(Q1));
    printf("isFullQueue3 = %d\n", isFullQueue3(Q1));
    printf("\n");

    printf("Dequeue3 sebanyak 4 kali...\n");
    dequeue3(&Q1, &E);
    dequeue3(&Q1, &E);
    dequeue3(&Q1, &E);
    dequeue3(&Q1, &E);
    printQueue3(Q1);
    printf("\n");
    printf("head = %d dan tail = %d\n", head3(Q1), tail3(Q1));
    printf("\n");

    printf("Enqueue3 sebanyak 4 kali...\n");
    enqueue3(&Q1, 'K');
    enqueue3(&Q1, 'K');
    enqueue3(&Q1, 'K');
    enqueue3(&Q1, 'K');
    printQueue3(Q1);
    printf("isFullQueue3 = %d\n", isFullQueue3(Q1));
    printf("\n");

    printf("Dequeue3 sebanyak 1 kali...\n");
    dequeue3(&Q1, &E);
    printQueue3(Q1);
    printf("\n");
    printf("head = %d dan tail = %d\n", head3(Q1), tail3(Q1));
    printf("\n");

    printf("Dequeue3 sebanyak 1 kali...\n");
    dequeue3(&Q1, &E);
    printQueue3(Q1);
    printf("\n");
    printf("head = %d dan tail = %d\n", head3(Q1), tail3(Q1));
    printf("\n");

    printf("Tes viewQueue3...\n");
    viewQueue3(Q1);
    printf("\n");

    printf("Tes sizeQueue3...\n");
    printf("sizeQueue3 = %d\n", sizeQueue3(Q1));
    printf("\n");

    printf("infoHead3 = %c\n", infoHead3(Q1));
    printf("infoTail3 = %c\n", infoTail3(Q1));
    printf("\n");

    printf("Dequeue3 sebanyak 2 kali...\n");
    dequeue3(&Q1, &E);
    dequeue3(&Q1, &E);
    printQueue3(Q1);
    printf("\n");
    printf("head = %d dan tail = %d\n", head3(Q1), tail3(Q1));
    printf("isOneElement3 = %d\n", isOneElement3(Q1));

    printf("\n");
    printf("=========================================================\n");
    printf("\n");
    
    printf("Enqueue3 sebanyak 4 kali...\n");
    enqueue3(&Q1, 'K');
    enqueue3(&Q1, 'K');
    enqueue3(&Q1, 'T');
    enqueue3(&Q1, 'T');
    printQueue3(Q1);
    printf("\n");
    printf("isTailOverHead = %d\n", isTailOverHead(Q1));
    printf("\n");

    printf("Banyaknya elemen 'T' = %d\n", countMember(Q1, 'T'));
    printf("\n");

    printf("Dequeue3 sebanyak 2 kali...\n");
    dequeue3(&Q1, &E);
    dequeue3(&Q1, &E);
    printQueue3(Q1);
    printf("\n");
    printf("head = %d dan tail = %d\n", head3(Q1), tail3(Q1));
    printf("\n");

    printf("Mencoba enqueue3E dengan 'K'...\n");
    enqueue3E(&Q1, 'K');
    printQueue3(Q1);
    printf("\n");
    printf("Mencoba enqueue3E dengan 'H'...\n");
    enqueue3E(&Q1, 'H');
    printQueue3(Q1);
    printf("\n");
    printf("infoTail3 = %c\n", infoTail3(Q1));
    printf("\n");

    return 0;
}