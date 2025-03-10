/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : 24060123140150/Indra Purwanto*/
/* Tanggal   : 13 September 2024*/
/***********************************/

#include "matriks.h"
#include <stdio.h>
#include "boolean.h"

/* KONSTRUKTOR */		
/* procedure initMatriks(output M: Matriks)
	{I.S.: - }
	{F.S.: Matriks M terdefinisi}
	{Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
void initMatriks(Matriks *M){
    /* Kamus Lokal */
    int i,j;

    /* Algoritma */
    for(i=1; i<=(*M).nbaris; i++){
        for(j=1; j<=(*M).nkolom; j++){
            (*M).cell [i][j] = -999;
        }
    }
    (*M).nbaris = 0;
    (*M).nkolom = 0;
} 

/* SELEKTOR */
/* function getNBaris(M: Matriks) -> integer
	{mengembalikan banyak baris matriks M yang terisi } */
int getNBaris(Matriks M){
    /* Kamus Lokal */

    /* Algoritma*/
    return M.nbaris;
}

/* function getNKolom(M: Matriks) -> integer
	{mengembalikan banyak kolom matriks M yang terisi } */
int getNKolom(Matriks M){
    /* Kamus Lokal */

    /* Algoritma */
    return M.nkolom;
} 

/* PREDIKAT */
/* function isEmptyMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M kosong } */
boolean isEmptyMatriks(Matriks M){
    /* Kamus Lokal */

    /* Algoritma */
    if(M.nbaris == 0 && M.nkolom == 0){
        return true;
    }    
    else {
        return false;
    }     
}

/* function isFullMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M penuh } */
boolean isFullMatriks(Matriks M){
    /* Kamus Lokal */

    /* Algortima */
    if(M.nbaris == 11 && M.nkolom == 11){
        return true;
    }
    else {
        return false; 
    }
}

/* OPERASI PENCARIAN*/
/* procedure searchX( input M:Matriks, input X: integer, output row: integer, output col: integer )
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: row berisi indeks baris dan col berisi indeks kolom ketemu X di M.cell, atau -999 jika tidak ketemu}
	{Proses: mencari elemen bernilai X dalam M.cell} */
void searchX(Matriks M, int X, int *row, int *col){
    /* Kamus Lokal */
    int i,j;

    /* Algortima */
    *row = -999;
    *col = -999;
    for(i=1; i<=M.nbaris; i++){
        for(j=1; j<=M.nkolom; j++){
            if (M.cell [i][j] == X){
                *row = i;
                *col = j;
                return;
            }
        }
    }

}

/* function countX (M:Matriks, X: integer) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam M.cell} */
int countX (Matriks M, int X){
    // kamus lokal
    int i, j, count;

    // algoritma
    count = 0;
    for (i=1; i<=M.nbaris; i++){
        for (j=1; j<=M.nkolom; j++){
            if(M.cell[i][j] == X){
                count++;
            }
        }
        
    }
    return count;

}

/* MUTATOR */
/* procedure addX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell bertambah 1 elemen pada baris ke-row dan kolom ke-col jika belum penuh}
	{Proses: mengisi elemen M.cell dengan nilai X} */
void addX (Matriks *M, int X, int row, int col){
    // kamus lokal

    // algoritma
    if (M->cell[row][col] == -999){
        (M->cell[row][col] = X);
    }
    if (row > (*M).nbaris && col <= (*M).nkolom){
        (*M).nbaris = row;
    }else if(col > (*M).nkolom && row <= (*M).nbaris){
        (*M).nkolom = col;
    }else if(col > (*M).nkolom && row > (*M).nbaris){
        (*M).nkolom = col;
        (*M).nbaris = row;
    }
}

/* procedure editX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell pada baris ke-row dan kolom ke-col diubah dengan nilai X}
	{Proses: mengubah isi M.cell pada baris ke-row dan kolom ke-col dengan nilai X} */
void editX (Matriks *M, int X, int row, int col){
    // kamus lokal

    // algoritma
    (M->cell[row][col] = X);

}

