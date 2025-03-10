/* File : list3.c */
/* Deskripsi : realisasi body ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : Indra Purwanto & 24060123140150*/
/* Tanggal : 15 November 2024*/

#include <stdio.h>
#include <stdlib.h>
#include "list3.h"


/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E){ //representasi fisik fungsi
    // kamus lokal
    address P;
    // algoritma
    P = (address) malloc(sizeof(Elm));
    if(P != NIL){
        info(P) = E;
        next(P) = NIL;
        prev(P) = NIL;
    }
    return P;
}
/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P){
    // kamus lokal

    // algoritma
    if(*P != NIL){
        next(*P) = NIL;
        prev(*P) = NIL;
    }
    free(*P);
    *P = NIL;
}

/* PROTOTYPE */
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List3)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List3 *L){
    First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List3) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List3 L){
    return (First(L) == NIL);
}

/*PENELUSURAN*/
/*procedure PrintList(input L:List3)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan semua elemen list L} */
void PrintList(List3 L){
	// kamus lokal
	address P;
	// algortima
	P = First(L);
	while (P != NIL){
		printf("%c", info(P));
		P = next(P);
    }
}

/*function NbElm(L:List3) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List3 L){
    // kamus lokal
	address P;
    int count;
	// algortima
	P = First(L);
    count = 0;
	while (P != NIL){
		count++;
		P = next(P);
    }
    return count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List3 *L, infotype V ){
    // kamus lokal
    address P;

    // algoritma
    P = Alokasi(V);
    if (P != NIL){
        if(First(*L)==NIL){
            First(*L) = P;
        } else{
            next(P) = NIL;
            prev(First(*L)) = P;
            First(*L) = P;
        }
    }
}

/*Procedure InsertVLast(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List3 *L, infotype V ){
    // kamus lokal
	address P, Last;
	// algoritma
	P = Alokasi(V);
	if (P != NIL){
		if (First(*L) == NIL){
			First(*L) = P;
		}
		else{
			Last = First(*L);
			while(next(Last) != NIL){
				Last = next(Last);
			}
			next(Last) = P;
            prev(P) = Last;
		}	
	}
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List3, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List3 *L, infotype *V){
    // kamus lokal
	address P;
	// algoritma
	*V = '#';
	if(First(*L) != NIL){
        P = First(*L);
		*V = info(P);
		First(*L) = next(P);
		next(P) = NIL;
        prev(First(*L)) = NIL;
	} 
    Dealokasi(&P);
}

/*Procedure DeleteVLast(input/output L:List3, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List3 *L, infotype *V){
    // kamus lokal
	address P;
	// algoritma
	*V = '#';
	if(First(*L) != NIL){
		if(next(First(*L)) == NIL){
			P = First(*L);
			*V = info(P);
		}
		else{
			P = First(*L);
			while(next(P) != NIL){
				P = next(P); 
			}
			*V = info(P);
            next(prev(P)) = NIL;
		}
	}
    Dealokasi(&P);
}

/*Procedure DeleteX(input/output L:List3, input X:infotype)
{ I.S. List L terdefinisi }
{ F.S. List mungkin menjadi kosong, atau berkurang 1 elemen. }
{ Proses: Elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteX(List3 *L, infotype X) {
    // Kamus lokal
    address P;
    boolean found;
    
    // Algoritma
    if (IsEmptyList(*L)) {
        printf("List kosong\n");
        return;
    }
    
    // Cari node dengan nilai X
    found = false;
    P = First(*L);
    while (P != NIL && !found) {
        if (info(P) == X) {
            found = true;
        } else {
            P = next(P);
        }
    }
    
    // Jika elemen tidak ditemukan
    if (P == NIL) {
        printf("Elemen tidak ditemukan\n");
        return;
    }
    
    // Proses delete node
    if (prev(P) == NIL) {  // Jika node pertama
        First(*L) = next(P);
        if (next(P) != NIL) {  // Jika bukan satu-satunya node
            prev(next(P)) = NIL;
        }
    } else if (next(P) == NIL) {  // Jika node terakhir
        next(prev(P)) = NIL;
    } else {  // Jika node di tengah
        next(prev(P)) = next(P);
        prev(next(P)) = prev(P);
    }
    Dealokasi(&P);
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List3, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X. }
{ Proses : Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List3 L, infotype X, address *A){
    // kamus lokal
    address P;
    boolean found;
    // algoritma
    found = false;
    *A = NIL;
    if(!IsEmptyList(L)){
        P = First(L);
        while((P != NIL)&&(found == false)){
            if(info(P) == X){
                found = true;
            } else{
                P = next(P);
            }
        }
        *A = P;
    }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List3, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.}
{ Proses : Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List3 *L, infotype X, infotype Y){
    // kamus lokal
    address P;
    boolean found;
    // algoritma
    found = false;
    if(!IsEmptyList(*L)){
        P = First(*L);
        while((P != NIL)&&(found == false)){
            if(info(P) == X){
                found = true;
            } else{
                P = next(P);
            }
        }
        info(P) = Y;
    }
}

/*Procedure Invers(input/output L:List3)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(List3 *L) {
    // Kamus lokal
    address P, last, next;
    
    // Algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        last = NIL;
        
        while (P != NIL) {
            // Simpan next node sebelum pointer diubah
            next = next(P);
            
            // Tukar pointer prev dan next
            next(P) = last;    // next sekarang menunjuk ke node sebelumnya
            prev(P) = next;    // prev sekarang menunjuk ke node selanjutnya
            
            // Update last dan pindah ke node berikutnya
            last = P;
            P = next;
        }
        
        // Update First ke node terakhir
        First(*L) = last;
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*Procedure InsertVAfterX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List3 *L, infotype X, infotype V){
    // kamus lokal
    address P;
    address last;
    boolean found;
    // algoritma
    P = Alokasi(V);
    found = false;
    last = First(*L);
    if(!IsEmptyList(*L)){
        while((last != NIL)&&(found == false)){
            if(info(last) == X){
                found = true;
            } else{
                last = next(last);
            }
        }
        if(next(last) == NIL){
            next(last) = P;
            prev(P) = last;
        } else{
            next(P) = next(last);
            prev(next(last)) = P;
            next(last) = P;
            prev(P) = last;
        }
    }
}

/*Procedure InsertVBeforeX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List3 *L, infotype X, infotype V){
    // kamus lokal
    address P;
    address last;
    boolean found;
    // algoritma
    P = Alokasi(V);
    found = false;
    last = First(*L);
    if(!IsEmptyList(*L)){
        while((last != NIL)&&(found == false)){
            if(info(last) == X){
                found = true;
            } else{
                last = next(last);
            }
        }
        if(prev(last) == NIL){
            prev(last) = P;
            next(P) = last;
            First(*L) = P;
        } else{
            prev(P) = prev(last);
            next(prev(last)) = P; 
            next(P) = last; 
            prev(last) = P;
        }
    }
}

/*Procedure DeleteVAfterX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List3 *L, infotype X, infotype *V) {
    // Kamus lokal
    address P, temp;
    boolean found;
    
    // Algoritma
    *V = '#';  // Nilai default jika tidak ditemukan
    
    if (!IsEmptyList(*L)) {
        // Cari node dengan nilai X
        found = false;
        P = First(*L);
        while (P != NIL && !found) {
            if (info(P) == X) {
                found = true;
            } else {
                P = next(P);
            }
        }
        
        // Jika X ditemukan dan ada node setelahnya
        if (found && next(P) != NIL) {
            // Simpan nilai yang akan dihapus
            *V = info(next(P));
            
            // Simpan node yang akan dihapus
            temp = next(P);
            
            // Update pointer
            if (next(temp) != NIL) {  // Jika bukan node terakhir
                next(P) = next(temp);
                prev(next(temp)) = P;
            } else {  // Jika node terakhir
                next(P) = NIL;
            }
            
            // Dealokasi node
            Dealokasi(&temp);
        } else {
            printf("X tidak ditemukan atau tidak ada elemen setelah X\n");
        }
    } else {
        printf("List kosong\n");
    }
}

/*Procedure DeleteVBeforeX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List3 *L, infotype X, infotype *V){
    // Kamus lokal
    address P, temp;
    boolean found;
    
    // Algoritma
    *V = '#';  // Nilai default jika tidak ditemukan
    
    if (!IsEmptyList(*L)) {
        // Cari node dengan nilai X
        found = false;
        P = First(*L);
        while (P != NIL && !found) {
            if (info(P) == X) {
                found = true;
            } else {
                P = next(P);
            }
        }
        
        // Jika X ditemukan dan ada node setelahnya
        if (found && prev(P) != NIL) {
            // Simpan nilai yang akan dihapus
            *V = info(prev(P));
            
            // Simpan node yang akan dihapus
            temp = prev(P);
            
            // Update pointer
            if (prev(temp) != NIL) {  // Jika bukan node terakhir
                prev(P) = prev(temp);
                next(prev(temp)) = P;
            } else {  // Jika node terakhir
                prev(P) = NIL;
            }
            
            // Dealokasi node
            Dealokasi(&temp);
        } else {
            printf("elemen X tidak ditemukan atau tidak ada elemen sebelum X\n");
        }
    } else {
        printf("List kosong\n");
    }
}

/*function CountX(L:List3, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List3 L, infotype X){
    // kamus lokal
    address P;
    int count;
    // algoritma
    count = 0;
    if(!IsEmptyList(L)){
        P = First(L);
        while(P != NIL){
            if(info(P) == X){
                count++;
                P = next(P);
            } else{
                P = next(P);
            }
        }
    }
    return count;
}

/*function FrekuensiX(L:List3, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List3 L, infotype X){
    //Kamus Lokal
    address P;
    int Count; 
    //Algoritma
    Count = 0;
    P = First(L);
    while (P != NIL){
        if (info(P) == X){
            Count++;
        }
        P = next(P);
    }
    return (float) Count / NbElm(L);
}

/*function MaxMember(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List3 L){
    //Kamus Lokal
    address P;
    int Count;
    int max;
	infotype M;
    //Algoritma
    P = First(L);
    max = 0;
    Count = 0;
    while (P != NIL){
        Count = CountX(L, info(P));
        if (Count > max){
            max = Count;
        }
        P = next(P);
    }
    return max;
}

/*function Modus(L:List3) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List3 L){
    //Kamus Lokal
    address P;
    int Count;
    int max;
    char mod;
    //Algoritma
    P = First(L);
    max = MaxMember(L);
    Count = 0;
	while ((P != NIL)){
		if(max == CountX(L, info(P))){
			mod = info(P);
			return mod;
		}
		P = next(P);
	}
}

/*function CountVocal(L:List3) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List3 L){
    // kamus lokal
    address P;
    int count;
    // algoritma
    count = 0;
    if(!IsEmptyList(L)){
        P = First(L);
        while(P != NIL){
            if((info(P) == 'A') || (info(P) == 'I') || (info(P) == 'U') || (info(P) == 'E') || (info(P) == 'O')){
                count++;
                P = next(P);
            } else{
                P = next(P);
            }
        }
    }
    return count;
}

/*function CountNG(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List3 L){
    // kamus lokal
    address P;
    int count;
    // algoritma
    count = 0;
    if(!IsEmptyList(L)){
        P = First(L);
        while(P != NIL){
            if(info(P) == 'N'){
                if(info(next(P)) == 'G'){
                    count++;
                    P = next(P);
                }
            } else{
                P = next(P);
            }
        }
    }
    return count;
}

/*Procedure SearchAllX(input L:List3, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. - }
{ Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List3 L, infotype X){
    //Kamus Lokal
    address P;
    int Found;
    int Posisi;
    //Algoritma
    Found = 0;
    Posisi = 1;
    P = First(L);
    while (P != NIL){
        if (info(P) == X){
            printf("Elemen %c ditemukan pada posisi %d\n", X, Posisi);
            Found = 1;
        }
        P = next(P);
        Posisi++;
    }
    if (!Found){
        printf("ELemen tidak ditemukan dalam list\n");
    }
}

/*Procedure DeleteAllX(input/output L:List3, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. List mungkin menjadi kosong. }
{ Proses: Semua elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteAllX(List3 *L, infotype X) {
    //kamus lokal
    address P;

    //algoritma
    SearchX(*L, X, &P); 
    while (P != NIL) { 
        DeleteX(L, X);  
        SearchX(*L, X, &P); 
    }
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List3, input L2:List3, output L:List3)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List3 L1, List3 L2, List3 *L){
    // Membuat variabel pointer P untuk traversal
    address P;
    
    // Membuat list kosong baru L
    CreateList(L);
    
    // Menyalin semua elemen dari L1
    P = First(L1);
    while (P != NIL){
        InsertVLast(L, info(P));  // Memasukkan nilai ke akhir list L
        P = next(P);              // Pindah ke node berikutnya
    }
    
    // Menyalin semua elemen dari L2
    P = First(L2);
    while (P != NIL){
        InsertVLast(L, info(P));  // Memasukkan nilai ke akhir list L
        P = next(P);              // Pindah ke node berikutnya
    }
}

/*Procedure SplitList(input L:List3, output L1:List3, output L2:List3)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List3 L, List3 *L1, List3 *L2){
    //Kamus Lokal
    int Count;
    int half;
    int panjang;
    address P;
    //Algoritma
    CreateList(L1);
    CreateList(L2);
    panjang = NbElm(L);
    half = panjang / 2;
    Count = 0;
    P = First(L);
    while (P != NIL && Count < half) {
        InsertVLast(L1, info(P));
        P = next(P);
        Count++;
    }
    while (P != NIL) {
        InsertVLast(L2, info(P));
        P = next(P);
    }
}

/*Procedure CopyList(input L1:List3, output L2:List3)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List3 L1, List3 *L2) {
    //Kamus Lokal
    address P;
    //Algoritma
    P = First(L1);
    CreateList(L2);
    while (P != NIL){
        InsertVLast(L2, info(P));
        P = next(P);
    }
}