/* Program   : tstack.c */
/* Deskripsi : file BODY modul queue karakter */
/* NIM/Nama  : Indra Purwanto*/
/* Tanggal   : 27 Spetember 2024*/
/***********************************/

#include <stdio.h>
#include "tqueue1.h"
#include "boolean.h"

/*procedure createQueue ( output Q:tQueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi elemen dengan huruf '-', head=tail=0 }*/ 
void createQueue(tqueue *Q){
    // kamus lokal
    int i;

    // algoritma
    for(i = 1; i<=11; i++){
        (*Q).wadah[i] = '-';
    }
    (*Q).head = 0;
    (*Q).tail = 0;
}

/*function Head(Q:tQueue)-> integer 
{mengembalikan elemen terdepan antrian Q} */
//int Head(tqueue Q);
#define head(Q) (Q).head //implementasi fisik macro

/*function Tail(Q:tQueue)-> integer 
{mengembalikan elemen terakhir antrian Q} */
//int Tail(tqueue Q);
#define tail(Q) (Q).tail //implementasi fisik macro

/*function infoHead(Q:tQueue)-> character 
{mengembalikan nilai elemen terdepan antrian Q} */
/*pikirkan bila antrian kosong*/
int infoHead(tqueue Q){
    return Q.wadah[Q.head];
}

/*function infoTail(Q:tQueue)-> character 
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
int infoTail(tqueue Q){
    return Q.wadah[Q.tail];
}

/*function sizeQueue(Q:tQueue)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue(tqueue Q){
    return Q.tail;
}

/*procedure printQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(tqueue Q){
      // kamus lokal
    int i;

    // algoritma
    for(i = 1; i<=11; i++){
        Q.wadah[i];
        printf("%c ; ", Q.wadah[i]);
    }
}

/*procedure viewQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen tak kosong ke layar}*/
void viewQueue(tqueue Q){
    // kamus lokal
    int i = Q.head;

    // algoritma
    if(isEmptyQueue(Q)){
        printf("tabel kosong");
    }
    else{
        for(i = Q.head; i<=Q.tail; i++){
        Q.wadah[i];
        printf("%c ; ", Q.wadah[i]);
        }
    }
}

/*function isEmptyQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(tqueue Q){
    return Q.tail == 0;
}
 
/*function isFullQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(tqueue Q){
    return Q.head == 11;
}

/*function isOneElement(Q:tQueue) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(tqueue Q){
    return Q.tail == 1;
}

/*procedure enqueue( input/output Q:tQueue, input e: character )
{I.S.: Q dan e terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void enqueue(tqueue *Q, char e){
  // kamus lokal
    int i;

    // algoritma
    if((*Q).tail != 11){
        (*Q).wadah[(*Q).tail + 1] = e;
        (*Q).tail++;
        (*Q).head = 1;
    }
    else{
        printf("tabel penuh");
    }
}
  
/*procedure deQueue( input/output Q:tQueue, output e: character )
{I.S.: }
{F.S.: e=infohead(Q) atau e='-' bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void dequeue(tqueue *Q, char *e){
        // kamus lokal
    int i ;

    // algoritma
    if(isEmptyQueue(*Q)){
        *e = '-';
    }
    else{
        *e = infoHead(*Q);
        if ((*Q).head == (*Q).tail){
            (*Q).wadah[(*Q).head] = '-';
            (*Q).head = 0;
            (*Q).tail = 0;
        } else {
            for (i = (*Q).head; i < (*Q).tail; i++) {
                (*Q).wadah[i] = (*Q).wadah[i + 1];
            }
            (*Q).wadah[(*Q).tail] = '-';
            (*Q).tail--;
        }
    }
}
 
/* procedure enqueue1(input/output Q:queue, input e:character)
{I.S.: Q dan e terdefinisi }
{F.S.: Q bertambah 1 elemen atau penuh}
{Proses: menambah elemen queue, jika Q penuh, elemen pertama/head dihapus} */
void enqueue1(tqueue *Q, char e){
    // kamus lokal
    int i;

    // algoritma
    if((*Q).tail != 11){
        (*Q).wadah[(*Q).tail + 1] = e;
        (*Q).tail++;
        (*Q).head = 1;
    }
    else{
        for(i = (*Q).head; i < (*Q).tail; i++){
            (*Q).wadah[i] = (*Q).wadah[i + 1];
        }
        (*Q).wadah[(*Q).tail] = e;
        (*Q).head = 1;
    }
}


/*tambahan, dikerjakan bila cukup waktu */


/*function maxlength(Q1:tqueue, Q2:tqueue) --> integer */
/*{mengembalikan ukuran yang terpanjang dari 2 antrian}*/
int maxlength(tqueue Q1, tqueue Q2){
    if(sizeQueue(Q1) > sizeQueue(Q2)){
        return sizeQueue(Q1);
    }
    else{
        return sizeQueue(Q2);
    }
    
}

/*procedure enqueue2( input/output Q1:tQueue, input/output Q2:tQueue, input e: character )
{I.S.: e terdefinisi}
{F.S.: elemen wadah Q1 atau Q2 bertambah 1, bila belum penuh}
{proses: menambah elemen wadah pada antrian terpendek dari Q1 atau Q2} */
void enqueue2(tqueue *Q1, tqueue *Q2, char e){
    if(!isFullQueue(*Q1) | !isFullQueue(*Q2)){
        if(sizeQueue(*Q1) > sizeQueue(*Q2)){
            (*Q2).wadah[(*Q2).tail + 1] = e;
        }
        else{
            (*Q1).wadah[(*Q1).tail + 1] = e;
        }
    }
    else{
        printf("semua tabel penuh");
    }
}

/*procedure dequeue2( input/output Q1:tQueue, input/output Q2:tQueue, output e: character )
{I.S.: }
{F.S.: e=infohead Q1 atau Q2 atau e='-' bila Q1 dan Q2 kosong, elemen wadah Q1 atau Q2 berkurang 1 }
{proses: mengurangi elemen wadah antrian terpanjang Q1 atau Q2, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail antrian menjadi 0 } */
void dequeue2(tqueue *Q1, tqueue *Q2, char *e){
    // kamus lokal
    int i;

    // algoritma
    if(!isEmptyQueue(*Q1) | !isEmptyQueue(*Q2)){    
        if(sizeQueue(*Q1) > sizeQueue(*Q2)){
            *e = infoHead(*Q1);
            if ((*Q1).head == (*Q1).tail){
                (*Q1).head = 0;
                (*Q1).tail = 0;
            }
            else {
                for (i = (*Q1).head; i < (*Q1).tail; i++) {
                    (*Q1).wadah[i] = (*Q1).wadah[i + 1];
                }
                (*Q1).wadah[(*Q1).tail] = '-';
                (*Q1).tail--;
            }
        }
        else{
            *e = infoHead(*Q2);
            if ((*Q2).head == (*Q2).tail){
                (*Q2).head = 0;
                (*Q2).tail = 0;
            }
            else{
                for(i = (*Q2).head; i < (*Q2).tail; i++) {
                    (*Q2).wadah[i] = (*Q2).wadah[i + 1];
                }
                (*Q2).wadah[(*Q2).tail] = '-';
                (*Q2).tail--;
            }
        }
        }
    else{
        printf("semua kosong");
    }
}