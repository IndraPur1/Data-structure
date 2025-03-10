/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : Indra Purwanto*/
/* Tanggal   : 20 Spetember 2024*/
/***********************************/

#include <stdio.h>
#include "tstack.h"
#include "boolean.h"

/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T){
    // kamus lokal
    int i;
 
    // algoritma
    for(i = 1 ; i <= 11 ; i++){
        (*T).wadah[i] = '-';
    }
    (*T).top = 0;
}

/*function top( T: Tstack) -> integer
	{mengembalikan posisi puncak stack } */
//int top (Tstack T);
//dalam praktikum ini, fungsi dapat direalisasikan
//menjadi macro dalam bahasa C.
#define top(T) (T).top

/*function infotop( T: Tstack) -> character
	{mengembalikan nilai elemen top stack } */
//char infotop (Tstack T);
#define infotop(T) (T).wadah[(T).top]

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T){
    return T.top == 0;
}

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T){
    return T.top == 11;
}

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E){
    if((*T).top < 11){
        (*T).wadah[(*T).top + 1] = E;
        (*T).top++;
    }
    else{
        printf("stack penuh");
    }
}

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X){
    // kamus lokal

     if ((*T).top > 0) {
        *X = (*T).wadah[(*T).top];
        printf("%c", *X);
        (*T).wadah[(*T).top] = '-';
        (*T).top = (*T).top - 1;
    }
    else {
        *X = '-';
    }
}

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T){
    // kamus lokal
    int i;

    // algoritma
    for(i = 1 ; i <= 11; i++){
        T.wadah[i];
        printf("%c ; ", T.wadah[i]);
    }

}

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T){
    // kamus lokal
    int i;

    // algoritma
    for(i = 1 ; i <= 11; i++){
        if(T.wadah[i] != '-'){
            T.wadah[i];
            printf("%c ; ", T.wadah[i]);
        }
    }
}

/* selanjutnya tugas algoritma palindrom dikerjakan di main */

	
/* kerjakan prosedur berikut bila tugas palindrom sudah sukses */

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN (Tstack *T, int N){
    // kamus lokal
    char elemen;
    int i;

    // algoritma
     if ((*T).top + N <= 11) {
        for (i = 1; i <= N; i++) {
            (*T).top++;
            printf("Masukkan elemen ke-%d: ", (*T).top);
            scanf(" %c", &elemen);
            (*T).wadah[(*T).top] = elemen;
        }
    } else {
        printf("Tidak cukup ruang untuk menambahkan %d elemen. Stack tetap tidak berubah.\n", N);
    }
}

/*procedure pushBabel1 ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) bila belum penuh atau menjadi kosong bila stack penuh }
	{Proses: menumpuk top atau menghapus semua elemen }*/
void pushBabel1 (Tstack *T, char E){
    // kamus lokal
    int i;

    // algoritma
    if((*T).top == 11){
        for(i = 1 ; i <= 11 ; i++){
            (*T).wadah[i] = '-';
        }
    }
    else{
        (*T).wadah[(*T).top + 1] = E;
    }
}

/*procedure pushZuma ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) atau berkurang 1 elemen bila E bernilai sama dengan top }
	{Proses: menumpuk top atau menghapus elemen top }
    {contoh: T=['A','B','C'], E='C' menjadi T=['A','B']}*/
void pushZuma (Tstack *T, char E){
    // kamus lokal
    int i;

    // algoritma
    if ((*T).top < 11) {
        if ((*T).top > 0 && (*T).wadah[(*T).top] == E) {
            (*T).wadah[(*T).top] = '-';
            (*T).top--;
        } else {
            (*T).top++;
            (*T).wadah[(*T).top] = E;
        }
    } else {
        printf("Stack penuh, tidak bisa menambah elemen.\n");
    }
}   

