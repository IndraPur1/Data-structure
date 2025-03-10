#include "tqueue3.h"
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

typedef struct {char nama;
                char negara;
                }peserta;

typedef struct priority{peserta wadah[11]; 
                        int head; 
                        int tail;
                        }Qpriority;


/*procedure createQueue3 ( output Q:tQueue3)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='#'}*/ 
void createQpriority(Qpriority *Q){
    // kamus lokal
    int i;
    peserta P0;

    // algoritma
    P0.nama = ' ';
    P0.negara = ' ';
    (*Q).head = 0;
    (*Q).tail = 0;
    for ( i = 1; i <= 10; i++){
        (*Q).wadah[i] = P0;
    }
}

/*function isEmptyQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(Qpriority Q){
    return (Q).tail == 0;
}
 
/*function isFullQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(Qpriority Q){
    return ((Q).head == 1 && (Q).tail == 10) || ((Q).head == ((Q).tail + 1));
}

/*function isOneElement3(Q:tQueue3) -> boolean
{mengembalikan true jika Q 1 elemen}*/
boolean isOneElement(Qpriority Q){
    if (!isEmptyQueue(Q)){
        return (Q).tail == (Q).head;
    }else{
        return false;
    }
}
/*procedure deQueue3( input/output Q:tQueue3,output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q), bila kosong E=' '}
{proses: mengurangi elemen wadah Q, bila 1 elemen, maka Head dan Tail mengacu ke 0 } */
void dequeue(Qpriority *Q, peserta *E){
    // kamus lokal
    peserta P0;

    // algoritma
    P0.nama = ' ';
    P0.negara = ' ';
    if (isEmptyQueue(*Q)){
        printf("Queue Kosong\n");
    }else{
        *E = (*Q).wadah[(*Q).head];
        (*Q).wadah[(*Q).head] = P0 ;
        (*Q).head = ((*Q).head % 10) + 1;
    }
}

/*function searchqueue(Q: Qpriority, P: peserta) -> integer
{mengembalikan index terakhir dari Q dengan negara dari elemen peserta yg sama dengan input P}*/
int searchqueue(Qpriority Q, peserta P){
    //kamus lokal
    int i, found;

    //algoritma
    found = 0;
    if (Q.head <= Q.tail){
        for ( i = 1; i <= 10; i++){
            if (P.negara == Q.wadah[i].negara){
                found = i;
            }
        }
    }else{
        for ( i = 1; i <= 10; i++){
            if (P.negara == Q.wadah[i].negara){
                if (i < Q.head){
                    found = i;
                }
            }
        }
    }
return found;
}

/*procedure enqueue (input/output Q: Qpriority, input P: peserta)
{I.S: Q terdefinisi, P terdefinisi}
{F.S: Q sama atau Q bertambah satu elemen (pada tail+1 atau sebelum elemen terakhir pada negara yang sama}
{proses: menambah elemen wadah Q sebagai tail, mungkin memutar ke 1 atau ditambahkan sebelum elemen terakhir pada negara yang sama }*/

void enqueue(Qpriority *Q, peserta P){
    //kamus lokal
    int i;
    peserta e;

    //algoritma
    if (!isFullQueue(*Q)){
        if (searchqueue(*Q,P) != 0){
            if ((*Q).head <= (*Q).tail){
                for ( i = (*Q).tail; i >= searchqueue(*Q,P) + 1; i--){
                    (*Q).wadah[i+1] = (*Q).wadah[i];
                }
                if (isOneElement(*Q)){
                    (*Q).head++;
                }(*Q).tail = ((*Q).tail % 10) + 1;
                (*Q).wadah[searchqueue(*Q,P) + 1] = P;
            }else{    
                for (i = (*Q).head + 9; i >= searchqueue(*Q,P) + 1; i--){
                    (*Q).wadah[(i+1) % 10] = (*Q).wadah[i % 10];
                }if (isOneElement(*Q)){
                    (*Q).head++;
                }(*Q).tail = ((*Q).tail % 10) + 1;
                (*Q).wadah[searchqueue(*Q,P) + 1] = P;
            }
        }else{
            if (isEmptyQueue(*Q)){
                (*Q).head++;
            }(*Q).tail = ((*Q).tail % 10) + 1;
            (*Q).wadah[(*Q).tail] = P;
        }
    }else{
        dequeue(Q, &e);
        if (searchqueue(*Q,P) != 0){
            for (i = (*Q).head + 9; i >= searchqueue(*Q,P) + 1; i--){
                if (i != 11){
                    (*Q).wadah[(i) % 10] = (*Q).wadah[(i-1) % 10];
                }else{
                    (*Q).wadah[(i) % 10] = (*Q).wadah[i-1];
                }
            }(*Q).wadah[searchqueue(*Q,P) + 1] = P;
        }else{
            (*Q).wadah[(*Q).tail + 1] = P;
        }
        (*Q).tail = ((*Q).tail % 10) + 1;
    }
}

