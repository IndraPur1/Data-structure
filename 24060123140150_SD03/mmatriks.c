/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : 24060123140150/Indra Purwanto*/
/* Tanggal   : 13 September 2024*/
/***********************************/

#include "matriks.h"
#include <stdio.h>
#include "boolean.h"
#include "matriks.c"

int main() {
	/*kamus*/
	Matriks M; 

	/*algoritma*/
	// inisialisasi dan print matriks//
	printf("--inisialisasi matriks--\n");
	M.nbaris = 10;
	M.nkolom = 10;
	initMatriks(&M);
	printMatriks(M);
	viewMatriks(M);
	printf("\n");

	// search x
	printf("--searchX---\n");
	int row, col;
	M.nbaris = 3;
	M.nkolom = 3;

	M.cell[1][1] = 1;
    M.cell[1][2] = 2;
    M.cell[1][3] = 3;
    M.cell[2][1] = 4;
    M.cell[2][2] = 5;
    M.cell[2][3] = 6;
    M.cell[3][1] = 7;
    M.cell[3][2] = 8;
    M.cell[3][3] = 9;
	int X = 7;

	// COUNT X------
	printf("--countX--\n");
	int x = 2;
	viewMatriks(M);
	int elX = countX(M, x);
	printf("telemen %d muncul %d kali\n", x, elX);
	printf("\n");

	// ADD X------
	printf("--addX--\n");
	int baris = 4;
	int kolom = 1;
	int elmen = 3;
	addX (&M,  elmen,  baris,  kolom);
	viewMatriks(M);
	printf("tambah %d dalam matriks [%d, %d]\n\n", elmen, baris, kolom);

	// EDIT X------
	printf("--edit X--\n");
	int a = 5;
	editX (&M, a, baris, kolom);
	viewMatriks(M);
	printf("mengganti matriks [%d, %d] dengan elemen %d\n\n", baris, kolom, a);

	// DEL X------
	printf("--delX--\n");
	int del = 5;
	int bar = 4;
	int kol = 1;
	delX (&M,  del);
	viewMatriks(M);
	printf("\n");

	// ADD MATRIKS------
	printf("--add Matriks--\n");

	Matriks M1, M2, M3, M4, M5;
	printf("matriks M1:\n");
	M1.nbaris = 3;
	M1.nkolom = 3;

	M1.cell[1][1] = 10;
	M1.cell[1][2] = 11;
	M1.cell[1][3] = 12;
	M1.cell[2][1] = 13;
	M1.cell[2][2] = 14;
	M1.cell[2][3] = 15;
	M1.cell[3][1] = 16;
	M1.cell[3][2] = 17;
	M1.cell[3][3] = 18;
	viewMatriks(M1);
	printf("\n");

	printf("matriks M2:\n");
	M2.nbaris = 3;
	M2.nkolom = 3;

	M2.cell[1][1] = 19;
	M2.cell[1][2] = 20;
	M2.cell[1][3] = 21;
	M2.cell[2][1] = 22;
	M2.cell[2][2] = 23;
	M2.cell[2][3] = 24;
	M2.cell[3][1] = 25;
	M2.cell[3][2] = 26;
	M2.cell[3][3] = 27;
	viewMatriks(M2);
	printf("\n");

	printf("hasil operasi penambahan:");
	M3 = addMatriks(M1, M2);
	viewMatriks(M3);
	printf("\n");

	// SUB MATRIKS------
	printf("hasil operasi pengurangan: \n");
	M4 = subMatriks(M1, M2);
	viewMatriks(M4);
	printf("\n");

	// KALI MATRIKS------
	printf("hasil operasi perkalian 2 matriks: \n");
	M5 = kaliMatriks(M1, M2);
	viewMatriks(M5);
	printf("\n");

	// ISI MATRIKS RANDOM------
	printf("--isi matriks random--\n");
	Matriks D;
	int n1 = 3;
	int n2 = 3;
	isiMatriksRandom(&D, n1, n2);
	viewMatriks(D);
	printf("\n\n");

	// ISI MATRIKS IDENTITAS------
	printf("--isi matriks identitas--\n");
	Matriks C;
	int barkol = 4;
	isiMatriksIdentitas(&C, barkol);
	viewMatriks(C);
	printf("\n");

	// POPULATE MATRIKS------
	printf("--populate matriks--\n");
	Matriks E;
	int a1, a2;
	printf("masukan baris: ");
    scanf("%d", &a1);
    printf("masukan kolom: ");
    scanf("%d", &a2);
	populateMatriks(&E, a1, a2);
	printf("matriks hasil inputan kybiard: \n");
	viewMatriks(E);
	printf("\n");	

	// KALI SEKALAR------
	printf("--kali sekalar--\n");
	Matriks A;
	int s = 2;
	A = kaliSkalarMatriks(M1, s);
	viewMatriks(A);
	printf("merupakan hasil kali sekalar %d dari matriks M2\n\n", s);

	// SUM MATRIKS------
	printf("--sum matriks--\n");
	int sum = getSumMatriks(A);
	printf("jumlah semua elemen dalam matriks M2: %d\n\n", sum);

	// AVERAGE------
	printf("--average--\n");
	int average = getAverageMatriks(A);
	printf("rata rata dati matriks adalah: %d\n\n", average);

	
	// MAX ELEMEN------
	printf("--elemen maximum--\n");
	int max = getMaxMatriks(A);
	printf("nilai maksimum dari M2: %d\n\n", max);

	// MIN ELEMEN------
	printf("--elemen minimum--\n");
	int min = getMinMatriks(A);
	printf("nilai minimum dari M2: %d\n\n", min);

	// TRANSPOSE MATRIKS------
	printf("--transpose matriks--\n");
	transposeMatriks(&A);
	viewMatriks(A);

	return 0;
}