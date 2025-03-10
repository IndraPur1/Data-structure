/* File : List2.c */
/* Deskripsi : realisasi body ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123140150 & Indra Purwanto*/
/* Tanggal : 8 November 2024*/

#include <stdio.h>
#include <stdlib.h>
#include "list2.h"

/*================== PROTOTYPE =======================*/
/****************** Manajemen Memori ******************/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E){
    //kamus lokal
	address P;
	//algoritma
	P = (address) malloc(sizeof(Elm));
	if (P != NIL) { //ruang memori tersedia
		info(P) = E;
		next(P) = NIL;
	}
	return P;
}

/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P){
    //kamus lokal
	
	//algoritma
	free(*P);
	*P = NIL;
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List2)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List2 *L){
    //Kamus Lokal 
    
    //Algoritma 
    First(*L) = NIL;
}

/****************** TEST KONDISI LIST ******************/
/* function IsEmptyList(L:List2) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List2 L){
    //Kamus Lokal
    
    //Algoritma
    return First(L) == NIL;
}

/* function IsOneElm(L:List2) --> boolean 
   {mengembalikan true bila list L hanya punya satu elemen} */
boolean IsOneElm (List2 L){
    //Kamus Lokal
    
    //Algoritma
    return First(L) != NIL && next(First(L)) == First(L);
}

/*********** PENELUSURAN ***********/
/*procedure PrintList(input L:List2)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List2 L){
    //Kamus Lokal
    address P;
    //Algoritma
    P = First(L);
    if (P == NIL){
        printf ("Isi list kosong");
    }
    else {
        printf ("Isi list :");
        do {
            printf("\t%c", info(P));
            P = next(P);
        }
        while (P != First(L));
    }
    printf ("\n");
}

/*function NbElm(L:List2) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List2 L){
    //Kamus Lokal
    address P;
    int Count;
    //Algoritma
    P = First(L);
    Count = 0;
    if (P != NIL){
        do{
            Count++;
            P = next(P);
        }
        while (P != First(L));
    }
    return Count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List2 *L, infotype V ){
    //Kamus Lokal
    address P;
    address A;
    //Algoritma
    A = Alokasi(V);
    P = First(*L);
    if (A != NIL){
        if (P == NIL){
            First(*L) = A;
            next(A) = A;
        }
        else {
            next(A) = First(*L);
            while (next(P) != First(*L)){
                P = next(P); 
            }
            next(P) = A;
            First(*L) = A;
        }
    }
}

/*Procedure InsertVLast(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V, next(P)=First(L)}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List2 *L, infotype V ){
    //Kamus Lokal
    address P;
    address Last;
    //Algoritma
    P = Alokasi(V);
    if (P != NIL){
        if (First(*L) == NIL){
            First(*L) = P;
            next(P) = P;
        }
        else{
            Last = First(*L);
            while (next(Last) != First(*L)){
                Last = next(Last);
            }
            next(Last) = P;
            next(P) = First(*L);
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen pertama list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List2 *L, infotype *V){
    //Kamus Lokal
    address P;
    address Last;
    //Algoritma
    if (First(*L) == NIL){
        (*V) ='#';
    }
    else {
        P = First(*L);
        (*V) = info(P);
        if (next(P) == P){
            First(*L) = NIL;
        }
        else {
            Last = First(*L);
            while (next(Last) != First(*L)){
                Last = next(Last);
            }
            First(*L) = next(P);
            next(Last) = First(*L);
        }
    }
    Dealokasi(&P);
}

/*Procedure DeleteVLast(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List2 *L, infotype *V){
    //Kamus Lokal
    address Last;
    address Prec;
    //Algoritma
    if (First(*L) == NIL){
        (*V) ='#';
    }
    else {
        Prec = NIL;
        Last = First(*L);
        while (next(Last) != First(*L)){
            Prec = Last;
            Last = next(Last);
        }
        (*V) = info(Last);
        if (Prec != NIL){
            next(Prec) = First(*L);
        }
        else{
            First(*L) = NIL;
        }
    }
    Dealokasi(&Last);
}

/*Procedure DeleteX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteX(List2 *L, infotype X){
    //Kamus Lokal
    address P;
    address Prev;
    address del;
    address Last;
    //Algoritma
    P = First(*L);
    Prev = NIL;
    if (P != NIL){
        do{
            if (info(P) == X){
                del = P;
                if (Prev == NIL){
                    if (next(P) == P){
                        First(*L) = NIL;
                        P = NIL;
                    }
                    else{
                        Last = P;
                        while (next(Last) != P){
                            Last = next(Last);
                        }
                        First(*L) = next(P);
                        next(Last) = First(*L);
                        P = First(*L);
                    }
                }
                else{
                    next(Prev) = next(P);
                    P = next(P);
                }
                next(del) = NIL;
                Dealokasi(&del);
            }
            else{
                Prev = P;
                P = next(P);
            }
        }
        while (P != First(*L) && P != NIL);
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List2, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List2 L, infotype X, address *A){
    //Kamus Lokal
    address P;
    //Algoritma
    P = First(L);
    (*A) = NIL;
    if (P != NIL){
        do {
            if (info(P) == X){
                (*A) = P;
            }
            else{
                P = next(P);
            }
        }
        while (P != First(L) && (*A) == NIL);
    }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List2, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List2 *L, infotype X, infotype Y){
    //Kamus Lokal
    address P;
    int Found;
    //Algoritma
    Found = 0;
    P = First(*L);
    do {
        if (info(P) == X){
            info(P) = Y;
            Found = 1;
        }
        else{
            P = next(P);
        }
    }
    while (P != First(*L) && Found == 0);
}

/*Procedure Invers(input/output L:List2)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, 
misal {'A','B','C'} menjadi {'C','B','A'} }*/
void Invers(List2 *L){
    //Kamus Lokal
    address P;
    address Next;
    address Prev;
    //Algoritma
    P = First(*L);
    Next = NIL;
    Prev = NIL;
    if (P != NIL){
        do{
            Next = next(P);
            next(P) = Prev;
            Prev = P;
            P = Next;
        }
        while (P != First(*L));
        next(First(*L)) = Prev; 
        First(*L) = Prev;
    }
}