/* procedure delX (input/output M:Matriks, input X:integer )
	{I.S.: M terdefinisi, X terdefinisi}
	{F.S.: elemen M.cell berkurang 1}
	{Proses: menghapus 1 elemen bernilai X dari M.cell*/
void delX (Matriks *M, int X){
    // kamus lokal 
    int row,col;

    //algoritma 
    searchX(*M, X, &row, &col);

    if(row != -999 && col != -999){
        (*M).cell[row][col] = -999;
    }
    else{
        printf ("elemen %d tidak ada di matriks", X);
    }
}

/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
	{proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
void isiMatriksRandom(Matriks *M, int x, int y){
    // kamus lokal
    int i, j;
    int rand();
    // algoritma
    for ( i = 1; i <= x; i++){
        for ( j = 1; j <= y; j++){
            (*M).cell[i][j] = rand() % 10;
        }
    }
    (*M).nbaris = x;
    (*M).nkolom = y;
}

/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
	{proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n){
    // kamus lokal
    int i, j;

    // algoritma
    (*M).nbaris = n;
    (*M).nkolom = n;
    for ( i = 1; i <= n; i++){
        for ( j = 1; j <= n; j++){
            if ( i == j){
                (*M).cell[i][j] = 1;
            }else{
                (*M).cell[i][j] = 0;
            }
        }
        
    }
    
}

/* OPERASI BACA/TULIS */
/* procedure populateMatriks(input/output M: Matriks, input x: integer, input y: integer)
{I.S.: M terdefinisi}
{F.S.: M terisi dengan inputan dari keybord sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
{proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} */
void populateMatriks(Matriks *M, int x, int y){
    // kamus lokal
    int i,j;

    // algprtima 
    for(i=1; i<=x; i++){
        for(j=1; j<=y; j++){
            printf ("Masukkan matriks [%d][%d]; ", i, j);
            scanf("%d", &(*M).cell[i][j]);
        }
    }
     (*M).nbaris = x;
     (*M).nkolom = y;
}

/* procedure printMatriks(input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen M.cell ke layar} */
void printMatriks(Matriks M){
    // kamus lokal 
    int i,j;

    // algoritma
    for(i=1; i<=10; i++){
        for(j=1; j<=10; j++){
            printf("[%d]", (M).cell[i][j]);
        }
        printf("\n");
    }
}

/* procedure viewMatriks (input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks (Matriks M){
    // kamus lokal 
    int i,j;

    // algortima 
    if(!isEmptyMatriks(M)){
		for(i=1 ; i <= M.nbaris ; i++){
			for(j=1 ; j <= M.nkolom ; j++){
				printf("%d ", M.cell[i][j]);
			}
			printf("\n");
		}
	}
	else{
		printf("Matriks kosong \n");
	}
}

/* OPERASI ARITMATIKA */
/* function addMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2){
    // kamus lokal 
    int i,j;
    Matriks M3;

    // algoritma
    M3.nbaris = M1.nbaris;
    M3.nkolom = M1.nkolom;
    for(i=1; i<=M1.nbaris; i++){
        for(j=1; j<=M2.nkolom; j++){
            M3.cell[i][j] = M1.cell[i][j] + M2.cell[i][j];
        }
        
    }
    printf("\n");
    return M3;
}

/* function subMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2){
    // kamus lokal
    int i,j;
    Matriks M3;

    // algoritma
    M3.nbaris = M1.nbaris;
    M3.nkolom = M1.nkolom;
    for(i=1; i<=M1.nbaris; i++){
        for(j=1; j<=M2.nkolom; j++){
            M3.cell[i][j] = M1.cell[i][j] - M2.cell[i][j];
    
        }
    }
    printf("\n");
    return M3;
}

/* function kaliMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil perkalian antara matriks M1 dengan M2} */
Matriks kaliMatriks(Matriks M1, Matriks M2){
    // kamus lokal 
    int i,j,k;
    Matriks M3;

    // algoritma
    M3.nbaris = M1.nbaris;
    M3.nkolom = M2.nkolom;
    if (M1.nkolom == M2.nbaris){
        for (i=1; i<=M1.nbaris; i++){
            for (j=1; j<=M2.nkolom; j++){
                M3.cell[i][j] = 0;
                for (k=1; k<=M1.nkolom; k++){
                    M3.cell[i][j] += M1.cell[i][k] * M2.cell[k][j];
                }
            }
        }
    }else{
        printf("operasi kali gagal");
    }
return M3;
}

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M1, int x){
    // kamus lokal
    int i, j;
    Matriks M2;

    // algoritma
    M2.nbaris = M1.nbaris;
    M2.nkolom = M1.nkolom;
    for (i=1; i<= M1.nbaris; i++){
        for (j=1; j<= M1.nkolom; j++){
            M2.cell[i][j] = M1.cell[i][j] * x;
        }
        
    }
    return M2;
}