/*procedure printQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak isi wadah ke layar, berisi atau kosong}*/
void printQueue(Qpriority Q){
    // kamus lokal
    int i;

    // algoritma
    for ( i = 1; i <= 10; i++){
        printf("%c, ", Q.wadah[i].negara);
    }printf("\n");
}

/*procedure viewQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue(Qpriority Q){
    // Kamus lokal
    int i;

    // Algoritma
    if (isEmptyQueue(Q)) {
        printf("Queue kosong\n");
    } else {
        for (i = Q.head; i != Q.tail ; i = (i % 10) + 1) {
            printf("%c, ", Q.wadah[i].negara);  
        }
        printf("%c, ", Q.wadah[Q.tail].negara);
        printf("\n");
    }
}

int main(){
    // kamus lokal
    Qpriority Q;
    peserta P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12;

    // algoritma
    createQpriority(&Q);
    P1.nama = 'A';
    P1.negara = 'X';
    P2.nama = 'B';
    P2.negara = 'V';
    P3.nama = 'C';
    P3.negara = 'Z';
    P4.nama = 'D';
    P4.negara = 'W';
    P5.nama = 'E';
    P5.negara = 'Z';
    P6.nama = 'F';
    P6.negara = 'Y';
    P7.nama = 'G';
    P7.negara = 'V';
    P8.nama = 'H';
    P8.negara = 'Y';
    P9.nama = 'I';
    P9.negara = 'X';
    P10.nama = 'J';
    P10.negara = 'W';
    P11.nama = 'K';
    P11.negara = 'Y';
    P12.nama = 'L';
    P12.negara = 'X';
    enqueue(&Q, P1);
    printQueue(Q);
    viewQueue(Q);
    printf("%d\n", Q.head);
    printf("%d\n", Q.tail);
    enqueue(&Q, P2);
    printQueue(Q);
    viewQueue(Q);
    printf("%d\n", Q.head);
    printf("%d\n", Q.tail);
    enqueue(&Q, P3);
    printQueue(Q);
    viewQueue(Q);
    printf("%d\n", Q.head);
    printf("%d\n", Q.tail);
    enqueue(&Q, P4);
    printQueue(Q);
    viewQueue(Q);
    printf("%d\n", Q.head);
    printf("%d\n", Q.tail);
    enqueue(&Q, P5);
    printQueue(Q);
    viewQueue(Q);
    printf("%d\n", Q.head);
    printf("%d\n", Q.tail);
    enqueue(&Q, P6);
    printQueue(Q);
    viewQueue(Q);
    printf("%d\n", Q.head);
    printf("%d\n", Q.tail);
    enqueue(&Q, P7);
    printQueue(Q);
    viewQueue(Q);
    printf("%d\n", Q.head);
    printf("%d\n", Q.tail);
    enqueue(&Q, P8);
    printQueue(Q);
    viewQueue(Q);
    printf("%d\n", Q.head);
    printf("%d\n", Q.tail);
    enqueue(&Q, P9);
    printQueue(Q);
    viewQueue(Q);
    printf("%d\n", Q.head);
    printf("%d\n", Q.tail);
    enqueue(&Q, P10);
    printQueue(Q);
    viewQueue(Q);
    printf("%d\n", Q.head);
    printf("%d\n", Q.tail);
    enqueue(&Q, P11);
    printQueue(Q);
    viewQueue(Q);
    printf("%d\n", Q.head);
    printf("%d\n", Q.tail);
    enqueue(&Q, P12);
    printQueue(Q);
    viewQueue(Q);
    printf("%d\n", Q.head);
    printf("%d\n", Q.tail);
    

return 0;
}