/*function CountX(L:List2, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List2 L, infotype X){
    //Kamus Lokal
    address P;
    int Count;
    //Algoritma
    Count = 0;
    P = First(L);
    if (P != NIL){
        do{
            if (info(P) == X){
            Count++;
            }
            P = next(P);
        }
        while (P != First(L));
    }
    return Count;
}

/*function FrekuensiX(L:List2, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List2 L, infotype X){
    //Kamus Lokal
    address P;
    int Count;
    //Algoritma
    Count = 0;
    P = First(L);
    if (P != NIL){
        do{
            if (info(P) == X){
                Count++;
            }
            P = next(P);
        }
        while (P != First(L));
    }
    return (float) Count/ NbElm(L);
}

/*function CountVocal(L:List2) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List2 L){
    //Kamus Lokal
    address P;
    int Count;
    //Algoritma
    Count = 0;
    P = First(L);
    if (P != NIL){
        do{
            if ((info(P) == 'A') || (info(P) == 'I') || (info(P) == 'U') || (info(P) == 'E') || (info(P) == 'O')){
                Count++;
            }
            P = next(P);
        }
        while (P != First(L));
    }
    return Count;
}

/*function CountNG(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List2 L){
    //Kamus Lokal
    address P;
    int Count;
    //Algoritma
    Count = 0;
    P = First(L);
    if (P != NIL && next(P) != First(L)){
        do{
            if (info(P) == 'N'){
                if (info(next(P)) == 'G'){
                    Count++;
                }
            }
            P = next(P);
        }
        while (P != First(L));
    }
    return Count;
}

/*Procedure InsertVAfterX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List2 *L, infotype X, infotype V){
    //Kamus Lokal
    address P;
    address A;
    //Algoritma
    P = Alokasi(V);
    if (P != NIL){
        A = First(*L);
        do{
            A = next(A);
        }
        while(A != First(*L) && info(A) != X);
        if (info(A) == X){
            next(P) = next(A);
            next(A) = P;
            if (next(A) == First(*L)){
                next(A) = First(*L);
            }
        }
    }
}

/*Procedure InsertVBeforeX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List2 *L, infotype X, infotype V){
    //Kamus Lokal
    address P;
    address A;
    address prev;
    address last;
    //Algoritma
    P = Alokasi(V);
    if (P != NIL){
        A = First(*L);
        prev = NIL;
        do{
            prev = A;
            A = next(A);
        }
        while(A != First(*L) && info(A) != X);
        if (info(A) == X){
            if (prev == NIL){
                last = First(*L);
                do{
                    last = next(last);
                }
                while (next(last) != First(*L));
                next(P) = First(*L);
                next(last) = P;
                First(*L) = P;
            }
            else{
                next(prev) = P;
                next(P) = A;
            }
        }
    }
}

/*Procedure DeleteVAfterX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List2 *L, infotype X, infotype *V){
    //Kamus Lokal
    address P;
    address delete;
    //Algoritma
    P = First(*L);
    if (P != NIL){
        delete = next(P);
        while(next(P) != First(*L) && info(P) != X){
            delete = next(delete);
            P = next(P);
        }
        if (info(P) == X){
            (*V) = info(delete);
            if (next(delete) == First(*L)){
                next(P) = First(*L);
            }
            else{
                next(P) = next(delete);
            }
            Dealokasi(&delete);
        }
        else{
            printf ("Elemen tidak ditemukan dalam list\n");
        }
    }
}

/*Procedure DeleteVBeforeX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List2 *L, infotype X, infotype *V){
    //Kamus Lokal
    address P; 
    address delete;
    address prev;
    //Algoritma
    P = First(*L);
    if(P != NIL){
        delete = P;
        prev = NIL;
        while(next(P) != First(*L) && info(P) != X){
            prev = delete;
            delete = P;
            P = next(P);
        }
        if(info(P) == X){
            (*V) = info(delete);
            if(P == First(*L)){
                while(next(delete) != First(*L)){
                    prev = delete;
                    delete = next(delete);
                }
                if(next(delete) == delete){
                    First(*L) = NIL;
                }
                else{
                    next(prev) = next(delete);
                }   
            }
            else{
                if (prev == delete){
                    while(next(prev) != delete){
                        prev = next(prev);
                    }
                    First(*L) = next(delete);
                    next(prev) = First(*L);
                }
                else{
                next(prev) = next(delete);
            }
            next(delete) = NIL;
            Dealokasi(&delete);
            }
        }
    }
}


/*Procedure DeleteAllX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Semua elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteAllX(List2 *L, infotype X){
    //Kamus Lokal
    address P;
    address Prev;
    address del;
    address Last;
    //Algoritma
    P = First(*L);
    Prev = NIL;
    if (P != NIL){
        do{
            if (info(P) == X){
                del = P;
                if (Prev == NIL){
                    if (next(P) == P){
                        First(*L) = NIL;
                        P = NIL;
                    }
                    else{
                       Last = P; 
                       while (next(Last) != First(*L)){
                           Last = next(Last);
                       }
                       First(*L) = next(P);
                       next(Last) = First(*L);
                       P = First(*L);
                    }
                }
                else{
                    next(Prev) = next(P);
                    P = next(P);
                }
                next(del) = NIL;
                Dealokasi(&del);
            }
            else {
                Prev = P;
                P = next(P);
            }
        }
        while (P != First(*L) && P != NIL);
    }
    
}


/*Procedure SearchAllX(input L:List2, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List2 L, infotype X){
    //Kamus Lokal
    address P;
    int Found;
    int Posisi;
    //Algoritma
    Found = 0;
    Posisi = 1;
    P = First(L);
    if (P == NIL) {
        printf("List adalah list kosong\n");
    }
    else {
        do{
            if (info(P) == X){
                printf ("Elemen %c ditemukan pada posisi : %d\n", X, Posisi);
                Found = 1;
            }
            P = next(P);
            Posisi++;
        }
        while (P != First(L));
        if (!Found){
            printf ("Elemen tidak ditemukan pada list\n");
        }
    }
}

/*function MaxMember(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List2 L){
    //Kamus Lokal
    address P;
    int Count;
    int max;
    //Algoritma
    P = First(L);
    max = 0;
    Count = 0;
    if (P != NIL){
        do{
            Count = CountX(L, info(P));
            if (Count > max){
                max = Count;
            }
            P = next(P);
        }
        while (P != First(L));
    }
    return max;
}

/*function Modus(L:List2) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List2 L){
    //Kamus Lokal
    address P;
    int Count;
    int max;
    char mod;
    //Algoritma
    P = First(L);
    max = 0;
    Count = 0;
    if (P != NIL){
        do{
            Count = CountX(L, info(P));
            if (Count > max){
                max = Count;
                mod = info(P);
            }
            P = next(P);
        }
        while (P != First(L));
    }
    return mod;
}


/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List2, input L2:List2, output L:List2)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List2 L1, List2 L2, List2 *L){
    //Kamus Lokal
    address Last1;
    address Last2;
    //Algoritma
    if (First(L1) == NIL && First(L2) == NIL){
        First(*L) = NIL;
    }
    else if (First(L1) == NIL){
        First(*L) = First(L2);
    }
    else if (First(L2) == NIL){
        First(*L) = First(L1);
    }
    else{
        First(*L) = First(L1);
    }
    Last1 = First(L1);
    while (next(Last1) != First(L1)){
        Last1 = next(Last1);
    }
    Last2 = First(L2);
    while (next(Last2) != First(L2)){
        Last2 = next(Last2);
    }
    next(Last1) = First(L2);
    next(Last2) = First(*L);
}

/*Procedure SplitList(input L:List2, output L1:List2, output L2:List2)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List2 L, List2 *L1, List2 *L2){
    //kamus lokal
    address P, Mid;
    int count, i;

    //algoritma
    if (!IsEmptyList(L)){
        count = NbElm(L);
        Mid = First(L);
        for (i = 1; i < (count / 2); i++){
            Mid = next(Mid);
        }
        (*L1) = L;
        First(*L2) = next(Mid);
        next(Mid) = First(*L1);
        P = First(*L2);
        while (next(P) != First(L)){
            P = next(P);
        }next(P) = First(*L2);
    }else{
        First(*L1) = NIL;
        First(*L2) = NIL;
    }
}

/*Procedure CopyList(input L1:List2, output L2:List2)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List2 L1, List2 *L2){
    //Kamus Lokal
    address P;
    address Last;
    //Algoritma
    P = First(L1);
    CreateList(L2);
    if (P != NIL){
        do {
            InsertVLast(L2, info(P));
            P = next(P);
        }
        while (P != First(L1));
    }
    if (First(*L2) != NIL) {
        Last = First(*L2);
        while (next(Last) != First(*L2)) {
            Last = next(Last);
        }
        next(Last) = First(*L2);  
    }
}