/* OPERASI STATISTIK*/
/* function getSumMatriks (M:Matriks) -> integer 
	{mengembalikan jumlah semua elemen pengisi M.cell} */
int getSumMatriks (Matriks M){
    // kamus lokal
    int i, j, temp;

    // algoritma
    temp = 0;
    for (i=1; i<= M.nbaris; i++){
        for (j=1; j<= M.nkolom; j++){
            temp += M.cell[i][j];
        }
        
    }
    return temp;  
}

/* function getAveragematriks (M:Matriks) -> real 
	{mengembalikan nilai rata-rata elemen pengisi M.cell} */
float getAverageMatriks (Matriks M){
    // kamus lokal 
    int average;

    // algoritma
    average = getSumMatriks(M) / (M.nbaris * M.nkolom);
    return average;
    
}

/* function getMaxMatriks (M:Matriks) -> integer
	{mengembalikan nilai elemen terbesar pengisi M.cell } */
int getMaxMatriks (Matriks M){
    // kamus lokal 
    int i,j;
    int max = M.cell[1][1];

    // algoritma
    for (i=1; i <= M.nbaris; i++){
        for (j=1; j <= M.nkolom; j++){
            if (M.cell[i][j] > max){
                max = M.cell[i][j];
            }
        }
        
    }
    return max;
}

/* function getMinMatriks (M:Matriks) -> integer
	{mengembalikan nilai elemen terkecil pengisi M.cell} */
int getMinMatriks (Matriks M){
    // kamus lokal
    int i,j;
    int min = M.cell[1][1];

    // algoritma
    for (i=1; i <= M.nbaris; i++){
        for (j=1; j <= M.nbaris; j++){
            if (M.cell[i][j] < min){

            }
        }
    }
    return min;
}

/* OPERASI LAINNYA */
/* procedure transposeMatriks(input/output M: Matriks)
	{I.S.: M terdefinisi}
	{F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
	{proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M){
    // kamus lokal 
    int i,j,temp;

    // algoritma
    temp = 0;
    for (i=1; i <= (*M).nbaris; i++){
        for (j=1; j <= (*M).nbaris; j++){
             temp = (*M).cell[i][j];
            (*M).cell[i][j] = (*M).cell[j][i];
            (*M).cell[j][i] = temp;
        }
        
    }
    if ((*M).nbaris != (*M).nkolom) {
        temp = (*M).nbaris;
        (*M).nbaris = (*M).nkolom;
        (*M).nkolom = temp;
    }
}

/* function getTransposeMatriks(M: Matriks)
	{menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M){
    // kamus lokal
    int i, j, temp;

    // algoritma
    temp = 0;
    for (i=1; i <= M.nkolom; i++){
        for (j=i + 1; j <= M.nbaris; j++){
            temp = M.cell[i][j];
            M.cell[i][j] = M.cell[j][i];
            M.cell[j][i] = temp;
        }
        
    }
    if (M.nbaris != M.nkolom) {
        temp = M.nbaris;
        M.nbaris = M.nkolom;
        M.nkolom = temp;
    }
    return M;
}