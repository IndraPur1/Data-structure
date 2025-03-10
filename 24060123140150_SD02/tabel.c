#ifndef   tabel_c
#include "tabel.h"
#include <math.h>
#include "boolean.h"

/* Deskripsi : Program ADT Tabel*/
/* NIM/Nama  : 24060123140150/Indra Purwanto*/
/* Tanggal   : 6  Agustus 2024*/

/*KONSTRUKTOR*/				 
/*procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah=-999}
	{Proses: menginisialisasi T} */
void createTable (Tabel *T){
    // kamus lokal
    int i;

    //algoritma
    for (i = 1; i < 11; i++){
        (*T).wadah[i] = -999;
    }
    (*T).size = 0;
}

/*SELEKTOR*/
/*function getSize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize (Tabel T){
    //kamus lokal

    //algoritma
    return T.size;
}

/*PREDIKAT*/
/*function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable (Tabel T){
    //kamus lokal

    //algoritma
    return T.size == 0;
}

/*function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable (Tabel T){
    //kamus lokal

    //algoritma
    return T.size == 10;
}

/*OPERASI PENCARIAN*/
/*function searchX (T:Tabel, X: integer) -> boolean
	{mencari elemen bernilai X dalam T.wadah dan mengembalikan index terkecilnya}*/
int searchX (Tabel T, int X){
    //kamus lokal
    int i, n;

    //algoritma
    n = -999, i = 1;
    while (i <= T.size && n == -999){
        if (T.wadah[i] == X){
            n = i;
        }
    }return n;
}

/*function countX (T:Tabel, X: integer) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam T.wadah}*/
int countX (Tabel T, int X){
    //kamus lokal
    int count = 0;

    //algoritma
    for (int i = 1; i <= T.size ; i++){
        if (T.wadah[i] == X){
            count += 1;
        }
    }
    return count;
}

/*function countEmpty( T: Tabel) -> integer
	{mengembalikan banyak elemen T yang belum terisi } */
int countEmpty (Tabel T){
    //kamus lokal
    int count = 0;

    //algoritma
    for (int i = 1; i <= 10; i++){
        if (T.wadah[i] == -999){
            count++;
        }
    }return count;
}

/*MUTATOR*/
/*procedure addXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai X}*/
void addXTable (Tabel *T, int X){
    //kamus lokal
    int i;

    //algoritma
    if (!isFullTable(*T)){
        (*T).size += 1;
        (*T).wadah[(*T).size] = X; 
    }
}

/*procedure delXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai X, geser semua elemen sisa}*/
void delXTable (Tabel *T, int X) {
    // Kamus lokal
    int i, j;

    // Algoritma
    for (i = 1; i <= T->size; i++) {  
        if ((*T).wadah[i] == X) {  
            for (j = i; j <= T->size; j++) {  
                (*T).wadah[j] = (*T).wadah[j+1]; 
            }
            (*T).wadah[T->size] = -999; 
            (*T).size--; 
            break;
        }
    }
}


/*procedure delAllXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllXTable (Tabel *T, int X){
    //kamus lokal
    int i;

    //algoritma
    for (i = 1; i <= T->size; i++){
        (*T).wadah[i] = -999;
        T->size--;
        }
            
}
/*OPERASI BACA/TULIS*/
/*procedure printTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable (Tabel T){
    //kamus lokal
    int i;

    //algoritma
    for (i = 1; i <= 10 ; i++){
        printf("%d |", (T).wadah[i]);
    }
    printf("\n");
    
}

/*procedure viewTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable (Tabel T){
    //kamus lokal
    int i;

    //algoritma
    for (i = 1; i <= (T).size ; i++){
        printf("%d |", (T).wadah[i]);
    }
    printf("\n");
}

/*procedure populate1 ( input/output T:Tabel, input N: integer )
	{I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
	{F.S.: T.wadah terisi sebanyak N elemen }
	{Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populate1 (Tabel *T, int N){
    //kamus lokal
    int elemen;
    
    //algoritma
    (*T).size = N; 
    for (int i = 1; i <= N; i++) {
        do {
            printf("masukkan angka ke %d: ", i);
            scanf("%d", &elemen);
            
            if (elemen <= 0) {
                printf("angka harus diatas 0\n");
            }
        } while (elemen <= 0);
        (*T).wadah[i] = elemen;
    }
}

/*procedure populate2 ( input/output T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: T.wadah terisi beberapa elemen positif}
	{Proses: mengisi elemen T.wadah berulang, bila angka 
	dari keyboard <=0 maka berhenti, tidak diproses}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populate2 (Tabel *T){
    //kamus lokal
    int elemen;
    int i;

    //algoritma
    for (i = (T)->size + 1; i <= 10; i++) {
        printf("masukkan angka ke %d: ", i);
        scanf("%d", &elemen);
        
        if (elemen <= 0) {
            printf("berhenti, tidak diproses\n");
            break;
        }        
        T->wadah[i] = elemen;
        T->size++; 
    }
}
 
/*OPERASI STATISTIK*/
/*function SumEl ( T:Tabel ) -> integer 
	{mengembalikan jumlah semua elemen pengisi T } */
