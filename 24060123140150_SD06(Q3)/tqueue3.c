/* Program   : tqueue3.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model III: head memutar searah jarum jam */
/* NIM/Nama  : 24060123140150 / Indra Purwanto*/
/* Tanggal   : 4 Oktober 2024*/
/***********************************/


#include "boolean.h"
#include <math.h>
#include <stdio.h>
#include "tqueue3.h"
#include <stdbool.h>

/*procedure createQueue3 ( output Q:tQueue3)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='#'}*/
void createQueue3(tqueue3 *Q)
{
    // Kamus Lokal
    int i;

    // Algoritma
    i = 1;
    for (i = 1; i <= 5; i++)
    {
        (*Q).wadah[i] = '#';
    }
    (*Q).head = 0;
    (*Q).tail = 0;
}

/*function isEmptyQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue3(tqueue3 Q)
{
    // Kamus Lokal

    // Algoritma
    return Q.tail == 0;
}

/*function isFullQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue3(tqueue3 Q)
{
    // Kamus Lokal

    // Algoritma
    return (tail3(Q) + 1 % 5) == head3(Q);
}

/*function isOneElement3(Q:tQueue3) -> boolean
{mengembalikan true jika Q 1 elemen}*/
boolean isOneElement3(tqueue3 Q)
{
    // Kamus Lokal

    // Algoritma
    return (Q.head == Q.tail) && (Q.head != 0);
}

/*Function Head3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terdepan} */
int head3(tqueue3 Q)
{
    // Kamus lokal

    // Algoritma
    return Q.head;
}

/*Function Tail3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terakhir} */
int tail3(tqueue3 Q)
{
    // Kamus Lokal

    // Algoritma
    return Q.tail;
}

/*Function InfoHead3(Q:tqueue3) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead3(tqueue3 Q)
{
    // Kamus Lokal

    // Algoritma
    if (isEmptyQueue3(Q))
    {
        return '#';
    }
    else
    {
        return Q.wadah[head3(Q)];
    }
}

/*Function InfoTail3(Q:tqueue3) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail3(tqueue3 Q)
{
    // Kamus Lokal

    // Algoritma
    if (isEmptyQueue3(Q))
    {
        return '#';
    }
    else
    {
        return Q.wadah[tail3(Q)];
    }
}

/*function sizeQueue3(Q:tQueue3)-> integer
{mengembalikan panjang antrian Q} */
int sizeQueue3(tqueue3 Q)
{
    // Kamus Lokal
    int i, total;

    // Algoritma
    if (isEmptyQueue3(Q))
    {
        return 0;
    }
    else
    {
        return ((tail3(Q) - head3(Q) + 5) % 5) + 1;
    }
}

/*procedure printQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak isi wadah ke layar, berisi atau kosong}*/
void printQueue3(tqueue3 Q){

    // Kamus Lokal
    int i;

    // Algoritma
    if (isEmptyQueue3(Q) || head3(Q) == 1)
    {
        for (i = 1; i <= 5; i++)
        {
            printf("%c ", Q.wadah[i]);
        }
    }
    else
    {
        i = head3(Q);
        while (i != (head3(Q) - 1))
        {
            printf("%c ", Q.wadah[i]);
            i = (i % 5) + 1;
        }
        printf("%c ", Q.wadah[i]);
    }
}

/*procedure viewQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue3(tqueue3 Q){
    // Kamus Lokal
    int i;

    // Algoritma
    i = head3(Q);
    while (i != (tail3(Q))) 
    {
        printf("%c ", Q.wadah[i]);
        i = (i % 5) + 1;
    }
    printf("%c ", Q.wadah[i]);
}

/*procedure enQueue3( input/output Q:tQueue3, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q sebagai tail, mungkin memutar ke 1 } */
void enqueue3(tqueue3 *Q, char E)
{
    // Kamus Lokal

    // Algoritma
    if (!isFullQueue3(*Q))
    {
        if (isEmptyQueue3(*Q))
        {
            (*Q).head += 1;
        }

        (*Q).tail = (tail3(*Q) % 5) + 1;
        (*Q).wadah[(*Q).tail] = E;
    }
}

/*procedure deQueue3( input/output Q:tQueue3,output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q), bila kosong E=' '}
{proses: mengurangi elemen wadah Q, bila 1 elemen, maka Head dan Tail mengacu ke 0 } */
void dequeue3(tqueue3 *Q, char *E)
{
    // Kamus Lokal

    // Algoritma
    if (!isEmptyQueue3(*Q))
    {
        *E = infoHead3(*Q);
        (*Q).wadah[head3(*Q)] = '#';
        if (isOneElement3(*Q))
        {
            (*Q).head = 0;
            (*Q).tail = 0;
        }
        else
        {
            (*Q).head = (head3(*Q) % 5) + 1;
        }
    }
    else
    {
        *E = ' ';
    }
}

/*EKSTRA: kerjakan bila semua fungsi/prosedur di atas sudah well tested*/
/*function isTailOverHead(Q:tQueue3) -> boolean
{mengembalikan true jika tail berada di depan head}*/
boolean isTailOverHead(tqueue3 Q)
{
    // Kamus Lokal

    // Algoritma
    return tail3(Q) < head3(Q);
}

/*function countMember(Q:tQueue3, E:character) -> integer
{mengembalikan banyaknya nilai E dalam antrian Q}*/
int countMember(tqueue3 Q, char E)
{
    // Kamus Lokal
    int i, sum;

    // Algoritma
    i = head3(Q);
    sum = 0;
    while (i != tail3(Q))
    {
        if (Q.wadah[i] == E)
        {
            sum += 1;
        }

        i = (i  % 5) + 1;
    }
    if (Q.wadah[i] == E)
    {
        sum += 1;
    }
    
    return sum;
}

/*procedure enQueue3E( input/output Q:tQueue3, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q sebagai tail, mungkin memutar ke 1 dengan syarat nilai E belum ada di Q} */
void enqueue3E(tqueue3 *Q, char E)
{
    // Kamus Lokal

    // Algoritma
    if (!isFullQueue3(*Q))
    {
        if (countMember(*Q, E) == 0)
        {
            enqueue3(Q, E);
        }
    }
}