/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060123140150/Indra Purwant*/
/* Tanggal   : 29 Agustus 2024*/
/***********************************/
#include <stdio.h>
#include "titik.h"
#include "titik.c"

int main() {
	//kamus main
	Titik A;
	Titik B;
	
	//algoritma
	printf("driver modul Titik dari titik A(2,3) dan titik B(5,7)\n");
	makeTitik(&A);
	setAbsis(&A,2);
	printf("Absis A = %d\n",A.absis);
	setOrdinat(&A,3);
	printf("Ordinat A = %d\n",A.ordinat);
	makeTitik(&B);
	setAbsis(&B,5);
	printf("Absis B = %d\n",B.absis);
	setOrdinat(&B,7);
	printf("Ordinat B = %d\n",B.ordinat);
	printf ("kuadran = %d\n", Kuadran(A));
	printf ("kuadran = %d\n", Kuadran(B));
	printf("Jarak A dan B = %f\n",Jarak(A,B));
	printf("Is Origin A = %d\n",isOrigin(A));
	printf("Is Origin B = %d\n",isOrigin(B));
	geserXY(&A,1,1);
	printf("Titik A bergeser satu jadi = %d,%d\n",A.absis,A.ordinat);
	geserXY(&B,1,1);
	printf("Titik B bergeser satu jadi = %d,%d\n",B.absis,B.ordinat);
	refleksiSumbuX(&A);
	printf("Refleksi Absis Titik A = %d\n",A.absis);
	refleksiSumbuY(&A);
	printf("Refleksi Ordinat Titik A = %d\n",A.ordinat);
	refleksiSumbuX(&B);
	printf("Refleksi Absis Titik B = %d\n",B.absis);
	refleksiSumbuY(&B);
	printf("Refleksi Ordinat Titik B = %d\n",B.ordinat);
	printf ("A kuadran = %d\n", Kuadran(A));
	printf ("B kuadran = %d\n", Kuadran(B));
	return 0;
}