int SumEl (Tabel T){
    //kamus lokal
    int i,sum = 0;

    //algoritma
    for ( i = 1; i <= T.size; i++){
        sum += T.wadah[i];
    }
    return sum;
}

/*function AverageEl ( T:Tabel ) -> real 
	{mengembalikan nilai rata-rata elemen pengisi T } */
float AverageEl (Tabel T){
    //kamus lokal
    int i;
    double avg, sum = 0;

    //algoritma
    for ( i = 1; i <= T.size; i++){
        sum += T.wadah[i];
    }
    avg = sum / T.size;
    return avg;
}


/*function getMaxEl ( T: Tabel) -> integer
	{mengembalikan nilai elemen terbesar } */
int getMaxEl (Tabel T){
    //kamus lokal
    int i,max;

    //algoritma
    max = -999;
    for ( i = 1; i <= T.size; i++){
        if (T.wadah[i] > max ){
            max = T.wadah[i];
        }
    }
    return max;
}

/*function getMinEl ( T: Tabel) -> integer
	{mengembalikan nilai elemen terkecil } */
int getMinEl (Tabel T){
    //kamus lokal
    int i,min;

    //algoritma
    min = T.wadah[1];
    for ( i = 1; i <= T.size; i++){
        if (T.wadah[i] < min ){
            min = T.wadah[i];
        }
    }
    return min;
}

/*function Modus ( T:Tabel ) -> integer 
	{mengembalikan elemen pengisi T yang paling banyak muncul } */
	/*asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama*/
int Modus (Tabel T){
    //kamus lokal
    int i, j, mod, IMod, count;
    
    //algoritma
    mod = T.wadah[1];
    IMod = 1;

    for (i = 1; i <= T.size; i++) {
        count = 1;
        for (j = i + 1; j <= T.size; j++) {
            if (T.wadah[i] == T.wadah[j]) {
                count++;
            }
        }
        if (count > IMod) {
            IMod = count;
            mod = T.wadah[i];
        }
    }
    return mod;
}

/*OPERASI PENGURUTAN*/
/*procedure SortAsc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari nilai terkecil hingga nilai terbesar}
	{Proses: mengurutkan elemen dalam T.wadah dari nilai terkecil hingga nilai terbesar}*/
void sortAsc (Tabel *T){
    //kamus lokal
    int i, Pass, Temp, IMin;
    
    //algoritma
    for (Pass = 1; Pass <= (*T).size - 1; Pass++) {
        IMin = Pass;
        for (i = Pass + 1; i <= (*T).size; i++) {
            if ((*T).wadah[IMin] > (*T).wadah[i]) {
                IMin = i;
            }
        }
        Temp = (*T).wadah[IMin];
        (*T).wadah[IMin] = (*T).wadah[Pass];
        (*T).wadah[Pass] = Temp;
    }
}


/*procedure SortDesc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari nilai terbesar hingga nilai terkecil}
	{Proses: mengurutkan elemen dalam T.wadah dari nilai terbesar hingga nilai terkecil}*/
void sortDesc (Tabel *T){
    //kamus lokal
    int i, Pass, Temp, IMax;
    
    //algoritma
    for (Pass = 1; Pass <= (*T).size - 1; Pass++) {
        IMax = Pass;
        for (i = Pass + 1; i <= (*T).size; i++) {
            if ((*T).wadah[IMax] < (*T).wadah[i]) {
                IMax = i;
            }
        }
        Temp = (*T).wadah[IMax];
        (*T).wadah[IMax] = (*T).wadah[Pass];
        (*T).wadah[Pass] = Temp;
    }
}

#endif