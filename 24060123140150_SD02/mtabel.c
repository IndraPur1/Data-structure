#include <stdio.h>
#include "tabel.h"
#include "tabel.c"

/* Deskripsi : Program ADT Tabel*/
/* NIM/Nama  : 24060123140150/Indra Purwanto*/
/* Tanggal   : 6  Agustus 2024*/

int main() {
	/*kamus*/
	Tabel T1;
	
	/*algoritma*/
	createTable(&T1);
	populate1(&T1,2);
	addXTable(&T1,6);
	populate2(&T1);
	printf("size : %d\n", getSize(T1));
	printf("is empty? : %d\n", isEmptyTable(T1));
	viewTable(T1);
	printf("sum : %d\n", SumEl(T1));
	printf("avg : %f\n", AverageEl(T1));
	printf("max : %d\n", getMaxEl(T1));
	printf("min : %d\n", getMinEl(T1));
	printf("modus : %d\n", Modus(T1));
	printf("Is full? : %d\n", isFullTable(T1));
	printf("search X : [%d]\n", searchX(T1, 6));
	printf("count X : %d\n", countX(T1, 6));
	printf("wadah kosong : %d\n", countEmpty(T1));
	printf("tabel sebelum dihapus : ");
	viewTable(T1);
	delXTable(&T1, 4);
	printf("tabel setelah X dihapus : ");
	viewTable(T1);
	sortDesc(&T1);
	printf("sortDesc : ");
	viewTable(T1);
	sortAsc(&T1);
	printf("sortAsc : ");
	viewTable(T1);
	return 0;
}